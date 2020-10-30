#include"header.h"
#include"declaration.h"

int compress4(int fd, char *ma)
{
	printf("%s: Begin\n ",__func__);
	int ci,fsize=0;
	unsigned char ch;
	unsigned char c;
	unsigned char byte;
	int fdn;
	fsize = lseek(fd, 0, SEEK_END) - 1;
	int ekey;
	printf("fsize = %d\n",fsize);
	lseek(fd, 0, SEEK_SET);
	printf("enter compressed file\n");
	fdn = (*opfi)("O_WRONLY|O_CREAT");
	printf("enter the master key file\n");
	ekey = (*opfi)("O_WRONLY|O_CREAT");
	while(fsize>=0)
	{
		printf("fsize : %d   ",fsize);
		byte ^= byte;
                read(fd,&ch,1);
                fsize--;
		ci = (*fiin)(ch, ma);
		c= (unsigned char)ci;
		printf("char c: %d\n",c);
		c = c<<4;
		byte |= c;
		if(fsize == 0)
		{
			c = 0x0f;
			byte |= c;
			write(fdn,&byte,1);
			goto ret;
		}
		read(fd, &ch, 1);
		fsize--;
		ci = (*fiin)(ch,ma);
		c= (unsigned char)ci;
		printf("char c2: %d\n",c);
		c= c<<4;
		c= c>>4;
		byte |= c;
		printf("byte: %d\n",byte);
		write(fdn,&byte,1);
	}
ret:
	write(ekey,ma,strlen(ma));
	close(ekey);
	close(fdn);
	printf("compression done\n");
	printf("%s: END \n",__func__);
	
	return 0;
}
