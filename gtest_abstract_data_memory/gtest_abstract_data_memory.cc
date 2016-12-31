// 抽象データ型のためのメモリ確保ライブラリのテスト
// absdataのサイズを複数回受け取る　そのあと合計サイズおよび各データへの先頭ポインタを返す
// 目的：抽象データ型の組み込みにおけるデータ確保。組み込みでは基本的に動的メモリ確保は禁止。
// あらかじめ確保済みのメモリを渡して、それに対してデータを割り当てる。
// 初期化テスト
// サイズ計算テスト
// 通常使用ユースケース


#include <iostream>
#include "../abstract_data_memory/abstract_data_memory.c"
#include "gtest/gtest.h"

#include "dummy_abstract_class.c"

class AbstractDataMemoryTest : public ::testing::Test{
protected:
    AbstractDataMemoryTest(){
        AbstDataMem_clear_alloc_size();
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
    char buf[ 256 ];
    
    AbstDataMem adm = AbstDataMem_init( buf, sizeof(buf) );
    
    EXPECT_EQ( adm->buf_size, sizeof(buf) );
    EXPECT_EQ( adm->header_size, sizeof( struct abst_data_mem_s ) );
    EXPECT_EQ( adm->used_size, 0u );
}

TEST_F(AbstractDataMemoryTest, 初期化テスト_バッファ不足)
{
    char buf[ 10 ];
    
    AbstDataMem adm = AbstDataMem_init( buf, sizeof(buf) );
    
    EXPECT_FALSE( adm );
    /*EXPECT_EQ( adm->buf_size, sizeof(buf) );
    EXPECT_EQ( adm->header_size, sizeof( struct abst_data_mem_s ) );
    EXPECT_EQ( adm->used_size, 0u );*/
}

TEST_F(AbstractDataMemoryTest, サイズ計算テスト)
{
    AbstDataMem_add_size( DummyAbst_size() );
    
    EXPECT_EQ( AbstDataMem_alloc_size(), sizeof( struct abst_data_mem_s ) + DummyAbst_size() );
}

TEST_F(AbstractDataMemoryTest, 通常使用ユースケース)
{
    AbstDataMem_add_size( DummyAbst_size() );
    
    char* buf = (char*)malloc( AbstDataMem_alloc_size() );
    
    AbstDataMem adm = AbstDataMem_init( buf, AbstDataMem_alloc_size() );
    
    DummyAbst da = (DummyAbst)AbstDataMem_get_data( adm, DummyAbst_size() );
    
    DummyAbst_init( da );
    
    EXPECT_EQ( da->a, 0);
    EXPECT_EQ( da->b, 1);
    EXPECT_FLOAT_EQ( da->c, 2.0f );
    EXPECT_DOUBLE_EQ( da->d, 3.0 );
}

TEST_F(AbstractDataMemoryTest, getdataバッファ不足)
{
    char* buf = (char*)malloc( AbstDataMem_alloc_size() );
    
    AbstDataMem adm = AbstDataMem_init( buf, AbstDataMem_alloc_size() );
    
    DummyAbst da = (DummyAbst)AbstDataMem_get_data( adm, DummyAbst_size() );
    
    ASSERT_FALSE( da );
}

TEST_F(AbstractDataMemoryTest, 残りサイズ計算)
{
    char buf[ 100 ];
    
    AbstDataMem adm = AbstDataMem_init( buf, 100 );
    
    EXPECT_EQ( AbstDataMem_remain_size( adm ), 100 - sizeof( abst_data_mem_s ) );
}

TEST_F(AbstractDataMemoryTest, 残りサイズ計算ゼロ)
{
    struct abst_data_mem_s adm_s;
    adm_s.buf_size = adm_s.header_size = sizeof( struct abst_data_mem_s );
    adm_s.used_size = 0u;
    
    EXPECT_EQ( AbstDataMem_remain_size( &adm_s ), 0u );
}

TEST_F(AbstractDataMemoryTest, 残りサイズ計算マイナスはゼロにする)
{
    struct abst_data_mem_s adm_s;
    adm_s.buf_size = adm_s.header_size = sizeof( struct abst_data_mem_s );
    adm_s.used_size = 1u;
    
    EXPECT_EQ( AbstDataMem_remain_size( &adm_s ), 0u );
}

TEST_F(AbstractDataMemoryTest, 構造体サイズ計算)
{
    
}

TEST(GeneralTest, 符号なし計算)
{
    EXPECT_TRUE( 10u - 11u == -1 );
    EXPECT_TRUE( 10u - 11u > 0u ); // これが成り立ってしまうので注意
}

TEST(GeneralTest, sizeof挙動)
{
    char ary[ 10 ];
    char* alc = (char*)malloc( 10 );
    
    EXPECT_EQ( sizeof(ary), 10 );
    EXPECT_NE( sizeof(ary), sizeof(char*) );
    
    EXPECT_NE( sizeof(alc), 10 );
    EXPECT_EQ( sizeof(alc), sizeof(char*) );
}

TEST_F(AbstractDataMemoryTest, 絶対成功テスト)
{
    SUCCEED();
}

