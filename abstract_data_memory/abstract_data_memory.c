//
//  abstract_data_memory.c
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/30.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#include "abstract_data_memory.h"

struct abst_data_mem_s{
    size_t  buf_size;
    size_t  header_size;
    size_t  used_size;
};

AbstDataMem AbstDataMem_init( const void* buf, size_t buf_size )
{
    AbstDataMem adm = (AbstDataMem)buf;
    
    adm->buf_size = buf_size;
    adm->header_size = sizeof( struct abst_data_mem_s );
    adm->used_size = 0u;
    
    return adm;
}

void* AbstDataMem_get_data( const AbstDataMem adm, size_t data_size )
{
    unsigned char* p;
    
    p = (unsigned char*)adm + adm->header_size + adm->used_size;
    
    adm->used_size += data_size;
    
    return (void*)p;
}

// utility

static size_t g_alloc_size = 0u;

void    AbstDataMem_clear_alloc_size()
{
    g_alloc_size = sizeof( struct abst_data_mem_s );
}

void    AbstDataMem_add_size( size_t data_size )
{
    g_alloc_size += data_size;
}

size_t  AbstDataMem_alloc_size()
{
    return g_alloc_size;
}