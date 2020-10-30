#include"header.h"
#include"declaration.h"

int compress5(int fd, char *ma)
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
	while(fsize>=0)
	{
		byte ^= byte;
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		c <<= 3;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x07;
			cc = 0xc0;
			byte |= c;
			byte |= cc;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		cc = c;
		c <<= 3;
		c >>= 5;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 6;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x3f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		c <<= 3;
		c >>= 2;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x01;
			cc = 0xf0;
			byte |= c;
			byte |= cc;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = cc = (char)ci;
		c <<= 3;
		c >>= 7;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 4;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x0f;
			cc = 0x80;
			byte |= c;
			byte |= cc;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = cc = (char)ci;
		c <<= 3;
		c >>= 4;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 7;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x7c;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		c <<= 3;
		c >>= 1;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x03;
			cc = 0xe0;
			byte |= c;
			byte |= cc;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = cc = (char)ci;
		c <<= 3;
		c >>= 6;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
		c = cc;
		c <<= 5;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x1f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (char)ci;
		c <<= 3;
		c >>= 3;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
	}
last:
	printf("compression done\n");
	printf("enter master key file name to save encryption key\n");
	key = (*opfi)("O_WRONLY|O_CREAT");
	write(key,ma,strlen(ma));
	close(key);
	close(fdn);

	printf("%s: END \n",__func__);

	return 0;
}
