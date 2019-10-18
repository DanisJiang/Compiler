#include "global.hpp"

// get the number from cin
int lexan()
{
    int t;
    while (1) {
        t = getchar();
        if (t == ' ' || t == '\t')
            ;
        else if (t == '\n') {
            lineno++;
        }
        else if (isdigit(t)) {
            ungetc(t, stdin);
            // printf("tokenval=%d\n", tokenval);
            std::cin >> tokenval;
            // printf("tokenval=%d\n", tokenval);
            return NUM;
        }
        else if (isalpha(t)) {
            std::string tmp;
            ungetc(t, stdin);
            std::cin >> tmp;
            if (*(tmp.end()-1) == ';') {
                tmp.erase(tmp.end()-1);
                ungetc(';', stdin);
            }
            int p = lookup(tmp);
            // std::cout << p << std::endl;
            if (p == -1) {
                p = insert(tmp, ID);
            }
            tokenval = p;
            // std::cout << symtable[0].getLex() << std::endl;
            return symtable[p].getToken();
        }
        else if (t == EOF)
            return DONE;
        else {
            tokenval = 0;
            return t;
        }
    }
}