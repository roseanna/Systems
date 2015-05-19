// Roseanna Chu
// HW 1

#include <stdio.h>
#include <string.h>
#define length 100

enum StateType {START, BSTAR, ESTAR, BCOMM, ECOMM};
enum Boolean {true, false};
enum Boolean is_lit(char *pointer, int size);
void printout(char *pointer, int size);
void main()
{
	char user_input[length];
	char *start;
	int comm_start, comm_end, input_length;
	enum Boolean test;

	printf("Put in some input: ");
	scanf("%[^\n]s", user_input);

	start = user_input;
	input_length = strlen(user_input);
	printout(start, input_length);
}
void printout(char *pointer, int size){
	char *a;
	a = pointer;
	int i = 0;
	enum StateType state = START;

	while (i < size){
		switch (state){
			case START:
				//if theres a literal first, look for the literal
				if(is_lit(a, size) == true){
					if(*(a+i) == '"'){
						printf("\"");
						state = BCOMM;
					}
					else
						printf("%c", *(a+i));
				}
				//the comment is first
				else{
					if(*(a+i) == '/' && *(a+i+1) == '*'){
						state = BSTAR;
					}					
					else
						printf("%c", *(a+i));
				}
				break;
			case BCOMM:
				if(*(a+i) == '"'){
					printf("\"");
					state = ECOMM;
				}
				else
					printf("%c", *(a+i));
				break;
			case BSTAR:
				if(i == size - 1){
					printf("\nError: unterminated comment\n");
				}
				else if(*(a+i) == '*' && *(a+i+1) == '/'){
					printf(" ");
					state = ECOMM;
					i++;
				}
				break;
			case ESTAR:
				printf("%c", *(a+i));
				break;
				// state = START;
			case ECOMM:
				// state = START;
				printf("%c", *(a+i));
				break;
		}
		i++;
	}
	printf("\n");

}

enum Boolean is_lit(char *pointer, int size){
	char *a;
	a = pointer;
	int counter = 0;
	int i = 0;
	int j = 0;
	int start_comm = 0;
	int end_comm = -1;
	int star_slash = -100;
	while(i < size){
		if(*(a+i) == '"'){
			if (counter == 0)
				start_comm = i;
			if(counter == 1)
				end_comm = i;
			counter++;
		}
		i++;
	}
	if(counter >= 2){
		while(j < size){
			if(*(a+j) == '/' && *(a+j+1) == '*'){
				star_slash = j;
				break;
			}
			j++;
		}
		if(star_slash == -100 || star_slash > start_comm)
			return true;
		else
			return true;
	}
	else{
		return false;
	}
} 



