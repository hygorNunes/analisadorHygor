#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;

void RetornaToken ()
{
   token t;
		do
     	{
         t = ProximoToken();

          //Imprime na tela os tekens retornados
          switch(t.classe)
   		{
   			case  1:  cout << "Classe = " << "if" << endl;         			break;
         	case  2:  cout << "Classe = " << "step" << endl;       			break;
         	case  3:  cout << "Classe = " << "else" << endl;       			break;
         	case  4:  cout << "Classe = " << "for" << endl;        			break;
         	case  5:  cout << "Classe = " << "return" << endl;     			break;
         	case  6:  cout << "Classe = " << "print" << endl;      			break;
         	case  7:  cout << "Classe = " << "read" << endl;       			break;
         	case  8:  cout << "Classe = " << "sqrt" << endl;               break;
         	case  9:  cout << "Classe = " << "+" << endl;                   break;
         	case 10:  cout << "Classe = " << "-" << endl;                   break;
         	case 11:  cout << "Classe = " << "*" << endl;                   break;
         	case 12:  cout << "Classe = " << "/" << endl;                   break;
         	case 13:  cout << "Classe = " << "=" << endl;                   break;
         	case 14:  cout << "Classe = " << "<" << endl;                   break;
         	case 15:  cout << "Classe = " << "(" << endl;                   break;
         	case 16:  cout << "Classe = " << ")" << endl;                   break;
         	case 17:  cout << "Classe = " << ";" << endl;                   break;
         	case 18:  cout << "Classe = " << ":=" << endl;                  break;
         	case 19:  cout << "Classe = " << "numero" << endl;              break;
         	case 20:  cout << "Classe = " << "identificador" << endl;       break;
         	case 21:  cout << "Classe = " << "final de sentenca" << endl;   break;
            case 22:  cout << "Classe = " << "erro" << endl;                break;
            case 23:  cout << "Classe = " << "num" << endl;                break;
            case 24:  cout << "Classe = " << "string" << endl;                break;
            case 25:  cout << "Classe = " << "'""''' "<< endl;                break;
            case 26:  cout << "Classe = " << ">" << endl;                break;
            case 27:  cout << "Classe = " << ":=" << endl;                break;
            case 28:  cout << "Classe = " << "{" << endl;                break;
            case 29:  cout << "Classe = " << "}" << endl;                break;
            
            
   		}
          cout << "Lexema = " << t.valor << endl;
          cout << "Linha  = " << t.posicaoL << endl;
          cout << endl;


      }while(t.classe != 21);
	
	if(t.classe == 21){
	
		printf("O Arquivo fonte foi analisado corretamente");
	} else{
	printf("O arquivo contém erros");
	}
	
      //Liberando memoria
      delete[] vetor;
}

/*----------------------------------------------------------------------------*/
