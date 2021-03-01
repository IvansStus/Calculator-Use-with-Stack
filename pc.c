// Ivan Stus cssc1719
// CS320Lab2 - pc.c 
// README - USE $ for multiplication, instead of *
 
#include <stdio.h>  //Used for printf, standard output
#include <stdlib.h> //Used for atoi
#include <string.h> //Used for strcmp
#include <ctype.h>  //Used for isdigit number checking

//Initialize variables needed for stack
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

//Creates the stack
struct Stack* createStack(unsigned capacity) { 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

//Pushes to top of stack 
void push(struct Stack* stack, int item) {  
    stack->array[++stack->top] = item;  
}

//Pops the top of stack 
int pop(struct Stack* stack) { 
    return stack->array[stack->top--]; 
} 

//Checks to see if argv[i] is a number, returns true/false
int isNumber(char number[]) {
    int i = 0;
    for (; number[i] != 0; i++) {
        if (!isdigit(number[i]))
            return 0;   //Returns false(0) if argv[i] is not a number
    }
    return 1;   //Returns true(1) if argv[i] is a number
}

//Calculates result given two operands and a operator, returns int 
int calc(char *sign, int op1, int op2) {
    int result = 0;
    if ((strcmp(sign, "+") == 0)) {
        result = op1 + op2;
    }
    if ((strcmp(sign, "-") == 0)) {
        result = op1 - op2;
    }
    if ((strcmp(sign, "$") == 0)) {
        result = op1 * op2;
    }
    if ((strcmp(sign, "/") == 0)) {
        result = op1 / op2;
    }
    return result;
}


//DRIVER, Main code
int main(int argc, char *argv[]) {
    struct Stack* stack = createStack(100);     //Creates stack
    int i = 1;      //Variable initializations
    int op1 = 0;
    int op2 = 0;
    int res = 0;
    if (argc > 1) {     //Checks to see if user input is greater than 1
        while (argv[i] != NULL) {       //Condition until end of the command line
            if (isNumber(argv[i]) == 1) {      
                int arg = atoi(argv[i]);    //Turns argv[i] into an integer
                push(stack, arg);       //Pushes argv[i] onto stack
            }
            else if ((isNumber(argv[i]) == 0) & ((strcmp(argv[i], "+") == 0) | (strcmp(argv[i], "-") == 0) | (strcmp(argv[i], "$") == 0) | (strcmp(argv[i], "/") == 0))) {      //Case for if argv[i] is not a number and checks to see if it is an acceptable operator
                op1 = pop(stack);   //Pop top two operands
                op2 = pop(stack);
                res = calc(argv[i], op1, op2);      //Carry out calculation
                push(stack, res);   //Pushes result of calculation back onto stack
            }
            else {      //Checks to see if any invalid characters are in input
                printf("Input Error, Try Again");
                exit(0);
            }
            i++;    //Iterating while loop
        }
        printf("The final result is %d", pop(stack));       //FINAL RESULT
        exit(1);
    }
    else {      //Checks to see if initial input is valid
        printf("Input Error, Try Again");
        exit(0);
    }
}