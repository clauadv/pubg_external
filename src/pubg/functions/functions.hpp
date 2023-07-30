#pragma once

namespace pubg
{
	class c_functions
	{
	public:
		static ue::math::fvector3 world_to_screen(ue::math::fvector3 world_location)
		{
			const auto player_camera_manager = pubg::vars::m_player_controller->get_player_camera_manager();
			if (!player_camera_manager)
				return { 0.f, 0.f, 0.f };

			static const auto screen_center = ue::math::fvector2{
				static_cast<float>(GetSystemMetrics(SM_CXSCREEN)) / 2.f,
				static_cast<float>(GetSystemMetrics(SM_CYSCREEN)) / 2.f
			};

			const ue::math::fmatrix44 temp_matrix = ue::math::fmatrix44::create(player_camera_manager->get_rotation());
			ue::math::fvector3 axis_x(temp_matrix.m[0][0], temp_matrix.m[0][1], temp_matrix.m[0][2]);
			ue::math::fvector3 axis_y(temp_matrix.m[1][0], temp_matrix.m[1][1], temp_matrix.m[1][2]);
			ue::math::fvector3 axis_z(temp_matrix.m[2][0], temp_matrix.m[2][1], temp_matrix.m[2][2]);

			auto delta = world_location - player_camera_manager->get_location();
			const ue::math::fvector3 transformed(delta.dot(axis_y), delta.dot(axis_z), delta.dot(axis_x));
			const float z_div = std::max(transformed.m_z, 1.f);

			ue::math::fvector3 screen_location{};
			screen_location.m_x = screen_center.m_x + transformed.m_x * (screen_center.m_x / std::tanf(player_camera_manager->get_fov() * FOV_DEG_TO_RAD)) / z_div;
			screen_location.m_y = screen_center.m_y - transformed.m_y * (screen_center.m_x / std::tanf(player_camera_manager->get_fov() * FOV_DEG_TO_RAD)) / z_div;

			return screen_location;
		}
	};
}