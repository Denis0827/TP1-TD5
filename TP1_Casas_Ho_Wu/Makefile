CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = BacktrackingKP01wCG.cpp KP01withCGInstance.cpp Solution.cpp Graph.cpp BruteForceKP01wCG.cpp DynamicProgrammingKP01.cpp
HEADERS = KP01withCGInstance.h Solution.h DynamicProgrammingKP01.h BacktrackingKP01wCG.h BruteForceKP01wCG.h Graph.h Item.h
OBJ = $(SRC:.cpp=.o)
EXEC = knapsack_solver

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
