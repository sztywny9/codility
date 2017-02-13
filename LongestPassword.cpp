// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isOdd( int i ) {
    return i & 1;
}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int maxPass = -1;

    int lettersCount = 0;
    int digitsCount = 0;
    bool valid = true;
    for( char c : S ) {
        if ( ' ' == c ) {
            //space new password
            //valid password
            if ( valid &&
                 !isOdd(lettersCount) &&
                 isOdd(digitsCount) &&
                 maxPass < (lettersCount + digitsCount) ) {
                maxPass = (lettersCount + digitsCount);
            }
            lettersCount = 0;
            digitsCount = 0;
            valid = true;
        } else if ( '0' <= c && '9' >= c ) {
            ++digitsCount;
        } else if ( ('a' <= c && 'z' >= c) ||
                    ('A' <= c && 'Z' >= c) ) {
            ++lettersCount;
        } else {
            valid = false;
        } 
    }
    
    if ( valid &&
         !isOdd(lettersCount) &&
         isOdd(digitsCount) &&
         maxPass < (lettersCount + digitsCount) ) {
        maxPass = (lettersCount + digitsCount);
    }
    
    return maxPass;
}
