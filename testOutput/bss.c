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
int32_t x30 = x2 - 1;
int32_t x33 = x3 - 1;
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
for(int x21=0; x21 < 4; x21++) {
int32_t x22 = x19 + x21;
int32_t x23 = x22 + 4;
int32_t x24 = x23 - 1;
int32_t x25 = x24 + 1;
for(int x27=x22; x27 < x25; x27++) {
int32_t x34 = MIN(x27, x33);
int32_t x35 = MAX(0, x34);
int32_t x36 = x2 * x35;
int32_t x47 = x27 - x19;
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
x96[x51] = x44;
int32_t x41 = x38 + 1;
UCHAR x42 = x0[x41];
uint16_t x45 = (uint16_t) x42;
int32_t x53 = x50 + 1;
x96[x53] = x45;
UCHAR x43 = x0[x38];
uint16_t x46 = (uint16_t) x43;
x96[x50] = x46;

}

}
int32_t x61 = x22 - x19;
int32_t x64 = MIN(x61, 3);
int32_t x65 = MAX(0, x64);
int32_t x66 = x2 * x65;
int32_t x77 = x2 * x22;
for(int x60=0; x60 < x2; x60++) {
int32_t x62 = MIN(x60, x30);
int32_t x63 = MAX(0, x62);
int32_t x67 = x63 + x66;
int32_t x68 = 3 * x67;
int32_t x69 = x68 + 2;
uint16_t x104 = x96[x69];
int32_t x71 = x68 + 1;
uint16_t x105 = x96[x71];
uint16_t x106 = x96[x68];
int32_t x78 = x60 + x77;
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
