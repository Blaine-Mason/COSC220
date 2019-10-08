#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
void Swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}
void fillArray(aint* arr, int length){
  srand(time(NULL));
  int n = 100;
  for(int i = 0; i < length; i++){
    arr[i] = rand() % n + 1;
  }
}
void BubbleSort(int* ar, int length, bool ascending){
  bool swapped = true;
  while(swapped){
    swapped = false;
    for(int i = 0; i < length; i++){
      if(ascending){
        if(ar[i] < ar[i+1]){
        Swap(ar[i], ar[i+1]);
        swapped = true;
        }
      }else{
        if(ar[i] > ar[i+1]){
        Swap(ar[i], ar[i+1]);
        swapped = true;
        }
      }
    }
  }
}
void SelectionSort(int* ar, int length, bool ascending){
  for(int i = 0; i < length - 1; i++){
    int min = ar[i];
    for(int j = i + 1; i <  length; i++){
      if(ascending){
        if(ar[j] > ar[min]){
          min = j;
        }
      }else{
        if(ar[j] < ar[min]){
          min = j;
        }
      }

    }
    Swap(ar[i], ar[min]);
  }
}
void InsertionSort(int* ar, int length, bool ascending){
  for(int i = 1; i < length; i++){
    int j = i;
    if(ascending){
      while(j > 0 && ar[j] > ar[j-1]){
        Swap(ar[j], ar[j-1]);
        j = j - 1;
      }
    }else{
      while(j > 0 && ar[j] < ar[j-1]){
        Swap(ar[j], ar[j-1]);
        j = j - 1;
      }
    }
  }
}
void PrintArray(int* a, int length){
  for(int i = 0; i < length; i++){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
bool isSorted(int* arr, int length, bool ascending){
  for(int i = 0; i < length; i++){
    if(ascending){
      if(arr[i] > arr[i + 1]){
        return false
      }
    }else{
      if(arr[i] < arr[i+1]){
        return false;
      }
    }
  }
  return true;
}
int main(){
  int length = 100;
  int a[length];
  for(int i = 0;  i < length; i++){
    a[i] = length;
    length--;
  }
  PrintArray(a, length);
  BubbleSort(a, length);
  PrintArray(a, length);

}
