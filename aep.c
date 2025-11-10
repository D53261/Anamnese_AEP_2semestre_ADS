#include <stdio.h>
#include <string.h>
#include <stdbool.h>

float lerFloat(char mensagem[]) {
    float valor;
    char buffer[50];

    while (1) {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%f", &valor) == 1) {
            return valor;
        } else {
            printf("Valor inválido, digite novamente.\n");
        }
    }
}

int lerInt(char mensagem[]) {
    int valor;
    char buffer[50];

    while (1) {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", &valor) == 1) {
            return valor;
        } else {
            printf("Digite apenas números!\n");
        }
    }
}

int main() {

    char nome[100], historico[500], sexo[20];
    char medicamentos[300], doencas[300], alergias[200];
    char habitos[400], objetivos[300];

    float peso, altura;
    int idade, escolha, opcaoSexo;

    while (true) {

        // Nome obrigatório
        do {
            printf("\nNome do paciente: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;

            if (strlen(nome) == 0) {
                printf("Campo obrigatório!\n");
            }
        } while (strlen(nome) == 0);

        idade = lerInt("Idade: ");

        // Escolha do sexo
        do {
            printf("Sexo (1-Masculino / 2-Feminino / 3-Outro): ");
            scanf("%d", &opcaoSexo);
            getchar(); // limpa buffer do teclado

            if (opcaoSexo == 1) strcpy(sexo, "Masculino\n");
            else if (opcaoSexo == 2) strcpy(sexo, "Feminino\n");
            else if (opcaoSexo == 3) strcpy(sexo, "Outro\n");
            else printf("Opção inválida!\n");

        } while (opcaoSexo < 1 || opcaoSexo > 3);

        peso = lerFloat("Peso (kg): ");
        altura = lerFloat("Altura (m): ");

        // Campos obrigatórios de texto
        do {
            printf("\nHistórico alimentar:\n> ");
            fgets(historico, sizeof(historico), stdin);
        } while (strlen(historico) <= 1);

        // Campos opcionais
        printf("\nDoenças preexistentes (vazio = nenhuma):\n> ");
        fgets(doencas, sizeof(doencas), stdin);

        printf("\nMedicamentos (vazio = nenhum):\n> ");
        fgets(medicamentos, sizeof(medicamentos), stdin);

        printf("\nAlergias (vazio = nenhuma):\n> ");
        fgets(alergias, sizeof(alergias), stdin);

        do {
            printf("\nHábitos de vida:\n> ");
            fgets(habitos, sizeof(habitos), stdin);
        } while (strlen(habitos) <= 1);

        do {
            printf("\nObjetivos nutricionais:\n> ");
            fgets(objetivos, sizeof(objetivos), stdin);
        } while (strlen(objetivos) <= 1);

        // Resumo final
        printf("\n=== RESUMO DA ANAMNESE ===\n");
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Sexo: %s", sexo);
        printf("Peso: %.2f kg\n", peso);
        printf("Altura: %.2f m\n", altura);
        printf("IMC: %.2f\n", peso / (altura * altura));
        printf("Histórico Alimentar: %s", historico);
        printf("Doenças Pre-existentes: %s", doencas);
        printf("Medicamentos: %s", medicamentos);
        printf("Alergias: %s", alergias);
        printf("Hábitos de Vida: %s", habitos);
        printf("Objetivos Nutricionais: %s", objetivos);

        escolha = lerInt("\nCadastrar outro paciente? (1-Sim / 2-Não): ");

        if (escolha != 1) {
            printf("Saindo...\n");
            break;
        }
    }

    return 0;
}
