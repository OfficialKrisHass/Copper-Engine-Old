workspace "Copper-Engine"
    architecture "x64"
    configurations {"Debug", "Release"}
    startproject "Engine"

outputDir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

include "Engine/lib/GLFW"

project "Engine"
    location "Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir("Build/" .. outputDir .. "/%{prj.name}")
    objdir("Build/Intermediate/" .. outputDir .. "/%{prj.name}")

    files {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs {

        "%{prj.name}/src",
        "%{prj.name}/lib/spdlog",
        "%{prj.name}/lib/GLFW/include"

    }

    links {

        "GLFW",
        "opengl32.lib"

    }

    defines { "CU_ENGINE" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {

            "CU_SYSTEM_WINDOWS",
            "CU_USE_OPENGL",
            "CU_USE_GLFW"

        }

    filter "system:linux"

        defines {

            "CU_SYSTEM_LINUX",
            "CU_USE_OPENGL",
            "CU_USE_GLFW"

        }

    filter "system:macosx"

        defines {

            "CU_SYSTEM_MAC",
            "CU_USE_METAL"

        }

    filter "configurations:Debug"
        defines "CU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CU_RELEASE"
        optimize "On"