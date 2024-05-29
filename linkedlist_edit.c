#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverse(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insert(int el, int indx, struct node **head) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = el;

    if (indx == 0) {  
        new_node->next = *head;
        *head = new_node;
        return;
    } 

    struct node *ptr = *head;
    int pointer = 1;

    while (pointer < indx && ptr != NULL) {
        ptr = ptr->next;
        pointer++;
    }

    if (ptr == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}

void delete(int indx, struct node **head) {
    int pointer = 1;
    struct node *ptr = *head;

    if (indx == 1) {  
        *head = (*head)->next;
        free(ptr);
        return;
    } 
    
    while (pointer < indx -1){
      ptr = ptr->next;
      pointer++;
    }
    
    struct node *q = ptr->next;
    ptr->next = q->next;
    free(q);
}

int main() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;

    struct node *second = (struct node*)malloc(sizeof(struct node));
    head->next = second;
    second->data = 2;

    struct node *third = (struct node*)malloc(sizeof(struct node));
    second->next = third;
    third->data = 3;
    third->next = NULL;

    insert(9, 3, &head); // Inserting at index 3
    delete(2, &head);

    traverse(head);

    return 0;
}

