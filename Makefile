jstest.exe: jstest2.c
	i686-w64-mingw32-gcc $^ -lwinmm -o $@
clean:
	rm *.exe
