#include "main.h"
struct library *book_count(struct library *head){
	if(head==NULL){
		printf("no books to display\n");
		return head;
	}
	struct library *tmp=head;
	char *Book_name=NULL;
	char *Author;
	printf("ENTER BOOK DETAILS...\n");
	printf("ENTER BOOK NAME:");
	__fpurge(stdin);
	Book_name=getstring();
	printf("ENTER AUTHOR:");
	__fpurge(stdin);
	Author=getstring();
       char flag=0;

	while(tmp){
          if((strcmp(tmp->book_name,Book_name)==0) && (strcmp(tmp->author,Author)==0) ){
	  		printf("BOOK :%s\nAUTHOR :%s\nCOUNT :%d\n",Book_name,Author,tmp->book_count);
	  flag=1;
	  }
		tmp=tmp->next;
	}
	if(flag==0){
		printf("NO BOOK FOUND WITH THAT DETAILS\n");
	}
	return head;
}



