#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int position;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next,position+1));
        }

        else if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()) break;
            
            if(opening_brackets_stack.top().Matchc(next)) 
                opening_brackets_stack.pop();
            
            else break;
        }

        else
            continue;
    }

    /*while(!opening_brackets_stack.empty()){
        cout<<opening_brackets_stack.top().type<<endl;
        opening_brackets_stack.pop();
    }*/

    if(position==text.length() && opening_brackets_stack.empty())
        cout<<"Success"<<endl;
    else if(position==text.length() && !opening_brackets_stack.empty())\
        cout<<opening_brackets_stack.top().position<<endl;
    else cout<<position+1<<endl;
}
