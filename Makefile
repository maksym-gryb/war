CC = g++
CC_FLAGS = -Iinc -Wall -g
LD_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

INC = #hello.h

SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

EXECUTABLE = app 

# Start of execution directives
#run: ${EXECUTABLE}
#	clear
#	./${EXECUTABLE}

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LD_FLAGS)

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(EXECUTABLE)
