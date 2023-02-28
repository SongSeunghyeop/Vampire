#pragma once
#include "myScene.h"
#include "Krochi.h"
#include "Enemy1.h"
#include "EnemyPool.h"
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
		Field* field;
		Krochi* krochi;
		Enemy1* enemy1;
		EnemyPool* enemyPool;
	};
}