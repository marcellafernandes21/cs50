#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_BLOCO 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s IMAGEM\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Não foi possível abrir %s para leitura\n", argv[1]);
        return 1;
    }

    BYTE buffer[TAMANHO_BLOCO];
    int contador_jpeg = 0;
    FILE *jpeg = NULL;

    while (fread(buffer, 1, TAMANHO_BLOCO, arquivo) == TAMANHO_BLOCO)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }

            char nome_arquivo[8];
            sprintf(nome_arquivo, "%03i.jpg", contador_jpeg);

            jpeg = fopen(nome_arquivo, "w");
            if (jpeg == NULL)
            {
                fclose(arquivo);
                fprintf(stderr, "Não foi possível criar %s\n", nome_arquivo);
                return 1;
            }

            contador_jpeg++;
        }

        if (jpeg != NULL)
        {
            fwrite(buffer, 1, TAMANHO_BLOCO, jpeg);
        }
    }

    if (jpeg != NULL)
    {
        fclose(jpeg);
    }
    fclose(arquivo);

    return 0;
}

