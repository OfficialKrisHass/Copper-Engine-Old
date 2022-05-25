workspace "Copper-Engine"
    architecture "x64"
    configurations {"Debug", "Release"}

project "Copper-Engine"
    location "Copper-Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir("Build/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")
    objdir("Build/Intermediate/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")

    files {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs {

        "%{prj.name}/src",

        "%{prj.name}/lib/spdlog"

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
