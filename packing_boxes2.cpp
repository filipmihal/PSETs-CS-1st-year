#include <iostream>
#include <cstdlib>
#include <algorithm> // for std::find
#include <iterator>

using namespace std; 

struct Box {                                       
	int dims[3];
	int index;
};

int compareSort( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int compareLex(const void *box1, const void *box2) {
    struct Box a = *((struct Box*)box1);
    struct Box b = *((struct Box*)box2);
    for (int i =0; i < 3; i++){
        if (a.dims[i] < b.dims[i])
        {
        return -1;
        }
         if (a.dims[i] > b.dims[i])
        {
        return 1;
        }
    }

    return 0;
}

int compareBoxes(int a[], int b[]){
    if(a[0] < b[0] && a[1] < b[1] && a[2] < b[2])
        return 0;
    if (a[0] > b[0] && a[1] > b[1] && a[2] > b[2])
        return 1;
    return -1;
}


int main(){
    int boxNum;
    
    std::cin >> boxNum;
    struct Box boxes[boxNum];
    int chain[boxNum][2];

    for(int i = 0; i < boxNum; i++){
        chain[i][0] = -1;
        chain[i][1] = 0;
    }

     for(int i = 0; i < boxNum; i++) {
        boxes[i].index = i;
		cin >> boxes[i].dims[0] >> boxes[i].dims[1] >> boxes[i].dims[2];
        qsort( boxes[i].dims, 3, sizeof(int), compareSort );
	}


    qsort(boxes, boxNum, sizeof(struct Box), compareLex);

    int maxChain = 0;
    int topChainIndex = 0;
    for (int i = 0; i < boxNum; i++){
        for(int j = i-1; j > -1; j--){
            if(compareBoxes(boxes[i].dims, boxes[j].dims) == 1){
                if(chain[i][1] <= chain[j][1]){
                    chain[i][0] = j;
                    chain[i][1] = chain[j][1]+1;

                    if(chain[i][1] > maxChain){
                        maxChain = chain[i][1];
                        topChainIndex = i;
                    }
                }
            }
        }
    }
     
    cout << maxChain +1 << "\n";

    while (maxChain != -1){
        cout << boxes[topChainIndex].index << "\n";
        maxChain = chain[topChainIndex][0];
        topChainIndex = chain[topChainIndex][0];
    }

    return 0;
}