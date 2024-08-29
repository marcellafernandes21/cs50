#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pessoa
{
    struct pessoa *pais[2];
    char alelos[2];
} pessoa;

const int GERACOES = 3;
const int TAMANHO_INDENTACAO = 4;

pessoa *criar_familia(int geracoes);
void imprimir_familia(pessoa *p, int geracao);
void liberar_familia(pessoa *p);
char alelo_aleatorio();

int main(void)
{
    srand(time(0));

    pessoa *p = criar_familia(GERACOES);

    imprimir_familia(p, 0);

    liberar_familia(p);
}

pessoa *criar_familia(int geracoes)
{
    pessoa *nova_pessoa = malloc(sizeof(pessoa));
    if (nova_pessoa == NULL)
    {
        return NULL;
    }

    if (geracoes > 1)
    {
        pessoa *pai0 = criar_familia(geracoes - 1);
        pessoa *pai1 = criar_familia(geracoes - 1);

        nova_pessoa->pais[0] = pai0;
        nova_pessoa->pais[1] = pai1;

        nova_pessoa->alelos[0] = pai0->alelos[rand() % 2];
        nova_pessoa->alelos[1] = pai1->alelos[rand() % 2];
    }
    else
    {
        nova_pessoa->pais[0] = NULL;
        nova_pessoa->pais[1] = NULL;

        nova_pessoa->alelos[0] = alelo_aleatorio();
        nova_pessoa->alelos[1] = alelo_aleatorio();
    }

    return nova_pessoa;
}

void liberar_familia(pessoa *p)
{
    if (p == NULL)
    {
        return;
    }

    liberar_familia(p->pais[0]);
    liberar_familia(p->pais[1]);

    free(p);
}

void imprimir_familia(pessoa *p, int geracao)
{
    if (p == NULL)
    {
        return;
    }

    for (int i = 0; i < geracao * TAMANHO_INDENTACAO; i++)
    {
        printf(" ");
    }

    if (geracao == 0)
    {
        printf("Filho (Geração %i): tipo sanguíneo %c%c\n", geracao, p->alelos[0], p->alelos[1]);
    }
    else if (geracao == 1)
    {
        printf("Pai (Geração %i): tipo sanguíneo %c%c\n", geracao, p->alelos[0], p->alelos[1]);
    }
    else
    {
        for (int i = 0; i < geracao - 2; i++)
        {
            printf("Bisavô-");
        }
        printf("Avô (Geração %i): tipo sanguíneo %c%c\n", geracao, p->alelos[0], p->alelos[1]);
    }

    imprimir_familia(p->pais[0], geracao + 1);
    imprimir_familia(p->pais[1], geracao + 1);
}

char alelo_aleatorio()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
