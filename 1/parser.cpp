#include "global.hpp"

void parse()
{
    lookahead = lexan();
    // printf("lookahead=%d", lookahead);
    // printf("tokenval=%d\n", tokenval);
    while (lookahead != DONE) {
        expr();
        match(';');
    }
}

void expr()
{
    int t;
    term();
    while (1) {
        switch (lookahead)
        {
        case '+': case '-':
            t = lookahead;
            // printf("loogahead=%d\n", lookahead);
            match(lookahead);
            term();
            // printf("t=%d\n", t);
            emit(t, 0);   
            continue;
        
        default:
            return;
        }
    }
}

void term()
{
    int t;
    factor();
    while (1) {
        // printf("lookahead=%d\n", lookahead);
        switch (lookahead)
        {
        case '*': case '/': case DIV: case MOD:
            t = lookahead;
            match(lookahead);
            factor();
            emit(t, 0);
            continue;
        
        default:
            return;
        }
    }
}

void factor()
{
    switch (lookahead)
    {
    case '(':
        match('(');
        expr();
        match(')');
        break;
    case NUM: 
        emit(NUM, tokenval);
        match(NUM);
        break;
    case ID:
        emit(ID, tokenval);
        match(ID);
        break;
    default:
        error("syntax error");
    }
}

void match(int t)
{
    if (lookahead == t) {
        lookahead = lexan();
    } else {
        error("syntax error");
    }
}