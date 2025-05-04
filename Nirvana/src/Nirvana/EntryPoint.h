#pragma once

#ifdef NIRVANA_PLATFORM_WINDOWS

extern Nirvana::Application* Nirvana::CreateApplication();

int main(int argc, char** argv)
{
	Nirvana::Log::Init();
	NIRVANA_CORE_WARN("Initialized Log!");
	NIRVANA_CORE_INFO("Hello! Var={0}", 5);

	auto app = Nirvana::CreateApplication();
	app->Run();
	delete app;
}


#endif // NIRVANA_PLATFORM_WINDOWS
