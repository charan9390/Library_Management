#include "main.h"
struct library *add_book(struct library *head){
	struct library *new_book,*tmp=head;
	new_book=calloc(1,sizeof(struct library));
        printf("ENTER NAME OF BOOK :");
	__fpurge(stdin);

	new_book->book_name=getstring();
	
	printf("ENTER AUTHOR OF BOOK :");
	__fpurge(stdin);
	 
	new_book->author=getstring();

	printf("ENTER NO OF PAGES IN THE BOOK :");
	scanf("%d",&(new_book->pages));

	if(head==NULL){
		head=new_book;
		head->book_count=1;
		new_book=NULL;
	}
	else{
		while(tmp){
if((strcmp(tmp->book_name,new_book->book_name)==0) && (strcmp(tmp->author,new_book->author)==0) && (new_book->pages==tmp->pages)){
				(tmp->book_count)++;
				free(new_book);
				new_book=NULL;
				goto end;
			}
			tmp=tmp->next;
		}
		new_book->next=head;
		new_book->book_count=1;
		head=new_book;
		new_book=NULL;

	}
end:
	return head;
}


