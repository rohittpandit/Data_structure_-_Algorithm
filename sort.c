#include <stdio.h>
#include <stdlib.h>

void delete(int *arr, int index, int k){
	for(int i = index; i <=k; i++){
		arr[i] = arr[i+1];
	}

}

int maximum(int *arr, int k){
	int max =  arr[0];
	int i = 0;
	while(i<k){
		if(arr[i] > max) {
			max = arr[i];
			}
		i++;
		}
	int index =0;
	while(index<k){
		if(max ==  arr[index]){
			delete(arr,  index, k);
		}
		index++;
		}
	return max;	
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


void sort_dsec(int *arr, int n ){
	int *new_arr = (int *)calloc(n, sizeof(int));
	int k = n;
	for(int i = 0; i<n; i++){	
		new_arr[i] = maximum(arr, k); 
		k--;
	}
	
	for(int i = 0; i<n; i++){
		arr[i] = new_arr[i]; 
	}
	printf("The sorted list in descending order is: ");
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
	sort_dsec(arr,n);
	printf("\n");
	
	return 0;
	
	
	
}



