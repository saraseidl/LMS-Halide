#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
UCHAR *x105 = malloc(sizeof(UCHAR) * x9);
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
uint16_t *x106 = malloc(sizeof(uint16_t) * 3);
int32_t x27 = x26 + x22;
int32_t x31 = x27 + 4;
int32_t x32 = x31 - 1;
int32_t x33 = x32 + 1;
for(int x35=x27; x35 < x33; x35++) {
int32_t x45 = MIN(x35, x44);
int32_t x46 = MAX(0, x45);
int32_t x47 = x2 * x46;
int32_t x59 = x35 - x27;
for(int x40=x30; x40 < x38; x40++) {
int32_t x42 = MIN(x40, x41);
int32_t x43 = MAX(0, x42);
int32_t x48 = x43 + x47;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
uint16_t x55 = (uint16_t) x51;
int32_t x58 = x40 - x30;
int32_t x60 = x58 + x59;
int32_t x61 = 3 * x60;
int32_t x62 = x61 + 2;
x106[x62] = x55;
int32_t x52 = x49 + 1;
UCHAR x53 = x0[x52];
uint16_t x56 = (uint16_t) x53;
int32_t x64 = x61 + 1;
x106[x64] = x56;
UCHAR x54 = x0[x49];
uint16_t x57 = (uint16_t) x54;
x106[x61] = x57;

}

}
int32_t x85 = x2 * x27;
for(int x71=0; x71 < 4; x71++) {
int32_t x72 = x30 + x71;
int32_t x73 = x72 - x30;
int32_t x74 = MIN(x73, 0);
int32_t x75 = MAX(0, x74);
int32_t x76 = 3 * x75;
int32_t x77 = x76 + 2;
uint16_t x114 = x106[x77];
int32_t x79 = x76 + 1;
uint16_t x115 = x106[x79];
uint16_t x116 = x106[x76];
int32_t x86 = x72 + x85;
int32_t x87 = 3 * x86;
int32_t x88 = x87 + 2;
UCHAR x117 = (UCHAR) x114;
x105[x88] = x117;
int32_t x90 = x87 + 1;
UCHAR x119 = (UCHAR) x115;
x105[x90] = x119;
UCHAR x121 = (UCHAR) x116;
x105[x87] = x121;

}
free(x106);

}

}

}
memcpy(x1, x105, x9);
free(x105);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
