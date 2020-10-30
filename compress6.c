#include"header.h"
#include"declaration.h"

int compress6(int fd, char *ma)
{
	printf("%s: Begin\n ",__func__);
	int fsize, ci;
	unsigned char ch, c,cc,byte;
	fsize = lseek(fd,-1,SEEK_END);
	lseek(fd,0,SEEK_SET);
	int fdn;
	int key;
	printf("enter compressed filename\n");
	fdn = (*opfi)("O_WRONLY|O_CREAT");
	printf("enter master key file name\n");
	key = (*opfi)("O_WRONLY|O_CREAT");
	while(fsize>=0)
	{
		byte ^= byte;
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		c <<= 2;
		byte |= c;
		//------------------------------------
		if( fsize == 0 )
		{
			c = 0x03;
			byte |= c;
			write(fdn, &byte, 1);
			byte ^= byte;
			cc = 0xf0;
			byte |= cc;
			write(fdn, &byte, 1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		cc = c;
		c <<= 2;
		c >>= 6;
		byte |= c;
		//----------------------------------
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 4;
		byte |= c;
		if( fsize == 0 )
		{
			c = 0x0f;
			byte |= c;
			write(fdn, &byte, 1);
			byte^= byte;
			cc = 0xc0;
			byte |= cc;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char) ci;
		cc = c;
		c <<= 2;
		c >>= 4;
		byte |= c;
		//----------------------------------
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 6;
		byte |= c;
		if( fsize == 0 )
		{
			c = 0x3f;
			byte |= c;
			write(fdn, &byte, 1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char) ci;
		c <<= 2;
		c >>= 2;
		byte |= c;
		//--------------------------------
		write(fdn,&byte,1);

	}
last:
	write(key, ma, strlen(ma));
	close(key);
	printf("compression done\n");
	close(fdn);
	printf("%s: END \n",__func__);
	return 0;
}
