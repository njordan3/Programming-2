# Start of the actual Makefile
# set a default level for the logging
LOGLEVEL?=0 # 0-none, 1-low, 2-med, 3 high

# this will be the compiler we want to use allong with all the options
# -Wall     ( with all warnings)
# -std=c++11  ( use c++ 2011 version  of the ANSI standards)
# set the macro LOGLEVEL to be defined with a value
COMP=g++ -Wall -std=c++11 -D LOGLEVEL=$(LOGLEVEL)  



# all is the default case , ours is to build "runme"
all:runme performance 
	
# clean up all the .o files, log files and other misc stuff
clean:
	rm  -f runme* *~  core *.log *.gch *.o


runme:  main1.cpp  Hash_stu.o
	$(COMP) -o runme main1.cpp  Hash_stu.o    
   
Hash_stu.o:			Hash.h Hash_stu.cpp
	$(COMP) -c Hash_stu.cpp
   
performance:  performance.cpp  Hash_stu.o
	$(COMP) -o  performance  performance.cpp  Hash_stu.o    
   

# DO NOT DELETE THIS LINE -- make depend depends on it.




