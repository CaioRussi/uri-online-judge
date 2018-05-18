#include <stdio.h>
#include <algorithm>
using namespace std;

struct tempo
{
    int hora;
    int minutos;
    int segundos;       
    char evento;
};

bool compara(tempo a, tempo b)
{
     if(a.hora < b.hora)
        return true;
     else
     if(a.hora == b.hora)
        if(a.minutos < b.minutos)
           return true;
        else
        if(a.minutos == b.minutos)
           if(a.segundos < b.segundos)
              return true;
     return false;
}

int main(void)
{
    int N, max, i, cont, M, entrada, saida, lido, maior, incerto;
    char evento[11];
    tempo cartao[64801];
    while(scanf("%d", &N) && N)
    {
       getchar();
       for(i = 0, entrada = 0, saida = 0, incerto = 0; i < N; i++)
       {
          gets(evento);
          cartao[i].hora = (evento[0]-48)*10 + (evento[1]-48);
          cartao[i].minutos = (evento[3]-48)*10 + (evento[4]-48);
          cartao[i].segundos = (evento[6]-48)*10 + (evento[7]-48);
          cartao[i].evento = evento[9];
          if(evento[9] == 'E')
             entrada++;
          else
          if(evento[9] == 'X')
             saida++;
          else
             incerto++;
       }
       
       sort(cartao, cartao+N, compara);
       
       if(entrada > saida)
          max = (incerto - (entrada - saida))/2; 
       else
          max = (saida - entrada) + (incerto - (saida - entrada))/2;
       
       for(i = 0, lido = 0, maior = 0, cont = 0; i < N; i++)
       {
          if(cartao[i].evento == 'E')
             cont++;
          else
             if(cartao[i].evento == '?')
             {
                if(lido < max)//pode-se considerar como entrada ainda.
                   cont++;
                else
                   cont--;
                lido++;
             }
             else//saída
                cont--;
          if(cont > maior)
             maior = cont;
       }
       
       printf("%d\n", maior);
    }
    return 0;
}
