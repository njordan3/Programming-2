// Purpose: HW 7 Hash Tables

//          This implements a static sized array-based hash table that uses

//          double hashing for collision resolution. The double hashing probe

//          sequence is hash1 , hash 2



#include <iostream>
#include <limits>
#include <string.h>
using namespace std;

#include "cmpslib.h"
struct LOGGER_DATA LGDATA;

#include "Hash.h"

char menu();
int main()
{
    LoggerSetUpLog("main.log");
    HashTable h;  // Declare the table.
    
    char sel;
    int  num;

    do
    {
        try
        {
            sel = menu();
            switch(sel)
            {
                case 'i':
                    Prompt("Enter an integer: ", num);
                    if(num < 0)
                    {
                        cout << "Integer must be greater than or equal to 0\n";
                        break;
                    }
                    cout << "Inserting " << num << " into the hash table\n";
                    if(h.insert(num))
                    {
                        cout << num << " inserted successfully\n";
                    }
                    else
                    {
                        cout << num << "Error inserting " << num << endl;
                    }
                    break;

                case 'd':
                    if(h.empty())
                    {
                        cout << "Table is empty. Insert data using Option 1 then try again.\n";
                         break;
                    }
                    Prompt("Enter an integer: ", num);
                    cout << "Deleting " << num << " from the hash table\n";
                    if(num < 0)
                    {
                        cout << "Integer must be greater than or equal to 0.\n";
                        break;
                    }
                    if(h.remove(num))
                    {
                        cout << num << " removed from the table\n";
                    }
                    else
                    {
                        cout << "Error removing " << num << endl;
                    }
                    break;

                case 's':
                    Prompt("Enter an integer: ", num);
                    cout << "Searching for " << num << "in the hash table\n";
                    if(h.search(num))
                    {
                        cout << num << " was found\n";
                    }
                    else
                    {
                        cout << num << " was NOT found\n";
                    }
                    break;

                case 'k':
                    Prompt("Enter an integer: ", num);
                    cout << "Primary key for " << num << " is " << h.hash1(num) << ".\n";
                    cout << "Secondary key for " << num << " is " << h.hash2(num) << ".\n";
                    break;

                case 'p':
                    cout << h.ToString() << endl;
                    break;

                case 'x':
                    cout << "Good-bye!\n";
                    break;

                default:
                    cout << "Invalid selection!\n";
            }
        }
        catch(string val)
        {
            cout <<"Exception: " << val << endl;
        }


    } while(sel != 'x');

    return 0;
}

char menu()
{
    LogStart();
    char sel;

    cout << endl;
    cout << "          Hash Table Menu\n";
    cout << "  ===================================\n";
    cout << "  i. Insert an integer into the table\n";
    cout << "  d. Delete an integer from the table\n";
    cout << "  s. Search the table for an integer \n";
    cout << "  k. Print the primary and secondary \n";
    cout << "     keys for an integer             \n";
    cout << "  p. Print HashTable                 \n";
    cout << "                                     \n";
    cout << "  x. Exit                            \n";
    cout << "  ===================================\n";
    Prompt("  Enter selection: ",sel);
    cout << endl;
    LogEndReturning(sel);
    return sel;
}

void getInt(int &tmp, const char *prompt)
{
    LogStart(tmp,prompt);
    cout << prompt;
    cin >> tmp;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. " << prompt;
        cin >> tmp;
    }

    LogEnd(tmp,prompt);
}





