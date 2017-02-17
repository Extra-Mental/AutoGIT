#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>

using namespace GarrysMod::Lua;

GMOD_MODULE_OPEN()
{

  /* push functions and arguments */
      LUA->getglobal("print");  /* function to be called */
      LUA->pushnumber("SVN DOWNLOADER LOADED---------------------------------------------------------------------------------");   /* push 1st argument */


      LUA->pop();  /* pop returned value */

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}
