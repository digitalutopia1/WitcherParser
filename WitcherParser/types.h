#pragma once
#include <string>
struct W3_DataInfos
{
public:
	int address;
	int size;

};

struct SPropertyHeader
{
public:
	std::string propName;
	std::string propType;
	int propSize;
	unsigned int endPos;
};

class SMaterial
{
public:
	SMaterial();
	~SMaterial() {}
};