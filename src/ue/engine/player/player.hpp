#pragma once

namespace ue::engine
{
	class u_player
	{
	public:
		ue::engine::u_player_controller* get_player_controller()
		{
			return reinterpret_cast<ue::engine::u_player_controller*>(XE_DECRYPT(READ_UINT64(this + offsets::player::m_player_controller)));
		}
	};
}