#include "cmpslib.h"
struct LOGGER_DATA LGDATA;

#ifndef MAX_SIZE
#define MAX_SIZE 10
#endif


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#include "fraction.h"
#include "Queue.h"



void ShowMenu()
{

    cout << "  Queue Menu\n";
    cout << "  ===============================================\n";
    cout << "  i Enqueue a value into the queue \n";
    cout << "  t Display the value returned by Front\n";
    cout << "  d Dequeue a value from the queue\n"; 
    cout << "  p Display the output of ToString() \n";
    cout << "  e Display the output of Empty()\n"; 
    cout << "  f Display the output of Full() \n";
    cout << "  c Use copy constructor ( NOT = ) to make copy of your queue,    and Display the output of its ToString()\n"; 
    cout << "  m Show this menu \n";
    cout << "  x Exit \n";
    cout << "  ===============================================\n";
}

int main()
{
    LoggerSetUpLog("main1.log");

    char selection;

    // Initialize the queue before the menu loop
    Queue<ELEMTYPE> myQ;
    ELEMTYPE elem;
    ShowMenu();


    do
    {

        try
        {
            Prompt("  Enter selection: ",selection);
            cout << "\nOption " << selection << " chosen\n";

            switch(selection)
            {
                case 'i':
                    {
                        Prompt("Enter element to Enqueue into the queue: ",elem);             
                        if(myQ.enQueue(elem))
                        {
                            cout << elem << " was addded.\n";
                        }
                        else
                        {
                            cout << elem << " was NOT addded\n";
                        }
                        break;
                    }
                case 't':
                    {
                        cout << "the Front function returned " << myQ.Front() << endl;
                        break;
                    }
                case 'd':
                    {
                        myQ.deQueue();
                        break;
                    }
                case 'p':
                    {
                        cout << myQ.ToString() << endl;
                        break;
                    }
                case 'e':
                    {
                        cout << boolalpha << myQ.Empty() << endl;
                        break;
                    }
                case 'f':
                    {
                        cout << boolalpha << myQ.Full() << endl;
                        break;
                    }
                case 'c':
                    {
                        Queue<ELEMTYPE> myQ2(myQ);
                        cout << myQ2.ToString() << endl;
                        break;
                    }
                case 'x':
                    {
                        cout << "Goodbye.\n";
                        break;
                    }
                case 'm':
                    {
                        ShowMenu();
                        break;
                    }

                default:
                    cout << "Invalid menu option!\n";
            }
        }
        catch (const char * msg)
        {  
            cout << "Exception Caught: "<< msg << endl;
        }
    }
    while(selection != 'x');

}



