#include <stdio.h>
//#include <math.h>

#define PI 3.14159265359

int temp (opcao) {
  int temp;
  float result;
  
  switch (opcao){
    case 1:
      printf("Digite o valor em Celsius: ");
      scanf("%d", &temp);
      
      result = temp * (9.0/5.0) + 32;
      printf("Valor em Fahrenheit: %.2f\n", result);
      result = temp + 273.15;
      printf("Valor em Kelvin: %.2f\n", result);
    break;
    case 2:
      printf("Digite o valor em Fahrenheit: ");
      scanf("%d", &temp);
      
      result = (temp - 32) * (5.0/9.0);
      printf("Valor em Celsius: %.2f\n", result);
      result = (temp - 32) * (5.0/9.0) + 273.15;
      printf("Valor em Kelvin: %.2f\n", result);
    break;
    case 3:
      printf("Digite o valor em Kelvin: ");
      scanf("%d", &temp);
      
      result = temp - 273.15;
      printf("Valor em Celsius: %.2f\n", result);
      result = (temp - 273.15) * (9.0/5.0) + 32;
      printf("Valor em Kelvin: %.2f\n", result);
    break;
    
  } 
  return 0;
}

int grau (opcao){
  float grau;
  float result;
  
  if (opcao == 1){
    printf("Digite o valor em Graus: \n");
    scanf("%f", &grau);
      
    result = PI * grau / 180;
    printf("Valor em Radianos: %.2f\n", result);
  } else {
    printf("Digite o valor em radiano: \n");
    scanf("%f", &grau);
    
    result = grau * (180 / 3.14159265359);
    printf("Valor em Grus: %.2f\n", result);
  }
  return 0;
}

void main () {

  int opcao;

  printf("### CONVERSOR DE UNIDADES ###\n");
  printf("\n");
  printf("1) Angulo\n");
  printf("2) Temperatura\n");
  printf("\n");
  printf("Digite uma opcao: ");
  
  scanf("%d", &opcao);
  
  switch (opcao){
    case 1:
      printf("Qual a unidade de origem?\n\n");
      printf("1) Graus\n");
      printf("2) Radianos\n");
      
      printf("Selecione uma opcao: \n");
      scanf("%d", &opcao);
      grau(opcao);
    break;
    case 2:
      printf("Qual a unidade de origem?\n\n");
      printf("1) Celsius\n");
      printf("2) Fahrenheit\n");
      printf("3) Kelvin\n");
      
      printf("Selecione uma opcao: \n");
      scanf("%d", &opcao);
      temp(opcao);
    break;
  }
}