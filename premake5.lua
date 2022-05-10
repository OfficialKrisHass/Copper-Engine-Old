workspace "Copper-Engine"
    architecture "x64"
    configurations {"Debug", "Release"}
    startproject "Engine"

outputDir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

include "Engine/lib/GLFW"
include "Engine/lib/GLAD"
include "Engine/lib/ImGui/ImGui"

project "Engine"
    location "Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir("Build/" .. outputDir .. "/%{prj.name}")
    objdir("Build/Intermediate/" .. outputDir .. "/%{prj.name}")

    pchheader "cupch.h"
    pchsource "Engine/src/cupch.cpp"

    files {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        
        "%{prj.name}/lib/stb/stb/stb_image.h",
        "%{prj.name}/lib/stb/stb/stb_image.cpp",

    }

    includedirs {

        "%{prj.name}/src",
        "%{prj.name}/lib/spdlog",
        
        "%{prj.name}/lib/GLFW/include",
        "%{prj.name}/lib/GLAD/include",
        "%{prj.name}/lib/GLM/include",
        "%{prj.name}/lib/ImGui",
        "%{prj.name}/lib/stb"

    }

    links {

        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"

    }

    defines { 

        "CU_ENGINE",
        "CU_EDITOR"

    }

    postbuildcommands {

        "{COPYDIR} assets ../Build/" .. outputDir .. "/%{prj.name}/assets"

    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {

            "CU_SYSTEM_WINDOWS",
            "GLM_ENABLE_EXPERIMENTAL"

        }

    filter "configurations:Debug"
        defines "CU_DEBUG"
        symbols "On"

        buildoptions "/MTd"

        linkoptions {

            '/NODEFAULTLIB:"libcmt.lib"',
            '/NODEFAULTLIB:"msvcrt.lib"',
            '/NODEFAULTLIB:"msvcrtd.lib"'

        }

    filter "configurations:Release"
        defines "CU_RELEASE"
        optimize "On"

        buildoptions "/MT"

        linkoptions {

            '/NODEFAULTLIB:"msvcrt.lib"',
            '/NODEFAULTLIB:"libcmtd.lib"',
            '/NODEFAULTLIB:"msvcrtd.lib"'

        }