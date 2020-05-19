#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library


#include "Square.h"
#include "Triangle.h"



int main()
  {
  LoggerSetUpLog("main1.log");

  //------------------------------------------------------------------


  LogLow("testing the Square class \n");
  if (true)
    {
    // test Square class
        Square a;
        cout << "Create a square named a, use the default constructor\n";
        cout << "a.ToString() returns: " << a.ToString() << endl;
        a.SetLength(-3.0);
        cout << "Use the SetLength function to set a with the value -3.0\n";
        cout << "a.ToString() returns: " << a.ToString() << endl;
        a.SetLength(3.5);
        cout << "Use the SetLength function to set a with the value 3.5\n";
        cout << "a.ToString() returns: " << a.ToString() << endl;
        

        Square b(44);
        cout << "Create a Square named b, use the parametrized constructor to create one with the initial value of 44\n";
        cout << "b.ToString() returns: " << b.ToString() << endl;
       
        Triangle c;
        cout << "Create a Triangle c, use the default constructor\n"; 
        cout << "c.ToString() returns: " << c.ToString() << endl;
        c.SetLength(-3.0);
        cout << "Use the SetLength function to set a with the value -3.0\n";
        cout << "c.ToString() returns: " << c.ToString() << endl;
        c.SetLength(3.5);
        cout << "Use the SetLength function to set a with the value 3.5\n";
        cout << "c.ToString() returns: " << c.ToString() << endl;
        c.SetHeight(-9);
        cout << "Use the SetHeight function to set a with the value -9.0\n";
        cout << "c.ToString() returns: " << c.ToString() << endl;
        c.SetHeight(9.5);
        cout << "Use the SetHeight function to set a with the value 9.5\n";
        cout << "c.ToString() returns: " << c.ToString() << endl;
        
        
        Triangle d(3,9);
        cout << "Create a Triangle named d, use the parametereized constructor to create it with the initial lenght of 3 and a width of 9\n";
        cout << "d.ToString() returns: " << d.ToString() << endl;


    
    }

  LogLow("finished testing the Square class \n\n\n\n");

  LogLow("testing the Triangle class \n");
  if (true)
    {
    //test Triangle class

    

    }
  LogLow("finished testing the Triangle class \n\n\n\n");



  //------------------------------------------------------------------


  ////LoggerClose();

  return 0;
  }
