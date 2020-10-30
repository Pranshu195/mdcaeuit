#include"header.h"
#include"declaration.h"

int decompress2(int fdc, char* ma)
{
	printf("%s: Begin\n ",__func__);	
	int fsize,dec,i;
	unsigned char c,cc,ch;
	printf("enter decompressed file\n");
	dec = (*opfi)("O_WRONLY|O_CREAT");
	fsize = lseek(fdc,0,SEEK_END)-1;
	lseek(fdc,0,SEEK_SET);
	printf("fsize: %d\n", fsize);
	while(fsize>=0)
	{
		read(fdc,&c,1);
		fsize--;
		cc = c;
		c >>= 6;
		//-----------------------------------
		if(c == 0x03)
		{
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c =  cc;
		c <<= 2;
		c >>= 6;
		//-------------------------------------
		if(c == 0x03)
		{
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);

		c =  cc;
		c <<= 4;
		c >>= 6;
		//-------------------------------------
		if(c == 0x03)
		{
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);

		c =  cc;
		c <<= 6;
		c >>= 6;
		//-----------------------------------
		if(c == 0x03)
		{
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
	}
last:
	printf("decompression done\n");
	close(dec);
	printf("%s: END \n",__func__);

	return 0;
}
