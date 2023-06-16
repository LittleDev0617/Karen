#pragma once
#include "Component.h"
#include "Sprite.h"
#include "../Utils.h"
#include <windows.h>
#define DEFAULT_BACKGROUND COLOR_BLACK

class ScreenRenderer
{
private:
    static char colorTable[16];
    static void SetScreenSize(Vec2 pos);
    static void SetBufferSize(Vec2 pos);
    static void SetFontSize(int size);
    static void GotoXY(Vec2 pos);
public:
    enum Color
    {
        COLOR_BLACK,
        COLOR_BROWN,
        COLOR_GREEN,
        COLOR_OLIVE,
        COLOR_NAVY,
        COLOR_PURPLE,
        COLOR_CADET_BLUE,
        COLOR_GRAY,
        COLOR_LIGHT_GRAY,
        COLOR_RED,
        COLOR_LIME,
        COLOR_YELLOW,
        COLOR_BLUE,
        COLOR_MAGENTA,
        COLOR_CYAN
    };
    
    static void InitScreen(int fontSize, int width, int height);
    static void SetPixel(Vec2& pos, Color color);
};

class SpriteRenderer2D : public Component
{
private:
    Sprite* sprite;

public:
    SpriteRenderer2D(GameObject* parent, Sprite* sprite) : Component(parent), sprite(sprite)
    {
    }

    ~SpriteRenderer2D()
    {
        delete sprite;
    }

    void Render();
    void SetSprite(Sprite* sprite);
};