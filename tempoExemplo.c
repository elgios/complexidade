#include <stdio.h>
#include <stdlib.h>

/* Arquivo tempo.h deve estar na mesma pasta deste código */
#include "tempo.h"

/* Teste de tempo. Quanto tempo leva para descobrir se um número 
 * grande é primo? Este código só tem o propósito de demonstrar
 * o uso da lib tempo.h
 * */
int main()
{
	unsigned long int numero=259029203;
	unsigned long int divisor, i;
	ulong passou;
	
	printf("tentando ver se %lu é primo\n", numero);
	
	divisor = 1;
	
	/* Antes de entrar no trecho de código a ser medido, invoca-se a
	 * função tempo() 
	 * */
	tempo();
	for (i=2; i < numero; i++){
		if ((numero % i)==0){
			divisor=numero / i;
			break;
		}
	}	
	passou = tempo();
	/* Após o trecho de código a ser medido, invoca-se novamente a função
	 * tempo() mas guardando o retorno em uma variável unsigned long int
	 * Cada vez que chama a função tempo(), ela retorna a quantidade de
	 * us (micro segundos) que se passou desde a última invocação da 
	 * mesma função tempo()
	 * */
	 
	if (divisor > 1){
		printf("%lu NÃO É PRIMO (divide por %lu)\n", numero, divisor);
	} else {
		printf("%lu É PRIMO\n", numero);
	}
	
	/* A variável passou tem us (micro segundos). Uma função chamada
	 * formata retorna uma sgring amigável com distinção entre segundos,
	 * milissegundos e micro
	 * */ 
	printf ("O cálculo levou %luns (%s)\n", passou, formata(passou));
}
/* Este código é apenas para testar o uso do tempo.h. Foi fixado um
 * número que é primo para testar. Pode testar com outros números.
 * Se o objetivo fosse otimizar o código para calcular de forma mais
 * eficiente, tem vários pontos a ser melhorado. Por exemplo, se um 
 * número nào é par não divide por 2 e pode-se começar o laço em 3
 * indo só nos impares. Isso já reduz o laço pela metade e o tempo 
 * também
 * */
