// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.hpp"

bool main(const int arg_c, char* arg_v[])
{
	LOG_INFO("injector started");

	if (!driver::c_driver::initialize())
	{
		LOG_ERROR("failed to initialize driver");
		return true;
	}

	if (!pubg::initialize())
	{
		LOG_ERROR("failed to initialize pubg");
		return true;
	}

	for (;;)
	{
		pubg::update();

		pubg::c_player::iterate([&](ue::engine::u_actor* actor)
		{
			const auto character = reinterpret_cast<ue::engine::u_character*>(actor);
			if (!character)
				return;

			fmt::print("\n");

			const auto name = reinterpret_cast<pubg::c_player*>(actor)->get_name();
			const auto health = character->get_health();
			const auto team = character->get_last_team();
			const auto position = reinterpret_cast<pubg::c_player*>(actor)->get_position();
			const auto world_to_screen = pubg::c_functions::world_to_screen(position);

			LOG_INFO("name -> {}", name);
			LOG_INFO("health -> {}", health);
			LOG_INFO("team -> {}", team);
			LOG_INFO("position -> ({}, {}, {})", position.m_x, position.m_y, position.m_z);
			LOG_INFO("world_to_screen -> ({}, {}, {})", world_to_screen.m_x, world_to_screen.m_y, world_to_screen.m_z);
		});
	}

	return false;
}