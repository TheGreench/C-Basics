/*
    Programa seguimiento

    Indicar cual será la salida por pantalla de este programa
    luego de realizar un analisis del código.
*/

#include <stdio.h>

int func_suma(int A, int B)
{
    return A + B;                               // {10}
}

void proc_02(int A, int *B, int C)              // A=1 B=1 C=3 => linea29 || A=2 B=2 C=3 linea43
{
    A = func_suma(A, *B) * C;                   // {11}
    printf("{12} %d %d %d\n", A, *B, C);        // {12} // A=6 B=1 C=3 => linea29 || A=12 B=2 C=3 linea43
}

void proc_01(int *A, int B, int D)              // A=1 B=2 C=3
{
    int C;

    C = *A;                                     // {13}
    *A = B;                                     // {14}
    B = C;                                      // {15}
    printf("{16} %d %d %d\n", *A, B, C);        // {16} // A=2 B=1 C=1
    proc_02(B, &C, D);                          // {17} // B=1 C=1 D=3
    printf("{18} %d %d %d\n", *A, B, C);        // {18} // A=2 B=1 C=1
}

int main()
{
    int A, B, C;

    A = 1;                                      // {1}
    B = 2;                                      // {2}
    C = 3;                                      // {3}
    printf("{4} %d %d %d\n", A, B, C);          // {4} // A=1 B=2 C=3
    proc_01(&A, B, C);                          // {5}
    printf("{6} %d %d %d\n", A, B, C);          // {6} // A=2 B=2 C=3
    proc_02(A, &B, C);                          // {7}
    printf("{8} %d %d %d\n", A, B, C);          // {8} // A=2 B=2 C=3

    return 0;
}