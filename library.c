#include "main.h"

struct library *remove_book(struct library *head){
	if(head==NULL){
		printf("NO BOOKS IN LIBRARY\n");
	}
		struct library *tmp=head;
		struct library *prev=tmp;
		while(tmp){
			if(tmp->book_count==0){
			if(tmp==head){
				head=tmp->next;
				tmp=head;
				free(prev);
				prev=tmp;
				continue;
			}else{
				prev->next=tmp->next;
				free(tmp);
				tmp=prev->next;
			}
				
			}
			prev=tmp;
			tmp=tmp->next;
		}
		return head;

}
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


struct library *print_available_books(struct library *head){
	
	struct library *tmp=head;
	printf("BOOK NAME                 AUTHOR           PAGES            BOOK COUNT \n");
	while(tmp){
		printf("%s              %s           %d            %d\n\n",tmp->book_name,tmp->author,tmp->pages,tmp->book_count);
		tmp=tmp->next;
	}
	return head;
}

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



struct library* edit_book_info(struct library *head){
	if(head==NULL){
		printf("NO BOOKS TO EDIT\n");
		return head;
	}
	struct library *tmp=head;
	char *Book_name,*Author;
	print_available_books(head);
EDIT:	printf("enter details of the book to be edited...\n");
	printf("ENTER BOOK NAME:");
	__fpurge(stdin);
	Book_name=getstring();
	printf("ENTER AUTHOR NAME:");
	__fpurge(stdin);
	Author=getstring();
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
			printf("WRONG CHOICE \n\nENTER AGAIN");
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





void save_books_info(struct library *head){
	struct library *tmp=head;
	FILE *fp=fopen("books_details.txt","w");
	while(tmp){
	fprintf(fp,"%s %s %d %d\n",tmp->book_name,tmp->author,tmp->pages,tmp->book_count);
	tmp=tmp->next;
	}
	fclose(fp);
}





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




