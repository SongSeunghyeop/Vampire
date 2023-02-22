#pragma once
#include "Entity.h"

namespace my
{
	class Resource // �߻�Ŭ���� 
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ�
		
		const std::wstring& GetKey() { return fileKey; }
		const std::wstring& GetPath() { return filePath; }

		void setInfo(const std::wstring& key, const std::wstring& path) // Ű�� ��� ����
		{ 
			this->fileKey = key; this->filePath = path;  
		};

	private:
		//map������ ���ҽ� Ű, ���
		std::wstring fileKey;
		std::wstring filePath;
	};

	class Image : public Resource
	{

	};
	class Sound : public Resource
	{

	};
}