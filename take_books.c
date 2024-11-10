#include "main.h"
struct library *take_book(struct library *head){
	if(head==NULL){
		printf("NO BOOKS ARE AVAILABLE IN LIBRARY\n");
		return head;
	}
	char *book,*auth;
	struct library *tmp=head;
	printf("AVAILABLE BOOKS\n");
	print_available_books(head);
	printf("ENTER BOOK NAME :");
	__fpurge(stdin);
	book=getstring();
	printf("ENTER AUTHOR:");
	__fpurge(stdin);
	auth=getstring();
	int taken=0;
	while(tmp){
             if((strcmp(book,tmp->book_name)==0)&&(strcmp(auth,tmp->author)==0)){
		     taken=1;
		     if(tmp->book_count == 1){
			     tmp->book_count--;
			    head = remove_book(head);
			    break;
		     }else{
			     tmp->book_count--;
			     break;
		     }
	     }	     
	     tmp=tmp->next;
	}
	if(taken==1){
	printf("BOOK TAKEN SUCCESSFULLY\n");
	}else{
		printf("BOOK NOT FOUND IN LIBRARY \n");
	}
	return head;



}



