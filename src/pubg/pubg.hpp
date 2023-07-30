#pragma once

namespace pubg::defs
{
	inline std::uint8_t* m_base{ nullptr };
}

namespace pubg::vars
{
	inline ue::engine::u_player_controller* m_player_controller{ nullptr };
}

namespace pubg
{
	inline bool initialize()
	{
		pubg::defs::m_base = driver::m_driver.get_module_base();
		if (!pubg::defs::m_base)
		{
			LOG_ERROR("failed to get pubg::defs::m_base");
			return false;
		}

		if (!xenuine::initialize())
		{
			LOG_ERROR("failed to initialize xenuine");
			return false;
		}

		ue::core::m_name_pool = ue::core::f_name_pool::get();
		if (!ue::core::m_name_pool)
		{
			LOG_ERROR("failed to get ue::core::m_name_pool");
			return false;
		}

		ue::engine::m_world = ue::engine::u_world::get();
		if (!ue::engine::m_world)
		{
			LOG_ERROR("failed to get ue::engine::m_world");
			return false;
		}

		LOG_INFO("pubg::defs::m_base -> {}", fmt::ptr(pubg::defs::m_base));
		LOG_INFO("ue::core::m_name_pool -> 0x{:x}", ue::core::m_name_pool);
		LOG_INFO("ue::engine::m_world -> {}", fmt::ptr(ue::engine::m_world));

		return true;
	}

	inline bool update()
	{
		if (!ue::engine::m_world)
			return false;

		const auto owning_game_instance = ue::engine::m_world->get_owning_game_instance();
		if (!owning_game_instance)
			return false;

		const auto local_player = owning_game_instance->get_local_player();
		if (!local_player)
			return false;

		pubg::vars::m_player_controller = local_player->get_player_controller();
		if (!pubg::vars::m_player_controller)
			return false;

		return false;
	}
}