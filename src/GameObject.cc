#include "GameObject.hh"

GameObject::GameObject(sf::Texture*& texture, float cropPosX, float cropPosY, float cropWidth, 
float cropHeight, float scaleX, float scaleY, b2Vec2* startPosition, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window)
{
    this->texture = texture;
    this->cropPosX = cropPosX;
    this->cropPosY = cropPosY;
    this->cropWidth = cropWidth;
    this->cropHeight = cropHeight;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->window = window;
    this->startPosition = startPosition;

    tileBaseWidth = cropWidth * scaleX;
    tileBaseHeight = cropHeight * scaleY;

    InitSprite(world, bodyType);
}

GameObject::~GameObject()
{
}

void GameObject::InitSprite(b2World*& world, b2BodyType bodyType)
{
    sprite = new sf::Sprite(*texture, *(new sf::IntRect(cropPosX, cropPosY, cropWidth, cropHeight)));
    sprite->setScale(*(new sf::Vector2f(scaleX, scaleY)));

    boxCollider = new BoxCollider(sprite->getPosition().x, sprite->getPosition().y, new sf::Color(0, 255, 0, 255), cropWidth, cropHeight,
    new Rigidbody(world, bodyType, startPosition, tileBaseWidth / 2, tileBaseHeight / 2, 1, 0, 0),
    sprite);
    boxCollider->GetBoxShape()->setScale(scaleX, scaleY);
    GetCollider()->SetUserData((void*) this);
}

sf::Sprite* GameObject::GetSprite() 
{
    return sprite;
}

void GameObject::SetPosition(float posX, float posY)
{
    sprite->setPosition(posX, posY);
    //boxCollider->SetBodyPosition(new b2Vec2(posX, posY));
}

BoxCollider* GameObject::GetCollider() const
{
    return boxCollider;
}

void GameObject::Update()
{
    boxCollider->UpdatePhysics();
    window->draw(*sprite);
    window->draw(*boxCollider->GetBoxShape());
}

void GameObject::SetTagName(const char* tagName)
{
    this->tagName = tagName;
}

const char* GameObject::GetTagName() const
{
    return tagName;
}