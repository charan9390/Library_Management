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

