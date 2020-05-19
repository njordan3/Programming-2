
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#include "SLinkedList.h"
#include "fraction.h"


void ShowMenu()
{
  cout << "  Linked List Menu \n";
  cout << "  ==================================================\n";
  cout << "  i  Insert a value into the list                   \n";
  cout << "  p  Print the value returned by ToString           \n";
  cout << "  m  Show this menu                                        \n";
  cout << "  x  Exit                                        \n";
  cout << "  ==================================================\n";
}

int main()
{
  LoggerSetUpLog("main1.log");
  if (true)
  { // make a subsccope


    SLinkedList<ELEMTYPE>  list;
    ELEMTYPE elem;

    char selection;
    ShowMenu();

    do
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



        case 'p':
          cout << list.ToString() << endl;
          break;


        default:
          cout << "Invalid menu option!\n";
      }
    }
    while(selection != 'x');
  }// end of subscope

}



