#ifndef H_count_min
#define H_count_min

// Standard libraries
#include <inttypes.h>
#include <stdbool.h>

// User defined libraries
#include "sketch/sketch.h"
#include "util/hash.h"

// Helpers
#define COUNT_MIN_INDEX(width, depth, index) \
	( 2 + ( (2+(width)) * (depth) ) + (index) )

// Structures
typedef struct {
	sketch_size_t      size;    // Width and depth of sketch
	uint64_t *restrict table;   // The count_min table
	hash_t   *restrict hash;    // Structure that determines work of hash function
} count_min_t; 


// Initialization
count_min_t *count_min_create(hash_t *restrict hash, const uint8_t b, 
		const double epsilon, const double delta);

// Destuction
void count_min_destroy(count_min_t *restrict s);

// Update
void count_min_update(count_min_t *restrict s, const uint32_t i, 
		const int64_t c);

// Query
uint64_t count_min_point(count_min_t *restrict s, const uint32_t i);
uint64_t count_min_point_partial(count_min_t *restrict s, const uint32_t i,
		const uint32_t d);
bool count_min_above_thresshold(count_min_t *restrict s, const uint32_t i, 
		const uint64_t th);
uint64_t count_min_range_sum(count_min_t *restrict s, const uint32_t l, 
		const uint32_t r);

// Heavy hitter thresshold
inline double count_min_heavy_hitter_thresshold(const uint64_t l1, 
		const double epsilon, const double th) {
	(void) epsilon;
	(void) l1;
	return th;	
}

#endif
