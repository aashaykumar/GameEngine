#pragma once

#include "Core.h"

namespace Nirvana
{
	class NIRVANA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
} // namespace Nirvana