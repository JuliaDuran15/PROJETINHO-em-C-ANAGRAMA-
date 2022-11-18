#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

/// Julia Duran, RA: 22009210
/// Luigi Bertoli, RA: 22000113
/// Thayn� Aquino, RA: 22002057
void ganha(){
            printf("\n\n\t   PARABENS, VOCE ACERTOU TODAS AS PALAVRAS\n");
            printf("\t\t          ___________      \n");
            printf("\t\t         '._==_==_=_.'     \n");
            printf("\t\t         .-\\:      /-.    \n");
            printf("\t\t        | (|:.     |) |    \n");
            printf("\t\t         '-|:.     |-'     \n");
            printf("\t\t           \\::.    /      \n");
            printf("\t\t            '::. .'        \n");
            printf("\t\t              ) (          \n");
            printf("\t\t            _.' '._        \n");
            printf("\t\t           '-------'       \n\n");
        }

void perde(){

            printf("\n\n    INFELIZMENTE VOCE PASSOU DO LIMITE DE ERROS, VOCE PERDEU\n");
            printf("\t\t       _______________         \n");
            printf("\t\t      /               \\       \n");
            printf("\t\t     /                 \\      \n");
            printf("\t\t   //                   \\/\\  \n");
            printf("\t\t   \\|   XXXX     XXXX   | /   \n");
            printf("\t\t    |   XXXX     XXXX   |/     \n");
            printf("\t\t    |   XXX       XXX   |      \n");
            printf("\t\t    |                   |      \n");
            printf("\t\t    \\__      XXX      __/     \n");
            printf("\t\t      |\\     XXX     /|       \n");
            printf("\t\t      | |           | |        \n");
            printf("\t\t      | I I I I I I I |        \n");
            printf("\t\t      |  I I I I I I  |        \n");
            printf("\t\t      \\_             _/       \n");
            printf("\t\t        \\_         _/         \n");
            printf("\t\t          \\_______/           \n\n");
}
void entrada()
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>> BEM VINDO JOGADOR<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf(">>>>>>>> FICAMOS MUIO FELIZES QUE ESCOLHERAM JOGAR NOSSO JOGO <<<<<\n");
}
void imprima_ma(int f, char banco[][17]){
                for(int j=0;j<f;j++){
            if(j%5==0)printf("\n\t\t");
            strupr(banco[j]);
            printf("%s ", banco[j]);
}
}

char* getstr()
{
    int i =0;
    char *S;
    S = NULL;
    fflush(stdin);
    do
    {
        S=(char*)realloc(S,(i+1)*sizeof(char));
        if(S == NULL)
        {
            printf("ERRO DE ALOCACAO");
            exit(1);
        }
        scanf("%c", &S[i]);
    }
    while(S[i++]!='\n');
    S[--i]='\0';
    return S;
}

void interface(int a, int e, int ta, int te, char vetAcert[][17])
{
    printf("\n=====================================================================================\n\t\t\t\tANAGRAMA\n");
    printf("=====================================================================================");
    printf("\n\t REGRAS: \n \t\t1-> Forme palavras com as letras contidas no quadro para pontuar.");
    printf("\n\t\t2-> Eh preciso acertar %d palavras para GANHAR.\n\t\t3-> Em %d tentativas erradas o jogo termina. ",ta, te);
    printf("\n=====================================================================================\n\t\t\t  QUADRO    DE    LETRAS\n");
    printf("\n\t\t\t       P N I O B G\n\t\t\t       E C Z R T I\n\t\t\t       S T A O M L\n\t\t\t       D F D A H U\n\t\t\t       V A E I Q C\n");
    printf("\n\t\t>>> ACERTOS: (%d de %d) \t>>> ERROS: (%d de %d)", a,ta,e,te);

    if(a!=0)
    {
        printf("\n\tVoce acertou as palavras:");
               imprima_ma(a,vetAcert);
}

    printf("\n\nPara encerrar - digite PARAR");
}

int validacao1(char *str)
{
    int S=0;
    for(int i=0; i<strlen(str); i++)
    {
        if(isalpha(str[i]))
            S++;
    }
	if(S==strlen(str)) return 1;
    return 0;
}

int validacao2 (char *str, char BancoDePalavras[][17], char BancoDeAcertos[][17], int a)
{
    int f=2;
    if(stricmp(str,"PARAR")==0) return 3;

    for(int i=0; i<30; i++)
    {
        if(stricmp(BancoDePalavras[i], str) == 0){
            f=0; break;
        }}

        if(f==0){
        for(int j=0; j<a; j++){

            if(stricmp(BancoDeAcertos[j], str) == 0 ){
            f=1; break;

            }}}

            return f;

}


