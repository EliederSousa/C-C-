/**
 *  haste.c
 *  
 *  Copyright (c) 2021, Elieder Sousa
 *  eliedersousa<at>gmail<dot>com
 *  
 *  Distributed under the MIT license.
 *  
 *  @date     04/03/22
 *  
 *  @brief    Calcula o problema do corte da haste através de recursão (sem programação dinâmica).
 */
#include <stdio.h>

int probhaste(int tam, int val[]){
  if(tam==0)
    return 0; // Caso base
  
  int i;
  int max = -999;
  for(i = 0; i < tam; i++){
    int i2 = i+1;
    int temp = val[i] + probhaste(tam-i2, val);
    if(temp > max)
      max = temp;
  }
  return max; 
}

int main() {
  int resultado = 0;
  int valores[10] = {1,5,8,9,10,17,17,20,24,30};
  resultado = probhaste(10, valores);
  printf("\nO maior valor é %d", resultado);
}