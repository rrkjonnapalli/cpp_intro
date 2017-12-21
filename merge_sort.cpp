#include<bits/stdc++.h>

void merge_sort(int arr[], int l, int h);
void merge(int arr[], int l, int m, int h);
void swap(int *x, int *y);

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void merge(int arr[], int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;

    int L[n1], R[n2];

    for (int i=0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for (int i=0; i < n2; i++){
        R[i] = arr[m+1+i];
    }

    int i=0, j=0, k=l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}


void merge_sort(int arr[], int l, int h){
    // printf("%d %d\n", l, h);
    if (l < h) {
        int m = l + (h-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	merge_sort(arr, 0, 6);

	for(int i=0;i<7;i++){
		printf("%d ", arr[i]);
	}
    printf("\n");
    return 0;
}