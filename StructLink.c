/*
Author: Jeff Flanegan
Class: CSC 230
Assignment: M4A3 #12.10
Date: 2019-7-17
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 999

/*
This program uses linked structs (nodes) to function as a stack using pointers
as reference to the self-referencing struct. The user inputs a string of characters
and each character is added to the stack, then each character is printed as it
is popped off the stack, effectively printing the string backwards.
*/

//structure for stack
struct stack{
    char letter;
    struct stack *next;
};

int main()
{
    typedef struct stack Stack;//struct alias
    typedef Stack *StackP;//pointer to struct
    StackP top = NULL;//top of stack pointer
    char text[SIZE+1];//string

    //input
    puts("Enter some text");
    fgets(text,SIZE,stdin);

    StackP newP;//new node pointer
    //add each char to the stack
    for (int i = 0; text[i] != '\0'; i++){//loop while index is not null
        newP = malloc(sizeof(Stack));//allocate memory
        newP->letter = text[i];//store value
        newP->next = top;//walk to top
        top = newP; //null the head
    }
    StackP temp;//pointer holder
    char val;// node value
    //pop the node and print char
    puts("\nYour text backward:");
    while(top != NULL){
        temp = top;
        val = top->letter;
        top = top->next;//walk to next node
        printf("%c", val);
        free(temp);//free memory
    }
    puts("\n");
    return 0;
}
