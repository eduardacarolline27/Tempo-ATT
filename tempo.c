#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void exibirDataHoraAtual(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);
    printf("Data e Hora atual: %s", asctime(tempoLocal));
}

void exibirDataHoraUTC(){
    time_t agora = time(NULL);
    struct tm *tempoUTC = gmtime(&agora);
    printf("Data e Hora em UTC: %s", asctime(tempoUTC));
}

void calcularTempoDecorrido(){
    time_t inicio, fim;
    double tempoDecorrido;

    inicio = time(NULL);
    printf("Pressione ENTER para parar o cronômetro...\n");
    getchar(); // Aguardar o usuário pressionar ENTER
    fim = time(NULL);

    tempoDecorrido = difftime(fim, inicio);
    printf("Tempo decorrido: %.2f segundos\n", tempoDecorrido);
}

void adicionarIntervaloTempo(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);
    
    printf("Data e hora atuais: %s", asctime(tempoLocal));

    //Adiconnando 5 a data atual
    tempoLocal->tm_mday += 5;

    time_t novoTempo = mktime(tempoLocal);
    printf("Data e hora após adicionar 5 dias: %s", asctime(localtime(&novoTempo)));
    
}

void formatadorDataHora(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);
    char buffer[80];

    strftime(buffer, 80, "Hoje é %A, %d de %B de %Y, %H:%M:%S.", tempoLocal);
    printf("Data e hora formatadas: %s\n", buffer);
}

int main() {
    int opcao;

    do {
        printf("\n Menu de Operações com o Tempo\n");
        printf("1. Exibir Data e Hora atual\n");
        printf("2. Exibir Data e Hora no Formato UTC\n");
        printf("3. Calcular Tempo Decorrido\n");
        printf("4. Adicionar Intervalo de Tempo à Data Atual\n");
        printf("5. Formatador de Data e Hora\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Capturar o ENTER do teclado

        switch (opcao) {
            case 1:
                exibirDataHoraAtual();
                break;
            case 2:
                exibirDataHoraUTC();
                break;
            case 3:
                calcularTempoDecorrido();
                break;
            case 4:
                adicionarIntervaloTempo();
                break;
            case 5:
                formatadorDataHora();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
