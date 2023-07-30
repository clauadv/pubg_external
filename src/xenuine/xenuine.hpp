#pragma once

namespace pubg::defs
{
	extern std::uint8_t* m_base;
}

namespace xenuine
{
	inline std::uint8_t* m_xe_decrypt_container = static_cast<std::uint8_t*>(LI_FN(VirtualAlloc).safe()(nullptr, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));

	inline bool initialize()
	{
		const auto decrypt_ptr = READ_UINT64(pubg::defs::m_base + offsets::xenuine::m_decrypt);
		if (!decrypt_ptr)
		{
			LOG_ERROR("failed to get decrypt_ptr");
			return false;
		}

		std::uint8_t backup_bytes[0x100];

		driver::m_driver.read(reinterpret_cast<void*>(decrypt_ptr), backup_bytes, sizeof(backup_bytes));

		*reinterpret_cast<std::uint16_t*>(xenuine::m_xe_decrypt_container) = static_cast<std::uint16_t>(0xb848);
		*reinterpret_cast<std::uint64_t*>(xenuine::m_xe_decrypt_container + 0x2) = decrypt_ptr + READ_INT32(reinterpret_cast<void*>(decrypt_ptr + 0x3)) + 7;

		LI_FN(memcpy).safe()(&xenuine::m_xe_decrypt_container[0xa], &backup_bytes[0x7], 0x100 - 0xa);

		LOG_INFO("xenuine initialized");
	}

	inline std::uint64_t decrypt(const std::uint64_t encrypted)
	{
		typedef std::uint64_t(__fastcall* xe_decrypt_fn_t)(std::uint64_t, std::uint64_t);
		return xe_decrypt_fn_t(xenuine::m_xe_decrypt_container)(0, encrypted);
	}
}