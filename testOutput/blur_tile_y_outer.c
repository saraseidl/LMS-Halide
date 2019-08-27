#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
UCHAR *x108 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 4;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 4;
int32_t x16 = x2 * 4;
int32_t x17 = x16 * 3;
int32_t x6 = x3 - 4;
int32_t x29 = x2 - 1;
int32_t x32 = x3 - 1;
int32_t x59 = x2 + 4;
int32_t x60 = x59 - 1;
int32_t x61 = x60 / 4;
int32_t x4 = x2 - 4;
for(int x15=0; x15 < x13; x15++) {
uint16_t *x109 = malloc(sizeof(uint16_t) * x17);
int32_t x19 = x15 * 4;
bool x20 = x19 > x6;
int32_t x21;
if (x20) {
x21 = x6;
} else {
x21 = x19;
}
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
x109[x50] = x43;
int32_t x40 = x37 + 1;
UCHAR x41 = x0[x40];
uint16_t x44 = (uint16_t) x41;
int32_t x52 = x49 + 1;
x109[x52] = x44;
UCHAR x42 = x0[x37];
uint16_t x45 = (uint16_t) x42;
x109[x49] = x45;

}

}
for(int x63=0; x63 < x61; x63++) {
int32_t x67 = x63 * 4;
bool x68 = x67 > x4;
int32_t x69;
if (x68) {
x69 = x4;
} else {
x69 = x67;
}
for(int x65=0; x65 < 4; x65++) {
int32_t x71 = x21 + x65;
int32_t x72 = x71 - x21;
int32_t x75 = MIN(x72, 3);
int32_t x76 = MAX(0, x75);
int32_t x77 = x2 * x76;
int32_t x88 = x2 * x71;
for(int x66=0; x66 < 4; x66++) {
int32_t x70 = x69 + x66;
int32_t x73 = MIN(x70, x29);
int32_t x74 = MAX(0, x73);
int32_t x78 = x74 + x77;
int32_t x79 = 3 * x78;
int32_t x80 = x79 + 2;
uint16_t x117 = x109[x80];
int32_t x82 = x79 + 1;
uint16_t x118 = x109[x82];
uint16_t x119 = x109[x79];
int32_t x89 = x70 + x88;
int32_t x90 = 3 * x89;
int32_t x91 = x90 + 2;
UCHAR x120 = (UCHAR) x117;
x108[x91] = x120;
int32_t x93 = x90 + 1;
UCHAR x122 = (UCHAR) x118;
x108[x93] = x122;
UCHAR x124 = (UCHAR) x119;
x108[x90] = x124;

}

}

}
free(x109);

}
memcpy(x1, x108, x9);
free(x108);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
