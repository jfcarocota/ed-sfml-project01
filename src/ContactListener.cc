#include "ContactListener.hh"

ContactListener::ContactListener()
{

}

ContactListener::~ContactListener()
{

}

void ContactListener::BeginContact(b2Contact* contact)
{
    void* bodyData = contact->GetFixtureA()->GetBody()->GetUserData();

    if(bodyData)
    {

    }
}
void ContactListener::EndContact(b2Contact* contact)
{

}