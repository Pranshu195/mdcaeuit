#include"header.h"
#include"declaration.h"

int decompress5(int fdc, char* ma)
{
	printf("%s: Begin\n ",__func__);
	
	int fsize, dec, i;
	unsigned char cc,ch,new,c;
	
	printf("enter decompressed file\n");	
	dec = (*opfi)("O_WRONLY|O_CREAT");
	fsize = lseek(fdc,-1,SEEK_END);
	lseek(fdc,0,SEEK_SET);
	printf("fsize: %d\n",fsize);

	while(fsize>0)
	{
		new ^= new;
		read(fdc,&c,1);
		printf("byte: %x\n",c);
		fsize--;
		cc = c;
		c >>= 3;
		if(c == 0x1f)
		{
		//	write(dec,
			goto last;
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c = cc;
		c <<= 5;
		c >>= 5;
		new |= c;
		new <<= 2;
		read(fdc,&c,1);
		
		printf("byte: %x\n",c);
		fsize--;
		cc = c;
		c >>= 6;
		new |= c;
		if(new == 0x1f)
		{
			goto last;		
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 2;
		c >>= 3;
		if(c == 0x1f)
		{
			goto last;		
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c = cc;
		c <<= 7;
		c >>= 3;
		new |= c;
		read(fdc,&c,1);
		printf("byte: %x\n",c);
		fsize--;
		cc = c;
		c >>= 4;
		new |= c;
		if(new == 0x1f)
		{
			goto last;		
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 4;
		c >>= 3;
		new |= c;
		read(fdc,&c,1);
		printf("byte: %x\n",c);
		fsize--;
		cc = c;
		c >>= 7;
		new |= c;
		if(new == 0x1f)
		{
			goto last;		
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 1;
		c >>= 3;
		if(c == 0x1f)
		{
			goto last;		
		}
		i = (int)c;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c = cc;
		c <<= 6;
		c >>= 3;
		new |= c;
		read(fdc, &c,1);
		printf("byte: %x\n",c);
		fsize--;
		cc = c;
		c >>= 5;
		new |= c;
		if(new == 0x1f)
		{
			goto last;		
		}
		i = (int)new;
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c = cc;
		c <<= 3;
		c >>= 3;
		if(c == 0x1f)
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
