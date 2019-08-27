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
int32_t x100 = x21 + 1;
bool x102 = x100 > x101;
int32_t x104;
if (x102) {
x104 = x103;
} else {
x104 = x21;
}
for(int x24=0; x24 < 4; x24++) {
int32_t x25 = x21 + x24;
int32_t x26 = x25 + -1;
int32_t x27 = x25 + 1;
int32_t x28 = x27 + 1;
for(int x30=x26; x30 < x28; x30++) {
int32_t x35 = MIN(x30, x5);
int32_t x36 = MAX(0, x35);
int32_t x37 = x2 * x36;
int32_t x86 = x30 - x22;
int32_t x87 = x9 * x86;
for(int x32=1; x32 < x4; x32++) {
int32_t x33 = MIN(x32, x4);
int32_t x34 = MAX(0, x33);
int32_t x38 = x34 + x37;
int32_t x39 = 3 * x38;
int32_t x40 = x39 + 2;
UCHAR x41 = x0[x40];
uint16_t x55 = (uint16_t) x41;
int32_t x45 = x32 + 1;
int32_t x46 = MIN(x45, x4);
int32_t x47 = MAX(0, x46);
int32_t x48 = x47 + x37;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
uint16_t x58 = (uint16_t) x51;
uint16_t x61 = x55 + x58;
int32_t x64 = x32 - 1;
int32_t x65 = MIN(x64, x4);
int32_t x66 = MAX(0, x65);
int32_t x67 = x66 + x37;
int32_t x68 = 3 * x67;
int32_t x69 = x68 + 2;
UCHAR x70 = x0[x69];
uint16_t x74 = (uint16_t) x70;
uint16_t x77 = x61 + x74;
int32_t x80 = (int) x77;
int32_t x83 = x80 / 3;
int32_t x88 = x64 + x87;
int32_t x89 = 3 * x88;
int32_t x90 = x89 + 2;
x176[x90] = x83;
int32_t x42 = x39 + 1;
UCHAR x43 = x0[x42];
uint16_t x56 = (uint16_t) x43;
int32_t x52 = x49 + 1;
UCHAR x53 = x0[x52];
uint16_t x59 = (uint16_t) x53;
uint16_t x62 = x56 + x59;
int32_t x71 = x68 + 1;
UCHAR x72 = x0[x71];
uint16_t x75 = (uint16_t) x72;
uint16_t x78 = x62 + x75;
int32_t x81 = (int) x78;
int32_t x84 = x81 / 3;
int32_t x92 = x89 + 1;
x176[x92] = x84;
UCHAR x44 = x0[x39];
uint16_t x57 = (uint16_t) x44;
UCHAR x54 = x0[x49];
uint16_t x60 = (uint16_t) x54;
uint16_t x63 = x57 + x60;
UCHAR x73 = x0[x68];
uint16_t x76 = (uint16_t) x73;
uint16_t x79 = x63 + x76;
int32_t x82 = (int) x79;
int32_t x85 = x82 / 3;
x176[x89] = x85;

}

}
int32_t x105 = x104 + x24;
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
