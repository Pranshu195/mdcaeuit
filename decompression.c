#include"header.h"
#include"declaration.h"

int decompression()
{

	printf("%s: Begin\n ",__func__);
	int fdc,ekey;
	int szm,cl;
	char *ma;
	ma = (char*)malloc(sizeof(char)*128);
	printf("enter compressed file name to decompress\n");
	fdc = (*opfi)("O_RDONLY");
	printf("file open successfully fdc: %d\n",fdc);
	printf("enter the master key file you have\n");
	ekey = (*opfi)("O_RDONLY");

	printf("file open successfully ekey: %d\n",ekey);

	szm = lseek(ekey,0,SEEK_END);
	lseek(ekey, 0, SEEK_SET);

	read(ekey,ma,szm);
	printf("%s\n",ma);
	cl = (*cole)(szm);
	printf("code length : %d\n",cl);
	switch(cl)
	{
		case 2:
			(*dec2)(fdc,ma);
			break;
		case 3:
			(*dec3)(fdc,ma);
			break;
		case 4:
			(*dec4)(fdc,ma);
			break;
		case 5:
			(*dec5)(fdc,ma);
			break;
		case 6:
			(*dec6)(fdc,ma);
			break;
		case 7:
			(*dec7)(fdc,ma);
			break;
	}
	close(ekey);
	close(fdc);
	printf("%s: END \n",__func__);

	return 0;
}
