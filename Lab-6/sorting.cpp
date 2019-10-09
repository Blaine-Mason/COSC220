#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
void Swap(int& a, int& b, int& c){
  c++; //haha get it
  int temp = a;
  a = b;
  b = temp;
}
void fillArray(int* arr, int length){
  srand(time(NULL));
  int n = 100;
  for(int i = 0; i < length; i++){
    arr[i] = rand() % n + 1;
  }
}
void BubbleSort(int* ar, int length, bool ascending, int& c){
  bool swapped = true;
  while(swapped){
    swapped = false;
    for(int i = 0; i < length; i++){
      if(ascending){
        if(ar[i] < ar[i+1]){
        Swap(ar[i], ar[i+1], c);
        swapped = true;
        }
      }else{
        if(ar[i] > ar[i+1]){
        Swap(ar[i], ar[i+1], c);
        swapped = true;
        }
      }
    }
  }
}
void SelectionSort(int* ar, int length, bool ascending, int& c){
  for(int i = 0; i <= length - 2; i++){
    int min = i;
    for(int j = i + 1; j <= length - 1; j++){
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
    Swap(ar[i], ar[min], c);
  }
}
void InsertionSort(int* ar, int length, bool ascending, int& c){
  for(int i = 1; i < length; i++){
    int j = i;
    if(ascending){
      while(j > 0 && ar[j] > ar[j-1]){
        Swap(ar[j], ar[j-1],c);
        j = j - 1;
      }
    }else{
      while(j > 0 && ar[j] < ar[j-1]){
        Swap(ar[j], ar[j-1], c);
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
        return false;
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
  int length = 100, count = 0;
  int a[length];
  fillArray(a, length);
  PrintArray(a, length);
  // The "auto" type determines the correct type at compile-time
  // -Dr.Anderson
  auto start = std::chrono::system_clock::now();
  InsertionSort(a, length, false, count); // replace with your sorting alorithm
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";
  PrintArray(a, length);
  std::cout << "Swap: " << count << std::endl;





}
