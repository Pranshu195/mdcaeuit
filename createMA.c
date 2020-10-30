#include"header.h"
#include"declaration.h"

char* createMasterArray(int fd)
{

	printf("%s: Begin\n ",__func__);
	int i=0;
	int fsize; 
	char *ma;
	ma = NULL;
	char ch;

	fsize = lseek(fd, 0, SEEK_END) - 1;
	lseek(fd, 0, SEEK_SET);
	int k=0;
	while(fsize)
	{
		read(fd,&ch,1);
		if((*uniq)(ma,ch,i))
		{
			ma = realloc(ma,(k+1));
			*(ma+k) = ch;
			k++;
		}
		i++;
		fsize--;
	}
	*(ma+k) = '\0';
	printf("%s: END \n",__func__);

	return ma;
}
