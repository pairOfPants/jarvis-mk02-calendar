GCC = g++
GXXFLAGS = -g -Wall -fsanitize=address

test: test.o calendar.o
	$(GCC) $(GXXFLAGS) test.o calendar.o -o test

test.o: test.cpp calendar.h
	$(GCC) $(GXXFLAGS) -c test.cpp

calendar.o: calendar.cpp calendar.h
	$(GCC) $(GXXFLAGS) -c calendar.cpp

clean:
	rm -f *.o test