#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x5 = x3 - 1;
int32_t x7 = x5 - 1;
int32_t x8 = x6 * x7;
int32_t x9 = x8 * 3;
UCHAR x10[x9];
int32_t x11 = 1 + x6;
int32_t x12 = x7 * x6;
int32_t x13 = x4 + x12;
for(int x15=x11; x15 < x13; x15++) {
int32_t x16 = x15 % x6;
int32_t x18 = x15 - 1;
int32_t x19 = x18 / x6;
int32_t x46 = x19 - 1;
int32_t x143 = x6 * x46;
int32_t x144 = x16 + x143;
int32_t x145 = 3 * x144;
int32_t x146 = x145 + 2;
int32_t x17 = x16 + 1;
int32_t x20 = x2 * x19;
int32_t x21 = x17 + x20;
int32_t x22 = 3 * x21;
int32_t x23 = x22 + 2;
UCHAR x24 = x0[x23];
int32_t x25 = (int) x24;
int32_t x31 = x19 + 1;
int32_t x32 = x2 * x31;
int32_t x33 = x17 + x32;
int32_t x34 = 3 * x33;
int32_t x35 = x34 + 2;
UCHAR x36 = x0[x35];
int32_t x37 = (int) x36;
int32_t x43 = x25 + x37;
int32_t x47 = x2 * x46;
int32_t x48 = x17 + x47;
int32_t x49 = 3 * x48;
int32_t x50 = x49 + 2;
UCHAR x51 = x0[x50];
int32_t x52 = (int) x51;
int32_t x58 = x43 + x52;
int32_t x61 = x16 + x47;
int32_t x62 = 3 * x61;
int32_t x63 = x62 + 2;
UCHAR x64 = x0[x63];
int32_t x65 = (int) x64;
int32_t x71 = x58 + x65;
int32_t x74 = x16 + x20;
int32_t x75 = 3 * x74;
int32_t x76 = x75 + 2;
UCHAR x77 = x0[x76];
int32_t x78 = (int) x77;
int32_t x84 = x71 + x78;
int32_t x87 = x16 + x32;
int32_t x88 = 3 * x87;
int32_t x89 = x88 + 2;
UCHAR x90 = x0[x89];
int32_t x91 = (int) x90;
int32_t x97 = x84 + x91;
int32_t x100 = x17 + 1;
int32_t x101 = x100 + x47;
int32_t x102 = 3 * x101;
int32_t x103 = x102 + 2;
UCHAR x104 = x0[x103];
int32_t x105 = (int) x104;
int32_t x111 = x97 + x105;
int32_t x114 = x100 + x20;
int32_t x115 = 3 * x114;
int32_t x116 = x115 + 2;
UCHAR x117 = x0[x116];
int32_t x118 = (int) x117;
int32_t x124 = x111 + x118;
int32_t x127 = x100 + x32;
int32_t x128 = 3 * x127;
int32_t x129 = x128 + 2;
UCHAR x130 = x0[x129];
int32_t x131 = (int) x130;
int32_t x137 = x124 + x131;
int32_t x140 = x137 / 9;
UCHAR x147 = x140;
x10[x146] = x147;
int32_t x149 = x145 + 1;
int32_t x26 = x22 + 1;
UCHAR x27 = x0[x26];
int32_t x28 = (int) x27;
int32_t x38 = x34 + 1;
UCHAR x39 = x0[x38];
int32_t x40 = (int) x39;
int32_t x44 = x28 + x40;
int32_t x53 = x49 + 1;
UCHAR x54 = x0[x53];
int32_t x55 = (int) x54;
int32_t x59 = x44 + x55;
int32_t x66 = x62 + 1;
UCHAR x67 = x0[x66];
int32_t x68 = (int) x67;
int32_t x72 = x59 + x68;
int32_t x79 = x75 + 1;
UCHAR x80 = x0[x79];
int32_t x81 = (int) x80;
int32_t x85 = x72 + x81;
int32_t x92 = x88 + 1;
UCHAR x93 = x0[x92];
int32_t x94 = (int) x93;
int32_t x98 = x85 + x94;
int32_t x106 = x102 + 1;
UCHAR x107 = x0[x106];
int32_t x108 = (int) x107;
int32_t x112 = x98 + x108;
int32_t x119 = x115 + 1;
UCHAR x120 = x0[x119];
int32_t x121 = (int) x120;
int32_t x125 = x112 + x121;
int32_t x132 = x128 + 1;
UCHAR x133 = x0[x132];
int32_t x134 = (int) x133;
int32_t x138 = x125 + x134;
int32_t x141 = x138 / 9;
UCHAR x150 = x141;
x10[x149] = x150;
UCHAR x29 = x0[x22];
int32_t x30 = (int) x29;
UCHAR x41 = x0[x34];
int32_t x42 = (int) x41;
int32_t x45 = x30 + x42;
UCHAR x56 = x0[x49];
int32_t x57 = (int) x56;
int32_t x60 = x45 + x57;
UCHAR x69 = x0[x62];
int32_t x70 = (int) x69;
int32_t x73 = x60 + x70;
UCHAR x82 = x0[x75];
int32_t x83 = (int) x82;
int32_t x86 = x73 + x83;
UCHAR x95 = x0[x88];
int32_t x96 = (int) x95;
int32_t x99 = x86 + x96;
UCHAR x109 = x0[x102];
int32_t x110 = (int) x109;
int32_t x113 = x99 + x110;
UCHAR x122 = x0[x115];
int32_t x123 = (int) x122;
int32_t x126 = x113 + x123;
UCHAR x135 = x0[x128];
int32_t x136 = (int) x135;
int32_t x139 = x126 + x136;
int32_t x142 = x139 / 9;
UCHAR x152 = x142;
x10[x145] = x152;

}
memcpy(x1, x10, x9);
}
#define WIDTH_OUT_DIFF (2)
#define HEIGHT_OUT_DIFF (2)
