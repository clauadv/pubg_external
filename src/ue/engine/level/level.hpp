#pragma once

namespace ue::engine
{
	class u_level
	{
	public:
		ue::engine::u_actor* get_actors()
		{
			return reinterpret_cast<ue::engine::u_actor*>(XE_DECRYPT(READ_UINT64(this + offsets::level::m_actors_array)));
		}

		std::int32_t get_actors_size()
		{
			return READ_INT32(this->get_actors() + offsets::level::m_actor_count);
		}
	};
}