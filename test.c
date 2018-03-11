#include <ctest.h>

int main(void) {
    ct_init("testsuit");

    ct_report("pass test", CTEST_SUCCESS);
    ct_report("fail test", CTEST_FAILURE);
    ct_report("pass test again", CTEST_SUCCESS);
    ct_report("fail again", CTEST_FAILURE);
    ct_report("pass again", CTEST_SUCCESS);
    ct_report("fail more", CTEST_FAILURE);
    ct_report("fail more", CTEST_FAILURE);
    
    ct_print_stats();
}
