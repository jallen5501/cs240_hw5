/*********************************************************************
John Allen	April 8 2016
lineholder.c	creates and manages the data structure used for tail.c
 ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lineholder.h"

static char *lines[2000];
static int first, end, current, full;

/***********************************
creats data structure, sizeof nlines
***********************************/
void init_lineholder(int nlines) {	//argument determines size of buffer
	first = current =  0;		//current will keep track of the
	end = nlines - 1;		//index of the of the data structure
	full = 0;			//where I am inserting lines and 
}					//also where to start printing if 
					//the structure is full
/**************************************************************************
takes in a char pointer as an argument, the line that the pointer points to is added into the data structure
dynamic memory allocation: malloc and free. Malloc grants memory for pointers so they can be declared to the perfect length. Whenever you use malloc, 
also I have to use the free command to return memory when I am done using it, this prevents memory leaks
**************************************************************************/
void insert_line(char *line) {
	if (*line > NULL)
		printf("success");
	if (lines[current] != NULL) 	//if lines[current] has a null value
		free((void *)lines[current]);	//free the line from memory
	if ((lines[current] = (char *)malloc(strlen(line) + 1)) != NULL)
		strcpy(lines[current], line); // line is copied to array
	if (++current > end) { // if the current spot exceeds the limit of 
		current = 0;	//the data structure, current == 0.
		full = 1;	//indicates that the structure is full
	}
}
/************************
prints the data structure
************************/
void print_lines() {

	if (!full) {	//if the buffer is not full, print it this way:
		int a = 0;	//start at the first index and print until
		while (lines[a] != NULL) {	//lines[index] == NULL
			printf("%s", lines[a]); // print the line
			free((void *)lines[a++]); //free the previously
		} 				  //allocated memory
	}	else {	//if the structure is full
		while (lines[current] != NULL) { //print at current
			printf("%s", lines[current]); //until 
			free((void *)lines[current]);//lines[current]
			lines[current] = NULL;//       == NULL
			current = ++current > end ? 0 : current;
		}
	}
}

