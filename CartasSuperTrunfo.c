#include <stdio.h>

// 1. Definição da Estrutura de Dados 
typedef struct {
    // 1. Estado (char)
    char estado;
     // 2. Código da Carta (ex: A01). Precisa de 4 espaços (3 chars + 1 para '\0')
    char codigo[4]; 
    // 3. Nome da Cidade. Vamos dar 50 espaços, o que é um bom limite.
    char nome[50]; 
    // 4. População (int)
    int populacao; 
    // 5. Área (float)
    float area; 
    // 6. PIB (float)
    float pib; 
    // 7. Número de Pontos Turísticos (int)
    int pontos_turisticos;
    
} Carta; // Este é o apelido que usaremos para declarar variáveis

int main() {
    
    // 2. Declaração das duas cartas (as variáveis)
    Carta carta1;
    Carta carta2;
    
    // ---------------------------------
    
    return 0;
}


void ler_carta(Carta *c) {
    printf("\n--- ENTRADA DE DADOS DA CARTA ---\n");
    
    // 1. Estado (char)
    printf("Estado (A a H): ");
    scanf(" %c", &c->estado); 
    
    // 2. Código (string)
    printf("Código da Carta (ex: A01): ");
    scanf("%s", c->codigo); 
    
    // 3. Nome da Cidade (string - simples)
    printf("Nome da Cidade: ");
    scanf("%s", c->nome); 
    
    // 4. População (int)
    printf("População (número de habitantes): ");
    scanf("%d", &c->populacao); 
    
    // 5. Área (float)
    printf("Área (em km²): ");
    scanf("%f", &c->area); 
    
    // 6. PIB (float)
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &c->pib); 
    
    // 7. Pontos Turísticos (int)
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void exibir_carta(Carta c, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", c.estado); 
    printf("Código: %s\n", c.codigo); 
    printf("Nome da Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao); 
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontos_turisticos); 
}

int main() {
    
    Carta carta1; 
    Carta carta2; 
    
    // 1. Chamar ler_carta para a Carta 1
    ler_carta(&carta1); 
    
    // 2. Chamar ler_carta para a Carta 2
    ler_carta(&carta2);
    
    // ----------------------------------------------------
    
    printf("\n\n#############################################");
    printf("\n### EXIBINDO DADOS DAS CARTAS CADASTRADAS ###");
    printf("\n#############################################\n");
    
    // 3. Chamar exibir_carta para a Carta 1
    exibir_carta(carta1, 1);

    // 4. Chamar exibir_carta para a Carta 2
    exibir_carta(carta2, 2);
    
    return 0;
}
