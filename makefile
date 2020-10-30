#! /bin/bash

mdcaeuit: main.o mainmenu.o compression.o decompression.o openfile.o createMA.o unique.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findindex.o init.o decompress2.o decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o findchar.o
	gcc -o mdcaeuit main.o mainmenu.o compression.o decompression.o openfile.o createMA.o unique.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findindex.o init.o decompress2.o decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o findchar.o



main.o: main.c header.h declaration.h
	gcc -c main.c
mainmenu.o: mainmenu.c header.h declaration.h
	gcc -c mainmenu.c
compression.o: compression.c header.h declaration.h
	gcc -c compression.c
decompression.o: decompression.c header.h declaration.h
	gcc -c decompression.c
openfile.o: openfile.c header.h declaration.h
	gcc -c openfile.c
createMA.o: createMA.c header.h declaration.h
	gcc -c createMA.c
unique.o: unique.c header.h declaration.h
	gcc -c unique.c
codelength.o: codelength.c header.h declaration.h
	gcc -c codelength.c
compress2.o: compress2.c header.h declaration.h
	gcc -c compress2.c
compress3.o: compress3.c header.h declaration.h
	gcc -c compress3.c
compress4.o: compress4.c header.h declaration.h
	gcc -c compress4.c
compress5.o: compress5.c header.h declaration.h
	gcc -c compress5.c
compress6.o: compress6.c header.h declaration.h
	gcc -c compress6.c
compress7.o: compress7.c header.h declaration.h
	gcc -c compress7.c
findindex.o: findindex.c header.h declaration.h
	gcc -c findindex.c
init.o: init.c header.h declaration.h
	gcc -c init.c
decompress2.o: decompress2.c header.h declaration.h
	gcc -c decompress2.c
decompress3.o: decompress3.c header.h declaration.h
	gcc -c decompress3.c
decompress4.o: decompress4.c header.h declaration.h
	gcc -c decompress4.c
decompress5.o: decompress5.c header.h declaration.h
	gcc -c decompress5.c
decompress6.o: decompress6.c header.h declaration.h
	gcc -c decompress6.c
decompress7.o: decompress7.c header.h declaration.h
	gcc -c decompress7.c
findchar.o: findchar.c header.h declaration.h
	gcc -c findchar.c

clean: 
	rm *.o
	rm ./mdcaeuit


