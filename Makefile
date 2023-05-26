msm: main.o file.o
	gcc -o msm main.o file.o

main.o: main.c
	gcc -c main.c

file.o: file.c
	gcc -c file.c

clean:
	rm ./msm ./main.o ./file.o