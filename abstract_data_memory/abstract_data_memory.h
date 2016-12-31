//
//  abstract_data_memory.h
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/30.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#ifndef abstract_data_memory_h
#define abstract_data_memory_h

#include "stdio.h"

typedef struct abst_data_mem_s* AbstDataMem;

AbstDataMem AbstDataMem_init( void* buf, size_t size );

// utility
void    AbstDataMem_clear_alloc_size();
void    AbstDataMem_add_size( size_t data_size );
size_t  AbstDataMem_alloc_size();

#endif
