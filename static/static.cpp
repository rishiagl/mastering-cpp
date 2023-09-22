#include <bits/stdc++.h>

class test
{
private:
    int x;
public:
    static void func1(){ std::cout << "this is func1" << std::endl; }
    static void func2(){ std::cout << "this is func2" ; }
};

test::test()
{
}

test::~test()
{
}

int main(){
    test* obj = new test();
    obj->func2;
    return 0;
}