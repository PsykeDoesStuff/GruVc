
#include "Types.h"
#include <stdbool.h>
#include <stdlib.h>
#define BITMAP_SIZE_TO_BYTES(_sz) ((((_sz) / 64) + 1) * sizeof(u64))
typedef u8 *Bitvec;

static inline Bitvec bitvec_alloc(u64 sz) {
  return (Bitvec)malloc(BITMAP_SIZE_TO_BYTES(sz));
}

static inline Bitvec bitvec_calloc(u64 sz) {
  return (Bitvec)calloc(1, BITMAP_SIZE_TO_BYTES(sz));
}

static inline Bitvec bitvec_realloc(Bitvec self, u64 sz) {
  return (Bitvec)realloc((void *)self, BITMAP_SIZE_TO_BYTES(sz));
}

static inline void bitvec_set(Bitvec self, u64 n) {
  ((u8 *)self)[n / 8] |= (1 << (n % 8));
}

static inline bool bitvec_get(Bitvec self, u64 n) {
  return (((u8 *)self)[n / 8] & (1 << (n % 8))) != 0;
}

static inline void bitvec_clr(Bitvec self, u64 n) {
  ((u8 *)self)[n / 8] &= ~(1 << (n % 8));
}
