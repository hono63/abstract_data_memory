//
//  abstract_data_memory.c
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/30.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#include "abstract_data_memory.h"

// structure
struct abst_data_mem_s{
    size_t  buf_size;
    size_t  header_size;
    size_t  used_size;
};

// prototype
static size_t AbstDataMem_remain_size( const AbstDataMem adm );
static size_t AbstDataMem_struct_size();

// external function

AbstDataMem AbstDataMem_init( void* buf, size_t buf_size )
{
    AbstDataMem adm;
    
    if( buf_size >= AbstDataMem_struct_size() ){

        adm = (AbstDataMem)buf;
        adm->buf_size = buf_size;
        adm->header_size = sizeof( struct abst_data_mem_s );
        adm->used_size = 0u;
    
    }else{
        adm = NULL;
    }
    
    return adm;
}

void* AbstDataMem_get_data( AbstDataMem adm, size_t data_size )
{
    unsigned char* p;
    
    if( adm != NULL && AbstDataMem_remain_size(adm) >= data_size ){
        
        p = (unsigned char*)adm + adm->header_size + adm->used_size;
        adm->used_size += data_size;
    
    }else{
        p = NULL;
    }
    
    return (void*)p;
}

// utility function

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


// internal function

static size_t AbstDataMem_remain_size( const AbstDataMem adm )
{
    int rmn = (int)adm->buf_size - (int)adm->header_size - (int)adm->used_size;
    
    if( rmn < 0 ){
        rmn = 0;
    }
    
    return  (size_t)rmn;
}

static size_t AbstDataMem_struct_size()
{
    return  sizeof(struct abst_data_mem_s);
}