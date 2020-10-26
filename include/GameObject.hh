#include<SFML/Graphics.hpp>
#include "BoxCollider.hh"
#pragma once

class GameObject
{
    protected:
        sf::Texture* texture;
        sf::Sprite* sprite;
        float cropPosX;  
        float cropPosY;
        float cropWidth;
        float cropHeight;
        float scaleX;
        float scaleY;
        BoxCollider* boxCollider;
        float tileBaseWidth;
        float tileBaseHeight;
        sf::RenderWindow* window;
        b2Vec2* startPosition;

        void InitSprite(b2World*&);
    public:
        GameObject(sf::Texture*&, float, float, float, float, float, float, b2Vec2*, b2World*&, sf::RenderWindow*&);
        ~GameObject();
        sf::Sprite* GetSprite();
        void SetPosition(float, float);
        BoxCollider* GetCollider() const;
        void Update();
};
