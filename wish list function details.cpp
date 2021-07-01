Item* CreateList(int N)
{
	Item *list=(Item*)malloc(sizeof(Item)*N);
	return list;
}
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality )
{
	int len=strlen(name);
	char *str=(char*)malloc( sizeof(char)*(len+10) );
	strcpy(str,name);
	L[idx].name=str;
	L[idx].price=price;
	L[idx].discount=discount;
	L[idx].quality=quality;
}
void DeleteList(Item* L, int N)
{
	int i;
	for(i=0;i<N;i++){
		free(L[i].name);
	}
	free(L);
}

int price_cmp( const void* lhs, const void* rhs )
{
	const Item l=*(const Item*)lhs;
	const Item r=*(const Item*)rhs;
	if(l.price-l.discount > r.price-r.discount){
		return 1;
	}else if(l.price-l.discount < r.price-r.discount){
		return -1;
	}else{
		return 0;
	}
}
int discount_cmp( const void* lhs, const void* rhs )
{
	const Item l=*(const Item*)lhs;
	const Item r=*(const Item*)rhs;
	if(l.discount > r.discount){
		return -1;
	}else if(l.discount < r.discount){
		return 1;
	}else{
		return 0;
	}
}
int quality_cmp( const void* lhs, const void* rhs )
{
	const Item l=*(const Item*)lhs;
	const Item r=*(const Item*)rhs;
	if(l.quality > r.quality){
		return -1;
	}else if(l.quality < r.quality){
		return 1;
	}else{
		return 0;
	}
}
