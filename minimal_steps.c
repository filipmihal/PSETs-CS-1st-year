#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Position1D {                                       
	int position;
	int people;
};
// sort the the structs
int compare(const void *position1, const void *position2) {
    return ((struct Position1D*)position1)->position - ((struct Position1D*)position2)->position;
}

int main(){
    int R, C, N;
    long int peopleSum = 0;
    scanf("%d %d %d", &R, &C, &N);
    struct Position1D yPos[N];
    struct Position1D xPos[N];

    for(int i = 0; i < N; i++) {
		scanf("%d %d %d", &((yPos)[i].position), &((xPos)[i].position), &((yPos)[i].people));
		(xPos)[i].people = (yPos)[i].people;
        peopleSum += (yPos)[i].people;
	}


    qsort(yPos, N, sizeof(struct Position1D), compare);
    qsort(xPos, N, sizeof(struct Position1D), compare);

    long int midY = peopleSum/2+1, midX = peopleSum/2+1;
    int y = -1, x =-1;
    while (midY > 0){
        y++;
        midY -= yPos[y].people;
    }
    
    while (midX > 0){
        x++;
        midX -= xPos[x].people;
    }

    printf("%d %d", yPos[y].position, xPos[x].position);
    return 0;

}