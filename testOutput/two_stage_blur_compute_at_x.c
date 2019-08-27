#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x7 = x5 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x147 = malloc(sizeof(UCHAR) * x9);
for(int x12=1; x12 < x5; x12++) {
int32_t x16 = x12 + -1;
int32_t x17 = x12 + 1;
int32_t x18 = x17 + 1;
int32_t x90 = x12 - x16;
int32_t x91 = MIN(x90, 2);
int32_t x92 = MAX(0, x91);
int32_t x93 = 3 * x92;
int32_t x94 = x93 + 2;
int32_t x96 = x93 + 1;
int32_t x99 = x17 - x16;
int32_t x100 = MIN(x99, 2);
int32_t x101 = MAX(0, x100);
int32_t x102 = 3 * x101;
int32_t x103 = x102 + 2;
int32_t x105 = x102 + 1;
int32_t x111 = x12 - 1;
int32_t x112 = x111 - x16;
int32_t x113 = MIN(x112, 2);
int32_t x114 = MAX(0, x113);
int32_t x115 = 3 * x114;
int32_t x116 = x115 + 2;
int32_t x118 = x115 + 1;
int32_t x131 = x6 * x111;
for(int x14=1; x14 < x4; x14++) {
int32_t *x148 = malloc(sizeof(int32_t) * 9);
int32_t x21 = x14 + 1;
for(int x20=x16; x20 < x18; x20++) {
int32_t x26 = MIN(x20, x5);
int32_t x27 = MAX(0, x26);
int32_t x28 = x2 * x27;
int32_t x78 = x20 - x16;
for(int x23=x14; x23 < x21; x23++) {
int32_t x24 = MIN(x23, x4);
int32_t x25 = MAX(0, x24);
int32_t x29 = x25 + x28;
int32_t x30 = 3 * x29;
int32_t x31 = x30 + 2;
UCHAR x32 = x0[x31];
uint16_t x46 = (uint16_t) x32;
int32_t x36 = x23 + 1;
int32_t x37 = MIN(x36, x4);
int32_t x38 = MAX(0, x37);
int32_t x39 = x38 + x28;
int32_t x40 = 3 * x39;
int32_t x41 = x40 + 2;
UCHAR x42 = x0[x41];
uint16_t x49 = (uint16_t) x42;
uint16_t x52 = x46 + x49;
int32_t x55 = x23 - 1;
int32_t x56 = MIN(x55, x4);
int32_t x57 = MAX(0, x56);
int32_t x58 = x57 + x28;
int32_t x59 = 3 * x58;
int32_t x60 = x59 + 2;
UCHAR x61 = x0[x60];
uint16_t x65 = (uint16_t) x61;
uint16_t x68 = x52 + x65;
int32_t x71 = (int) x68;
int32_t x74 = x71 / 3;
int32_t x77 = x23 - x14;
int32_t x79 = x77 + x78;
int32_t x80 = 3 * x79;
int32_t x81 = x80 + 2;
x148[x81] = x74;
int32_t x33 = x30 + 1;
UCHAR x34 = x0[x33];
uint16_t x47 = (uint16_t) x34;
int32_t x43 = x40 + 1;
UCHAR x44 = x0[x43];
uint16_t x50 = (uint16_t) x44;
uint16_t x53 = x47 + x50;
int32_t x62 = x59 + 1;
UCHAR x63 = x0[x62];
uint16_t x66 = (uint16_t) x63;
uint16_t x69 = x53 + x66;
int32_t x72 = (int) x69;
int32_t x75 = x72 / 3;
int32_t x83 = x80 + 1;
x148[x83] = x75;
UCHAR x35 = x0[x30];
uint16_t x48 = (uint16_t) x35;
UCHAR x45 = x0[x40];
uint16_t x51 = (uint16_t) x45;
uint16_t x54 = x48 + x51;
UCHAR x64 = x0[x59];
uint16_t x67 = (uint16_t) x64;
uint16_t x70 = x54 + x67;
int32_t x73 = (int) x70;
int32_t x76 = x73 / 3;
x148[x80] = x76;

}

}
int32_t x156 = x148[x94];
int32_t x157 = x148[x96];
int32_t x158 = x148[x93];
int32_t x159 = x148[x103];
int32_t x160 = x148[x105];
int32_t x161 = x148[x102];
int32_t x162 = x148[x116];
int32_t x163 = x148[x118];
int32_t x164 = x148[x115];
int32_t x130 = x14 - 1;
int32_t x132 = x130 + x131;
int32_t x133 = 3 * x132;
int32_t x134 = x133 + 2;
int32_t x165 = x156 + x159;
int32_t x166 = x165 + x162;
int32_t x167 = x166 / 3;
UCHAR x168 = (UCHAR) x167;
x147[x134] = x168;
int32_t x136 = x133 + 1;
int32_t x170 = x157 + x160;
int32_t x171 = x170 + x163;
int32_t x172 = x171 / 3;
UCHAR x173 = (UCHAR) x172;
x147[x136] = x173;
int32_t x175 = x158 + x161;
int32_t x176 = x175 + x164;
int32_t x177 = x176 / 3;
UCHAR x178 = (UCHAR) x177;
x147[x133] = x178;
free(x148);

}

}
memcpy(x1, x147, x9);
free(x147);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
