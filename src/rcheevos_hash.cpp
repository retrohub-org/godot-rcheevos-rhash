#include "rcheevos_hash.h"

#include "rhash/rc_hash.h"

#include <iostream>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void RCheevosHash::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_file_hash", "path", "console_id"), &RCheevosHash::get_file_hash);
}

void RCheevosHash::error_callback(const char *p_message)
{
	std::cout << "[rcheevos-rhash] Error: " << p_message << std::endl;
}

RCheevosHash::RCheevosHash()
{
	rc_hash_init_error_message_callback(error_callback);
	rc_hash_init_default_cdreader();
}

RCheevosHash::~RCheevosHash()
{
}

String RCheevosHash::get_file_hash(const String &p_path, const int &p_console_id) const
{
	char hash[33];
	hash[0] = '\0';
	// The rcheevos API returns 1 on success, and 0 on failure. Because of course it does (╯°□°)╯︵ ┻━┻
	if (rc_hash_generate_from_file(hash, p_console_id, p_path.utf8().get_data())) {
		return String(hash);
	}
	return "";
}
