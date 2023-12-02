#include <bitset>
#include <iostream>

int main() {
    // 创建一个包含8位的bitset
    std::bitset<8> myBitset;

    // 设置位
    myBitset.set(1);
    myBitset.set(3);
    myBitset.set(5);

    // 输出二进制表示
    std::cout << "Binary representation: " << myBitset << std::endl;

    // 获取位的值
    std::cout << "Bit at position 2: " << myBitset.test(2) << std::endl;

    // 以整数形式输出
    std::cout << "Integer representation: " << myBitset.to_ulong() << std::endl;

    return 0;
}
