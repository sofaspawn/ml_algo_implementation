CXX = clang
CXXFLAGS = -std=c++11
LDFLAGS = -lstdc++ -lm

linear: linear.cpp
	$(CXX) $(CXXFLAGS) linear.cpp -g -o linear $(LDFLAGS) && ./linear && rm linear
