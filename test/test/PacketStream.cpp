#include <PacketStream.h>

PacketStream::PacketStream(){
	input.str("");
	output.str("");
}

void PacketStream::writeFloat(float dataIn){
	output<<dataIn<<" ";
}

void PacketStream::writeInt(int dataIn){
	output<<dataIn<<" ";	
}

void PacketStream::writeBool(bool dataIn){
	output<<dataIn<<" ";	
}

void PacketStream::writeString(string dataIn){
	output<<dataIn<<" ";	
}

void PacketStream::writeVector(b2Vec2 dataIn){
	writeFloat(dataIn.x);
	writeFloat(dataIn.y);
}

void PacketStream::readFloat(float& dataOut){
	input>>dataOut;
}

void PacketStream::readInt(int& dataOut){
	input>>dataOut;	
}

void PacketStream::readBool(bool& dataOut){
	input>>dataOut;	
}

void PacketStream::readString(string& dataOut){
	input>>dataOut;	
}

void PacketStream::readVector(b2Vec2& dataOut){
	readFloat(dataOut.x);
	readFloat(dataOut.y);	
}

void PacketStream::toCharArray(char* outputArray){
	string s = output.str();
	memcpy(outputArray, s.c_str() + '\0', s.length()+1);
	output.str("");
}

void PacketStream::fromCharArray(char* inputArray){
	input.str("");
	input.str(inputArray);
}