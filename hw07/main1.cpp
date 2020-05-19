
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


// include the standard template library stack

#include <stack>
#include "Stack.h"
// lets define ELEMTYPE  as the type we want our stack to hold

// we want to be sure it is defined defalut to be some known type 


#ifndef ELEMTYPE  // only do the following define if its not already defined

#define ELEMTYPE  int
#endif


void ShowMenu()
{

    cout << "  Stack Menu \n";
    cout << "  ===============================================\n";
    cout << "  i  Push a value into the stack\n";
    cout << "  t  Display the value returned by Top\n";
    cout << "  d  Pop a value from the stack\n";
    cout << "  e  Display the value returned by empty()\n";
    cout << "  s  Display the value returned by size()\n";
    cout << "  p  Display the output of ToString()\n";
    cout << "  m  Show this menu \n";
    cout << "  x  Exit \n";
    cout << "  ===============================================\n";

}


int main()
{
    LoggerSetUpLog("main1.log");

    // create an stl::mystack

    // this is the only time you should use any stl containers 

    //std::stack<ELEMTYPE> mystack; 

    //ELEMTYPE elem;

    Stack stack;
    char selection;
    int val;
    // Initialize the stack before the menu loop


    ShowMenu();

    do
    {
        // the Prompt function is defined in cmpslib.h you can use it for any datatype

        // if you need to have the user input a value in one of the menu driven mains use this function instead of 

        // using cin 
        Prompt("  Enter selection: ",selection);
        cout << "\nOption " << selection << " chosen\n";

        switch(selection)
        {
            case 'i':
                Prompt("Enter element to Push into the stack: ", val);
                if(stack.isFull())
                {
                    cout << val << " was NOT added.\n";
                }
                else
                {
                    stack.Push(val);
                    cout << val << " was added.\n";
                }
                break;

            case 't': 
                cout << "The Top function returned " << stack.Top() << endl;

                break;

            case 'd': 
                if(stack.isEmpty())
                {
                    cout << "could not pop a value\n";
                }
                else
                {
                    stack.Pop();
                    cout << "a value was popped from the stack.\n";
                }
                break;

            case 'e':
                cout << boolalpha << stack.isEmpty() << endl;
                break;

            case 's':
                cout << stack.Size() << endl;
                break;

            case 'p':
                cout << stack.ToString() << endl;
                break;

            case 'x':
                cout << "Goodbye.\n";
                break;

            case 'm':
                ShowMenu();
                break;

            default:
                cout << "Invalid menu option!\n";
        }
    }
    while(selection != 'x');

}


