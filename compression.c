#include"header.h"
#include"declaration.h"

int compression()
{
	char *ma;
	int som;
	int cl;
	printf("%s: Begin\n ",__func__);
	int fd;
	fd = (*opfi)("O_RDONLY");
	printf("file open successfully, fd: %d\n",fd);

	ma = (*crma)(fd);
	printf(" %s\n",ma);
	som = strlen(ma);
	cl = (*cole)(som);
	printf("the code length is cl : %d\n",cl);

	switch(cl)
	{
		case 2:
			(*com2)(fd,ma);
			break;
		case 3:
			(*com3)(fd,ma);
			break;
		case 4:
			(*com4)(fd,ma);
			break;
		case 5:
			(*com5)(fd,ma);
			break;
		case 6:
			(*com6)(fd,ma);
			break;
		case 7:
			(*com7)(fd,ma);
			break;
	}

	close(fd);
	printf("%s: END \n",__func__);

	return 0;
}
