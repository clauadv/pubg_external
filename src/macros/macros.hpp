#pragma once

#define WSTR(str) std::wstring{ str.begin(), str.end() }
#define STR(wstr) std::string{ wstr.begin(), wstr.end() }

#define DEG_TO_RAD (static_cast<float>(M_PI) / 180.f)
#define FOV_DEG_TO_RAD (static_cast<float>(M_PI) / 360.f)

#define XE_DECRYPT(encrypted) xenuine::decrypt(encrypted)

#define READ_UINT64(address) driver::m_driver.read_t<std::uint64_t>(address)
#define READ_INT32(address) driver::m_driver.read_t<std::int32_t>(address)
#define READ_FLOAT(address) driver::m_driver.read_t<float>(address)
#define READ_VEC3(address) driver::m_driver.read_t<ue::math::fvector3>(address)
#define READ_ROT(address) driver::m_driver.read_t<ue::math::frotator>(address)