#ifndef RCHEEVOS_RHASH_H
#define RCHEEVOS_RHASH_H

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/string.hpp>

extern "C" {
#include "rhash/rc_hash.h"
}

namespace godot
{
	class RCheevosHash : public Object
	{
		GDCLASS(RCheevosHash, Object)

	private:
		static RCheevosHash *singleton;

	protected:
		static void _bind_methods();

	public:
		String get_file_hash(const String &p_path, const int &p_console_id) const;

		static RCheevosHash *get_singleton() { return singleton; }
		static void error_callback(const char *p_message);

		RCheevosHash();
		~RCheevosHash();
	};
}

#endif // RCHEEVOS_RHASH_H