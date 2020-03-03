## Usage of `make` utility and `static` and `shared` library

- create a `.c` file and write a function that you want to use as library.
- create a `.h` file and declare that function.

### use `make` utility to build a `shared` library(`*.so`) from that function
```
make -f create_lib build-shared PROG=sort
```

### use `make` utility to build a `static` library(`*.a`) from that function
```
make -f create_lib build-shared PROG=sort
```

### use `make` utility to build both `static` and `shared` libraries
```
make -f create_lib PROG=sort
```

### clean / delete `static`, `shared` library and `object` files all together.
```
make -f create_lib clean
```
### clean the `static` library and `object` files.
```
make -f create_lib clean-static
```

### clean the `shared` library and `object` files.
```
make -f create_lib clean-shared
```

### how to use the source / `.c` file directly in the code
- `note`: in `Makefile`, all lines are indented by `tab` characters not `space`.
- add the following lines in `CmakeLists.txt` file to build the final `executable`.
```
# include all library code
FILE(GLOB MyCSources private_libs/*.c)
add_executable(test_two_libs refresher/test_two_libs.c ${MyCSources})
```

### how to use the `shared` / `static` library directly in the code
- copy `template/create_mac_binary_from_lib` makefile to the directory where source file (`test_sort.c`) exists.
- specify the `source` and `lib` while building the binary using `make` utility.
```
# build the source using shared libary and run the binary
make -f create_mac_binary_from_custom_lib PROG=test LIB=sort

# build the source using static library 
make -f create_mac_binary_from_custom_lib PROG=test LIB=sort build-static

# run the source file using the static library 
make -f create_mac_binary_from_custom_lib PROG=test LIB=sort run-static

# clean / remove the binary from cmake-build-debug folder
make -f create_mac_binary_from_custom_lib PROG=test LIB=sort clean
```