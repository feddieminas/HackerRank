//
//  https://www.hackerrank.com/challenges/oil-well?h_r=internal-search
//
//  Oil_Well.cpp
//  HacckerrankCpp
//

//Sent two solutions

/*
 Solution 1. Pass testcases 0, 1, 2 and 3. Testcases 4,5 and 9 shows Wrong Answer and rest testcases Terminated due to Timeout. Hacckerrank allows max of 2,72 secs
 
 Method using :
 1) bring max distances x to the end and lower distances x to the beginning
 2) bring max distances x to last before end and lower distances x to the beginning
 */


#define USING_MAIN_1

#if defined USING_MAIN_1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> onecoords;

inline void swap(vector<onecoords>& v1s,int x,int y) {
    onecoords temp;
    temp = v1s[y];
    v1s[y] = v1s[x];
    v1s[x] = temp;
}

void swapMaxMin(vector<onecoords>& v1scopy, vector<onecoords> v1s, int x, int y, int foundmaxsmins) {
    onecoords temp = v1s[x];
    for (int i = 0; i < y - foundmaxsmins; i++)
        v1scopy[i] = v1scopy[i + 1];
    v1scopy[y - foundmaxsmins] = temp;
}

inline int mydistance(vector<onecoords> v1s, int pointerj, int pointeri) {
    return (max(abs(v1s[pointerj].first - v1s[pointeri].first), abs(v1s[pointerj].second - v1s[pointeri].second)));
}

int retcalc(vector<onecoords> v1scopy, int vs1size) {
    int mymaxdist = 0, mytmpmaxdist = 0;
    int ret = 0, j = 1;
    while (j < vs1size)
    {
        mytmpmaxdist = 0;
        for (int i = 0; i < j; i++) {
            mymaxdist = mydistance(v1scopy, j, i);
            if (mymaxdist > mytmpmaxdist) {
                mytmpmaxdist = mymaxdist;
            }
            
        }
        
        ret += mytmpmaxdist;
        j++;
    }
    
    //cout << ret << endl;
    
    return ret;
}

int main()
{
    int h, v;
    int Grid[51][51];
    
    cin >> h >> v;
    
    vector<onecoords> v1s;
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < v; j++) {
            cin >> Grid[i][j];
            if (Grid[i][j] == 1) {
                onecoords mypair = make_pair(i + 1, j + 1);
                v1s.push_back(mypair);
            }
        }
    
    if (v1s.empty()) {
        cout << int(0) << endl;
        return 0;
    }
    
    int vs1size = v1s.size();
    
    /*
     cout << "vPairs" << endl;
     for (int i = 0; i < vs1size; i++)
     cout << v1s[i].first << v1s[i].second << endl;
     cout << endl;
     */
    
    int finalcost = 1000000;
    v = 0;
    while (v<vs1size) {
        
        swap(v1s, v, vs1size - 1);
        
        vector<onecoords> v1scopy(v1s);
        
        /*
         cout << "vInit " << v << endl;
         for (int i = 0; i < vs1size; i++)
         cout << v1scopy[i].first << v1scopy[i].second << " ";
         cout << endl;
         */
        
        int mymaxdist, mytmpmaxdist = 0, foundmins = 0;
        int foundmaxs = -1;  //1)
        //int foundmaxs = 0; //2) if uncomment this, then comment the above //1) and vice versa
        
        mytmpmaxdist = 0;
        int j = vs1size - 1, ret=0;
        
        ret = retcalc(v1scopy, vs1size);
        if (finalcost > ret) finalcost = ret;
        
        for (int i = 0; i < j; i++) {
            mymaxdist = mydistance(v1s,j,i);
            if (mymaxdist >= mytmpmaxdist) {
                mytmpmaxdist = mymaxdist;
                swapMaxMin(v1scopy, v1s, i, j, 0);    //1)
                //swapMaxMin(v1scopy, v1s, i, j, 1);  //2) if uncomment this, then comment the above //1) and vice versa
                foundmaxs++;
                
            }
            else if (mymaxdist < mytmpmaxdist) {
                foundmins++;
                swapMaxMin(v1scopy, v1s, i, j, foundmaxs + foundmins);
            }
            
            /*
             cout << "vLoop " << v << endl;
             for (int i = 0; i < vs1size; i++)
             cout << v1scopy[i].first << v1scopy[i].second << " ";
             cout << endl;
             */
            
            ret = retcalc(v1scopy, vs1size);
            if (finalcost > ret) finalcost = ret;
        }
        
        swap(v1s, vs1size - 1,v);
        
        v++;
    }
    
    cout << finalcost << endl;
    
    return 0;
    
}


#else

/*
 Solution 2. Pass testcases 0, 1 and 3 as the others Terminated due to Timeout. Hacckerrank allows max of 2,72 secs
 
 similar idea to the below published by jiayuanmark using structs as pairs rather than pairs as per below
 idea below to the normal resurse is to do inner loops having the upperbound value as constant. Key for it is the 'const int& init' parameter
 Thus for ex. testcase 0 : 11 21 33 can swap index 0 to 2 and then consequently index 1 to 2
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> onecoords;
int finalcost=0;

inline int mydistance(vector<onecoords> v1s, int pointerj, int pointeri) {
    return (max(abs(v1s[pointerj].first - v1s[pointeri].first), abs(v1s[pointerj].second - v1s[pointeri].second)));
}

void permute(vector<onecoords> v1s, const int& init, int end) {
    
    if (init == end+1) {
        
        /*
         for (int i = 0; i <= end; i++) {
         cout << v1s[i].first << ' ' << v1s[i].second << ' ';
         }
         cout << endl;
         */
        
        ///*
        int ret = 0;
        int j = 1;
        while (j < end + 1)
        {
            int mymaxdist = 0;
            for (int i = 0; i < j; i++) {
                if (mydistance(v1s, j, i)>mymaxdist) mymaxdist = mydistance(v1s, j, i);
            }
            
            ret+=mymaxdist;
            
            j++;
        }
        
        //cout << ret << endl;
        
        if (finalcost==0 || ret<finalcost) finalcost = ret;
        //*/
        
        return;
    }
    
    for (int i = init; i <= end; i++) {
        onecoords temp=v1s[init];
        v1s[init] = v1s[i];
        v1s[i] = temp;
        
        permute(v1s, init + 1, end);
        
        temp = v1s[init];
        v1s[init] = v1s[i];
        v1s[i] = temp;
        
        /*
         temp = v1s[i];   //the normal recurse
         v1s[i] = v1s[init];
         v1s[init] = temp;
         */
        
        /*
         //below helpful if u need subsets
         
         if (j == 0) cout << v1s[i].first << v1s[i].second << endl;
         
         if (j == 0 && i == 0) {
         for (int k = 0; k <= end; k++) {
         cout << v1s[k].first << v1s[k].second << ' ';
         }
         cout << endl;
         //return; //if we can stop there
         }
         */
    }
    
    return;
}

int main()
{
    int h, v;
    int Grid[51][51];
    
    cin >> h >> v;
    
    vector<onecoords> v1s;
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < v; j++) {
            cin >> Grid[i][j];
            if (Grid[i][j] == 1) {
                onecoords mypair = make_pair(i + 1, j + 1);
                v1s.push_back(mypair);
            }
        }
    
    
    int vs1size = v1s.size();
    
    permute(v1s, 0, vs1size-1);
    
    cout << finalcost << endl;
    
    return 0;
    
}

#endif // USING_MAIN_1