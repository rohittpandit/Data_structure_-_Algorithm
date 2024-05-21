#include <stdio.h>
#include <stdlib.h>

int insert(int element, int index_no, int a[], int *n){
    
    for(int j = *n; j > index_no; j--){
         a[j] = a[j-1];
    }
    a[index_no] = element;
     (*n)++;
}

int main() {
    int n;
    printf("Enter the size of n: ");
    scanf("%d", &n);
    
    int a[n]; 
    
    for(int i = 0; i <n; i++){  // Taking input of array
        scanf("%d", &a[i]);
        printf("%p\n", &a[i]);
    }
    printf("\n");
    int * arr = &a[0];
    
    // Inserting a new element in a 1st index.
    insert(5,3,a,&n);
    
      
    for(int i = 0; i <n; i++){  // Taking input of array
        printf("%d ", a[i]);
        
    }
    printf("\n");
     for(int i = 0; i <n; i++){  // Taking input of array
        printf("%p\n", &a[i]);
    }
    
   
    return 0;
}