CC := gcc
CXX := g++
CPP := gcc -E
AS := gcc -x assembler
YACC := bison
LEX := flex
AR := ar

CFLAGS := -std=c99 -W -Wall $(CFLAGS)
CXXFLAGS := -std=c++98 -W -Wall $(CXXFLAGS)
ARFLAGS := r

dbg_CFLAGS := -g -O0 -DDBG_ON
dbg_ASFLAGS := -g
dbg_LDFLAGS := -g
opt_CFLAGS := -O2

MKDIR := mkdir -p
MV := mv -f
CP := cp -a

INCLUDES := $(MAKETOP)/tech/h $(MAKETOP)/tech/libsrc
DEFINES := NOUNREF

-include $(MAKETOP)/envloc.mk
