#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x7 = x5 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x149 = malloc(sizeof(UCHAR) * x9);
for(int x12=1; x12 < x5; x12++) {
int32_t x100 = x12 + 1;
int32_t x113 = x12 - 1;
int32_t x133 = x6 * x113;
for(int x14=1; x14 < x4; x14++) {
int32_t *x150 = malloc(sizeof(int32_t) * 9);
int32_t x16 = x12 + x14;
int32_t x17 = x16 + -1;
int32_t x18 = x16 + 1;
int32_t x19 = x18 + 1;
int32_t x22 = x14 + 1;
for(int x21=x17; x21 < x19; x21++) {
int32_t x27 = MIN(x21, x5);
int32_t x28 = MAX(0, x27);
int32_t x29 = x2 * x28;
int32_t x79 = x21 - x17;
for(int x24=x14; x24 < x22; x24++) {
int32_t x25 = MIN(x24, x4);
int32_t x26 = MAX(0, x25);
int32_t x30 = x26 + x29;
int32_t x31 = 3 * x30;
int32_t x32 = x31 + 2;
UCHAR x33 = x0[x32];
uint16_t x47 = (uint16_t) x33;
int32_t x37 = x24 + 1;
int32_t x38 = MIN(x37, x4);
int32_t x39 = MAX(0, x38);
int32_t x40 = x39 + x29;
int32_t x41 = 3 * x40;
int32_t x42 = x41 + 2;
UCHAR x43 = x0[x42];
uint16_t x50 = (uint16_t) x43;
uint16_t x53 = x47 + x50;
int32_t x56 = x24 - 1;
int32_t x57 = MIN(x56, x4);
int32_t x58 = MAX(0, x57);
int32_t x59 = x58 + x29;
int32_t x60 = 3 * x59;
int32_t x61 = x60 + 2;
UCHAR x62 = x0[x61];
uint16_t x66 = (uint16_t) x62;
uint16_t x69 = x53 + x66;
int32_t x72 = (int) x69;
int32_t x75 = x72 / 3;
int32_t x78 = x24 - x14;
int32_t x80 = x78 + x79;
int32_t x81 = 3 * x80;
int32_t x82 = x81 + 2;
x150[x82] = x75;
int32_t x34 = x31 + 1;
UCHAR x35 = x0[x34];
uint16_t x48 = (uint16_t) x35;
int32_t x44 = x41 + 1;
UCHAR x45 = x0[x44];
uint16_t x51 = (uint16_t) x45;
uint16_t x54 = x48 + x51;
int32_t x63 = x60 + 1;
UCHAR x64 = x0[x63];
uint16_t x67 = (uint16_t) x64;
uint16_t x70 = x54 + x67;
int32_t x73 = (int) x70;
int32_t x76 = x73 / 3;
int32_t x84 = x81 + 1;
x150[x84] = x76;
UCHAR x36 = x0[x31];
uint16_t x49 = (uint16_t) x36;
UCHAR x46 = x0[x41];
uint16_t x52 = (uint16_t) x46;
uint16_t x55 = x49 + x52;
UCHAR x65 = x0[x60];
uint16_t x68 = (uint16_t) x65;
uint16_t x71 = x55 + x68;
int32_t x74 = (int) x71;
int32_t x77 = x74 / 3;
x150[x81] = x77;

}

}
int32_t x91 = x12 - x17;
int32_t x92 = MIN(x91, 2);
int32_t x93 = MAX(0, x92);
int32_t x94 = 3 * x93;
int32_t x95 = x94 + 2;
int32_t x158 = x150[x95];
int32_t x97 = x94 + 1;
int32_t x159 = x150[x97];
int32_t x160 = x150[x94];
int32_t x101 = x100 - x17;
int32_t x102 = MIN(x101, 2);
int32_t x103 = MAX(0, x102);
int32_t x104 = 3 * x103;
int32_t x105 = x104 + 2;
int32_t x161 = x150[x105];
int32_t x107 = x104 + 1;
int32_t x162 = x150[x107];
int32_t x163 = x150[x104];
int32_t x114 = x113 - x17;
int32_t x115 = MIN(x114, 2);
int32_t x116 = MAX(0, x115);
int32_t x117 = 3 * x116;
int32_t x118 = x117 + 2;
int32_t x164 = x150[x118];
int32_t x120 = x117 + 1;
int32_t x165 = x150[x120];
int32_t x166 = x150[x117];
int32_t x132 = x14 - 1;
int32_t x134 = x132 + x133;
int32_t x135 = 3 * x134;
int32_t x136 = x135 + 2;
int32_t x167 = x158 + x161;
int32_t x168 = x167 + x164;
int32_t x169 = x168 / 3;
UCHAR x170 = (UCHAR) x169;
x149[x136] = x170;
int32_t x138 = x135 + 1;
int32_t x172 = x159 + x162;
int32_t x173 = x172 + x165;
int32_t x174 = x173 / 3;
UCHAR x175 = (UCHAR) x174;
x149[x138] = x175;
int32_t x177 = x160 + x163;
int32_t x178 = x177 + x166;
int32_t x179 = x178 / 3;
UCHAR x180 = (UCHAR) x179;
x149[x135] = x180;
free(x150);

}

}
memcpy(x1, x149, x9);
free(x149);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
