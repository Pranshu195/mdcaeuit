#include"header.h"
#include"declaration.h"

int mainmenu()
{

	printf("%s: Begin\n ",__func__);
	int choice;
	printf("------Main Menu------\n");
	
	printf("1. Compression\n");
	printf("2. Decompression\n");
	printf("0. Exit\n");

	printf("enter your choice : ");
	scanf("%d", &choice);
		
	printf("%s: END \n",__func__);

	return choice;
}
