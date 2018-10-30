#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
   int i, j, k;
   int count = 0;

   i = left;    //i to locate first array location
   j = mid;     //i to locate second array location
   k = left;    //i to locate merged array location

   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]) {    //when left item is less than right item
         temp[k++] = arr[i++];
      }else{
         temp[k++] = arr[j++];
         count += (mid - i);    //find how many convertion is performed
      }
   }

    while (i <= mid - 1)    //if first list has remaining item, add them in the list
       temp[k++] = arr[i++];

    while (j <= right)    //if second list has remaining item, add them in the list
       temp[k++] = arr[j++];

    for (i=left; i <= right; i++)
       arr[i] = temp[i];    //store temp Array to main array
    return count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
   int mid, count = 0;

   if (right > left) {
      mid = (right + left)/2;    //find mid index of the array
      count  = mergeSort(arr, temp, left, mid);    //merge sort left sub array
      count += mergeSort(arr, temp, mid+1, right);    //merge sort right sub array

      count += merge(arr, temp, left, mid+1, right);    //merge two sub arrays
   }
   return count;
}

int arrInversion(int arr[], int n) {
   int temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}

int * shuffle(int *arr, size_t n)
{
      size_t i;
      srand(time(NULL));
      for (i = 0; i < n - 1; i++)
      {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
      }
			return arr;
}

int * randomArray(int n){
	 int * arr = (int*)malloc(sizeof(int) * n);
	 for(int i=0; i<n; i++){
		  arr[i] = i;
	 }
	 return shuffle(arr, n);
}

void printArr(int arr[], int n){
		cout<<"Os elementos do vetor são: {";
		for(int i=0; i<n; i++){
				cout<<arr[i]<<", ";
		}
		cout<<"\n";
}

int main() {
	 int n;
	 cout<<"Insira o número de elementos desejados no vetor: ";
	 cin >> n;

	 int * arr = randomArray(n);
	 printArr(arr, n);

   cout<< "A quantidade de inversões é:  "<<arrInversion(arr, n)<< "\n";
}
