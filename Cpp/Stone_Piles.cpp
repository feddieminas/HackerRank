//
//  https://www.hackerrank.com/challenges/stone-piles
//
//  Stone_Piles.cpp
//  HacckerrankCpp
//


/*
Solution. Fully accepted
 
sprague-grundy number theorem
Link below Set 3 and Set 4
concept: http://www.geeksforgeeks.org/combinatorial-game-theory-set-4-sprague-grundy-theorem/

below i <= rest / 2 and rest - i > i is the key to loop and find pair combinations of not the same value.
Ex. 4 stones not 2,2 but only a) 0, 1, 3
Ex. 5 stones not 2,2,1 and 3,1,1 but only a) 0, 1, 4 b) 0, 2, 3
XORingRes vector pushes the XOR sum of next positions
Ex. 8 stones - 0^1^7=4 - 0^1^2^5=2 - 0^1^3^4=1 - 0^2^6=3 - 0^3^5=3
sg_spdiv of each number of stones stores the minimum number not present in XORingRes
Ex. 8 stones - XORingRes 1 2 3 4 - sg_spdiv[8] = 0
*/

//#include <cstring>
//#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void compute_sg_spdiv(int prev, int start, int rest, vector<int>& sg_spdiv, vector<int>& XORingRes) {
    
    for (int i = start; i <= rest / 2; i++) {
        if (rest - i > i) {
            int res = prev ^ sg_spdiv[i] ^ sg_spdiv[rest - i];
            //cout << "res "<< res << endl;
            XORingRes.push_back(res);
            if (rest >= 2 && ((rest - 1) / 2) >= (i + 1)) compute_sg_spdiv(prev ^ sg_spdiv[i], i + 1, rest - i, sg_spdiv, XORingRes);
        }
    }
    
    int k = 0;
    if (prev == 0) {
        
        /*
         cout << "size "<< XORingRes.size() << endl;
         for (int i = 0; i < XORingRes.size(); i++)
         cout << rest << " " << XORingRes[i] << endl;
         cout << endl;
         */
        
        sort(XORingRes.begin(), XORingRes.end());
        XORingRes.erase(unique(XORingRes.begin(), XORingRes.end()), XORingRes.end());
        for (int i = 0; i < XORingRes.size(); i++)
            if (XORingRes[i] == i)
                k++;
            else
                break;
        sg_spdiv[n] = k;
    }
}

int main()
{
    vector<int> sg_spdiv(51, -1); //stone piles divisible
    sg_spdiv[0] = 0;
    sg_spdiv[1] = 0;
    sg_spdiv[2] = 0;
    sg_spdiv[3] = 1;
    
    vector<int> XORingRes;
    
    for (int i = 4; i <= 50; i++) {
        XORingRes.clear();
        n = i;
        compute_sg_spdiv(0, 1, i, sg_spdiv, XORingRes);
    }
    
    /*
     for (int i = 0; i <= 50; i++) {
     cout << sg_spdiv[i] << " ";
     }
     cout << endl;
     */
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> n; //piles
        int res = 0;
        
        for (int i = 0; i < n;i++) {
            int k;
            cin >> k; //stones
            res = res^sg_spdiv[k]; //XOR of Grundy
        }
        
        if (res == 0)
            cout << "BOB" << endl;
        else
            cout << "ALICE" << endl;
    }
    
    return 0;
}

