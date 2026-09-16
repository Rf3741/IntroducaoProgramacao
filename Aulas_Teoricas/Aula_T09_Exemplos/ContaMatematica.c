#include <stdio.h>

int main(void) {
	// declaracao de variaveis
	double primeiro, segundo, resultado;
	char operador;

	// entrada de dados
	scanf("%lf %lf %c", &primeiro, &segundo, &operador);

	// processamento
	switch (operador) {
	case '+':
		resultado = primeiro + segundo;
		break;
	case '-':
		resultado = primeiro - segundo;
		break;
	case '*':
		resultado = primeiro * segundo;
		break;
	case '/':
		resultado = primeiro / segundo;
		break;
	default:
		printf("Operador invalido\n");
		return 1;
	}

	// exibicao do resultado
	printf("Resultado: %.2f %c %.2f = %.2f\n", primeiro, operador, segundo, resultado);

	return 0;
}
