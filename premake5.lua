workspace "Copper-Engine"
    architecture "x64"
    configurations {"Debug", "Release"}
    startproject "Engine"

outputDir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

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

        "%{prj.name}/src"

    }

    defines { "CU_ENGINE" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines "CU_SYSTEM_WINDOWS"

    filter "configurations:Debug"
        defines "CU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CU_RELEASE"
        optimize "On"