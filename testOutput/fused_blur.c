#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x7 = x5 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR *x174 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = 1 + x6;
int32_t x12 = x7 * x6;
int32_t x13 = x4 + x12;
for(int x15=x11; x15 < x13; x15++) {
int32_t x16 = x15 - 1;
int32_t x17 = x16 % x6;
int32_t x18 = x17 + 1;
int32_t x20 = MIN(x18, x4);
int32_t x21 = MAX(0, x20);
int32_t x19 = x16 / x6;
int32_t x22 = MIN(x19, x5);
int32_t x23 = MAX(0, x22);
int32_t x24 = x2 * x23;
int32_t x25 = x21 + x24;
int32_t x26 = 3 * x25;
int32_t x27 = x26 + 2;
UCHAR x28 = x0[x27];
uint16_t x43 = (uint16_t) x28;
int32_t x32 = x19 + 1;
int32_t x33 = MIN(x32, x5);
int32_t x34 = MAX(0, x33);
int32_t x35 = x2 * x34;
int32_t x36 = x21 + x35;
int32_t x37 = 3 * x36;
int32_t x38 = x37 + 2;
UCHAR x39 = x0[x38];
uint16_t x46 = (uint16_t) x39;
uint16_t x49 = x43 + x46;
int32_t x52 = x19 - 1;
int32_t x53 = MIN(x52, x5);
int32_t x54 = MAX(0, x53);
int32_t x55 = x2 * x54;
int32_t x56 = x21 + x55;
int32_t x57 = 3 * x56;
int32_t x58 = x57 + 2;
UCHAR x59 = x0[x58];
uint16_t x63 = (uint16_t) x59;
uint16_t x66 = x49 + x63;
int32_t x69 = MIN(x17, x4);
int32_t x70 = MAX(0, x69);
int32_t x71 = x70 + x55;
int32_t x72 = 3 * x71;
int32_t x73 = x72 + 2;
UCHAR x74 = x0[x73];
uint16_t x78 = (uint16_t) x74;
uint16_t x81 = x66 + x78;
int32_t x84 = x70 + x24;
int32_t x85 = 3 * x84;
int32_t x86 = x85 + 2;
UCHAR x87 = x0[x86];
uint16_t x91 = (uint16_t) x87;
uint16_t x94 = x81 + x91;
int32_t x97 = x70 + x35;
int32_t x98 = 3 * x97;
int32_t x99 = x98 + 2;
UCHAR x100 = x0[x99];
uint16_t x104 = (uint16_t) x100;
uint16_t x107 = x94 + x104;
int32_t x110 = x18 + 1;
int32_t x111 = MIN(x110, x4);
int32_t x112 = MAX(0, x111);
int32_t x113 = x112 + x55;
int32_t x114 = 3 * x113;
int32_t x115 = x114 + 2;
UCHAR x116 = x0[x115];
uint16_t x120 = (uint16_t) x116;
uint16_t x123 = x107 + x120;
int32_t x126 = x112 + x24;
int32_t x127 = 3 * x126;
int32_t x128 = x127 + 2;
UCHAR x129 = x0[x128];
uint16_t x133 = (uint16_t) x129;
uint16_t x136 = x123 + x133;
int32_t x139 = x112 + x35;
int32_t x140 = 3 * x139;
int32_t x141 = x140 + 2;
UCHAR x142 = x0[x141];
uint16_t x146 = (uint16_t) x142;
uint16_t x149 = x136 + x146;
int32_t x152 = (int) x149;
int32_t x155 = x152 / 9;
UCHAR x158 = (UCHAR) x155;
int32_t x161 = x6 * x52;
int32_t x162 = x17 + x161;
int32_t x163 = 3 * x162;
int32_t x164 = x163 + 2;
x174[x164] = x158;
int32_t x29 = x26 + 1;
UCHAR x30 = x0[x29];
uint16_t x44 = (uint16_t) x30;
int32_t x40 = x37 + 1;
UCHAR x41 = x0[x40];
uint16_t x47 = (uint16_t) x41;
uint16_t x50 = x44 + x47;
int32_t x60 = x57 + 1;
UCHAR x61 = x0[x60];
uint16_t x64 = (uint16_t) x61;
uint16_t x67 = x50 + x64;
int32_t x75 = x72 + 1;
UCHAR x76 = x0[x75];
uint16_t x79 = (uint16_t) x76;
uint16_t x82 = x67 + x79;
int32_t x88 = x85 + 1;
UCHAR x89 = x0[x88];
uint16_t x92 = (uint16_t) x89;
uint16_t x95 = x82 + x92;
int32_t x101 = x98 + 1;
UCHAR x102 = x0[x101];
uint16_t x105 = (uint16_t) x102;
uint16_t x108 = x95 + x105;
int32_t x117 = x114 + 1;
UCHAR x118 = x0[x117];
uint16_t x121 = (uint16_t) x118;
uint16_t x124 = x108 + x121;
int32_t x130 = x127 + 1;
UCHAR x131 = x0[x130];
uint16_t x134 = (uint16_t) x131;
uint16_t x137 = x124 + x134;
int32_t x143 = x140 + 1;
UCHAR x144 = x0[x143];
uint16_t x147 = (uint16_t) x144;
uint16_t x150 = x137 + x147;
int32_t x153 = (int) x150;
int32_t x156 = x153 / 9;
UCHAR x159 = (UCHAR) x156;
int32_t x166 = x163 + 1;
x174[x166] = x159;
UCHAR x31 = x0[x26];
uint16_t x45 = (uint16_t) x31;
UCHAR x42 = x0[x37];
uint16_t x48 = (uint16_t) x42;
uint16_t x51 = x45 + x48;
UCHAR x62 = x0[x57];
uint16_t x65 = (uint16_t) x62;
uint16_t x68 = x51 + x65;
UCHAR x77 = x0[x72];
uint16_t x80 = (uint16_t) x77;
uint16_t x83 = x68 + x80;
UCHAR x90 = x0[x85];
uint16_t x93 = (uint16_t) x90;
uint16_t x96 = x83 + x93;
UCHAR x103 = x0[x98];
uint16_t x106 = (uint16_t) x103;
uint16_t x109 = x96 + x106;
UCHAR x119 = x0[x114];
uint16_t x122 = (uint16_t) x119;
uint16_t x125 = x109 + x122;
UCHAR x132 = x0[x127];
uint16_t x135 = (uint16_t) x132;
uint16_t x138 = x125 + x135;
UCHAR x145 = x0[x140];
uint16_t x148 = (uint16_t) x145;
uint16_t x151 = x138 + x148;
int32_t x154 = (int) x151;
int32_t x157 = x154 / 9;
UCHAR x160 = (UCHAR) x157;
x174[x163] = x160;

}
memcpy(x1, x174, x9);
free(x174);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
