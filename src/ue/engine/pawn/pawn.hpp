#pragma once

namespace ue::engine
{
	class u_pawn : public ue::engine::u_actor
	{
	public:
		std::uint64_t get_player_state()
		{
			return XE_DECRYPT(READ_UINT64(this + offsets::pawn::m_player_state));
		}
	};
}