#
# Makefile para construir el proyecto distlocrec.exe
#
# AAFR, 22 de noviembre de 2016
#

CC= gcc -c

CLINKER= gcc -lm -o

FLAGS= -O3 -Wall

OBJ= main.o algoritmo.o cargadatos.o salida.o

DIR_SRC=./src/

DIR_BIN=./bin/


all: sclean $(OBJ)
	$(CLINKER) $(DIR_BIN)distlocrec.exe $(OBJ) $(FLAGS)
	@rm -rf *.o


%.o: $(DIR_SRC)%.c
	$(CC) $(FLAGS) $<


clean:
	@rm -rfv *.o


sclean:
	@rm -rfv *.o
	@rm -rfv $(DIR_BIN)*.exe
