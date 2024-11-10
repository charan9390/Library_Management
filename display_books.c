#include "main.h"
struct library *print_available_books(struct library *head){
	
	struct library *tmp=head;
	system("clear");
	// Print table header with borders
printf("+------------------+-----------------+----------+------------+\n");
printf("| BOOK NAME        | AUTHOR          | PAGES    | BOOK COUNT |\n");
printf("+------------------+-----------------+----------+------------+\n");

// Print each row with borders
while (tmp) {
    printf("| %-16s | %-15s | %-8d | %-10d |\n", tmp->book_name, tmp->author, tmp->pages, tmp->book_count);
    tmp = tmp->next;
}

// Print table footer
printf("+------------------+-----------------+----------+------------+\n");
	return head;
}

