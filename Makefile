CXX = clang
CXXFLAGS = -std=c++11
LDFLAGS = -lstdc++

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main $(LDFLAGS) && ./main
