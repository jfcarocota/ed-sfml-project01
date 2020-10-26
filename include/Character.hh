#include <SFML/Graphics.hpp>
#include "Animation.hh"
#include "GameObject.hh"
#pragma once

class Character : public GameObject
{
    private:
    
        Animation** animations;

    public:
        Character(sf::Texture*&, float, float, float, float, float, float, b2Vec2*, b2World*&, sf::RenderWindow*&);
        ~Character();
        void FlipSpriteX(float);
        void SetAnimations(Animation**);
        Animation* GetAnimation(int) const;
        void Move(b2Vec2*);
};
