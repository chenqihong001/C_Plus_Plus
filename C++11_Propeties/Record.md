# 一些关键字

## noexcept

* 可以用于指定函数是否抛出异常

    > `void myFUnc noexcept(){}`

* 运算符
    >`int result = foo() noexcept ? bar() : baz();`
    对于此式子，若foo()抛出异常则调用bar,否则调用baz
