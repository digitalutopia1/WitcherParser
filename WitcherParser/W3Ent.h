#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "W3_Content.h"
#include "types.h"
struct W3ENT_HEADER
{
public:
	char magic[4];
	int unk1;
	int unk2;
	int unk3;
	int unk4;
	int unk5;
	int unk6;
	int unk7;
	int unk8;
	int unk9;
	int stringChunkStart;
	int stringChunkSize;
	int unk12;
	int unk13;
	int unk14;
	int unk15;
	int unk16;
	int nbFiles;
	int unk18;
	int unk19;
	int unk20;
	int unk21;
	int contentChunkStart;
	int contentChunkSize;
	int unk24;
	int unk25;
	int unk26;
	int unk27;
	int unk28;
	int unk29;
	int unk30;
	int unk31;
	int unk32;
	int unk33;
	int unk34;
	int unk35;
	int unk36;
	int unk37;
	int unk38;
	int unk39;
};



class W3Ent
{
public:
	W3Ent(const char*);
	std::vector<W3_DataInfos> meshes;
	std::vector<std::string> strings;
	std::vector<std::string> files;
	bool ReadPropertyHeader(FILE*, SPropertyHeader&);
	~W3Ent();
};

