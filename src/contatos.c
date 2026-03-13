#include <stdio.h>      
#include <string.h>     
#include "contatos.h"   




void cadastrarContato(Contato contatos[], int *total){
    if (*total >= MAX_CONTATOS){
        printf("Limite maximo de contatos ja foi atingido!");
        return; 
    }

    printf("Nome: ");
    fgets(contatos[*total].nome, TAM_NOME, stdin); 
    
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = 0; 

    printf("Telefone: ");
    fgets(contatos[*total].telefone, TAM_TELEFONE, stdin); 
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = 0;

    printf("Email: ");
    fgets(contatos[*total].email, TAM_EMAIL, stdin);
    contatos[*total].email[strcspn(contatos[*total].email, "\n")] = 0;

    contatos[*total].ativo = 1;  

    (*total)++;  

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

int buscarContato(Contato contatos[], int total, char nome[]){  
    for (int i = 0; i < total; i++){
        if(contatos[i].ativo && strcmp(contatos[i].nome, nome) == 0){   
            return i;
        }
    }
    return -1;

}

void editarContato(Contato contatos[], int total){
    char nome[TAM_NOME]; 

    printf("Digite o nome do cantato a editar: ");
    fgets(nome, TAM_NOME, stdin); 
    nome[strcspn(nome, "\n")] = 0;

    int indice = buscarContato(contatos, total, nome);

    if (indice == -1){
        printf("Usuário não cadastrado!\n");
        return;
    }

    printf("Novo telefone: ");
    fgets(contatos[indice].telefone, TAM_TELEFONE, stdin );   
    contatos[indice].telefone[strcspn(contatos[indice].telefone, "\n")] = 0; 
    printf("Novo email: ");
    fgets(contatos[indice].email, TAM_EMAIL, stdin );  
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


    if (total == 0)
        return 0;

    int contaAtual = 0;

    
    if (contatos[total - 1].ativo &&
        strlen(contatos[total - 1].nome) > n) {
        contaAtual = 1;
    }

    
    return contaAtual + contarNomesMaioresQueN(contatos, total - 1, n);
}




