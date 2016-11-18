/*
 *  Comp 15
 *  Sorting Assignment
 *
 *  sortnums.cpp
 *  Author:  Mark A. Sheldon, Tufts University, Spring 2016
 *
 *  This file is taken from my solution, but with the function
 *  definitions, except for main(), omitted.
 *
 *  You may use this code as-is, you can modify it, or you can throw
 *  it away and do your own thing.  But there are things you should
 *  note:
 * 
 *       - main() is really sweet.  Aspire to this level of directness
 *         and clarity.
 *       - The integer vector is always passed by reference.  This
 *         avoids lots of copying, and allows you to not implement a
 *         copy constructor.
 *       - The input stream (cin) is also passed by reference.  Always
 *         pass input/output streams by reference or pointer. 
 *       - It is common Unix practice to print a "usage" string on the
 *         standard error output (cerr) when a program is not used
 *         correctly.  The usageAbort() function is give to you, and
 *         you can use it to exit the program with an appropriate
 *         message if no algorithm is given on the command line or if
 *         the algorithm given isn't one of "bubble", "sort2",
 *         "sort3".
 *       - Detailed specifications for the functions declared at the
 *         top of the file are given below main(), but the
 *         implementations have been omitted.
 */
#include <iostream>
#include <cstdlib>

#include "IntVector.h"

using namespace std;

string algorithmFromCommandLine(int argc, char *argv[]);
void   usageAbort (string progname, string message);
void   readNumbers(istream &input, IntVector &data);
void   sortNumbers(string algorithm, IntVector &data);
void   printNumbers(const IntVector &data);

void swap(IntVector &vector, int i, int j);

void bubbleSort(IntVector &data);
void insertionSort(IntVector &data);
void radixSort(IntVector &data);
int getMax(IntVector &data);
void countingSort(IntVector &data, int digit);

int main(int argc, char *argv[])
{
        IntVector data;
        string    sortAlgorithm;
      
        sortAlgorithm = algorithmFromCommandLine(argc, argv);
   
	readNumbers(cin, data);
        sortNumbers(sortAlgorithm, data);
        printNumbers(data);

        return 0;
}

/*
 * Abort the program with a message on standard error
 * explaining how to run the program correctly from the 
 * command line.
 */
void usageAbort(string progname, string message)
{
        cerr << message << endl
             << "Usage:  " << progname << " algorithm" << endl
             << "     where algorithm is one of "
             << "bubble, sort2, or sort3"
             << endl;
        exit(1);
}

/***************************************************************************/
/**                      Functions you may want to write                  **/
/***************************************************************************/


/* 
 *  Parameters: argc, which is argument count, is the number of arguments
 *  given from the command line, and argv, the argument vector, is 
 *  an array of C strings, one for each parameter from the command line
 *  Returns: the sorting algorithm that was specified on the command line
 *  Note: the program is aborted if no algorithm is specified or if
 *  specified algorithm is not supported.
 */

string algorithmFromCommandLine(int argc, char *argv[])
{	
	//no algorithm
	if (argc == 1)
		usageAbort(argv[0], "no algorithm is specified");

	//assign C string to variable of type string
	string sort = argv[1];
	
	if (sort == "bubble" or sort == "sort2" or sort == "sort3") {
		return sort;
	}
	
	//too many arguments
	else if (argc > 2)
		usageAbort(argv[0], "too many arguments; try giving one");
	
	//not one of the used sorts
	usageAbort(argv[0], "specified algorithm is not supported");
	
	
	return "";
}


/* 
 *  Parameters: input stream, which gives the collection of integers and
 *  are separated by white space, and data, which is access to the vector
 *  Returns: nothing
 *  Note: this function reads in the integers from the given input stream
 *  and adds them to the end of the data vector
 */

void readNumbers(istream &input, IntVector &data) 
{
	//keep looping infinitely until you break; break only when 
	//input.eof is true, meaning at the end of file; benefit
	//is don't need to call input.eof twice, which makes it
	//slightly better performance-wise
	while (true) {
		int num;
		input >> num;
		if (!input.eof()) 
			data.add(num);
		else 
			break;
	}
	
}

/* 
 *  Parameters: the string algorithm, which shows what algorithm the user
 *  wishes to use, and data, which is access to the vector
 *  Returns: nothing
 *  Note: this function calls specific sorting functions to implement the
 *  sort that the algorithm calls for
 */

void sortNumbers(string algorithm, IntVector &data)
{
	if (algorithm == "bubble") 
		bubbleSort(data);
	
	if (algorithm == "sort2") 
		insertionSort(data);
	
	if (algorithm == "sort3")
		radixSort(data);
}


