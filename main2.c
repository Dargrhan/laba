#include  <stdlib.h>
#include  <stdio.h>
#include <math.h>
void Sort(int *arr, int n, int *swaps, int *comparisons)
{
  int m, med; 
  for (int i = 0; i < n - 1; i++) 
  {
    m = i; 
    for (int j = i + 1; j < n; j++)
    {
      comparisons[0]++;
      if (abs(arr[j]) > abs(arr[m])) {
        m = j;   
      }
    }
    med = arr[i];
    arr[i] = arr[m];
    swaps[0]++;
    arr[m] = med;
  }
}
void quickSort(int *arr, int left, int right, int *swaps, int *comparisons)
{
  int k; 
  int l = left;  
  int r = right;
  k = (arr[left]);
  while (left < right)
  {
    while (abs(arr[right]) <= abs(k) && (left < right)){
      comparisons[1]+=1;
      right--;
    }
    if (left != right) 
    {
      swaps[1]++;
      arr[left] = arr[right]; 
      left++; 
    }
    while (abs(arr[left]) >= abs(k) && (left < right)){
      left++; 
      comparisons[1]+=1;
    }
    if (left != right) 
    {
      swaps[1]++;
      arr[right] = arr[left]; 
      right--; 
    }
  }
  arr[left] = k; 
  k = left;
  left = l;
  right = r;
  if (left < k) 
    quickSort(arr, left, k - 1, swaps, comparisons);
  if (right > k)
    quickSort(arr, k + 1, right, swaps, comparisons);
}
void rand_array(int n, int *Arr, int *Arr2){
    int i;
        for (int i = 0; i<n; i++) {
            Arr[i] = rand() % 507 - 100;
            Arr2[i] = Arr[i];
        }
}
void up_array(int n, int *Arr, int *Arr2){
    for (int i = 0; i<n; i++) {
            Arr[i] = i;
            Arr2[i] = Arr[i];
        }
}
void down_array(int n, int *Arr, int *Arr2){
    int o=0;
    for (int i = n-1; i>=0; i--) {
            Arr[o] = i;
            Arr2[o] = Arr[o];
            o++;
    }
}

int main (void){
    int Arr[20000];
    int Arr2[20000];
    int comparisons[5];
    comparisons[0] = 0;
    comparisons[1] = 0;
    int swaps[5]; //счетчик (0 - sort. 1 элемент - quick sort)
    swaps[0] = 0;
    swaps[1] = 0;
    for (int n = 10; n<=10000; n = n*10){
        rand_array(n, Arr, Arr2);
        int left = 0;
        int right = n - 1;
        quickSort(Arr, left, right, swaps, comparisons);
        Sort(Arr2, n, swaps, comparisons);
        printf("%d %d - sort; ", swaps[0], comparisons[0]);
        printf("%d %d - qsort; ", swaps[1], comparisons[1]);
    }
    printf("rand\n");
    
    comparisons[0] = 0;
    comparisons[1] = 0; 
    swaps[0] = 0;
    swaps[1] = 0;
    for (int n = 10; n<=10000; n = n*10){
        up_array(n, Arr, Arr2);
        int left = 0;
        int right = n - 1;
        quickSort(Arr, left, right, swaps, comparisons);
        Sort(Arr2, n, swaps, comparisons);
        printf("%d %d - sort; ", swaps[0], comparisons[0]);
        printf("%d %d - qsort; ", swaps[1], comparisons[1]);
    }
    printf("voz\n");
    
    
    comparisons[0] = 0;
    comparisons[1] = 0; 
    swaps[0] = 0;
    swaps[1] = 0;
    for (int n = 10; n<=10000; n = n*10) {
        down_array(n, Arr, Arr2);
        int left = 0;
        int right = n - 1;
        quickSort(Arr, left, right, swaps, comparisons);
        Sort(Arr2, n, swaps, comparisons);
        printf("%d %d - sort; ", swaps[0], comparisons[0]);
        printf("%d %d - qsort; ", swaps[1], comparisons[1]);
    }
    printf("ub\n");
    return 0;
}