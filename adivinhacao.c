#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main () {
    //Imprime o cabe�alho
    setlocale(LC_ALL, "Portuguese");

    printf ("\n\n");
    printf("          P  /_\\  P                                 \n");
    printf("         /_\\_|_|_/_\\                               \n");
    printf("    n_n | ||. .|| | n_n         Bem vindo ao         \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o!    \n");
    printf("    |" "  |  |_|  |"  " |                            \n");
    printf("   |_____| ' _ ' |_____|                             \n");
    printf("          \\__|_|__/                                 \n");
    printf ("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numeroSecreto = numerogrande % 100;
    int chute = 0;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf ("Qual o n�vel de dificuldade?\n");
    printf ("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
    printf ("Escolha :");
    scanf ("%d", &nivel);

    int numerodetentativas;

    switch (nivel) {
        case 1 :
            numerodetentativas = 20;
            break;
        case 2 :
            numerodetentativas = 15;
            break;
        default :
            numerodetentativas = 6;
            break;
    }

    for (int i = 1; i <= numerodetentativas; i++){
        printf ("\n*Tentativa %d*\n", tentativas);
        printf ("\nQual o seu chute : ");
        scanf ("%d", &chute);
        printf ("\nSeu chute foi : %d", chute);

        if (chute < 0){
            printf ("\nN�o � permitido o uso de n�meros negativos.\nTente Novamente!\n");
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if (acertou) {
            break;
        }
        else if (maior) {
            printf ("\nSeu chute foi maior que o n�mero secreto\n");
           }
        else {
            printf ("\nSeu chute foi menor que o n�mero secreto\n");
           }
        tentativas++;
        //O programa sempre l� da direita para esquerda. Por isso o 2.0 , para enteder que se � double.
        double pontosperdidos = abs(chute - numeroSecreto) / (double)2;
        pontos = pontos - pontosperdidos;
        }
    printf ("\nFim de jogo!");
    if (acertou) {
        printf ("\n\n");
        printf ("               OOOOOOOOOOO                    \n");
        printf ("           OOOOOOOOOOOOOOOOOOO                \n");
        printf ("        OOOOOO  OOOOOOOOO  OOOOOO             \n");
        printf ("      OOOOOO      OOOOO      OOOOOO           \n");
        printf ("    OOOOOOOO  #   OOOOO  #   OOOOOOOO         \n");
        printf ("   OOOOOOOOOO    OOOOOOO    OOOOOOOOOO        \n");
        printf ("  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf ("  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf ("  OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO       \n");
        printf ("   OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO        \n");
        printf ("    OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO         \n");
        printf ("      OOOOO   OOOOOOOOOOOOOOO   OOOO          \n");
        printf ("        OOOOOO   OOOOOOOOO   OOOOOO           \n");
        printf ("           OOOOOO        OOOOOO              \n");
        printf ("               OOOOOOOOOOOO                   \n");
        printf ("\n\n");
        printf ("Parab�ns voc� ganhou!\n");
        printf ("Voc� acertou em %d tentativas!\n", tentativas);
        printf ("Total de pontos : %.2f\n", pontos);
    } else {
        printf("\n\n");
        printf("                              \n");
        printf("       \|/ ____ \|/           \n");
        printf("        @~/ ,. \~@            \n");
        printf("       /_( \__/ )_\           \n");
        printf("          \__U_/              \n");
        printf("\n\n");
        printf ("Voc� perdeu! Tente de novo!\n");
        }
    return 0;
    }

