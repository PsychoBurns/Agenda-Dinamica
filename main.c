#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* STRUCT PARA INFORMAÇOES DOS CONTATOS DA AGENDA
IRA POSSUIR 10 ESPAÇOS PARA CONTATO*/
typedef struct Pessoa
{
    int id;
    char nome[100];
    char telefone[20];
    char email[100];
    char dataNascimento[10];
    char obs[200];
    struct Pessoa *proximo;
} Pessoa;

/* DECLARAÇÃO DE VAIRAVEIS GLOBAIS*/
Pessoa *p = NULL, *aux, *ultimo;
int i;
/*FIM DA DECLARAÇÃO DE VARIAVEIS*/

/* INICIO DA FUNÇÃO MENU
IRA POSSUIR TODOS AS OUTRAS FUNÇOES DO CODIGO*/
void menu()
{
    int opcMenu;
    do
    {
        printf("____________________________\n");
        printf("|         AGENDA           |\n");
        printf("|__________________________|\n");
        printf("| [1] -[CADASTRAR]         |\n");
        printf("| [2] -[LISTAR]            |\n");
        printf("| [3] -[BUSCAR]            |\n");
        printf("| [4]- [ALTERAR]           |\n");
        printf("| [5]- [EXCLUIR]           |\n");
        printf("| [0]- [SAIR]              |\n");
        printf("|__________________________|\n");
        scanf("%d", &opcMenu);

        switch (opcMenu)
        {
        case 1:
            /* Cadastro */
            cadastro();
            break;

        case 2:
            /* Listar */
            listar();
            break;

        case 3:
            /* Buscar */
            break;

        case 4:
            /* Alterar */
            break;
        case 5:
            /* Excluir */
            break;
        case 0:
            /* Sair */
            break;

        default:
            printf("Opção invalida!");
            printf("Digite um opção valida!");
            break;
        }

    } while (opcMenu != 0);
}
/* FIM DA FUNÇÃO MENU*/

/* INICIO DA FUNÇÃO CADASTRAR CONTATO*/
void cadastro()
{
    int opcCadastro;
    int id = 1;
    printf("____________________________\n");
    printf("|  CADASTRO DE CONTATO     |\n");
    printf("|__________________________|\n");

    for (i = 0; i < 10; i++)
    {
        aux = malloc(sizeof(Pessoa));

        aux->id = id++;
        printf("Nome Completo: \n");
        fflush(stdin);
        scanf("%s", aux->nome);
        printf("Telefone | Ex: (00) 0000-0000 \n");
        fflush(stdin);
        scanf("%s", aux->telefone);
        printf("Email: \n");
        fflush(stdin);
        scanf("%s", aux->email);
        printf("Data de Nascimento | Ex: dd/mm/aaaa \n");
        fflush(stdin);
        scanf("%s", aux->dataNascimento);
        printf("Observação sobre o contato: \n");
        fflush(stdin);
        scanf("%s", aux->obs);

        aux->proximo = NULL;

        if (p == NULL)
        {
            p = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->proximo = aux;
            ultimo = aux;
        }
        printf("____________________________________\n");
        printf("| Cadastro realizado com sucesso ! |\n");
        printf("|__________________________________|\n");
        printf("Deseja realizar outro cadastro?\n ");
        printf("________________\n");
        printf("| [1] -[SIM]   |\n");
        printf("| [2] -[NAO]   |\n");
        printf("|______________|\n");
        scanf("%d", &opcCadastro);
        if (opcCadastro == 2)
        {
            break;
        }
    }
    return (0);
}
/* FIM DA FUNÇÃO CADASTRAR CONTATO*/

/* INICIO DA FUNÇÃO LISTAR CONTATO
IRA LISTAR TODOS OS CONTATOS DA AGENDA*/
void listar()
{
    aux = p;
    int opcListar;
    printf("____________________________\n");
    printf("|   LISTAR CONTATOS        |\n");
    printf("|__________________________|\n");

    do
    {
        for (i = 0; i < 10; i++)
        {
            printf("__________________________________\n");
            printf("Id : %d   Nome: %s  Telefone: %s \n", aux->id, aux->nome, aux->telefone);
            printf("__________________________________\n");

            aux = aux->proximo;
        }
        printf("Deseja continuar?\n ");
        printf("________________\n");
        printf("| [1] -[SIM]   |\n");
        printf("| [2] -[NAO]   |\n");
        printf("|______________|\n");
        scanf("%d", &opcListar);
    } while (opcListar == 1);
}
/* FIM DA FUNÇÃO LISTAR*/

int main(void)
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    menu();
    return 0;
}