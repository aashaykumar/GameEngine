workspace "Nirvana"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nirvana"
		location "Nirvana"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir ..  "/%{prj.name}")
		objdir ("bin-int/" .. outputdir	.. "/%{prj.name}")
		
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
		

			defines
			{
				"NIRVANA_PLATFORM_WINDOWS",
				"NIRVANA_BUILD_DLL"
			}

			buildoptions {"/utf-8"}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		
		filter "configurations:Debug"
			defines "NIRVANA_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "NIRVANA_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines  "NIRVANA_DIST"
			optimize "On"



project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir ..  "/%{prj.name}")
		objdir ("bin-int/" .. outputdir	.. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		includedirs
		{
			"Nirvana/vendor/spdlog/include",
			"Nirvana/src"
		}
		links
		{
			"Nirvana"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
		

			defines
			{
				"NIRVANA_PLATFORM_WINDOWS"
			}
			buildoptions {"/utf-8"}			
		filter "configurations:Debug"
			defines "NIRVANA_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "NIRVANA_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines  "NIRVANA_DIST"
			optimize "On"
