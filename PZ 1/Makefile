CXX = cl
CXXFLAGS = /EHsc /W4 /O2 /std:c++17
TARGET = geometry_program.exe

SRCS = main.cpp func.cpp
OBJS = $(SRCS:.cpp=.obj)
HEADERS = structs.h func.h

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) /Fe:$(TARGET) $(OBJS)

main.obj: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) /c main.cpp

func.obj: func.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) /c func.cpp

clean:
	del /Q $(OBJS) $(TARGET)

run: $(TARGET)
	$(TARGET)

.PHONY: clean run