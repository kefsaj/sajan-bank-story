GXX=g++

GXXFLAGS=-std=c++11 -Wall

SRCDIR=source

TESTDIR=tests

unittests: tests.o PersonTests.o Testable.o \
	   TestResult.o Date.o Person.o DialogueLine.o DialogueLineTests.o \
		DialogueTests.o Dialogue.o
	$(GXX) $(GXXFLAGS) -o unittests \
              tests.o PersonTests.o Testable.o \
			  TestResult.o Date.o Person.o DialogueLine.o DialogueLineTests.o \
				DialogueTests.o Dialogue.o 

tests.o: $(TESTDIR)/main.cpp
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/main.cpp -o tests.o

PersonTests.o: $(TESTDIR)/PersonTests.cpp $(TESTDIR)/TestResult.h \
				  $(TESTDIR)/PersonTests.h $(SRCDIR)/Person.h \
				  $(TESTDIR)/Testable.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/PersonTests.cpp

DialogueLineTests.o: $(TESTDIR)/DialogueLineTests.h $(TESTDIR)/DialogueLineTests.cpp \
				 	$(TESTDIR)/Testable.h $(SRCDIR)/DialogueLine.h \
					$(TESTDIR)/TestResult.h 
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/DialogueLineTests.cpp

DialogueTests.o: $(TESTDIR)/DialogueTests.h $(TESTDIR)/DialogueTests.cpp \
					$(TESTDIR)/Testable.h $(SRCDIR)/Dialogue.h \
					$(TESTDIR)/TestResult.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/DialogueTests.cpp

Testable.o: $(TESTDIR)/Testable.cpp $(TESTDIR)/Testable.h \
				 $(TESTDIR)/TestResult.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/Testable.cpp

TestResult.o: $(TESTDIR)/TestResult.cpp $(TESTDIR)/TestResult.h
	$(GXX) $(GXXFLAGS) -c $(TESTDIR)/TestResult.cpp

Date.o: $(SRCDIR)/Date.cpp $(SRCDIR)/Date.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/Date.cpp

Person.o: $(SRCDIR)/Person.cpp $(SRCDIR)/Person.h $(SRCDIR)/Date.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/Person.cpp

DialogueLine.o: $(SRCDIR)/DialogueLine.cpp $(SRCDIR)/DialogueLine.h \
				$(SRCDIR)/Person.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/DialogueLine.cpp

Dialogue.o: $(SRCDIR)/Dialogue.cpp $(SRCDIR)/Dialogue.h $(SRCDIR)/DialogueLine.h
	$(GXX) $(GXXFLAGS) -c $(SRCDIR)/Dialogue.cpp

clean:
	-rm *.o
