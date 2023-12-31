#pragma once
#include "Sprite.h"
#include "../Utils.h"
#include <windows.h>
#define DEFAULT_BACKGROUND COLOR_BLACK
#define COLOR_TRANSPARENT COLOR_MAGENTA

class ScreenRenderer
{
private:
    static void SetScreenSize(Vec2 pos);
    static void SetBufferSize(Vec2 pos);
    static void SetFontSize(int size);
public:
static char colorTable[16];
static void GotoXY(Vec2 pos);
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
        COLOR_CYAN,
        COLOR_WHITE
    };
    
    static void InitScreen(int fontSize, int width, int height);
    static void SetPixel(Vec2& pos, Color color);
};