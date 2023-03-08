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
	FIELD,
	ITEMS,
	ENEMY,
	MAINITEMS,
	PLAYER_AFTER2,
	PLAYER_AFTER,
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