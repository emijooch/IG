# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica4

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -g -I/usr/include -I.
CXXFLAGS=  -g -I/usr/include -I. -std=c++0x

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -framework GLUT -framework OpenGL -framework Cocoa 

# definicion del compilador
#
CC = g++

# definicion de objetos
#
OBJECTS= practica4.o Bomberos.o escena.o ejes.o Tetraedro.o Objeto3D.o Cubo.o file_ply_stl.o ply.o Revolucion.o Cilindro.o Iluminacion.o Texturas.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ -std=c++11 $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)
	
#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

