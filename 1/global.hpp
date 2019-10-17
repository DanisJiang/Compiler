#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

int tokenval;
int lineno = 1;
int lookahead;

class entry
{
private:
    std::string lex;
    int token;

public:
    const std::string &getLex();
    entry();
    entry(std::string s, int tok) : lex(s), token(tok){};
};

std::vector<entry> symtable;

int lexan();
int lookup(const std::string &s);
int insert(std::string s, int tok);
void init();
void parse();
void expr();
void term();
void factor();
void match(int t);
void error(std::string m);
void emit(int t, int tval);