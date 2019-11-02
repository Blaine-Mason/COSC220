#include <iostream>
int partition(int arr[], int start, int end){

}
void swap(int &val1, int &val2){
  int temp = val1;
  val1 = val2;
  val2 = temp;
}
void quicksort(int arr[], int start, int end){

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


  return 0;
}
