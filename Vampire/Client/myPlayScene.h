#pragma once
#include "myScene.h"
#include "Krochi.h"
#include "Krochi_after.h"
#include "Krochi_after2.h"
#include "Enemy1.h"
#include "EnemyPool.h"
#include "Field.h"
#include "myCollisionManager.h"

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
		Krochi_after* krochi_after;
		Krochi_after2* krochi_after2;
		Enemy1* enemy1;
		EnemyPool* enemyPool;
	};
}