int main()
{
    int fase, a=0, e=0, ta=30, te, flag, ver;
    char BancoDePalavras[30][17] = {"Perigo", "Bronze", "Cientista", "Ronco", "Motorista", "Tela", "Mar", "Soldado", "Faringe", "Data", "Trincheira", "Original", "Futebol", "Diretor", "Brinde", "Caravelas", "Espectro", "Submarino", "Onda", "Presa", "Entrada", "Fugir", "Ovo", "Marcador", "Significado", "Nervo", "Esquilo", "Capacete", "Pare", "Defesa"};
    char *palavra, vetAcertos[30][17];

    system("color 5F");

    entrada();

    do
    {
        printf("\nFACIL(1) MEDIO(2) DIFICIL(3) IMPOSSIVEL(4)\nEscolha a fase: ");
        scanf("%d", &fase);
    }
    while(fase < 1 || fase > 4);

    switch(fase)
    {
    case 1:
        te = 7;
        do
        {interface( a, e, ta, te, vetAcertos);
            do
            {

                printf("ro\nDigite a palavra que achou: ");
                palavra = getstr();

            }
            while(validacao1(palavra)==0);

            flag = validacao2(palavra, BancoDePalavras, vetAcertos, a);

            if(flag==0){

            strcpy(vetAcertos[a], palavra);
            a++;
            }
            if(flag==2)e++;
        }
        while(a<30 && e<7 && flag!=3);
        if(a==30)
        {
		ganha();
        }
        if(e==7)
        {
		perde();
        }
        do{
        printf("\nDeseja ver o banco de palavras? SIM(1) NAO(2): ");
        scanf("%d", &ver);
        if(ver==1){printf("\n");
                imprima_ma(TAM,BancoDePalavras);
                printf("\n");
}
        }while(ver !=1 && ver !=2);

        break;
    case 2:
        te = 5;
        do
        {
            interface(a, e, ta, te, vetAcertos);
            do
            {
                printf("\nDigite a palavra que achou: ");
                palavra = getstr();
            }
            while(validacao1(palavra)==0);


            flag = validacao2(palavra, BancoDePalavras, vetAcertos, a);

            if(flag==0){

            strcpy(vetAcertos[a], palavra);
            a++;
            }
            if(flag==2)e++;
        }
        while(a<30 && e<5 && flag!=3);
        if(a==30)
        {
            ganha();
        }
        if(e==5)
        {
            perde();
        }
        do{
        printf("\nDeseja ver o banco de palavras? SIM(1) NAO(2): ");
        scanf("%d", &ver);
        if(ver==1){
                printf("\n");
        imprima_ma(TAM,BancoDePalavras);
        printf("\n");
        }
        }while(ver !=1 && ver !=2);

        break;
    case 3:
        te = 3;
                do{
            interface(a, e, ta, te, vetAcertos);
            do
            {
                printf("\nDigite a palavra que achou: ");
                palavra = getstr();
            }
            while(validacao1(palavra)==0);


            flag = validacao2(palavra, BancoDePalavras, vetAcertos, a);

            if(flag==0){

            strcpy(vetAcertos[a], palavra);
            a++;
            }
            if(flag==2)e++;
        }
        while(a<30 && e<7 && flag!=3);
        if(a==30)
        {
		ganha();
        }
        if(e==3)
        {
		perde();
        }
        do{
        printf("\nDeseja ver o banco de palavras? SIM(1) NAO(2): ");
        scanf("%d", &ver);
        if(ver==1){printf("\n");
    imprima_ma(TAM,BancoDePalavras);
    printf("\n");
}
        }while(ver !=1 && ver !=2);

        break;
    case 4:
        te = 1;
        do
        {
            interface(a, e, ta, te, vetAcertos);
            do
            {
                printf("\nDigite a palavra que achou: ");
                palavra = getstr();
            }
            while(validacao1(palavra)==0);

            flag = validacao2(palavra, BancoDePalavras, vetAcertos, a);

            if(flag==0){

            strcpy(vetAcertos[a], palavra);
            a++;
            }
            if(flag==2)e++;
        }
        while(a<30 && e<1 && flag!=3);
        if(a==30)
        {
		ganha();
        }

        if(e==1)
        {
		perde();
        }
        do{
        printf("\nDeseja ver o banco de palavras? SIM(1) NAO(2): ");
        scanf("%d", &ver);
        if(ver==1){
                printf("\n");
        imprima_ma(TAM,BancoDePalavras);
        printf("\n");
        }
        }while(ver !=1 && ver !=2);

        break;
    default:
        break;
    }

    return 0;
}
