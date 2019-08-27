#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x7 = x4 - -1;
int32_t x8 = x7 * x3;
int32_t x9 = x8 * 3;
UCHAR *x104 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 2;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 2;
int32_t x16 = x2 * 2;
int32_t x17 = x16 * 3;
int32_t x30 = x3 - 1;
int32_t x5 = x3 - 2;
for(int x15=0; x15 < x13; x15++) {
int32_t *x105 = malloc(sizeof(int32_t) * x17);
int32_t x19 = x15 * 2;
bool x62 = x19 > x5;
int32_t x63;
if (x62) {
x63 = x5;
} else {
x63 = x19;
}
for(int x21=0; x21 < 2; x21++) {
int32_t x22 = x19 + x21;
int32_t x23 = x22 + 1;
for(int x25=x22; x25 < x23; x25++) {
int32_t x31 = MIN(x25, x30);
int32_t x32 = MAX(0, x31);
int32_t x33 = x2 * x32;
int32_t x47 = x25 - x19;
int32_t x48 = x2 * x47;
for(int x27=0; x27 < x2; x27++) {
int32_t x28 = MIN(x27, x4);
int32_t x29 = MAX(0, x28);
int32_t x34 = x29 + x33;
int32_t x35 = 3 * x34;
int32_t x36 = x35 + 2;
UCHAR x37 = x0[x36];
int32_t x41 = (int32_t) x37;
int32_t x44 = x41 * 2;
int32_t x49 = x27 + x48;
int32_t x50 = 3 * x49;
int32_t x51 = x50 + 2;
x105[x51] = x44;
int32_t x38 = x35 + 1;
UCHAR x39 = x0[x38];
int32_t x42 = (int32_t) x39;
int32_t x45 = x42 * 2;
int32_t x53 = x50 + 1;
x105[x53] = x45;
UCHAR x40 = x0[x35];
int32_t x43 = (int32_t) x40;
int32_t x46 = x43 * 2;
x105[x50] = x46;

}

}
int32_t x64 = x63 + x21;
int32_t x66 = x64 - x19;
int32_t x69 = MIN(x66, 1);
int32_t x70 = MAX(0, x69);
int32_t x71 = x2 * x70;
int32_t x86 = x7 * x64;
for(int x61=-1; x61 < x4; x61++) {
int32_t x65 = x61 + 1;
int32_t x67 = MIN(x65, x4);
int32_t x68 = MAX(0, x67);
int32_t x72 = x68 + x71;
int32_t x73 = 3 * x72;
int32_t x74 = x73 + 2;
int32_t x113 = x105[x74];
int32_t x76 = x73 + 1;
int32_t x114 = x105[x76];
int32_t x115 = x105[x73];
int32_t x85 = x61 - -1;
int32_t x87 = x85 + x86;
int32_t x88 = 3 * x87;
int32_t x89 = x88 + 2;
int32_t x116 = x113 / 2;
UCHAR x117 = (UCHAR) x116;
x104[x89] = x117;
int32_t x91 = x88 + 1;
int32_t x119 = x114 / 2;
UCHAR x120 = (UCHAR) x119;
x104[x91] = x120;
int32_t x122 = x115 / 2;
UCHAR x123 = (UCHAR) x122;
x104[x88] = x123;

}

}
free(x105);

}
memcpy(x1, x104, x9);
free(x104);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
