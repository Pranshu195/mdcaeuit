int init();
int mainmenu();
int compression();
int decompression();
int openfile(char*);


char* createMasterArray(int );
int unique(char*, char, int);
int codelength(int);
int compress2(int, char *);
int compress3(int, char *);
int compress4(int, char *);
int compress5(int, char *);
int compress6(int, char *);
int compress7(int, char *);
int findindex(char , char *);
int decompress2(int, char *);
int decompress3(int, char *);
int decompress4(int, char *);
int decompress5(int, char *);
int decompress6(int, char *);
int decompress7(int, char *);
char findchar(int , char *);
 
 
//----------------------------------------pointer funtions ----------------//

int (*mame)();
int (*comp)();
int (*deco)();

int (*opfi)(char *);
char* (*crma)(int);
int (*uniq)(char*, char, int);
int (*cole)(int);

int (*com2)(int, char*);
int (*com3)(int, char*);
int (*com4)(int, char*);
int (*com5)(int, char*);
int (*com6)(int, char*);
int (*com7)(int, char*);
int (*fiin)(char, char*);

int (*dec2)(int, char*);
int (*dec3)(int, char*);
int (*dec4)(int, char*);
int (*dec5)(int, char*);
int (*dec6)(int, char*);
int (*dec7)(int, char*);
char (*fich)(int, char*);


