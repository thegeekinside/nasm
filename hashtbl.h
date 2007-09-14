/*
 * hashtbl.h
 *
 * Efficient dictionary hash table class.
 */

#ifndef NASM_HASHTBL_H
#define NASM_HASHTBL_H

#include <inttypes.h>
#include <stddef.h>
#include "nasmlib.h"

struct hash_tbl_node {
    uint64_t hash;
    const char *key;
    void *data;
};

struct hash_table {
    struct hash_tbl_node *table;
    size_t load;
    size_t size;
    size_t max_load;
};

struct hash_insert {
    uint64_t hash;
    struct hash_table *head;
    struct hash_tbl_node *where;
};

uint64_t crc64(const char *string);
struct hash_table *hash_init(void);
void *hash_find(struct hash_table *head, const char *string,
		struct hash_insert *insert);
void hash_add(struct hash_insert *insert, const char *string, void *data);
void hash_free(struct hash_table *head, void (*free_func)(char *, void *));

#endif /* NASM_HASHTBL_H */
