#include"header.h"
#include"declaration.h"

int decompress6(int fdc, char* ma)
{
	printf("%s: Begin\n ",__func__);
	int fsize, dec, i;
	unsigned char cc,ch,new,c;
	
	printf("enter decompressed file\n");	
	dec = (*opfi)("O_WRONLY|O_CREAT");
	fsize = lseek(fdc,-1,SEEK_END);
	lseek(fdc,0,SEEK_SET);
	printf("fsize: %d\n",fsize);

	while(fsize>=0)
	{
		new ^= new;
		read(fdc,&c,1);
		fsize--;
		cc = c;
		c >>= 2;
		if( c == 0x3f )
		{
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//----------------------------one---------------------
		c = cc;
		c <<= 6;
		c >>= 2;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		cc = c;
		c >>= 4;
		new |= c;
		i = (int)new;
		if( new == 0x3f )
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		//------------------------two-----------------------
		c = cc;
		c <<= 4;
		c >>= 2;
		new |= c;
		read(fdc, &c,1);
		fsize --;
		cc = c;
		c >>= 6;
		new |= c;
		i = (int) new;
		if( new == 0x3f )
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		//-------------------------three---------------------
		c = cc;
		c <<= 2;
		c >>= 2;
		i = (int)c;
		if( c == 0x3f )
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------four-------------------------

	}

last:
	printf("decompression done\n");
	close(dec);

	printf("%s: END \n",__func__);

	return 0;
}
