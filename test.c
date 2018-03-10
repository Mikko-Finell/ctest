#include <ctest.h>

int main(void) {
    ct_init("testsuit");

    ct_report("pass test", 1);
    ct_report("fail test", 0);
    ct_report("pass test again", 1);
    ct_report("fail again", 0);
    ct_report("pass again", 1);
    ct_report("fail more", 0);
    ct_report("fail more", 0);
    
    ct_print_stats();
    ct_terminate();
}
