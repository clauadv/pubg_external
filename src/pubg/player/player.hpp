#pragma once

namespace pubg
{
	class c_player
	{
	public:
		static void iterate(const std::function<void(ue::engine::u_actor*)>& function)
		{
			if (!ue::engine::m_world)
				return;

			const auto persistent_level = ue::engine::m_world->get_persistent_level();
			if (!persistent_level)
				return;

			const auto actors = persistent_level->get_actors();
			if (!actors)
				return;

			const auto actors_size = persistent_level->get_actors_size();
			if (!actors_size)
				return;

			for (auto i{ 0 }; i < actors_size; i++)
			{
				const auto actor = actors->get_actor(i);
				if (!actor)
					continue;

				const auto object_id = actor->get_object_id();
				if (!object_id)
					continue;

				const auto object_name = actor->get_object_name(object_id);
				if (object_name.empty())
					continue;

				if (!(object_name.contains(SK("playermale_a_c")) || object_name.contains(SK("playerfemale_a_c"))))
					continue;

				function(actor);
			}
		}

		std::string get_name()
		{
			const auto character = reinterpret_cast<ue::engine::u_character*>(this);
			if (!character)
				return SK("Invalid");

			const auto name = character->get_name();
			if (!name)
				return SK("Invalid");

			const auto result = ue::core::f_name_pool::read_unicode(name, 24);
			if (result.empty())
				return SK("Invalid");

			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			return converter.to_bytes(result);
		}

		ue::math::fvector3 get_position()
		{
			const auto root_component = reinterpret_cast<ue::engine::u_actor*>(this)->get_root_component();
			if (!root_component)
				return { 0.f, 0.f, 0.f };

			return root_component->get_relative_location();
		}
	};
}