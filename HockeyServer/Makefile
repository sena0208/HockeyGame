#macro
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
PROGRAM      := run
INCDIR       := include
SRCDIR       := src
OBJDIR       := obj
SRCS         := $(wildcard $(SRCDIR)/*.cpp)
OBJS         := $(OBJDIR)/main.o \
                $(OBJDIR)/hockey_server.o \
								$(OBJDIR)/spuck.o \
								$(OBJDIR)/steam.o \
								$(OBJDIR)/smallet.o

CXX          := g++
INCLUDE      := -I$(MAKEFILE_DIR)$(INCDIR)/
CFLAGS       := -Wall -c -O3


$(PROGRAM): $(OBJS)
	@$(CXX) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CXX) $(CFLAGS) $(INCLUDE) $< -o $@

.PHONY: clean
clean:
	@$(RM) $(OBJS) $(PROGRAM)
								
