#pragma once
#include "myScene.h"
#include "myInput.h"

namespace my
{
	class menuScene : public myScene
	{
	public:
		menuScene();
		~menuScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

	private:
	};
}