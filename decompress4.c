#include"header.h"
#include"declaration.h"



int decompress4(int fdc, char* ma)
{
	printf("%s: Begin\n ",__func__);
	int fsize,dec,i;
	unsigned char cc,sav;
	unsigned char ch;
	printf("enter decompressed file\n");
	dec = (*opfi)("O_WRONLY|O_CREAT");
	fsize = lseek(fdc,0,SEEK_END)-1;
	lseek(fdc,0,SEEK_SET);
	printf("fsize: %d\n", fsize);
	while(fsize>=0)
	{
		read(fdc,&ch,1);
		printf("byte: %x\n",ch);
		fsize--;
		sav = ch;
		ch >>= 4;
		i = (int)ch;
		cc = (*fich)(i,ma);
		write(dec,&cc,1);
		sav <<= 4;
		sav >>= 4;
		if( sav == 0x0f)
		{
			write(dec,'\0',1);
			goto last;
		}
		i = (int)sav;
		cc= (*fich)(i,ma);
		write(dec,&cc,1);
		
	}
last:
	printf("decompression done\n");
	close(dec);
	printf("%s: END \n",__func__);

	return 0;
}
