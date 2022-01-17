# Makefile is an alternate to the code - g++  driver.cpp  helper_functions.cpp  basic_functions.cpp  moves.cpp  operations.cpp
# A key feature of makefile is that it ensures only those files that have changes are compiled again.
# gcc -c means compile but don't link. Used to create object files.

run: driver.o helper_functions.o basic_functions.o moves.o operations.o 
	g++ driver.o helper_functions.o basic_functions.o moves.o operations.o -o run

# When there is a change in any of the above .o files,execute the line of code above

operations.o: operations.cpp header4.h 
	g++ -c operations.cpp

# Means that whenever operations.cpp or header4.h changes, generate operations.o again using the line of code above

moves.o: moves.cpp header1.h header2.h header3.h
	g++ -c moves.cpp

basic_functions.o: basic_functions.cpp header1.h header2.h 
	g++ -c basic_functions.cpp

helper_functions.o: helper_functions.cpp header1.h
	g++ -c helper_functions.cpp

driver.o: driver.cpp 
	g++ -c driver.cpp

clean:							# delete all .o and .out files and our executable 'run'
	rm -f *.o *.out run