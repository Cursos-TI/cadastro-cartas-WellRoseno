#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main() {
    Carta carta1, carta2;

    // ===== Cadastro da Carta 1 =====
    printf("Cadastro da Carta 1:\n");

    printf("Estado: ");
    scanf(" %2s", carta1.estado);

    printf("Codigo: ");
    scanf(" %3s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nome);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);

    // Cálculos
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    printf("\n---------------------------------\n");

    // ===== Cadastro da Carta 2 =====
    printf("Cadastro da Carta 2:\n");

    printf("Estado: ");
    scanf(" %2s", carta2.estado);

    printf("Codigo: ");
    scanf(" %3s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nome);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);

    // Cálculos
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    printf("\n=================================\n");

    // ===== Escolha do atributo para comparação =====
    // Atributo escolhido: PIB per Capita
    printf("Comparação de Cartas (Atributo: PIB per Capita)\n\n");

    printf("Carta 1 - %s (%s): %.2f reais\n", carta1.nome, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): %.2f reais\n", carta2.nome, carta2.estado, carta2.pib_per_capita);

    // ===== Lógica de comparação =====
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
