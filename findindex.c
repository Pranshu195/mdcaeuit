#include"header.h"
#include"declaration.h"




int findindex(char ch ,char *ma)
{
	
	int len , i = 0;
	len = strlen(ma);
	

	
	for(i = 0; i<=len;i++)
	{
		if(ch == *(ma+i))
		{	
			return (i);
		}
	}
	return(0x0f);
}
