#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isempty(int *top) {
    if (*top == -1)
        return -1;
    else
        return 0; // Ensure to return 0 when stack is not empty
}

char pop(char stack[], int *top) {
    if (*top == -1) // Check if stack is empty before popping
        return '\0'; // Return a default value or handle error appropriately
    char el = stack[*top];
    stack[*top] = '\0';
    (*top)--;
    return el;
}

void push(char stack[], char el, int *top) {
    (*top)++;
    stack[*top] = el;
}

int main() {
    char operator[7] = {'+', '-', '*', '/', '(', ')', '\0'};

    char input[100];
    printf("Write your expression: ");
    fgets(input, sizeof(input), stdin);

    char stack[100];
    int top = -1;

    char postfix[100];

    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        char current_char = input[i];
        int isoperator = 0; // isoperator checks whether the input[i] is operator or not, if it is 0 it means it is not an operator and if it is 1 it is an operator.

        if (i == (strlen(input) - 1)) {
            while (top != -1) {
                postfix[index] = pop(stack, &top);
                index++;
            }
            break;
        }

        for (int j = 0; j < strlen(operator); j++) {
            if (current_char == operator[j]) {
                isoperator++;
                break;
            }
        }

        if (isoperator == 0) {
            postfix[index] = current_char;
            index++;
        } else if (current_char == operator[4] || current_char == operator[5]) {
            if (current_char != operator[5]) {
                if (isempty(&top) == -1) {
                    push(stack, current_char, &top);
                } else {
                    if (stack[top] == operator[0] || stack[top] == operator[1]) {
                        if (current_char == operator[0] || current_char == operator[1]) {
                            postfix[index] = pop(stack, &top);
                            index++;
                            push(stack, current_char, &top);
                        } else {
                            push(stack, current_char, &top);
                        }
                    } else if (stack[top] == operator[2] || stack[top] == operator[3]) {
                        postfix[index] = pop(stack, &top);
                        index++;
                        push(stack, current_char, &top);
                    }
                }
            } else if (current_char == operator[5]) {
                while (stack[top] != operator[4]) {
                    postfix[index] = pop(stack, &top);
                    index++;
                }
                pop(stack, &top); // Pop the '(' from the stack, but not stored in postfix.
            }
        } else {
            if (isempty(&top) == -1) {
                push(stack, current_char, &top);
            } else {
                if (stack[top] == operator[0] || stack[top] == operator[1]) {
                    if (current_char == operator[0] || current_char == operator[1]) {
                        postfix[index] = pop(stack, &top);
                        index++;
                        push(stack, current_char, &top);
                    } else {
                        push(stack, current_char, &top);
                    }
                } else if (stack[top] == operator[2] || stack[top] == operator[3]) {
                    postfix[index] = pop(stack, &top);
                    index++;
                    push(stack, current_char, &top);
                }
            }
        }
    }

    postfix[index] = '\0'; // Ensure postfix expression is null-terminated
    puts(postfix);

    return 0;
}
