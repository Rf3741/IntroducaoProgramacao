 #include <stdio.h>

int main(void) {
	// declaracao de variaveis
	int primeiro, segundo;

	// entrada de dados
	printf("Digite dois numeros: ");
	scanf("%d %d", &primeiro, &segundo);

	// processamento e exibicao do resultado
	if (primeiro > segundo) {
		printf("%d e o maior numero\n", primeiro);
	} else if (segundo > primeiro) {
		printf("%d e o maior numero\n", segundo);
	} else {
		printf("Os dois numeros sao iguais\n");
	}

	return 0;
}
