all: liblist.so driver

liblist.so: list.c list.h
	gcc -g -O0 -finstrument-functions list.c -fPIC -shared -o liblist.so

driver: liblist.so driver.c
	gcc -g -O0 -finstrument-functions -L ../../../Aviso/Runtime -lIRPTR -L. -llist -o driver driver.c

clean:
	-rm liblist.so
	-rm driver
