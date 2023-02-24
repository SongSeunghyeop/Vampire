#pragma once

struct Vector2 {

	float x, y;
	Vector2() : x(0.0f), y(0.0f){ }
	Vector2(int a, int b) : x(a), y(b){ }

	Vector2(const Vector2&) = default;
	Vector2& operator = (const Vector2&) = default;
	Vector2(Vector2&&) = default;
	Vector2& operator = (Vector2&&) = default;
};	 