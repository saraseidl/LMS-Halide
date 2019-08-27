#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x5 = x2 - 1;
int32_t x6 = x5 - 1;
int32_t x4 = x3 - 1;
int32_t x7 = x4 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x148 = malloc(sizeof(UCHAR) * x9);
int32_t x13 = x2 * 3;
for(int x12=1; x12 < x4; x12++) {
int32_t *x149 = malloc(sizeof(int32_t) * x13);
int32_t x131 = x12 - 1;
int32_t x132 = x6 * x131;
for(int x16=1; x16 < x5; x16++) {
int32_t x17 = x12 + x16;
int32_t x18 = x17 + 1;
int32_t x21 = x16 + -1;
int32_t x22 = x16 + 1;
int32_t x23 = x22 + 1;
for(int x20=x17; x20 < x18; x20++) {
int32_t x26 = x20 - 1;
int32_t x29 = MIN(x26, x4);
int32_t x30 = MAX(0, x29);
int32_t x31 = x2 * x30;
int32_t x39 = MIN(x20, x4);
int32_t x40 = MAX(0, x39);
int32_t x41 = x2 * x40;
int32_t x58 = x20 + 1;
int32_t x59 = MIN(x58, x4);
int32_t x60 = MAX(0, x59);
int32_t x61 = x2 * x60;
int32_t x81 = x20 - x12;
int32_t x82 = x2 * x81;
for(int x25=x21; x25 < x23; x25++) {
int32_t x27 = MIN(x25, x5);
int32_t x28 = MAX(0, x27);
int32_t x32 = x28 + x31;
int32_t x33 = 3 * x32;
int32_t x34 = x33 + 2;
UCHAR x35 = x0[x34];
uint16_t x49 = (uint16_t) x35;
int32_t x42 = x28 + x41;
int32_t x43 = 3 * x42;
int32_t x44 = x43 + 2;
UCHAR x45 = x0[x44];
uint16_t x52 = (uint16_t) x45;
uint16_t x55 = x49 + x52;
int32_t x62 = x28 + x61;
int32_t x63 = 3 * x62;
int32_t x64 = x63 + 2;
UCHAR x65 = x0[x64];
uint16_t x69 = (uint16_t) x65;
uint16_t x72 = x55 + x69;
int32_t x75 = (int) x72;
int32_t x78 = x75 / 3;
int32_t x83 = x25 + x82;
int32_t x84 = 3 * x83;
int32_t x85 = x84 + 2;
x149[x85] = x78;
int32_t x36 = x33 + 1;
UCHAR x37 = x0[x36];
uint16_t x50 = (uint16_t) x37;
int32_t x46 = x43 + 1;
UCHAR x47 = x0[x46];
uint16_t x53 = (uint16_t) x47;
uint16_t x56 = x50 + x53;
int32_t x66 = x63 + 1;
UCHAR x67 = x0[x66];
uint16_t x70 = (uint16_t) x67;
uint16_t x73 = x56 + x70;
int32_t x76 = (int) x73;
int32_t x79 = x76 / 3;
int32_t x87 = x84 + 1;
x149[x87] = x79;
UCHAR x38 = x0[x33];
uint16_t x51 = (uint16_t) x38;
UCHAR x48 = x0[x43];
uint16_t x54 = (uint16_t) x48;
uint16_t x57 = x51 + x54;
UCHAR x68 = x0[x63];
uint16_t x71 = (uint16_t) x68;
uint16_t x74 = x57 + x71;
int32_t x77 = (int) x74;
int32_t x80 = x77 / 3;
x149[x84] = x80;

}

}
int32_t x94 = x16 - 1;
int32_t x95 = MIN(x94, x5);
int32_t x96 = MAX(0, x95);
int32_t x97 = 3 * x96;
int32_t x98 = x97 + 2;
int32_t x157 = x149[x98];
int32_t x100 = x97 + 1;
int32_t x158 = x149[x100];
int32_t x159 = x149[x97];
int32_t x103 = MIN(x16, x5);
int32_t x104 = MAX(0, x103);
int32_t x105 = 3 * x104;
int32_t x106 = x105 + 2;
int32_t x160 = x149[x106];
int32_t x108 = x105 + 1;
int32_t x161 = x149[x108];
int32_t x162 = x149[x105];
int32_t x114 = MIN(x22, x5);
int32_t x115 = MAX(0, x114);
int32_t x116 = 3 * x115;
int32_t x117 = x116 + 2;
int32_t x163 = x149[x117];
int32_t x119 = x116 + 1;
int32_t x164 = x149[x119];
int32_t x165 = x149[x116];
int32_t x133 = x94 + x132;
int32_t x134 = 3 * x133;
int32_t x135 = x134 + 2;
int32_t x166 = x157 + x160;
int32_t x167 = x166 + x163;
int32_t x168 = x167 / 3;
UCHAR x169 = (UCHAR) x168;
x148[x135] = x169;
int32_t x137 = x134 + 1;
int32_t x171 = x158 + x161;
int32_t x172 = x171 + x164;
int32_t x173 = x172 / 3;
UCHAR x174 = (UCHAR) x173;
x148[x137] = x174;
int32_t x176 = x159 + x162;
int32_t x177 = x176 + x165;
int32_t x178 = x177 / 3;
UCHAR x179 = (UCHAR) x178;
x148[x134] = x179;

}
free(x149);

}
memcpy(x1, x148, x9);
free(x148);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
