#include<bits/stdc++.h>

int kth_smallest_element(int arr[], int l, int r, int k);
int partition(int arr[], int l, int r);
int random_partition(int arr[], int l, int r);

using namespace std;
void swap(int *x, int *y);

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int kth_smallest_element(int arr[], int l, int r, int k){
	if (k > 0 && k <= r - l + 1) {
		printf("bounds %d %d and position %d\n", l, r, k);
		
		int pos = random_partition(arr, l, r);
		printf("position from random partition:: %d\n", pos);
		
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kth_smallest_element(arr, l, pos-1, k);
		return kth_smallest_element(arr, pos+1, r, k-pos+l-1);
	}
	return std::numeric_limits<int>::max();
}

int random_partition(int arr[], int l, int r){
	int n = r-l+1;
	int pivot = rand() % n;

	printf("pivot position in random partition:: %d\n", pivot);
	
	swap(&arr[l+pivot], &arr[r]);
	return partition(arr, l, r);
}



int partition(int arr[], int l, int r){
	int x = arr[r], i=l;
	printf("pivot in partition:: %d\n", x);
	for ( int j=l; j <= r-1; j++){
		if (arr[j] <= x){
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int main(){
	// int arr[] = {10, 80, 30, 90, 40, 50, 70};
	// printf("%d\n", kth_smallest_element(arr, 0, 6, 4));

	int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kth_smallest_element(arr, 0, n-1, k) << "\n";

    return 0;
}