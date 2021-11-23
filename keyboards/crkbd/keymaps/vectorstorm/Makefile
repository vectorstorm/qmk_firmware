all: rledata.h
clean:
	rm rle
	rm rledata.h

rledata.h: rle
	./rle >rledata.h
	cat rledata.h

rle: rle.c
	gcc -g rle.c -o rle

