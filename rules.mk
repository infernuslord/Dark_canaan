.SUFFIXES:

#DEPFLAGS = -MMD $(DDIR)/$*._d -MT $@
DEPFLAGS = -MMD

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

$(ODIR)/%.o: %.c $(PRJOUT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -o $@ -c $<
#	$(MV) $(DDIR)/$*._d $(DDIR)/$*.d

$(ODIR)/%.o: %.cpp $(PRJOUT)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -o $@ -c $<
#	$(MV) $(DDIR)/$*._d $(DDIR)/$*.d

$(ODIR)/%.o: %.asm $(PRJOUT)
	$(AS) $(ASFLAGS) $(CPPFLAGS) -o $@ -c $<

$(PRJLIB) $(PRJOUT) $(PRJDEP):
	$(MKDIR) $@

