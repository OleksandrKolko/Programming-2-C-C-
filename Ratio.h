//Header file for Rational
#ifndef Ratio_h
#define Ratio_h
#include <stdbool.h>

typedef struct Ratio {
    int num;
    unsigned dem;
}Ratio;

extern Ratio add(Ratio x, Ratio y);

extern Ratio mull(Ratio x, Ratio y);

extern bool greater(Ratio x, Ratio y);

extern void reduce(Ratio* x);

extern void output(Ratio x);

extern int input(Ratio* x);

extern int compare(Ratio x, Ratio y);

#endif //Ratio_h