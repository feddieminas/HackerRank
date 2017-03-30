//
//  https://www.hackerrank.com/challenges/find-strings?h_r=internal-search
//
//  Find_Strings.cpp
//  HacckerrankCpp
//


/*
 Solution. Passed sample test plus two out of seven testcases.Could pass at least other two testcases but I have a segmentation fault.
 Segmentation fault should be on my string y declared and assign. Pls advise
 
 Attrs:
 lrank(lr) : the rank of sa
 suffix array(sa) : ordered sa of chars of the string
 lcp : lcp of sa strings
 length of sastr(lstr) : order length of individual strings substrings
 
 One String
 ex. banana1
 lr   4 3 6 2 5 1 0
 sa   6 5 3 1 0 4 2
 lcp  0 0 1 3 0 0 2
 lstr 0 1 3 5 6 2 4
 
 Two String
 ex. aab2aac1
 lr   2 4 6 1 3 5 7 0
 sa   7 3 0 4 1 5 2 6
 lcp  0 0 0 2 1 1 0 0
 lstr 0 0 3 3 2 2 1 1
 
 Reference help :
 Esteban Arango Medina github
 https://discuss.codechef.com/questions/21385/a-tutorial-on-suffix-arrays
 https://www.careercup.com/question?id=3315662
 https://www.quora.com/Given-a-string-how-do-I-find-the-number-of-distinct-substrings-of-the-string
 http://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
 */


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

string A;

struct saAttrs
{
    int nr[2];
    int p;
} L[2001];

int P[12][2001]; //rnks
int N, i;
int stp, cnt;

int cmp(struct saAttrs a, struct saAttrs b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1]<b.nr[1] ? 1 : 0) : (a.nr[0]<b.nr[0] ? 1 : 0);
}

int LCP(string a, string b)
{
    int counter = 0;
    for (int ii = 0; ii < max(a.length(), b.length()); ii++)
    {
        if (a[ii] == b[ii])
            counter++;
        else
            break;
    }
    return counter;
}

