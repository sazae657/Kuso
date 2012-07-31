DIE=cc
KILL=-m64 -fpic -DCOMPILE_DL=1 -g
FUCK=/usr
OBJ=Kuso.o
TGT=kuso.so
PHJ=/usr/local/include/php
PHI=-I$(PHJ) -I$(PHJ)/main -I$(PHJ)/Zend -I$(PHJ)/TSRM -I$(FUCK)/include

PHM=/usr/local/lib
LDF=-lX11 -lXm 
EAG=$(word 5, $(shell php -i|egrep ^extension))

.c.o:
	$(DIE) $(KILL) $(PHI) -c $< -o $@

$(TGT):$(OBJ)
	$(DIE) -g -shared -rdynamic -o $(TGT) $(OBJ) $(LDF)

fuck: $(TGT)
	-rm $(EAG)$(TGT)
	cp $(TGT) $(EAG)

die:
	- rm -f *.o
	- rm -f $(TGT)
