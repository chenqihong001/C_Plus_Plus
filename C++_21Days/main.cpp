#include <iostream>
#include <array>
#include "day14.h"
#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include "timer.h"
#include <algorithm>
int main() {
    std::vector<int> myVector;
    for (int i = 0; i < 15000; ++i) {
        myVector.push_back(i);
    }
    std::list<int> myList;

    for (int i = 0; i < 15000; ++i) {
        myList.push_back(i);
    }
   
    //for(int i = 0;i<500;i++)//67ms
    //std::find(myVector.begin(), myVector.end(),7500);//3ms
    auto it1 = myVector.begin() + 7500;
    auto it2 = std::next(myList.begin(),7500);
    Timer<nanoseconds> time;
    myList.insert(it2, 9999);
    return 0;
}
