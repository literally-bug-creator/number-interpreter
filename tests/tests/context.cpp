#include "context.hpp"

#include <cstddef>
#include <gtest/gtest.h>

using namespace number_interpreter;

TEST( TestContext, WithEmptyTokens ) {
    std::vector<Token> tokens = {};
    Context ctx = Context( tokens );
    EXPECT_EQ( ctx.size(), tokens.size() );
}

TEST( TestContext, NonEmptyTokens ) {
    int TOKEN_AMOUNT = 100;
    std::vector<Token> tokens;
    tokens.resize( TOKEN_AMOUNT );

    for ( int i = 0; i < TOKEN_AMOUNT; i++ ) {
        Token token = make_token( i - '0' );
        tokens.push_back( token );
        Context ctx = Context( tokens );
        EXPECT_EQ( ctx.size(), tokens.size() );
    }
}

TEST( TestContext, NextOneOfOne ) {
    int TOKEN_AMOUNT = 100;
    Token token = make_token( '1' );
    std::vector<Token> tokens = { token };
    Context ctx = Context( tokens );

    ctx.next( size( token ) );

    EXPECT_EQ( ctx.is_finished(), true );
}

TEST( TestContext, NextOneOfTwo ) {
    int TOKEN_AMOUNT = 100;
    Token token = make_token( '1' );
    std::vector<Token> tokens = { token, token };
    Context ctx = Context( tokens );

    ctx.next( size( token ) );

    EXPECT_EQ( ctx.is_finished(), false );
}

TEST( TestContext, NextTwoOfTwo ) {
    int TOKEN_AMOUNT = 100;
    Token token = make_token( '1' );
    std::vector<Token> tokens = { token, token };
    Context ctx = Context( tokens );

    ctx.next( size( token ) );
    ctx.next( size( token ) );

    EXPECT_EQ( ctx.is_finished(), true );
}

TEST( TestContext, GetRemainingTokensAmount ) {
    int TOKEN_AMOUNT = 100;
    Token token = make_token( '1' );
    std::vector<Token> tokens( TOKEN_AMOUNT, token );
    Context ctx = Context( tokens );

    for ( int i = 0; i < TOKEN_AMOUNT; i++ ) {
        EXPECT_EQ( ctx.get_remaining_tokens_amount(), tokens.size() - i );
        ctx.next( size( token ) );
    }

    EXPECT_EQ( ctx.is_finished(), true );
}

TEST( TestContext, DumpAndRestore ) {
    int TOKEN_AMOUNT = 50;
    Token token = make_token( '1' );
    std::vector<Token> tokens( TOKEN_AMOUNT, token );
    Context ctx = Context( tokens );

    ContextImage image = ctx.dump();
    for ( auto& token : tokens ) {
        ctx.next( size( token ) );
    }

    EXPECT_EQ( ctx.is_finished(), true );
    EXPECT_EQ( ctx.get_remaining_tokens_amount(), 0 );
    ctx.restore( image );
    EXPECT_EQ( ctx.is_finished(), false );
    EXPECT_EQ( ctx.get_remaining_tokens_amount(), TOKEN_AMOUNT );
}

TEST( TestContext, GetTokens ) {
    int TOKEN_AMOUNT = 50;
    Token token = make_token( '1' );
    std::vector<Token> tokens( TOKEN_AMOUNT, token );
    Context ctx = Context( tokens );

    for ( size_t i = 0; i < TOKEN_AMOUNT; i++ ) {
        TokenSequenceView view = ctx.get_tokens();

        EXPECT_EQ( view.size(), ctx.size() - ( i + 1 ) );

        for ( size_t j = 0; j < view.size(); j++ ) {
            Token view_token = view.at( j );
            Token real_token = tokens.at( j + i );

            EXPECT_EQ( is_equal( view_token, real_token ), true );
        }

        ctx.next( size( token ) );
    }
}
