#pragma once
#include "myScene.h"
#include "Krochi.h"
#include "Krochi_after.h"
#include "Krochi_after2.h"
#include "Enemy1.h"
#include "EnemyPool.h"
#include "Field.h"
#include "myBullet.h"
#include "myCollisionManager.h"
#include "myObject.h"

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
		Enemy1* enemy1;
		EnemyPool* enemyPool;
		float pTime;
	};
}