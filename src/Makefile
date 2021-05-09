PROBLEMS	:= 
EXTRA_SRCS	:=
EXTRA_HDRS	:= 

PROB_OBJS	:= $(patsubst %, %.o, $(PROBLEMS)) $(patsubst %.cpp, %.o, $(EXTRA_SRCS))
PROB_SRCS	:= $(patsubst %, %.cpp, $(PROBLEMS)) $(EXTRA_SRCS)
PROB_HDRS	:= $(patsubst %, %.hpp, $(PROBLEMS)) $(EXTRA_HDRS)

OUT	:= restoran
OBJS	:= main.o $(PROB_OBJS)
SOURCE	:= main.cpp $(PROB_SRCS)
HEADER	:= $(PROB_HDRS)

DEPS	:= $(patsubst %.o, %.d, $(OBJS))

CXX	:= g++
FLAGS	:= -g -c -Wall -Wpedantic -Wextra -std=c++14 -MMD $(extra_flags)
LFLAGS	:= -Wall -Wpedantic -Wextra -std=c++14 $(extra_lflags)

ifeq ($(OS),Windows_NT)
	FLAGS += -Wa,-mbig-obj
	OUT := $(OUT).exe
endif

ifeq (,$(findstring /bin/,$(SHELL)))
	CLEAN_CMD := cmd /c del /q *.o *.d *.exe 2>nul
else
	CLEAN_CMD := rm -f *.o *.d $(OUT)
endif

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(OUT)

%.o: %.cpp
	$(CXX) $(FLAGS) $< -o $@

run: $(OUT)
	./$(OUT)

clean:
	$(CLEAN_CMD)

.DELETE_ON_ERROR:
.PHONY: all run clean

-include $(DEPS)