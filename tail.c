/***************************************************************************
John Allen	April 8 2016
Tail.c		conatins main. method, executable function mimics unix utili	    ty function, tail
main {
default argument = 10	if the user enter no argument or one that does not 
			make sense for this program; the program will use 
			this value
While (the input file has more lines) {
	insert the line into the datastrcture describe in lineholder.c
}
	print the last n amount of mines of the file
	n = given argument or default argument
}
***************************************************************************/
#include <stdio.h>
#include "lineholder.h"

int getline1(char s[]);

int main(int argc, char *argv[]) {

int argument = 10;
	
	if (argc == 2)
		argument = abs(atoi(argv[1]));	

	if (argument == 0)
		argument = 10;

	char currentline[500];
	init_lineholder(argument);
	while (getline1(currentline) > 0) {
		insert_line(currentline);
	}
	print_lines();
}

int getline1(char s[]) {
    int i, c;
    for (i=0;(c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }   
    if (c == '\n') {
        s[i++] = c;
    }   
    s[i] = '\0';
    return i;
}

