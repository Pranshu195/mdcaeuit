#include"header.h"
#include"declaration.h"

int decompress3(int fdc, char* ma)
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
		read(fdc,&c,1);
		fsize--;
		cc = c;
		c >>= 5;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------one------------------------------
		c = cc;
		c <<= 3;
		c >>= 5;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------two------------------------------
		c = cc;
		c &= 0x03;
		new = c;
		new <<= 1;
		read(fdc,&c,1);
		fsize--;
		cc = c;
		c >>= 7;
		new |= c;
		if(new == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		//-----------------------------------------------three------------------------------
		c = cc;
		c <<= 1;
		c >>= 5;
		i = (int)c;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------four-------------------------------
		c = cc;
		c <<= 4;
		c >>= 5;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------five------------------------------
		c = cc;
		c &= 0x01;
		new = c;
		new <<= 2;
		read(fdc,&c,1);
		fsize--;
		cc = c;
		c >>= 6;
		new |= c;
		if(new == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		//-----------------------------------------------six------------------------------
		c = cc;
		c <<= 2;
		c >>= 5;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------seven------------------------------
		c = cc;
		c <<= 5;
		c >>= 5;
		if(c == 0x07)
		{
			ch = '\0';
			//write(dec,&ch,1);
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		//-----------------------------------------------eight------------------------------
	}
last:
	close(dec);
	printf("decompression done\n");
	printf("%s: END \n",__func__);

	return 0;
}
