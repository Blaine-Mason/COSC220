#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
//Swaps
void Swap(int& a, int& b, int& c){
  c++; //haha get it
  int temp = a;
  a = b;
  b = temp;
}
//Fills array with random numbers from 1-100
void fillArray(int* arr, int length){
  srand(time(NULL));
  int n = 100;
  for(int i = 0; i < length; i++){
    arr[i] = rand() % n + 1;
  }
}
void BubbleSort(int* ar, int length, bool ascending, int& c){
  // The "auto" type determines the correct type at compile-time
  // -Dr.Anderson
  auto start = std::chrono::system_clock::now();
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
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cout << "Swap: " << c << std::endl;
}
void SelectionSort(int* ar, int length, bool ascending, int& c){
  // The "auto" type determines the correct type at compile-time
  // -Dr.Anderson
  auto start = std::chrono::system_clock::now();
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
    Swap(ar[min], ar[i], c);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cout << "Swap: " << c << std::endl;
}
void InsertionSort(int* ar, int length, bool ascending, int& c){
  // The "auto" type determines the correct type at compile-time
  // -Dr.Anderson
  auto start = std::chrono::system_clock::now();
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
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cout << "Swap: " << c << std::endl;
}
//Print
void PrintArray(int* a, int length){
  for(int i = 0; i < length; i++){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
//Checks if sorted
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
  //Seed for time
  srand(time(NULL));
  //Loop for Insertion Sort
  for(int len = 1000; len < 100000; len = len*4){
    int count = 0;
    int* a;
    a = new int[len];
    fillArray(a, len);
    std::cout << "Insertion Sort "<< len << ": " << std::endl;
    //InsertionSort(a, len, true, count); // replace with your sorting alorithm
    InsertionSort(a, len, false, count);
    delete[] a;
  }
  std::cout << std::endl << std::endl;
  //Loop for Selection Sort
  for(int len = 1000; len < 100000; len = len*4){
    int count = 0;
    int* a;
    a = new int[len];
    fillArray(a, len);
    std::cout << "Selection Sort "<< len << ": " << std::endl;
    //SelectionSort(a, len, true, count);
    SelectionSort(a, len, false, count);
    delete[] a;
  }
  //Loop for Bubble Sort
  std::cout << std::endl << std::endl;
  for(int len = 1000; len < 100000; len = len*4){
    int count = 0;
    int* a;
    a = new int[len];
    fillArray(a, len);
    std::cout << "Bubble Sort "<< len << ": " << std::endl;
    //BubbleSort(a, len, true, count);
    BubbleSort(a, len, false, count);
    delete[] a;
  }





}
