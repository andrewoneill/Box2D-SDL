#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command
{
public:
	virtual ~Command(void);
	virtual void excute() = 0;

protected:
	Command(){};
};

#endif 