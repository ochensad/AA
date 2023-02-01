DRIVERDIR := src
INPUTFILES := config-28.txt matrix-7.txt
MODE := -USER
DAYCOUNT := 100


GOCOMP := go run
PYINT  := python3

.PHONY: app autoconf

app:
	@cd $(DRIVERDIR); $(GOCOMP) main.go $(INPUTFILES) $(DAYCOUNT) $(MODE); cd ..

