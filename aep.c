#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char nome[100], input[50], historico_alimentar[500], sexo[10], medicamentos[300], doencas_preexistentes[300], alergias[200], habitos_de_vida[400], objetivos_nutricionais[300];
    int idade, sexoD;
    float peso, altura;
    int escolha;
    
    while (true) {
        printf("\n=== Sistema de Anamnese - Clinica de Nutricao ===\n\n");

        while (true) {
            printf("Nome do paciente: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            if(strlen(nome) == 0) {
                printf("Insira dados, esses dados são importantes para o exame!\n");
                continue;
            }
            nome[strlen(nome)] = '\n';
            nome[strlen(nome)+1] = '\0';
            break;
        }
        
        while (1) {
            printf("Idade: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        
            if (strlen(input) == 0) {
                printf("Digite um valor!\n");
                continue;
            }
        
            if (sscanf(input, "%d", &idade) != 1) {
                printf("Valor invalido! Digite apenas numeros.\n");
                continue;
            }
            break;
        }
    
        while (true) {
            printf("Sexo: (1: Masculino / 2: Feminino / 3: Outro) ");
            scanf(" %d", &sexoD);
            if (sexoD == 1) {
                strcpy(sexo, "Masculino");
                break;
            } else if (sexoD == 2) {
                strcpy(sexo, "Feminino");
                break;
            } else if (sexoD == 3) {
                strcpy(sexo, "Outro");
                break;
            } else {
                printf("Digite um valor valido!!\n");
                continue;
            }
        }
        getchar();

        while (true) {
            printf("Peso (kg): ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        
            if (strlen(input) == 0) {
                printf("Digite um valor!\n");
                continue;
            }
        
            if (sscanf(input, "%f", &peso) != 1) {
                printf("Valor invalido! Digite apenas numeros.\n");
                continue;
            }
            break;
        }
        
        while (true) {
            printf("Altura (m): ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        
            if (strlen(input) == 0) {
                printf("Digite um valor!\n");
                continue;
            }
        
            if (sscanf(input, "%f", &altura) != 1) {
                printf("Valor invalido! Digite apenas numeros.\n");
                continue;
            }
            break;
        }
        
        while(true) {
            printf("\nHistorico alimentar:\n> ");
            fgets(historico_alimentar, sizeof(historico_alimentar), stdin);
            historico_alimentar[strcspn(historico_alimentar, "\n")] = '\0';
            if(strlen(historico_alimentar) == 0) {
                printf("Insira dados, esses dados são importantes para o exame!\n");
                continue;
            }
            historico_alimentar[strlen(historico_alimentar)] = '\n';
            historico_alimentar[strlen(historico_alimentar)+1] = '\0';
            break;
        }
    
        printf("\nDoencas pre-existentes: (Não digite nada em caso de inexistencia)\n> ");
        fgets(doencas_preexistentes, sizeof(doencas_preexistentes), stdin);
    
        printf("\nMedicamentos em uso: (Não digite nada em caso de inexistencia)\n> ");
        fgets(medicamentos, sizeof(medicamentos), stdin);
    
        printf("\nAlergias: (Não digite nada em caso de inexistencia)\n> ");
        fgets(alergias, sizeof(alergias), stdin);
    
        while(true) {
            printf("\nHabitos de vida:\n> ");
            fgets(habitos_de_vida, sizeof(habitos_de_vida), stdin);
            habitos_de_vida[strcspn(habitos_de_vida, "\n")] = '\0';
            if (strlen(habitos_de_vida) == 0) {
                printf("Insira dados, esses dados são importantes para o exame!\n");
                continue;
            }
            habitos_de_vida[strlen(habitos_de_vida)] = '\n';
            habitos_de_vida[strlen(habitos_de_vida)+1] = '\0';
            break;
        }
    
        while(true) {
            printf("\nObjetivos nutricionais:\n> ");
            fgets(objetivos_nutricionais, sizeof(objetivos_nutricionais), stdin);
            objetivos_nutricionais[strcspn(objetivos_nutricionais, "\n")] = '\0';
            if(strlen(objetivos_nutricionais) == 0) {
                printf("Insira dados, esses dados são importantes para o exame!\n");
                continue;
            }
            objetivos_nutricionais[strlen(objetivos_nutricionais)] = '\n';
            objetivos_nutricionais[strlen(objetivos_nutricionais)+1] = '\0';
            break;
        }


        printf("\n\n=== RESUMO DA ANAMNESE ===\n");
        printf("Nome: %s", nome);
        printf("Idade: %d\n", idade);
        printf("Sexo: %s\n", sexo);
        printf("Peso: %.2f kg\n", peso);
        printf("Altura: %.2f m\n", altura);
        printf("IMC: %.2f\n", peso / (altura * altura));
        printf("\nHistorico Alimentar: %s", historico_alimentar);
        printf("Doencas Pre-existentes: %s", doencas_preexistentes);
        printf("Medicamentos: %s", medicamentos);
        printf("Alergias: %s", alergias);
        printf("Habitos de Vida: %s", habitos_de_vida);
        printf("Objetivos Nutricionais: %s", objetivos_nutricionais);
        
        printf("\nDeseja cadastrar mais um cliente?(1) Sim / 2) Não)\n");
        scanf(" %d", &escolha);
        if (escolha == 1) {
            continue;
        } else {
            printf("Saindo da Anamnese...\n");
            break;
        }
        
    }
    return 0;
}
