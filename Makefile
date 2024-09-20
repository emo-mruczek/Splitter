objects = sheet.o person.o expense.o main.o
CXX = g++
SRC_DIR = src
CXXFLAGS = -Wall -Werror  

all: main

main: $(objects)
	$(CXX) $(objects) -o main

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main

