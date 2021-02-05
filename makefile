CXX       := g++
CXX_FLAGS := -std=c++11 -ggdb

EXECUTABLE  := Main


all: $(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(EXECUTABLE): *.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ 

clean:
	-rm $(BIN)/*