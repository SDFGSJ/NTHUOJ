#include "function.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Item* CreateList(int N){
    Item* L = (Item*) malloc( sizeof(Item) * N );
    return L;
}
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality ){
    L[idx].name = (char*) malloc( sizeof(char) * (strlen(name)+1) );
    strcpy( L[idx].name, name);

    L[idx].price = price;
    L[idx].discount = discount;
    L[idx].quality = quality;
}
void DeleteList(Item* L, int N){
    for(int i=0; i<N; i++){
        free( L[i].name );
    }
    free(L);
}

int price_cmp( const void* lhs, const void* rhs ){
    const Item* a = (Item*) lhs;
    const Item* b = (Item*) rhs;
    int sp[2];
    sp[0] = a->price - a->discount;
    sp[1] = b->price - b->discount;
    if( sp[0] > sp[1] ) return 1;
    if( sp[0] < sp[1] ) return -1;
    return 0;
}
int discount_cmp( const void* lhs, const void* rhs ){
    const Item* a = (Item*) lhs;
    const Item* b = (Item*) rhs;
    if( a->discount > b->discount ) return -1;
    if( a->discount < b->discount ) return 1;
    return 0;

}
int quality_cmp( const void* lhs, const void* rhs ){
    const Item* a = (Item*) lhs;
    const Item* b = (Item*) rhs;
    if( a->quality > b->quality ) return -1;
    if( a->quality < b->quality ) return 1;
    return 0;
}
