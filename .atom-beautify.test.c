#include <stdio.h>

int main(int argc, char const *argv[]) {
		int i = 0;
		int limit = 2;
		do{
			if(i++ < limit){
				printf("bangkit\n");
			}
		}while (i < limit);
	return 0;
}
