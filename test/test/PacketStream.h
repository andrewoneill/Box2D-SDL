#ifndef PACKETSTREAM_H
#define PACKETSTREAM_H

#include <sstream>
#include <Box2D\Box2D.h>

using namespace std;

class PacketStream{
private:
	ostringstream output;
	istringstream input;	

public:
	static enum MESSAGETYPE{GAMEOBJECTUPDATED};
	PacketStream();
	void writeFloat(float);
	void writeInt(int);
	void writeBool(bool);
	void writeString(string);
	void writeVector(b2Vec2);
	void readFloat(float&);
	void readInt(int&);
	void readBool(bool&);
	void readString(string&);
	void readVector(b2Vec2&);
	void toCharArray(char*);
	void fromCharArray(char*);
};


#endif