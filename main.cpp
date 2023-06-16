#include "./Components/Render.h"
#include "GameObject.h"

int main()
{	
    ScreenRenderer::InitScreen(3, 140,70);

    GameObject obj1;
    obj1.GetComponent<SpriteRenderer2D>()->SetSprite(new Bitmap("sprites/Knight_1/Protect.bmp"));
    obj1.GetComponent<SpriteRenderer2D>()->Render();
}