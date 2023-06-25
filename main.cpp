#define _CRT_SECURE_NO_WARNINGS
#include "./Components/Render.h"
#include "GameObject.h"

int main()
{	    
    ScreenRenderer::InitScreen(1, 50,50);

    GameObject obj1;
    //obj1.GetComponent<SpriteRenderer2D>()->SetSprite(new Bitmap("test5.bmp"));
    obj1.GetComponent<SpriteRenderer2D>()->SetSprite(new Bitmap("sprites/Knight_1/Protect2.bmp"));
    //obj1.GetComponent<SpriteRenderer2D>()->SetSprite(new Bitmap("Resources/defaultSprite24.bmp"));
    obj1.GetComponent<SpriteRenderer2D>()->Render();
}