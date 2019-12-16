
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;
/*----------------------------------------------------------------------------*/




/*---------------------Inicio int FalhouAutomatos-----------------------------*/
int FalhouAutomatos (int &partida)
{
	switch(partida)
   {
   		 case  0: return  3; //comentario
   		 case  3: return  6; //if
         case  6: return 11; //then
         case 11: return 16; //else
         case 16: return 20; //end
         case 20: return 27; //repeat
         case 27: return 33; //until
         case 33: return 38; //read
         case 38: return 44; //write
         case 44: return 46; // +
         case 46: return 48; // -
         case 48: return 50; // *
         case 50: return 52; // /
         case 52: return 54; // =
         case 54: return 56; // <
         case 56: return 58; // (
         case 58: return 60; // )
         case 60: return 62; // ;
         case 62: return 65; // :=
         case 65: return 68; // número
         case 68: return 72; //Identificador ou Final de sentença
         case 75: return 76; // {
         default: return 74;//Retorna Erro...
   }
}
/*-----------------------Fim int FalhouAutomatos------------------------------*/



/*---------------------Inicio token ProximoToken()----------------------------*/
token ProximoToken ()
{
  	//Declarando Variaveis
  	token t;//Declarando token de retorno
  	int p;//Contador auxiliar
   int estado = 0;//Auxilia Posiciona as comparações
  	int partida = 0;//Posiciona as comparações
  	int pos = 0;//Variavel contadora aux for

  //Limpando o vetor que recebo o Lexema
  for(p = 0; p < 100; p++)
  {
  		t.valor[p] = NULL;
  }
                

   	while(1)//Laço Infinito
  		{
        switch (estado)
        {
           /*---------------Início "Comentário"--------------------*/
          case 0: c = ProximoCaracter ( );
                  if(isspace(c))//Verifica se espa�o em branco ,tabula��o ou final de linha
                    	InicioDeLexema++;//Aponta para o início do Lexema
                  else if(c == '{') estado = 1;
                  else
                  {   //Iguala o inicio do apontador com o proximo Lexema
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 1: c = ProximoCaracter ( );
          			if (c == '}' && vetor[InicioDeLexema] == '{')
                  	estado = 2;
                  if (c == '{' && vetor[InicioDeLexema] == '{')
                  {
                  	estado = 74;
                     if (vetor[ApontadorAdiante] == '\n')
                     	ApontadorAdiante--;
                  }      
                  if (c != '{' && vetor[InicioDeLexema] != '{')
                  {
                  	estado = 1;
                  }
          break;



          case 2: estado = 0;
                  InicioDeLexema = ApontadorAdiante;
			 break;
          /*------------------Fim "Comentário"---------------------*/


          /*-------------------Inicio "if"-----------------------*/
          case 3: c = ProximoCaracter ( );
          			if(c == 'i')estado = 4;
                  else
                  {   //Iguala o inicio do apontador com o proximo Lexema
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 4: c = ProximoCaracter ();
          			if ((c == 'f')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 5;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 5:
          			t.classe = 1;
                  strcpy(t.valor,"if");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-------------------Fim "if"------------------------*/



          /*-----------------Início "then"---------------------*/
          case 6: c = ProximoCaracter ();
          			if (c == 's')
                  	estado = 7;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 7: c = ProximoCaracter ();
          			if (c == 't')
                  	estado = 8;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 8: c = ProximoCaracter ();
          			if (c == 'e')
                  	estado = 9;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 9: c = ProximoCaracter ();
          			if ((c =='p')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 10;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 10:
          			t.classe = 2;
                  strcpy(t.valor,"step");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-------------------Fim "step"-----------------------*/



          /*------------------Início "else"---------------------*/
          case 11: c = ProximoCaracter ();
          			if (c == 'e')
                  	estado = 12;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 12: c = ProximoCaracter ();
          			if (c == 'l')
                  	estado = 13;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 13: c = ProximoCaracter ();
          			if (c == 's')
                  	estado = 14;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 14: c = ProximoCaracter ( );
          			if ((c =='e')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 15;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 15:
          			t.classe = 3;
                  strcpy(t.valor,"else");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "else"------------------------*/



          /*----------------Início "for"-----------------------*/
          case 16: c = ProximoCaracter ( );
          			if (c == 'f')
                  	estado = 17;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 17: c = ProximoCaracter ( );
          			if (c == 'o')
                  	estado = 18;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 18: c = ProximoCaracter ( );
          			if ((c =='r')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 19;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 19:
          			t.classe = 4;
                  strcpy(t.valor,"for");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
  		    return t;
          /*------------------Fim "for"-------------------------*/



          /*----------------Início "return"---------------------*/
          case 20: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 21;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 21: c = ProximoCaracter ( );
          			if (c == 'e')
                  	estado = 22;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 22: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 23;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 23: c = ProximoCaracter ( );
          			if (c == 'u')
                  	estado = 24;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 24: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 25;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 25: c = ProximoCaracter ( );
          			if ((c == 'n')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 26;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 26:
          			t.classe = 5;
                  strcpy(t.valor,"return");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "return"-----------------------*/



          /*----------------Início "print"----------------------*/
          case 27: c = ProximoCaracter ( );
          			if (c == 'u')
                  	estado = 28;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 28: c = ProximoCaracter ( );
          			if (c == 'n')
                  	estado = 29;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 29: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 30;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 30: c = ProximoCaracter ( );
          			if (c == 'i')
                  	estado = 31;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 31: c = ProximoCaracter ( );
          			if ((c == 'l')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 32;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 32:
          			t.classe = 6;
                  strcpy(t.valor,"print");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "print"----------------------*/



          /*-----------------Início "read"---------------------*/
          case 33: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 34;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 34: c = ProximoCaracter ( );
          			if (c == 'e')
                  	estado = 35;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 35: c = ProximoCaracter ( );
          			if (c == 'a')
                  	estado = 36;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 36: c = ProximoCaracter ( );
          			if ((c == 'd')&&(!islower(vetor[ApontadorAdiante]))&&(!isupper(vetor[ApontadorAdiante])))
                  	estado = 37;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 37:
						t.classe = 7;
                  strcpy(t.valor,"read");//Retorna Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			  return t;
          /*-------------------Fim "read"-----------------------*/



          /*-----------------Início "sqrt"---------------------*/
          case 38: c = ProximoCaracter ( );
          			if (c == 's')
                  	estado = 39;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 39: c = ProximoCaracter ( );
          			if (c == 'q')
                  	estado = 40;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 40: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 41;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 41: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 42;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


        


          case 43:
          			t.classe = 8;
                  strcpy(t.valor,"sqrt");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "sqrt"-----------------------*/



          /*-----------------Início "+"------------------------*/
          case 44: c = ProximoCaracter ( );
          			if (c == '+')
                  	estado = 45;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 45:
          			t.classe = 9;
                  strcpy(t.valor,"+");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "+"--------------------------*/



          /*-----------------Início "-"------------------------*/
          case 46: c = ProximoCaracter ( );
          			if (c == '-')
                  	estado = 47;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 47:
          			t.classe = 10;
                  strcpy(t.valor,"-");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "-"--------------------------*/



          /*-----------------Início "*"------------------------*/
          case 48: c = ProximoCaracter ( );
          			if (c == '*')
                  	estado = 49;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 49:
          			t.classe = 11;
                  strcpy(t.valor,"*");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "*"--------------------------*/



          /*-----------------Início "/"------------------------*/
          case 50: c = ProximoCaracter ( );
          			if (c == '/')
                  	estado = 51;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 51:
          			t.classe = 12;
                  strcpy(t.valor,"/");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "/"--------------------------*/



          /*-----------------Início "="------------------------*/
          case 52: c = ProximoCaracter ( );
          			if (c == '=')
                  	estado = 53;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 53:
          			t.classe = 13;
                  strcpy(t.valor,"=");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "="--------------------------*/



          /*-----------------Início "<"------------------------*/
          case 54: c = ProximoCaracter ( );
          			if (c == '<')
                  	estado = 55;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 55:
          			t.classe = 14;
                  strcpy(t.valor,"<");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "<"--------------------------*/



          /*-----------------Início "("------------------------*/
          case 56: c = ProximoCaracter ( );
          			if (c == '(')
                  	estado = 57;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 57:
          			t.classe = 15;
                  strcpy(t.valor,"(");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "("--------------------------*/



          /*-----------------Início ")"------------------------*/
          case 58: c = ProximoCaracter ();
          			if (c == ')')
                  	estado = 59;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


           case 59:
          			t.classe = 16;
                  strcpy(t.valor,")");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ")"--------------------------*/



          /*-----------------Início ";"------------------------*/
          case 60: c = ProximoCaracter ( );
          			if (c == ';')
                  	estado = 61;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 61:
          			t.classe = 17;
                  strcpy(t.valor,";");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ";"--------------------------*/



          /*-----------------Início ":="------------------------*/
          case 62: c = ProximoCaracter ( );
          			if (c == ':')
                  	estado = 63;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 63:
          			t.classe = 18;
                  strcpy(t.valor,":");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ":="--------------------------*/



          /*-----------------Início "número"--------------------*/
          case 65: c = ProximoCaracter ( );
          			if (isdigit(c))
                  	estado = 66;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 66: c = ProximoCaracter ( );
          			if (isdigit(c))
                  	estado = 66;
                  else
                  {
                  	if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 67;
                     ApontadorAdiante--;
                  }
          break;



          case 67:
          			t.classe = 19;
                  for( p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p]; //Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "número"----------------------*/



          /*--------------Início "identificador"------------------*/
          case 68: c = ProximoCaracter ( );
          			if (islower(c) || isupper(c))
                  	estado = 69;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 69: c = ProximoCaracter ( );
          			if (islower(c) || isupper(c))
                  	estado = 69;
                  else
                  {
                     if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 70;
                     ApontadorAdiante--;
                  }
          break;


          case 70: c = ProximoCaracter ( );
          			if (isdigit(c))
                  {
                    	estado = 70;
                  }
                  else
                  {
                  	if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 71;
                     ApontadorAdiante--;
                  }
          break;



          case 71:
                  t.classe = 20;
                  for( p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p]; //Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*---------------Fim "identificador"-------------------*/



         /*-----------------Início "final"------------------------*/
          case 72: c = ProximoCaracter ();
          			if (c == '\0')
                  	estado = 73;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 73:
          			t.classe = 21;
                  strcpy(t.valor,"FIM");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "final"--------------------------*/



			 /*-------------------Início "erro"---------------------*/
          case 74:
          			ApontadorAdiante++;

          			t.classe = 22;
                  for(p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p];//Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
		    return t;
         /*---------------------Fim "erro"----------------------*/
         
         /*-------------------Início "{"---------------------*/
          case 75:c = ProximoCaracter ( );
          			if (c == '{')
                  	estado = 76;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;
          
           case 76:
          			t.classe = 28;
                  strcpy(t.valor,"{");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = InicioDeLexema;
			 return t;
          
          
         /*---------------------Fim "{"----------------------*/
          
        }//Fim switch
  		}//Fim while		
}//Fim Procedimento
/*-----------------------Fim token ProximoToken()-----------------------------*/
