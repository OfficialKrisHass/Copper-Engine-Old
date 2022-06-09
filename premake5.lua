workspace "Copper-Engine"
    architecture "x64"
    configurations {"Debug", "Release"}

include "Copper-Engine/lib/GLFW"
include "Copper-Engine/lib/GLAD"

project "Copper-Engine"
    location "Copper-Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir("Build/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")
    objdir("Build/Intermediate/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")

    pchheader "cupch.h"
    pchsource "Copper-Engine/src/cupch.cpp"

    files {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs {

        "%{prj.name}/src",

        "%{prj.name}/lib/spdlog",
        "%{prj.name}/lib/GLFW/include",
        "%{prj.name}/lib/GLAD/include",
        "%{prj.name}/lib/GLM/include"

    }

    links {

        "GLFW",
        "GLAD"

    }

    postbuildcommands {

        "{COPYDIR} assets ../Build/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/assets"

    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines "CU_WINDOWS"

    filter "configurations:Debug"
        defines "CU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CU_RELEASE"
        optimize "On"
