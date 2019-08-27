#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x7 = x6 * x3;
int32_t x8 = x7 * 3;
int32_t *x150 = malloc(sizeof(int32_t) * x8);
int32_t x5 = x3 - 1;
for(int x11=0; x11 < x3; x11++) {
int32_t x16 = MIN(x11, x5);
int32_t x17 = MAX(0, x16);
int32_t x18 = x2 * x17;
int32_t x67 = x6 * x11;
for(int x13=1; x13 < x4; x13++) {
int32_t x14 = MIN(x13, x4);
int32_t x15 = MAX(0, x14);
int32_t x19 = x15 + x18;
int32_t x20 = 3 * x19;
int32_t x21 = x20 + 2;
UCHAR x22 = x0[x21];
uint16_t x36 = (uint16_t) x22;
int32_t x26 = x13 + 1;
int32_t x27 = MIN(x26, x4);
int32_t x28 = MAX(0, x27);
int32_t x29 = x28 + x18;
int32_t x30 = 3 * x29;
int32_t x31 = x30 + 2;
UCHAR x32 = x0[x31];
uint16_t x39 = (uint16_t) x32;
uint16_t x42 = x36 + x39;
int32_t x45 = x13 - 1;
int32_t x46 = MIN(x45, x4);
int32_t x47 = MAX(0, x46);
int32_t x48 = x47 + x18;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
uint16_t x55 = (uint16_t) x51;
uint16_t x58 = x42 + x55;
int32_t x61 = (int) x58;
int32_t x64 = x61 / 3;
int32_t x68 = x45 + x67;
int32_t x69 = 3 * x68;
int32_t x70 = x69 + 2;
x150[x70] = x64;
int32_t x23 = x20 + 1;
UCHAR x24 = x0[x23];
uint16_t x37 = (uint16_t) x24;
int32_t x33 = x30 + 1;
UCHAR x34 = x0[x33];
uint16_t x40 = (uint16_t) x34;
uint16_t x43 = x37 + x40;
int32_t x52 = x49 + 1;
UCHAR x53 = x0[x52];
uint16_t x56 = (uint16_t) x53;
uint16_t x59 = x43 + x56;
int32_t x62 = (int) x59;
int32_t x65 = x62 / 3;
int32_t x72 = x69 + 1;
x150[x72] = x65;
UCHAR x25 = x0[x20];
uint16_t x38 = (uint16_t) x25;
UCHAR x35 = x0[x30];
uint16_t x41 = (uint16_t) x35;
uint16_t x44 = x38 + x41;
UCHAR x54 = x0[x49];
uint16_t x57 = (uint16_t) x54;
uint16_t x60 = x44 + x57;
int32_t x63 = (int) x60;
int32_t x66 = x63 / 3;
x150[x69] = x66;

}

}
int32_t x79 = x5 - 1;
int32_t x80 = x6 * x79;
int32_t x81 = x80 * 3;
UCHAR *x158 = malloc(sizeof(UCHAR) * x81);
int32_t x87 = x6 - 1;
for(int x84=1; x84 < x5; x84++) {
int32_t x90 = MIN(x84, x5);
int32_t x91 = MAX(0, x90);
int32_t x92 = x6 * x91;
int32_t x100 = x84 + 1;
int32_t x101 = MIN(x100, x5);
int32_t x102 = MAX(0, x101);
int32_t x103 = x6 * x102;
int32_t x114 = x84 - 1;
int32_t x115 = MIN(x114, x5);
int32_t x116 = MAX(0, x115);
int32_t x117 = x6 * x116;
int32_t x134 = x6 * x114;
for(int x85=1; x85 < x4; x85++) {
int32_t x86 = x85 - 1;
int32_t x88 = MIN(x86, x87);
int32_t x89 = MAX(0, x88);
int32_t x93 = x89 + x92;
int32_t x94 = 3 * x93;
int32_t x95 = x94 + 2;
int32_t x159 = x150[x95];
int32_t x97 = x94 + 1;
int32_t x160 = x150[x97];
int32_t x161 = x150[x94];
int32_t x104 = x89 + x103;
int32_t x105 = 3 * x104;
int32_t x106 = x105 + 2;
int32_t x162 = x150[x106];
int32_t x108 = x105 + 1;
int32_t x163 = x150[x108];
int32_t x164 = x150[x105];
int32_t x118 = x89 + x117;
int32_t x119 = 3 * x118;
int32_t x120 = x119 + 2;
int32_t x165 = x150[x120];
int32_t x122 = x119 + 1;
int32_t x166 = x150[x122];
int32_t x167 = x150[x119];
int32_t x135 = x86 + x134;
int32_t x136 = 3 * x135;
int32_t x137 = x136 + 2;
int32_t x168 = x159 + x162;
int32_t x169 = x168 + x165;
int32_t x170 = x169 / 3;
UCHAR x171 = (UCHAR) x170;
x158[x137] = x171;
int32_t x139 = x136 + 1;
int32_t x173 = x160 + x163;
int32_t x174 = x173 + x166;
int32_t x175 = x174 / 3;
UCHAR x176 = (UCHAR) x175;
x158[x139] = x176;
int32_t x178 = x161 + x164;
int32_t x179 = x178 + x167;
int32_t x180 = x179 / 3;
UCHAR x181 = (UCHAR) x180;
x158[x136] = x181;

}

}
free(x150);
memcpy(x1, x158, x81);
free(x158);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
