//
//  https://www.hackerrank.com/challenges/crush
//
//  Algorithmic_Crush.cpp
//  HacckerrankCpp
//

/*
 Solution 1
 */

#include <iostream>

using namespace std;

int main()

{
    
    long N, M, a, b, k, MaxVal = 0;
    
    cin >> N >> M;
    
    long *arr = new long int[N]();
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> k;
        arr[a - 1] += k;
        if((N-b)>0) arr[b] -= k; //insert negatives to its first out of range to isolate Maxvals..
        //Ex. testcase after first loop would be 100 0 -100 0 0
        //after second loop would be 100 100 -100 0 0
        //after third loop would be 100 100 0 0 -100
    }
    
    long arrrets = 0;
    for (int i = 0; i < N; i++) {
        arrrets = arrrets + arr[i];
        if (arrrets > MaxVal) MaxVal = arrrets; //In array 100 100 0 0 -100 --> MaxVal is 200
    }
    
    delete[] arr;
    
    cout << MaxVal << endl;
    
    return 0;
    
}
