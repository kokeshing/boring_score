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

	
	for(int i = 0; i < times; i++){
		printf("%d\n", pinls[i]);
	}
	

	int score = 0, count10 = 0, flame = 1;
	for(int i = 0; i < times; i++){
		if(pinls[i] == 10 && (i - count10) % 2 == 0 && flame != 10){
			printf("%d\n", flame);
			flame++;
			count10++;

			printf("score = %d + 10 + %d + %d\n", score, pinls[i+1], pinls[i+2]);

			score = score + 10 + pinls[i+1] + pinls[i+2];
		}else if(pinls[i-1] + pinls[i] == 10 && (i - count10) % 2 == 1 && flame != 10){
			printf("%d\n", flame);
			flame++;

			/*
			if(i + 1 == times){
				printf("score = %d + 10 + 0 - %d\n", score, pinls[i-1]);
				score = score + 10 + 0 - pinls[i-1];
			}else {
				printf("score = %d + 10 + %d - %d\n", score, pinls[i+1], pinls[i-1]);
				score = score + 10 + pinls[i+1] - pinls[i-1];
			}
			*/
			printf("score = %d + 10 + %d - %d\n", score, pinls[i+1], pinls[i-1]);
			score = score + 10 + pinls[i+1] - pinls[i-1];

		}else {
			printf("%d\n", flame);

			printf("score = %d + %d\n", score, pinls[i]);

			if((i - count10) % 2 == 1){
				flame++;
			}

			score = score + pinls[i];
		}
	}	

	printf("%d\n", score);

	return 0;
}