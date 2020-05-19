
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#include "fraction.h"
#include "Stack.h"
void ShowMenu()
{

	cout << "  Stack Menu \n";
	cout << "  ===============================================\n";
    cout << "  i  Push a value into the stack\n";
    cout << "  t  Display the value returned by Top\n";
    cout << "  d  Pop a value from the stack\n";
    cout << "  p  Display the output of ToString()\n";    
	cout << "  m  Show this menu \n";
	cout << "  x  Exit \n";
	cout << "  ===============================================\n";

}


int main()
{
	LoggerSetUpLog("main.log");
	
	char selection;
    
	// Initialize the stack before the menu loop
    Stack<ELEMTYPE> stack;
    ELEMTYPE elem;

	ShowMenu();
	do
	{
		try{
			Prompt("  Enter selection: ",selection);
			cout << "\nOption " << selection << " chosen\n";

			switch(selection)
			{
                case 'i':
                    Prompt("Enter element to Push into the stack: ", elem);                        
                    stack.Push(elem);
                    cout << elem << " was added.\n";
                    break;
				
                case 't':
                    if(!stack.Empty())
                    {
                        cout << "The Top function returned " << stack.Top() << endl;
                    }
                    else
                    {
                        cout << "Exception:Stack::Top could not return top value from empty stack.\n";
                    }
                    break;
                case 'd':
                    if(stack.Empty())
                    {
                        cout << "could not pop a value\n";
                    }
                    else
                    {
                        stack.Pop();
                        cout << "a value was popped from the stack.\n";
                    }
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
		catch (const char * msg)
		{
			cout << "Exception:" << msg << endl;	

		}
	}
	while(selection != 'x');

}



