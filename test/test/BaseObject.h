#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <CollisionIdentifier.h>
#include <ObjectFactory.h>
#include <SDL_dev\SDL2-2.0.3\include\SDL.h>

class BaseObject{
public:
	CollisionIdentifier *m_ColId;
	BaseObject(void);
	~BaseObject(void);
};

#endif