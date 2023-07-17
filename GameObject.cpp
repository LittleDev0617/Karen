#include "GameObject.h"


void SpriteRenderer2D::Render()
{
    char buf[40];
    unsigned int w = sprite->getWidth(), h = sprite->getHeight();
    Pixel* p;
    Vec2 pos { 0, 0 };
    std::string s = "";

    if (sprite->isCompressed())
    {
        p = sprite->getCompressedData();
        for (; pos.y < h; pos.y++)
        {
            ScreenRenderer::GotoXY(gameObject->getPos() + Vec2 { 0, pos.y });
            for (int x = 0; x < w;)
            {
                char buf2[300];
                sprintf_s<40>(buf, "\033[48;2;%d;%d;%dm%%%dc", p->rgb.R, p->rgb.G, p->rgb.B, p->len);
                sprintf_s<300>(buf2, buf, ' ');
                s += buf2;
                x += p->len;
                p++;
            }
            //fprintf(stdout, s.c_str());
            //printf("\n");
            //s += "\n";
        }
        //printf(s.c_str());
        printf("\033[48;2;0;0;0m");
    }
    else
    {
        //for (; pos.y < h; pos.y++)
        //{
        //    for (pos.x = 0; pos.x < w; p++, pos.x++)
        //        ScreenRenderer::SetPixel(pos, (ScreenRenderer::Color)sprite->getPixel(pos));
        //}
    }
}

void SpriteRenderer2D::SetSprite(Sprite* sprite)
{
    if (this->sprite) delete this->sprite;

    this->sprite = sprite;
}