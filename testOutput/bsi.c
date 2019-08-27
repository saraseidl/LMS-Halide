#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x6 = x2 * x3;
int32_t x7 = x6 * 3;
UCHAR *x90 = malloc(sizeof(UCHAR) * x7);
int32_t x9 = x3 + 4;
int32_t x10 = x9 - 1;
int32_t x11 = x10 / 4;
int32_t x16 = x2 * 4;
int32_t x17 = x16 * 3;
int32_t x4 = x3 - 4;
int32_t x30 = x2 - 1;
int32_t x33 = x3 - 1;
for(int x13=0; x13 < x11; x13++) {
int32_t x19 = x13 * 4;
bool x20 = x19 > x4;
int32_t x21;
if (x20) {
x21 = x4;
} else {
x21 = x19;
}
for(int x15=0; x15 < 4; x15++) {
uint16_t *x91 = malloc(sizeof(uint16_t) * x17);
int32_t x22 = x21 + x15;
int32_t x23 = x22 + 4;
int32_t x24 = x23 - 1;
int32_t x25 = x24 + 1;
for(int x27=x22; x27 < x25; x27++) {
int32_t x34 = MIN(x27, x33);
int32_t x35 = MAX(0, x34);
int32_t x36 = x2 * x35;
int32_t x47 = x27 - x22;
int32_t x48 = x2 * x47;
for(int x29=0; x29 < x2; x29++) {
int32_t x31 = MIN(x29, x30);
int32_t x32 = MAX(0, x31);
int32_t x37 = x32 + x36;
int32_t x38 = 3 * x37;
int32_t x39 = x38 + 2;
UCHAR x40 = x0[x39];
uint16_t x44 = (uint16_t) x40;
int32_t x49 = x29 + x48;
int32_t x50 = 3 * x49;
int32_t x51 = x50 + 2;
x91[x51] = x44;
int32_t x41 = x38 + 1;
UCHAR x42 = x0[x41];
uint16_t x45 = (uint16_t) x42;
int32_t x53 = x50 + 1;
x91[x53] = x45;
UCHAR x43 = x0[x38];
uint16_t x46 = (uint16_t) x43;
x91[x50] = x46;

}

}
int32_t x72 = x2 * x22;
for(int x60=0; x60 < x2; x60++) {
int32_t x61 = MIN(x60, x30);
int32_t x62 = MAX(0, x61);
int32_t x63 = 3 * x62;
int32_t x64 = x63 + 2;
uint16_t x99 = x91[x64];
int32_t x66 = x63 + 1;
uint16_t x100 = x91[x66];
uint16_t x101 = x91[x63];
int32_t x73 = x60 + x72;
int32_t x74 = 3 * x73;
int32_t x75 = x74 + 2;
UCHAR x102 = (UCHAR) x99;
x90[x75] = x102;
int32_t x77 = x74 + 1;
UCHAR x104 = (UCHAR) x100;
x90[x77] = x104;
UCHAR x106 = (UCHAR) x101;
x90[x74] = x106;

}
free(x91);

}

}
memcpy(x1, x90, x7);
free(x90);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
