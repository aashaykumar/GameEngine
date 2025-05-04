#include "Application.h"

// namespace Nirvana
namespace Nirvana
{
	Application::Application()
	{
	}


	Application::~Application()
	{
	}


	void Application::Run()
	{
		while (true);
	}


	//To be defined in CLIENT
	Application* CreateApplication()
	{
		return new Application();
	}
}
