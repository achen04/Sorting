## ReadMe for COMP 15 HW5
## Sorting Assignment


/////////////////////PURPOSE///////////////////////////////////////////////
1.  The purpose of this program is to sort large amounts of data numbers by
    three different sorting methods. For this particular program, data 
    can be sorted through bubble sort, insertion sort, and radix sort,
    depending on the user. 

//////////////////////FILES////////////////////////////////////////////////
2.  
	-IntVector.h: This file defines the functions that are used in the
	 Intvector.cpp file, which are functions to create a dynamic array
	 that makes up the vector. 

	-IntVector.cpp: This file contains the functions that are needed
	 to create the vector, which includes add, expand, set, and get. 

	-sortnums.cpp: This file contains the main and the functions that
	 are needed for sorting. All sorting functions are in this file. 

//////////////////////TO COMPILE//////////////////////////////////////////
3.  use included Makefile

////////////////////////DATA STRUCTURES//////////////////////////////////
4.  The main data structure used in this assignment is a dynamic array.
The dynamic array is what the IntVector is. Thus, the vector of numbers
is in fact a dynamic array. A dynamic array is first created in 
the constructor. It can expand when the capacity is full. Expansion is done
by first creating a bigger array (in this case it is twice the size of the
original capacity), then copying data from the old to the new array, and 
then deleting the old array, and now setting the pointer to the new array, 
and finally updating the capacity. When the program is done running, the 
destructor deletes the dynamic array as it is no longer needed. A dynamic
array is useful in this case as it is not known how many numbers/how 
much data is being inputed, and thus an array that can dynamically expand
according to the number of inputed numbers is ideal.

////////////////////////////ALGORITHM//////////////////////////////////////
5.  
------------------------BUBBLE SORT----------------------------------------
The first sort is the bubble sort. The following is the algorithm for
bubble sort:

	-Start at index 0 of the array.

	-Compare the current value with the adjacent value (adjacent value
	 would be the value at index+1).

	-If the value at the current index is larger than the adjacent value,
	 swap the two values. 

	-Add one to the index so you can compare the next pair of adjacent
	 values. 

	-After the array has been gone through the first time, repeat the
	 above steps again, swapping when necessary.

	-Repeat the process again until the whole array is gone through 
	 without any swaps.

Complexity: The best case complexity is O(n). This can occur if the array is 
already sorted and thus no swap needs to occur. This also means that only
1 iteration of n elements is required, and thus the complexity would be O(n).
The worst case complexity is O(n^2). This happens with the array is sorted 
in the reverse order, because n-1 comparisons would happen in the first
pass, and n-2 in the second pass, and n-3 in the third pass, and so on. Thus,
when added together, the worst case complexity would ne O(n^2).

These are the following references I used to accomplish this sort:
https://en.wikipedia.org/wiki/Bubble_sort 
http://www.sorting-algorithms.com/bubble-sort

--------------------------INSERTION SORT-----------------------------------
The second sort is insertion sort. The following is the algorithm:

	-Compare the first two elements in the array.

	-If the first element is larger than the second element, insert the 
	first element after the second one by swapping the two elements. 

	-Check the third element of the array with the elements before it 
	and insert it in the proper position (swapping when necessary)

	-Check the fourth element in the same way.

	-Do the same procedure check for all elements until you have reached
	the end of the array.

Complexity: The best case complexity is O(n), in which the array is already 
sorted. This is because if the array is already sorted, there is no need to
compare the element with all the other elements. Thus, only one pass going
through the array is needed, resulting in the complexity case of O(n).
The worst case complexity is O(n^2), when the array is sorted in reverse 
order. This is because it is then necessary to compare each element with
all the previous elements in the array. 


References for this sort:
http://www.programiz.com/article/insertion-sort-algorithm-programming
www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm

-------------------------------RADIX SORT----------------------------------
The third sort is radix sort. The following is the algorithm:

	-Find the maximum value in the vector array to determine what the 
	largest number of digits there is. 

	-Start by sorting the one's digit using counting sort.

	-Use an array of size 10 for the counting sort to count how many 
	times each key (0-9 digit) appears in the original array of numbers.
	(an equation with the modulo is used to determine this)

	-Calculate the culminative totals in this counting sort array. These
	numbers tell us, for instance, that the three occurences of 3 should
	be in places 7, 8, 9 of the output array.

	-Use an output array of the size of the original array to copy
	the data from the original array to the output array in a sorted way.
	Where the element should be in the output array is determined by 
	the counting sort array.

	-Then, copy the data from the output array to the vector,

	-Use this same procedure for the ten's digit, hundred's and so on,
	until all digit values have been compared (step 1 tells you 
	how any times to loop through the counting sort)

Complexity: The average complexity of this version of the radix sort is
O(d*n), where d is the largest number of digits (how many significant
digits to go through), and n is the number of elements in the array. This
is because the overall complexity of the counting sort is O(k + n), where 
k is the range of the input. Since k is constant, the counting sort complexity
becomes O(n), and because we use counting sort according to the number of
digits, the complexity of radix sort is O(d*n).
See the proof of the counting sort here:
http://www.code2learn.com/2012/01/counting-sort-algorithm-with-example.html


References for counting sort specifically:
http://www.code2learn.com/2012/01/counting-sort-algorithm-with-example.html
http://www.cse.iitk.ac.in/users/dsrkg/cs210/applets/sortingII/countingSort/
algCount.html
https://en.wikipedia.org/wiki/Counting_sort#The_algorithm

References for radix sort:
https://www.cs.auckland.ac.nz/software/AlgAnim/radixsort.html
http://www.cprogramming.com/tutorial/computersciencetheory/radix.html
http://stackoverflow.com/questions/36178085/explaining-radix-sort

-----------------------ADDITIONAL HELP-----------------------------------
6.  A TA from Tufts University has helped me with this assignement. 


