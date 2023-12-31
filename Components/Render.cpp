#include "Render.h"
#include <iostream>

char ScreenRenderer::colorTable[16] = { 0, 4, 2, 6, 1, 5, 3, 8, 7, 12, 10, 14, 1, 13, 11, 15 };

void ScreenRenderer::SetFontSize(int size)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = size;
    cfi.dwFontSize.Y = size;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, TEXT("Raster Fonts"));

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void ScreenRenderer::SetScreenSize(Vec2 pos)
{
	SMALL_RECT p = { 0, 0, pos.x, pos.y };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &p);
}

void ScreenRenderer::SetBufferSize(Vec2 pos)
{
	COORD p = { pos.x, pos.y };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void ScreenRenderer::InitScreen(int fontSize, int width, int height)
{
    SetFontSize(fontSize);
    width = 300;
    height = 400;
    SetBufferSize({ width, height });
    SetScreenSize({ width -1 , height - 1 });
}

void ScreenRenderer::GotoXY(Vec2 pos)
{    
	COORD p = { pos.x, pos.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void ScreenRenderer::SetPixel(Vec2& pos, ScreenRenderer::Color color)
{
    GotoXY(pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorTable[color] << 4);
    std::cout << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorTable[DEFAULT_BACKGROUND] << 4);
}