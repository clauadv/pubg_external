#pragma once

namespace ue::engine
{
	class u_scene_component
	{
	public:
		ue::math::fvector3 get_relative_location()
		{
			return READ_VEC3(this + offsets::scene_component::m_relative_location);
		}
	};
}