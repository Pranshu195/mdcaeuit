#include"header.h"
#include"declaration.h"

int init()
{



	printf("%s: Begin\n ",__func__);

	mame = mainmenu;
	comp = compression;
	deco = decompression;
	opfi = openfile;
	crma = createMasterArray;
	uniq = unique;
	cole = codelength;
	com2 = compress2;
	com3 = compress3;
	com4 = compress4;
	com5 = compress5;
	com6 = compress6;
	com7 = compress7;
	fiin = findindex;
	
	dec2 = decompress2;
	dec3 = decompress3;
	dec4 = decompress4;
	dec5 = decompress5;
	dec6 = decompress6;
	dec7 = decompress7;
	fich = findchar;
	



	printf("%s: END \n",__func__);

	return 0;
}
