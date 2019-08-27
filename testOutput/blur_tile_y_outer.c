#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x9 = x5 - 1;
int32_t x12 = x6 * x9;
int32_t x13 = x12 * 3;
UCHAR *x187 = malloc(sizeof(UCHAR) * x13);
int32_t x15 = x9 + 4;
int32_t x16 = x15 - 1;
int32_t x17 = x16 / 4;
int32_t x20 = x6 + 4;
int32_t x21 = x20 - 1;
int32_t x22 = x21 / 4;
int32_t x108 = x4 - 4;
int32_t x110 = x108 - 1;
int32_t x115 = x5 - 4;
int32_t x117 = x115 - 1;
for(int x19=0; x19 < x17; x19++) {
int32_t x28 = x19 * 4;
int32_t x114 = x28 + 1;
bool x116 = x114 > x115;
int32_t x118;
if (x116) {
x118 = x117;
} else {
x118 = x28;
}
for(int x24=0; x24 < x22; x24++) {
int32_t x31 = x24 * 4;
int32_t x107 = x31 + 1;
bool x109 = x107 > x108;
int32_t x111;
if (x109) {
x111 = x110;
} else {
x111 = x31;
}
for(int x26=0; x26 < 4; x26++) {
int32_t *x188 = malloc(sizeof(int32_t) * 9);
int32_t x29 = x28 + x26;
int32_t x30 = x29 + -1;
int32_t x33 = x29 + 1;
int32_t x34 = x33 + 1;
int32_t x32 = x31 + x26;
int32_t x37 = x32 + 1;
for(int x36=x30; x36 < x34; x36++) {
int32_t x42 = MIN(x36, x5);
int32_t x43 = MAX(0, x42);
int32_t x44 = x2 * x43;
int32_t x94 = x36 - x30;
for(int x39=x32; x39 < x37; x39++) {
int32_t x40 = MIN(x39, x4);
int32_t x41 = MAX(0, x40);
int32_t x45 = x41 + x44;
int32_t x46 = 3 * x45;
int32_t x47 = x46 + 2;
UCHAR x48 = x0[x47];
uint16_t x62 = (uint16_t) x48;
int32_t x52 = x39 + 1;
int32_t x53 = MIN(x52, x4);
int32_t x54 = MAX(0, x53);
int32_t x55 = x54 + x44;
int32_t x56 = 3 * x55;
int32_t x57 = x56 + 2;
UCHAR x58 = x0[x57];
uint16_t x65 = (uint16_t) x58;
uint16_t x68 = x62 + x65;
int32_t x71 = x39 - 1;
int32_t x72 = MIN(x71, x4);
int32_t x73 = MAX(0, x72);
int32_t x74 = x73 + x44;
int32_t x75 = 3 * x74;
int32_t x76 = x75 + 2;
UCHAR x77 = x0[x76];
uint16_t x81 = (uint16_t) x77;
uint16_t x84 = x68 + x81;
int32_t x87 = (int) x84;
int32_t x90 = x87 / 3;
int32_t x93 = x39 - x32;
int32_t x95 = x93 + x94;
int32_t x96 = 3 * x95;
int32_t x97 = x96 + 2;
x188[x97] = x90;
int32_t x49 = x46 + 1;
UCHAR x50 = x0[x49];
uint16_t x63 = (uint16_t) x50;
int32_t x59 = x56 + 1;
UCHAR x60 = x0[x59];
uint16_t x66 = (uint16_t) x60;
uint16_t x69 = x63 + x66;
int32_t x78 = x75 + 1;
UCHAR x79 = x0[x78];
uint16_t x82 = (uint16_t) x79;
uint16_t x85 = x69 + x82;
int32_t x88 = (int) x85;
int32_t x91 = x88 / 3;
int32_t x99 = x96 + 1;
x188[x99] = x91;
UCHAR x51 = x0[x46];
uint16_t x64 = (uint16_t) x51;
UCHAR x61 = x0[x56];
uint16_t x67 = (uint16_t) x61;
uint16_t x70 = x64 + x67;
UCHAR x80 = x0[x75];
uint16_t x83 = (uint16_t) x80;
uint16_t x86 = x70 + x83;
int32_t x89 = (int) x86;
int32_t x92 = x89 / 3;
x188[x96] = x92;

}

}
int32_t x119 = x118 + x26;
int32_t x120 = x119 + 1;
int32_t x122 = x120 - x30;
int32_t x125 = MIN(x122, 2);
int32_t x126 = MAX(0, x125);
int32_t x134 = x120 + 1;
int32_t x135 = x134 - x30;
int32_t x136 = MIN(x135, 2);
int32_t x137 = MAX(0, x136);
int32_t x148 = x119 - x30;
int32_t x149 = MIN(x148, 2);
int32_t x150 = MAX(0, x149);
int32_t x167 = x6 * x119;
for(int x106=0; x106 < 4; x106++) {
int32_t x112 = x111 + x106;
int32_t x113 = x112 + 1;
int32_t x121 = x113 - x32;
int32_t x123 = MIN(x121, 0);
int32_t x124 = MAX(0, x123);
int32_t x127 = x124 + x126;
int32_t x128 = 3 * x127;
int32_t x129 = x128 + 2;
int32_t x196 = x188[x129];
int32_t x131 = x128 + 1;
int32_t x197 = x188[x131];
int32_t x198 = x188[x128];
int32_t x138 = x124 + x137;
int32_t x139 = 3 * x138;
int32_t x140 = x139 + 2;
int32_t x199 = x188[x140];
int32_t x142 = x139 + 1;
int32_t x200 = x188[x142];
int32_t x201 = x188[x139];
int32_t x151 = x124 + x150;
int32_t x152 = 3 * x151;
int32_t x153 = x152 + 2;
int32_t x202 = x188[x153];
int32_t x155 = x152 + 1;
int32_t x203 = x188[x155];
int32_t x204 = x188[x152];
int32_t x168 = x112 + x167;
int32_t x169 = 3 * x168;
int32_t x170 = x169 + 2;
int32_t x205 = x196 + x199;
int32_t x206 = x205 + x202;
int32_t x207 = x206 / 3;
UCHAR x208 = (UCHAR) x207;
x187[x170] = x208;
int32_t x172 = x169 + 1;
int32_t x210 = x197 + x200;
int32_t x211 = x210 + x203;
int32_t x212 = x211 / 3;
UCHAR x213 = (UCHAR) x212;
x187[x172] = x213;
int32_t x215 = x198 + x201;
int32_t x216 = x215 + x204;
int32_t x217 = x216 / 3;
UCHAR x218 = (UCHAR) x217;
x187[x169] = x218;

}
free(x188);

}

}

}
memcpy(x1, x187, x13);
free(x187);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
