#pragma once
#include "Entity.h"

namespace my
{
	class Resource // 추상클래스 
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수
		
		const std::wstring& GetKey() { return fileKey; }
		const std::wstring& GetPath() { return filePath; }

		void setInfo(const std::wstring& key, const std::wstring& path) // 키와 경로 설정
		{ 
			this->fileKey = key; this->filePath = path;  
		};

	private:
		//map에서의 리소스 키, 경로
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