workspace "Deranos"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Deranos"
    location "Deranos"
    kind "consoleapp"
    language "C++"

    targetdir("bin/" ..  outputdir .. "/%{prj.name}")
    objdir("bin-int/" ..  outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Deranos/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/vendor/glad/glad.c",
        "%{prj.name}/vendor/GLFW/glfw3.h",
        "%{prj.name}/vendor/GLFW/glfw3native.h"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/glm",
        "%{prj.name}/vendor/KHR",
        "%{prj.name}/vendor/glad",
        "%{prj.name}/vendor/GLFW/include"
    }

    libdirs
    {
        "%{prj.name}/vendor/GLFW/lib"
    }

    links
    {
        "glfw3.lib",
        "opengl32.lib"
    }


    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "DERANOS_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        symbols "On"

        defines 
        {
            "DERANOS_DEBUG"
        }

    filter "configurations:Release"
        symbols "On"
        optimize "On"

        defines 
        {
            "DERANOS_RELEASE"
        }

    filter "files:not **.cpp"
        flags
        {
            "NoPCH"
        }

        
    
    

        

