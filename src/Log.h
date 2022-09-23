#pragma once

#include <spdlog/spdlog.h>
#include <memory>

namespace Deranos 
{
	class Log
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

//Core log macros
#define DERANOS_CORE_TRACE(...) ::Deranos::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DERANOS_CORE_INFO(...)  ::Deranos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DERANOS_CORE_WARN(...)  ::Deranos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DERANOS_CORE_ERROR(...) ::Deranos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DERANOS_CORE_FATAL(...) ::Deranos::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define DERANOS_TRACE(...) ::Deranos::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DERANOS_INFO(...)  ::Deranos::Log::GetClientLogger()->info(__VA_ARGS__)
#define DERANOS_WARN(...)  ::Deranos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DERANOS_ERROR(...) ::Deranos::Log::GetClientLogger()->error(__VA_ARGS__)
#define DERANOS_FATAL(...) ::Deranos::Log::GetClientLogger()->fatal(__VA_ARGS__)