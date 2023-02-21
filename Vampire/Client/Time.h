#pragma once
#include "CommonInclude.h"

namespace ya
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static double getDeltaTime() { return deltaTime; }

	private:
		static double deltaTime;
		static double mSecond;
		static LARGE_INTEGER mCpuFreq;
		static LARGE_INTEGER mprevCpuFreq;
		static LARGE_INTEGER mcurCpuFreq;
	};
}