#include  <stdlib.h>
#include  <stdio.h>
void Sort(int *arr, int n, int *count2)
{
  int m, med; 
  for (int i = 0; i < n - 1; i++) 
  {
    m = i; 
    count2[1]++;
    count2[1]++;
    for (int j = i + 1; j < n; j++)
    {
      count2[1]+=2; //сравнение в цикле и ниже
      if (arr[j] < arr[m]) {
        m = j;   
        count2[0]++;
      }
    }
    count2[1]++;//несколько if не пройдут в цикл. но все равно сравнение будет
    count2[1]++;
    count2[1]++;
    med = arr[i];
    count2[0]++;
    arr[i] = arr[m];
    count2[0]++;
    arr[m] = med;
  }
}
void quickSort(int *arr, int left, int right, int *count1)
{
  int k; 
  int l = left;  
  int r = right;
  k = arr[left];
  while (left < right)
  {
    count1[1]++;
    while ((arr[right] >= k) && (left < right)){
      count1[1]+=2;
      right--;
    }
    count1[1]++;//тк если в цикл не прошло => сравнение выполнилось
    count1[1]++;
    if (left != right) 
    {
      count1[0]++;
      arr[left] = arr[right]; 
      left++; 
    }
    while ((arr[left] <= k) && (left < right)){
      left++; 
      count1[1]+=2;
    }
    count1[1]++;
    count1[1]++;
    if (left != right) 
    {
      count1[0]++;
      arr[right] = arr[left]; 
      right--; 
    }
  }
  arr[left] = k; 
  k = left;
  left = l;
  right = r;
  count1[1]++;
  if (left < k) 
    quickSort(arr, left, k - 1, count1);
  count1[1]++;
  if (right > k)
    quickSort(arr, k + 1, right, count1);
}
int main (void){
    int Arr[20];
    int Arr2[20];
    int count1[5];
    count1[0] = 0;
    count1[1] = 0;
    int count2[5]; //счетчик (1 - колво сравнений. 0 элемент - перестановок)
    count2[0] = 0;
    count2[1] = 0;
    int n = 10;
    int i;
    for (int i = 0; i<n; i++) {
        Arr[i] = rand() % 201 - 100;
        Arr2[i] = Arr[i];
        printf("%d", Arr[i]);
        printf("\n");
    }
    int left = 0;
    int right = n - 1;
    quickSort(Arr, left, right, count1);
    Sort(Arr2, n, count2);
    for ( int i = 0; i < n; i ++)
        printf("%d ", Arr[i]);
        printf("\n");
    for ( int i = 0; i < n; i ++)
        printf("%d ", Arr2[i]);
        printf("\n");
    printf("%d %d ", count2[0], count2[1]);
    printf("%d %d", count1[0], count1[1]);
    return 0;
}