 #pragma once

namespace my
{
	struct Vector2 {

		static Vector2 Up;
		static Vector2 Right;
		static Vector2 One;
		static Vector2 Zero;

		float x, y;
		Vector2() : x(0.0f), y(0.0f) { }
		Vector2(int a, int b) : x(a), y(b) { }
		Vector2(float a, float b) : x(a), y(b) { }

		Vector2(const Vector2&) = default;
		Vector2& operator = (const Vector2&) = default;
		Vector2(Vector2&&) = default;
		Vector2& operator = (Vector2&&) = default;

		Vector2 operator+(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;

			return temp;
		}

		Vector2 operator-(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;

			return temp;
		}

		void operator+=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
		}

		void operator-=(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;
		}
	};
}

