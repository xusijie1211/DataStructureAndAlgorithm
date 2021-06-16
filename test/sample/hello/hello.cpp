/**
 * Your frist step to C++ world
 */

#include <iostream>
extern "C" {
#include <hello/hello.h>
}
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello, World!" << endl;
    hello();
    return 0;
}
