#include<stdio.h>

struct SCORE_DATA {
	char name[256];
	int score;
};
int search_max(struct SCORE_DATA *p) {
	int i = 0;
	int max = 0;
	for (i = 1; i<5; i++) {
		if (p[i].score > p[max].score)max = i;
	}
	return max;
}
int search_min(struct SCORE_DATA *p) {

	int i = 0;
	int min = 0;
	for (i = 1; i<5; i++) {
		if (p[i].score < p[min].score)min = i;
	}
	return min;
}

int main() {

	struct SCORE_DATA book[5];
	int i = 0;
	for (i = 0; i<5; i++) {
		printf("%d人目のスコア:　名前と点数を入力(スペース区切り)-> ", i);
		// scanf("%s %d",name[i],&score[i]);
		scanf("%s %d", book[i].name, &book[i].score);

	}


	printf("最大値: %3d点(%sさん)\n", book[search_max(book)].score, book[search_max(book)].name);
	printf("最小値: %3d点(%sさん)\n", book[search_min(book)].score, book[search_min(book)].name);


	return 0;
}
