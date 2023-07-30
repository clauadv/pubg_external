#pragma once

namespace ue::engine
{
	class u_player_camera_manager
	{
	public:
		ue::math::fvector3 get_location()
		{
			return READ_VEC3(this + offsets::player_camera_manager::m_location);
		}

		ue::math::frotator get_rotation()
		{
			return READ_ROT(this + offsets::player_camera_manager::m_rotation);
		}

		float get_fov()
		{
			return READ_FLOAT(this + offsets::player_camera_manager::m_fov);
		}
	};
}