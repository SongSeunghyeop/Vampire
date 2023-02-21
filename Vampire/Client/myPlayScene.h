#pragma once
#include "myScene.h"
namespace ya
{
	class PlayScene : public myScene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
	};
}