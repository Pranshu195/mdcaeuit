#include"header.h"
#include"declaration.h"

int unique(char *ma, char ch, int noc)
{
	int i;
	
	if(noc==0)
	{
		return 1;
	}
	for(i=0; i<=noc;i++)
	{
		if(*(ma+i) == ch)
		{
		//	printf("character found ch: = %c\n", ch);
			return 0;
		}
	}	
	return 1;
	printf("%s: END \n",__func__);
}
