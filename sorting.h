class SortingClass{
public:
	SortingClass(){};
	
	// methods defination for sorting arrays

	// Insertion sort declaration
	template <typename T>
	T* insertionSort (T* arr, int n);
	// Selection sort declaration
	template <typename T> 
	T* selectionSort(T* arr, int n);
	// Bubble sort declaration
	template <typename T> 
	T* bubbleSort(T* arr, int n);
	// Merge sort declaration
	template <typename T> 
	T* mergeSort(T* arr, int n);				
};