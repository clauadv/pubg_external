#pragma once

namespace pubg::defs
{
	extern std::uint8_t* m_base;
}

namespace ue::engine
{
	class u_world
	{
	public:
		static ue::engine::u_world* get()
		{
			return reinterpret_cast<ue::engine::u_world*>(XE_DECRYPT(READ_UINT64(pubg::defs::m_base + offsets::world::m_u_world)));
		}

		ue::engine::u_level* get_persistent_level()
		{
			return reinterpret_cast<ue::engine::u_level*>(XE_DECRYPT(READ_UINT64(this + offsets::world::m_persistent_level)));
		}

		ue::engine::u_game_instance* get_owning_game_instance()
		{
			return reinterpret_cast<ue::engine::u_game_instance*>(XE_DECRYPT(READ_UINT64(this + offsets::world::m_owning_game_instance)));
		}
	};

	inline ue::engine::u_world* m_world{ nullptr };
}