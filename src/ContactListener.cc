#include "ContactListener.hh"
#include<iostream>
#include "GameObject.hh"
#include <cstring>


ContactListener::ContactListener()
{

}

ContactListener::~ContactListener()
{
    
}

void ContactListener::BeginContact(b2Contact* contact)
{
    GameObject* bodyDataA = (GameObject*) contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject* bodyDataB = (GameObject*) contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyDataA && bodyDataB)
    {
        if(std::strcmp(bodyDataA->GetTagName(), "player") == 0 && std::strcmp(bodyDataB->GetTagName(), "coin") == 0 )
        {
            std::cout << "collected" << std::endl;
        }
        if(std::strcmp(bodyDataA->GetTagName(), "player") == 0 && std::strcmp(bodyDataB->GetTagName(), "treasure") == 0 )
        {
            std::cout << "item" << std::endl;
        }
    }
}
void ContactListener::EndContact(b2Contact* contact)
{

}