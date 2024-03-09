//Oliver Falchettore
// 2/22/24
//8 queens backtracking with 1D array
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int q[8], c = 0, sol_num = 1;
    q[0] = 0;
	
    nc: c++;
	if (c == 8) goto print;
	q[c] = -1; // r = -1
	
    nr: q[c]++;
	if (q[c] == 8) goto backtrack;
		

	//row testing
	for (int i = 0; i < c; i++){
	    if ((q[i] == q[c]) || ((c - i) == (abs(q[c] - q[i])))){
		goto nr;
	    }
	}
		
	//good!!
	goto nc;
	
    backtrack:
	c--;
	if(c == -1) return 0;
	goto nr;
		
    print:
	//prints the solution once c = 8
	cout << "Solution #" << sol_num++ << endl;
	for (int i = 0; i < 8; i++){
	    for (int j = 0; j < 8; j++){
		if (q[j] == i){
		    cout << "[Q]";
		}else{
		    cout << "[ ]";
		}
	    }
	    cout << endl;
	}
		
	cout << endl;
	goto backtrack;
}

