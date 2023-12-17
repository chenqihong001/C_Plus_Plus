// 不可以通过set的迭代器去修改set节点的值->会影响整体的顺序结构
// 即iterator(set) is const_iterator
class Set
{
public:
    // insert(elem);           在容器中插入元素。
    // clear();                清除所有元素
    // erase(pos);             删除pos迭代器所指的元素，返回下一个元素的迭代器。
    // erase(beg, end);        删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    // erase(elem);            删除容器中值为elem的元素。
    // find(key);              查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    // count(key);             查找键key的元素个数
    // lower_bound(keyElem);   返回第一个key>=keyElem元素的迭代器。
    // upper_bound(keyElem);   返回第一个key>keyElem元素的迭代器。
    // equal_range(keyElem);   返回容器中key与keyElem相等的上下限的两个迭代器。
};