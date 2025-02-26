CXX = clang
CXXFLAGS = -std=c++11
LDFLAGS = -lstdc++

linear: linear.cpp
	$(CXX) $(CXXFLAGS) linear.cpp -o linear $(LDFLAGS) && ./linear && rm linear
