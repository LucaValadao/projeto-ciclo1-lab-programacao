#ifndef CONTATOS_H              
#define CONTATOS_H

#define MAX_CONTATOS 100
#define TAM_NOME 100
#define TAM_TELEFONE 20
#define TAM_EMAIL 100

 

typedef struct Contato{
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
    int ativo; 

} Contato;

void cadastrarContato(Contato contatos[], int *total); 
void listarContatos(Contato contatos[], int total);
int buscarContato(Contato contatos[], int total, char nome[]);
void editarContato(Contato contatos[], int total);
void removerContato(Contato contatos[], int *total);
int contarNomesMaioresQueN(Contato contatos[], int total, size_t n);

#endif 


