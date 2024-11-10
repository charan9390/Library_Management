#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct library{
        char *book_name;
        char *author;
        int pages;
        int book_count;
        struct library *next;
};
char *getstring(void);


struct library *add_book(struct library *);

struct library *print_available_books(struct library *);

struct library *book_count(struct library *);

struct library *edit_book_info(struct library *);

struct library *take_book(struct library *);

struct library *find_book(struct library *);

void quit_application();


struct library *remove_book(struct library *);

void save_books_info(struct library *);


struct library *sync_library();
