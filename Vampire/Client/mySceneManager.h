#pragma once
#include "myScene.h"

namespace my 
{
	class mySceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

		static void LoadScene(eSceneType type);

	private:
		static std::vector<myScene*> mScenes;
		static myScene* activeScene; 
	};
}

