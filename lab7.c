#include <stdio.h>
#include <stdlib.h>

typedef struct attra {
    int data;
    int numswaps;
} attributes;

// Function to perform bubble sort and track the number of swaps
attributes* bubblesort(int* arr, int size) {
    attributes* swaps = (attributes*)malloc(sizeof(attributes) * size);


    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    int i,j,temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                // Swap the elements
                int temp = swaps[j].data;
                swaps[j].data = swaps[j + 1].data;
                swaps[j + 1].data = temp;

                // Increment the number of swaps for each element involved
                
                swaps[j].numswaps++;
                swaps[j+1 ].numswaps++;
                


            }
        }
    }
    return swaps;
}
void selectionsort(attributes* arr, int size) {
   


    int i, j, min_idx;
    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < size-1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (arr[j].data < arr[min_idx].data)
                min_idx = j;
  
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            attributes temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            
            // Increment swap count for the element put into its correct position
            arr[i].numswaps++;
        }
    }
}

int main() {
    int i;
    int arr[] = {97,16,45,  63,  13,  22,  7,  58,  72};
    int arr1[] = {97,16,45,  63,  13,  22,  7,  58,  72};
    int arr2[] = {90,  80,  70,  60,  50,  40,  30,  20,  10};
    int array2[] = {90,  80,  70,  60,  50,  40,  30,  20,  10};
    int size = 9;
    int total1,total2, total3, total4;
    attributes* arr11 = (attributes*)malloc(sizeof(attributes) * size);
        for (int i = 0; i < size; i++) {
        arr11[i].data = arr1[i];
        arr11[i].numswaps = 0;  // Initialize swap count to 0
    }
    attributes* arr22 = (attributes*)malloc(sizeof(attributes) * size);
        for (int i = 0; i < size; i++) {
        arr22[i].data = arr2[i];
        arr22[i].numswaps = 0;  // Initialize swap count to 0
    }
    
  
    attributes* sortedAttributes = bubblesort(arr, size);  
    selectionsort(arr11,size);
    for(i=0;i<size;i++){
        total1 += sortedAttributes[i].numswaps;
    }
    total1 = total1/2;
    for(i=0;i<size;i++){
        total2 += arr11[i].numswaps;
    }
    total1 = total1/2;


    
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
            printf("%d (Swaps: %d)\n", sortedAttributes[i].data, sortedAttributes[i].numswaps);
        }
    printf("total swaps %d\n",total1);
    free(sortedAttributes);
    
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
            printf("%d (Swaps: %d)\n", arr11[i].data, arr11[i].numswaps);
        }
    printf("total swaps %d\n",total2);
        free(arr11);


    
    attributes* sortedAttributes2 = bubblesort(array2, size);  
    selectionsort(arr22,size);
    for(i=0;i<size;i++){
        total3 += sortedAttributes2[i].numswaps;
    }
    total3 = total3/2;
    for(i=0;i<size;i++){
        total4 += arr22[i].numswaps;
    }
  


    
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
            printf("%d (Swaps: %d)\n", sortedAttributes2[i].data, sortedAttributes2[i].numswaps);
        }
    printf("total swaps %d\n",total3);
    free(sortedAttributes2);
    
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
            printf("%d (Swaps: %d)\n", arr22[i].data, arr22[i].numswaps);
        }
    printf("total swaps %d",total4);
        free(arr22);
    return 0;
}
