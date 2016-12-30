#include <iostream>
#include <vector>
#include <set>

using namespace std;

int twoBiggestSum(const vector<int>& list) {
    multiset<int> twoBiggest;//ordered set with repetitions
    
    for (auto i : list) {
        twoBiggest.insert(i);
        if (twoBiggest.size() > 2) {
            twoBiggest.erase(twoBiggest.begin());//remove the smallest
        }
    }
    
    int sum = 0;
    for (auto i : twoBiggest) {
        sum += i;
    }
    return sum;
}

//Normally I would include prettyprint.hpp from github, however this is not suitable
ostream& operator<<(ostream& stream, const vector<int>& obj) {
    bool once = false;
    
    stream << "[";
    for (auto i : obj) {
        if (once) {
            stream << ",";
        }
        stream << i;
        once = true;
    }
    stream << "]";
    
    return stream;
}

void testTwoBiggestSum(const vector<int>& input, int expected_output) {
    auto output = twoBiggestSum(input);
    if (output == expected_output) {
        cout << "Test successful - input = " << input << " output = " << output << "\n";
    }
    else {
        cout << "Test failed - input = " << input << " output = " << output << " expected output = " << expected_output  <<"\n";
    }
}

int main()
{   
    testTwoBiggestSum({1, 10, 3, 7, 9},19);
    testTwoBiggestSum({-2, 1, -1, 0},1);
    testTwoBiggestSum({1,2,3},5);
    testTwoBiggestSum({-1,2,-3,-100},1);
    testTwoBiggestSum({10,10,1,2,11},21);
    testTwoBiggestSum({10,20,90,30,40,60,-1},90+60);

    return 0;
}

