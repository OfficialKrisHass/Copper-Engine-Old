project "GLAD"
    kind "StaticLib"
    language "C"
    staticruntime "On"

    targetdir("Build/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")
    objdir("Build/Intermediate/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")

    files {

        "include/GLAD/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"

    }

    includedirs {

        "include"

    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"