#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void input(struct node **head, int n) {
    struct node *ptr = *head;
    int i = 0;
	
    printf("Enter the list: ");
    while (i < n) {
        scanf("%d", &ptr->data);
        if(i<n-1){
        	ptr->next = (struct node*)malloc(sizeof(struct node));
        	ptr = ptr->next;
        	}
        i++;
    }
    ptr->next = NULL; // Set the next of last node to NULL
}

int minimum(struct node *ptr){
	int min = ptr->data;
	while(ptr!=NULL){
		if(ptr->data < min){
			min = ptr->data;
		}
		ptr = ptr->next;	
	} 
	return min;
}

void traverse(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n;
    printf("Enter the size of List: ");
    scanf("%d", &n);
    
    struct node *head = (struct node*)malloc(sizeof(struct node));
    
    input(&head, n);
    traverse(head);
    printf("\n");
    printf("The minimum value is: %d", minimum(head));

    // Free memory
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

   
}

