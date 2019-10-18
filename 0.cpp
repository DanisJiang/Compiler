#include<iostream>
#include<string>
using std::string;

void expr(string::iterator& i);
void rest(string::iterator& i);
string::iterator& term(string::iterator& i);


// expr -> term rest
void expr(string::iterator& i)
{
    rest(term(i));
}

// rest -> + term {print("+")} rest | - term {print("-")} rest | e
void rest(string::iterator& i)
{
    if (*i == '+') {
        i = term(++i);
        std::cout << '+';
        rest(i);
    }
    else if (*i == '-') {
        i = term(++i);
        std::cout << '-';
        rest(i);
    }
    else if (*i != '\0') {
        std::cerr << "error: invalid op!" << std::endl;
        exit(-1);
    }
    else ;  // e
}

/* 
term -> 0 {print("0")}
term -> 1 {print("1")}
...
term -> 9 {print("9")}
*/
string::iterator& term(string::iterator& i)
{
    if (isdigit(*i)) {
        std::cout << *i;
        i++;
    }
    else {
        std::cerr << "error: should be digit!" << std::endl;
        exit(-1);
    }
    return i;
}

int main()
{
    string s = "9-5+2";
    while (std::cin >> s)
    {
        string::iterator i = s.begin();
        expr(i);
        std::cout << std::endl;
    }
}