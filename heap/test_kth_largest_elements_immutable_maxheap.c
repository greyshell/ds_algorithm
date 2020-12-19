/*
 * author: greyshell
 * description: unit_tests case
 *
 * run the test:
 * export the test function inside unit_tests/testlib.h
 * navigate to the unit_tests/ directory
 * make test FLD=folder_name TEST_PROG=program_name
 * */

#include <string.h>
#include "../libO2/lib/Unity/src/unity.h"
#include "../unit_tests/testlib.h"

// create the data structure

void setUp(void) {
    // initialize the data structure
}

void tearDown(void) {
    // delete the data structure
}

void test_kth_largest_elements_immutable_max_heap_case_1(void) {
    int test_arr[7] = {7, 17, 16, 2, 3, 15, 14};
    int exp_arr[4] = {17, 16, 15, 14};
    int out_arr[4] = {0};

    kth_largest_elements_immutable_max_heap(test_arr, 8, 3, out_arr);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, 3);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_kth_largest_elements_immutable_max_heap_case_1);

    return UNITY_END();
}
