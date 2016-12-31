//
//  dummy_abstract_class.h
//  abstract_data_memory
//
//  Created by Hodohara Norifumi on 2016/12/31.
//  Copyright (c) 2016年 Hodohara Norifumi. All rights reserved.
//

#ifndef dummy_abstract_class_h
#define dummy_abstract_class_h

#include <stdio.h>

typedef struct dummy_abst_s* DummyAbst;

size_t DummyAbst_size();
void DummyAbst_init( DummyAbst da );

#endif
