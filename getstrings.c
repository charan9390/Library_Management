#include "main.h"
char *getstring(){
	char *ptr=NULL;
	int i=0;
	do{
		ptr=realloc(ptr,i+1);
		ptr[i]=getchar();

	}while(ptr[i++]!='\n');
	ptr[i-1]='\0';
	return ptr;
}
