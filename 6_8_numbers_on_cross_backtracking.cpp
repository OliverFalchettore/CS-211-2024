#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int q[8] = {0}; 
	int cb = -1, sol_num = 0; // cb = current box
	
	static int a[8][5] = {{-1}, //0
						{0, -1}, // 1
						{0, -1}, // 2
						{0, 1, 2, -1}, // 3
						{0, 1, 3, -1}, // 4
						{1, 4, -1}, // 5
						{2, 3, 4, -1}, // 6
						{3, 4, 5, 6, -1} // 7
					  };
	
	
	q[cb] = 1;
	
	nextBox: cb++;
		if (cb == 8) goto print;
		q[cb] = -1; 

	nr: q[cb]++;
		if (q[cb] == 8) goto backtrack;
		
		//if other boxes have the same number
		for (int i = 0; i < cb; ++i){ // If the number in square c has already been used, return false.
			if (q[cb] == q[i])
				goto nr;
		}
		
		//adjacent check
		for (int i = 0; a[cb][i] != -1; i++){
			if (abs(q[cb] - q[a[cb][i]]) == 1){
				goto nr;
			}
		}
			
		goto nextBox;
		
				
		
	backtrack:
		cb--;
		if (cb == -1) return 0;
		goto nr;

	print:
		cout << "Solution #" << ++sol_num << endl;
		cout << "   " << "[" << q[0]+1 << "]" << "["<< q[1]+1 << "]" << endl;
		cout << "[" << q[2]+1 << "]" << "[" << q[3]+1 << "]" << "["<< q[4]+1 << "]" << "[" << q[5]+1 << "]" << endl;
		cout << "   " << "[" << q[6]+1 << "]" << "["<< q[7]+1 << "]" << endl;
		
		cout << endl;
		goto backtrack;

}
