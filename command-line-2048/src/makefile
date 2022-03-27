# Makefile is an alternate to the code - g++  driver.cpp  helper.cpp  core.cpp  moves.cpp
# A key feature of makefile is that it ensures only those files that have changes are compiled again.
# g++ -c means compile but don't link. Used to create object files. Those object files are linked later (see line 5).

run: driver.o helper.o core.o moves.o  
	g++ driver.o helper.o core.o moves.o -o run

moves.o: moves.cpp ../header/helper.h ../header/core.h ../header/moves.h
	g++ -c moves.cpp

core.o: core.cpp ../header/helper.h ../header/core.h 
	g++ -c core.cpp

helper.o: helper.cpp ../header/helper.h
	g++ -c helper.cpp

driver.o: driver.cpp 
	g++ -c driver.cpp

clean:							# delete all .o and .out files and our executable 'run'
	rm -f *.o *.out run