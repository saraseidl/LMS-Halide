#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 * x3;
int32_t x5 = x4 * 3;
UCHAR *x40 = malloc(sizeof(UCHAR) * x5);
int32_t x11 = x2 - 1;
int32_t x14 = x3 - 1;
for(int x8=0; x8 < x3; x8++) {
int32_t x15 = MIN(x8, x14);
int32_t x16 = MAX(0, x15);
int32_t x17 = x2 * x16;
int32_t x25 = x2 * x8;
for(int x10=0; x10 < x2; x10++) {
int32_t x12 = MIN(x10, x11);
int32_t x13 = MAX(0, x12);
int32_t x18 = x13 + x17;
int32_t x19 = 3 * x18;
int32_t x20 = x19 + 2;
UCHAR x21 = x0[x20];
int32_t x26 = x10 + x25;
int32_t x27 = 3 * x26;
int32_t x28 = x27 + 2;
x40[x28] = x21;
int32_t x22 = x19 + 1;
UCHAR x23 = x0[x22];
int32_t x30 = x27 + 1;
x40[x30] = x23;
UCHAR x24 = x0[x19];
x40[x27] = x24;

}

}
memcpy(x1, x40, x5);
free(x40);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
