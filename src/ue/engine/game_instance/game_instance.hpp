#pragma once

namespace ue::engine
{
	class u_game_instance
	{
	public:
		ue::engine::u_player* get_local_player()
		{
			return reinterpret_cast<ue::engine::u_player*>(XE_DECRYPT(READ_UINT64(READ_UINT64(this + offsets::game_instance::m_local_players))));
		}
	};
}