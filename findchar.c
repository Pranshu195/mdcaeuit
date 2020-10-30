#include"header.h"
#include"declaration.h"

char findchar(int pos, char* ma)
{
	int i;
	int len = strlen(ma);
	for(i = 0; i<len;i++)
	{
		if(i == pos)
		{
			return (*(ma+pos));
		}
	}

}
