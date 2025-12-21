#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// very random large number
#define TABLE_SIZE 30000

typedef struct entry_t {
  char *key;
  void *value;
  struct entry_t *next;
} entry_t;

typedef struct {
  entry_t **entries;
} Hashtable;

void HashTableInit(Hashtable *hashtable) {
  // Only allocate the internal array
  hashtable->entries = malloc(sizeof(entry_t *) * TABLE_SIZE);

  for (int i = 0; i < TABLE_SIZE; i++) {

    hashtable->entries[i] = NULL;
  }
}

entry_t *HashtablePair(const char *key, const void *value, size_t size) {

  entry_t *entry = malloc(sizeof(entry_t));
  entry->key = malloc(strlen(key) + 1);
  entry->value = malloc(size);

  // copy data in place
  strcpy(entry->key, key);
  memcpy(entry->value, value, size);

  entry->next = NULL;
  return entry;
}

unsigned int hash(const char *key) {
  unsigned long int value = 0;
  unsigned int i = 0;
  unsigned int keylen = strlen(key);

  // multiply it a few times
  for (; i < keylen; i++) {
    value = value * 37 + key[i];
  }
  // make sure value <= value < TABLE_SIZE
  value = value % TABLE_SIZE;

  return value;
}
void HashtableSet(Hashtable *hashtable, const char *key, const void *value,
                  size_t size) {
  unsigned int slot = hash(key);

  // lookup entry set
  entry_t *entry = hashtable->entries[slot];

  // if theres nothing there, insert
  if (entry == NULL) {
    hashtable->entries[slot] = HashtablePair(key, value, size);
    return;
  }

  entry_t *prev;
  // walk through each entry until either the end is reacher or a mathcing key
  // is found
  while (entry != NULL) {
    // check key
    if (strcmp(entry->key, key) == 0) {
      // match found, replace value
      free(entry->value);
      entry->value = malloc(size);
      memcpy(entry->value, value, size);
      return;
    }

    prev = entry;
    entry = prev->next;
  }
  // end of chain reached without a match, add new kvp
  prev->next = HashtablePair(key, value, size);
}

void *HashtableGet(Hashtable *hashtable, const char *key) {
  unsigned int slot = hash(key);
  // try to find a valid slot
  entry_t *entry = hashtable->entries[slot];
  // no slot, nothing to return
  if (entry == NULL) {
    return NULL;
  }
  // go through each entry in the slot
  while (entry != NULL) {
    // return value if found
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    // go to next key if available
    entry = entry->next;
  }
  return NULL;
}
