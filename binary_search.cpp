#include<bits/stdc++.h>

int binary_search(int arr[], int l, int r, int elem){
	if (l <= r) {
		int mid = l + (r-l)/2;
		if (arr[mid] == elem)
			return mid;
		else if (arr[mid] > elem)
			r = mid-1;
		else
			l = mid+1;
		binary_search(arr, l, r, elem);
	}else{
		return -1;
	}
}
int main(){
	std::ios_base::sync_with_stdio(false);
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = -1;
	int result = binary_search(arr, 0, n-1, x);
	printf("%d\n", result);
	return 0;
}