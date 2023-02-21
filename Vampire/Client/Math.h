#pragma once

struct Vector2 {

	float x, y;
	Vector2() : x(0.0f), y(0.0f){ }
	Vector2(int a, int b) : x(a), y(b){ }
	Vector2(Vector2& other) : x(other.x), y(other.y){ }
};	