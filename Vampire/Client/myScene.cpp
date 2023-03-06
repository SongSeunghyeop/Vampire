#include "myScene.h"

namespace my
{
	void Scene::Initialize()
	{
		for (Layer& layer : mLayers)
		{
			layer.Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}

	void Scene::Release()
	{
		for (Layer& layer : mLayers)
		{
			layer.Release();
		}
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}

	void Scene::AddGameObj(GameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}
	const std::vector<GameObject*>& Scene::GetGameObj(eLayerType layer)
	{
		return mLayers[(UINT)layer].GetGameObjects();
	}

	Scene::Scene()
	{
		//mLayer.reserve(5);
		mLayers.resize((UINT)eLayerType::END);
	}

	Scene::~Scene()
	{

	}
}
