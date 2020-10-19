WRAPPER_PROG=fuzz_calc
LIB_FLD=calc
LIB=calc

all: build run

build: clean
	mkdir -p ../tests/test_$(LIB)/fuzz_test
	mkdir -p ../tests/test_$(LIB)/fuzz_test/in
	echo abc > ../tests/test_$(LIB)/fuzz_test/in/t1
	AFL_USE_ASAN=1 afl-gcc ../tests/test_$(LIB)/$(WRAPPER_PROG).c ../src/$(LIB_FLD)/$(LIB).c -o ../tests/test_$(LIB)/fuzz_test/$(LIB)_afl

run:
	afl-fuzz -i ../tests/test_$(LIB)/fuzz_test/in -o ../tests/test_$(LIB)/fuzz_test/out -m none ../tests/test_$(LIB)/fuzz_test/$(LIB)_afl

clean:
	rm -rf ../tests/test_$(LIB)/fuzz_test/
