#include <stdio.h>
#include <string.h>

char operator[7] = {'+', '-', '*', '/', '(', ')', '\0'};
char input[100];
char stack[30];
int top = -1;
char postfix[100];

int isEmpty() {
    if (top == -1)
        return 1;  // Return 1 if stack is empty
    else
        return 0;  // Return 0 if stack is not empty
}

int precedence(char curr_char) {
    if (curr_char == operator[0] || curr_char == operator[1]) // if curr_char = + or - then it return 0  
        return 0;
    else if (curr_char == operator[2] || curr_char == operator[3])  // else if curr_char = * or /  then it returns 1
        return 1;
    else if (curr_char == operator[4]) // else if curr_char = openbracket then it returns 2
        return 2;
    else if (curr_char == operator[5]) // else if curr_char = closing bracket then it returns 3
        return 3;
    else
        return -1; // if it is not anything above it means curr_char is operand.
}

void push(char curr_char) { // push function insert the operators in the top of stack 
    top++;
    stack[top] = curr_char;
}

char pop() {  // pop function removes the operator from the top of stack and return the removed element
    if (isEmpty() == 1)
        return '\0';  // Return null character if stack is empty
    else {
        char el = stack[top];
        stack[top] = '\0';
        top--;
        return el;
    }
}

int main() {
    int index = 0;
    printf("Enter the expression: ");
    fgets(input, sizeof(input), stdin);  // It takes input from the user

    for (int i = 0; i < strlen(input); i++) {  // i created a loop to scan all element of input, and it scans till the length of input
        char curr_char = input[i];       // current character stores the elment of input at i index
        
        if(i == strlen(input)-1){  // if i =  strlen(input)-1 it pops all the element of the stack, it means if the scanning is completed no element left in the input it pop all the element of the stack in the postfix array
            while(isEmpty()!=1){
                postfix[index] = pop();
                index++;
            }
        }

        if (precedence(curr_char) == -1) { // if precedence(curr_char) returns -1 it means it is operand, and operand stores in the postfix array.
            postfix[index] = curr_char;
            index++;
        } else if (isEmpty() == 1) { // if stack is empty and precedence(curr_char) is operator than it push the operator in the stack
            push(curr_char);
        } else if ((isEmpty() == 0 && stack[top] == operator[4]) || (isEmpty() == 0 && precedence(curr_char) > precedence(stack[top]) && curr_char != operator[5])) { 
  //in this condition i have taken 2 condition in or basis means one  should be true to satisfy whole condition, first condition says if stack is not empty and stack[top] = opening bracket than push the operator, because we know the opening bracket is higher precedence than other operator, so if stack[top] has opening bracket, we cannot able to push the element. Second condition is " if stack is not empty, and precedence(current character) > precedence(stack[top]) and current character should not be closing bracket than push the element, that condition means if current character has more precedence than the stack[top] element, than we need to push the element in the stack, but we also need to keep in mind about closing bracket, because we know closing bracket is also has higher precedence, so we don't want to push closing bracket in the stack.
            push(curr_char);
        } else if (isEmpty() == 0 && curr_char == operator[5]) {
// in this condition if current character found that it is closing bracket and top is not empty than it pop all the element from the stack and push into postfix array
            while (stack[top] != operator[4]) {
                postfix[index] = pop();
                index++;
            }
            pop();
        } else if (isEmpty() == 0 && precedence(curr_char) <= precedence(stack[top])) {
// in this condition if stack is not empty and precedence of current character is less than or equal to  precedence of stack top, we need to remove top element of stack and push into postfix array.
            postfix[index] = pop();
            index++;
            push(curr_char);
        }
    }

   

    postfix[index] = '\0'; // we close the postfix index.

    printf("The postfix expression is:  %s\n", postfix);

    
    return 0;
}
	
	
