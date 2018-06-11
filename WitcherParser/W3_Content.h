#pragma once
#include <stdio.h>
#include "types.h"

class W3_Content
{
public:
	W3_Content(FILE*, W3_DataInfos);
	~W3_Content(){};
};

class W3_CMaterialInstance
{
public:
	W3_CMaterialInstance(FILE*, W3_DataInfos);
	~W3_CMaterialInstance(){};
};

class W3_CEntityTemplate
{
public:
	W3_CEntityTemplate(FILE*, W3_DataInfos);
	~W3_CEntityTemplate(){};
};

class W3_CEntity
{
public:
	W3_CEntity(FILE*, W3_DataInfos);
	~W3_CEntity(){};
};

class W3_CMeshComponent
{
public:
	W3_CMeshComponent(FILE*, W3_DataInfos);
	~W3_CMeshComponent(){};
};

class W3_CSkeleton
{
public:
	W3_CSkeleton(FILE*, W3_DataInfos);
	~W3_CSkeleton(){};
};

class W3_CAnimationBufferBitwiseCompressed
{
public:
	W3_CAnimationBufferBitwiseCompressed(FILE*, W3_DataInfos);
	~W3_CAnimationBufferBitwiseCompressed(){};
};

class W3_CUnknown
{
public:
	W3_CUnknown(FILE*, W3_DataInfos);
	~W3_CUnknown(){};
};