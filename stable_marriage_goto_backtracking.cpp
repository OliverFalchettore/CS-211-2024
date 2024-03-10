#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Define men's preferences
    static int mp[3][3] = { {0,2,1},  // 0  Men's preferences
                            {0,2,1},  // 1
                            {1,2,0}}; // 2
    // Define women's preferences
    static int wp[3][3] = { {2,1,0},  // 0  Women's preferences
                            {0,1,2},  // 1
                            {2,0,1}}; // 2

    // Initialize variables
    
    /*
	c = new man
	q[c] = new women
	q[i] = old women
	i = old man
	*/
    
    int c = 0;            // Counter variable
    static int sol_num = 0; // Counter for solutions found
    int q[3] = {0};       // Array to store solutions

    // Start of backtracking algorithm
    nextMan: 
        c++; // Move to next man
        if(c == 3) goto print; // If all men are assigned partners, print solution
        q[c] = -1; // Initialize woman for current man

    nr: 
        q[c]++; // Move to next woman for current man
        if (q[c] == 3) goto backtrack; // If all women are tried, backtrack

        // Check if the current assignment violates any conditions
        for (int i = 0; i < c; i++) {
            if (q[i] == q[c]                                              
                || mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]  
                || mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) {
                    goto nr; // If condition is violated, try next woman
            }
        }

        goto nextMan; // If conditions are met, move to next man

    backtrack: // Backtrack step
        c--; // Move back to previous man
        if (c == -1) return 0; // If all solutions are found, exit
        goto nr; // Try next woman for previous man

    print: // Printing the solution
        cout << "Solution #" << ++sol_num << ":\nMan\tWoman\n";

        // Print the assignments
        for (int i = 0; i < 3; ++i)
            cout << i << "\t" << q[i] << "\n";
        cout << "\n";

        cout << endl;
        goto backtrack; // Continue searching for more solutions

    return 0;
}

