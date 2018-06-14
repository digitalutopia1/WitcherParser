
#include "W3Ent.h"


W3Ent::W3Ent(const char* fn)
{
	FILE* fh = fopen(fn,"rb");
	W3ENT_HEADER h;
	fread(&h, sizeof(W3ENT_HEADER), 1, fh);
	fseek(fh, h.stringChunkStart, SEEK_SET);
	strings = std::vector<std::string>();
	while (ftell(fh) < h.stringChunkStart + h.stringChunkSize)
	{
		char buffer[256];
		long pos = ftell(fh);
		fread(buffer, 1, sizeof(buffer), fh);
		int len = strlen(buffer);
		std::string tempString;
		tempString.assign(&buffer[0],strlen(&buffer[0]));
		strings.push_back(tempString);
		fseek(fh, pos + len + 1,SEEK_SET);
	}

	files = std::vector<std::string>(h.nbFiles);
	for (int i = 0; i < h.nbFiles; ++i)
	{
		files[i] = strings[strings.size() - h.nbFiles + i];
	}

	fseek(fh, h.contentChunkStart, SEEK_SET);
	meshes = std::vector<W3_DataInfos>();
	for (int i = 0; i < h.contentChunkSize; ++i)
	{
		W3_DataInfos infos;
		unsigned short dataType;
		fread(&dataType, sizeof(unsigned short), 1, fh);
		std::string dataTypeName = strings[dataType];
		fseek(fh, 6, SEEK_CUR);
		fread(&infos, sizeof(W3_DataInfos), 1, fh);
		fseek(fh, 8, SEEK_CUR);
		long back = ftell(fh);
		if (dataTypeName == "CMesh")
		{
			meshes.push_back(infos);
		}
		else if (dataTypeName == "CMaterialInstance")
		{
			W3_CMaterialInstance(fh, infos);
		}
		else if (dataTypeName == "CEntityTemplate")
		{
			W3_CEntityTemplate(fh, infos);
		}
		else if (dataTypeName == "CEntity")
		{
			W3_CEntity(fh, infos);
		}
		else if (dataTypeName == "CMeshComponent")
		{
			W3_CMeshComponent(fh, infos);
		}
		else if (dataTypeName == "CSkeleton")
		{
			W3_CSkeleton(fh, infos);
		}
		else if (dataTypeName == "CAnimationBufferBitwiseCompressed")
		{
			W3_CAnimationBufferBitwiseCompressed(fh, infos);
		}
		else
		{
			W3_CUnknown(fh, infos);
		}

		fseek(fh, back, SEEK_SET);

	}



	std::cout << std::endl;

	fclose(fh);

}


bool W3Ent::ReadPropertyHeader(FILE* fh, SPropertyHeader& ph)
{

	return true;
}

W3Ent::~W3Ent()
{
}
