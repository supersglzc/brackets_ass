#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line); 
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            	enum BracketType type;
                if(next == '(')
                        type = ROUND;
                else if(next == '[')
                        type = SQUARE;
                else
                        type = CURLY;
		//printf("%d\n", type);
		Bracket bracket = {type, position};
		push(opening_brackets_stack, bracket);
        }
        if (next == ')' || next == ']' || next == '}') {
        	Bracket bracket2 = pop(opening_brackets_stack);
		enum BracketType type2;
		if(next == ')')
                        type2 = ROUND;
                else if(next == ']')
                        type2 = SQUARE;
                else
                        type2 = CURLY;
		//printf("here\n");
		//printf("%d\n", bracket2.type);
		//printf("%d\n", type2);
		if(bracket2.type != type2){
			printf("%d\n", position + 1);
			return 0;
		}	
        }
    }
	Bracket head;
	if(!isEmpty(opening_brackets_stack)){
		while(!isEmpty(opening_brackets_stack)){
			head = pop(opening_brackets_stack);
		}
		printf("%d\n", head.position + 1);
		return 0;
	}
	
    // Printing answer, write your code here
	printf("My result is: Success\n");
    return 0;
}
