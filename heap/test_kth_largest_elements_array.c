/*
 * author: greyshell
 * description: unittest case
 *
 * run the test:
 * export the test function - kth_largest_elements_array() inside unittest/testlib.h
 * navigate to the unittest/ directory
 * make test FLD=heap TEST_PROG=kth_largest_elements_array
 * */

#include <string.h>
#include "../libO2/lib/Unity/src/unity.h"
#include "../unittest/testlib.h"

// create the data structure

void setUp(void) {
    // initialize the data structure
}

void tearDown(void) {
    // delete the data structure
}

void test_kth_largest_elements_array_case_1(void) {
    int test_arr[8] = {10, 20, 30, 50, 90, 70, 80, 40};
    int exp_arr[3] = {70, 80, 90};
    int out_arr[3] = {0};

    kth_largest_elements_array(test_arr, 8, 3, out_arr);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, 3);
}

void test_kth_largest_elements_array_case_2(void) {
    int test_arr[5] = {5, 2, 4, 1, 3};
    int exp_arr[2] = {4, 5};
    int out_arr[3] = {0};

    kth_largest_elements_array(test_arr, 5, 2, out_arr);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, 2);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_kth_largest_elements_array_case_1);
    RUN_TEST(test_kth_largest_elements_array_case_2);

    return UNITY_END();
}