#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x7 = x4 - -1;
int32_t x8 = x7 * x3;
int32_t x9 = x8 * 3;
UCHAR *x105 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 2;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 2;
int32_t x16 = x2 * 2;
int32_t x17 = x16 * 3;
int32_t x5 = x3 - 2;
int32_t x34 = x3 - 1;
for(int x15=0; x15 < x13; x15++) {
int32_t *x106 = malloc(sizeof(int32_t) * x17);
int32_t x19 = x15 * 2;
bool x20 = x19 > x5;
int32_t x21;
if (x20) {
x21 = x5;
} else {
x21 = x19;
}
for(int x23=0; x23 < 2; x23++) {
int32_t x24 = x21 + x23;
int32_t x25 = x24 + 2;
int32_t x26 = x25 - 1;
int32_t x27 = x26 + 1;
for(int x29=x24; x29 < x27; x29++) {
int32_t x35 = MIN(x29, x34);
int32_t x36 = MAX(0, x35);
int32_t x37 = x2 * x36;
int32_t x51 = x29 - x21;
int32_t x52 = x2 * x51;
for(int x31=0; x31 < x2; x31++) {
int32_t x32 = MIN(x31, x4);
int32_t x33 = MAX(0, x32);
int32_t x38 = x33 + x37;
int32_t x39 = 3 * x38;
int32_t x40 = x39 + 2;
UCHAR x41 = x0[x40];
int32_t x45 = (int32_t) x41;
int32_t x48 = x45 * 2;
int32_t x53 = x31 + x52;
int32_t x54 = 3 * x53;
int32_t x55 = x54 + 2;
x106[x55] = x48;
int32_t x42 = x39 + 1;
UCHAR x43 = x0[x42];
int32_t x46 = (int32_t) x43;
int32_t x49 = x46 * 2;
int32_t x57 = x54 + 1;
x106[x57] = x49;
UCHAR x44 = x0[x39];
int32_t x47 = (int32_t) x44;
int32_t x50 = x47 * 2;
x106[x54] = x50;

}

}
int32_t x67 = x24 - x21;
int32_t x70 = MIN(x67, 1);
int32_t x71 = MAX(0, x70);
int32_t x72 = x2 * x71;
int32_t x87 = x7 * x24;
for(int x65=-1; x65 < x4; x65++) {
int32_t x66 = x65 + 1;
int32_t x68 = MIN(x66, x4);
int32_t x69 = MAX(0, x68);
int32_t x73 = x69 + x72;
int32_t x74 = 3 * x73;
int32_t x75 = x74 + 2;
int32_t x114 = x106[x75];
int32_t x77 = x74 + 1;
int32_t x115 = x106[x77];
int32_t x116 = x106[x74];
int32_t x86 = x65 - -1;
int32_t x88 = x86 + x87;
int32_t x89 = 3 * x88;
int32_t x90 = x89 + 2;
int32_t x117 = x114 / 2;
UCHAR x118 = (UCHAR) x117;
x105[x90] = x118;
int32_t x92 = x89 + 1;
int32_t x120 = x115 / 2;
UCHAR x121 = (UCHAR) x120;
x105[x92] = x121;
int32_t x123 = x116 / 2;
UCHAR x124 = (UCHAR) x123;
x105[x89] = x124;

}

}
free(x106);

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
