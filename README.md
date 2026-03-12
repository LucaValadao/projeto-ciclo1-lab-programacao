# Sistema de Gerenciamento de Contatos em C

Integrantes
Luca Constâncio C. Valadão
Gabriel Oliveira Freitas 
Nicolas Santana Lins
Carlos Augusto Rodrigues
Artur Rodrigues

## Descrição

Este projeto consiste em um **sistema simples de gerenciamento de contatos**, desenvolvido em **linguagem C**, que permite ao usuário realizar operações básicas de manipulação de dados como cadastro, listagem, busca, edição e remoção de contatos.

O sistema foi desenvolvido com foco em **boas práticas de programação**, organização de código em múltiplos arquivos e utilização de conceitos fundamentais da linguagem C, como:

- Structs
- Vetores
- Ponteiros
- Manipulação de strings
- Modularização com arquivos `.h` e `.c`
- Recursividade

O programa é executado via **terminal**, utilizando um **menu interativo** para navegação entre as funcionalidades.

---

# Funcionalidades

O sistema permite:

✔ Cadastrar novos contatos  
✔ Listar contatos cadastrados  
✔ Buscar contato pelo nome  
✔ Editar telefone e email de um contato  
✔ Remover contato (remoção lógica)  
✔ Contar quantos contatos possuem nome com tamanho maior que **N** (utilizando **recursão**)

---

# Estrutura do Projeto

O projeto foi organizado seguindo boas práticas de separação entre **implementação** e **interface**.

### Descrição das pastas

| Pasta | Função |
| `include/` | Contém os arquivos de cabeçalho (`.h`) |
| `src/` | Contém os arquivos de implementação (`.c`) |
| `README.md` | Documentação do projeto |

---

# Estrutura de Dados

O sistema utiliza uma **struct** para representar um contato:

```c
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
    int ativo;
} Contato;

### Campos da estrutura

| Campo | Descrição |
| `nome` | Nome do contato |
| `telefone` | Telefone do contato |
| `email` | Email do contato |
| `ativo` | Indica se o contato está ativo (`1`) ou removido (`0`) |

A variável `ativo` é utilizada para implementar **remoção lógica**, evitando reorganização do vetor de contatos.

---

# 🔧 Decisões de Projeto

| Decisão | Justificativa |

| Uso de `struct` | Permite agrupar informações relacionadas a um contato |
| Vetor de contatos | Simplifica o armazenamento dos dados |
| `fgets` para leitura | Permite ler strings com espaços e evita problemas de buffer |
| Remoção lógica | Evita reorganização do vetor após exclusões |
| Recursividade | Aplicação prática de funções recursivas |

---

# Compilação e Execução

### Compilação

Para compilar o programa utilizando **GCC**, navegue até a pasta onde estão os arquivos `.c` e execute:

```bash
gcc main.c contatos.c -o programa.exe


### Execução
.\programa.exe
