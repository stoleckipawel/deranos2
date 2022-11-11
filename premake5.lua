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
        "%{prj.name}/vendor/GLFW/glfw3native.h",
        "%{prj.name}/vendor/imgui/**.h",
        "%{prj.name}/vendor/imgui/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/glm",
        "%{prj.name}/vendor/KHR",
        "%{prj.name}/vendor/glad",
        "%{prj.name}/vendor/GLFW/include",
        "%{prj.name}/vendor/stb_image",
        "%{prj.name}/vendor/assimp/include",
        "%{prj.name}/vendor/assimp/lib",
        "%{prj.name}/vendor/assimp/dll",
        "%{prj.name}/vendor/imgui",
        "%{prj.name}/vendor"
    }

    libdirs
    {
        "%{prj.name}/vendor/GLFW/lib",
        "%{prj.name}/vendor/assimp/lib"
    }

    links
    {
        "glfw3.lib",
        "opengl32.lib",
        "assimp-vc140-mt.lib",
        "assimp-vc140-mt.dll"
    }

    postbuildcommands 
    {
        '{COPY} "../Deranos/vendor/assimp/dll/assimp-vc140-mt.dll" "%{cfg.targetdir}"'
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

    filter "files:Deranos/vendor/imgui/**.cpp or files:Deranos/vendor/assimp/**.cpp or files:not **.cpp"
        flags 
        { 
            "NoPCH" 
        }


    
    


        
    
    

        

