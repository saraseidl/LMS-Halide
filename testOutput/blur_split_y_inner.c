#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x5 = x3 - 1;
int32_t x6 = x5 - 1;
int32_t x4 = x2 - 1;
int32_t x9 = x4 - 1;
int32_t x10 = x9 * x6;
int32_t x11 = x10 * 3;
UCHAR *x174 = malloc(sizeof(UCHAR) * x11);
int32_t x13 = x6 + 4;
int32_t x14 = x13 - 1;
int32_t x15 = x14 / 4;
int32_t x20 = x9 * 3;
int32_t x21 = x20 * 3;
int32_t x108 = x9 - 1;
int32_t x100 = x5 - 4;
int32_t x102 = x100 - 1;
for(int x17=0; x17 < x15; x17++) {
int32_t x23 = x17 * 4;
int32_t x99 = x23 + 1;
bool x101 = x99 > x100;
int32_t x103;
if (x101) {
x103 = x102;
} else {
x103 = x23;
}
for(int x19=0; x19 < 4; x19++) {
int32_t *x175 = malloc(sizeof(int32_t) * x21);
int32_t x24 = x23 + x19;
int32_t x25 = x24 + -1;
int32_t x26 = x24 + 1;
int32_t x27 = x26 + 1;
for(int x29=x25; x29 < x27; x29++) {
int32_t x34 = MIN(x29, x5);
int32_t x35 = MAX(0, x34);
int32_t x36 = x2 * x35;
int32_t x85 = x29 - x25;
int32_t x86 = x9 * x85;
for(int x31=1; x31 < x4; x31++) {
int32_t x32 = MIN(x31, x4);
int32_t x33 = MAX(0, x32);
int32_t x37 = x33 + x36;
int32_t x38 = 3 * x37;
int32_t x39 = x38 + 2;
UCHAR x40 = x0[x39];
uint16_t x54 = (uint16_t) x40;
int32_t x44 = x31 + 1;
int32_t x45 = MIN(x44, x4);
int32_t x46 = MAX(0, x45);
int32_t x47 = x46 + x36;
int32_t x48 = 3 * x47;
int32_t x49 = x48 + 2;
UCHAR x50 = x0[x49];
uint16_t x57 = (uint16_t) x50;
uint16_t x60 = x54 + x57;
int32_t x63 = x31 - 1;
int32_t x64 = MIN(x63, x4);
int32_t x65 = MAX(0, x64);
int32_t x66 = x65 + x36;
int32_t x67 = 3 * x66;
int32_t x68 = x67 + 2;
UCHAR x69 = x0[x68];
uint16_t x73 = (uint16_t) x69;
uint16_t x76 = x60 + x73;
int32_t x79 = (int) x76;
int32_t x82 = x79 / 3;
int32_t x87 = x63 + x86;
int32_t x88 = 3 * x87;
int32_t x89 = x88 + 2;
x175[x89] = x82;
int32_t x41 = x38 + 1;
UCHAR x42 = x0[x41];
uint16_t x55 = (uint16_t) x42;
int32_t x51 = x48 + 1;
UCHAR x52 = x0[x51];
uint16_t x58 = (uint16_t) x52;
uint16_t x61 = x55 + x58;
int32_t x70 = x67 + 1;
UCHAR x71 = x0[x70];
uint16_t x74 = (uint16_t) x71;
uint16_t x77 = x61 + x74;
int32_t x80 = (int) x77;
int32_t x83 = x80 / 3;
int32_t x91 = x88 + 1;
x175[x91] = x83;
UCHAR x43 = x0[x38];
uint16_t x56 = (uint16_t) x43;
UCHAR x53 = x0[x48];
uint16_t x59 = (uint16_t) x53;
uint16_t x62 = x56 + x59;
UCHAR x72 = x0[x67];
uint16_t x75 = (uint16_t) x72;
uint16_t x78 = x62 + x75;
int32_t x81 = (int) x78;
int32_t x84 = x81 / 3;
x175[x88] = x84;

}

}
int32_t x104 = x103 + x19;
int32_t x105 = x104 + 1;
int32_t x107 = x105 - x25;
int32_t x111 = MIN(x107, 2);
int32_t x112 = MAX(0, x111);
int32_t x113 = x9 * x112;
int32_t x121 = x105 + 1;
int32_t x122 = x121 - x25;
int32_t x123 = MIN(x122, 2);
int32_t x124 = MAX(0, x123);
int32_t x125 = x9 * x124;
int32_t x136 = x104 - x25;
int32_t x137 = MIN(x136, 2);
int32_t x138 = MAX(0, x137);
int32_t x139 = x9 * x138;
int32_t x156 = x9 * x104;
for(int x98=1; x98 < x4; x98++) {
int32_t x106 = x98 - 1;
int32_t x109 = MIN(x106, x108);
int32_t x110 = MAX(0, x109);
int32_t x114 = x110 + x113;
int32_t x115 = 3 * x114;
int32_t x116 = x115 + 2;
int32_t x183 = x175[x116];
int32_t x118 = x115 + 1;
int32_t x184 = x175[x118];
int32_t x185 = x175[x115];
int32_t x126 = x110 + x125;
int32_t x127 = 3 * x126;
int32_t x128 = x127 + 2;
int32_t x186 = x175[x128];
int32_t x130 = x127 + 1;
int32_t x187 = x175[x130];
int32_t x188 = x175[x127];
int32_t x140 = x110 + x139;
int32_t x141 = 3 * x140;
int32_t x142 = x141 + 2;
int32_t x189 = x175[x142];
int32_t x144 = x141 + 1;
int32_t x190 = x175[x144];
int32_t x191 = x175[x141];
int32_t x157 = x106 + x156;
int32_t x158 = 3 * x157;
int32_t x159 = x158 + 2;
int32_t x192 = x183 + x186;
int32_t x193 = x192 + x189;
int32_t x194 = x193 / 3;
UCHAR x195 = (UCHAR) x194;
x174[x159] = x195;
int32_t x161 = x158 + 1;
int32_t x197 = x184 + x187;
int32_t x198 = x197 + x190;
int32_t x199 = x198 / 3;
UCHAR x200 = (UCHAR) x199;
x174[x161] = x200;
int32_t x202 = x185 + x188;
int32_t x203 = x202 + x191;
int32_t x204 = x203 / 3;
UCHAR x205 = (UCHAR) x204;
x174[x158] = x205;

}
free(x175);

}

}
memcpy(x1, x174, x11);
free(x174);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
