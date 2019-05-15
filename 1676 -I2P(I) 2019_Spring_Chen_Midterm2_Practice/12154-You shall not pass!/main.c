#include <stdio.h>
#include "function.h"

int n,k;
int spell[MAX_N][MAX_N];// Hp
int sputum[MAX_N*MAX_N];// attack
int win;

int main()
{
    freopen("input.txt","r",stdin);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &spell[i][j]);
	for(int i=0; i<k; i++) scanf("%d", &sputum[i]);
	win = solve(&n, &k, sputum, spell);
	if(win==0) printf("Fly you fool.\n");
	else printf("Victory belongs to the Spitters!\n");
	return 0;
}
