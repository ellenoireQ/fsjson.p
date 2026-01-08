CXX=g++
CXXFLAGS= -Wall -Wextra -std=c++20 -MMD -MP
TARGET=main
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)
.PHONY: all clean run

# Clean all 
clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS)

run: all
	./$(TARGET)
