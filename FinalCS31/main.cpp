//
//  main.cpp
//  FinalCS31
//
//  Created by HaoYu Luo on 2022/6/4.
//

#include <iostream>
using namespace std;

void ptr_function(int* ptr)
{
    int *ptr2 = new int;
    *ptr2 = 10;
    ptr = ptr2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
