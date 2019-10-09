#include <iostream>

//Blaine Mason
//COSC220 Lab-1
//8-27-2019
//This program allows the user to enter any amount of integers then computes the mean and displays
//that to the user.

using namespace std;
//Prototypes
double mean(int ar[], int size); //takes in array and size of array and reutrns a double mean
double mean2(int* ar, int size); //takes in array and size of array and returns a double mean
int main(){
	//creates a pointer to arr
	int* arr;
	int* newarr;
	//arr is assigned an integer array of initial size 10
	arr = new int[10];
	//temp will hold the value the user enters
	//count will count the elements of the array
	int temp, count = 0;
	do{//do-while loop allows the user to keep inputing integers until a -1 is entered
		cout << "Enter an integer to be stored into an array(-1 to quit): ";
		cin >> temp;
		//newarr points to an array that is one item larger
		newarr = new int[count + 1];
		//the contents of arr are copied to newarr
		for(int i = 0; i < count; i++)
		{
			*(newarr + i) = *(arr + i);
		}
		//what arr was pointing to before the new element was added
		//is now deleted.
		delete[] arr;
		//arr now points to the newarr that holds the extra element
		arr = newarr;
		if(temp != -1){//when the user wants to keep storing integers
			//store the temp value in arr[count]
			arr[count] = temp;
			//increment count
			count++;
		}
	
	}while(temp != -1);
	//the output of the two funcitons mean and mean2 are displayed 	
	cout << "Mean: " << mean(arr, count) << endl;
	cout << "Mean 2: " << mean2(arr, count) << endl;
	//finally arr is deleted to prevent a memory leak
	delete[] arr;
	cout << "Arr[] Deleted\nGoodbye." << endl; 
	return 0;	
}

double mean(int ar[], int size){
	//sum will store the sum of all the elements in order to calculate the mean
	double sum = 0;
	for(int i = 0; i < size; i++){
		sum += ar[i];
	}
	//returns the mean
	return sum/size;
}
double mean2(int* ar, int size){
	double sum = 0;
	for(int i = 0; i < size; i++)
	{
		//ar[i] is now being done by the dereferencing of the first element of ar
		//then added to the int i, to get the memory location of ar[i] which is 
		//dereferenced to be added to sum.
		sum += *(ar + i);
	}
	//returns the mean
	return sum/size;
 }
