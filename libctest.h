#ifndef __ctest__
#define __ctest__

extern void ct_init(const char * module_name);

extern void ct_report(const char * test_name, int success);

extern void ct_print_stats(void);

extern void ct_terminate(void);

extern void ct_print_stats_and_terminate(void);

#endif
