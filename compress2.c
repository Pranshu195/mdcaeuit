#include"header.h"
#include"declaration.h"

int compress2(int fd, char*ma)
{
	printf("%s: Begin\n ",__func__);
	int fsize, ci;
	unsigned char ch, c,byte;
	fsize = lseek(fd,-1,SEEK_END);
	lseek(fd,0,SEEK_SET);
	int fdn;
	int key;
	printf("enter compressed filename\n");
	fdn = (*opfi)("O_WRONLY|O_CREAT");
	while(fsize>=0)
	{
		byte ^= byte;
		read(fd, &ch,1);
		fsize--;
		//-------------------------------------------------
		ci= (*fiin)(ch, ma);
		sprintf(&c, "%d",ci);
		c <<= 6;
		byte |= c;
		read(fd,&ch,1);
		fsize--;
		if(fsize == 0)
		{
			c = 0x3f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		//-------------------------------------------
		ci = (*fiin)(ch,ma);
		sprintf(&c,"%d",ci);
		c<<=6;
		c>>=2;
		byte |= c;
		read(fd,&ch,1);
		fsize--;
		if(fsize == 0)
		{
			c = 0x0f;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		//----------------------------------------------------
		ci = (*fiin)(ch,ma);
		sprintf(&c,"%d",ci);
		c<<=6;
		c>>=4;
		byte |= c;
		read(fd,&ch,1);
		fsize--;

		if(fsize == 0)
		{
			c = 0x03;
			byte |= c;
			write(fdn,&byte,1);
			goto last;
		}
		//------------------------------------------------------
		ci = (*fiin)(ch,ma);
		sprintf(&c,"%d",ci);
		c<<=6;
		c>>=6;
		byte |= c;
		write(fdn,&byte,1);
	}
last:
	printf("compression done\n");
	printf("enter master key file name\n");
	key = (*opfi)("O_WRONLY|O_CREAT");
	write(key,ma,strlen(ma));
	close(fdn);
	close(key);
	printf("%s: END \n",__func__);

	return 0;
}
