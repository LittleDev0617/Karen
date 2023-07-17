#pragma once
#include <string>

struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;

	bool operator==(RGB& rgb)
	{
		return R == rgb.R && G == rgb.G && B == rgb.B;
	}

	void operator=(RGB& rgb)
	{
		R = rgb.R;
		G = rgb.G;
		B = rgb.B;
	}
};

struct Pixel
{
	unsigned char len;
	RGB rgb;
};

struct Vec2
{
	int x;
	int y;

	Vec2 operator+(const Vec2& v2)
	{
		Vec2 tmp = *this;
		tmp.x += v2.x;
		tmp.y += v2.y;
		return tmp;
	}

	void operator=(Vec2& v)
	{
		x = v.x;
		y = v.y;
	}

	void operator+=(Vec2& v)
	{
		x += v.x;
		y += v.y;
	}
};

std::string ext(std::string& path);