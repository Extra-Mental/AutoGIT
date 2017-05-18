workspace "gm_autogit"
    configurations { "Debug", "Release" }

project "gm_autogit"
    kind         "SharedLib"
    architecture "x86"
    language     "C++"
    includedirs  "../include/"
    targetdir    "bin/%{cfg.buildcfg}"
    symbols      "On"
	defines { "GMMODULE" }
    
    if os.is( "windows" ) then targetsuffix "_win32" end
    if os.is( "macosx" )  then targetsuffix "_osx"   end
    if os.is( "linux" )   then targetsuffix "_linux" end

    configuration "Debug"
        optimize "Debug"

    configuration "Release"
        optimize "Speed"
        flags    "StaticRuntime"

    files
    {
        "src/**.*",
        "../include/**.*"
    }