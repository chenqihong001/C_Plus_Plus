#include <iostream>

int main() {
    try {
        throw std::runtime_error("This is an exception!");  // 抛出异常
        // 可能引发异常的代码块
    }
    catch (const std::runtime_error& e) {
        // 处理 std::runtime_error 类型的异常
        std::cerr << "Caught a runtime_error: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        // 处理 std::logic_error 类型的异常
        std::cerr << "Caught a logic_error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // 处理其他类型的异常
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...) {
        // 处理任意类型的异常
        std::cerr << "Caught an unknown exception." << std::endl;
    }
    return 0;
}
