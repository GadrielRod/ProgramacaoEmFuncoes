/* Fig. 6.16: fig06_16.c */

#include <stdio.h>

#include <locale.h>

#define SIZE 99



/* function prototypes */

void mean( const int answer[] );

void median( int answer[] );

void mode( int freq[], const int answer[] ) ;

void bubbleSort( int a[] );

void printArray( const int a[] );



/* fun��o main inicia a execu��o do programa */

int main( void )

{

   int frequency[ 10 ] = { 0 }; /* inicializa frequ�ncia do array */



   /* inicializa resposta do array */
   int response[ SIZE ] =

      { 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,

        7, 8, 9, 5, 9, 8, 7, 8, 7, 8,

        6, 7, 8, 9, 3, 9, 8, 7, 8, 7,

        7, 8, 9, 8, 9, 8, 9, 7, 8, 9,

        6, 7, 8, 7, 8, 7, 9, 8, 9, 2,

        7, 8, 9, 8, 9, 8, 9, 7, 5, 3,

        5, 6, 7, 2, 5, 3, 9, 4, 6, 4,

        7, 8, 9, 6, 8, 7, 8, 9, 7, 8,

        7, 4, 4, 2, 5, 3, 8, 7, 5, 6,

        4, 5, 6, 1, 6, 5, 7, 8, 7 };



   setlocale(LC_ALL, "Portuguese");

   /* processa respostas */

   mean( response );

   median( response );

   mode( frequency, response );

   return 0; /* indica conclus�o bem-sucedida */

} /* fim do main */



/* calcula m�dia de todos os valores de resposta */

void mean( const int answer[] )

{

   int j; /* contador para totalizar os elementos do array */

   int total = 0; /* vari�vel para manter a soma dos elementos do array */



   printf( "%s\n%s\n%s\n", "********", "  Mean", "********" );



   /* valores totais de respostas */

   for ( j = 0; j < SIZE; j++ ) {

      total += answer[ j ];

   } /* end for */



   printf(  "A m�dia � o valor m�dio dos itens de dados.\n"

            "A m�dia � igual ao total de todos\n"

            "os itens de dados divididos pelo n�mero\n"

            "de itens de dados ( %d ). O valor m�dio para esta\n"

            "execu��o �: %d / %d = %.4f\n\n",

           SIZE, total, SIZE, (  double  ) total / SIZE );

} /* fim da fun��o mean */



/* ordena array e determina valor do elemento mediano */

void median( int answer[] )

{

   printf( "\n%s\n%s\n%s\n%s",

           "********", " Mediana", "********",

           "O array de respostas, n�o ordenado, �" );



   printArray( answer ); /* exibe array n�o ordenado */



   bubbleSort( answer ); /* ordena array */



   printf( "\n\nO array ordenado �" );

   printArray( answer ); /* exibe array ordenado */



   /* exibe elemento mediano */

    printf( "\n\nA mediana � o elemento %d do\n"

            "array ordenado de %d elementos.\n"

            "Para essa execu��o, a mediana � %d\n\n",

           SIZE / 2, SIZE, answer[ SIZE / 2 ] );

} /* fim da fun��o median */



/* determina a resposta mais frequente */

void mode( int freq[], const int answer[] )

{

   int rating; /* contador para acessar os elementos 1-9 do array freq */

   int j; /* contador para resumir os elementos 0-98 do array answer */

   int h; /* contador para exibir histogramas dos elementos no array freq */

   int largest = 0; /* representa maior frequ�ncia */

   int modeValue = 0; /* representa resposta mais frequente */



   printf( "\n%s\n%s\n%s\n",

           "********", "  Moda", "********" );



   /* initialize frequencies to 0 */

   for ( rating = 1; rating <= 9; rating++ ) {

      freq[ rating ] = 0;

   } /* fim do for */



/* resumo das frequ�ncias*/

   for ( j = 0; j < SIZE; j++ ) {

      ++freq[ answer[ j ] ];

   } /* fim do for */



   /* cabe�alhos de impress�o para colunas do resultado */

   printf( "%s%11s%19s\n\n%54s\n%54s\n\n",

           "Resposta", "Frequencia", "Histograma",

           "1    1    2    2", "5    0    5    0    5" );



   /* exibe resultados */

   for ( rating = 1; rating <= 9; rating++ ) {

      printf( "%8d%11d          ", rating, freq[ rating ] );



      /* acompanha valor da moda e valor da maior frequ�ncia */

      if ( freq[ rating ] > largest ) {

         largest = freq[ rating ];

         modeValue = rating;

      } /* fim do if */



      /* barra de histograma de sa�da de impress�o que representa valor de frequ�ncia */

      for ( h = 1; h <= freq[ rating ]; h++ ) {

         printf( "*" );

      } /* fim do for interno */



      printf( "\n" ); /* nova linha de sa�da */

   } /* fim do for externo */



   /* exibe o valor da moda */

   printf( "A moda � o valor mais frequente.\n"

           "Para essa execu��o, a moda � %d, que ocorreu"

           " %d vezes.\n", modeValue, largest );

} /* fim da fun��o mode */



/* fun��o que ordena um array com o algoritmo bubble sort */

void bubbleSort( int a[] )

{

   int pass; /* contador de passada */

   int j; /* contador de compara��o */

   int hold; /* local tempor�rio usado para troca de elementos */



   /* loop para controlar n�mero de passadas */

   for ( pass = 1; pass < SIZE; pass++ ) {



      /* loop para controlar n�mero de compara��es por passada */

      for ( j = 0; j < SIZE - 1; j++ ) {



         /* troca elementos se estiverem fora de ordem */

         if ( a[ j ] > a[ j + 1 ] ) {

            hold = a[ j ];

            a[ j ] = a[ j + 1 ];

            a[ j + 1 ] = hold;

         }/* fim do if */

      } /* fim do for interno */

   } /* fim do for externo */

} /* fim da fun��o bubbleSort */



//* imprime conte�do do array de resultados (20 valores por linha) */

void printArray( const int a[] )

{

   int j; /* contador */



   /* imprime conte�do do array */

   for ( j = 0; j < SIZE; j++ ) {



      if ( j % 10 == 0 ) { /* inicia nova linha a cada 20 valores */

         printf( "\n" );

      } /* fim do if */



      printf( "%2d", a[ j ] );

   } /* fim do for */

} /* fim da fun��o printArray */
