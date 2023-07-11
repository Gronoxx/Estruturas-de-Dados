
all:
	gcc -Dm=3 -DCARGA=100 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=3 -DCARGA=10000 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=100 -DCARGA=10000 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=500 -DCARGA=500 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=1000 -DCARGA=500 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=500 -DCARGA=1000 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp

	gcc -Dm=10000 -DCARGA=3 -c src/main.c -o obj/main.o
	gcc -o bin/arvexp obj/main.o -lm
	./bin/arvexp
clean:
	rm -rf obj/*
	rm -rf bin/*
