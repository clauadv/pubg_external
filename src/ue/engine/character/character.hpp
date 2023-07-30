#pragma once

namespace ue::engine
{
	class u_character : public ue::engine::u_pawn
	{
	public:
		std::uint64_t get_mesh()
		{
			return READ_UINT64(this + offsets::character::m_mesh);
		}

		float get_health()
		{
			return READ_FLOAT(this + offsets::character::m_health);
		}

		std::uint64_t get_name()
		{
			return READ_UINT64(this + offsets::character::m_name);
		}

		std::int32_t get_last_team()
		{
			return READ_INT32(this + offsets::character::m_last_team_num);
		}
	};
}