#pragma once

enum class eSceneType
{
	Intro,
	Title,
	TitleUI,
	Play,
	InGameMenu,
	Ending,
	Max,
};

enum class eLayerType
{ // �׷����� ����
	BACKGROUND,
	FIELD,
	ITEMS,
	MONSTERS,
	MAINITEMS,
	PLAYER,
	EFFECT,
	DAMAGE,
	UI,
	END,
};

enum class eComponentType
{
	TRANSFORM,
	COLLIDER,
	SPRITERENDERER,
	ANIMATOR,
	AUDIO,
	END,
};