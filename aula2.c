#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_sequencial(int lista[20], int tamanho, int valor) {
    int comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        if (lista[i] == valor) {
            return comparacoes;
        }
    }
    return comparacoes;
}

int busca_binaria(int lista[], int tamanho, int valor) {
    int comparacoes = 0;
    int esquerda = 0, direita = tamanho-1;
    while (esquerda <= direita) {
        comparacoes++;
        int meio = (esquerda + direita) / 2;
        if (lista[meio] == valor) {
            return comparacoes;
        } else if (lista[meio] > valor) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return comparacoes;
}

int main() {
    srand(time(NULL)); 
    FILE *fp = fopen("resultados.txt", "wt"); 
    int tamanho, valor, comparacoes_seq, comparacoes_bin;
     
    for (tamanho = 10; tamanho <= 100000; tamanho += 10) {
        int lista[tamanho];
        for (int i = 0; i < tamanho ; i++) {
            lista[i] = rand() % (tamanho*2);
        }
        comparacoes_seq=0;
        comparacoes_bin=0;

        for (int i = 0; i < tamanho; i++); {
            valor = lista[rand() % tamanho];
            comparacoes_seq += busca_sequencial(lista, tamanho, valor);
            comparacoes_bin += busca_binaria(lista, tamanho, valor);
        }
        fprintf(fp, "%d %f %f\n", tamanho, (float) comparacoes_seq/tamanho, (float) comparacoes_bin/tamanho);
    }


    fclose(fp); 
    return 0;
}
