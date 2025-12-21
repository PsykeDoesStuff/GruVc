#pragma once

#include <stddef.h>
#include <stdint.h>
typedef uint64_t UUid;

void GenerateUUid(UUid *id);
char *UUidToString(size_t length, UUid id);
