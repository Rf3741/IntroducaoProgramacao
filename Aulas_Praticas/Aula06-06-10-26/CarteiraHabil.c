/* 
Introdução a Programação - Aula 6 
Rafael Andrade Câmara, 06/10/2026, 26.2.4022    
*/

 #include <stdio.h>

int verificar_elegibilidade(int idade, float score) {
	// processamento
	if (idade >= 18 && score >= 7.5) {
		return 1;
	}

	return 0;
}

int main () {
	// declaracao de variaveis
	int idade;
	float score;

	// entrada de dados
	printf("Digite a idade: ");
	scanf("%d", &idade);

	printf("Digite o score: ");
	scanf("%f", &score);

	// exibicao do resultado
	if (verificar_elegibilidade(idade, score) == 1) {
		printf("ELEGIVEL\n");
	} else {
		printf("NAO ELEGIVEL\n");
	}

	return 0;
}
