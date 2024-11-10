#include "main.h"

struct library *find_book(struct library *head){
	struct library *tmp=head;
	char *bookname,*authorname;
	printf("ENTER BOOK DETAILS TO SEARCH\n");
	printf("ENTER BOOK NAME :");
	__fpurge(stdin);
	bookname=getstring();
	printf("ENTER AUTHOR NAME :");
	__fpurge(stdin);
	authorname=getstring();
	while(tmp){
		if((strcmp(bookname,tmp->book_name)==0)&&(strcmp(authorname,tmp->author)==0)){
			printf("******BOOK FOUND******");
			printf("BOOK NAME :%s AUTHOR NAME: %s PAGES : %d\n",bookname,authorname,tmp->pages);
		}
		tmp=tmp->next;
	}
	free(bookname);
	free(authorname);
	return head;
}



