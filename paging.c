#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
 int process_size, page_size, mem_size, num_frames, num_entries, phys_bits,
log_bits;
 int page_table[100][3];
 int logical_address, page_num, offset, frame_num, i, found;
 printf("Enter process size (in KB): ");
 scanf("%d", &process_size);
 printf("Enter page size (in bytes): ");
 scanf("%d", &page_size);
 printf("Enter physical memory size (in MB): ");
 scanf("%d", &mem_size);
 printf("Enter page table (page no., frame no., valid bit):\n");
 for (i = 0; i < 100; i++) {
 scanf("%d %d %d", &page_table[i][0], &page_table[i][1], &page_table[i][2]);
 if (page_table[i][2] == 0) {
 break;
 }
 }
 num_entries = i;

 // calculate number of frames
 num_frames = (mem_size * 1024) / page_size;

 // calculate number of bits in physical address
 phys_bits = log2(num_frames * page_size);

 // calculate number of bits in logical address
 log_bits = log2(process_size * 1024);
 printf("Number of bits in logical address: %d\n", log_bits);
 printf("Distribution of logical address: %d bits page number, %d bits offset\n",
 log_bits - phys_bits, phys_bits);
 // simulate a logical address lookup
 printf("Enter a logical address in binary form: ");
 scanf("%d", &logical_address);
 offset = logical_address % page_size;
 page_num = logical_address / page_size;
 found = 0;
 for (i = 0; i < num_entries; i++) {
 if (page_table[i][0] == page_num && page_table[i][2] == 1) {
 frame_num = page_table[i][1];
 printf("Page %d is present in frame %d\n", page_num, frame_num);
 found = 1;
 break;
 }
 }
 if (found == 0) {
 printf("Page %d is not present in memory\n", page_num);
 }
 printf("Total number of frames in memory: %d\n", num_frames);
 printf("Number of entries in page table: %d\n", num_entries);
 printf("Number of bits in physical address: %d\n", phys_bits);
 return 0;
}
