#include "function.h"

void Array::move(int d) {
    if(rev)
        d *= -1;
    cur += d;
    if(cur > this->size)
        cur = this->size;
    else if(cur < 1)
        cur = 1;
}

void Array::remove() {
    if(rev == false){
        for(int i = cur; i < this->size; i++){
            mem[i] = mem[i+1];
        }
        this->size--;
        if(cur > this->size)
            cur--;
    }
    else{
        for(int i = cur; i < this->size; i++){
            mem[i] = mem[i+1];
        }
        this->size--;
        cur--;
        if(cur < 1)
            cur++;
    }

}

void Array::reverse() {
    rev = !rev;
    //cur = size - cur + 1;
}

void List::move(int d) {
    if(rev)
        d *= -1;
    if(d > 0){
        while(d && cur->nxt){
            cur = cur->nxt;
            d--;
        }
    }
    else if(d < 0){
        d *= -1;
        while(d && cur->pre){
            cur = cur->pre;
            d--;
        }
    }
    else
        return;
}


void List::remove() {
    cur = cur->remove(rev);
    this->size--;
}


void List::reverse() {
    rev = !rev;
}

ContainerBase* create(int n, int *arr, int op2Cnt, int op3Cnt) {
    ContainerBase* rt = nullptr;
    if(op2Cnt > op3Cnt)
        rt = new Array(n, arr);
    else
        rt = new List(n, arr);
    return rt;
}
