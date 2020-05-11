#include "public.h"

typedef struct node{
    int key;
    int value;
    node():key(0), value(0) {}
}node;

// typedef struct list{
//     node test[100];
//     int length;
//     list():length(100) {}
// }list;


int main(){
    // list li;
    node test[100];
    for(int i=0; i<100; ++i){
        // li.test[i].key = i;
        // li.test[i].value = i*i;
        test[i].key = i;
        test[i].value = i*i;
    }

    for(int i=0; i<100; ++i){
        // cout << li.test[i].key << endl;
        // cout << li.test[i].value << endl;
        cout << test[i].key << endl;
        cout << test[i].value << endl;
    }
}