/* 
 *  Parameters: data, which is access to the vector
 *  Returns: nothing
 *  Note: Prints contents of data one item per line
 */

void   printNumbers(const IntVector &data)
{
	int size = data.size();
	
	for (int i = 0; i < size; i++) {
		cout << data.get(i) << endl;
	}
}



/* 
 *  Parameters: data, which is access to the vector
 *  Returns: nothing
 *  Note: this function performs an in-place sort of contents of data
 *  using the bubble sort algorithm. see ReadMe.md for detailed
 *  specifications of how the algorithm is carried out. 
 */

void bubbleSort(IntVector &data)
{
	int size = data.size();
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++)  {
			if (data.get(j) > data.get(j+1)) {
				swap(data, j, j+1);
			}
		}
	}
}


/* 
 *  Parameters: data, which is access to the vector, the index numbers
 *  of the two elements to swap
 *  Returns: nothing
 *  Note: Updates the given vector so that the items at position i and j
 * are swapped.
 */
void swap(IntVector &vector, int i, int j) 
{
	int temp = vector.get(j);
	
	vector.set(j, vector.get(i));
	
	vector.set(i, temp);
}


/* 
 *  Parameters: data, which is access to the vector
 *  Returns: nothing
 *  Note: this function performs an insertion sort. see ReadMe.md for detailed
 *  specifications of how the algorithm is carried out. 
 */
void insertionSort(IntVector &data) 
{
	int size = data.size();
	int j; //variable for the while loop
	
	for (int i = 1; i < size; i++) {
		j = i;
		while (j > 0 && data.get(j) < data.get(j-1)) {
			swap(data, j, j-1);
			j--;
		}
	}
}

/* 
 *  Parameters: data, which is access to the vector
 *  Returns: nothing
 *  Note: this function performs a radix sort by also implementing a
 *  counting sort. see ReadMe.md for detailed
 *  specifications of how the algorithm is carried out. 
 */
void radixSort (IntVector &data)
{
	//find the max number in the vector to know the max number of digits
	//that we have to sort
	int max = getMax(data);
	
	int digit = 1; //starts with the one's place
	
	//will stop after looping through # of digits
	//(when digit is 1, we are sorting the one's place. when digit is 10, 
	//sorting the ten's place, digit is 100, sorting the hundred's place
	// and so on
	while (max/digit > 0) {
		countingSort(data,digit);
		digit *= 10;
	}

	//max/digit is an int because int/int is int, and so when the number
	//becomes a 0.?? decimal number, we will break out of the loop
}

/* 
 *  Parameters: data, which is access to the vector
 *  Returns: the maximum value in the array in 
 *  order to calculate the maximum number of digits in the array
 */
int getMax(IntVector &data) 
{
	int max = data.get(0);
	
	for (int i = 1; i < data.size(); i++) {
		if (data.get(i) > max)
			max = data.get(i);
	}
	
	return max;
}

/* 
 *  Parameters: data, which is access to the vector, and digit, which is 
 *  the largest number of significant digits
 *  Returns: nothing
 *  Note: this function performs a counting sort to help with the radix
 *  sort. see ReadMe.md for detailed specifications of how this is 
 *  carried out.
 */
void countingSort(IntVector &data, int digit) {
	int size = data.size();
	
	int output[size]; //output array to hold the sorted outputs
	int counter[10]; //count array which serve as the "buckets"
				//for each digit
	int index; //the index of counter which gives the value that 
	//is used for the index of output array
	
	//setting elements in the counter array as 0 because no
	//digit has been calculated in it yet
	for (int i = 0; i < 10; i++) {
		counter[i] = 0;
	}
	
	//the next three for loops use a counting sort to sort the 
	//individual digits
	//NOTE: data.get(i)/digit%10 gives the singular digit value % 10
	//therefore, same singular digits will be in the same bucket
	
	//also, the elements in countDigit is not the data number itself,
	//but a number that increments from 0 that determines where 
	//the value goes in the output array
	for (int i = 0; i < size; i++) {
		(counter[(data.get(i)/digit)%10])++;
	}
	
	//changing counter[i] so counter[i] contains the position
	//of this digit in the output array
	for (int i = 1; i < 10; i++) {
		counter[i] += counter[i-1];
	}
	
	//building the output array (which is sorted for that digit)
	//size - 1 because arrays start at 0
	for (int i = size - 1; i >= 0; i--) {
		index = (data.get(i)/digit)%10;
		//-1 because index starts at 0
		output[counter[index]-1] = data.get(i);
		counter[index]--;
	}

	//copy the output array to the vector. the vector should now contain
	//an array sorted for the current digit
	for (int i = 0; i < size; i++) {
		data.set(i, output[i]);
	}

}