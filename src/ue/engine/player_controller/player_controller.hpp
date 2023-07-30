#pragma once

namespace ue::engine
{
	class u_player_controller
	{
	public:
		ue::engine::u_pawn* get_acknowledged_pawn()
		{
			return reinterpret_cast<ue::engine::u_pawn*>(XE_DECRYPT(READ_UINT64(this + offsets::player_controller::m_acknowledged_pawn)));
		}

		ue::engine::u_player_camera_manager* get_player_camera_manager()
		{
			return reinterpret_cast<ue::engine::u_player_camera_manager*>(READ_UINT64(this + offsets::player_controller::m_player_camera_manager));
		}
	};
}