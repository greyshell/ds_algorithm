# Description

## Usage of `make` utility and `static` / `shared` library

- create a `.c` file and write a function that you would like to use as `library`.
- create a `.h` file and declare that function.

## Use `make` utility to build both `static` and `shared` libraries

```
make -f create_lib LIB=foo FLD=foo
```

##### Use `make` utility to build a `shared` library(`*.so`) from that function

```
make -f create_lib LIB=foo FLD=foo build-shared
```

##### Use `make` utility to build a `static` library(`*.a`) from that function

```
make -f create_lib LIB=foo FLD=foo build-shared
```

##### Clean / delete `static`, `shared` library and `object` files all together

```
make -f create_lib LIB=foo FLD=foo clean
```

##### Clean the `static` library and `object` files.

```
make -f create_lib LIB=foo FLD=foo clean-static
```

##### Clean the `shared` library and `object` files.

```
make -f create_lib LIB=foo FLD=foo clean-shared
```

## How to use the source file or `.c` file directly into the code
> `Note`: in `Makefile`, all lines are indented by `tab` characters not `space`.

Add the following lines in `CmakeLists.txt` file to build the final `executable`.

```
FILE(GLOB MyFoo private_libs/foo/foo.c)
add_executable(test_foo basic/test_foo.c ${MyFoo})
```

## How to use the `shared` / `static` library(`.so` / `.a`) directly into the code

- `FLD`: provide the folder name where the target program is present
- `PROG`: provide program name that uses the library
- `LIB`: provide the lib name to generate the binary with that name.

```
# build two executables inside `cmake-build-debug` directory using shared and static library
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo 

# build the executable using static library 
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo build-static

# run the executable using the static library 
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo run-static

# for linux add the shared lib path into ~/.zshrc.
export LD_LIBRARY_PATH=/root/Dropbox/pentest/code_dev/ds_algorithm/private_libs/lib_shared

# build the mac binary
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo build-mac

# run the mac binary
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo run-shared-mac

# clean / remove the binary from cmake-build-debug folder
make -f create_binary_from_lib FLD=basic PROG=test_foo LIB=foo clean
```

## How to fuzz my `private` libraries with `AFL`

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

## Execute all commands using `make` utility

- `SRC_FLD`: provide the directory name where the wrapper program is present.
- `WRAPPER_PROG`: provide the wrapper program name without `file extension`.
- `LIB_FLD`: provide the lib folder name
- `LIB`: provide the lib name 

```
make -f fuzz_lib_with_afl SRC_FLD=stack WRAPPER_PROG=fuzzlib_stack_using_singly_linked_list LIB_FLD=stack LIB=stack_using_singly_linked_list 
```

## How to inspect the crash

- `afl` writes all crashes inside `out/crashes` directory. 
- in order to reproduce the crash with a crash data, navigate to `fuzz_lib/<lib>` directory and execute the binary. 

```
./fuzz_afl/stack_using_singly_linked_list/stack_using_singly_linked_list_afl  < out/crashes/id:000000,sig:06,src:000000,op:havoc,rep:64
```
