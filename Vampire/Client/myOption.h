#pragma once
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"
#include "InGameMenu.h"

namespace my
{
	class Option : public Scene
	{
	public:
		Option();
		~Option();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	/*	virtual void OnEnter();
		virtual void OnExit();*/

	private:
		InGameMenu* menu;
	};
}