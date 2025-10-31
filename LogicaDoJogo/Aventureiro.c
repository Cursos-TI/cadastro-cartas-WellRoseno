#include <stdio.h>
#include <string.h>

// Estrutura da carta
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
    // ====== Cartas pré-cadastradas ======
    Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculo dos indicadores derivados
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    int opcao;

    // ====== Menu de seleção ======
    printf("===== SUPER TRUNFO - COMPARAÇÃO ENTRE CARTAS =====\n");
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("0 - Sair\n");
    printf("\nDigite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=====================================\n");

    switch (opcao) {
        case 1: // População
            printf("Comparação de Cartas (Atributo: População)\n\n");
            printf("Carta 1 - %s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("Carta 2 - %s: %d habitantes\n", carta2.nome, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 2: // Área
            printf("Comparação de Cartas (Atributo: Área)\n\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.nome, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.nome, carta2.area);

            if (carta1.area > carta2.area)
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Comparação de Cartas (Atributo: PIB)\n\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", carta1.nome, carta1.pib);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", carta2.nome, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Comparação de Cartas (Atributo: Pontos Turísticos)\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", carta1.nome, carta1.num_pontos_turisticos);
            printf("Carta 2 - %s: %d pontos turísticos\n", carta2.nome, carta2.num_pontos_turisticos);

            if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos)
                printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos)
                printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 5: // Densidade Demográfica (regra invertida)
            printf("Comparação de Cartas (Atributo: Densidade Demográfica)\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nome, carta1.densidade_populacional);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nome, carta2.densidade_populacional);

            if (carta1.densidade_populacional < carta2.densidade_populacional)
                printf("\nResultado: Carta 1 (%s) venceu! (menor densidade vence)\n", carta1.nome);
            else if (carta2.densidade_populacional < carta1.densidade_populacional)
                printf("\nResultado: Carta 2 (%s) venceu! (menor densidade vence)\n", carta2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 0:
            printf("Saindo do jogo... Até a próxima!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
