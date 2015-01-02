ODIR := .out
DDIR := .dep

ifndef PRJTOP
PRJTOP := $(CURDIR)
endif
PRJLIB := $(abspath $(PRJTOP)/../../lib)
PRJOUT = $(PRJTOP)/$(ODIR)
PRJDEP = $(PRJTOP)/$(DDIR)

-include $(PRJTOP)/flags.mk

SYS ?= linux64
OPT ?= dbg

PRJLIB := $(PRJLIB)/$(SYS)-$(OPT)
ODIR := $(ODIR)/$(SYS)-$(OPT)
DDIR := $(DDIR)/$(SYS)-$(OPT)

CFLAGS += $($(OPT)_CFLAGS)
CXXFLAGS += $($(OPT)_CFLAGS) $($(OPT)_CXXFLAGS)
ASFLAGS += $($(OPT)_ASFLAGS)
LDFLAGS += $($(OPT)_LDFLAGS)

CPPFLAGS += $(DEFINES:%=-D%)
CPPFLAGS += -I. -I$(PRJTOP) $(INCLUDES:%=-I%)

all: ALL


