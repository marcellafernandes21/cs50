#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Número de bytes no cabeçalho do arquivo WAV
const int HEADER_SIZE = 44;

// Definindo tipos de dados para garantir tamanhos consistentes
typedef uint8_t BYTE;
typedef int16_t SAMPLE;

int main(int argc, char *argv[])
{
    // Verifica argumentos de linha de comando
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abre arquivos e determina o fator de escala
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    float factor = atof(argv[3]);

    // Abre o arquivo de entrada
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Could not open file %s.\n", input_filename);
        return 1;
    }

    // Abre o arquivo de saída
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL)
    {
        printf("Could not open file %s.\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Lê e copia o cabeçalho do arquivo
    BYTE header[HEADER_SIZE];
    fread(header, sizeof(BYTE), HEADER_SIZE, input_file);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output_file);

    // Processa amostras de áudio
    SAMPLE buffer;
    while (fread(&buffer, sizeof(SAMPLE), 1, input_file))
    {
        // Modifica o valor da amostra pelo fator
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(SAMPLE), 1, output_file);
    }

    // Fecha os arquivos
    fclose(input_file);
    fclose(output_file);

    return 0;
}