int main()
{
    
    int T, testc;
    cin >> T;
    
    string tmpA;
    for (testc = 0; testc < T; testc++) {
        cin >> tmpA;
        A += tmpA;
        A += char(T - testc);
    }
    
    N = A.length();
    
    for (i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';
    
    for (stp = 1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for (i = 0; i < N; i++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        
        sort(L, L + N, cmp);
        
        for (i = 0; i < N; i++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
        
    }
    
    vector<int> lrank(N);     //4 3 6 2 5 1 0 for banana
    vector<int> sa;           //6 5 3 1 0 4 2 for banana
    vector<string> sastr;     //a ana anana banana na nana for banana
    vector<int> sastrlen(N);  //0 1 3 5 6 2 4 sastr length for banana
    
    string y;
    for (i = 0; i < N; i++) {
        sa.push_back(L[i].p);
        lrank[L[i].p] = i;
        
        y="";
        for (int j = sa[i]; j < N; j++) {
            y += A[j];
        }
        sastr.push_back(y); //if more than one strings not necessary correct strings but those strings create me a correct lcp below
    }
    
    for (int j = N - 1, ac = 1; j >= 0; --j) {
        if (A[j] < 'a') ac = 0;
        sastrlen[lrank[j]] = ac;  //0 1 3 5 6 2 4 for banana
        ac++;
    }
    
    /*
     cout << "p " ;
     for (i = 0; i < N; i++) {
     cout << lrank[i] << " ";
     }
     cout << endl;
     
     cout << "r ";
     for (i = 0; i < N; i++) {
     cout << sa[i] << " ";
     }
     cout << endl;
     */
    
    vector<int> lcp; //0 0 1 3 0 0 2 for banana
    lcp.push_back(0);
    for (i = 1; i < N; i++)
    {
        lcp.push_back(LCP(sastr[i - 1], sastr[i]));
    }
    //lcp.push_back(0);
    
    //vector<string>().swap(sastr);
    
    /*
     cout << "h ";
     for (i = 0; i < N; i++) {
     cout << lcp[i] << " ";
     }
     cout << endl;
     
     cout << "l ";
     for (i = 0; i < N; i++) {
     cout << sastr[i] << "  ";
     }
     cout << endl;
     
     cout << "lstr ";
     for (i = 0; i < N; i++) {
     cout << sastrlen[i] << " ";
     }
     cout << endl;
     */
    
    cin >> T;
    while (T--) {
        cin >> testc; //k
        for (i = 0; i < N; i++) {
            int comp = sastrlen[i] - lcp[i];
            if (comp >= testc) {
                cout << A.substr(sa[i], lcp[i] + testc) << endl;
                break;
            }
            else
                testc = testc - comp;
        }
        if (i == N)
            cout << "INVALID" << endl;
    }
    
    return 0;
}



/*
 Code below works for one string (ex. S1 aab or SS2 aac), no union strings as the challenge requests later (S1 U S2)
 
 Useful to understand the concepts of suffix and lcp array
 
 Attrs:
 lrank(lr) : the rank of sa
 suffix array(sa) : ordered sa of chars of a string
 lcp : lcp of sa strings
 length of sastr(lstr) : order length of individual strings substrings
 
 One string
 ex. banana
 lr   4 3 6 2 5 1
 sa   5 3 1 0 4 2
 lcp  1 3 0 0 2 0
 lstr 1 3 5 6 2 4
*/


/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

string A;

struct saAttrs
{
    int nr[2];
    int p;
} L[2001];

int P[12][2001]; //rnks
int N, i;
int stp, cnt;

int cmp(struct saAttrs a, struct saAttrs b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1]<b.nr[1] ? 1 : 0) : (a.nr[0]<b.nr[0] ? 1 : 0);
}

int LCP(string a, string b)
{
    int counter = 0;
    for (int ii = 0; ii < max(a.length(), b.length()); ii++)
    {
        if (a[ii] == b[ii])
            counter++;
        else
            break;
    }
    return counter;
}

int main()
{
    
    int T, testc;
    cin >> T;
    
    string tmpA;
    for (testc = 0; testc < T; testc++) {
        cin >> tmpA;
        A += tmpA;
        //A += char(T - testc);
    }
    
    N = A.length();
    
    for (i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';
    
    for (stp = 1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for (i = 0; i < N; i++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        
        //banana
        //5 1 3 0 2 4
        //5 3 1 0 4 2
        //5 3 1 0 4 2
        sort(L, L + N, cmp);
        
        //for (i = 0; i < N; i++) {
        //cout << L[i].p << " ";
        //}
        //cout << endl;
        
        //banana
        //0 1 2 3 4 5 index
        //3 1 4 1 4 0 or 0 1 1 3 4 4 PArray rank
        //3 2 5 1 4 0 or 0 1 2 3 4 5
        //3 2 5 1 4 0 or 0 1 2 3 4 5
        for (i = 0; i < N; i++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
        
        //for (i = 0; i < N; i++) {
        //cout << P[stp][L[i].p] << " ";
        //}
        //cout << endl;
        
    }
    
    vector<int> lrank(N);  //4 3 6 2 5 1 for banana
    vector<int> sa;        //5 3 1 0 4 2 for banana
    vector<string> sastr;  //a ana anana banana na nana for banana
    vector<int> sastrlen;  //1 3 5 6 2 4 sastr length for banana
    
    for (i = 0; i < N; i++) {
        sa.push_back(L[i].p);
        //cout << sa[i] << " ";
        lrank[L[i].p] = i + 1; //or i+1
        
        string y;
        for (int j = sa[i]; j < N; j++) {
            y += A[j];
        }
        //cout << y << endl;
        sastr.push_back(y);
        sastrlen.push_back(y.length());
    }
    //cout << endl;
    
    ///*
    
    cout << "p ";
    for (i = 0; i < N; i++) {
        cout << lrank[i] << " ";
    }
    cout << endl;
    
    cout << "r ";
    for (i = 0; i < N; i++) {
        cout << sa[i] << " ";
    }
    cout << endl;
    
    
    vector<int> lcp; //1 3 0 0 2 0 for banana
    for (i = 1; i < N; i++)
    {
        lcp.push_back(LCP(sastr[i - 1], sastr[i]));
    }
    lcp.push_back(0);
    
    
    cout << "h ";
    for (i = 0; i < N; i++) {
        cout << lcp[i] << " ";
    }
    cout << endl;
    
    cout << "l ";
    for (i = 0; i < N; i++) {
        cout << sastr[i] << " ";
    }
    cout << endl;
    
    cout << "lstr ";
    for (i = 0; i < N; i++) {
        cout << sastrlen[i] << " ";
    }
    cout << endl;
    
    
    cin >> T; //testcases of finding values
    while (T--) {
        cin >> testc; //k
        testc = testc - 1;
        for (i = 0; i < N; i++) {
            int comp = sastrlen[i] - lcp[i];
            if (comp >= testc) {
                cout << A.substr(sa[i], lcp[i] + testc) << endl;
                break;
            }
            else
                testc = testc - comp + lcp[i];
        }
        
        if (i == N)
            cout << "INVALID" << endl;
    }
    
    
    return 0;
}
 
*/


