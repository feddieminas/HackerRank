//
//  https://www.hackerrank.com/contests/master/challenges/xoring-ninja?h_r=internal-search
//
//  Xoring_Ninja.cpp
//  HacckerrankCpp
//

//Sent three solutions. Have a fully accepted solution in Python

#define USING_MAIN_1

#if defined USING_MAIN_1

/*
 Solution 1. Pass testcases 1 to 5 and 14. Others Terminated due to Timeout. Hacckerank has a max limit of 2,72 secs
 
 To find the subsets of a given set you need to loop through each element of
 an array and recurse through each level until you reach the out of range (N size-1). ArrStart increases by 1
 while levelstart remains static in order to be able to find the subsets which are not close to each other. Ex.
 (subset 1 3 on the setOrig 1 2 3)
 
 Ex.
 setOrig 1 2 3     |  setOrig 1 2 3 4
 Loops on Order:   |  Loops on Order:
 1                 |  1
 1 2               |  1 2
 1 2 3             |  1 2 3
 1 3               |  1 2 3 4
 2                 |  1 2 4
 2 3               |  1 3
 3                 |  1 3 4
 Sum: 12           |  1 4
                   |  2
                   |  2 3
                   |  2 3 4
                   |  2 4
                   |  3
                   |  3 4
                   |  4
                   |  Sum: 56
 */

#include <iostream>

using namespace std;

long long sum;
long long MOD = 1000000007;

void myPowerSetSum(long long* SetOrig, long long* SetsTmp,int mylevelstart,int myarrstart, long size) {
    
    long long XorSumSet;
    for (long i = myarrstart; i < size; i++) {
        SetsTmp[mylevelstart] = SetOrig[i];
        XorSumSet = 0;
        for (long j = 0; j <= mylevelstart; j++) {
            //cout << SetsTmp[j] << ' ';
            XorSumSet = XorSumSet^SetsTmp[j];
        }
        //cout << endl;
        sum = (sum + XorSumSet) % MOD;
        if (i < size - 1) {
            myPowerSetSum(SetOrig, SetsTmp, mylevelstart+1, int(i+1), size);
        }
    }
    
    return;
}


int main()
{
    int T;
    cin >> T;
    
    do
    {
        long N;
        cin >> N;
        
        long long *setOrig = new long long[N+1];
        for (long i = 0; i < N; i++) {
            cin >> setOrig[i];
        }
        
        long long *setsTmp = new long long[N + 1];
        
        sum = 0;
        
        myPowerSetSum(setOrig, setsTmp,0,0,N);
        
        delete[] setsTmp;
        delete[] setOrig;
        
        cout << sum << endl;
        
        T--;
        
    } while (T > 0);
    
    
    return 0;
    
}

#elif defined USING_MAIN_2

/*
 Solution 2. Pass testcases 1 to 5 and 14. Have abort called to the rest of the test-cases
 
 Use modulo and divisor to find the subsets of a set.
 Ex. 
 SetOrig 1 2 3
 Loops on Order (Indices on the left) :
 0 0 0  | 0 0 0
 1 0 0  | 1 0 0
 0 1 0  | 0 2 0
 1 1 0  | 1 2 0
 0 0 1  | 0 0 3
 1 0 1  | 1 0 3
 0 1 1  | 0 2 3
 1 1 1  | 1 2 3
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long sum;
long long MOD = 1000000007;

void myPowerSetInd(long long* SetOrig, long long** Set, long size) {
    
    long toloop;
    long numins;
    long numsets = pow(2, size);
    for (long i = 0; i < numsets; i++) {
        toloop = i;
        for (long j = 0; j < size; j++) {
            numins = toloop % 2;
            if (numins == 1) {
                numins = SetOrig[j];
            }
            else {
            }
            Set[i][j]=numins;
            toloop = toloop/2;
        }
    }
    return;
}


int main()
{
    int T;
    cin >> T;
    
    do
    {
        long N;
        cin >> N;
        
        long long *setOrig = new long long[N+1];
        for (long i = 0; i < N; i++) {
            cin >> setOrig[i];
        }
        
        long numsets = pow(2, N);
        long long** set = new long long*[numsets+1];
        for (long i = 0; i < numsets; ++i)
            set[i]= new long long[N+1];
        
        myPowerSetInd(setOrig,set,N);
        
        delete [] setOrig;
        
        sum = 0;
        
        long long m;
        for (long i = 0; i < numsets; i++) {
            m = 0;
            for (long j = 0; j < N; j++) {
                m = m^set[i][j];
                //cout << set[i][j] << ' ';
            }
            sum = (sum + m) % MOD;
            //cout << endl;
        }
        
        for (long i = 0; i < numsets; ++i)
            delete [] set[i];
        delete [] set;
        
        cout << sum << endl;
        
        T--;
        
    } while (T > 0);
    
    return 0;
}


#else


/*
 Solution 3 using permutations. Have two codes below
 */


