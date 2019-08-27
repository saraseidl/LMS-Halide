#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
UCHAR *x106 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 4;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 4;
int32_t x16 = x2 + 4;
int32_t x17 = x16 - 1;
int32_t x18 = x17 / 4;
int32_t x6 = x3 - 4;
int32_t x4 = x2 - 4;
int32_t x41 = x2 - 1;
int32_t x44 = x3 - 1;
for(int x15=0; x15 < x13; x15++) {
int32_t x24 = x15 * 4;
bool x25 = x24 > x6;
int32_t x26;
if (x25) {
x26 = x6;
} else {
x26 = x24;
}
for(int x20=0; x20 < x18; x20++) {
int32_t x28 = x20 * 4;
bool x29 = x28 > x4;
int32_t x30;
if (x29) {
x30 = x4;
} else {
x30 = x28;
}
int32_t x36 = x30 + 4;
int32_t x37 = x36 - 1;
int32_t x38 = x37 + 1;
for(int x22=0; x22 < 4; x22++) {
uint16_t *x107 = malloc(sizeof(uint16_t) * 48);
int32_t x27 = x26 + x22;
int32_t x31 = x27 + 4;
int32_t x32 = x31 - 1;
int32_t x33 = x32 + 1;
for(int x35=x27; x35 < x33; x35++) {
int32_t x45 = MIN(x35, x44);
int32_t x46 = MAX(0, x45);
int32_t x47 = x2 * x46;
int32_t x59 = x35 - x27;
int32_t x60 = 4 * x59;
for(int x40=x30; x40 < x38; x40++) {
int32_t x42 = MIN(x40, x41);
int32_t x43 = MAX(0, x42);
int32_t x48 = x43 + x47;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
uint16_t x55 = (uint16_t) x51;
int32_t x58 = x40 - x30;
int32_t x61 = x58 + x60;
int32_t x62 = 3 * x61;
int32_t x63 = x62 + 2;
x107[x63] = x55;
int32_t x52 = x49 + 1;
UCHAR x53 = x0[x52];
uint16_t x56 = (uint16_t) x53;
int32_t x65 = x62 + 1;
x107[x65] = x56;
UCHAR x54 = x0[x49];
uint16_t x57 = (uint16_t) x54;
x107[x62] = x57;

}

}
int32_t x86 = x2 * x27;
for(int x72=0; x72 < 4; x72++) {
int32_t x73 = x30 + x72;
int32_t x74 = x73 - x30;
int32_t x75 = MIN(x74, 3);
int32_t x76 = MAX(0, x75);
int32_t x77 = 3 * x76;
int32_t x78 = x77 + 2;
uint16_t x115 = x107[x78];
int32_t x80 = x77 + 1;
uint16_t x116 = x107[x80];
uint16_t x117 = x107[x77];
int32_t x87 = x73 + x86;
int32_t x88 = 3 * x87;
int32_t x89 = x88 + 2;
UCHAR x118 = (UCHAR) x115;
x106[x89] = x118;
int32_t x91 = x88 + 1;
UCHAR x120 = (UCHAR) x116;
x106[x91] = x120;
UCHAR x122 = (UCHAR) x117;
x106[x88] = x122;

}
free(x107);

}

}

}
memcpy(x1, x106, x9);
free(x106);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
