#macro
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
PROGRAM      := run
INCDIR       := include
SRCDIR       := src
OBJDIR       := obj
SRCS         := $(wildcard $(SRCDIR)/*.cpp)
OBJS         := $(OBJDIR)/main.o

CXX          := g++
INCLUDE      := -I$(MAKEFILE_DIR)$(INCDIR)/
CFLAGS       := -Wall -c -O2

$(PROGRAM): $(OBJS)
	$(CXX) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PROGRAM)
