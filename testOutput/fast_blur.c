#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x6 = x4 - 1;
int32_t x9 = x6 * x3;
int32_t x10 = x9 * 3;
uint16_t *x164 = malloc(sizeof(uint16_t) * x10);
int32_t x5 = x3 - 1;
int32_t x12 = x5 * x6;
int32_t x13 = x4 + x12;
for(int x15=1; x15 < x13; x15++) {
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
uint16_t x42 = (uint16_t) x28;
int32_t x32 = x18 + 1;
int32_t x33 = MIN(x32, x4);
int32_t x34 = MAX(0, x33);
int32_t x35 = x34 + x24;
int32_t x36 = 3 * x35;
int32_t x37 = x36 + 2;
UCHAR x38 = x0[x37];
uint16_t x45 = (uint16_t) x38;
uint16_t x48 = x42 + x45;
int32_t x51 = MIN(x17, x4);
int32_t x52 = MAX(0, x51);
int32_t x53 = x52 + x24;
int32_t x54 = 3 * x53;
int32_t x55 = x54 + 2;
UCHAR x56 = x0[x55];
uint16_t x60 = (uint16_t) x56;
uint16_t x63 = x48 + x60;
uint16_t x66 = x63 / 3;
int32_t x69 = x6 * x19;
int32_t x70 = x17 + x69;
int32_t x71 = 3 * x70;
int32_t x72 = x71 + 2;
x164[x72] = x66;
int32_t x29 = x26 + 1;
UCHAR x30 = x0[x29];
uint16_t x43 = (uint16_t) x30;
int32_t x39 = x36 + 1;
UCHAR x40 = x0[x39];
uint16_t x46 = (uint16_t) x40;
uint16_t x49 = x43 + x46;
int32_t x57 = x54 + 1;
UCHAR x58 = x0[x57];
uint16_t x61 = (uint16_t) x58;
uint16_t x64 = x49 + x61;
uint16_t x67 = x64 / 3;
int32_t x74 = x71 + 1;
x164[x74] = x67;
UCHAR x31 = x0[x26];
uint16_t x44 = (uint16_t) x31;
UCHAR x41 = x0[x36];
uint16_t x47 = (uint16_t) x41;
uint16_t x50 = x44 + x47;
UCHAR x59 = x0[x54];
uint16_t x62 = (uint16_t) x59;
uint16_t x65 = x50 + x62;
uint16_t x68 = x65 / 3;
x164[x71] = x68;

}
int32_t x79 = x5 - 1;
int32_t x80 = x6 * x79;
int32_t x81 = x80 * 3;
UCHAR *x170 = malloc(sizeof(UCHAR) * x81);
int32_t x85 = x6 + 16;
int32_t x86 = x85 - 1;
int32_t x87 = x86 / 16;
int32_t x93 = x4 - 16;
int32_t x95 = x93 - 1;
int32_t x99 = x6 - 1;
__m256i x208 = _mm256_set_epi16(21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846, 21846);
__m256i x225 = _mm256_set_epi64x(0L, 0L, 0L, 0L);
for(int x84=1; x84 < x5; x84++) {
int32_t x102 = MIN(x84, x5);
int32_t x103 = MAX(0, x102);
int32_t x104 = x6 * x103;
int32_t x112 = x84 + 1;
int32_t x113 = MIN(x112, x5);
int32_t x114 = MAX(0, x113);
int32_t x115 = x6 * x114;
int32_t x126 = x84 - 1;
int32_t x127 = MIN(x126, x5);
int32_t x128 = MAX(0, x127);
int32_t x129 = x6 * x128;
int32_t x146 = x6 * x126;
for(int x89=0; x89 < x87; x89++) {
int32_t x91 = x89 * 16;
int32_t x92 = x91 + 1;
bool x94 = x92 > x93;
int32_t x96;
if (x94) {
x96 = x95;
} else {
x96 = x91;
}
int32_t x171 = MIN(x96, x99);
int32_t x172 = MAX(0, x171);
int32_t x173 = x172 + x104;
int32_t x174 = 3 * x173;
int32_t x176 = x174 + 32;
int32_t x179 = x174 + 16;
int32_t x182 = x172 + x115;
int32_t x183 = 3 * x182;
int32_t x185 = x183 + 32;
int32_t x188 = x183 + 16;
int32_t x191 = x172 + x129;
int32_t x192 = 3 * x191;
int32_t x194 = x192 + 32;
int32_t x197 = x192 + 16;
int32_t x204 = x96 + x146;
int32_t x205 = 3 * x204;
int32_t x207 = x205 + 32;
int32_t x235 = x205 + 16;
uint16_t x177 = x164[x176];
uint16_t x180 = x164[x179];
uint16_t x181 = x164[x174];
uint16_t x186 = x164[x185];
uint16_t x189 = x164[x188];
uint16_t x190 = x164[x183];
uint16_t x195 = x164[x194];
uint16_t x198 = x164[x197];
uint16_t x199 = x164[x192];
// loadu
int32_t x97 = x96 + x90;
int32_t x100 = MIN(x97, x99);
int32_t x101 = MAX(0, x100);
int32_t x105 = x101 + x104;
int32_t x106 = 3 * x105;
int32_t x210 = x106 + 32;
__m256i x211 = _mm256_loadu_si256((__m256i const *) (x164 + x210));
// loadu
int32_t x116 = x101 + x115;
int32_t x117 = 3 * x116;
int32_t x213 = x117 + 32;
__m256i x214 = _mm256_loadu_si256((__m256i const *) (x164 + x213));
// loadu
int32_t x130 = x101 + x129;
int32_t x131 = 3 * x130;
int32_t x217 = x131 + 32;
__m256i x218 = _mm256_loadu_si256((__m256i const *) (x164 + x217));
__m256i x215 = _mm256_add_epi16(x211, x214);
__m256i x219 = _mm256_add_epi16(x215, x218);
__m256i x220 = _mm256_mulhi_epi16(x219, x208);
__m256i x221 = _mm256_sub_epi16(x219, x220);
__m256i x222 = _mm256_srli_epi16(x221, 1);
__m256i x223 = _mm256_add_epi16(x220, x222);
__m256i x224 = _mm256_srli_epi16(x223, 1);
__m256i x226 = _mm256_packus_epi16(x224, x225);
__m256i x227 = _mm256_permute4x64_epi64(x226, 216);
__m128i x228 = _mm256_extracti128_si256(x227, 0);
_mm_storeu_si128((__m128i*) (x170 + x207), x228);
// loadu
int32_t x237 = x106 + 16;
__m256i x238 = _mm256_loadu_si256((__m256i const *) (x164 + x237));
// loadu
int32_t x240 = x117 + 16;
__m256i x241 = _mm256_loadu_si256((__m256i const *) (x164 + x240));
// loadu
int32_t x244 = x131 + 16;
__m256i x245 = _mm256_loadu_si256((__m256i const *) (x164 + x244));
__m256i x242 = _mm256_add_epi16(x238, x241);
__m256i x246 = _mm256_add_epi16(x242, x245);
__m256i x247 = _mm256_mulhi_epi16(x246, x208);
__m256i x248 = _mm256_sub_epi16(x246, x247);
__m256i x249 = _mm256_srli_epi16(x248, 1);
__m256i x250 = _mm256_add_epi16(x247, x249);
__m256i x251 = _mm256_srli_epi16(x250, 1);
__m256i x252 = _mm256_packus_epi16(x251, x225);
__m256i x253 = _mm256_permute4x64_epi64(x252, 216);
__m128i x254 = _mm256_extracti128_si256(x253, 0);
_mm_storeu_si128((__m128i*) (x170 + x235), x254);
// loadu
__m256i x261 = _mm256_loadu_si256((__m256i const *) (x164 + x106));
// loadu
__m256i x263 = _mm256_loadu_si256((__m256i const *) (x164 + x117));
// loadu
__m256i x266 = _mm256_loadu_si256((__m256i const *) (x164 + x131));
__m256i x264 = _mm256_add_epi16(x261, x263);
__m256i x267 = _mm256_add_epi16(x264, x266);
__m256i x268 = _mm256_mulhi_epi16(x267, x208);
__m256i x269 = _mm256_sub_epi16(x267, x268);
__m256i x270 = _mm256_srli_epi16(x269, 1);
__m256i x271 = _mm256_add_epi16(x268, x270);
__m256i x272 = _mm256_srli_epi16(x271, 1);
__m256i x273 = _mm256_packus_epi16(x272, x225);
__m256i x274 = _mm256_permute4x64_epi64(x273, 216);
__m128i x275 = _mm256_extracti128_si256(x274, 0);
_mm_storeu_si128((__m128i*) (x170 + x205), x275);

}

}
free(x164);
memcpy(x1, x170, x81);
free(x170);
}
int32_t WIDTH_OUT_DIFF = 2;
int32_t HEIGHT_OUT_DIFF = 2;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
