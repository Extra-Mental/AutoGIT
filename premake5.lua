solution "SVNDownloader"

   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   libdirs { "../libs/**" }
   includedirs { "../include/" }

   configurations
	{
		"Release"
	}

	configuration "Release"
		defines { "NDEBUG" }
		flags{ "Optimize", "FloatFast" }

    project "SVNDownloader"
      defines { "GMMODULE" }
      files { "src/**.*", "../include/**.*" }
      kind "SharedLib"
