//
//  main.cpp
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/30.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#include <stdio.h>
#include "abstract_data_memory.h"

int main(int argc, const char * argv[])
{
    AbstDataMem_clear_alloc_size();
    
    char* buf = (char*)malloc( AbstDataMem_alloc_size() );
    
    AbstDataMem adm = AbstDataMem_init( buf, AbstDataMem_alloc_size() );
    
    return 0;

}
