#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x8 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x9 = x5 - 1;
int32_t x10 = x8 * x9;
int32_t x11 = x10 * 3;
UCHAR *x173 = malloc(sizeof(UCHAR) * x11);
int32_t x15 = x8 * 3;
int32_t x16 = x15 * 3;
int32_t x109 = x8 - 1;
for(int x14=1; x14 < x5; x14++) {
int32_t *x174 = malloc(sizeof(int32_t) * x16);
int32_t x18 = x14 + -1;
int32_t x19 = x14 + 1;
int32_t x20 = x19 + 1;
int32_t x21 = x20 - x18;
int32_t x22 = x21 + 2;
int32_t x23 = x22 - 1;
int32_t x24 = x23 / 2;
int32_t x33 = x20 - 2;
int32_t x35 = x33 - x18;
for(int x26=0; x26 < x24; x26++) {
int32_t x31 = x26 * 2;
int32_t x32 = x31 + x18;
bool x34 = x32 > x33;
int32_t x36;
if (x34) {
x36 = x35;
} else {
x36 = x31;
}
for(int x28=0; x28 < 2; x28++) {
int32_t x37 = x36 + x28;
int32_t x38 = x37 + x18;
int32_t x41 = MIN(x38, x5);
int32_t x42 = MAX(0, x41);
int32_t x43 = x2 * x42;
int32_t x92 = x8 * x37;
for(int x30=1; x30 < x4; x30++) {
int32_t x39 = MIN(x30, x4);
int32_t x40 = MAX(0, x39);
int32_t x44 = x40 + x43;
int32_t x45 = 3 * x44;
int32_t x46 = x45 + 2;
UCHAR x47 = x0[x46];
uint16_t x61 = (uint16_t) x47;
int32_t x51 = x30 + 1;
int32_t x52 = MIN(x51, x4);
int32_t x53 = MAX(0, x52);
int32_t x54 = x53 + x43;
int32_t x55 = 3 * x54;
int32_t x56 = x55 + 2;
UCHAR x57 = x0[x56];
uint16_t x64 = (uint16_t) x57;
uint16_t x67 = x61 + x64;
int32_t x70 = x30 - 1;
int32_t x71 = MIN(x70, x4);
int32_t x72 = MAX(0, x71);
int32_t x73 = x72 + x43;
int32_t x74 = 3 * x73;
int32_t x75 = x74 + 2;
UCHAR x76 = x0[x75];
uint16_t x80 = (uint16_t) x76;
uint16_t x83 = x67 + x80;
int32_t x86 = (int) x83;
int32_t x89 = x86 / 3;
int32_t x93 = x70 + x92;
int32_t x94 = 3 * x93;
int32_t x95 = x94 + 2;
x174[x95] = x89;
int32_t x48 = x45 + 1;
UCHAR x49 = x0[x48];
uint16_t x62 = (uint16_t) x49;
int32_t x58 = x55 + 1;
UCHAR x59 = x0[x58];
uint16_t x65 = (uint16_t) x59;
uint16_t x68 = x62 + x65;
int32_t x77 = x74 + 1;
UCHAR x78 = x0[x77];
uint16_t x81 = (uint16_t) x78;
uint16_t x84 = x68 + x81;
int32_t x87 = (int) x84;
int32_t x90 = x87 / 3;
int32_t x97 = x94 + 1;
x174[x97] = x90;
UCHAR x50 = x0[x45];
uint16_t x63 = (uint16_t) x50;
UCHAR x60 = x0[x55];
uint16_t x66 = (uint16_t) x60;
uint16_t x69 = x63 + x66;
UCHAR x79 = x0[x74];
uint16_t x82 = (uint16_t) x79;
uint16_t x85 = x69 + x82;
int32_t x88 = (int) x85;
int32_t x91 = x88 / 3;
x174[x94] = x91;

}

}

}
int32_t x108 = x14 - x18;
int32_t x112 = MIN(x108, 2);
int32_t x113 = MAX(0, x112);
int32_t x114 = x8 * x113;
int32_t x122 = x19 - x18;
int32_t x123 = MIN(x122, 2);
int32_t x124 = MAX(0, x123);
int32_t x125 = x8 * x124;
int32_t x136 = x14 - 1;
int32_t x137 = x136 - x18;
int32_t x138 = MIN(x137, 2);
int32_t x139 = MAX(0, x138);
int32_t x140 = x8 * x139;
int32_t x157 = x8 * x136;
for(int x106=1; x106 < x4; x106++) {
int32_t x107 = x106 - 1;
int32_t x110 = MIN(x107, x109);
int32_t x111 = MAX(0, x110);
int32_t x115 = x111 + x114;
int32_t x116 = 3 * x115;
int32_t x117 = x116 + 2;
int32_t x184 = x174[x117];
int32_t x119 = x116 + 1;
int32_t x185 = x174[x119];
int32_t x186 = x174[x116];
int32_t x126 = x111 + x125;
int32_t x127 = 3 * x126;
int32_t x128 = x127 + 2;
int32_t x187 = x174[x128];
int32_t x130 = x127 + 1;
int32_t x188 = x174[x130];
int32_t x189 = x174[x127];
int32_t x141 = x111 + x140;
int32_t x142 = 3 * x141;
int32_t x143 = x142 + 2;
int32_t x190 = x174[x143];
int32_t x145 = x142 + 1;
int32_t x191 = x174[x145];
int32_t x192 = x174[x142];
int32_t x158 = x107 + x157;
int32_t x159 = 3 * x158;
int32_t x160 = x159 + 2;
int32_t x193 = x184 + x187;
int32_t x194 = x193 + x190;
int32_t x195 = x194 / 3;
UCHAR x196 = (UCHAR) x195;
x173[x160] = x196;
int32_t x162 = x159 + 1;
int32_t x198 = x185 + x188;
int32_t x199 = x198 + x191;
int32_t x200 = x199 / 3;
UCHAR x201 = (UCHAR) x200;
x173[x162] = x201;
int32_t x203 = x186 + x189;
int32_t x204 = x203 + x192;
int32_t x205 = x204 / 3;
UCHAR x206 = (UCHAR) x205;
x173[x159] = x206;

}
free(x174);

}
memcpy(x1, x173, x11);
free(x173);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
