//
//  https://www.hackerrank.com/challenges/insertion-sort
//
//  Insertion_Sort_Advanced_Analysis.cpp
//  HacckerrankCpp
//

//Sent two solutions

#define USING_MAIN_1

#ifdef USING_MAIN_1

/*
 Solution 1. Using Binary Index Tree. Topcoder website has a good article about it
 
 */

#include <iostream>
#include <cmath>        //pow
#include <algorithm>  //fill_n

using namespace std;

class BinaryIndexTree {
private:
    long MaxVal;
    int *arrclass;
    
public:
    BinaryIndexTree() {}
    BinaryIndexTree(long x) { MaxVal = x - 1; arrclass = new int[x]; fill_n(arrclass, x, 0); }
    
    ///*
    void update(int idx, int val) {
        while (idx <= MaxVal) {
            arrclass[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    int read(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += arrclass[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    //*/
    
    ~BinaryIndexTree() { delete[] arrclass; }
};

int main()

{
    
    int T;
    
    cin >> T;
    
    
    do
        
    {
        int N;
        
        cin >> N;
        
        int *arr = new int[N];
        
        for (int i = 0; i < N; i++)
            
            cin >> arr[i];
        
        long counter = 0;
        
        BinaryIndexTree BITCounter(pow(10, 7) + 1);
        
        for (int i = N - 1; i >= 0; i--) {
            BITCounter.update(arr[i], 1);
            counter += BITCounter.read(arr[i] - 1);
        }
        
        delete[] arr;
        
        cout << counter << endl;
        
        T--;
        
    } while (T > 0);
    
    
    return 0;
    
}


#else


/*
 Solution 2. Using Merge Sort...
 
 I do the Merge Sort approach efficiently, I miss the number of shifts. I pass the sample testcases and testcase 10 with all the Tries below.
 One can use it for the time beeing to determine correctly the number of shifts as the sort ascending order is correct !!
 
 I have tried using three methods :
 Try 1 to subtract from middle the sort ascending elements shifts
 and
 Try 2 to subtract from the already placed right array (middle to upperbound) the sort ascending elements shifts
 and
 Try 3 counts your sort descending comparisons (j), adds it up to your countertmp when a sort ascending comparison appears.
 This is needed so to subtract your ascending orders (i)(no shifts needed) from your descending ones. Thus if i, your
 counter for the ascending orders is zero, means that only the j descending orders count as upon multiplication thereafter
 results that there are no any elements left from the left array (lowerbound to middle)
 */

#include <iostream>

using namespace std;

long counter;
int arr[10000001], arrhelp[10000001], N;

long merge_sort(int lowerbound, int upperbound) {
    
    if ((upperbound - lowerbound) <= 1) {
        
        //cout << 0 << endl;
        
        return 0;
        
    }
    
    
    if ((upperbound - lowerbound) == 2) {
        
        if (arr[lowerbound] > arr[lowerbound + 1]) {
            
            int tmp = arr[lowerbound];
            
            arr[lowerbound] = arr[lowerbound + 1];
            
            arr[lowerbound + 1] = tmp;
            
            //cout << "1" << endl;
            
            return 1;  //the pos difference between first (lowerbound) and second number (lowerbound + 1)
            //ex. testcase array 2 - merge_sort(0, 2) has counter 1
            
        }
        
        //cout << 0 << endl;
        
        return 0;
        
    }
    
    
    int middle;
    
    middle = lowerbound + (int)((upperbound - lowerbound) / 2);
    
    counter += merge_sort(lowerbound, middle); //ex. testcase array 2 - merge (0, 2) comes first
    
    counter += merge_sort(middle, upperbound); //ex. testcase array 2 - merge(3, 5) comes second, merge(2, 5) comes third
    
    
    int index = lowerbound;
    
    int LBtoM = lowerbound;
    
    int MtoUB = middle;
    
    int resizeUB = ((upperbound == N) ? upperbound - 1 : upperbound);
    
    long countertmp = 0;
    
    //long myhelp = 0;  //myhelp is on Try 2
    
    //long i = 0, j = 0; //i and j is on Try 3
    
    while ((LBtoM < middle) && (MtoUB <= resizeUB)) {
        
        if (arr[LBtoM] <= arr[MtoUB]) //if is sort ascending or equal number
            
        {
            //countertmp+=j; //Try 3
            
            arrhelp[index] = arr[LBtoM];
            
            LBtoM++;
            
            //myhelp++;  //Try 2
            
            //i++;  //Try 3
            
        }
        
        else if (arr[LBtoM] > arr[MtoUB])   //if is sort descending
            
        {
            
            arrhelp[index] = arr[MtoUB];
            
            countertmp += middle - LBtoM;  //Try 1
            
            ////countertmp += 1;
            
            MtoUB++;
            
            //j++; //Try 3
            
        }
        
        index++;
        
    }
    
    //countertmp = ((MtoUB == N) ? resizeUB : MtoUB) - lowerbound - myhelp; //Try 2
    
    //countertmp+=j*((middle-lowerbound)-i);  //Try 3
    
    
    while (LBtoM < middle) {
        
        arrhelp[index] = arr[LBtoM];
        
        index++;
        
        LBtoM++;
        
    }
    
    
    while (MtoUB <= resizeUB) {
        
        arrhelp[index] = arr[MtoUB];
        
        index++;
        
        MtoUB++;
        
    }
    
    
    int loopRnders;
    
    for (loopRnders = lowerbound; loopRnders <= resizeUB; loopRnders++) {
        
        arr[loopRnders] = arrhelp[loopRnders];
        
        //cout << arr[loopRnders];
        
    }
    
    //cout << "\n";
    
    //cout << countertmp << endl; //ex. testcase array 2 - merge_sort(2, 5) has counter 2 and merge_sort(0, 5) has counter 1
    
    return countertmp;
    
}


void inputarr(int arr[], int size) {
    
    for (int i = 0; i < size; i++)
        
        cin >> arr[i];
    
    return;
    
}


int main()

{
    
    int T;
    
    cin >> T;
    
    
    do
        
    {
        
        arr[10000000] = { 0 };
        
        arrhelp[10000000] = { 0 };
        
        cin >> N;
        
        inputarr(arr, N);
        
        counter = 0;
        
        counter+= merge_sort(0, N); //ex. testcase array 2 - merge_sort(0, 5) comes fourth
        
        cout << counter << endl;
        
        //for (int i = 0; i < N; i++)
        
        //cout << arr[i] << " ";
        
        
        T--;
        
    } while (T > 0);
    
    
    return 0;
    
}


#endif // USING_MAIN_1
