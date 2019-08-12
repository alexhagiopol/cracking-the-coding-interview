/*
 * PROBLEM:
 * Write an aligned malloc and free function that supports allocating memory such that the
 * memory address returned is divisible by a specific power of two.
 *
 * These articles discuss the importance of aligned memory allocation:
 * https://developer.ibm.com/articles/pa-dalign/
 * https://codeyarns.com/2017/02/28/aligned-memory-allocation/
 *
 * The general idea is that CPU hardware is designed to read multiple bytes of data from
 * memory in a single read instruction, and therefore one must keep this design choice in
 * mind when allocating memory. For example, a CPU with 64 bit architecture can
 * read addresses 0-7 (1 byte each) in a single read instruction. If a data structure
 * requires 32 bits of memory but those 32 bits are spread out over addresses 5, 7, 8, and 9,
 * then the CPU will require two read instructions to read 32 bits instead of one. One instruction
 * will read addresses 0-7, a second will read addresses 8-15, and more instructions will be
 * required to shift the results for further operations. Had the 32 bit data structure been
 * aligned in memory to fit completely inside of addresses 0-7 or 8-15, it could have been read
 * in just one read instruction. Thus by aligning data to the CPU's memory access granularity,
 * one can improve performance.
 *
 * ALGORITHM:
 * 1. Write a wrapper around the built in malloc() and free() functionality in C that
 * takes into account the alignment issues discussed above.
 * 2. The core feature to implement is returning a memory address whose value is
 * divisible by the alignment parameter of the function and which points to the required
 * number of bytes.
 */

#pragma once

namespace chapter_12 {
    void* alignedMalloc(size_t required_bytes, size_t alignment) {
        // allocate enough space for required bytes, pointer to full memory block that enables alignedFree(), and alignment space
        void* p1; // initial block
        void* p2; // aligned block inside initial block
        int offset = alignment - 1 + sizeof(void*);  // offset to achieve alignment - includes size of extra pointer
        p1 = (void*)malloc(required_bytes + offset);
        if (p1 == NULL) return NULL;  // handle case where user tries to allocate more memory than they have
        p2 = (void*)(((size_t)(p1) + offset) & ~(alignment - 1));
        ((void**)p2)[-1] = p1;
        return p2;
    }

    void alignedFree(void* p2) {
        void* p1 = ((void**)p2)[-1];
        free(p1);
    }
}
