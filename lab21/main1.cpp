#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#ifndef ELEMTYPE 
#define ELEMTYPE int
#endif


#include "fraction.h"
#include "BST.h"

void ShowMenu()
{
	cout << "             Binary Search Tree\n";
	cout << "  ===============================================\n";
	//_SSR_
	cout << "  i Insert a value into the tree                \n";
	cout << "  p Print the values of the tree in sorted order\n";
	cout << "  m Show this menu\n";
	//_ESR_
	cout << "  x Exit                                        \n";
	cout << "  ===============================================\n";
}



int main()
{
	LoggerSetUpLog("main.log");
	if (true)
	{
	//_SSR_
	BST<ELEMTYPE> tree;
	ELEMTYPE elem;
	//_ESR_
	char  selection;

	// Initialize the tree before the menu loop
	ShowMenu(); 
	do
	{
		Prompt("  Enter selection: ",selection);
		cout << "\nOption " << selection << " chosen\n";
		LogLow("Option %schosen\n",selection);

		switch(selection)
		{
			case 'x':
				cout << "Goodbye.\n";
				break;

				case 'm':
				ShowMenu();
				break;
				//_SSR_

			case 'i':
				Prompt("Enter element to insert into the tree: ",elem);
				if(tree.insert(elem))
				{
					cout << elem << " was added.\n";
				}
				else
				{
					cout << elem << " was NOT added.\n";
				}
				break;



			case 'p':
				tree.print();
				break;

				//_ESR
			default:
				cout << "Invalid menu option!\n";
		}
	}
	while(selection != 'x');
	}

}



