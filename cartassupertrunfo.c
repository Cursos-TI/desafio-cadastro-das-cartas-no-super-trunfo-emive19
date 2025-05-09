#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Função para calcular o Super Poder
float calcularSuperPoder(struct Carta c) {
    float inversoDensidade = c.densidadePopulacional > 0 ? 1.0 / c.densidadePopulacional : 0;
    float poder = (float)c.populacao +
                  c.area +
                  c.pib +
                  (float)c.pontosTuristicos +
                  c.pibPerCapita +
                  inversoDensidade;
    return poder;
}

int main() {
    struct Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        printf("Digite os dados da Carta %d:\n", i + 1);

        printf("Estado (letra de A a H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código da Carta (ex: A01): ");
        scanf(" %3s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("População: ");
        scanf("%lu", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos
        cartas[i].densidadePopulacional = cartas[i].area > 0 ? (float)cartas[i].populacao / cartas[i].area : 0;
        cartas[i].pibPerCapita = cartas[i].populacao > 0 ? (cartas[i].pib * 1000000000) / cartas[i].populacao : 0;
        cartas[i].superPoder = calcularSuperPoder(cartas[i]);

        printf("\n");
    }

    // Comparações
    printf("Comparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", cartas[0].populacao > cartas[1].populacao);
    printf("Área: Carta 1 venceu (%d)\n", cartas[0].area > cartas[1].area);
    printf("PIB: Carta 1 venceu (%d)\n", cartas[0].pib > cartas[1].pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", cartas[0].pontosTuristicos > cartas[1].pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", cartas[0].densidadePopulacional < cartas[1].densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", cartas[0].pibPerCapita > cartas[1].pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", cartas[0].superPoder > cartas[1].superPoder);

    return 0;
}
