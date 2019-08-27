#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 / 2;
int32_t x5 = x4 - 1;
int32_t x6 = x5 - 1;
int32_t x7 = x6 * x3;
int32_t x8 = x7 * 3;
UCHAR *x68 = malloc(sizeof(UCHAR) * x8);
int32_t x16 = x2 - 1;
int32_t x19 = x3 - 1;
for(int x11=0; x11 < x3; x11++) {
int32_t x20 = MIN(x11, x19);
int32_t x21 = MAX(0, x20);
int32_t x22 = x2 * x21;
int32_t x53 = x6 * x11;
for(int x13=1; x13 < x5; x13++) {
int32_t x14 = 2 * x13;
int32_t x15 = x14 + 1;
int32_t x17 = MIN(x15, x16);
int32_t x18 = MAX(0, x17);
int32_t x23 = x18 + x22;
int32_t x24 = 3 * x23;
int32_t x25 = x24 + 2;
UCHAR x26 = x0[x25];
uint16_t x40 = (uint16_t) x26;
int32_t x30 = x14 - 1;
int32_t x31 = MIN(x30, x16);
int32_t x32 = MAX(0, x31);
int32_t x33 = x32 + x22;
int32_t x34 = 3 * x33;
int32_t x35 = x34 + 2;
UCHAR x36 = x0[x35];
uint16_t x43 = (uint16_t) x36;
uint16_t x46 = x40 - x43;
UCHAR x49 = (UCHAR) x46;
int32_t x52 = x13 - 1;
int32_t x54 = x52 + x53;
int32_t x55 = 3 * x54;
int32_t x56 = x55 + 2;
x68[x56] = x49;
int32_t x27 = x24 + 1;
UCHAR x28 = x0[x27];
uint16_t x41 = (uint16_t) x28;
int32_t x37 = x34 + 1;
UCHAR x38 = x0[x37];
uint16_t x44 = (uint16_t) x38;
uint16_t x47 = x41 - x44;
UCHAR x50 = (UCHAR) x47;
int32_t x58 = x55 + 1;
x68[x58] = x50;
UCHAR x29 = x0[x24];
uint16_t x42 = (uint16_t) x29;
UCHAR x39 = x0[x34];
uint16_t x45 = (uint16_t) x39;
uint16_t x48 = x42 - x45;
UCHAR x51 = (UCHAR) x48;
x68[x55] = x51;

}

}
memcpy(x1, x68, x8);
free(x68);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 2;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
