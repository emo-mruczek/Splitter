all: main expense person sheet link
	
main: 
	g++ -Wall -Werror -c main.cpp -o main.o

expense:
	g++ -Wall -Werror -c Expense.cpp -o expense.o

person:
	g++ -Wall -Werror -c Person.cpp -o person.o

sheet:
	g++ -Wall -Werror -c Sheet.cpp -o sheet.o

link:
	g++ *.o -o main

clean:
	rm *o main


