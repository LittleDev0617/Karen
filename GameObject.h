#pragma once
#include "./Components/Bitmap.h"
#include "./Components/Sprite.h"
#include "./Components/Render.h"
#include "Utils.h"
#include <vector>

class GameObject;

class Component
{
protected:
    GameObject* gameObject;
    virtual std::string getName() { return "Component"; };
public:
    Component(GameObject* gameObject) : gameObject(gameObject) {}
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

    void Translate(Vec2 vec)
    {
        pos += vec;
    }
};