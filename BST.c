#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

void search(struct tree *head, int search_el){
    if(head == NULL){
        printf("NO data available");
    }

    if(head->data == search_el){
        printf("Element found");
    }
    else if(head->data > search_el){
        search(head->left, search_el);
    }
    else if(head->data < search_el){
        search(head->right, search_el);
    }
    else printf("Not Found");
}

int max_left(struct tree *head){
   if(head==NULL){
    return -1;
   }
   if(head->left->right==NULL) return head->left->data; 
   else head = head->left;
   while(head->right!=NULL){
    head = head->right;
   }
   return head->data;
}

int max(struct tree *head){
    if(head == NULL){
        return -1;
    }
    while(head->right!=NULL){
        head = head->right;
    }
    return head->data;
}

void insert(struct tree **head, int data){
    if(*head==NULL){
        *head = (struct tree*)malloc(sizeof(struct tree));
        (*head)->data = data;
        (*head)->right = NULL;
        (*head)->left = NULL;
    }
    else if(((*head)->data > data)){
        insert(&((*head)->left), data);
    }
    else insert(&((*head)->right), data);
}

void inorder(struct tree *head){
    if(head!=NULL){
        inorder(head->left);
        printf("%d ", head->data);
        inorder(head->right);
    }
}

void delete(struct tree **head, int data){
    if(*head == NULL){
        printf("N0 Element");

    }

    if((*head)->data>data){
        delete(&(*head)->left, data);
    }
    else if((*head)->data<data){
        delete(&(*head)->right, data);
    }
    else{
        // NO children
        if((*head)->right == NULL && (*head)->left == NULL){
            free(*head);
            *head = NULL;
        }
        //One children
        else if ((*head)->right == NULL || (*head)->left == NULL){
            if((*head)->left != NULL){
                struct tree *temp = *head;
                *head = (*head)->left;
                free(temp);
            }
            else {
                struct tree *temp = *head;
                *head = (*head)->right;
                free(temp);
            }
        }
        // Two Children
        else{
            struct tree *temp = (*head)->left;
            
         
            while(temp->right!=NULL){
                temp = temp->right;
            }
            
            (*head)->data = temp->data;
            delete(&((*head))->left, temp->data);
        }
    }
    
}

void postorder(struct tree *head){
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        printf("%d ", head->data);
    }
}



int main(){
    struct tree *head = NULL;
    int arr[8] = {10, 5, 15, 2,4 , 14, 19, 8};
    int index = 0;
    while(index<8){
        insert(&head, arr[index]);
        index++;
    }
    postorder(head);
    search(head, 10);

    printf("\n");
    printf("%d", max_left(head));
    printf("\n");
    
    delete(&head, 14);
    postorder(head);
   
    
    

}