//Oliver Falchettore
//Project: Eight Queens Problem - Dump
//2/11/2024
#include <iostream>
using namespace std;



// Function to check if a queen can be placed at (row, col) without conflicts
bool OK(int memo[]) {
    //traverse all the elements in the 1D array
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            // Check for conflicts in rows and diagonals
            if ((memo[i] == memo[j]) || ((memo[i] - memo[j]) == (i - j)) || ((memo[i] - memo[j]) == (j - i))) {
                return false;
            }
        }
    }
    return true;
}

// Function to print the board configuration
void PRINT(int memo[]) {
    //traverse the 8 rows
    for (int i = 0; i < 8; i++) {
    	//traverse the 8 rows
        for (int j = 0; j < 8; j++) {
	    // the labeled row in current column
            if (memo[j] == i) { 
                cout << "Q"; // place a queen
            } else {
                cout << "*"; // Empty cell
            }
        }
        cout << endl;
    }
    cout << endl;
}


//the Four Queens Problem using brute force
int main() {

    int N = 8;
	
    int memo[N] = {0}; // Initialize the board
    
    int solution_num = 1;

    // Use multiple-level nested loops to generate all possible placements
    for(int rowInCol0 = 0; rowInCol0 < N; rowInCol0++){
        memo[0] = rowInCol0;
        for(int rowInCol1 = 0; rowInCol1 < N; rowInCol1++){
            memo[1] = rowInCol1;
            for(int rowInCol2 = 0; rowInCol2 < N; rowInCol2++){
                memo[2] = rowInCol2;
                for(int rowInCol3 = 0; rowInCol3 < N; rowInCol3++){
                    memo[3] = rowInCol3;
                    for(int rowInCol4 = 0; rowInCol4 < N; rowInCol4++){
                        memo[4] = rowInCol4;
                        for(int rowInCol5 = 0; rowInCol5 < N; rowInCol5++){
                            memo[5] = rowInCol5;
                            for(int rowInCol6 = 0; rowInCol6 < N; rowInCol6++){
                                memo[6] = rowInCol6;
                                for(int rowInCol7 = 0; rowInCol7 < N; rowInCol7++){
                                    memo[7] = rowInCol7;
                               
                                    //validate
                                    if(OK(memo)){
                                    	//counter for solution number
                                    	cout << "Solution #" << solution_num << endl; 
                                        PRINT(memo);
                                        //count the correct solutions
                                        solution_num++; 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
    
    return 0;
}
