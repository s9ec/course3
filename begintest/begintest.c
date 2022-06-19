//
// Created by sxy on 2022/5/22.
//
#include <stdio.h>
#include <string.h>
#include "../CUnit/Basic.h"
#include "../store.h"
#include "../arithmetic.h"



static int suite_init(void)
{
    return 0;
}

static int suite_clean(void)
{
    return 0;
}

static void test_store(void)  //test "store" function
{
    CU_ASSERT_EQUAL(store("initial.txt"),1);
    CU_ASSERT_EQUAL(store("abc.txt"),1);
    CU_ASSERT_EQUAL(store("abc.txt"),1);
    CU_ASSERT_EQUAL(store("cde.txt"),1);
    CU_ASSERT_EQUAL(store("hji.txt"),1);
    CU_ASSERT_EQUAL(store("ski.txt"),1);
    CU_ASSERT_EQUAL(store("skio.txt"),1);
    CU_ASSERT_EQUAL(store("loi.txt"),1);
    CU_ASSERT_EQUAL(store("qwsi.txt"),1);


}
static void test_check(void)   //test "check" function
{
    CU_ASSERT_EQUAL(check(3),3);
    CU_ASSERT_EQUAL(check(1),0);
    CU_ASSERT_EQUAL(check(2),-1);
    CU_ASSERT_EQUAL(check(4),0);
    CU_ASSERT_EQUAL(check(5),0);
    CU_ASSERT_EQUAL(check(6),0);
    CU_ASSERT_EQUAL(check(7),0);
    CU_ASSERT_EQUAL(check(8),0);


}

static CU_TestInfo tests_store[] = {
        { "test_store", test_store },
        CU_TEST_INFO_NULL,
};
static CU_TestInfo tests_check[] = {
        { "test_check", test_check },
        CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
        { "suite_sum", suite_init, suite_clean, NULL, NULL, tests_store },
        {"suite_check", suite_init, suite_clean, NULL, NULL,  tests_check},
        CU_SUITE_INFO_NULL
};



int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    /* Register suites. */
    if (CUE_SUCCESS != CU_register_suites(suites)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}