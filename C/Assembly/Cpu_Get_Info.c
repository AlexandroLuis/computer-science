#include <stdio.h>
#include <stdint.h>
#include <cpuid.h>
#include <string.h>

int main(int argc, char **argv)
{
    int op;

    int eax;
    int ebx;
    int ecx;
    int edx;

    op = 0;

    __asm__ (
             "cpuid" : "=a" (eax),
                       "=b" (ebx),
                       "=c" (ecx),
                       "=d" (edx)
                     : "a" (op));

    char from[sizeof(int) * 3 + 1];
    strncpy(from, (const char*) &ebx, sizeof(int));
    strncpy(&from[8], (const char*) &ecx, sizeof(int));
    strncpy(&from[4], (const char*) &edx, sizeof(int));
    from[12] = '\0';

    printf("Your Cpu is %s", from);

    return 0;
}
