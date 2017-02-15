// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sum6( 6, A[0] );
    for( unsigned int i = 1; i < A.size(); ++i ) {
        sum6[i % 6] = *std::max_element( sum6.begin(), sum6.end() ) + A[i];
    }
    
    return sum6[(A.size() - 1) % 6];
}
