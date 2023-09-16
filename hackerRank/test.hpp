#include <iostream>
#include <vector>
class Test {
public:
    static std::vector<int> test;  // Declaration of the static vector
};

std::vector<int> Test::test={1,2,4,5,6};