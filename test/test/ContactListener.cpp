#include <ContactListener.h>


ContactListener *ContactListener::me;

ContactListener *ContactListener::createListener(){
	if(me == NULL){
		me = new ContactListener();
	}
	return me;
}

ContactListener::ContactListener(void){

}

ContactListener::~ContactListener(void){

}

void ContactListener::checkObject(CollisionIdentifier *ident){
	if(ident->m_className == "Player")
		m_player = (Player*)ident->m_baseClass;
	else if(ident->m_className == "Enemy")
		m_enemy = (Enemy*)ident->m_baseClass;
}

void ContactListener::BeginContact(b2Contact *contact){
	bool looking = true;
    b2Fixture *fixtureA = contact->GetFixtureA();
    b2Fixture *fixtureB = contact->GetFixtureB();
    b2Body *body1 = fixtureA->GetBody();
    b2Body *body2 = fixtureB->GetBody();
	CollisionIdentifier *body1Ident = ((CollisionIdentifier*)body1->GetUserData());
	CollisionIdentifier *body2Ident = ((CollisionIdentifier*)body2->GetUserData());
	
	m_player = NULL;

	m_enemy = NULL;

	checkObject(body1Ident);

	checkObject(body2Ident);

}
void ContactListener::EndContact(b2Contact *contact){

}

void ContactListener::setWorld(b2World *world){
	m_world = world;
}

void ContactListener::setGame(Game *game){
	m_game = game;
}
      