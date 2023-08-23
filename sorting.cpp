// For theory please visit the following website: https://betterprogramming.pub/5-basic-sorting-algorithms-you-must-know-9ef5b1f3949c 
#include <iostream>
#include <vector>

#include "sorting.h"

// ------------------------------------------------------------------------------
// Insertion sort Defination
// ------------------------------------------------------------------------------
template <typename T>
T* SortingClass::insertionSort(T* arr, int n){
	
	for(size_t i=1; i<n; i++){

		int key = arr[i];
		int j = i-1;

		while(j>=0 && key<arr[j]){

			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

	return arr;
}

// ------------------------------------------------------------------------------
// Selection sort Defination
// ------------------------------------------------------------------------------
template <typename T>
T* SortingClass::selectionSort(T* arr, int n){

	for(size_t i=0; i<n; i++){
		int minVal = 1e5;
		int minValIndx = -1;
		for(size_t j=i+1; j<n; j++){
			if (minVal >= min(minVal, arr[j])){minVal = min(minVal, arr[j]); minValIndx = j;}
		}
		if(minValIndx!=-1){
			int temp = arr[minValIndx];
			arr[minValIndx] = arr[i];
			arr[i] = temp;
		}
	}
}

// ------------------------------------------------------------------------------
// Bubble sort defination
// ------------------------------------------------------------------------------
template <typename T> 
T* SortingClass::bubbleSort(T* arr, int n){
	bool isSorted = false;
	while(!isSorted){
		for(size_t i=1; i<n; i++){
			if(arr[i]<arr[i-1]){
				int temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
				isSorted = true; 
			}
		}
		if(!isSorted){break; return arr;}
		isSorted = false;		
	}
	return arr;
}

// Merge sort helpers
template <typename T>
void merge(T* arr, int l, int m, int r){
	int nL = m-l+1;
	int nR = r-m;

	// divide the array into two array and sort based on the merge sort rule
	int l_arr[nL];
	int r_arr[nR];
	
	for(int i=0; i<=nL; i++){
		l_arr[i] = arr[l+i];
	}
	for(int j=0; j<=nR; j++){
		r_arr[j] = arr[m+1+j];
	}
	
	int ii = 0; int jj = 0;
	int k = l;

	while(ii< nL && jj< nR){
		if(l_arr[ii] <= r_arr[jj]){
			arr[k] = l_arr[ii];
			ii++;
		}else{
			arr[k] = r_arr[jj];
			jj++;
		}
		k++;
	}
	
	while(ii<nL){
		arr[k] = l_arr[ii];
		k++; ii++;
	}
	while(jj < nR){
		arr[k] = r_arr[jj];
		k++; jj++;
	}
}

template <typename T>
void divideTheArray(T* arr, int l, int r){

	if(l<r){
		// find the mid element from the array and keep dividing the array 
		int m = l + (r-l)/2;
		 
		divideTheArray(arr, l, m);
		divideTheArray(arr, m+1, r);
		// merge the divided arrays 
		merge(arr, l, m, r);
	}

}// merge sort helper ends here

// ------------------------------------------------------------------------------
// Merge sort defination
// ------------------------------------------------------------------------------
template <typename T>
T* SortingClass::mergeSort(T* arr, int n){
	divideTheArray(arr, 0, n-1);
	return arr;
}

int main(){

	int arr[] = {12,11,13,5,6};
	int n = sizeof(arr) / sizeof(arr[0]);

	SortingClass obj;
	int* arrPointer = obj.mergeSort(arr, n); 
	for(int i=0; i<n; i++){
		std::cout << arrPointer[i] << std::endl;
	}
	return 0;
}