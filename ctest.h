#ifndef __ctest__
#define __ctest__

#define CTEST_SUCCESS 1
#define CTEST_FAILURE 0

extern void ct_init(const char * module_name);
extern void ct_report(const char * test_name, int success);
extern void ct_summary(void);

#endif
