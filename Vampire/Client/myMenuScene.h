#pragma once
#include "myScene.h"
#include "myInput.h"

namespace my
{
	class MenuScene : public Scene
	{
	public:
		MenuScene();
		~MenuScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

	private:
	};
}