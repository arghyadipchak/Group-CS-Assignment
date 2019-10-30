#include <stdio.h>
#include <stdlib.h>

//Sorting Functions:
//Selection Sort, Bubble Sort
//Insertion Sort, Merge Sort, Heap Sort

void swap(int *arr,int p1,int p2){
  int tmp = *(arr+p1);
  *(arr+p1) = *(arr+p2);
  *(arr+p2) = tmp;
}
void selection_sort(int *arr,int n){
  int minpos=0;
  for(int i=0;i<n-1;i++){
    minpos=i;
    for(int j=i+1;j<n;j++)
      if(arr[j]<arr[minpos]) minpos=j;
    if(minpos!=i) swap(arr,i,minpos);
  }
}
void bubble_sort(int *arr,int n){
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++)
      if(arr[j]>arr[j+1]) swap(arr,j,j+1);
  }
}
void insertion_sort(int *arr,int n){
  int val,pos;
  for(int i=1;i<n;i++){
    val=arr[i];
    pos=i;
    while(pos>0 && arr[pos-1]>val){
      arr[pos] = arr[pos-1];
      pos--;
    }
    if(pos!=i) arr[pos]=val;
  }
}
void merge(int *arr,int *ar1,int n1,int *ar2,int n2){
  int p1=0;
  int p2=0;
  int p=0;
  while(p1<n1 && p2<n2){
    if(ar1[p1]<=ar2[p2])
      arr[p++] = ar1[p1++];
    else
      arr[p++] = ar2[p2++];
  }
  while(p1<n1) arr[p++] = ar1[p1++];
  while(p2<n2) arr[p++] = ar2[p2++];
}
void merge_sort(int *arr,int n){
  if(n<=1) return;
  int *ar1 = (int*) calloc(n/2,sizeof(int));
  int *ar2 = (int*) calloc(n-n/2,sizeof(int));
  for(int i=0;i<n/2;i++)
    ar1[i] = arr[i];
  for(int i=0;i<n-n/2;i++)
    ar2[i] = arr[i+n/2];
  merge_sort(ar1,n/2);
  merge_sort(ar2,n-n/2);
  merge(arr,ar1,n/2,ar2,n-n/2);
}
void heap_sort(int *arr,int n){
  return;
}
//All The Sorting Functions are to be called as
//func_sort(<array pointer>,<size>);
int main(){
  return 0;
}
