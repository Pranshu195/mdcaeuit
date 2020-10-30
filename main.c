#include"header.h"
#include"declaration.h"

int main()
{



	printf("%s: Begin \n ",__func__);
	init();
	int choice;

	while(1)
	{	
		choice= (*mame)();
		switch (choice)
		{
			case 1:(*comp)();
			//	compression();
				break;
			case 2: (*deco)();
				break;
			case 0:
			       	break;
			default: printf("invalid option\n");
		}

		if(choice == 0)
			break;
	}	
	
	printf("%s: END\n ",__func__);

	return 0;
}
