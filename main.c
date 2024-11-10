#include "main.h"



struct library *books=NULL; 
int main(){
	books=sync_library(books);

	struct library * (*p[6])(struct library *);//array of function pointers
	p[0]=add_book;
	p[1]=print_available_books;
	p[2]=book_count;
	p[3]=edit_book_info;
	p[4]=take_book;
	p[5]=find_book;
//	p[6]=save_books_info;
//	p[7]=quit_application;
	char choice;
	printf("=================WELCOME TO LIBRARY====================\n");

	while(1){
choice:printf("*****************************************\n");
	printf("*               MENU                    *\n");
	printf("*****************************************\n");

	// Print menu options with decorative spacing
	printf("* 1 : ADD BOOK                          *\n");
	printf("* 2 : AVAILABLE BOOKS                   *\n");
	printf("* 3 : COUNT OF SPECIFIC BOOK            *\n");
	printf("* 4 : EDIT BOOK INFO                    *\n");
	printf("* 5 : TAKE A BOOK                       *\n");
	printf("* 6 : FIND A BOOK                       *\n");
	printf("* 7 : SAVE BOOKS INFO                   *\n");
	printf("* 8 : QUIT APPLICATION                  *\n");

     // Print menu footer
     printf("*****************************************\n");

     // Prompt for user choice
     printf("ENTER YOUR CHOICE: ");
		__fpurge(stdin);
		choice=getchar()-48;
		if(choice>8||choice<1){
			printf("WRONG CHOICE!!!!\n");
			goto choice;
		}else if(choice >=1 && choice<=6){
			books = p[choice-1](books);
		}else{
			if(choice==7){
				save_books_info(books);
			}else if(choice==8){
				save_books_info(books);
				exit(0);
			}
		}
		

	}
}
