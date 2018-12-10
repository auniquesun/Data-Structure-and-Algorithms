/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int left, int mid, int right) 
{ 
	int len_left = mid - left + 1;
    int len_right = right - mid;

    int Left[len_left];
    int Right[len_right];

    int i,j;
    // 拷贝左侧部分
    for(i=0; i<len_left; i++)
        Left[i] = arr[left + i];
    // 拷贝右侧部分
    for(j=0; j<len_right; j++)
        Right[j] = arr[len_left + j];

    int k = left;   //跟踪arr数组
    for(i=left, j=left; i<len_left && j<len_right;){
        if(Left[i] < Right[j]){
            arr[k++] = Left[i++];
        }
        else{
            arr[k++] = Right[j++];
        }
    }

    //拷贝left剩余的元素
    while(i<len_left)
        arr[k++] = Left[i++];

    // 拷贝right剩余的元
    while(j<len_right)
        arr[k++] = Right[j++];
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right) 
{ 
	if(left<right){
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size); 

	mergeSort(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 
