#pragma once
#include "cmpslib.h"
#include "Square.h"

// the Triangle class will contain 
class Triangle : public Square
{
    //data members

    protected:/**/
        double height;

        //functions

    public:/**/
        Triangle();
        /* set height to 0 ( use Setheight  ), length should be set in Square constructor */


        Triangle(double, double);
        /*
           set length to value one passed in 
           set height to value two passed in 
           use SetLength and Setheight
           */


        ~Triangle();
        /* just log start & end */

        void SetHeight(double );
        /* set height to value passed in , if value is less than zero set height to 0 */


        double Area();
        /* return the area,  (-5. (length * height)) */

        string ToString();
        /* return a formatted string like the example */

};/**/


