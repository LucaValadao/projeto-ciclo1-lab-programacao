# Sistema de Gerenciamento de Contatos em C

# 👨‍💻 Integrantes e Contribuições

A seguir estão descritas as responsabilidades e contribuições de cada integrante do grupo durante o desenvolvimento do projeto **Sistema de Gerenciamento de Contatos em C**.

| Integrante | Contribuição no Projeto |
|-------------|-------------------------|
| **Luca Constâncio C. Valadão** | Responsável pela **estruturação principal do sistema e organização lógica do código**. Desenvolveu parte significativa da implementação das funcionalidades do programa, incluindo a estrutura de dados utilizada para armazenar os contatos e a integração entre as diferentes funções do sistema. Também atuou na definição da arquitetura do projeto, separando corretamente os arquivos de implementação (`.c`) e cabeçalho (`.h`), garantindo uma organização modular do código. |
| **Gabriel Oliveira Freitas** | Contribuiu diretamente na **codificação das funcionalidades do sistema**, auxiliando na implementação das operações relacionadas ao gerenciamento de contatos, como cadastro, edição e manipulação das informações armazenadas no vetor de contatos. Também colaborou na revisão da lógica de algumas funções para garantir que o sistema operasse corretamente durante a execução. |
| **Nicolas Santana Lins** | Atuou na **organização e elaboração da documentação do projeto**, sendo responsável pela estruturação e escrita do **README.md**. Além disso, realizou **testes de funcionamento do sistema**, verificando se as funcionalidades implementadas estavam operando corretamente e identificando possíveis melhorias ou ajustes no código. Também participou da revisão geral do projeto para melhorar a clareza e organização das informações apresentadas. |
| **Carlos Augusto Rodrigues** | Contribuiu na **organização e revisão da documentação do projeto**, colaborando na construção do README e na melhoria da apresentação das informações. Também participou da **realização de testes do sistema**, auxiliando na validação das funcionalidades implementadas e na identificação de possíveis inconsistências ou melhorias necessárias no funcionamento do programa. |
| **Artur Rodrigues** | Responsável pela **organização da apresentação do projeto**, incluindo a preparação dos **slides utilizados na apresentação**. Realizou o estudo do funcionamento do código desenvolvido pelo grupo para compreender a lógica do sistema e explicar corretamente suas funcionalidades durante a apresentação do trabalho. Também contribuiu na preparação do material visual utilizado para demonstrar o funcionamento do programa. |

---

### 📌 Organização do Trabalho em Equipe

O desenvolvimento do projeto foi realizado de forma colaborativa, com divisão de responsabilidades entre **desenvolvimento do código, documentação, testes e apresentação**. Essa divisão permitiu que cada integrante contribuísse em uma etapa específica do projeto, garantindo melhor organização e qualidade no resultado final.

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



