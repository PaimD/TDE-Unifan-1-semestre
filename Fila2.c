#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vagas[50] = {0}; 

void exibirVagas() {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d° = %d  ", n + 1, vagas[n]);
            n++;
        }
        printf("\n");
    }
}

void cadastrarVaga() {
    int caso;
    printf("Qual o caso da vaga você quer cadastrar? ");
    printf("\n[1] Urgente\n[2] Emergente\n");
    scanf("%d", &caso);

    int cadastrou = 0;
    for (int i = 49; i >= 0; i--) {
        if (vagas[i] == 0) {
            vagas[i] = caso;
            printf("Pessoa cadastrada na vaga %d com prioridade %d.\n", i + 1, caso);
            cadastrou = 1;
            break;
        }
    }

    if (!cadastrou) {
        printf("N?o há vagas disponíveis.\n");
        return;
    }

    int ocupadas[50];
    int count = 0;
    for (int i = 0; i < 50; i++) {
        if (vagas[i] != 0) {
            ocupadas[count++] = vagas[i];
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (ocupadas[j] > ocupadas[j + 1]) {
                int temp = ocupadas[j];
                ocupadas[j] = ocupadas[j + 1];
                ocupadas[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < count; i++) {
        vagas[i] = ocupadas[i];
    }


    for (int i = count; i < 50; i++) {
        vagas[i] = 0;
    }

    printf("Vagas ordenadas com sucesso (ocupadas no início).\n");
}



void liberarVaga() {
    int nv;
    printf("Qual vaga você quer liberar? ");
    scanf("%d", &nv);

    if (nv < 1 || nv > 50) {
        printf("Número de vaga inválido.\n");
        return;
    }

    if (vagas[nv - 1] != 0) {
        vagas[nv - 1] = 0;
        printf("Vaga liberada com sucesso.\n");
    } else {
        printf("A vaga já está livre.\n");
    }
}


void contarVagas() {
    int vagasocupadas = 0;
    for (int i = 0; i < 50; i++) {
        if (vagas[i] != 0) {
            vagasocupadas++;
        }
    }
    int vagaslivres = 50 - vagasocupadas;
    printf("Tem %d vaga(s) ocupada(s).\n", vagasocupadas);
    printf("Tem %d vaga(s) livre(s).\n", vagaslivres);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    char cont;

    do {
        printf("-------------------------\n  Fila Hospitalar \n-------------------------\n");
        printf("O que deseja fazer?\n");
        printf("[1] Exibir as vagas\n[2] Cadastrar uma vaga\n[3] Liberar uma vaga\n[4] Verificar status das vagas\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirVagas();
                break;
            case 2:
                cadastrarVaga();
                break;
            case 3:
                liberarVaga();
                break;
            case 4:
                contarVagas();
                break;
            default:
                printf("Opç?o inválida.\n");
        }

        system("pause");
        getchar(); 
        printf("Deseja continuar? [S/N] ");
        scanf(" %c", &cont);
        system("cls"); 
    } while (cont == 'S' || cont == 's');

    printf("Muito obrigado por usar o programa!\n");
    return 0;
}