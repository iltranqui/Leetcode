// ArratLibrary with function taken from the internet and explained
#include <bits/stdc++.h> 
using namespace std; 




// Group 1 ) Array Rotation
// C++ program to rotate an array by d elements 

/*Function to left Rotate arr[] of any size by 1 --- Moves all elements by 1 position - Doesn't return element */ 
void leftRotatebyOne(auto arr[]) {
    int len = sizeof(arr);
	auto temp = arr[0], i; 
	for (i = 0; i < len - 1; i++) 
		arr[i] = arr[i + 1]; 
	arr[i] = temp; 
} 


/*Function to left rotate arr[] by d positions -- Moves all elements by pos positions to teh right*/
void leftRotate(auto arr[], int d) 
{ 
	for (int i = 0; i < d; i++) 
		leftRotatebyOne(arr); 
} 


/* utility function to print an array */
void printArray(auto arr[]) 
{   
    int len = sizeof(arr);
	for (int i = 0; i < len; i++) 
		cout << arr[i] << " "; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	leftRotate(arr, 2, n); 
	printArray(arr, n); 

	return 0; 
} 

/*Function to reverse arr[] from index start to end*/
/* Take Divide the array from start pos to end pos. Switches extreme points and closes the gap */
void rvereseArray(int arr[], int start, int end) // Time Complexity O(n): Space Complexity O(1)
{ 
    while (start < end) { 
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
} 

/* Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i]. */
auto rotatesum(auto arr[]) {
	int len=sizeof(arr);
	//max Find array sum and i*arr[i] with no rotation 
    int arrSum = 0;  // Stores sum of arr[i] 
    int currVal = 0;  // Stores sum of i*arr[i] 
    for (int i=0; i<len; i++) 
    { 
        arrSum = arrSum + arr[i]; 
        currVal = currVal+(i*arr[i]); 
    } 
  
    // Initialize result as 0 rotation sum 
    int maxVal = currVal; 
  
    // Try all rotations one by one and find 
    // the maximum rotation sum. 
    for (int j=1; j<len; j++) 
    { 
        currVal = currVal + arrSum-len*arr[len-j]; 
        if (currVal > maxVal) 
            maxVal = currVal; 
    } 
  
    // Return result 
    return maxVal; 

}