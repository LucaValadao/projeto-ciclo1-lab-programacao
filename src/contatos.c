#include <stdio.h>      // Biblioteca para entrada e saída
#include <string.h>     // Biblioteca para manipulação de strings
#include "contatos.h"   // Inclusão do header criado


// Cadastrar contato 

void cadastrarContato(Contato contatos[], int *total){
    if (*total >= MAX_CONTATOS){
        printf("Limite maximo de contatos ja foi atingido!");
        return; 
    }

    printf("Nome: ");
    fgets(contatos[*total].nome, TAM_NOME, stdin); // fgets(destino, tamanho_maximo, origem); -> *total - Está pegando a posição do próximo contato disponível.
    //stdin é a entrada do teclado
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = 0; // estrutura que exclui \n, pois toda string vem com o \n padrão q pode causar erros

    printf("Telefone: ");
    fgets(contatos[*total].telefone, TAM_TELEFONE, stdin); 
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = 0;

    printf("Email: ");
    fgets(contatos[*total].email, TAM_EMAIL, stdin);
    contatos[*total].email[strcspn(contatos[*total].email, "\n")] = 0;

    contatos[*total].ativo = 1; // marcar como ativo 

    (*total)++; // Isso passa para a proxima posição do array(banco de dados) onde o proximo cadastro ja vai para uma posição livre 

    printf("Cadastro concluido!\n");

}


void listarContatos(Contato contatos[], int total){
    for (int i = 0; i < total; i++){
        if (contatos[i].ativo){
            printf("\n[%d]\n", i);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
        }
    }
}

int buscarContato(Contato contatos[], int total, char nome[]){  // int - pois vai retornar um valor inteiro caso ache ou -1 caso nn ache.
    for (int i = 0; i < total; i++){
        if(contatos[i].ativo && strcmp(contatos[i].nome, nome) == 0){   // strcmd compara duas strings retornam 0 ser forem iguais
            return i;
        }
    }
    return -1;

}

void editarContato(Contato contatos[], int total){
    char nome[TAM_NOME]; // variavel auxiliar 

    printf("Digite o nome do cantato a editar: ");
    fgets(nome, TAM_NOME, stdin); // fgets lê a linha inteira enquanto scanf para no primeiro espaço 
    nome[strcspn(nome, "\n")] = 0; //Ela remove o caractere de quebra de linha inserido pelo fgets, substituindo o '\n' por '\0', garantindo que a string seja comparada corretamente.


    int indice = buscarContato(contatos, total, nome);

    if (indice == -1){
        printf("Usuário não cadastrado!\n");
        return;
    }

    printf("Novo telefone: ");
    fgets(contatos[indice].telefone, TAM_TELEFONE, stdin );  // substitui no espaço da memoria contatos[indice].telefone o novo telefone 
    contatos[indice].telefone[strcspn(contatos[indice].telefone, "\n")] = 0; // Ela remove o caractere de quebra de linha inserido pelo fgets, localizando o '\n' com strcspn e substituindo por '\0', garantindo que a string fique corretamente formatada.

    printf("Novo email: ");
    fgets(contatos[indice].email, TAM_EMAIL, stdin );  // substitui no espaço da memoria contatos[indice].telefone o novo telefone 
    contatos[indice].email[strcspn(contatos[indice].email, "\n")] = 0;

    printf("Contato Atualizado!\n");

}


void removerContato(Contato contatos[], int *total){
    char nome[TAM_NOME];

    printf("Digite o nome do contato a remover: ");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;

    int indice = buscarContato(contatos, *total, nome);

    if (indice == -1){
        printf("Usuário não cadastrado!\n");
        return;
    }

    contatos[indice].ativo = 0;

    printf("Contato removido! \n");

}


int contarNomesMaioresQueN(Contato contatos[], int total, size_t n){

    // Caso base: se não houver contatos
    if (total == 0)
        return 0;

    int contaAtual = 0;

    // Verifica último elemento
    if (contatos[total - 1].ativo &&
        strlen(contatos[total - 1].nome) > n) {
        contaAtual = 1;
    }

    // Soma resultado atual + chamada recursiva
    return contaAtual + contarNomesMaioresQueN(contatos, total - 1, n);
}



// para executar abrir o terminal dentro do projetoCiclo1 e executar primeiro 
//gcc main.c contatos.c -o programa.exe
// Depois 
// .\programa.exe

