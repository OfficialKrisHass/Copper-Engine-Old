project "ImGui"
    kind "StaticLib"
    language "C++"
    
    targetdir("Build/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")
    objdir("Build/Intermediate/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}")

    files
    {
        "imconfig.h",
        "imgui.h",
        "imgui.cpp",
        "imgui_draw.cpp",
        "imgui_internal.h",
        "imgui_widgets.cpp",
        "imstb_rectpack.h",
        "imstb_textedit.h",
        "imstb_truetype.h",
        "imgui_demo.cpp"
    }
    
    filter "system:windows"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "On"
        
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"
