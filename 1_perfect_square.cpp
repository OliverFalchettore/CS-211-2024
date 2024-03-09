//Oliver Falchettore
//Project 1: Perfect squares

#include <iostream>
using namespace std;


int main(){
	bool last_two_odd = false;

	int i = 0, square = 0;

	while (!last_two_odd){
		//performs the math
		square = i * i;

		//grabs the two right most numbers
		int first_last = square % 10;
		int second_last = (square / 10) % 10;

		//check if the perfect square number last two digits are true
		if ((first_last % 2 == 1) && (second_last % 2 == 1)){
			last_two_odd = true;
		}

		//increments for next iteration
		i++;
	}

	//outputs the answer
	cout << i << " * " << i << " = " << square << endl;
	cout << "The first perfect square (i*i) whose last two digits are both odd: " << square << endl;

	return 0;
}
