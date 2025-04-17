all:
	gcc -o messageblender main.c -l:libimago.a -l:libpng.a -l:libjpeg.a -lz -lm
