#include <list> // include the listlibraray 
#include <algorithm>
#include <iostream> // include the library for input/output streams   (cout, endl and such)

using namespace std;

void PrintBackwards(string val)
{
    for(int x = val.length(); x >= 0; x--)
    {
        cout << val[x];
    }    
    cout << endl;
}

int main()
{
    list<string> l;
    cout << "creating a string list\n";
    cout << "adding values to the list\n";
    cout << "adding value one\n";
    l.push_back("one");   
    cout << "adding value two\n";
    l.push_back("two");   
    cout << "adding value three\n";
    l.push_back("three");   
    cout << "adding value four\n";
    l.push_back("four");   
    cout << "adding value five\n\n\n";
    l.push_back("five"); 
    cout << "creating an iterator\n";
    cout << "setting the iterator = to l.begin()\n";
    list<string>::iterator temp = l.begin();
    cout << "our iterator points to the value " << *temp << endl;
    cout << "incrementing the iterator\n";
    temp++;
    cout << "our iterator now points to the value " << *temp << endl;
    cout << endl << endl;
    cout << "printing the items in the list front to back\n";
    temp = l.begin();
    while(temp != l.end())
    {
        cout << "the iterator now points to " << *temp << endl;
        temp++; 
    }
    cout << "\ncreating revers_iterator = to l.rbegin()\n";
    list<string>::reverse_iterator temp2 = l.rbegin();
    cout << "printing the items in the list back to front\n";
    while(temp2 != l.rend())
    {
        cout << "the iterator now points to " << *temp2 << endl;
        temp2++;
    }
    cout << "\nprinting the items backwards\n";
    for_each(l.begin(),l.end(),PrintBackwards);
    

    return 0;
}


