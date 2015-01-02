ifndef MAKETOP
MAKETOP := $(CURDIR)
endif
export MAKETOP

SUBDIRS := lib cam

$(SUBDIRS):
	cd $@ && $(MAKE)

