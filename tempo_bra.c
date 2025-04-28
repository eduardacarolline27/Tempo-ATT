#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Função para exibir data e hora atual
void exibirDataHoraAtual(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);
    printf("Data e Hora atual: %02d/%02d/%04d %02d:%02d:%02d\n",
           tempoLocal->tm_mday,
           tempoLocal->tm_mon + 1,
           tempoLocal->tm_year + 1900,
           tempoLocal->tm_hour,
           tempoLocal->tm_min,
           tempoLocal->tm_sec);
}

// Função para exibir data e hora no formato UTC
void exibirDataHoraUTC(){
    time_t agora = time(NULL);
    struct tm *tempoUTC = gmtime(&agora);
    printf("Data e Hora em UTC: %02d/%02d/%04d %02d:%02d:%02d\n",
           tempoUTC->tm_mday,
           tempoUTC->tm_mon + 1,
           tempoUTC->tm_year + 1900,
           tempoUTC->tm_hour,
           tempoUTC->tm_min,
           tempoUTC->tm_sec);
}

// Função para calcular tempo decorrido
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

// Função para adicionar intervalo de tempo à data atual
void adicionarIntervaloTempo(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);

    printf("Data e hora atuais: %02d/%02d/%04d %02d:%02d:%02d\n",
           tempoLocal->tm_mday,
           tempoLocal->tm_mon + 1,
           tempoLocal->tm_year + 1900,
           tempoLocal->tm_hour,
           tempoLocal->tm_min,
           tempoLocal->tm_sec);

    // Adicionando 5 dias à data atual
    tempoLocal->tm_mday += 5;

    time_t novoTempo = mktime(tempoLocal);
    struct tm *novoTempoLocal = localtime(&novoTempo);
    printf("Data e hora após adicionar 5 dias: %02d/%02d/%04d %02d:%02d:%02d\n",
           novoTempoLocal->tm_mday,
           novoTempoLocal->tm_mon + 1,
           novoTempoLocal->tm_year + 1900,
           novoTempoLocal->tm_hour,
           novoTempoLocal->tm_min,
           novoTempoLocal->tm_sec);
}

// Função para formatar data e hora
void formatadorDataHora(){
    time_t agora = time(NULL);
    struct tm *tempoLocal = localtime(&agora);
    char buffer[80];

    strftime(buffer, 80, "Hoje é %A, %d de %B de %Y, %H:%M:%S.", tempoLocal);
    printf("Data e hora formatadas: %s\n", buffer);
}

// Função principal
int main() {
    int opcao;

    do {
        printf("\nMenu de Operações com o Tempo\n");
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
