#pragma once
#include "myGameObject.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myTransform.h"

namespace my::object
{
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObj(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::getActiveScene();
		scene->AddGameObj(gameObj, type);
		gameObj->Initialize();
		gameObj->GameObject::GetComponent<Transform>()->setPos(pos);
		return gameObj;
	}

	static void Destory(GameObject* obj)
	{
		obj->setState(GameObject::eState::Death);
	}
}