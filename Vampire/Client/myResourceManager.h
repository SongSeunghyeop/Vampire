#pragma once
#include "myResource.h"

namespace my
{
	class ResourceManager
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			//���ҽ� �ʿ��� ������ Ž��, �����Ͱ� �ִٸ� �ش� ������ ��ȯ
			// ���ٸ� end ��ȯ
			std::map<std::wstring, Resource*> ::iterator it = mResources.find(key);

			if (it != mResources.end()) // it ���� �迭�� �������� �ʴٸ� end �� ��ȯ
				return dynamic_cast<T*>(it->second); // ���ҽ� ��ȯ

			return NULL; // it���� �迭�� �̹� �ִٸ� �ΰ� ��ȯ
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = ResourceManager::Find<T>(key);

			if (resource != NULL)
				return resource;

			resource = new T();

			if (FAILED(resource->Load(path)))
			{
				assert(false);
				return NULL;
			}

			resource->setInfo(key, path);
			mResources.insert(make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}

