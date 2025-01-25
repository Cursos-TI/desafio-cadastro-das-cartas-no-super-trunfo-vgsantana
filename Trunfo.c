#include <stdio.h>
#include <string.h>

//Struct com as infos da carta
struct info_carta { 
    char codCarta[50];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;

};

//Struct com o nome da carta + informacoes
struct nome_carta {
    char estado[50];
    struct info_carta carta;
};

//Cadastrar os dados das cartas
void cadastraCarta(struct nome_carta *nome){
    printf("Digite o nome do Estado: ");
    fgets(nome->estado, 50, stdin);
    nome->estado[strcspn(nome->estado, "\n")] = '\0';

    printf("Digite o codigo da carta: ");
    fgets(nome->carta.codCarta, 50, stdin);
    nome->carta.codCarta[strcspn(nome->carta.codCarta, "\n")] = '\0';

    printf("Digite o nome da cidade: ");
    fgets(nome->carta.nomeCidade, 50, stdin);
    nome->carta.nomeCidade[strcspn(nome->carta.nomeCidade, "\n")] = '\0';

    printf("Digite o valor populacional: ");
    scanf("%lu", &nome->carta.populacao);

    printf("Digite a area(Km): ");
    scanf("%f", &nome->carta.area);

    printf("Digite o Pib: ");
    scanf("%f", &nome->carta.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &nome->carta.pontosTuristicos);

    nome->carta.densidadePopulacional = (nome->carta.area > 0) ? nome->carta.populacao / nome->carta.area : 0;
    nome->carta.pibPerCapita = (nome->carta.populacao > 0 ) ? nome->carta.pib / nome->carta.populacao : 0;
    nome->carta.superPoder = nome->carta.populacao + nome->carta.area + nome->carta.pib + nome->carta.pontosTuristicos + nome->carta.densidadePopulacional + nome->carta.pibPerCapita;

    getchar();

}

//Exibe os dados
void exibirDados(struct nome_carta nome){

    printf("Nome do Estado: %s\n", nome.estado);
    printf("Codigo da carta: %s\n", nome.carta.codCarta);
    printf("Nome da cidade: %s\n", nome.carta.nomeCidade);
    printf("Populacao: %lu\n", nome.carta.populacao);
    printf("Area: %.2f\n", nome.carta.area);
    printf("Pib: %.2f\n", nome.carta.pib);
    printf("Pontos Turisticos: %d\n", nome.carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", nome.carta.densidadePopulacional);
    printf("Pib per capita: %.2f\n", nome.carta.pibPerCapita);
    printf("Super poder: %.2f\n", nome.carta.superPoder);

}

//Comparar atributos das cartas
int compararAtributos(float atrib1, float atrib2, int *pontosCarta1, int *pontosCarta2){
    if (atrib1 > atrib2){
        (*pontosCarta1)++;
        return 0;
        }else if(atrib1 < atrib2){
            (*pontosCarta2)++;
            return 1;
        }else{
            (*pontosCarta1)++;
            (*pontosCarta2)++;
            return 2;
        }
}

//Compara os atributos que devem ser inversos na comparacao
int compararAtributosInvertido(float atrib1, float atrib2, int *pontosCarta1, int *pontosCarta2){
    if (atrib1 < atrib2){
        (*pontosCarta1)++;
        return 0;
        }else if(atrib1 > atrib2){
            (*pontosCarta2)++;
            return 1;
        }else{
            (*pontosCarta1)++;
            (*pontosCarta2)++;
            return 2;
        }
}

//Exibe a carta com o atributo vencedor
void atributoVencedor(struct nome_carta nome1, struct nome_carta nome2,int atributoVencedor){
    if(atributoVencedor==0){
        printf("Venceu: %s\n\n", nome1.estado);
    }else if(atributoVencedor==1){
        printf("Venceu: %s\n\n", nome2.estado);
    }else{
        printf("Empate\n\n");
    };
}

//Compara os atributos das cartas
int compararCartas(struct nome_carta nome1, struct nome_carta nome2){
    int pontosCarta1 = 0, pontosCarta2 = 0, atributo;

    printf("Nome: %s x %s\n", nome1.estado, nome2.estado);
    printf("Codigo da carta: %s x %s\n", nome1.carta.codCarta, nome2.carta.codCarta);
    printf("Nome da cidade: %s x %s\n", nome1.carta.nomeCidade, nome2.carta.nomeCidade);

    printf("Populacao: %lu x %lu\n", nome1.carta.populacao, nome2.carta.populacao);
    atributo = compararAtributos((float)nome1.carta.populacao, (float)nome2.carta.populacao, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    printf("Area: %.2f x %.2f\n", nome1.carta.area, nome2.carta.area);
    atributo = compararAtributos(nome1.carta.area, nome2.carta.area, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);


    printf("Pib: %.2f x %.2f\n", nome1.carta.pib, nome2.carta.pib);
    atributo = compararAtributos(nome1.carta.pib, nome2.carta.pib, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    printf("Pontos Turisticos: %d x %d\n", nome1.carta.pontosTuristicos, nome2.carta.pontosTuristicos);
    atributo = compararAtributos((float)nome1.carta.pontosTuristicos, (float)nome2.carta.pontosTuristicos, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    printf("Densidade Populacional: %.2f x %.2f\n", nome1.carta.densidadePopulacional, nome2.carta.densidadePopulacional);
    atributo = compararAtributosInvertido(nome1.carta.densidadePopulacional, nome2.carta.densidadePopulacional, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    printf("Pib per capita: %.2f x %.2f\n", nome1.carta.pibPerCapita, nome2.carta.pibPerCapita);
    atributo = compararAtributos(nome1.carta.pibPerCapita, nome2.carta.pibPerCapita, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    printf("Super Poder: %.2f x %.2f\n", nome1.carta.superPoder, nome2.carta.superPoder);
    atributo = compararAtributos(nome1.carta.superPoder, nome2.carta.superPoder, &pontosCarta1, &pontosCarta2);
    atributoVencedor(nome1, nome2, atributo);

    //Exibe o numero de pontos de cada carta
    printf("Pontos: %d x %d\n", pontosCarta1, pontosCarta2);

    //Exibe a carta vencedora
    if(pontosCarta1 > pontosCarta2){
        printf("A carta %s ganhou!!!", nome1.estado);
        return 0;
    }else if(pontosCarta2 > pontosCarta1){
        printf("A carta %s ganhou!!!", nome2.estado);
        return 1;
    }else{
        printf("As cartas empataram");
        return 2;
        }
}

int main(){
    struct nome_carta nome1, nome2;
    printf("-------Jogo Super Trunfo!!!!!-------\n");

    printf("\n-Cadastrando a os dados da primeira carta-\n");
    cadastraCarta(&nome1);

    printf("\n ---Exibindo dados da carta 1---\n");
    exibirDados(nome1);

    printf("\n-Cadastrando a os dados da segunda carta-\n");
    cadastraCarta(&nome2);

    printf("\n ---Exibindo dados da carta 2---\n");
    exibirDados(nome2);

    printf("\n---Comparando cartas---\n");

    compararCartas(nome1, nome2);
    
}