// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int low = 0;
    int peak = 0;
    int depthMax = 0;
    bool type  = true; // 0 - rising 1- falling
    
    if ( A.size() < 3 ) {
        return 0;
    }
    peak = A[0];

    for ( unsigned int i = 1; i < A.size(); ++i ) {
        if ( A[i] >= A[i-1] ) {
            //rising
            if ( type ) {
                type = false;
                if ( low == 0 || A[i-1] < low ) {
                    low = A[i-1];
                }
            }
            
        } else {
            //falling
            if ( !type ) {
                type = true;
                //if ( low != 0 && //ignore first peak
                int depth = std::min( A[i -1], peak) - low;
                
                if ( low != 0 &&
                     depth > depthMax ) { //ignore first peak
                       depthMax = depth;
                }
                
                if ( A[i -1] > peak ) {
                    peak = A[i-1];
                    //reset low
                    low = 0;
                } 
            }
        }
    }
    
    if ( !type ) {
        //rising
        //second peak;
        int depth = std::min( A[A.size()-1], peak) - low;
              //cout << "Deph: " << depth <<endl;  
        if ( low != 0 &&
             depth > depthMax ) { //ignore first peak
               depthMax = depth;
        }
    }
    
    return depthMax;
}
