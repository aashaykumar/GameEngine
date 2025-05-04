#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nirvana {
	
	class NIRVANA_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros

#define NIRVANA_CORE_ERROR(...)    ::Nirvana::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NIRVANA_CORE_WARN(...)     ::Nirvana::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define NIRVANA_CORE_INFO(...)     ::Nirvana::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NIRVANA_CORE_TRACE(...)    ::Nirvana::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NIRVANA_CORE_FATAL(...)    ::Nirvana::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros

#define NIRVANA_CORE_ERROR(...)    ::Nirvana::Log::GetClientLogger()->error(__VA_ARGS__)
#define NIRVANA_CORE_WARN(...)     ::Nirvana::Log::GetClientLogger()->critical(__VA_ARGS__)
#define NIRVANA_CORE_INFO(...)     ::Nirvana::Log::GetClientLogger()->info(__VA_ARGS__)
#define NIRVANA_CORE_TRACE(...)    ::Nirvana::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NIRVANA_CORE_FATAL(...)    ::Nirvana::Log::GetClientLogger()->critical(__VA_ARGS__)
