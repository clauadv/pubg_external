#pragma once

namespace ue::math
{
	struct frotator
	{
		float m_pitch; // 0x00(0x04)  
		float m_yaw; // 0x04(0x04)  
		float m_roll; // 0x08(0x04)

		[[nodiscard]] bool zero() const
		{
			return (this->m_pitch == 0.f && this->m_yaw == 0.f && this->m_roll == 0.f);
		}
	};
}