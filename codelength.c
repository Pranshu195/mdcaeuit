#include"header.h"
#include"declaration.h"

int codelength(int som)
{

	printf("%s: Begin\n ",__func__);
	int cl;
	if(som <4)
		cl = 2;
	else if(som <8)
		cl = 3;
	else if(som <16)
		cl = 4;
	else if(som <32)
		cl = 5;
	else if(som <64)
		cl = 6;
	else if(som <128)
		cl = 7;

	printf("%s: END \n",__func__);

	return cl;
}
