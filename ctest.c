#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

#define NORMAL  "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"

static int passed;
static int failed;

void ct_init(const char * module_name) {
    printf("\nRunning tests for module \"%s\"\n", module_name);
    passed = 0;
    failed = 0;
}

void ct_report(const char * test_name, int status) {
    if (status != CTEST_SUCCESS && status != CTEST_FAILURE) {
        printf("Invalid report argument for test \"%s\"\n", test_name);
        exit(EXIT_FAILURE);
    }

    if (status == CTEST_SUCCESS) {
        printf(" [%sPASSED", GREEN);
        ++passed;
    } else {
        printf(" [%sFAILED", RED);
        ++failed;
    }
    printf("%s] %s\n", NORMAL, test_name);
}

void ct_summary(void) {
    const int tot = passed + failed;

    if (tot)
        printf("Passed: %i/%i (%.1f%%)\n\n", passed, tot,
            tot ? 100 * (double)passed / (double)tot : 100);
    else
        printf("No results recorded...\n");
}
