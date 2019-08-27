#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
int32_t *x107 = malloc(sizeof(int32_t) * x9);
int32_t x4 = x2 - 1;
int32_t x5 = MIN(x4, x2);
int32_t x6 = x3 - 1;
int32_t x7 = MIN(x6, x3);
int32_t x11 = x5 * x7;
int32_t x12 = x11 * 3;
UCHAR *x108 = malloc(sizeof(UCHAR) * x12);
for(int x15=0; x15 < x7; x15++) {
int32_t x16 = x15 + 1;
int32_t x17 = x16 + 1;
for(int x19=x15; x19 < x17; x19++) {
int32_t x23 = x2 * x19;
for(int x21=0; x21 < x2; x21++) {
int32_t x22 = x21 + x19;
int32_t x24 = x21 + x23;
int32_t x25 = 3 * x24;
int32_t x26 = x25 + 2;
x107[x26] = x22;
int32_t x28 = x25 + 1;
x107[x28] = x22;
x107[x25] = x22;

}

}
int32_t x39 = MIN(x15, x6);
int32_t x40 = MAX(0, x39);
int32_t x41 = x2 * x40;
int32_t x49 = MIN(x16, x6);
int32_t x50 = MAX(0, x49);
int32_t x51 = x2 * x50;
int32_t x91 = x5 * x15;
for(int x36=0; x36 < x5; x36++) {
int32_t x37 = MIN(x36, x4);
int32_t x38 = MAX(0, x37);
int32_t x42 = x38 + x41;
int32_t x43 = 3 * x42;
int32_t x44 = x43 + 2;
int32_t x116 = x107[x44];
int32_t x46 = x43 + 1;
int32_t x117 = x107[x46];
int32_t x118 = x107[x43];
int32_t x52 = x38 + x51;
int32_t x53 = 3 * x52;
int32_t x54 = x53 + 2;
int32_t x119 = x107[x54];
int32_t x56 = x53 + 1;
int32_t x120 = x107[x56];
int32_t x121 = x107[x53];
int32_t x62 = x36 + 1;
int32_t x63 = MIN(x62, x4);
int32_t x64 = MAX(0, x63);
int32_t x65 = x64 + x41;
int32_t x66 = 3 * x65;
int32_t x67 = x66 + 2;
int32_t x122 = x107[x67];
int32_t x69 = x66 + 1;
int32_t x123 = x107[x69];
int32_t x124 = x107[x66];
int32_t x75 = x64 + x51;
int32_t x76 = 3 * x75;
int32_t x77 = x76 + 2;
int32_t x125 = x107[x77];
int32_t x79 = x76 + 1;
int32_t x126 = x107[x79];
int32_t x127 = x107[x76];
int32_t x92 = x36 + x91;
int32_t x93 = 3 * x92;
int32_t x94 = x93 + 2;
int32_t x128 = x116 + x119;
int32_t x129 = x128 + x122;
int32_t x130 = x129 + x125;
int32_t x131 = x130 / 4;
UCHAR x132 = (UCHAR) x131;
x108[x94] = x132;
int32_t x96 = x93 + 1;
int32_t x134 = x117 + x120;
int32_t x135 = x134 + x123;
int32_t x136 = x135 + x126;
int32_t x137 = x136 / 4;
UCHAR x138 = (UCHAR) x137;
x108[x96] = x138;
int32_t x140 = x118 + x121;
int32_t x141 = x140 + x124;
int32_t x142 = x141 + x127;
int32_t x143 = x142 / 4;
UCHAR x144 = (UCHAR) x143;
x108[x93] = x144;

}

}
free(x107);
memcpy(x1, x108, x12);
free(x108);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
