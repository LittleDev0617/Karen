#pragma once
#include <string>

class GameObject;

class Component
{
protected:
    GameObject* gameObject;
    virtual std::string getName() { return "Component";  };
public:
    Component(GameObject* gameObject) : gameObject(gameObject) {}
};