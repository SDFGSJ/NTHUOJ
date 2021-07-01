#include "function.h"

ContainerBase* create(int n, int *array, int cnt2, int cnt3) {
    ContainerBase* solver;
    if (cnt2 > cnt3)  solver = new Array(n, array);
    else solver = new List(n, array);
    return solver;
}

void Array::move(int d) {
    cur += rev ? -d : d;
    if (cur > size) cur = size;
    if (cur < 1) cur = 1;
}

void Array::remove() {
    if (rev) {
        if (cur == 1) {
            for (int i = 1; i < size; i++) {
                mem[i] = mem[i+1];
            }
            size--;
        }else {
            for (int i = cur; i < size; i++) {
                mem[i] = mem[i+1];
            }
            size--;
            cur--;
        }
        return;
    }
    if (cur != size) {
        for (int i = cur; i < size; i++) mem[i] = mem[i+1];
        size--;
    }else {
        cur--;
        size--;
    }
}

void Array::reverse() {
    rev = !rev;
}

void List::move(int d) {
    if (rev) d = -d;
    if (d >= 0) while (d--) if (cur->nxt) cur = cur->nxt;
    else break;
    else while (d++) if (cur->pre) cur = cur->pre;
    else break;
}

void List::remove() {
    cur = cur->remove();
    if (rev && cur->pre != nullptr && cur->nxt != nullptr) cur = cur->pre;
    size--;
}

void List::reverse() {
    rev = !rev;
}
