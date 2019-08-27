#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x8 = x2 * x3;
int32_t x9 = x8 * 3;
uint16_t *x230 = malloc(sizeof(uint16_t) * x9);
int32_t x4 = x2 - 1;
int32_t x5 = x3 - 1;
for(int x12=0; x12 < x3; x12++) {
int32_t x17 = MIN(x12, x5);
int32_t x18 = MAX(0, x17);
int32_t x19 = x2 * x18;
int32_t x30 = x2 * x12;
for(int x14=0; x14 < x2; x14++) {
int32_t x15 = MIN(x14, x4);
int32_t x16 = MAX(0, x15);
int32_t x20 = x16 + x19;
int32_t x21 = 3 * x20;
int32_t x22 = x21 + 2;
UCHAR x23 = x0[x22];
uint16_t x27 = (uint16_t) x23;
int32_t x31 = x14 + x30;
int32_t x32 = 3 * x31;
int32_t x33 = x32 + 2;
x230[x33] = x27;
int32_t x24 = x21 + 1;
UCHAR x25 = x0[x24];
uint16_t x28 = (uint16_t) x25;
int32_t x35 = x32 + 1;
x230[x35] = x28;
UCHAR x26 = x0[x21];
uint16_t x29 = (uint16_t) x26;
x230[x32] = x29;

}

}
int32_t x42 = x4 - 1;
int32_t x43 = x5 - 1;
int32_t x44 = x42 * x43;
int32_t x45 = x44 * 3;
UCHAR *x238 = malloc(sizeof(UCHAR) * x45);
int32_t x49 = x2 * 3;
int32_t x50 = x49 * 3;
int32_t x57 = x2 + 16;
int32_t x58 = x57 - 1;
int32_t x59 = x58 / 16;
int32_t x6 = x2 - 16;
for(int x48=1; x48 < x5; x48++) {
uint16_t *x239 = malloc(sizeof(uint16_t) * x50);
int32_t x52 = x48 + -1;
int32_t x53 = x48 + 1;
int32_t x54 = x53 + 1;
for(int x56=x52; x56 < x54; x56++) {
int32_t x69 = MIN(x56, x5);
int32_t x70 = MAX(0, x69);
int32_t x71 = x2 * x70;
int32_t x82 = x56 - x52;
int32_t x83 = x2 * x82;
for(int x61=0; x61 < x59; x61++) {
int32_t x63 = x61 * 16;
bool x64 = x63 > x6;
int32_t x65;
if (x64) {
x65 = x6;
} else {
x65 = x63;
}
int32_t x240 = MIN(x65, x4);
int32_t x241 = MAX(0, x240);
int32_t x242 = x241 + x71;
int32_t x243 = 3 * x242;
int32_t x245 = x243 + 32;
int32_t x248 = x243 + 16;
int32_t x252 = x65 + x83;
int32_t x253 = 3 * x252;
int32_t x255 = x253 + 32;
int32_t x264 = x253 + 16;
uint16_t x246 = x230[x245];
uint16_t x249 = x230[x248];
uint16_t x250 = x230[x243];
// loadu
int32_t x66 = x65 + x62;
int32_t x67 = MIN(x66, x4);
int32_t x68 = MAX(0, x67);
int32_t x72 = x68 + x71;
int32_t x73 = 3 * x72;
int32_t x257 = x73 + 32;
__m256i x258 = _mm256_loadu_si256((__m256i const *) (x230 + x257));
// loadu
__m256i x260 = _mm256_add_epi16(x258, x258);
_mm256_storeu_si256((__m256i *) (x239 + x255), x260);
// loadu
int32_t x266 = x73 + 16;
__m256i x267 = _mm256_loadu_si256((__m256i const *) (x230 + x266));
// loadu
__m256i x269 = _mm256_add_epi16(x267, x267);
_mm256_storeu_si256((__m256i *) (x239 + x264), x269);
// loadu
__m256i x273 = _mm256_loadu_si256((__m256i const *) (x230 + x73));
// loadu
__m256i x275 = _mm256_add_epi16(x273, x273);
_mm256_storeu_si256((__m256i *) (x239 + x253), x275);

}

}
int32_t x99 = x48 - x52;
int32_t x102 = MIN(x99, 2);
int32_t x103 = MAX(0, x102);
int32_t x104 = x2 * x103;
int32_t x112 = x53 - x52;
int32_t x113 = MIN(x112, 2);
int32_t x114 = MAX(0, x113);
int32_t x115 = x2 * x114;
int32_t x126 = x48 - 1;
int32_t x127 = x126 - x52;
int32_t x128 = MIN(x127, 2);
int32_t x129 = MAX(0, x128);
int32_t x130 = x2 * x129;
int32_t x213 = x42 * x126;
for(int x98=1; x98 < x4; x98++) {
int32_t x100 = MIN(x98, x4);
int32_t x101 = MAX(0, x100);
int32_t x105 = x101 + x104;
int32_t x106 = 3 * x105;
int32_t x107 = x106 + 2;
uint16_t x285 = x239[x107];
int32_t x109 = x106 + 1;
uint16_t x286 = x239[x109];
uint16_t x287 = x239[x106];
int32_t x116 = x101 + x115;
int32_t x117 = 3 * x116;
int32_t x118 = x117 + 2;
uint16_t x288 = x239[x118];
int32_t x120 = x117 + 1;
uint16_t x289 = x239[x120];
uint16_t x290 = x239[x117];
int32_t x131 = x101 + x130;
int32_t x132 = 3 * x131;
int32_t x133 = x132 + 2;
uint16_t x291 = x239[x133];
int32_t x135 = x132 + 1;
uint16_t x292 = x239[x135];
uint16_t x293 = x239[x132];
int32_t x141 = x98 - 1;
int32_t x142 = MIN(x141, x4);
int32_t x143 = MAX(0, x142);
int32_t x144 = x143 + x130;
int32_t x145 = 3 * x144;
int32_t x146 = x145 + 2;
uint16_t x294 = x239[x146];
int32_t x148 = x145 + 1;
uint16_t x295 = x239[x148];
uint16_t x296 = x239[x145];
int32_t x154 = x143 + x104;
int32_t x155 = 3 * x154;
int32_t x156 = x155 + 2;
uint16_t x297 = x239[x156];
int32_t x158 = x155 + 1;
uint16_t x298 = x239[x158];
uint16_t x299 = x239[x155];
int32_t x164 = x143 + x115;
int32_t x165 = 3 * x164;
int32_t x166 = x165 + 2;
uint16_t x300 = x239[x166];
int32_t x168 = x165 + 1;
uint16_t x301 = x239[x168];
uint16_t x302 = x239[x165];
int32_t x174 = x98 + 1;
int32_t x175 = MIN(x174, x4);
int32_t x176 = MAX(0, x175);
int32_t x177 = x176 + x130;
int32_t x178 = 3 * x177;
int32_t x179 = x178 + 2;
uint16_t x303 = x239[x179];
int32_t x181 = x178 + 1;
uint16_t x304 = x239[x181];
uint16_t x305 = x239[x178];
int32_t x187 = x176 + x104;
int32_t x188 = 3 * x187;
int32_t x189 = x188 + 2;
uint16_t x306 = x239[x189];
int32_t x191 = x188 + 1;
uint16_t x307 = x239[x191];
uint16_t x308 = x239[x188];
int32_t x197 = x176 + x115;
int32_t x198 = 3 * x197;
int32_t x199 = x198 + 2;
uint16_t x309 = x239[x199];
int32_t x201 = x198 + 1;
uint16_t x310 = x239[x201];
uint16_t x311 = x239[x198];
int32_t x214 = x141 + x213;
int32_t x215 = 3 * x214;
int32_t x216 = x215 + 2;
uint16_t x312 = x285 + x288;
uint16_t x313 = x312 + x291;
uint16_t x314 = x313 + x294;
uint16_t x315 = x314 + x297;
uint16_t x316 = x315 + x300;
uint16_t x317 = x316 + x303;
uint16_t x318 = x317 + x306;
uint16_t x319 = x318 + x309;
uint16_t x320 = x319 / 18;
UCHAR x321 = (UCHAR) x320;
x238[x216] = x321;
int32_t x218 = x215 + 1;
uint16_t x323 = x286 + x289;
uint16_t x324 = x323 + x292;
uint16_t x325 = x324 + x295;
uint16_t x326 = x325 + x298;
uint16_t x327 = x326 + x301;
uint16_t x328 = x327 + x304;
uint16_t x329 = x328 + x307;
uint16_t x330 = x329 + x310;
uint16_t x331 = x330 / 18;
UCHAR x332 = (UCHAR) x331;
x238[x218] = x332;
uint16_t x334 = x287 + x290;
uint16_t x335 = x334 + x293;
uint16_t x336 = x335 + x296;
uint16_t x337 = x336 + x299;
uint16_t x338 = x337 + x302;
uint16_t x339 = x338 + x305;
uint16_t x340 = x339 + x308;
uint16_t x341 = x340 + x311;
uint16_t x342 = x341 / 18;
UCHAR x343 = (UCHAR) x342;
x238[x215] = x343;

}
free(x239);

}
free(x230);
memcpy(x1, x238, x45);
free(x238);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
