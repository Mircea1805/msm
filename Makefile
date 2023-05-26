msm: main.o file.o modules.o
	gcc -o msm main.o file.o modules.o

main.o: main.c
	gcc -c main.c

file.o: file.c
	gcc -c file.c

modules.o: modules.c
	gcc -c modules.c

clean:
	rm ./main.o ./file.o ./modules.o