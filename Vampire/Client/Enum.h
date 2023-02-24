#pragma once

enum class eSceneType
{
	Title,
	Play,
	Menu,
	Ending,
	Max,
};

enum class eLayerType
{ // �׷����� ����
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