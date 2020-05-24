# How to create a library

##### usage of `make` utility and `static` and `shared` library

- create a `.c` file and write a function that you want to use as library.
- create a `.h` file and declare that function.

##### use `make` utility to build both `static` and `shared` libraries
```
make -f create_lib LIB=foo
```

##### use `make` utility to build a `shared` library(`*.so`) from that function
```
make -f create_lib build-shared LIB=foo
```

##### use `make` utility to build a `static` library(`*.a`) from that function
```
make -f create_lib build-shared LIB=foo
```

##### clean / delete `static`, `shared` library and `object` files all together.
```
make -f create_lib clean
```
##### clean the `static` library and `object` files.
```
make -f create_lib clean-static
```

##### clean the `shared` library and `object` files.
```
make -f create_lib clean-shared
```

##### how to use the source / `.c` file directly in the code
- `note`: in `Makefile`, all lines are indented by `tab` characters not `space`.
- add the following lines in `CmakeLists.txt` file to build the final `executable`.
```
# include all library code
FILE(GLOB MyCSources private_libs/*.c)
add_executable(test_two_libs refresher/test_two_libs.c ${MyCSources})
```

##### how to use the `shared` / `static` library directly in the code
- copy `template/create_binary_from_lib` makefile to the directory where source file (`test_foo.c`) exists.
- specify the `PROG` = source_file and `LIB` = library_used while building the binary using `make` utility.
```
# build two executables using shared and static library
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo

# build the executable using static library 
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo build-static

# run the executable using the static library 
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo run-static

# for linux add the shared lib path into ~/.zshrc.
export LD_LIBRARY_PATH=/root/Dropbox/pentest/code_dev/kali_coding/ds_algorithm/private_libs/shared

# build the linux binary
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo build-linux

# run the linux binary
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo run-shared-linux

# clean / remove the binary from cmake-build-debug folder
make -f create_binary_from_custom_lib PROG=test_foo LIB=foo clean
```

# How to fuzz my custom library with AFL

- create a wrapper program to simulate all operations exposed by the test program.
- create a directory - `fuzz_afl`.
- create a dummy test case just to kick off the fuzzer. 
```
mkdir fuzz_afl
mkdir fuzz_afl/lib_name
mkdir fuzz_afl/lib_name/in
echo abc > fuzz_afl/lib_name/in/t1
```
- navigate to the folder which has the wrapper program.
- compile that wrapper program with `afl-gcc` and create the binary inside the `lib_name` directory.
```
AFL_USE_ASAN=1 afl-gcc test_lib_name_fuzz.c ../private_libs/lib_name.c -o ../fuzz_alf/lib_name/lib_name_afl
```
- execute the binary to check that runs properly
- run the `afl-gcc` fuzzer.
```
afl-fuzz -i ../fuzz_afl/lib_name/in -o ../fuzz_afl/lib_name/out -m none ../fuzz_afl/lib_name/lib_name_afl
```
- `afl` writes all crashes inside `out/crashes` directory. 
- reproduce the crash with a crash data.
```
./lib_name_afl < out/crashes/id:000000,sig:06,src:000000,op:havoc,rep:64
```

##### execute all commands using `make` utility

- provide the directory name as `FLD` where fuzz wrapper file is present.
- provide the fuzz lib name as `LIB`.
```
make -f fuzz_lib_with_afl FLD=linked_list LIB=singly_linked_list
```