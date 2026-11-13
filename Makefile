CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp alfabeto.cpp automato.cpp transdutor_mealy.cpp relatorio.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = mascarador

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
