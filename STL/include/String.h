#pragma once
#include <iostream>
class String
{
public:
    String();                  // 创建一个空的字符串 例如: String str;
    String(const String &str); // 使用一个String对象初始化另一个String对象
    String(const char *s);     // 使用字符串s初始化
    String(int n, char c);     // 使用n个字符c初始化
    // 基本赋值操作
    String &operator=(const char *s);                  // char*类型字符串 赋值给当前的字符串
    String &operator=(const String &s);                // 把字符串s赋给当前的字符串
    String &operator=(char c);                         // 字符赋值给当前的字符串
    String &assign(const char *s);                     // 把字符串s赋给当前的字符串
    String &assign(const char *s, int n);              // 把字符串s的前n个字符赋给当前的字符串
    String &assign(const String &s);                   // 把字符串s赋给当前字符串
    String &assign(int n, char c);                     // 用n个字符c赋给当前字符串
    String &assign(const String &s, int start, int n); // 将s从start开始n个字符赋值给字符串
    // 存取字符操作
    char &operator[](int n); // 通过[]方式取字符
    char &at(int n);         // 通过at方法获取字符
    // 拼接操作
    String &operator+=(const String &str);           // 重载+=操作符
    String &operator+=(const char *str);             // 重载+=操作符
    String &operator+=(const char c);                // 重载+=操作符
    String &append(const char *s);                   // 把字符串s连接到当前字符串结尾
    String &append(const char *s, int n);            // 把字符串s的前n个字符连接到当前字符串结尾
    String &append(const String &s);                 // 同operator+=()
    String &append(const String &s, int pos, int n); // 把字符串s中从pos开始的n个字符连接到当前字符串结尾
    String &append(int n, char c);                   // 在当前字符串结尾添加n个字符c
    // 查找和替换操作
    int find(const String &str, int pos = 0) const;     // 查找str第一次出现位置,从pos开始查找
    int find(const char *s, int pos = 0) const;         // 查找s第一次出现位置,从pos开始查找
    int find(const char *s, int pos, int n) const;      // 从pos位置查找s的前n个字符第一次位置
    int find(const char c, int pos = 0) const;          // 查找字符c第一次出现位置
    int rfind(const String &str, int pos) const;        // 查找str最后一次位置,从pos开始查找
    int rfind(const char *s, int pos) const;            // 查找s最后一次出现位置,从pos开始查找
    int rfind(const char *s, int pos, int n) const;     // 从pos查找s的前n个字符最后一次位置
    int rfind(const char c, int pos = 0) const;         // 查找字符c最后一次出现位置
    String &replace(int pos, int n, const String &str); // 替换从pos开始n个字符为字符串str
    String &replace(int pos, int n, const char *s);     // 替换从pos开始的n个字符为字符串s

    /*compare函数在>时返回 1，<时返回 -1，==时返回 0。比较区分大小写，比较时参考字典顺序，排越前面的越小。大写的A比小写的a小。*/
    // 比较操作
    int compare(const String &s) const; // 与字符串s比较
    int compare(const char *s) const;   // 与字符串s比较
    // 子串
    String substr(int pos = 0, int n) const; // 返回由pos开始的n个字符组成的字符串
    // 插入，删除操作
    String &insert(int pos, const char *s);     // 插入字符串
    String &insert(int pos, const String &str); // 插入字符串
    String &insert(int pos, int n, char c);     // 在指定位置插入n个字符c
    String &erase(int pos, int n);              // 删除从Pos开始的n个字符
};
