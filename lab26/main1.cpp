#include <vector> // include the vector libraray 

#include <iostream> // include the library for input/output streams   (cout, endl and such)

#include <algorithm> // for the random_shuffle and sort

#include <ctime> // to seed the random number generator



using namespace std;

int main()
{
   srand(time(NULL));
    // create a vector to store Integers
    vector<int> vec;
    cout  << "creating an integer vector" << endl;
    for(int loop = 10; loop < 60; loop = loop+10)
    {
        cout << "adding value " << loop << endl;
        vec.push_back(loop);
    }
    cout << "size returns " << vec.size() << endl << endl << endl;
    cout << "creating standard vector::iterator\n";
    cout << "setting the iterator = to vec.begin()\n";
    vector<int>::iterator temp = vec.begin();
    cout << "our iterator points to the value " << *temp << endl;
    cout << "incrementing the iterator\n";
    temp++;
    cout << "our iterator now points to the value " << *temp << endl << endl << endl;
    cout << "printing the items in the vector front to back\n";
    temp = vec.begin();
    while(temp != vec.end())
    {
        cout << "the iterator now points to " << *temp << endl;
        temp++;
    }
    cout << "\nusing [] operator\n";
    int loop2 = 0;
    for(auto loop = vec.begin(); loop != vec.end(); loop++)
    {
        cout << "myIntegerVector[" << loop2 << "] = " << vec[loop2] << endl;
        loop2++;
    }
    random_shuffle(vec.begin(),vec.end());
    cout << "\ncalling random_shuffle\n";
    int loop3 = 0;
    for(auto loop = vec.begin(); loop != vec.end(); loop++)
    {
        cout << "myIntegerVector[" << loop3 << "] = " << vec[loop3] << endl;
        loop3++;
    }
    sort(vec.begin(),vec.end());
    cout << "\ncalling sort\n"; 
    int loop4 = 0;
    for(auto loop = vec.begin(); loop != vec.end(); loop++)
    {
        cout << "myIntegerVector[" << loop4 << "] = " << vec[loop4] << endl;
        loop4++;
    }



    return 0;
}



