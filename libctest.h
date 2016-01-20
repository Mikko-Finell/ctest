#ifndef __testing__
#define __testing__

extern void ct_init(const char * module_name);

extern void ct_report(const char * test_name, int success);

extern void ct_terminate(void);

#endif
