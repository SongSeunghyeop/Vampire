#pragma once

enum class eSceneType
{
	Intro,
	Title,
	Play,
	Option,
	Ending,
	Max,
};

enum class eLayerType
{ // �׷����� ����
	BACKGROUND,
	ITEMS,
	PLAYERAFTER,
	PLAYER,
	ENEMY,
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