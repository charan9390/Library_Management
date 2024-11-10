#include "main.h"

void save_books_info(struct library *head){
	struct library *tmp=head;
	FILE *fp=fopen("books_details.txt","w");
	while(tmp){
	fprintf(fp,"%s %s %d %d\n",tmp->book_name,tmp->author,tmp->pages,tmp->book_count);
	tmp=tmp->next;
	}
	fclose(fp);
}


