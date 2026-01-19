CXX = g++ 
ifneq ($(TERMUX_VERSION),)
	CXX = clang++
endif

CXXFLAGS = -std=c++17 -Wall -Iinc -Wno-unused-but-set-variable -Wno-unused-local-typedefs -O2

ifneq ($(DEBUG),1)
	CXXFLAGS += -g
endif

CXXFLAGS += -I$(CSOLVER_HOME)/inc

LDFLAGS = -L$(CSOLVER_HOME)/lib
LDLIBS = -lcsolver

TARGET = video_audio_c

SRCS = main.cpp $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(TARGET) $(OBJS)
