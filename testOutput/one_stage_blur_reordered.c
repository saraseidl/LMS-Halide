#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x7 = x5 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x172 = malloc(sizeof(UCHAR) * x9);
for(int x12=1; x12 < x4; x12++) {
int32_t x15 = MIN(x12, x4);
int32_t x16 = MAX(0, x15);
int32_t x64 = x12 - 1;
int32_t x65 = MIN(x64, x4);
int32_t x66 = MAX(0, x65);
int32_t x106 = x12 + 1;
int32_t x107 = MIN(x106, x4);
int32_t x108 = MAX(0, x107);
for(int x14=1; x14 < x5; x14++) {
int32_t x17 = MIN(x14, x5);
int32_t x18 = MAX(0, x17);
int32_t x19 = x2 * x18;
int32_t x20 = x16 + x19;
int32_t x21 = 3 * x20;
int32_t x22 = x21 + 2;
UCHAR x23 = x0[x22];
uint16_t x38 = (uint16_t) x23;
int32_t x27 = x14 + 1;
int32_t x28 = MIN(x27, x5);
int32_t x29 = MAX(0, x28);
int32_t x30 = x2 * x29;
int32_t x31 = x16 + x30;
int32_t x32 = 3 * x31;
int32_t x33 = x32 + 2;
UCHAR x34 = x0[x33];
uint16_t x41 = (uint16_t) x34;
uint16_t x44 = x38 + x41;
int32_t x47 = x14 - 1;
int32_t x48 = MIN(x47, x5);
int32_t x49 = MAX(0, x48);
int32_t x50 = x2 * x49;
int32_t x51 = x16 + x50;
int32_t x52 = 3 * x51;
int32_t x53 = x52 + 2;
UCHAR x54 = x0[x53];
uint16_t x58 = (uint16_t) x54;
uint16_t x61 = x44 + x58;
int32_t x67 = x66 + x50;
int32_t x68 = 3 * x67;
int32_t x69 = x68 + 2;
UCHAR x70 = x0[x69];
uint16_t x74 = (uint16_t) x70;
uint16_t x77 = x61 + x74;
int32_t x80 = x66 + x19;
int32_t x81 = 3 * x80;
int32_t x82 = x81 + 2;
UCHAR x83 = x0[x82];
uint16_t x87 = (uint16_t) x83;
uint16_t x90 = x77 + x87;
int32_t x93 = x66 + x30;
int32_t x94 = 3 * x93;
int32_t x95 = x94 + 2;
UCHAR x96 = x0[x95];
uint16_t x100 = (uint16_t) x96;
uint16_t x103 = x90 + x100;
int32_t x109 = x108 + x50;
int32_t x110 = 3 * x109;
int32_t x111 = x110 + 2;
UCHAR x112 = x0[x111];
uint16_t x116 = (uint16_t) x112;
uint16_t x119 = x103 + x116;
int32_t x122 = x108 + x19;
int32_t x123 = 3 * x122;
int32_t x124 = x123 + 2;
UCHAR x125 = x0[x124];
uint16_t x129 = (uint16_t) x125;
uint16_t x132 = x119 + x129;
int32_t x135 = x108 + x30;
int32_t x136 = 3 * x135;
int32_t x137 = x136 + 2;
UCHAR x138 = x0[x137];
uint16_t x142 = (uint16_t) x138;
uint16_t x145 = x132 + x142;
int32_t x148 = (int) x145;
int32_t x151 = x148 / 9;
UCHAR x154 = (UCHAR) x151;
int32_t x157 = x6 * x47;
int32_t x158 = x64 + x157;
int32_t x159 = 3 * x158;
int32_t x160 = x159 + 2;
x172[x160] = x154;
int32_t x24 = x21 + 1;
UCHAR x25 = x0[x24];
uint16_t x39 = (uint16_t) x25;
int32_t x35 = x32 + 1;
UCHAR x36 = x0[x35];
uint16_t x42 = (uint16_t) x36;
uint16_t x45 = x39 + x42;
int32_t x55 = x52 + 1;
UCHAR x56 = x0[x55];
uint16_t x59 = (uint16_t) x56;
uint16_t x62 = x45 + x59;
int32_t x71 = x68 + 1;
UCHAR x72 = x0[x71];
uint16_t x75 = (uint16_t) x72;
uint16_t x78 = x62 + x75;
int32_t x84 = x81 + 1;
UCHAR x85 = x0[x84];
uint16_t x88 = (uint16_t) x85;
uint16_t x91 = x78 + x88;
int32_t x97 = x94 + 1;
UCHAR x98 = x0[x97];
uint16_t x101 = (uint16_t) x98;
uint16_t x104 = x91 + x101;
int32_t x113 = x110 + 1;
UCHAR x114 = x0[x113];
uint16_t x117 = (uint16_t) x114;
uint16_t x120 = x104 + x117;
int32_t x126 = x123 + 1;
UCHAR x127 = x0[x126];
uint16_t x130 = (uint16_t) x127;
uint16_t x133 = x120 + x130;
int32_t x139 = x136 + 1;
UCHAR x140 = x0[x139];
uint16_t x143 = (uint16_t) x140;
uint16_t x146 = x133 + x143;
int32_t x149 = (int) x146;
int32_t x152 = x149 / 9;
UCHAR x155 = (UCHAR) x152;
int32_t x162 = x159 + 1;
x172[x162] = x155;
UCHAR x26 = x0[x21];
uint16_t x40 = (uint16_t) x26;
UCHAR x37 = x0[x32];
uint16_t x43 = (uint16_t) x37;
uint16_t x46 = x40 + x43;
UCHAR x57 = x0[x52];
uint16_t x60 = (uint16_t) x57;
uint16_t x63 = x46 + x60;
UCHAR x73 = x0[x68];
uint16_t x76 = (uint16_t) x73;
uint16_t x79 = x63 + x76;
UCHAR x86 = x0[x81];
uint16_t x89 = (uint16_t) x86;
uint16_t x92 = x79 + x89;
UCHAR x99 = x0[x94];
uint16_t x102 = (uint16_t) x99;
uint16_t x105 = x92 + x102;
UCHAR x115 = x0[x110];
uint16_t x118 = (uint16_t) x115;
uint16_t x121 = x105 + x118;
UCHAR x128 = x0[x123];
uint16_t x131 = (uint16_t) x128;
uint16_t x134 = x121 + x131;
UCHAR x141 = x0[x136];
uint16_t x144 = (uint16_t) x141;
uint16_t x147 = x134 + x144;
int32_t x150 = (int) x147;
int32_t x153 = x150 / 9;
UCHAR x156 = (UCHAR) x153;
x172[x159] = x156;

}

}
memcpy(x1, x172, x9);
free(x172);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
