#include <stdio.h>
#include <string>
#include <iostream>
#include "thread_guard.h"
int main()
{
    Functor f;
    std::thread th(&Functor::Func, &f, 0);
    th.join();
    return 0;
}

