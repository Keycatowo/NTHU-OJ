#include <stdio.h>
#include "function.h"
#define ll long long int
int input[(int)2e6];
int main() {
    int n, t;
    scanf( "%d%d", &n, &t );
    for( int i = 0 ; i < n ; i++ ) {
        scanf( "%d", &input[i] );
    }
    for( int i = 0 ; i < t ; i++ ){
        int q;
        scanf( "%d", &q );
        printf( "%d is at index: %d\n", q, BS(input, q, n) );
    }
    
    
    
    return 0;
}


