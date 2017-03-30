//
//  https://www.hackerrank.com/challenges/matrix-rotation-algo
//
//  Matrix_Layer_Rotation.cpp
//  HacckerrankCpp
//

//Sent two solutions

#define USING_MAIN_1

#ifdef USING_MAIN_1

/*
 Solution 1. Fully accepted because it reached the max of 2.52 seconds Hacckerrank requires
 
 You use only a single matrix (i.e. arrsourcemat) loop through numRounds (as per below example by swapping)
 rotating
 1) top row (left to right)
 2) right column (from top to bottom)
 3) bottom row (from right to left)
 4) Left column (from bottom to top)
 as a clock circle it will produce you the final rotated matrix (i.e. arrsourcemat) with no
 timeouts involved... Key is the numRoots which prevents number of rotations no needed to occur using the modulo function
 For ex. for a 4*4 matrix estimated one round has 12 rotations as its very outer ring. If you request 12 rotations the outer ring
 does not need to be rotated 12 times at its matrix stays the same
 */

#include <algorithm>
#include <iostream>

using namespace std;   //arrmat below act as arrsourcemat mentioned above

int main()  //main 1
{
    int M, N, R;
    cin >> M >> N >> R;
    
    int arrmat[300][300];
    
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arrmat[r][c];
        }
    }
    
    //int maxnum = max(M, N);
    int minnum = min(M, N);
    int numRounds = minnum / 2;
    
    for (int i = 0; i<numRounds; i++) {
        
        /*
         Tried worked for sample tests and 4 test cases
         //int numRots = (maxnum * 3) - (maxnum - minnum) - ((M + N-(maxnum - minnum))*i);
         //numRots = R % numRots;
         */
        
        //use number two as rows cols, 4 and 4 since are four sides (Top, Right, Bottom, Left). subtract as you go  towards inner ring.
        //Multiply with i, the lower the outer ring, the higher the inner ring
        int numRots = R % (2 * (M + N - 4 * i) - 4); //BlakeBrown
        
        for (int Rot = 0; Rot < numRots; Rot++) {
            //Top Row (Left to Right)
            for (int j = i; j < N - i - 1; j++) {
                int tmp = arrmat[i][j];
                arrmat[i][j] = arrmat[i][j + 1];
                arrmat[i][j + 1] = tmp;
            }
            
            //Right Column (From, top to bottom)
            for (int j = i; j < M - i - 1; j++) {
                int tmp = arrmat[j][N - i - 1];
                arrmat[j][N - i - 1] = arrmat[j + 1][N - i - 1];
                arrmat[j + 1][N - i - 1] = tmp;
            }
            
            //Bottom Row (from right to left)
            for (int j = N - i - 1; j > i; j--) {
                int tmp = arrmat[M - i - 1][j];
                arrmat[M - i - 1][j] = arrmat[M - i - 1][j - 1];
                arrmat[M - i - 1][j - 1] = tmp;
            }
            
            //Left column (from bottom to top)
            for (int j = M - i - 1; j > i + 1; j--) {
                int tmp = arrmat[j][i];
                arrmat[j][i] = arrmat[j - 1][i];
                arrmat[j - 1][i] = tmp;
            }
            
        }
        
    }
    
    //Conclusion
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cout << arrmat[r][c] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}


#else

/*
 Solution 2. Partially accepted as it did not reach the max of seconds Hacckerrank requires per Test Case
 
 M   N   R
 300 300 999999999 Terminated due to Timeout
 250 289 42971434 Terminated due to Timeout
 136 240 212131  Terminated due to Timeout
 Three timeouts out of 12 TestCases. Hackerrank requires max of 2,52 seconds per TestCase
 
 
 Created four matrices.
 arrrow shows the row indices single anti - clockwise rotation
 arrcol shows the col indices single anti - clockwise rotation
 arrsourcemat matrix to be rotated
 arrdestmat matrix rotated
 
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main()  //main 2
{
    int M, N, R;
    cin >> M >> N >> R;
    
    //My Rows anc Cols to be Rotated by One Index
    int arrrow[300][300], arrcol[300][300];
    
    //Insert Current Positon Row and Col Indices
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            arrrow[r][c] = r;
            arrcol[r][c] = c;
        }
    }
    
    int numRounds = min(M, N) / 2;
    
    //Loop for Row and Cols Indexes
    for (int i = 0; i<numRounds; i++) {
        
        //Left column
        for (int j = i; j<M - i - 1; j++) {
            int tmp = arrrow[j][i];
            arrrow[j][i] = arrrow[j + 1][i];
            arrrow[j + 1][i] = tmp;
            
            /*
             tmp = arrcol[j][i]; //cols no need a left col rotation
             arrcol[j][i] = arrcol[j + 1][i];
             arrcol[j + 1][i] = tmp;
             */
        }
        
        //Bottom Row
        for (int j = i; j<N - i - 1; j++) {
            int tmp = arrrow[M - i - 1][j];
            arrrow[M - i - 1][j] = arrrow[M - i - 1][j + 1];
            arrrow[M - i - 1][j + 1] = tmp;
            
            tmp = arrcol[M - i - 1][j];
            arrcol[M - i - 1][j] = arrcol[M - i - 1][j + 1];
            arrcol[M - i - 1][j + 1] = tmp;
        }
        
        //Right Column
        for (int j = M - i - 1; j>i; j--) {
            if (j > i + 1) {
                int tmp = arrrow[j][N - i - 1]; //j>i+1 for rows
                arrrow[j][N - i - 1] = arrrow[j - 1][N - i - 1];
                arrrow[j - 1][N - i - 1] = tmp;
            }
            
            int tmp = arrcol[j][N - i - 1];     //j>i for cols
            arrcol[j][N - i - 1] = arrcol[j - 1][N - i - 1];
            arrcol[j - 1][N - i - 1] = tmp;
        }
        
        
        //Top Row
        for (int j = N - i - 1; j>i + 1; j--) {
            /*
             int tmp=arrrow[i][j]; //rows no need a top row rotation
             arrrow[i][j]=arrrow[i][j-1];
             arrrow[i][j-1]=tmp;
             */
            
            int tmp = arrcol[i][j];
            arrcol[i][j] = arrcol[i][j - 1];
            arrcol[i][j - 1] = tmp;
        }
    }
    
    int arrsourcemat[300][300], arrdestmat[300][300];
    
    //Input your Source Matrix
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arrsourcemat[r][c];
        }
    }
    
    //int numRots = (max(M, N) * 3) - (max(M, N) % 2); //estimated one round are x rotaions. For ex. a 4*4 mat has one round 12 rotaions
    //numRots = R % numRots;
    for (int Rot = 1; Rot <= R; Rot++) {
        //Insert to Dest Matrix
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                arrdestmat[arrrow[r][c]][arrcol[r][c]] = arrsourcemat[r][c];
            }
        }
        
        //Rotations.. Insert your Dest matrix to Source Matrix for further rotations if requested
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                arrsourcemat[r][c] = arrdestmat[r][c];
            }
        }
    }
    
    //Conclusion
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cout << arrdestmat[r][c] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

#endif
