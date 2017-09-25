#include "GarrysMod/Lua/Interface.h"

#include <git2.h>
#include <git2/clone.h>

#include <string>
//#ifndef _WIN32
//# include <pthread.h>
//# include <unistd.h>
//#endif

using namespace GarrysMod::Lua;

// print to console
void luaPrint(lua_State* state , char* str)
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); // get the globalle cooleo beans table on here

		LUA->GetField(-1, "print"); // giiivee meeeeeee the print function
		LUA->PushString(str); // push the string with it as well
		LUA->Call(1, 0); // call that! with ONE argument and ZERO return values

	LUA->Pop(); // now fock off!
}

// runstring
void luaRunStr(lua_State* state, char* str)
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); // get the globalle cooleo beans table on here

	LUA->GetField(-1, "RunString"); // giiivee meeeeeee the print function
	LUA->PushString(str); // push the string with it as well
	LUA->Call(1, 0); // call that! with ONE argument and ZERO return values

	LUA->Pop(); // now fock off!
}

int cloneRepo(lua_State* state){

	// make sure we get 2 strings
	LUA->CheckType(1, GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2, GarrysMod::Lua::Type::STRING);

	// sik git sgit
	git_repository *repo = NULL;
	const char* url = LUA->GetString(1);
	const char* path = LUA->GetString(1);

	int error = git_clone(&repo, url, path, NULL); // clone and store error code
	
	// also im pretty sure that gmod just like sits in the uh gmod folder like 
	// youd do .\garrysmod\addons\ufap | because is module
	
	LUA->PushNumber(error); 	// youre returning 1 and i think its a good idea to 
						// just return error code to lua and do most of your sgit in lua
						// ie concommand does cloneRepo(arg1,"sgitsgitsgit")
	
	return 1; // Returning one = 1 return value in the luas
}



GMOD_MODULE_OPEN()
{

	luaPrint(state, "autoGIT Loaded! -------------------");


	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB ); // Push the global table
		 LUA->PushCFunction( cloneRepo ); // Push our function
		 LUA->SetField( -3, "cloneRepo" ); // Set MyFirstFunction in lua to our C++ function
		 //			^^^ might have to be -2 i dunno 
		 
	LUA->Pop(); // Pop the global table off the stack							// Set the table 

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}
