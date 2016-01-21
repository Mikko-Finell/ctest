#include "libctest.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define NORMAL  "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"

int * passed = NULL;
int * failed = NULL;

void ct_init(const char * module_name) {
    assert(passed == NULL && failed == NULL);
    printf("\nRunning tests for module \"%s\"\n", module_name);
    passed = malloc(sizeof(int));
    failed = malloc(sizeof(int));
    *passed = 0;
    *failed = 0;
}

void ct_report(const char * test_name, int status) {
    if (status < 0 || status > 1) {
        printf("Invalid report argument for test \"%s\"\n", test_name);
        exit(1);
    }

    if (status == 1) {
        printf(" [%sPASSED", GREEN);
        (*passed)++;
    } else {
        printf(" [%sFAILED", RED);
        (*failed)++;
    }
    printf("%s] %s\n", NORMAL, test_name);
}

void ct_print_stats(void) {
    int nf = (double)*failed;
    int np = (double)*passed;
    int tot = nf + np;

    if (tot == 0) {
        printf("No tests yet...\n");
    } else {
        double rate = 0;
        if (nf == 0) {
            rate = 100;
        } else if (np > 0) {
            rate = 100 * (double)np / (double)(nf + np);
        }
        printf("Passed: %i/%i (%.1f%%)\e\n\n", np, tot, rate);
    }
}

void ct_terminate(void) {
    free(passed);
    free(failed);
}

