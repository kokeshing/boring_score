#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]){
	
	int times = 0;
	long tmp = 0;
	tmp = strtol(argv[1], NULL, 10);
	if(!(tmp > INT_MAX || tmp < INT_MIN)){
		times = (int)tmp;
	}
	
	int pinls[times]; 
	long result = 0;
	for(int i = 0; i < times; i++){
		result = strtol(argv[i+2], NULL, 10);
		if(!(result > INT_MAX || result < INT_MIN)){
			pinls[i] = (int)result;
		}
	}	

	int score = 0, count10 = 0, flame = 1;
	for(int i = 0; i < times; i++){
		if(pinls[i] == 10 && (i - count10) % 2 == 0 && flame != 10){
			flame++;
			count10++;

			score = score + 10 + pinls[i+1] + pinls[i+2];
		}else if(pinls[i-1] + pinls[i] == 10 && (i - count10) % 2 == 1 && flame != 10){
			flame++;

			score = score + 10 + pinls[i+1] - pinls[i-1];

		}else {
			if((i - count10) % 2 == 1){
				flame++;
			}

			score = score + pinls[i];
		}
	}	

	printf("%d\n", score);

	return 0;
}