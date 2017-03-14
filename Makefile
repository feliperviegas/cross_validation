CCC= g++
PARAMETERS = -O3 -lm

main: crossValidation.o
	$(CCC) $(PARAMETERS) -o crossValidation crossValidation.o

crossValidation.o: crossValidation.cpp crossValidation.h
	$(CCC) $(PARAMETERS) -c crossValidation.cpp -o crossValidation.o

clean:
	rm -f *.o crossValidation *~
