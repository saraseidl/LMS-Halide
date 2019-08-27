#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x6 = x2 * x3;
int32_t x7 = x6 * 3;
UCHAR *x89 = malloc(sizeof(UCHAR) * x7);
int32_t x9 = x3 + 4;
int32_t x10 = x9 - 1;
int32_t x11 = x10 / 4;
int32_t x16 = x2 * 3;
int32_t x4 = x3 - 4;
int32_t x29 = x2 - 1;
int32_t x32 = x3 - 1;
for(int x13=0; x13 < x11; x13++) {
int32_t x18 = x13 * 4;
bool x19 = x18 > x4;
int32_t x20;
if (x19) {
x20 = x4;
} else {
x20 = x18;
}
for(int x15=0; x15 < 4; x15++) {
uint16_t *x90 = malloc(sizeof(uint16_t) * x16);
int32_t x21 = x20 + x15;
int32_t x22 = x21 + 4;
int32_t x23 = x22 - 1;
int32_t x24 = x23 + 1;
for(int x26=x21; x26 < x24; x26++) {
int32_t x33 = MIN(x26, x32);
int32_t x34 = MAX(0, x33);
int32_t x35 = x2 * x34;
int32_t x46 = x26 - x21;
int32_t x47 = x2 * x46;
for(int x28=0; x28 < x2; x28++) {
int32_t x30 = MIN(x28, x29);
int32_t x31 = MAX(0, x30);
int32_t x36 = x31 + x35;
int32_t x37 = 3 * x36;
int32_t x38 = x37 + 2;
UCHAR x39 = x0[x38];
uint16_t x43 = (uint16_t) x39;
int32_t x48 = x28 + x47;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
x90[x50] = x43;
int32_t x40 = x37 + 1;
UCHAR x41 = x0[x40];
uint16_t x44 = (uint16_t) x41;
int32_t x52 = x49 + 1;
x90[x52] = x44;
UCHAR x42 = x0[x37];
uint16_t x45 = (uint16_t) x42;
x90[x49] = x45;

}

}
int32_t x71 = x2 * x21;
for(int x59=0; x59 < x2; x59++) {
int32_t x60 = MIN(x59, x29);
int32_t x61 = MAX(0, x60);
int32_t x62 = 3 * x61;
int32_t x63 = x62 + 2;
uint16_t x98 = x90[x63];
int32_t x65 = x62 + 1;
uint16_t x99 = x90[x65];
uint16_t x100 = x90[x62];
int32_t x72 = x59 + x71;
int32_t x73 = 3 * x72;
int32_t x74 = x73 + 2;
UCHAR x101 = (UCHAR) x98;
x89[x74] = x101;
int32_t x76 = x73 + 1;
UCHAR x103 = (UCHAR) x99;
x89[x76] = x103;
UCHAR x105 = (UCHAR) x100;
x89[x73] = x105;

}
free(x90);

}

}
memcpy(x1, x89, x7);
free(x89);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
