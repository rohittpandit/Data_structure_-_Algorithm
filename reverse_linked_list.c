#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;  
    struct node *next;
};

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

void reverse(struct node **head){
    struct node *next = NULL;
    struct node *current = *head;
    struct node *previous = NULL;
    
    while(current != NULL){
        
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        
    }
    
    *head = previous;
    
    
}

int main() { 
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data =2;
    head->next =  (struct node *)malloc(sizeof(struct node));
    head->next->data = 5;
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->data =  7;
    head->next->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->next->data = 12;
    
    
    
    
    traverse(head);
    printf("\n");
    reverse(&head);
    traverse(head);
    
    
}
