#include "biblioteca.h"
#include "quebrador-senha.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 6

/* --------------------------------------------------------------------- */
/* Quebrador de senha exaustivo */

int quebrador_senha_exaustivo_(char* v, int i)
{
	/* Testa a senha quando chega na base */
	if (i == TAM)
		return login(v);

	/* k é o valor na tabela ASCII de 0-9 */
	/* Acrescenta os números */
	for (int k = 48; k < 58; k++)
	{
		v[i] = (char)k;

		if (quebrador_senha_exaustivo_(v, i+1))
			return 1;
	}

	/* k é o valor na tabela ASCII de a-z  */
	/* Pula o k dos números para as letras */
	for (int k = 97; k < 123; k++)
	{
		vetor[i] = (char)k;

		if (quebrador_senha_exaustivo_(v, i+1))
			return 1;
	}

	/* Se chegou até aqui é por que não encontrou a senha */
	return 0;
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_exaustivo(void)
{
	char v[TAM];
	return quebrador_senha_exaustivo_(v, 0);
}

/* --------------------------------------------------------------------- */
/* Quebrador de senha com poda */

void zeraVetor(int* v, int tam)
{
	for (int i = 0; i < tam; i++)
		v[i] = 0;
}

/* Retorna 0 caso o elemento já esteja no vetor */
int nao_tem(int repetido)
{
	return (repetido == 1);
}

int quebrador_senha_poda_(char* v, int* vAux, int i, int qtd_n, int qtd_l)
{
	/* Testa a senha quando chega na base */
	if (i == TAM)
		return login(v);

	/* Vê se ainda pode adicionar número */
	if (qtd_n < 4)
	{
		/* k é o valor na tabela ASCII de 0-9 */
		/* indice é a posição no vetorAux do elem adicionado */
		for (int k = 48, indice = 0; k < 58; k++, indice++)
		{
			v[i] = (char)k;
			qtd_n++;

			/* Marca qual número foi adicionado */
			vAux[indice]++;

			if (nao_tem(vAux[indice]) && 
				quebrador_senha_poda_(v, vAux, i+1, qtd_n, qtd_l))
				return 1;
		
			if (qtd_n == 4)
				k = 57;

			/* backtracking */	
			qtd_n --;
			vAux[indice]--;	
		}	
	}

	/* Vê se ainda pode adicionar letra */
	if (qtd_l < 4)
	{
		/* k é o valor na tabela ASCII de a-z */
		for (int k = 97, indice = 10; k < 123; k++, indice++)
		{
			v[i] = (char)k;
			qtd_l++;
			
			/* Marca qual letra foi adicionada */
			v[indice]++;

			if (nao_tem(v[indice]) &&
				quebrador_senha_poda_(v, vAux, i+1, qtd_n, qtd_l))
				return 1;

			/* backtracking */
			vAux[indice]--;	
			qtd_l--;		
		}	
	}

	/* Se chegou até aqui é por que não encontrou a senha */
	return 0;
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_poda(){
	char v[TAM]; /* Vetor principal */

	/* Vetor de números e letras, marca se o elem já está no vetor */
	int v[36];
	zeraVetor(v, 36); 

	return quebrador_senha_poda_(v, vAux, 0, 0, 0);
}
