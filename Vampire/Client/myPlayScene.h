#pragma once
#include "myScene.h"
#include "Krochi.h"
#include "Field.h"

namespace my
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

	private:
		Krochi* krochi;
	};
}