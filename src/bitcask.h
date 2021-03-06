/*
 *  Beansdb - A high available distributed key-value storage system:
 *
 *      http://beansdb.googlecode.com
 *
 *  Copyright 2010 Douban Inc.  All rights reserved.
 *
 *  Use and distribution licensed under the BSD license.  See
 *  the LICENSE file for full text.
 *
 *  Authors:
 *      Davies Liu <davies.liu@gmail.com>
 *
 */

#ifndef __BITCASK_H__
#define __BITCASK_H__

#include <stdint.h>

#include "record.h"
#include "diskmgr.h"
#include "beansdb.h"

typedef struct bitcask_t Bitcask;

Bitcask*   bc_open(const char *path, int depth, int pos, time_t before);
Bitcask*   bc_open2(Mgr *mgr, int depth, int pos, time_t before);
void       bc_scan(Bitcask *bc);
void       bc_flush(Bitcask *bc, int limit, int period);
void       bc_close(Bitcask *bc);
void       bc_merge(Bitcask *bc);
void       bc_optimize(Bitcask *bc, int limit);
DataRecord* bc_get(Bitcask *bc, const char* key);
bool       bc_set(Bitcask *bc, const char* key, char* value, int vlen, int flag, int version);
bool       bc_delete(Bitcask *bc, const char* key);
uint16_t   bc_get_hash(Bitcask *bc, const char * pos, int *count);
char*      bc_list(Bitcask *bc, const char* pos, const char *prefix);
uint32_t   bc_count(Bitcask *bc, uint32_t* curr);
void       bc_stat(Bitcask *bc, uint64_t *bytes);

#endif
