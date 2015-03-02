#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D\Box2D.h>
#include <CollisionIdentifier.h>
#include <Player.h>
#include <Game.h>
#include <Enemy.h>

using namespace std;
class ContactListener: public b2ContactListener{
public:
	Game *m_game;

	b2World *m_world;
	static ContactListener *me;
	static ContactListener *createListener();
	void setWorld(b2World *world);
	void setGame(Game *game);
	ContactListener(void);
	~ContactListener(void);
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);

private:
	void checkObject(CollisionIdentifier*);
	
	Player *m_player;
	Enemy *m_enemy;
	
};

#endif