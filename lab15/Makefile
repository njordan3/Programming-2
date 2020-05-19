# Start of the actual Makefile
FLAGS = -Wall -std=c++11
LOG = -D LOGLEVEL=3 # 0-none, 1-low, 2-med, 3 high


all:	runme1 runme2 runme3 runme4

clean:
		rm  -f runme* *~  core *.log *.gch  *.o 


runme1:	main1.cpp Queue.h 
	g++ $(FLAGS) -o runme1 $(LOG) main1.cpp   

runme2:	main2.cpp Queue.h 
	g++ $(FLAGS) -o runme2 $(LOG) main2.cpp   

runme3:	main3.cpp Queue.h 
	g++ $(FLAGS) -o runme3 $(LOG) main3.cpp   

runme4:	main4.cpp Queue.h 
	g++ $(FLAGS) -o runme4 $(LOG) main4.cpp   



# DO NOT DELETE THIS LINE -- make depend depends on it.




