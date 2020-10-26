#include "Collectable.hh"

Collectable::Collectable(sf::Texture*& texture, float cropPosX, float cropPosY, float cropWidth, 
float cropHeight, float scaleX, float scaleY, b2Vec2* startPosition, b2BodyType bodyType,b2World*& world, sf::RenderWindow*& window) : 
GameObject(texture, cropPosX, cropPosY,cropWidth, cropHeight, scaleX, scaleY, startPosition, bodyType, world, window)
{

}

Collectable::~Collectable()
{
}