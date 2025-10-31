#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta
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
    // ===== Cartas pré-cadastradas =====
    Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // ===== Cálculos derivados =====
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    int opcao1, opcao2;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n\n");
    printf("Cartas disponíveis:\n");
    printf("Carta 1: %s (%s)\n", carta1.nome, carta1.estado);
    printf("Carta 2: %s (%s)\n\n", carta2.nome, carta2.estado);

    // ===== MENU 1 =====
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // ===== MENU 2 (dinâmico) =====
    printf("\nAgora escolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i == opcao1) continue; // não mostrar o mesmo atributo
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
            case 6: printf("6 - PIB per Capita\n"); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("\nErro: os atributos devem ser diferentes!\n");
        return 1;
    }

    printf("\n=====================================\n");

    // ===== Função auxiliar de comparação =====
    // Atribui o valor correspondente de cada atributo escolhido
    switch (opcao1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.num_pontos_turisticos; valor1_c2 = carta2.num_pontos_turisticos; break;
        case 5: valor1_c1 = carta1.densidade_populacional; valor1_c2 = carta2.densidade_populacional; break;
        case 6: valor1_c1 = carta1.pib_per_capita; valor1_c2 = carta2.pib_per_capita; break;
        default: printf("Opção inválida!\n"); return 1;
    }

    switch (opcao2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.num_pontos_turisticos; valor2_c2 = carta2.num_pontos_turisticos; break;
        case 5: valor2_c1 = carta1.densidade_populacional; valor2_c2 = carta2.densidade_populacional; break;
        case 6: valor2_c1 = carta1.pib_per_capita; valor2_c2 = carta2.pib_per_capita; break;
        default: printf("Opção inválida!\n"); return 1;
    }

    // ===== Comparação individual =====
    printf("Comparação de cartas:\n\n");
    printf("Carta 1 - %s:\n", carta1.nome);
    printf("Carta 2 - %s:\n\n", carta2.nome);

    // Função anônima para imprimir o nome do atributo
    char *atributoNome(int opcao) {
        switch (opcao) {
            case 1: return "População";
            case 2: return "Área";
            case 3: return "PIB";
            case 4: return "Pontos Turísticos";
            case 5: return "Densidade Demográfica";
            case 6: return "PIB per Capita";
            default: return "Desconhecido";
        }
    }

    printf("Atributo 1: %s\n", atributoNome(opcao1));
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    printf("Atributo 2: %s\n", atributoNome(opcao2));
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // ===== Regras de vitória individuais =====
    int vitoria1_attr1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    int vitoria1_attr2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma_c1);
    printf("%s: %.2f\n", carta2.nome, soma_c2);
    printf("\n=====================================\n");

    // ===== Resultado Final =====
    if (soma_c1 > soma_c2)
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    else if (soma_c2 > soma_c1)
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    else
        printf("Resultado: Empate!\n");

    return 0;
}
