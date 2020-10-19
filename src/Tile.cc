#include "Tile.hh"

Tile::Tile(float posX, float posY, float scale, float cropSize, sf::Texture*& texture)
{
    sprite = new sf::Sprite(*texture, *(new sf::IntRect(posX, posY, cropSize, cropSize)));
    sprite->setScale(*(new sf::Vector2f(scale, scale)));
}

Tile::~Tile()
{
}

void Tile::Move(float x, float y)
{
    sprite->move(*(new sf::Vector2f(x, y)));
}

void Tile::SetPosition(float x, float y)
{
    sprite->setPosition(*(new sf::Vector2f(x, y)));
}

sf::Sprite* Tile::GetSprite() const
{
    return sprite;
}
