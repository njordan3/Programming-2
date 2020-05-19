# Start of the actual Makefile
# set a default level for the logging
LOGLEVEL?=3 # 0-none, 1-low, 2-med, 3 high

# this will be the compiler we want to use allong with all the options
# -Wall     ( with all warnings)
# -std=c++11  ( use c++ 2011 version  of the ANSI standards)
# set the macro LOGLEVEL to be defined with a value
COMP=g++ -Wall -std=c++11 -D LOGLEVEL=$(LOGLEVEL)

all:	runme1 runme2 runme3 runme4 runme5 runme6

clean:
		rm  -f runme* *~  core *.log *.gch *.o 

runme1:	main1.cpp Shape.h 
	$(COMP) -o runme1 main1.cpp 

runme2:	main2.cpp Shape.h Line.h 
	$(COMP) -o runme2 main2.cpp 

runme3:	main3.cpp Shape.h Line.h Square.h 
	$(COMP) -o runme3 main3.cpp 

runme4:	main4.cpp Shape.h Line.h Square.h Cube.h 
	$(COMP) -o runme4 main4.cpp 

runme5:	main5.cpp Shape.h Line.h Rectangle.h 
	$(COMP) -o runme5 main5.cpp 

runme6:	main6.cpp Shape.h Line.h Rectangle.h Rectangular_Prism.h 
	$(COMP) -o runme6 main6.cpp 




# DO NOT DELETE THIS LINE -- make depend depends on it.




