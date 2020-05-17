SRCS = UsgsTree.cpp UsgsTreeTest.cpp submitty_driver.cpp
EXE = a.out
BRIDGES_LDFLAGS = -L/usr/local/submitty/bridges/curl/lib
BRIDGES_CXXFLAGS = -I. -I/usr/local/submitty/bridges/curl/include -I/usr/local/submitty/bridges/bridges/include


ifneq ("$(wildcard UsgsTreeDriver.cpp)","")
	# Code.CS settings
	SRCS = UsgsTree.cpp UsgsTreeTest.cpp UsgsTreeDriver.cpp
	EXE = UsgsTree.out
	BRIDGES_LDFLAGS = -L../../include/curl/lib
	BRIDGES_CXXFLAGS = -I. -I../../include/curl/include -I../../include/bridges/include
else ifneq ("$(wildcard UsgsTree.cpp)","")
	# Do nothing. Leave defaults.
else
	# Testing locally.
	SRCS = ../UsgsTree.cpp UsgsTreeTest.cpp submitty_driver.cpp
	BRIDGES_LDFLAGS = -L../../../../include/curl/lib
	BRIDGES_CXXFLAGS = -I.. -I. -I../../../../include/curl/include -I../../../../include/bridges/include
endif

# Everything below that should not have to change ever.

CXX=g++
LD=g++
CC=g++

TARGET = all 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -std=c++14 $(BRIDGES_CXXFLAGS)

LDFLAGS = -g $(BRIDGES_LDFLAGS) -pthread
LIBS = -lcurl

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(EXE)

clean:
	-rm -f $(OBJS)
	-rm -f $(EXE)
