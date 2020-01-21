dl_example.out: array_test_dl.c
	gcc -shared array.c -o libarray.so
	gcc array_test_dl.c -o dl_exaple.out -ldl
example.out: array_test.c
	gcc -shared array.c -o libarray.so
	gcc -c array_test.c 
	gcc array_test.o -larray -L. -o example.out -Wl,-rpath,.
clean: 
	rm *.o
