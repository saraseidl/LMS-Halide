#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
UCHAR *x111 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 4;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 4;
int32_t x16 = x2 * 4;
int32_t x17 = x16 * 3;
int32_t x22 = x2 + 4;
int32_t x23 = x22 - 1;
int32_t x24 = x23 / 4;
int32_t x6 = x3 - 4;
int32_t x4 = x2 - 4;
int32_t x43 = x2 - 1;
int32_t x46 = x3 - 1;
for(int x15=0; x15 < x13; x15++) {
uint16_t *x112 = malloc(sizeof(uint16_t) * x17);
int32_t x19 = x15 * 4;
bool x20 = x19 > x6;
int32_t x21;
if (x20) {
x21 = x6;
} else {
x21 = x19;
}
for(int x26=0; x26 < x24; x26++) {
int32_t x35 = x26 * 4;
bool x36 = x35 > x4;
int32_t x37;
if (x36) {
x37 = x4;
} else {
x37 = x35;
}
int32_t x38 = x37 + 4;
int32_t x39 = x38 - 1;
int32_t x40 = x39 + 1;
for(int x28=0; x28 < 4; x28++) {
int32_t x29 = x21 + x28;
int32_t x30 = x29 + 4;
int32_t x31 = x30 - 1;
int32_t x32 = x31 + 1;
for(int x34=x29; x34 < x32; x34++) {
int32_t x47 = MIN(x34, x46);
int32_t x48 = MAX(0, x47);
int32_t x49 = x2 * x48;
int32_t x60 = x34 - x21;
int32_t x61 = x2 * x60;
for(int x42=x37; x42 < x40; x42++) {
int32_t x44 = MIN(x42, x43);
int32_t x45 = MAX(0, x44);
int32_t x50 = x45 + x49;
int32_t x51 = 3 * x50;
int32_t x52 = x51 + 2;
UCHAR x53 = x0[x52];
uint16_t x57 = (uint16_t) x53;
int32_t x62 = x42 + x61;
int32_t x63 = 3 * x62;
int32_t x64 = x63 + 2;
x112[x64] = x57;
int32_t x54 = x51 + 1;
UCHAR x55 = x0[x54];
uint16_t x58 = (uint16_t) x55;
int32_t x66 = x63 + 1;
x112[x66] = x58;
UCHAR x56 = x0[x51];
uint16_t x59 = (uint16_t) x56;
x112[x63] = x59;

}

}
int32_t x75 = x29 - x21;
int32_t x78 = MIN(x75, 3);
int32_t x79 = MAX(0, x78);
int32_t x80 = x2 * x79;
int32_t x91 = x2 * x29;
for(int x73=0; x73 < 4; x73++) {
int32_t x74 = x37 + x73;
int32_t x76 = MIN(x74, x43);
int32_t x77 = MAX(0, x76);
int32_t x81 = x77 + x80;
int32_t x82 = 3 * x81;
int32_t x83 = x82 + 2;
uint16_t x120 = x112[x83];
int32_t x85 = x82 + 1;
uint16_t x121 = x112[x85];
uint16_t x122 = x112[x82];
int32_t x92 = x74 + x91;
int32_t x93 = 3 * x92;
int32_t x94 = x93 + 2;
UCHAR x123 = (UCHAR) x120;
x111[x94] = x123;
int32_t x96 = x93 + 1;
UCHAR x125 = (UCHAR) x121;
x111[x96] = x125;
UCHAR x127 = (UCHAR) x122;
x111[x93] = x127;

}

}

}
free(x112);

}
memcpy(x1, x111, x9);
free(x111);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
