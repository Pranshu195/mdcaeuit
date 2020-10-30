#include"header.h"
#include"declaration.h"

int openfile(char *mode)
{

	printf("%s: Begin\n ",__func__);
	int fd;
	char filename[20];
	scanf(" %s", filename);
	if(strncmp(mode, "O_RDONLY", 8) == 0)
	{
		printf("read only \n");
		fd = open(filename, O_RDONLY);	
	}
	else if(strncmp(mode, "O_WRONLY|O_CREAT", 16) == 0)
	{
		printf("create mode\n");
		fd = open(filename,O_WRONLY|O_CREAT);
	}
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("%s: END \n",__func__);

	return fd;
}
