#include <iostream>
void swap(int &val1, int &val2){
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

int partition(int arr[], int start, int end){
  int piviotV = arr[start];
  int i = start + 1;
  for(int j  = start + 1; j <= end; j++){
    if(arr[j] < piviotV){
      swap(arr[i], arr[j]);
      i++;

    }
  }
  swap(arr[start], arr[i - 1]);
  return i - 1;
}
void quicksort(int arr[], int start, int end){
  int piviot;
  if(start <= end -1){
    piviot = partition(arr, start, end);
    quicksort(arr, start, piviot - 1);
    quicksort(arr, piviot + 1, end);
  }
}
int main(){
  /*
  * Swap Test
  */
  int a = 10;
  int b = 5;
  std::cout << "Pre Swap: " << std::endl;
  std::cout << "a: " << a << " - " << "b: " << b << std::endl;
  // Prints "a: 10 - b: 5"
  swap(a,b);
  std::cout << "Post Swap: " << std::endl;
  std::cout << "a: " << a << " - " << "b: " << b << std::endl;
  // Prints "a: 5 - b: 10"

  int ar[] = {10, 5};
  std::cout << "Pre Swap: " << std::endl;
  std::cout << "[0]: " << ar[0] << " [1]: " << ar[1] << std::endl;
  swap(ar[0], ar[1]);
  std::cout << "Post Swap: " << std::endl;
  std::cout << "[0]: " << ar[0] << " [1]: " << ar[1] << std::endl;

  int randArr[6] = {6, 2, 5, 4, 8, 3};
  int smallArr[3] = {4, 2, 8};

  std::cout << "Rand Array:" << std::endl;
  for(int i = 0; i < 6;  i++){
    std::cout << randArr[i] << " ";
  }
  std::cout << std::endl;
  int p = partition(randArr, 0, 5);
  std::cout << "Piviot Value: "<< randArr[p] << " Piviot Location: " << p << std::endl;
  for(int i = 0; i < 6;  i++){
    std::cout << randArr[i] << " ";
  }
  std::cout << std::endl;

  int qTest[15] = {2, 65, 43, 88, 97, 154, 354, 10, 4, 11, 323, 65, 67, 3, 1};
  std::cout << "Before Sort:" << std::endl;
  for(int i = 0; i < 15;  i++){
    std::cout << qTest[i] << " ";
  }
  std::cout << "\nAfter Sort: " << std::endl;
  quicksort(qTest, 0, 14);
  for(int i = 0; i < 15;  i++){
    std::cout << qTest[i] << " ";
  }


  return 0;
}
