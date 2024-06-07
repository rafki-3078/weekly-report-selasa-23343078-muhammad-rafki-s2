#include <stdio.h>

int main() {
	
	int nil[3]; 
	
	nil[0] = 80;
	nil[1] = 85; 
	nil[2] = 90;
	
	int rr = (nil[0] + nil[1] + nil[2]) / 3; 
	
	printf("The average of the 3 grades is: %d\n", rr); 
	
	return 0;
}
