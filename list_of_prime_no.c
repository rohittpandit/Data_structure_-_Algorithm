#include <stdio.h>
#include <stdlib.h>

int prime(int x) {
    int y = 0;
    for(int i = 2; i < x; i++) {
        if (x % i == 0) {
            y++;
        }
    }
    if (y == 0) {
        return x;
    } else {
        return 0;
    }
}

int main() {
    int end_case;
    printf("Enter the end case: ");
    scanf("%d", &end_case);
    
    int y = 0;
    int *a = NULL;
    
    for(int i = 2; i < end_case; i++) {
        if(prime(i) > 0) {
            y++;
            a = (int*)realloc(a, y * sizeof(int));
            a[y - 1] = prime(i);
        }
    }
    
    printf("Prime numbers up to %d:\n", end_case);
    for(int i = 0; i < y; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\nTotal No of Prime Number: %d", y);
    
    // Free the dynamically allocated memory
    free(a);

    return 0;
}
