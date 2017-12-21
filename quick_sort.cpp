#include<bits/stdc++.h>

int partition(int arr[], int l, int h);
void swap(int *x, int *y);
void quick_sort(int arr[], int l, int h);

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(int arr[], int l, int h) {
	if(l < h){
		int pi = partition(arr, l, h);

		quick_sort(arr, l, pi-1);
		quick_sort(arr, pi+1, h);
	}
}

int partition(int arr[], int l, int h){
	int pivot = arr[h];
	int i = l-1;

	for (int j = l; j <= h-1; j++){
		if (arr[j] <= pivot){
			i += 1;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[h]);
	return i+1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	quick_sort(arr, 0, 6);

	for(int i=0;i<7;i++){
		printf("%d ", arr[i]);
	}
	return 0;
}