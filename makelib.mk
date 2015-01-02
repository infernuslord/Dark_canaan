
SOURCES := $($(TARGET)_OBJS)
OBJECTS := $(SOURCES:%=$(ODIR)/%.o)
DEPS := $(SOURCES:%=$(DDIR)/%.d)
LIB := $(PRJLIB)/lib$(TARGET).a

ALL: $(LIB)

clean:
	$(RM) $(OBJECTS) $(DEPS) $(LIB)

test:
	@echo $(SYS)
	@echo $(OPT)
	@echo $(DEPFLAGS)

$(LIB): $(OBJECTS) $(PRJLIB)
	$(AR) $(ARFLAGS) $?

include $(MAKETOP)/rules.mk

-include $(DEPS)
