#include "testOutput/pipeline.h"
#include <assert.h>
#include <png.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: run infile outfile\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n.", argv[1]);
    return 1;
  }

  // Read image
  png_structp read_ptr = png_create_read_struct(
     PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (read_ptr == NULL) {
    printf("Error reading file.");
    return 1;
  }

  png_infop info_ptr = png_create_info_struct(read_ptr);
  png_init_io(read_ptr, fp);
  png_set_sig_bytes(read_ptr, 0);
  png_read_info(read_ptr, info_ptr);

  int width = png_get_image_width(read_ptr, info_ptr);
  int height = png_get_image_height(read_ptr, info_ptr);
  png_byte color = png_get_color_type(read_ptr, info_ptr);
  png_byte depth = png_get_bit_depth(read_ptr, info_ptr);

  printf("Width: %d, height: %d, depth: %d, color: %d\n", width, height, depth, color);
  printf("%d\n", PNG_COLOR_TYPE_RGB);

  if (depth != 8 || color != PNG_COLOR_TYPE_RGB) {
    printf("Error: Depth not equal to 8 or color type not RGB.");
  }

  // Extract pixel data
  char *image = malloc(sizeof(char) * width * height * 3);
  png_bytep row_pointers[height];
  for (int i = 0; i < height; i++) row_pointers[i] = image + 3 * width * i;
  png_read_image(read_ptr, row_pointers);

  // Transform the pixels
  int new_height = (height * HEIGHT_OUT_MUL) / HEIGHT_OUT_DIV - HEIGHT_OUT_DIFF;
  int new_width = (width * WIDTH_OUT_MUL) / WIDTH_OUT_DIV - WIDTH_OUT_DIFF;
  printf("Expexted output size: %d\n", new_height * new_width);
  char *out = malloc(sizeof(char) * (new_width) * new_height * 3);
  pipeline(image, out, width, height);

  // Write the output data
  png_structp write_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop write_info_ptr = png_create_info_struct(write_ptr);
  FILE *ofp = fopen(argv[2], "wb");
  png_init_io(write_ptr, ofp);

  png_set_IHDR(write_ptr, write_info_ptr, new_width, new_height, depth,
               color, png_get_interlace_type(read_ptr, info_ptr),
               png_get_compression_type(read_ptr, info_ptr),
               png_get_filter_type(read_ptr, info_ptr));
  png_write_info(write_ptr, write_info_ptr);
  png_bytep out_row_pointers[new_height];
  for (int i = 0; i < new_height; i++) out_row_pointers[i] = out + 3 * (new_width) * i;
  png_write_image(write_ptr, out_row_pointers);
  png_write_end(write_ptr, NULL);

  fflush(ofp);
  fclose(ofp);
  fclose(fp);
  free(image);
  free(out);
}
