#include"header.h"
#include"declaration.h"

int compress3(int fd, char *ma)
{

	printf("%s: Begin\n ",__func__);
	int ci,ekey,fdn;
	unsigned char byte, c,ch,save;
	int fsize;
	fsize = lseek(fd,-1,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("fsize = %d\n",fsize);
	printf("enter compressed file name\n");
	fdn = (*opfi)("O_WRONLY|O_CREAT");
	printf("enter master key file name \n");
	ekey = (*opfi)("O_WRONLY|O_CREAT");
	while(fsize>=0)
	{
		byte ^= byte;
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		c <<= 5;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x1f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		//----------------------------------if-------------------
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		c <<= 5;
		c >>= 3;
		byte |= c;
		//--------------------------if------------------------------
		if(fsize == 0)
		{
			c = 0x03;
			byte |= c;
			write(fdn,&byte,1);
			byte ^= byte;
			c = 0xff;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		save = c;
		c <<= 5;
		c >>= 6;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		byte ^= byte;
		save <<= 7;
		byte |= save;
		//--------------------------------if-------------------------
		if(fsize == 0)
		{
			c = 0x7f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		c <<= 5;
		c >>= 1;
		byte |= c;
		//-----------------------------if-----------------------------
		if(fsize == 0)
		{
			c = 0x0f;
			byte |= c;
			printf("byt: %x\n",byte);
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		c <<= 5;
		c >>= 4;
		byte |= c;
		//----------------------------------if-------------------------
		if(fsize == 0)
		{
			c = 0x01;
			byte |= c;
			write(fdn,&byte,1);
			byte ^= byte;
			c = 0xcf;
			byte |= c;
			write(fdn, &byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		save = c;
		c <<= 5;
		c >>= 7;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
		//-----------------------------if----------------------------
		byte ^= byte;
		save <<= 6;
		byte |= save;
		//---------------------------if------------------------------
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
		c = (unsigned char)ci;
		c <<= 5;
		c >>= 2;
		byte |= c;
		//------------------------if------------------------------------
		if(fsize == 0)
		{
			c = 0x07;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		read(fd,&ch,1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c = (unsigned char)ci;
		c <<= 5;
		c >>= 5;
		byte |= c;
		printf("byte: %x\n",byte);
		write(fdn,&byte,1);
	}
last:
	write(ekey,ma,strlen(ma));
	printf("compression done\n");
	close(fdn);
	printf("%s: END \n",__func__);

	return 0;
}
