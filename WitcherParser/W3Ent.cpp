
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
			std::cout << "CMaterialInstance" << std::endl;
		}
		else if (dataTypeName == "CEntityTemplate")
		{
			std::cout << "CEntityTemplate" << std::endl;
		}
		else if (dataTypeName == "CEntity")
		{
			std::cout << "CEntity" << std::endl;
		}
		else if (dataTypeName == "CMeshComponent")
		{
			std::cout << "CMeshComponent" << std::endl;
		}
		else if (dataTypeName == "CSkeleton")
		{
			std::cout << "CSkeleton" << std::endl;
		}
		else if (dataTypeName == "CAnimationBufferBitwiseCompressed")
		{
			std::cout << "CAnimationBufferBitwiseCompressed" << std::endl;
		}
		else
		{
			std::cout << "W3_CUnknown" << std::endl;
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
