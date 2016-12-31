// 抽象データ型のためのメモリ確保ライブラリのテスト
// absdataのサイズを複数回受け取る　そのあと合計サイズおよび各データへの先頭ポインタを返す
// 目的：抽象データ型の組み込みにおけるデータ確保。組み込みでは基本的に動的メモリ確保は禁止。
// あらかじめ確保済みのメモリを渡して、それに対してデータを割り当てる。
// 初期化テスト
// サイズ計算テスト


#include <iostream>
#include "../abstract_data_memory/abstract_data_memory.c"
#include "gtest/gtest.h"

class AbstractDataMemoryTest : public ::testing::Test{
protected:
    AbstractDataMemoryTest(){
    }
    virtual ~AbstractDataMemoryTest(){
    }
    virtual void SetUp(){
    }
    virtual void TearDown(){
        
    }

};

TEST_F(AbstractDataMemoryTest, 初期化テスト)
{
    int buf[ 256 ];
    
    AbstDataMem adm = AbstDataMem_init( buf, sizeof(buf) );
    
    EXPECT_EQ( adm->size, sizeof(buf) );
}

TEST_F(AbstractDataMemoryTest, 絶対成功テスト)
{
    SUCCEED();
}

