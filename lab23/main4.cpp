#include <iostream>
#include <random>
#include <array>
#include <algorithm>
#include <ctime>
using namespace std;
#include "DLinkedList.h"
#define MAX_VALUES 10000

int main()
{
		/*
			 lets create an array of test values
			 populate the different containters fromt he same array to keep the tests constistent
		 */

		std::array<int,MAX_VALUES> sample_data;
		for ( int loop2=0;loop2< MAX_VALUES;loop2++)
				sample_data[loop2] = loop2;

		// this part will shuffle the array
		std::srand ( unsigned ( std::time(0) ) ); 
		random_shuffle(sample_data.begin(),sample_data.end());


		int search_value = sample_data[(int) (MAX_VALUES  * .5)  ]; // .5 is halfway
		clock_t start,med,end;

		cout << "doubly linked list insert back" << endl;
		start = clock();
		/* 
			 Create an instance of the DLinkedListClass
			 copy over the values from the array 
		 */
		DLinkedList sll_temp1;
		for ( int loop2=0;loop2< MAX_VALUES;loop2++)
				sll_temp1.InsertBack(sample_data[loop2]);
		med = clock();
		/* 
			 create a ListNode and set it by calling the Search function
			 search for the value at postion (DFS * MAX_VALUES)
			 DFS is the percentage of the array we would have to search
		 */

		DListNode*  sll_ptr = sll_temp1.Search(search_value);
		end = clock();

		cout << "insert time:"<< std::fixed  << (double) (med - start) << endl;
		cout << "search time:"<< std::fixed  << (double) (end - med) << endl;

		return 0;
}


