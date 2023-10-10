#ifndef MULTIRET_H_
#define MULTIRET_H_

#include <stdarg.h>
#include <stdint.h>

#define MULTIPLE_RETURN(func_name, params, return_type, body) \
    __attribute__((naked)) void func_name params {            \
        void* _return_address;                                \
        asm volatile("pop %0" : "=r"(_return_address) : );    \
        body                                                  \
        asm volatile(                                         \
            "push %0\n\t"                                     \
            "ret"                                             \
            : : "r"(_return_address)                          \
        );                                                    \
    }

#define RETURN(value)                             \
    do {                                          \
        uint64_t _return = (uint64_t)(value);     \
        asm volatile("push %0" : : "r"(_return)); \
    } while(0)

#define _GET_RETURN(output) \
    asm volatile("pop %0" : "=r"(output) : )

#define _OUT_VARS_SIZE(out_vars) (sizeof(out_vars) / sizeof(*out_vars))

#define CALL_MULTIPLE_RETURN(func_name, params, return_type, ...) \
    do {                                                          \
        func_name params;                                         \
        return_type* out_vars[] = { __VA_ARGS__ };                \
        uint64_t temp;                                            \
        for(int i = _OUT_VARS_SIZE(out_vars); i > 0; i--) {       \
            _GET_RETURN(temp);                                    \
            *out_vars[i - 1] = (return_type)temp;                 \
        }                                                         \
    } while(0)

#endif // MULTIRET_H_