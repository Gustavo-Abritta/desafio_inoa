/// Declaração das bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
    /// Declaração de algumas variaveis

    FILE*entrada;
    FILE*saida;
    char ativo[10], email [20], resp, resp2;
    int n, i;
    float preco, limsup, liminf;
    bool continuar, mesmoativo;

    /// Abrir arquivo de  saida

    saida=fopen("saida.txt", "w");

    /// Printar mensagem inicial na tela e no arquivo

    printf ("Inicio do desafio Inoa\n");
    fprintf (saida, "Inicio do desafio Inoa\n");

    /// Atribuição de booleana

    continuar = true;

    /// Executar sempre que quiser continuar o programa

    while (continuar){
        mesmoativo = true;

        /// Coletar dados do ativo

        printf ("Digite o nome do ativo a ser monitorado:");
        scanf ("%s", & ativo);
        printf ("Digite o valor do limite superior:");
        scanf ("%f", & limsup);
        printf ("Digite o valor do limite inferior:");
        scanf ("%f", & liminf);
        fprintf (saida, "Ativo: %s\n", ativo);

        /// Executar para o ativo e comparar com os limites inferior e superior
        while (mesmoativo){

            /// Abrir arquivo de entrada e ler numero de emails

            entrada=fopen("entrada.txt", "r");
            fscanf (entrada, "%d ", & n);

            /// Perguntar o nome do ativo hoje e comparar

            printf ("Digite o valor do ativo hoje:");
            scanf ("%f", & preco);
            fprintf(saida, "Preco hoje: %.2f\n", preco);
            if (preco>=limsup){
                for (i=0; i<n; i++){
                    fscanf (entrada, "%s ", & email);
                    fprintf (saida, "Mandar email de venda para: %s\n", email);
                }
            }
            else if (preco<=liminf){
                    for (i=0; i<n; i++){
                        fscanf (entrada, "%s ", & email);
                        fprintf (saida, "Mandar email de compra para: %s\n", email);
                    }
                }
            else fprintf (saida, "Manter ativo.\n");

            /// Definir se mudar o ativo e se continua o programa

            printf ("Deseja continuar analisando o ativo? (S ou N) ");
            fflush(stdin);
            scanf ("%c", & resp);
            if (resp == 'N' || resp == 'n'){
                mesmoativo=false;
                printf ("Deseja mudar de ativo? (S ou N) ");
                fflush(stdin);
                scanf ("%c", & resp2);
                if (resp2 == 'N' || resp2 == 'n')
                    continuar = false;
            }
        }
            /// Fechar arquivo de entrada

            fclose(entrada);

    }

    /// Mensagem final + fechar arquivo de saida + finalização

    printf ("Fim do programa.\n");
    fprintf (saida, "Fim do programa.\n");
    fclose(saida);
    return 0;
}
