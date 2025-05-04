#include "Nirvana.h"

class Sandbox : public Nirvana::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Nirvana::Application* Nirvana::CreateApplication()
{
	return new Sandbox();
}
