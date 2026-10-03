#include <stdio.h>
#include <stdlib.h>


void reverse_arr(int *arr, int left, int right) {
    
    if(left >= right)
        
        return; 
        
    int temp = arr[left];
    
    arr[left] = arr[right]; 
    
    arr[right] = temp; 
    
    reverse_arr(arr, left + 1, right - 1); 
}

int main(void)
{
    int arr[] = {1, 2, 3}; // 0 -> 1, 1 -> 2, 2 -> 3. 
    
    int size = sizeof(arr)/sizeof(arr[0]); 
    
    printf("Hello World\n");
    
    reverse_arr(arr, 0, size - 1);
    
    for(int i = 0; i < size; i++) {
        printf("%d \n", arr[i]); 
    }

    return 0;
}