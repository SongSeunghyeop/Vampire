#pragma once
#include "myScene.h"

namespace ya 
{
	class mySceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

	private:
		static std::vector<myScene*> mScenes;
	};
}
