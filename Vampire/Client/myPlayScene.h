#pragma once
#include "myScene.h"
#include "Dragon.h"
#include "Field.h"

namespace my
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

		virtual void OnEnter();
		virtual void OnExit();

	private:
		Dragon* dragon;
	};
}