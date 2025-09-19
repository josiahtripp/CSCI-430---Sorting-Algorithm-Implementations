CC := g++
CFLAGS := -Wall -Wextra
INCL := include

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

TARGET := SortingAlgs

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)