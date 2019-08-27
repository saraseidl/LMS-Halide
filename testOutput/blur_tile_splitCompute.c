#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x9 = x5 - 1;
int32_t x12 = x6 * x9;
int32_t x13 = x12 * 3;
UCHAR *x193 = malloc(sizeof(UCHAR) * x13);
int32_t x15 = x9 + 4;
int32_t x16 = x15 - 1;
int32_t x17 = x16 / 4;
int32_t x20 = x6 * 6;
int32_t x21 = x20 * 3;
int32_t x25 = x6 + 4;
int32_t x26 = x25 - 1;
int32_t x27 = x26 / 4;
int32_t x111 = x4 - 4;
int32_t x113 = x111 - 1;
int32_t x125 = x6 - 1;
int32_t x118 = x5 - 4;
int32_t x120 = x118 - 1;
for(int x19=0; x19 < x17; x19++) {
int32_t *x194 = malloc(sizeof(int32_t) * x21);
int32_t x23 = x19 * 4;
int32_t x24 = x23 + -1;
int32_t x117 = x23 + 1;
bool x119 = x117 > x118;
int32_t x121;
if (x119) {
x121 = x120;
} else {
x121 = x23;
}
for(int x29=0; x29 < x27; x29++) {
int32_t x38 = x29 * 4;
int32_t x110 = x38 + 1;
bool x112 = x110 > x111;
int32_t x114;
if (x112) {
x114 = x113;
} else {
x114 = x38;
}
for(int x31=0; x31 < 4; x31++) {
int32_t x32 = x23 + x31;
int32_t x33 = x32 + -1;
int32_t x34 = x32 + 1;
int32_t x35 = x34 + 1;
int32_t x39 = x38 + x31;
int32_t x40 = x39 + 1;
for(int x37=x33; x37 < x35; x37++) {
int32_t x45 = MIN(x37, x5);
int32_t x46 = MAX(0, x45);
int32_t x47 = x2 * x46;
int32_t x96 = x37 - x24;
int32_t x97 = x6 * x96;
for(int x42=x39; x42 < x40; x42++) {
int32_t x43 = MIN(x42, x4);
int32_t x44 = MAX(0, x43);
int32_t x48 = x44 + x47;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
uint16_t x65 = (uint16_t) x51;
int32_t x55 = x42 + 1;
int32_t x56 = MIN(x55, x4);
int32_t x57 = MAX(0, x56);
int32_t x58 = x57 + x47;
int32_t x59 = 3 * x58;
int32_t x60 = x59 + 2;
UCHAR x61 = x0[x60];
uint16_t x68 = (uint16_t) x61;
uint16_t x71 = x65 + x68;
int32_t x74 = x42 - 1;
int32_t x75 = MIN(x74, x4);
int32_t x76 = MAX(0, x75);
int32_t x77 = x76 + x47;
int32_t x78 = 3 * x77;
int32_t x79 = x78 + 2;
UCHAR x80 = x0[x79];
uint16_t x84 = (uint16_t) x80;
uint16_t x87 = x71 + x84;
int32_t x90 = (int) x87;
int32_t x93 = x90 / 3;
int32_t x98 = x74 + x97;
int32_t x99 = 3 * x98;
int32_t x100 = x99 + 2;
x194[x100] = x93;
int32_t x52 = x49 + 1;
UCHAR x53 = x0[x52];
uint16_t x66 = (uint16_t) x53;
int32_t x62 = x59 + 1;
UCHAR x63 = x0[x62];
uint16_t x69 = (uint16_t) x63;
uint16_t x72 = x66 + x69;
int32_t x81 = x78 + 1;
UCHAR x82 = x0[x81];
uint16_t x85 = (uint16_t) x82;
uint16_t x88 = x72 + x85;
int32_t x91 = (int) x88;
int32_t x94 = x91 / 3;
int32_t x102 = x99 + 1;
x194[x102] = x94;
UCHAR x54 = x0[x49];
uint16_t x67 = (uint16_t) x54;
UCHAR x64 = x0[x59];
uint16_t x70 = (uint16_t) x64;
uint16_t x73 = x67 + x70;
UCHAR x83 = x0[x78];
uint16_t x86 = (uint16_t) x83;
uint16_t x89 = x73 + x86;
int32_t x92 = (int) x89;
int32_t x95 = x92 / 3;
x194[x99] = x95;

}

}
int32_t x122 = x121 + x31;
int32_t x123 = x122 + 1;
int32_t x124 = x123 - x24;
int32_t x128 = MIN(x124, 5);
int32_t x129 = MAX(0, x128);
int32_t x130 = x6 * x129;
int32_t x138 = x123 + 1;
int32_t x139 = x138 - x24;
int32_t x140 = MIN(x139, 5);
int32_t x141 = MAX(0, x140);
int32_t x142 = x6 * x141;
int32_t x153 = x122 - x24;
int32_t x154 = MIN(x153, 5);
int32_t x155 = MAX(0, x154);
int32_t x156 = x6 * x155;
int32_t x173 = x6 * x122;
for(int x109=0; x109 < 4; x109++) {
int32_t x115 = x114 + x109;
int32_t x126 = MIN(x115, x125);
int32_t x127 = MAX(0, x126);
int32_t x131 = x127 + x130;
int32_t x132 = 3 * x131;
int32_t x133 = x132 + 2;
int32_t x202 = x194[x133];
int32_t x135 = x132 + 1;
int32_t x203 = x194[x135];
int32_t x204 = x194[x132];
int32_t x143 = x127 + x142;
int32_t x144 = 3 * x143;
int32_t x145 = x144 + 2;
int32_t x205 = x194[x145];
int32_t x147 = x144 + 1;
int32_t x206 = x194[x147];
int32_t x207 = x194[x144];
int32_t x157 = x127 + x156;
int32_t x158 = 3 * x157;
int32_t x159 = x158 + 2;
int32_t x208 = x194[x159];
int32_t x161 = x158 + 1;
int32_t x209 = x194[x161];
int32_t x210 = x194[x158];
int32_t x174 = x115 + x173;
int32_t x175 = 3 * x174;
int32_t x176 = x175 + 2;
int32_t x211 = x202 + x205;
int32_t x212 = x211 + x208;
int32_t x213 = x212 / 3;
UCHAR x214 = (UCHAR) x213;
x193[x176] = x214;
int32_t x178 = x175 + 1;
int32_t x216 = x203 + x206;
int32_t x217 = x216 + x209;
int32_t x218 = x217 / 3;
UCHAR x219 = (UCHAR) x218;
x193[x178] = x219;
int32_t x221 = x204 + x207;
int32_t x222 = x221 + x210;
int32_t x223 = x222 / 3;
UCHAR x224 = (UCHAR) x223;
x193[x175] = x224;

}

}

}
free(x194);

}
memcpy(x1, x193, x13);
free(x193);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
