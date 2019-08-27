#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x8 = x4 - 1;
int32_t x9 = x8 * x3;
int32_t x10 = x9 * 3;
int32_t *x170 = malloc(sizeof(int32_t) * x10);
int32_t x5 = x3 - 1;
int32_t x12 = x5 - 1;
int32_t x13 = x8 * x12;
int32_t x14 = x13 * 3;
UCHAR *x171 = malloc(sizeof(UCHAR) * x14);
int32_t x108 = x8 - 1;
for(int x17=1; x17 < x5; x17++) {
int32_t x18 = x17 + -1;
int32_t x19 = x17 + 1;
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
int32_t x92 = x8 * x38;
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
x170[x95] = x89;
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
x170[x97] = x90;
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
x170[x94] = x91;

}

}

}
int32_t x111 = MIN(x17, x5);
int32_t x112 = MAX(0, x111);
int32_t x113 = x8 * x112;
int32_t x121 = MIN(x19, x5);
int32_t x122 = MAX(0, x121);
int32_t x123 = x8 * x122;
int32_t x134 = x17 - 1;
int32_t x135 = MIN(x134, x5);
int32_t x136 = MAX(0, x135);
int32_t x137 = x8 * x136;
int32_t x154 = x8 * x134;
for(int x106=1; x106 < x4; x106++) {
int32_t x107 = x106 - 1;
int32_t x109 = MIN(x107, x108);
int32_t x110 = MAX(0, x109);
int32_t x114 = x110 + x113;
int32_t x115 = 3 * x114;
int32_t x116 = x115 + 2;
int32_t x181 = x170[x116];
int32_t x118 = x115 + 1;
int32_t x182 = x170[x118];
int32_t x183 = x170[x115];
int32_t x124 = x110 + x123;
int32_t x125 = 3 * x124;
int32_t x126 = x125 + 2;
int32_t x184 = x170[x126];
int32_t x128 = x125 + 1;
int32_t x185 = x170[x128];
int32_t x186 = x170[x125];
int32_t x138 = x110 + x137;
int32_t x139 = 3 * x138;
int32_t x140 = x139 + 2;
int32_t x187 = x170[x140];
int32_t x142 = x139 + 1;
int32_t x188 = x170[x142];
int32_t x189 = x170[x139];
int32_t x155 = x107 + x154;
int32_t x156 = 3 * x155;
int32_t x157 = x156 + 2;
int32_t x190 = x181 + x184;
int32_t x191 = x190 + x187;
int32_t x192 = x191 / 3;
UCHAR x193 = (UCHAR) x192;
x171[x157] = x193;
int32_t x159 = x156 + 1;
int32_t x195 = x182 + x185;
int32_t x196 = x195 + x188;
int32_t x197 = x196 / 3;
UCHAR x198 = (UCHAR) x197;
x171[x159] = x198;
int32_t x200 = x183 + x186;
int32_t x201 = x200 + x189;
int32_t x202 = x201 / 3;
UCHAR x203 = (UCHAR) x202;
x171[x156] = x203;

}

}
free(x170);
memcpy(x1, x171, x14);
free(x171);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
