#include<SFML/Graphics.hpp>
#include "GameObject.hh"
#pragma once

class Collectable : public GameObject
{
    private:

    public:
        Collectable(sf::Texture*&, float, float, float, float, float, float, b2Vec2*, b2World*&, sf::RenderWindow*&);
        ~Collectable();
};


