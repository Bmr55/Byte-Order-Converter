#include <stdio.h>
#include <inttypes.h>
#include "byte_order_converter.h"

// check system byte ordering 
void print_system_byte_order() {

  int n = 1;

  if(*(char *)&n == 1) {
    printf("Swapping from Little Endian Byte Order to Big Endian Byte Order\n");
  } else {
    printf("Swapping from Big Endian Byte Order to Little Endian Byte Order\n");
  }
}

int main() {
  unsigned short value1 = 0xA236;
  printf("16-bit Value = 0x%hX\n", value1);
  print_system_byte_order();
  value1 = swap_byte_order_16bit(value1);
  printf("16-bit Value = 0x%hX\n\n", value1);

  unsigned int value2 = 0xA236CAF8;
  printf("32-bit Value = 0x%X\n", value2);
  print_system_byte_order();
  value2 = swap_byte_order_32bit(value2);
  printf("32-bit Value = 0x%X\n\n", value2);

  unsigned long value3 = 0xA236CAF8FF00AACC;
  printf("64-bit Value = 0x%" PRIX64 "\n", value3);
  print_system_byte_order();
  value3 = swap_byte_order_64bit(value3);
  printf("64-bit Value = 0x%" PRIX64 "\n\n", value3);
}
