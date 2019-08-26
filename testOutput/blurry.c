#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x6 = x2 * x3;
int32_t x7 = x6 * 3;
UCHAR *x93 = malloc(sizeof(UCHAR) * x7);
int32_t x9 = x3 + 4;
int32_t x10 = x9 - 1;
int32_t x11 = x10 / 4;
int32_t x14 = x2 * 4;
int32_t x15 = x14 * 3;
int32_t x23 = x2 - 1;
int32_t x26 = x3 - 1;
int32_t x4 = x3 - 4;
for(int x13=0; x13 < x11; x13++) {
uint16_t *x94 = malloc(sizeof(uint16_t) * x15);
int32_t x17 = x13 * 4;
int32_t x18 = x17 + 1;
for(int x20=x17; x20 < x18; x20++) {
int32_t x27 = MIN(x20, x26);
int32_t x28 = MAX(0, x27);
int32_t x29 = x2 * x28;
int32_t x40 = x20 - x17;
int32_t x41 = x2 * x40;
for(int x22=0; x22 < x2; x22++) {
int32_t x24 = MIN(x22, x23);
int32_t x25 = MAX(0, x24);
int32_t x30 = x25 + x29;
int32_t x31 = 3 * x30;
int32_t x32 = x31 + 2;
UCHAR x33 = x0[x32];
uint16_t x37 = (uint16_t) x33;
int32_t x42 = x22 + x41;
int32_t x43 = 3 * x42;
int32_t x44 = x43 + 2;
x94[x44] = x37;
int32_t x34 = x31 + 1;
UCHAR x35 = x0[x34];
uint16_t x38 = (uint16_t) x35;
int32_t x46 = x43 + 1;
x94[x46] = x38;
UCHAR x36 = x0[x31];
uint16_t x39 = (uint16_t) x36;
x94[x43] = x39;

}

}
bool x56 = x17 > x4;
int32_t x57;
if (x56) {
x57 = x4;
} else {
x57 = x17;
}
for(int x54=0; x54 < 4; x54++) {
int32_t x58 = x57 + x54;
int32_t x59 = x58 - x17;
int32_t x62 = MIN(x59, 3);
int32_t x63 = MAX(0, x62);
int32_t x64 = x2 * x63;
int32_t x75 = x2 * x58;
for(int x55=0; x55 < x2; x55++) {
int32_t x60 = MIN(x55, x23);
int32_t x61 = MAX(0, x60);
int32_t x65 = x61 + x64;
int32_t x66 = 3 * x65;
int32_t x67 = x66 + 2;
uint16_t x102 = x94[x67];
int32_t x69 = x66 + 1;
uint16_t x103 = x94[x69];
uint16_t x104 = x94[x66];
int32_t x76 = x55 + x75;
int32_t x77 = 3 * x76;
int32_t x78 = x77 + 2;
UCHAR x105 = (UCHAR) x102;
x93[x78] = x105;
int32_t x80 = x77 + 1;
UCHAR x107 = (UCHAR) x103;
x93[x80] = x107;
UCHAR x109 = (UCHAR) x104;
x93[x77] = x109;

}

}
free(x94);

}
memcpy(x1, x93, x7);
free(x93);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
