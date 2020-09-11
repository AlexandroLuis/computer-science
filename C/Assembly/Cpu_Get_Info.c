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

    char vendor[sizeof(int) * 3 + 1];
    strncpy(vendor, (const char*) &ebx, sizeof(int));
    strncpy(&vendor[8], (const char*) &ecx, sizeof(int));
    strncpy(&vendor[4], (const char*) &edx, sizeof(int));
    vendor[12] = '\0';

    printf("Your Cpu is %s", vendor);

    return 0;
}
