#include "main.h"
struct library* edit_book_info(struct library *head){
	if(head==NULL){
		printf("NO BOOKS TO EDIT\n");
		return head;
	}
	struct library *tmp=head;
	char *Book_name,*Author;
	print_available_books(head);
EDIT:printf("\n============================================\n");
printf("   Enter the details of the book to edit\n");
printf("============================================\n\n");

// Prompt for book name with clear instructions
printf("-> ENTER BOOK NAME: ");
__fpurge(stdin);
Book_name = getstring();

// Prompt for author name with a cleaner presentation
printf("-> ENTER AUTHOR NAME: ");
__fpurge(stdin);
Author = getstring();
	while(tmp){
		int choice=0;
		if((strcmp(tmp->book_name,Book_name)==0)&&(strcmp(tmp->author,Author)==0)){
SELECTION:      printf("SELECT ITEM TO BE EDITED\n");
		printf("1.BOOK NAME  2.AUTHOR 3.BOTH");
		scanf("%d",&choice);
		if(choice==1){
			free(Book_name);
			printf("ENTER NEW NAME:");
			__fpurge(stdin);
			Book_name=getstring();
			free(tmp->book_name);
			tmp->book_name=Book_name;
			Book_name=NULL;
			printf("NAME SUCCESSFULLY EDITED\n");
		}else if(choice==2){
			 free(Author);
                        printf("ENTER NEW NAME:");
                        __fpurge(stdin);
                        Author=getstring();
                        free(tmp->author);
                        tmp->author=Author;
                        Author=NULL;
                        printf("NAME SUCCESSFULLY EDITED\n");
		}else if(choice==3){
			 free(Book_name);
                        printf("ENTER NEW BOOK NAME:");
                        __fpurge(stdin);
                        Book_name=getstring();
                        free(tmp->book_name);
                        tmp->book_name=Book_name;
                        Book_name=NULL;
                        printf("NAME SUCCESSFULLY EDITED\n");
			 
			
			free(Author);
                        printf("ENTER NEW AUTHOR NAME:");
                        __fpurge(stdin);
                        Author=getstring();
                        free(tmp->author);
                        tmp->author=Author;
                        Author=NULL;
                        printf("NAME SUCCESSFULLY EDITED\n");

		}else{
			printf("NO BOOKS FOUND WITH THAT DETAILS \n\nENTER AGAIN");
			goto SELECTION;
		}
		break;
		}
		tmp=tmp->next;
	}
	if(tmp==NULL){
		printf("ENTERED WRONG DETAILS \n\n ENTER AGAIN\n");
		goto EDIT;
	}

	return head;
}

