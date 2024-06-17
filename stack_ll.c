#include <stdio.h>
#include <stdlib.h>

struct stack{
	int el;
	struct stack *next;
};

void traverse(struct stack *top){
	while(top !=NULL){
		printf("%d ", top->el);
		top = top->next;
	}
}


void pop(struct stack **top){
	struct stack *pointer = *top;
	*top = pointer->next;
	pointer->next = NULL;
	free(pointer);
}
	

void push(struct stack **top, int data){
	struct stack *new_stack =  (struct stack *) malloc(sizeof(struct stack));
	
	
	new_stack->el =  data;
	new_stack->next =  *top;
	*top = new_stack;
}

int main (){
	struct stack *top =  NULL;
	
	push(&top, 5);
	push(&top, 9);
	push(&top, 11);
	
	traverse(top);
	
	
	pop(&top);
	printf("\n");
	
	traverse(top);
	
	
}
