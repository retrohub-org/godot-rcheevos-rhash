#include "register_types.h"

#include "rcheevos_hash.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static RCheevosHash *singleton = nullptr;

void initialize_rcheevos_rhash_module(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}

	ClassDB::register_class<RCheevosHash>();
	singleton = memnew(RCheevosHash);
	Engine::get_singleton()->register_singleton("RCheevosHash", singleton);
}

void uninitialize_rcheevos_rhash_module(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}

	Engine::get_singleton()->unregister_singleton("RCheevosHash");
	memdelete(singleton);
}

extern "C"
{
	// Initialization.
	GDExtensionBool GDE_EXPORT rcheevos_rhash_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_rcheevos_rhash_module);
		init_obj.register_terminator(uninitialize_rcheevos_rhash_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}