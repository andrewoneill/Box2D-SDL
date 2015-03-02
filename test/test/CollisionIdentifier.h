#ifndef COLLISIONIDENTIFIER_H
#define COLLISIONIDENTIFIER_H

#include <string>
using namespace std;
class BaseObject;
class CollisionIdentifier{
public:
	string m_className;
	BaseObject *m_baseClass;
	CollisionIdentifier(void);
	~CollisionIdentifier(void);
};
#include <BaseObject.h>

#endif