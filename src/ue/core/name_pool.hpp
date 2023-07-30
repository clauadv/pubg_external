#pragma once

namespace pubg::defs
{
	extern std::uint8_t* m_base;
}

namespace ue::core
{
	inline std::uint64_t m_name_pool{ 0 };

	class f_name_pool
	{
	public:
		static std::uint64_t get()
		{
			const auto g_names = READ_UINT64(pubg::defs::m_base + offsets::name_pool::m_g_names);

			const auto decrypted_v11 = READ_UINT64(XE_DECRYPT(g_names));
			const auto decrypted_v12 = READ_UINT64(XE_DECRYPT(decrypted_v11));
			const auto decrypted_v13 = XE_DECRYPT(decrypted_v12);

			return XE_DECRYPT(READ_UINT64(decrypted_v13));
		}

		static std::uint32_t decrypt(std::uint32_t value)
		{
			/*
				"%s<W:%.1f%%> %s", any xref
				v7 = __ROL4__(*(_DWORD *)(v5 + 24) ^ 0xbdf783b8, 7);
				LODWORD(v19) = v7 ^ (v7 << 16) ^ 0x4f3edbc0;
			*/

			auto v7 = __ROL4__(value ^ 0xbdf783b8, 7);
			auto v19 = v7 ^ (v7 << 16) ^ 0x4f3edbc0;
			return v19;
		}

		static std::string get_name_from_id(std::int32_t id)
		{
			const auto name_ptr = READ_UINT64(ue::core::m_name_pool + (id / offsets::name_pool::m_chunk_size) * 0x08);
			const auto name = READ_UINT64(name_ptr + (id % offsets::name_pool::m_chunk_size) * 0x08);

			char names_c[64];
			driver::m_driver.read(reinterpret_cast<void*>(name + 0x10), names_c, sizeof(names_c) - 0x01);
			names_c[sizeof(names_c) - 0x01] = '\0';

			auto _name = std::string(names_c);
			std::ranges::transform(_name, _name.begin(), ::tolower);

			return _name;
		}

		static std::wstring read_unicode(const std::uintptr_t address, std::size_t size)
		{
			const auto buffer = std::make_unique<wchar_t[]>(size);
			driver::m_driver.read(reinterpret_cast<void*>(address), buffer.get(), size * 2);

			return std::wstring(buffer.get());
		}
	};
}