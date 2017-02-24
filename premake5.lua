solution "AutoGIT"

  configurations	{"Release"}

	configuration "Release"
		defines { "NDEBUG" }
		flags{ "Optimize", "FloatFast" }

    project "AutoGIT"
      kind "SharedLib"
      language "C++"
      defines { "GMMODULE" }
      files { "src/**.*", "include/**.*"}
      libdirs { "libs" }

      targetdir "bin/%{cfg.buildcfg}"
      includedirs { "../include/**" }
