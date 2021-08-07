all : pet.o specification.o environment.o
	gcc -std=c99 -o pet pet.o specification.o environment.o

pet.o : pet.c
	gcc -std=c99 -c pet.c -lpthread

specification.o : ./specification/specification.c
	gcc -std=c99 -c ./specification/specification.c

environment.o : ./environment/environment.c
	gcc -std=c99 -c ./environment/environment.c

clean :
	rm -f pet pet.o specification/specification.o environment/environment.o