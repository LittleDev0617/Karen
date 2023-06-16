#pragma once
#include <string>

struct Vec2
{
	int x;
	int y;

	Vec2& operator+(const Vec2& v2)
	{
		x += v2.x;
		y += v2.y;
	}
};

std::string ext(std::string& path);