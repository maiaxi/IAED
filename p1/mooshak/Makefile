# Copyright (C) 2021, Pedro Reis dos Santos
.SUFFIXES: .in .out .diff
MAKEFLAGS += --no-print-directory # No entering and leaving messages
OK="\e[1;32mtest $< PASSED\e[0m"
KO="\e[1;31mtest $< FAILED\e[0m"
EXE=../proj1

all:: clean # run regression tests
	@$(MAKE) $(MFLAGS) `ls *.in | sed -e "s/in/diff/"`

.in.diff:
	@-$(EXE) < $< | diff - $*.out > $@
	@if [ `wc -l < $@` -eq 0 ]; then echo $(OK); else echo $(KO); fi;

mooshak::
	for i in T*; do cp $$i/input test`basename $$i | sed -e "s/T//"`.in; cp $$i/output test`basename $$i | sed -e "s/T//"`.out; done

clean::
	rm -f *.diff
