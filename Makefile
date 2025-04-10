all:
	gcc -o main main.c -l:libimago.a -l:libpng.a -l:libjpeg.a -lz -lm
