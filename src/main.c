#include <stdio.h>
#include <string.h>
            // Biblioteca padrão
#include "contatos.h"

int main(){
    Contato contatos[MAX_CONTATOS];
    int total = 0;
    int opcao;  

    do {
        // Menu principal
        printf("\n===== GERENCIADOR DE CONTATOS =====\n");
        printf("1) Cadastrar\n");
        printf("2) Listar\n");
        printf("3) Buscar por nome\n");
        printf("4) Editar\n");
        printf("5) Excluir\n");
        printf("6) Estatisticas (recursivo)\n");
        printf("7) Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);  // Lê opção
        getchar();            // Limpa buffer

        switch(opcao) {

            case 1:
                cadastrarContato(contatos, &total);
                break;

            case 2:
                listarContatos(contatos, total);
                break;

            case 3: {
                char nome[TAM_NOME];
                printf("Nome para buscar: ");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0;

                int indice = buscarContato(contatos, total, nome);

                if (indice == -1)
                    printf("Contato nao encontrado!\n");
                else
                    printf("Contato encontrado no indice %d\n", indice);
                break;
            }

            case 4:
                editarContato(contatos, total);
                break;

            case 5:
                removerContato(contatos, &total);
                break;

            case 6: {
                int n;
                printf("Contar nomes maiores que: ");
                scanf("%d", &n);
                getchar();

                int resultado = contarNomesMaioresQueN(contatos, total, n);

                printf("Total: %d contatos\n", resultado);
                break;
            }

            case 7:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 7); // Repete até sair

    return 0; // Finaliza programa

}