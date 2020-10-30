#include"header.h"
#include"declaration.h"

int decompress7(int fdc, char* ma)
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
		printf("byte : %x\n",c);
		fsize--;
		cc = c;
		c >>= 1;
		if( c == 0x7f)
		{
			goto last;
		}
		i = (int)c;
		printf("c : %x\n",i);
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		c = cc;
		c <<= 7;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 2;
		new |= c;
		if( new == 0x7f)
		{
			goto last;
		}
		i = (int)new;
		printf("c : %x\n",i);
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 6;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 3;
		new |= c;
		i = (int)new;
		printf("c : %x\n",i);
		if( new == 0x7f)
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 5;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 4;
		new |= c;
		i = (int)new;
		printf("c : %x\n",i);
		if( new == 0x7f)
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 4;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 5;
		new |= c;
		i = (int)new;
		printf("c : %x\n",i);
		if( new == 0x7f)
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 3;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 6;
		new |= c;
		i = (int)new;
		printf("c : %x\n",i);
		if( new == 0x7f)
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 2;
		c >>= 1;
		new |= c;
		read(fdc, &c, 1);
		fsize--;
		printf("byte : %x\n",c);
		cc = c;
		c >>= 7;
		new |= c;
		if( new == 0x7f)
		{
			goto last;
		}
		i = (int)new;
		printf("c : %x\n",i);
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
		c = cc;
		c <<= 1;
		c >>= 1;
		i = (int)c;
		printf("c : %x\n",i);
		if( c == 0x7f)
		{
			goto last;
		}
		ch = (*fich)(i,ma);
		write(dec,&ch,1);
		new ^= new;
	}
last:
	printf("decompression done\n");
	close(dec);
	printf("%s: END \n",__func__);

	return 0;
}
