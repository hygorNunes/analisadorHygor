
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "lexico.h"
#include "token.h"
FILE *arq_saida;

using namespace std;

int main ()
{
   //Digite aqui o arquivo para leitura: ArquivoFonte1.mln  ou  ArquivoFonte2.mln .
	arquivo("ArquivoFonte1.mln");
	
	arq_saida = fopen("resultado.txt","w");
	
	fprintf(arq_saida,"O Arquivo fonte foi analisado corretamente");

   //Retorna os tokens
   RetornaToken ();

	

   return 0;



	
	

}
