#include "Collectable.hh"

Collectable::Collectable(sf::Texture*& texture, float cropPosX, float cropPosY, float cropWidth, 
float cropHeight, float scaleX, float scaleY, b2World*& world, sf::RenderWindow*& window) : 
GameObject(texture, cropPosX, cropPosY,cropWidth, cropHeight, scaleX, scaleY, world, window)
{
    
}

Collectable::~Collectable()
{
}