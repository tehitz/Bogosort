#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define LISTSIZE 10 //Real list size is (LISTSIZE + 1)
#define MAXINT 100 //Maximum integer for rand()

int data[]; // Initialization for int data array

void shuffle(int *data); // Declare function, which is defined later

// Check if data array is sorted. Takes the array as argument
bool isSorted(int *data) {
	// Loop through all the integers and see if they are in the right order
	//Returns false if they are in incorrect order
	for(int i = 0; i < LISTSIZE; i++) {
		if(data[i] > data[i+1]) { 
			return false;
		}
	}
	return true;
}

//Main loop for sorting
//Check for isSorted() result and if false it calls shuffle() and passes array to it
void sort(int *data, int *iterations) {	
	while(!isSorted(data)) {
		shuffle(data);
		*iterations += 1;
	}
}

//Shuffle the array to random order
//Takes the array as argument
void shuffle(int *data) {
	int temp, random; //Random variable and temporary variable
	for(int i = 0; i <= LISTSIZE; i++) {
		temp = data[i];
		random = rand() % LISTSIZE; //Modulus to stay in list range
		data[i] = data[random];
		data[random] = temp;
	}
}

//Main function
int main() {
	long long count = 0;
	int *iterations = &count;
	srand(time(0)); //Initialize pseudo random number generator
	//Loop list to assign numbers to it
	for(int i = 0; i <= LISTSIZE; i++) {
		unsigned int num = (rand() % (MAXINT) + 1); //Modulus to keep random int lower than max int
		data[i] = num; //Assign random number to list index i
		printf("Data %d: %d\n", i+1, data[i]); //Print starting data
	}

	sort(data, iterations); //Sort data with bogosort

	//Print sorted data
	for(int i = 0; i <= LISTSIZE; i++) {
		printf("Sorted %d: %d\n", i+1, data[i]);
	}
	printf("Sorting took %d iterations to complete.\n", *iterations);

	return 0;
}