//3a) Solution tried using vectors and function prev_permutation from algorithm library. Pass testcases 1 to 5 and 14. Others Terminated due to Timeout. Hacckerank has a max limit of 2,72 secs for each testcase

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sum;
long long MOD = 1000000007;

void myPowersetSum(vector<int> &arr, vector<vector<int>> &comb) {
    if (arr.empty()) return;
    
    int counterloop = 0;
    for (int i = 0; i < arr.size(); i++) {
        vector<int> arrloop(i+1,1);
        arrloop.resize(arr.size(),0);
        
        /*
         for (int j = 0; j < arrloop.size(); j++) {
         cout << arrloop[j] << ' ';
         }
         cout << endl;
         */
        
        int lastcounter = counterloop;
        
        do {
            vector<int> tmploop;
            for (int l = 0; l < arr.size(); l++) {
                if (arrloop[l] == 1) tmploop.push_back(arr[l]);
            }
            comb.push_back(tmploop);
            counterloop+=1;
        } while (prev_permutation(arrloop.begin(),arrloop.end()));
        
        ///*
        //cout << lastcounter << ' ' << counterloop << endl;
        //*/
        
        /*
         for (const vector<int> &v : comb)
         {
         for (int x : v) cout << x << ' ';
         cout << endl;
         }
         */
        
        /*
         for (int i = lastcounter; i < counterloop; i++) {
         for (int j = 0; j < comb[i].size(); j++) {
         cout << comb[i][j] << ' ';
         }
         cout << endl;
         }
         */
        
        long long m;
        for (int i = lastcounter; i < counterloop; i++) {
            m = 0;
            for (int j = 0; j < comb[i].size(); j++) {
                m = m^comb[i][j];
            }
            //cout << m << ' ';
            sum = (sum + m) % MOD;
        }
        
        
    }
    
    return;
}

int main()

{
    int T;
    
    cin >> T;
    
    
    do
        
    {
        int N;
        
        cin >> N;
        
        vector<int> arr(N);
        
        for (int i = 0; i < arr.size(); i++) {
            cin >> arr[i];
        }
        
        vector<vector<int>> comb;
        
        sum = 0;
        
        myPowersetSum(arr, comb);
        
        cout << sum << endl;
        
        T--;
        
    } while (T > 0);
    
    return 0;
    
}


//3b) Solution tried using Permutation and Set object to allocate unique combinations. Pass testcases 1, 2, 4 and 14. Others Terminated due to Timeout. Hacckerank has a max limit of 2,72 secs for each testcase

/*

#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> myset;
typename set<vector<int>>::iterator it;
long long sum;
long long MOD = 1000000007;

void permute(int setOrig[], int set[], int init, int end) {
    
    if (init == end) {
        vector<int> v0= vector<int>(end+1);
        
        
        for (int i = 0; i <= end; i++) {
            v0[i] = set[i];
            if (v0[i] == 1) v0[i] = setOrig[i];
        }
        
        
        myset.insert(v0);
        
        return;
    }
    
    int j = init;
    for (int i = init; i <= end; i++) {
        int temp = set[j];
        set[j] = set[i];
        set[i] = temp;
        
        permute(setOrig, set, j + 1, end);
        
        temp = set[i];
        set[i] = set[j];
        set[j] = temp;
    }
    
    return;
}

int main()
{
    int T;
    cin >> T;
    
    do
    {
        int N;
        cin >> N;
        
        int *setOrig=new int [N];
        
        for (int i = 0; i < N; i++) {
            cin >> setOrig[i];
        }
        
        int *set = new int[N]();
        
        for (int j = 0; j < N; j++) {
            set[j] = 1;
            permute(setOrig, set, 0, N - 1);
        }
        
        delete[] set;
        delete[] setOrig;
        
        sum = 0;
        long long m;
        for (it = myset.begin(); it != myset.end(); it++) {
            const vector<int>& i = (*it);
            
            m = 0;
            for (int j = 0; j <= N-1; j++) {
                m = m^i[j];
            }
            sum = (sum + m) % MOD;
            
            //cout<<myset.size()<<endl;
            
            //for (int j = 0; j <= N-1; j++) {
            //cout << i[j] << ' ';   //cout << i[0] << endl;
            //}
            //cout << endl;
        }
        
        cout << sum << endl;
        
        myset.clear();
        
        T--;
        
    } while (T > 0);
    
    return 0;
}

*/

#endif // USING_MAIN_1
