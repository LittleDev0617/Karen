#pragma once
#include "./Components/Component.h"
#include "./Components/Bitmap.h"
#include "./Components/Sprite.h"
#include "./Components/Render.h"
#include "Utils.h"
#include <vector>

class GameObject
{
private:
    Vec2 pos;
    Vec2 scale;
    std::vector<Component*> components;

public:
    Vec2& getPos() { return pos; };

    GameObject() 
    {
        components.push_back(new SpriteRenderer2D(this, new Bitmap("Resources/defaultSprite.bmp")));

        pos.x = 0; pos.y = 0;
        scale.x = 1; scale.y = 1;
    }

    ~GameObject()
    {
        for (int i = 0; i < components.size(); i++)
        {
            delete components[i];
        }
        
    }

    template <class T> T* GetComponent()
    {
        T* com = 0;
        for (int i = 0; i < components.size(); i++)
        {
            if((com = dynamic_cast<T*>(components[i])))
                return com;
        }    
        return nullptr;
    }

};