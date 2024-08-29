#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a estrutura de uma pessoa
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

// Função para escolher aleatoriamente um alelo
char random_allele(void)
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

// Função para criar uma família de um tamanho de geração especificado
person *create_family(int generations)
{
    // Aloca memória para uma nova pessoa
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        return NULL;
    }

    // Caso base: sem pais
    if (generations > 1)
    {
        // Caso recursivo: criar pais
        new_person->parents[0] = create_family(generations - 1);
        new_person->parents[1] = create_family(generations - 1);

        // Atribuir alelos aleatoriamente com base nos pais
        new_person->alleles[0] = new_person->parents[0]->alleles[rand() % 2];
        new_person->alleles[1] = new_person->parents[1]->alleles[rand() % 2];
    }
    else
    {
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

// Função para imprimir a árvore genealógica
void print_family(person *p, int generation)
{
    // Caso base: sem pessoa
    if (p == NULL)
    {
        return;
    }

    // Imprime o número da geração
    for (int i = 0; i < generation; i++)
    {
        printf(" ");
    }

    // Imprime a pessoa
    printf("Geração %i: tipo sanguíneo %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Imprime os pais
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Função para liberar a memória alocada
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    // Libera os pais recursivamente
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Libera a própria pessoa
    free(p);
}

int main(void)
{
    // Semente para o gerador de números aleatórios
    srand(time(0));

    // Cria uma família com 3 gerações
    person *p = create_family(3);

    // Imprime a árvore genealógica
    print_family(p, 0);

    // Libera a memória
    free_family(p);

    return 0;
}
