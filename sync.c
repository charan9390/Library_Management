#include "main.h"

struct library *sync_library(struct library *head){
	FILE *fp=fopen("books_details.txt","r");
	if(fp==NULL){
		return NULL;
	}
	char bookname[20],authorname[20];
	int tmp_pages,tmp_count;
	struct library *tmp_book;
	while(fscanf(fp,"%s %s %d %d",bookname,authorname,&tmp_pages,&tmp_count)==4){
	       tmp_book=calloc(1,sizeof(struct library));
	       tmp_book->book_name=calloc(1,strlen(bookname)+1);
	       strcpy(tmp_book->book_name,bookname);


	       tmp_book->author=calloc(1,strlen(authorname)+1);
               strcpy(tmp_book->author,authorname);

		tmp_book->pages=tmp_pages;
		tmp_book->book_count=tmp_count;
	       	
	 	if(head==NULL){
			head=tmp_book;
			tmp_book=NULL;
		}else{
			tmp_book->next=head;
			head=tmp_book;
			tmp_book=NULL;	
		}
				
	}
	return head;
}



