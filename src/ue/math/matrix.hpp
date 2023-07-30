#pragma once

namespace ue::math
{
	class fmatrix44
	{
	public:
		float m[4][4];

        static ue::math::fmatrix44 create(ue::math::frotator rotation, ue::math::fvector3 origin = { 0.f, 0.f, 0.f })
        {
            const float rad_pitch = rotation.m_pitch * DEG_TO_RAD;
            const float rad_yaw = rotation.m_yaw * DEG_TO_RAD;
            const float rad_roll = rotation.m_roll * DEG_TO_RAD;

            const float sin_pitch = std::sinf(rad_pitch);
            const float cos_pitch = std::cosf(rad_pitch);
            const float sin_yaw = std::sinf(rad_yaw);
            const float cos_yaw = std::cosf(rad_yaw);
            const float sin_roll = std::sinf(rad_roll);
            const float cos_roll = std::cosf(rad_roll);

            ue::math::fmatrix44 matrix{};
            matrix.m[0][0] = cos_pitch * cos_yaw;
            matrix.m[0][1] = cos_pitch * sin_yaw;
            matrix.m[0][2] = sin_pitch;
            matrix.m[0][3] = 0.f;

            matrix.m[1][0] = sin_roll * sin_pitch * cos_yaw - cos_roll * sin_yaw;
            matrix.m[1][1] = sin_roll * sin_pitch * sin_yaw + cos_roll * cos_yaw;
            matrix.m[1][2] = -sin_roll * cos_pitch;
            matrix.m[1][3] = 0.f;

            matrix.m[2][0] = -cos_roll * sin_pitch * cos_yaw - sin_roll * sin_yaw;
            matrix.m[2][1] = cos_yaw * sin_roll - cos_roll * sin_pitch * sin_yaw;
            matrix.m[2][2] = cos_roll * cos_pitch;
            matrix.m[2][3] = 0.f;

            matrix.m[3][0] = origin.m_x;
            matrix.m[3][1] = origin.m_y;
            matrix.m[3][2] = origin.m_z;
            matrix.m[3][3] = 1.f;

            return matrix;
        }
	};
}