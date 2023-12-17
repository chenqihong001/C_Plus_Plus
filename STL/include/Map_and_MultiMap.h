#pragma once
#include <map>
// 不可通过map的迭代器求修改map中数据的键值
class Map
{
public:
    // find(key);              查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
    // count(keyElem);         返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
    // lower_bound(keyElem);   返回第一个key>=keyElem元素的迭代器。
    // upper_bound(keyElem);   返回第一个key>keyElem元素的迭代器。
    // equal_range(keyElem);   返回容器中key与keyElem相等的上下限的两个迭代器。
    // clear();                删除所有元素
    // erase(pos);             删除pos迭代器所指的元素，返回下一个元素的迭代器。
    // erase(beg, end);        删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    // erase(keyElem);         删除容器中key为keyElem的对组。
};