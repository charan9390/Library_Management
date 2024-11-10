a.out:add_books.o display_books.o find_books.o main.o save.o take_books.o count_books.o edit_books_info.o remove_book.o  sync.o getstrings.o
	cc add_books.o display_books.o find_books.o main.o save.o take_books.o count_books.o edit_books_info.o remove_book.o  sync.o getstrings.c


main.o:main.c
	cc -c main.c

add_books.o:add_books.c 
	cc -c add_books.c 

display_books.o:display_books.c
	cc -c display_books.c

find_books.o:find_books.c 
	cc -c find_books.c 

save.o:save.c
	cc -c save.c

take_books.o:take_books.c
	cc -c take_books.c 

count_books.o:count_books.c 
	cc -c count_books.c 

edit_books_info.o:edit_books_info.c 
	cc -c edit_books_info.c 

remove_book.o:remove_book.c 
	cc -c remove_book.c 

getstrings.o:getstrings.c
	cc -c getstrings.c
