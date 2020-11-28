TEST_FLD=heap
TEST_PROG=kth_largest_elements_array


PATHU = libO2/lib/Unity/src/
PATHS = TEST_FLD/
PATHT = TEST_FLD/
DEBUG_ROOT = test_build/

PATH_DEBUG = $(DEBUG_ROOT)$(TEST_PROG)/

PATHB = $(PATH_DEBUG)/unittest/
PATHD = $(PATHB)/depends/
PATHO = $(PATHB)/objs/
PATHR = $(PATHB)/results/

BUILD_PATHS = $(DEBUG_ROOT) $(PATH_DEBUG) $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)/$(TEST_PROG).c)

CLEANUP=rm -f
CLEANUP_DIR=rm -rf
MKDIR=mkdir -p
TARGET_EXTENSION=out

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -Dtest -lO2


RESULTS = $(PATHR)test_$(TEST_PROG).txt

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`

.PHONY: clean
.PHONY: test

all: test clean

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)%.o $(PATHU)unity.o
	$(LINK) -o $@ $^

$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHD)%.d:: $(PATHT)%.c
	$(DEPEND) $@ $<

$(DEBUG_ROOT):
	$(MKDIR) $(DEBUG_ROOT)

$(PATH_DEBUG):
	$(MKDIR) $(PATH_DEBUG)

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	$(CLEANUP_DIR) $(PATH_DEBUG)

clean-all:
	$(CLEANUP_DIR) $(DEBUG_ROOT)

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt

