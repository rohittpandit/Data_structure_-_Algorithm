#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int el, int size){
	int left = 0, right =  size-1;
	
	
	
	while(left <= right) {
		int mid =  (left +  right) / 2;
		
		if(el == arr[mid]) {
		return mid;}
		else if(el > arr[mid]){
			left =  mid+1;
		}
		else if(el < arr[mid]){
			right = mid-1;
		}
	}
	
	return -1;
	

}

void delete(int *arr, int index, int k){
	for(int i = index; i <=k; i++){
		arr[i] = arr[i+1];
	}

}



int minimum(int *arr, int k){
	int min =  arr[0];
	int i = 0; 
	while(i<k){
		if(arr[i] < min) {
			min = arr[i];
			}
		i++;
		}
	int index =0;
	while(index<k){
		if(min ==  arr[index]){
			delete(arr,  index, k);
		}
		index++;
		}
	return min;	
}


void sort_asec(int *arr, int n ){
	int *new_arr = (int *)calloc(n, sizeof(int));
	int k = n;
	for(int i = 0; i<n; i++){	
		new_arr[i] = minimum(arr, k); 
		k--;
	}
	
	for(int i = 0; i<n; i++){
		arr[i] = new_arr[i]; 
	}
	printf("The sorted list in ascending order is: ");
	for(int i = 0; i<n; i++){
		printf("%d ", arr[i]); 
	}
	free(new_arr);
}


int main() {
	int n;
	printf("Enter the list size: ");
	scanf("%d", &n);
	printf("\n");	
	
	int *arr = (int *)calloc(n, sizeof(int));
	
	printf("Enter the list: ");
	for(int i = 0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	
	
	sort_asec(arr,n);
	printf("\n");
	
	int el;
	printf("Enter the search element: ");
	scanf("%d", &el);
	
	printf("\n");
	
	if(search(arr, el, n) != -1) printf("The element is at location: %d", search(arr, el, n));
	else printf("The element is not found");
	printf("\n");
	
	
	return 0;
	
	
	
}



