#pragma once

namespace ue::engine
{
	class u_actor
	{
	public:
		ue::engine::u_actor* get_actor(std::int32_t idx)
		{
			return reinterpret_cast<ue::engine::u_actor*>(READ_UINT64(READ_UINT64(this) + (idx * 0x08)));
		}

		std::uint32_t get_object_id()
		{
			return ue::core::f_name_pool::decrypt(READ_INT32(this + offsets::actor::m_object_id));
		}

		std::string get_object_name(std::uint32_t id)
		{
			return ue::core::f_name_pool::get_name_from_id(id);
		}

		ue::engine::u_scene_component* get_root_component()
		{
			return reinterpret_cast<ue::engine::u_scene_component*>(XE_DECRYPT(READ_UINT64(this + offsets::actor::m_root_component)));
		}
	};
}