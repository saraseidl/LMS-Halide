#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x5 = x3 - 1;
int32_t x6 = x5 - 1;
int32_t x4 = x2 - 1;
int32_t x9 = x4 - 1;
int32_t x10 = x9 * x6;
int32_t x11 = x10 * 3;
UCHAR *x175 = malloc(sizeof(UCHAR) * x11);
int32_t x13 = x6 + 4;
int32_t x14 = x13 - 1;
int32_t x15 = x14 / 4;
int32_t x18 = x9 * 6;
int32_t x19 = x18 * 3;
int32_t x109 = x9 - 1;
int32_t x101 = x5 - 4;
int32_t x103 = x101 - 1;
for(int x17=0; x17 < x15; x17++) {
int32_t *x176 = malloc(sizeof(int32_t) * x19);
int32_t x21 = x17 * 4;
int32_t x22 = x21 + -1;
int32_t x23 = x21 + 4;
int32_t x24 = x23 - 1;
int32_t x25 = x24 + 1;
int32_t x26 = x25 + 1;
for(int x28=x22; x28 < x26; x28++) {
int32_t x33 = MIN(x28, x5);
int32_t x34 = MAX(0, x33);
int32_t x35 = x2 * x34;
int32_t x84 = x28 - x22;
int32_t x85 = x9 * x84;
for(int x30=1; x30 < x4; x30++) {
int32_t x31 = MIN(x30, x4);
int32_t x32 = MAX(0, x31);
int32_t x36 = x32 + x35;
int32_t x37 = 3 * x36;
int32_t x38 = x37 + 2;
UCHAR x39 = x0[x38];
uint16_t x53 = (uint16_t) x39;
int32_t x43 = x30 + 1;
int32_t x44 = MIN(x43, x4);
int32_t x45 = MAX(0, x44);
int32_t x46 = x45 + x35;
int32_t x47 = 3 * x46;
int32_t x48 = x47 + 2;
UCHAR x49 = x0[x48];
uint16_t x56 = (uint16_t) x49;
uint16_t x59 = x53 + x56;
int32_t x62 = x30 - 1;
int32_t x63 = MIN(x62, x4);
int32_t x64 = MAX(0, x63);
int32_t x65 = x64 + x35;
int32_t x66 = 3 * x65;
int32_t x67 = x66 + 2;
UCHAR x68 = x0[x67];
uint16_t x72 = (uint16_t) x68;
uint16_t x75 = x59 + x72;
int32_t x78 = (int) x75;
int32_t x81 = x78 / 3;
int32_t x86 = x62 + x85;
int32_t x87 = 3 * x86;
int32_t x88 = x87 + 2;
x176[x88] = x81;
int32_t x40 = x37 + 1;
UCHAR x41 = x0[x40];
uint16_t x54 = (uint16_t) x41;
int32_t x50 = x47 + 1;
UCHAR x51 = x0[x50];
uint16_t x57 = (uint16_t) x51;
uint16_t x60 = x54 + x57;
int32_t x69 = x66 + 1;
UCHAR x70 = x0[x69];
uint16_t x73 = (uint16_t) x70;
uint16_t x76 = x60 + x73;
int32_t x79 = (int) x76;
int32_t x82 = x79 / 3;
int32_t x90 = x87 + 1;
x176[x90] = x82;
UCHAR x42 = x0[x37];
uint16_t x55 = (uint16_t) x42;
UCHAR x52 = x0[x47];
uint16_t x58 = (uint16_t) x52;
uint16_t x61 = x55 + x58;
UCHAR x71 = x0[x66];
uint16_t x74 = (uint16_t) x71;
uint16_t x77 = x61 + x74;
int32_t x80 = (int) x77;
int32_t x83 = x80 / 3;
x176[x87] = x83;

}

}
int32_t x100 = x21 + 1;
bool x102 = x100 > x101;
int32_t x104;
if (x102) {
x104 = x103;
} else {
x104 = x21;
}
for(int x98=0; x98 < 4; x98++) {
int32_t x105 = x104 + x98;
int32_t x106 = x105 + 1;
int32_t x108 = x106 - x22;
int32_t x112 = MIN(x108, 5);
int32_t x113 = MAX(0, x112);
int32_t x114 = x9 * x113;
int32_t x122 = x106 + 1;
int32_t x123 = x122 - x22;
int32_t x124 = MIN(x123, 5);
int32_t x125 = MAX(0, x124);
int32_t x126 = x9 * x125;
int32_t x137 = x105 - x22;
int32_t x138 = MIN(x137, 5);
int32_t x139 = MAX(0, x138);
int32_t x140 = x9 * x139;
int32_t x157 = x9 * x105;
for(int x99=1; x99 < x4; x99++) {
int32_t x107 = x99 - 1;
int32_t x110 = MIN(x107, x109);
int32_t x111 = MAX(0, x110);
int32_t x115 = x111 + x114;
int32_t x116 = 3 * x115;
int32_t x117 = x116 + 2;
int32_t x184 = x176[x117];
int32_t x119 = x116 + 1;
int32_t x185 = x176[x119];
int32_t x186 = x176[x116];
int32_t x127 = x111 + x126;
int32_t x128 = 3 * x127;
int32_t x129 = x128 + 2;
int32_t x187 = x176[x129];
int32_t x131 = x128 + 1;
int32_t x188 = x176[x131];
int32_t x189 = x176[x128];
int32_t x141 = x111 + x140;
int32_t x142 = 3 * x141;
int32_t x143 = x142 + 2;
int32_t x190 = x176[x143];
int32_t x145 = x142 + 1;
int32_t x191 = x176[x145];
int32_t x192 = x176[x142];
int32_t x158 = x107 + x157;
int32_t x159 = 3 * x158;
int32_t x160 = x159 + 2;
int32_t x193 = x184 + x187;
int32_t x194 = x193 + x190;
int32_t x195 = x194 / 3;
UCHAR x196 = (UCHAR) x195;
x175[x160] = x196;
int32_t x162 = x159 + 1;
int32_t x198 = x185 + x188;
int32_t x199 = x198 + x191;
int32_t x200 = x199 / 3;
UCHAR x201 = (UCHAR) x200;
x175[x162] = x201;
int32_t x203 = x186 + x189;
int32_t x204 = x203 + x192;
int32_t x205 = x204 / 3;
UCHAR x206 = (UCHAR) x205;
x175[x159] = x206;

}

}
free(x176);

}
memcpy(x1, x175, x11);
free(x175);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
