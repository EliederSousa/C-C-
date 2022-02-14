#include <stdio.h>
#include <time.h>

double mat[1000];

double fib_iterativo( int n ) {
    double a = 0;
    double b = 1;
    double result;
    if( n == 0 ) return 0;

    for (int w=1; w<n; w++ ) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

double fib_recursivo( int n ) {
    if( n == 0 ) {
        return 0;
    } else if ( n == 1 ) {
        return 1;
    } else {
        return fib_recursivo(n-1) + fib_recursivo(n-2);
    }
}

double fib_progdinamica( int n ) {
    if( n == 0 ) {
        return 0;
    } else if ( n == 1 ) {
        mat[1] = 1;
        return 1;
    } else if ( mat[n] > 0 ) {
        return mat[n];
    } else {
        mat[n] = fib_progdinamica(n-1) + fib_progdinamica(n-2);
        return mat[n];
    }
}

int main() {
    // Zerando a matriz de cache.
    for ( int w=0;w<1000;w++ ) {
        mat[w] = 0;
    };

    printf("\n\nIterativo\n\n");

    // Algoritmo iterativo
    for( int w=0; w<=100; w++ ) {
        clock_t time = clock();

        printf("fib(%d) = %.0lf, ", w, fib_iterativo(w));

        time = clock() - time;
        double taken = ((double)time)/CLOCKS_PER_SEC;
        printf("calculado em %fs\n", taken);
    }

    printf("\n\nRecursivo\n\n");

    // Algoritmo recursivo
    for( int w=0; w<=45; w++ ) {
        clock_t time = clock();

        printf("fib(%d) = %.0lf, ", w, fib_recursivo(w));

        time = clock() - time;
        double taken = ((double)time)/CLOCKS_PER_SEC;
        printf("calculado em %fs\n", taken);
    }

    printf("\n\nDinâmico\n\n");

    // Algoritmo recursivo usando programação dinâmica
    for( int w=0; w<=100; w++ ) {
        clock_t time = clock();

        printf("fib(%d) = %.0lf, ", w, fib_progdinamica(w));

        time = clock() - time;
        double taken = ((double)time)/CLOCKS_PER_SEC;
        printf("calculado em %fs\n", taken);
    }

    return 0;
}