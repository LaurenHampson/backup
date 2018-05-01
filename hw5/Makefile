CXX = g++

CPPFLAGS = -g -Wall



qsorttest: qsorttest.cpp functor.h functor.cpp

	$(CXX) $(CPPFLAGS) $^ -o qsorttest


functortest: functortest.cpp functor.h functor.cpp

	$(CXX) $(CPPFLAGS) $^ -o functortest

Thanksgiving: Thanksgiving.cpp lengthmismatch.h lengthmismatch.cpp 

	$(CXX) $(CPPFLAGS) $^ -o Thanksgiving


.PHONY: clean



clean:

	rm -rf *.o qsorttest
	rm -rf *.o functortest
	rm -rf *.o Thanksgiving