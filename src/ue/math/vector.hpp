#pragma once

namespace ue::math
{
	struct fvector2
	{
		float m_x; // 0x00(0x04)  
		float m_y; // 0x04(0x04)

		[[nodiscard]] bool zero() const
		{
			return (this->m_x == 0.f && this->m_y == 0.f);
		}
	};

	struct fvector3
	{
		float m_x; // 0x00(0x04)  
		float m_y; // 0x04(0x04)  
		float m_z; // 0x08(0x04)

		fvector3 operator-(fvector3 in) { return { this->m_x - in.m_x, this->m_y - in.m_y, this->m_z - in.m_z }; }

		[[nodiscard]] bool zero() const
		{
			return (this->m_x == 0.f && this->m_y == 0.f && this->m_z == 0.f);
		}

		[[nodiscard]] float dist(const ue::math::fvector3 to) const
		{
			return (std::sqrt(((this->m_x - to.m_x) * (this->m_x - to.m_x)) + ((this->m_y - to.m_y) * (this->m_y - to.m_y)) + ((this->m_z - to.m_z) * (this->m_z - to.m_z))));
		}

		[[nodiscard]] float dot(ue::math::fvector3& v)
		{
			return this->m_x * v.m_x + this->m_y * v.m_y + this->m_z * v.m_z;
		}
	};
}