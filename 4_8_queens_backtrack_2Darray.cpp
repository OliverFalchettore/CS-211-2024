// Oliver Falchettore
//8 queens backtracking
#include <iostream>
using namespace std;


int main() {
    // unformally initialize all elements to 0
    int b[8][8] = {0}, r = 0, c = 0;
	int sol_num = 1;
	
    // put the queen in the upper left square
    b[0][0] = 1;

    nc:  c++;
        if (c == 8) goto print;
        r = -1;

    nr:  r++;
        if (r == 8) goto backtrack;

        // row testing
        for (int i = 0; i < c; i++) {
            if (b[r][i] == 1) goto nr;
        }    
        
	// up diagonal test
        for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
            if (b[r - i][c - i] == 1) goto nr;
        }
            
	// down diagonal test	            			
	for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
            if (b[r + i][c - i] == 1) goto nr;
        }
        
        // place the queen
        b[r][c] = 1;
        goto nc;

    backtrack:
        c--;
        if (c == -1) return 0;
        r = 0;
        while (b[r][c] != 1) {
            r++;
        }
        b[r][c] = 0;
        goto nr;

    print:
    	cout << "Solution #" << sol_num++ << endl; 
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (b[i][j] == 1) {
                    cout << "[Q]";
                } else {
                    cout << "[ ]";
                }
            }
            cout << endl;
        }
        cout << endl;
        goto backtrack;
        
}
