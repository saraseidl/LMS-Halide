#include <string.h>
#include "pipeline.h"
void pipeline(UCHAR * x0, UCHAR * x1, int32_t x2, int32_t x3) {
int32_t x4 = x2 - 1;
int32_t x7 = x4 - -1;
int32_t x8 = x7 * x3;
int32_t x9 = x8 * 3;
UCHAR *x102 = malloc(sizeof(UCHAR) * x9);
int32_t x11 = x3 + 2;
int32_t x12 = x11 - 1;
int32_t x13 = x12 / 2;
int32_t x16 = x2 * 3;
int32_t x27 = x3 - 1;
int32_t x5 = x3 - 2;
for(int x15=0; x15 < x13; x15++) {
int32_t *x103 = malloc(sizeof(int32_t) * x16);
int32_t x20 = x15 + 1;
int32_t x59 = x15 * 2;
bool x60 = x59 > x5;
int32_t x61;
if (x60) {
x61 = x5;
} else {
x61 = x59;
}
for(int x19=0; x19 < 2; x19++) {
for(int x22=x15; x22 < x20; x22++) {
int32_t x28 = MIN(x22, x27);
int32_t x29 = MAX(0, x28);
int32_t x30 = x2 * x29;
int32_t x44 = x22 - x15;
int32_t x45 = x2 * x44;
for(int x24=0; x24 < x2; x24++) {
int32_t x25 = MIN(x24, x4);
int32_t x26 = MAX(0, x25);
int32_t x31 = x26 + x30;
int32_t x32 = 3 * x31;
int32_t x33 = x32 + 2;
UCHAR x34 = x0[x33];
int32_t x38 = (int32_t) x34;
int32_t x41 = x38 * 2;
int32_t x46 = x24 + x45;
int32_t x47 = 3 * x46;
int32_t x48 = x47 + 2;
x103[x48] = x41;
int32_t x35 = x32 + 1;
UCHAR x36 = x0[x35];
int32_t x39 = (int32_t) x36;
int32_t x42 = x39 * 2;
int32_t x50 = x47 + 1;
x103[x50] = x42;
UCHAR x37 = x0[x32];
int32_t x40 = (int32_t) x37;
int32_t x43 = x40 * 2;
x103[x47] = x43;

}

}
int32_t x62 = x61 + x19;
int32_t x64 = x62 - x15;
int32_t x67 = MIN(x64, 0);
int32_t x68 = MAX(0, x67);
int32_t x69 = x2 * x68;
int32_t x84 = x7 * x62;
for(int x58=-1; x58 < x4; x58++) {
int32_t x63 = x58 + 1;
int32_t x65 = MIN(x63, x4);
int32_t x66 = MAX(0, x65);
int32_t x70 = x66 + x69;
int32_t x71 = 3 * x70;
int32_t x72 = x71 + 2;
int32_t x111 = x103[x72];
int32_t x74 = x71 + 1;
int32_t x112 = x103[x74];
int32_t x113 = x103[x71];
int32_t x83 = x58 - -1;
int32_t x85 = x83 + x84;
int32_t x86 = 3 * x85;
int32_t x87 = x86 + 2;
int32_t x114 = x111 / 2;
UCHAR x115 = (UCHAR) x114;
x102[x87] = x115;
int32_t x89 = x86 + 1;
int32_t x117 = x112 / 2;
UCHAR x118 = (UCHAR) x117;
x102[x89] = x118;
int32_t x120 = x113 / 2;
UCHAR x121 = (UCHAR) x120;
x102[x86] = x121;

}

}
free(x103);

}
memcpy(x1, x102, x9);
free(x102);
}
int32_t WIDTH_OUT_DIFF = 0;
int32_t HEIGHT_OUT_DIFF = 0;
int32_t WIDTH_OUT_MUL = 1;
int32_t WIDTH_OUT_DIV = 1;
int32_t HEIGHT_OUT_MUL = 1;
int32_t HEIGHT_OUT_DIV = 1;
