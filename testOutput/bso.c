#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x6 = x2 * x3;
int32_t x7 = x6 * 3;
UCHAR *x95 = malloc(sizeof(UCHAR) * x7);
int32_t x9 = x3 + 4;
int32_t x10 = x9 - 1;
int32_t x11 = x10 / 4;
int32_t x14 = x2 * 4;
int32_t x15 = x14 * 3;
int32_t x4 = x3 - 4;
int32_t x27 = x2 - 1;
int32_t x30 = x3 - 1;
for(int x13=0; x13 < x11; x13++) {
uint16_t *x96 = malloc(sizeof(uint16_t) * x15);
int32_t x17 = x13 * 4;
bool x18 = x17 > x4;
int32_t x19;
if (x18) {
x19 = x4;
} else {
x19 = x17;
}
int32_t x20 = x19 + 4;
int32_t x21 = x20 - 1;
int32_t x22 = x21 + 1;
for(int x24=x19; x24 < x22; x24++) {
int32_t x31 = MIN(x24, x30);
int32_t x32 = MAX(0, x31);
int32_t x33 = x2 * x32;
int32_t x44 = x24 - x19;
int32_t x45 = x2 * x44;
for(int x26=0; x26 < x2; x26++) {
int32_t x28 = MIN(x26, x27);
int32_t x29 = MAX(0, x28);
int32_t x34 = x29 + x33;
int32_t x35 = 3 * x34;
int32_t x36 = x35 + 2;
UCHAR x37 = x0[x36];
uint16_t x41 = (uint16_t) x37;
int32_t x46 = x26 + x45;
int32_t x47 = 3 * x46;
int32_t x48 = x47 + 2;
x96[x48] = x41;
int32_t x38 = x35 + 1;
UCHAR x39 = x0[x38];
uint16_t x42 = (uint16_t) x39;
int32_t x50 = x47 + 1;
x96[x50] = x42;
UCHAR x40 = x0[x35];
uint16_t x43 = (uint16_t) x40;
x96[x47] = x43;

}

}
for(int x58=0; x58 < 4; x58++) {
int32_t x60 = x19 + x58;
int32_t x61 = x60 - x19;
int32_t x64 = MIN(x61, 3);
int32_t x65 = MAX(0, x64);
int32_t x66 = x2 * x65;
int32_t x77 = x2 * x60;
for(int x59=0; x59 < x2; x59++) {
int32_t x62 = MIN(x59, x27);
int32_t x63 = MAX(0, x62);
int32_t x67 = x63 + x66;
int32_t x68 = 3 * x67;
int32_t x69 = x68 + 2;
uint16_t x104 = x96[x69];
int32_t x71 = x68 + 1;
uint16_t x105 = x96[x71];
uint16_t x106 = x96[x68];
int32_t x78 = x59 + x77;
int32_t x79 = 3 * x78;
int32_t x80 = x79 + 2;
UCHAR x107 = (UCHAR) x104;
x95[x80] = x107;
int32_t x82 = x79 + 1;
UCHAR x109 = (UCHAR) x105;
x95[x82] = x109;
UCHAR x111 = (UCHAR) x106;
x95[x79] = x111;

}

}
free(x96);

}
memcpy(x1, x95, x7);
free(x95);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
