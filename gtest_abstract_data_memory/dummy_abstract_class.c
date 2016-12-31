//
//  dummy_abstract_class.c
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/31.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#include "dummy_abstract_class.h"

struct dummy_abst_s{
    int a;
    int b;
    float c;
    double d;
};

size_t DummyAbst_size()
{
    return sizeof( struct dummy_abst_s );
}

void DummyAbst_init( DummyAbst da )
{
    if( da != NULL ){
        da->a = 0;
        da->b = 1;
        da->c = 2.0f;
        da->d = 3.0;
    }
}