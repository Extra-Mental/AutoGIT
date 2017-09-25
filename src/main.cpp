#include "GarrysMod/Lua/Interface.h"

#include <git2.h>
#include <git2/clone.h>

#include <string>
//#ifndef _WIN32
//# include <pthread.h>
//# include <unistd.h>
//#endif

using namespace GarrysMod::Lua;

int cloneRepo(lua_State* state){

	LUA->CheckType(1, GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2, GarrysMod::Lua::Type::STRING);

	git_repository *repo = NULL;
	const char* url = LUA->GetString(1);
	const char* path = LUA->GetString(1);

	int error = git_clone(&repo, url, path, NULL);

	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); // Push the global table
	LUA->GetField(-1, "print"); // Get the print function
	LUA->PushNumber(error);
	LUA->Call(1, 0); // Call the function
	LUA->Pop();

	
	return 1;
}

GMOD_MODULE_OPEN()
{

	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); // Push the global table
	LUA->GetField(-1, "print"); // Get the print function
	LUA->PushString("AutoGIT Loaded---------------------------------------------------------------------"); // Push our argument
	LUA->Call(1, 0); // Call the function
	LUA->Pop(); // Pop the global table off the stack

	//LUA->CreateTable();
		//LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); // Push the global table
		//LUA->PushCFunction(cloneRepo); // Push our function
		//LUA->SetField(-2, "__cloneRepo"); // Set MyFirstFunction in lua to our C++ function
		//LUA->Pop(); // Pop the global table off the stackc
	//metatable = LUA->ReferenceCreate();

	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);	// Push global table
	LUA->PushString("cloneRepo");					// Push Name
	LUA->PushCFunction(cloneRepo);			// Push function
	LUA->SetTable(-3);								// Set the table 

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}
