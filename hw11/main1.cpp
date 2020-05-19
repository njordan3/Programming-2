
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#include "DLinkedList.h"
#include "fraction.h"


void ShowMenu()
{
    cout << "  Linked List Menu \n";
    cout << "  ==================================================\n";
    cout << "  i  Insert a value into the list                   \n";
    cout << "  a  Insert a value after a value                  \n";
    cout << "  d  Delete a value from the list (1st from front)  \n";
    cout << "  c  Does the list contain a specific value        \n";
    cout << "  p  Print the value returned by ToString           \n";
    cout << "  f  Print the value returned by Front()            \n";
    cout << "  b  Print the value returned by Back()            \n";
    cout << "  m  Show this menu                                        \n";
    cout << "  x  Exit                                        \n";
    cout << "  ==================================================\n";
}

int main()
{
    LoggerSetUpLog("main1.log");
    if (true)
    { // make a subsccope


        DLinkedList<ELEMTYPE>  list;
        ELEMTYPE elem;
        ELEMTYPE elem2;

        char selection;
        ShowMenu();

        do
        {
            try
            {

                Prompt("  Enter selection: ",selection);
                cout << "\nOption " << selection << " chosen\n";

                switch(selection)
                {
                    case 'x':
                        cout << "Goodbye.\n";
                        break;
                    case 'm':
                        ShowMenu();
                        break;

                    case 'i':
                        Prompt("Enter element to insert into the list: ",elem);
                        if(list.Insert(elem))
                        {
                            cout << elem << " was added.\n";
                        }
                        else
                        {
                            cout << elem << " was NOT added.\n";
                        }
                        break;

                    case 'a':
                        Prompt("Enter element to insert into the list: ", elem);
                        Prompt("Enter element to insert after: ", elem2);
                        if(list.InsertAfter(elem, elem2))
                        {
                            cout << elem << " was added.\n";
                        }
                        else
                        {
                            cout << elem << " was NOT added.\n";
                        }
                        break;

                    case 'd':
                        Prompt("Enter element to delete: \n", elem); 
                        if(list.Delete(elem))
                        {
                            cout << elem << " removed from the list\n";
                        }
                        else
                        {
                            cout << "Could not remove " << elem << " from the list.\n";
                        }
                        break;

                    case 'c':
                        Prompt("Enter a value to check for: \n", elem); 
                        if(list.Contains(elem))
                        {
                            cout << elem << " is in the list\n";
                        }
                        else
                        {
                            cout << elem << " was not in the list\n";
                        }
                        break;

                    case 'p':
                        cout << list.ToString() << endl;
                        break;

                    case 'f':
                        cout << list.Front() << endl;
                        break;

                    case 'b':
                        cout << list.Back() << endl;
                        break;

                    default:
                        cout << "Invalid menu option!\n";
                }
            }
            catch (const char * msg)
            {
                cout << "Exception Caught: " << msg << endl;
            }
        }
        while(selection != 'x');
    }// end of subscope

}



