#pragma once

namespace offsets::name_pool
{
	constexpr std::uint64_t m_g_names{ 0x9a03e50 };
	constexpr std::uint64_t m_chunk_size{ 0x3f80 };
}

namespace offsets::xenuine
{
	constexpr std::uint64_t m_decrypt{ 0x816cf28 };
}

namespace offsets::world
{
	constexpr std::uint64_t m_u_world{ 0x9814c48 };
	constexpr std::uint64_t m_persistent_level{ 0x798 };
	constexpr std::uint64_t m_owning_game_instance{ 0x928 };
}

namespace offsets::game_instance
{
	constexpr std::uint64_t m_local_players{ 0x38 };
}

namespace offsets::level
{
	constexpr std::uint64_t m_actors_array{ 0x88 };
	constexpr std::uint64_t m_actor_count{ 0x08 };
}

namespace offsets::player
{
	constexpr std::uint64_t m_player_controller{ 0x30 };
}

namespace offsets::player_controller
{
	constexpr std::uint64_t m_acknowledged_pawn{ 0x490 };
	constexpr std::uint64_t m_player_camera_manager{ 0x4b0 };
}

namespace offsets::actor
{
	constexpr std::uint64_t m_root_component{ 0x230 };
	constexpr std::uint64_t m_object_id{ 0x18 };
}

namespace offsets::scene_component
{
	constexpr std::uint64_t m_relative_location{ 0x300 };
}

namespace offsets::pawn
{
	constexpr std::uint64_t m_player_state{ 0x428 };
}

namespace offsets::character
{
	constexpr std::uint64_t m_mesh{ 0x478 };
	constexpr std::uint64_t m_health{ 0x878 };
	constexpr std::uint64_t m_name{ 0x2438 };
	constexpr std::uint64_t m_last_team_num{ 0xf10 };
}

namespace offsets::player_camera_manager
{
	constexpr std::uint64_t m_location{ 0x478 };
	constexpr std::uint64_t m_rotation{ 0x46c };
	constexpr std::uint64_t m_fov{ 0xa04 };
}