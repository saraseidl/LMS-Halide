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
int32_t x13 = x6 * 3;
int32_t x14 = x13 * 3;
for(int x12=1; x12 < x5; x12++) {
UCHAR x15[x14];
int32_t x16 = x12 + -1;
int32_t x19 = x6 * x16;
int32_t x20 = 1 + x19;
int32_t x17 = x12 + 1;
int32_t x21 = x17 * x6;
int32_t x22 = x4 + x21;
for(int x24=x20; x24 < x22; x24++) {
int32_t x25 = x24 - 1;
int32_t x26 = x25 % x6;
int32_t x28 = x25 / x6;
int32_t x70 = x28 - x16;
int32_t x71 = x6 * x70;
int32_t x72 = x26 + x71;
int32_t x73 = 3 * x72;
int32_t x74 = x73 + 2;
int32_t x27 = x26 + 1;
int32_t x29 = x2 * x28;
int32_t x30 = x27 + x29;
int32_t x31 = 3 * x30;
int32_t x32 = x31 + 2;
UCHAR x33 = x0[x32];
int32_t x34 = (int) x33;
int32_t x40 = x27 + 1;
int32_t x41 = x40 + x29;
int32_t x42 = 3 * x41;
int32_t x43 = x42 + 2;
UCHAR x44 = x0[x43];
int32_t x45 = (int) x44;
int32_t x51 = x34 + x45;
int32_t x54 = x26 + x29;
int32_t x55 = 3 * x54;
int32_t x56 = x55 + 2;
UCHAR x57 = x0[x56];
int32_t x58 = (int) x57;
int32_t x64 = x51 + x58;
int32_t x67 = x64 / 3;
UCHAR x75 = x67;
x15[x74] = x75;
int32_t x77 = x73 + 1;
int32_t x35 = x31 + 1;
UCHAR x36 = x0[x35];
int32_t x37 = (int) x36;
int32_t x46 = x42 + 1;
UCHAR x47 = x0[x46];
int32_t x48 = (int) x47;
int32_t x52 = x37 + x48;
int32_t x59 = x55 + 1;
UCHAR x60 = x0[x59];
int32_t x61 = (int) x60;
int32_t x65 = x52 + x61;
int32_t x68 = x65 / 3;
UCHAR x78 = x68;
x15[x77] = x78;
UCHAR x38 = x0[x31];
int32_t x39 = (int) x38;
UCHAR x49 = x0[x42];
int32_t x50 = (int) x49;
int32_t x53 = x39 + x50;
UCHAR x62 = x0[x55];
int32_t x63 = (int) x62;
int32_t x66 = x53 + x63;
int32_t x69 = x66 / 3;
UCHAR x80 = x69;
x15[x73] = x80;

}
int32_t x87 = x12 - x16;
int32_t x88 = x6 * x87;
int32_t x99 = x17 - x16;
int32_t x100 = x6 * x99;
int32_t x114 = x12 - 1;
int32_t x115 = x114 - x16;
int32_t x116 = x6 * x115;
int32_t x133 = x6 * x114;
for(int x85=1; x85 < x4; x85++) {
int32_t x86 = x85 - 1;
int32_t x89 = x86 + x88;
int32_t x90 = 3 * x89;
int32_t x91 = x90 + 2;
UCHAR x92 = x15[x91];
int32_t x94 = x90 + 1;
UCHAR x95 = x15[x94];
UCHAR x97 = x15[x90];
int32_t x101 = x86 + x100;
int32_t x102 = 3 * x101;
int32_t x103 = x102 + 2;
UCHAR x104 = x15[x103];
int32_t x106 = x102 + 1;
UCHAR x107 = x15[x106];
UCHAR x109 = x15[x102];
int32_t x117 = x86 + x116;
int32_t x118 = 3 * x117;
int32_t x119 = x118 + 2;
UCHAR x120 = x15[x119];
int32_t x122 = x118 + 1;
UCHAR x123 = x15[x122];
UCHAR x125 = x15[x118];
int32_t x134 = x86 + x133;
int32_t x135 = 3 * x134;
int32_t x136 = x135 + 2;
int32_t x93 = (int) x92;
int32_t x105 = (int) x104;
int32_t x111 = x93 + x105;
int32_t x121 = (int) x120;
int32_t x127 = x111 + x121;
int32_t x130 = x127 / 3;
UCHAR x137 = x130;
x10[x136] = x137;
int32_t x139 = x135 + 1;
int32_t x96 = (int) x95;
int32_t x108 = (int) x107;
int32_t x112 = x96 + x108;
int32_t x124 = (int) x123;
int32_t x128 = x112 + x124;
int32_t x131 = x128 / 3;
UCHAR x140 = x131;
x10[x139] = x140;
int32_t x98 = (int) x97;
int32_t x110 = (int) x109;
int32_t x113 = x98 + x110;
int32_t x126 = (int) x125;
int32_t x129 = x113 + x126;
int32_t x132 = x129 / 3;
UCHAR x142 = x132;
x10[x135] = x142;

}

}
memcpy(x1, x10, x9);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
