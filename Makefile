GXX=g++

GXXFLAGS=-std=c++11 -Wall

SRCDIR=source

TESTDIR=tests

unittests: tests.o PersonTests.o Testable.o \
	   TestResult.o Date.o Person.o
	$(GXX) $(GXXFLAGS) -o unittests \
              tests.o PersonTests.o Testable.o \
			  TestResult.o Date.o Person.o

tests.o: $(TESTDIR)/main.cpp
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/main.cpp -o tests.o

PersonTests.o: $(TESTDIR)/PersonTests.cpp $(TESTDIR)/TestResult.h \
				  $(TESTDIR)/PersonTests.h $(SRCDIR)/Person.h \
				  $(TESTDIR)/Testable.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/PersonTests.cpp

Testable.o: $(TESTDIR)/Testable.cpp $(TESTDIR)/Testable.h \
				 $(TESTDIR)/TestResult.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/Testable.cpp

TestResult.o: $(TESTDIR)/TestResult.cpp $(TESTDIR)/TestResult.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/TestResult.cpp

Date.o: $(SRCDIR)/Date.cpp $(SRCDIR)/Date.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/Date.cpp

Person.o: $(SRCDIR)/Person.cpp $(SRCDIR)/Person.h $(SRCDIR)/Date.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/Person.cpp

clean:
	-rm *.o
