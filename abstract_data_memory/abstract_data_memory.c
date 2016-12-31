//
//  abstract_data_memory.c
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/30.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#include "abstract_data_memory.h"

struct abst_data_mem_s{
    size_t  size;
};

AbstDataMem AbstDataMem_init( void* buf, size_t size )
{
    AbstDataMem adm = (AbstDataMem)buf;
    
    adm->size = size;
    
    return adm;
}

// utility

static size_t g_alloc_size = 0u;

void    AbstDataMem_clear_alloc_size()
{
    g_alloc_size = 0u;
}

void    AbstDataMem_add_size( size_t data_size )
{
    g_alloc_size += data_size;
}

size_t  AbstDataMem_alloc_size()
{
    return g_alloc_size;
}