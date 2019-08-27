#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x5 = x2 - 1;
int32_t x6 = x5 - 1;
int32_t x4 = x3 - 1;
int32_t x7 = x4 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x147 = malloc(sizeof(UCHAR) * x9);
int32_t x13 = x2 * 3;
for(int x12=1; x12 < x4; x12++) {
int32_t *x148 = malloc(sizeof(int32_t) * x13);
int32_t x17 = x12 + 1;
int32_t x130 = x12 - 1;
int32_t x131 = x6 * x130;
for(int x16=1; x16 < x5; x16++) {
int32_t x20 = x16 + -1;
int32_t x21 = x16 + 1;
int32_t x22 = x21 + 1;
for(int x19=x12; x19 < x17; x19++) {
int32_t x25 = x19 - 1;
int32_t x28 = MIN(x25, x4);
int32_t x29 = MAX(0, x28);
int32_t x30 = x2 * x29;
int32_t x38 = MIN(x19, x4);
int32_t x39 = MAX(0, x38);
int32_t x40 = x2 * x39;
int32_t x57 = x19 + 1;
int32_t x58 = MIN(x57, x4);
int32_t x59 = MAX(0, x58);
int32_t x60 = x2 * x59;
int32_t x80 = x19 - x12;
int32_t x81 = x2 * x80;
for(int x24=x20; x24 < x22; x24++) {
int32_t x26 = MIN(x24, x5);
int32_t x27 = MAX(0, x26);
int32_t x31 = x27 + x30;
int32_t x32 = 3 * x31;
int32_t x33 = x32 + 2;
UCHAR x34 = x0[x33];
uint16_t x48 = (uint16_t) x34;
int32_t x41 = x27 + x40;
int32_t x42 = 3 * x41;
int32_t x43 = x42 + 2;
UCHAR x44 = x0[x43];
uint16_t x51 = (uint16_t) x44;
uint16_t x54 = x48 + x51;
int32_t x61 = x27 + x60;
int32_t x62 = 3 * x61;
int32_t x63 = x62 + 2;
UCHAR x64 = x0[x63];
uint16_t x68 = (uint16_t) x64;
uint16_t x71 = x54 + x68;
int32_t x74 = (int) x71;
int32_t x77 = x74 / 3;
int32_t x82 = x24 + x81;
int32_t x83 = 3 * x82;
int32_t x84 = x83 + 2;
x148[x84] = x77;
int32_t x35 = x32 + 1;
UCHAR x36 = x0[x35];
uint16_t x49 = (uint16_t) x36;
int32_t x45 = x42 + 1;
UCHAR x46 = x0[x45];
uint16_t x52 = (uint16_t) x46;
uint16_t x55 = x49 + x52;
int32_t x65 = x62 + 1;
UCHAR x66 = x0[x65];
uint16_t x69 = (uint16_t) x66;
uint16_t x72 = x55 + x69;
int32_t x75 = (int) x72;
int32_t x78 = x75 / 3;
int32_t x86 = x83 + 1;
x148[x86] = x78;
UCHAR x37 = x0[x32];
uint16_t x50 = (uint16_t) x37;
UCHAR x47 = x0[x42];
uint16_t x53 = (uint16_t) x47;
uint16_t x56 = x50 + x53;
UCHAR x67 = x0[x62];
uint16_t x70 = (uint16_t) x67;
uint16_t x73 = x56 + x70;
int32_t x76 = (int) x73;
int32_t x79 = x76 / 3;
x148[x83] = x79;

}

}
int32_t x93 = x16 - 1;
int32_t x94 = MIN(x93, x5);
int32_t x95 = MAX(0, x94);
int32_t x96 = 3 * x95;
int32_t x97 = x96 + 2;
int32_t x156 = x148[x97];
int32_t x99 = x96 + 1;
int32_t x157 = x148[x99];
int32_t x158 = x148[x96];
int32_t x102 = MIN(x16, x5);
int32_t x103 = MAX(0, x102);
int32_t x104 = 3 * x103;
int32_t x105 = x104 + 2;
int32_t x159 = x148[x105];
int32_t x107 = x104 + 1;
int32_t x160 = x148[x107];
int32_t x161 = x148[x104];
int32_t x113 = MIN(x21, x5);
int32_t x114 = MAX(0, x113);
int32_t x115 = 3 * x114;
int32_t x116 = x115 + 2;
int32_t x162 = x148[x116];
int32_t x118 = x115 + 1;
int32_t x163 = x148[x118];
int32_t x164 = x148[x115];
int32_t x132 = x93 + x131;
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

}
free(x148);

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
