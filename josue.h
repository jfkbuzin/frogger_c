//Josué Filipe Keglevich de Buzin
#include "conio2.h"
#include <stdio.h>
#define MAX3 51
#define MIN3 0
#define CIMA 72
#define BAIXO 80
#define ESQ 77
#define DIR 75

/*
Descrição das Funçoes:

menuf : cria a agua no jogo
carro : cria os carros no jogo
troncos : cria os troncos no jogo
tartaruga1 : cria as tartarugas no jogo, modificando seu desenho conforme estiverem submergindo
men e mex : quando o objeto chegar à beira da tela, ele reaparece do outro lado
menu : mostra o menu e espera o usuario digitar uma letra no teclado
reinicio : retorna o jogo à posição inicial após a morte ou quando o usuario passar de fase
morte : morte do jogador e game over se as vidas chegarem a zero

*/

typedef struct
{ //transformar os objetos em estruturas
    char objeto;	//S T R C
    int	tamanho; //
    int	espacamento;
    float velocidade;
    int	linha_inicial;
    int	coluna_inicial;

} TIPO_FASE;

void menuf(char vet[12][60])
{
    int lin = 0;

    while(lin<12)
    {
        textcolor(BLUE);
        cputsxy(0,1+lin, vet[lin]);
        lin++;
    }
}

void carro(char c1[2][8], TIPO_FASE s)
{

    int lin;
    int col;

    for(lin=0;lin<2;lin++)
    {
        for(col=0;col<8;col++)
        {
            textcolor(RED);
            gotoxy(s.coluna_inicial+col,s.linha_inicial+lin);
            cprintf("%c", c1[lin][col]);
        }
        cprintf("\n");
    }
}

void troncos(TIPO_FASE s, int *N1)
{
    int lin, col;

    for(lin=0;lin<2;lin++)
        {
            for(col=0;col<*N1;col++)
            {
                textcolor(BROWN);
                gotoxy(s.coluna_inicial+col,s.linha_inicial+lin);
                cprintf("%c", '#');
            }
            cprintf("\n");
        }
}


void tartaruga1(char tartaruga[2][4], char tartaruga_s[2][4], int *x, int *y, int *z)
{
    int lin, col;

    switch(*z)
        {
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 :
            case 6 :
            case 7 :
            case 8 :
            case 9 :
            case 10 :for(lin=0;lin<2;lin++)
                    {
                        for(col=0;col<4;col++)
                        {
                            textcolor(BLUE);
                            gotoxy(*x+col,*y+lin);
                            cprintf("~");
                        }
                    cprintf("\n");
                    }
            break;
            case 11 :
            case 12 :
            case 13 :
            case 14 :
            case 15 :
            case 16 :
            case 17 :
            case 18 :
            case 19 :
            case 20 :for(lin=0;lin<2;lin++)
                    {
                        for(col=0;col<4;col++)
                        {
                            textcolor(GREEN);
                            gotoxy(*x+col,*y+lin);
                            cprintf("%c", tartaruga_s[lin][col]);
                        }
                    cprintf("\n");
                    }
            break;
            case 21 :
            case 22 :
            case 23 :
            case 24 :
            case 25 :
            case 26 :
            case 27 :
            case 28 :
            case 29 :
            case 30 :for(lin=0;lin<2;lin++)
                    {
                        for(col=0;col<4;col++)
                        {
                            textcolor(GREEN);
                            gotoxy(*x+col,*y+lin);
                            cprintf("%c", tartaruga[lin][col]);
                        }
                    cprintf("\n");
                    }
            break;
            case 31 :
            case 32 :
            case 33 :
            case 34 :
            case 35 :
            case 36 :
            case 37 :
            case 38 :
            case 39 :
            case 40 :for(lin=0;lin<2;lin++)
                    {
                        for(col=0;col<4;col++)
                        {
                            textcolor(GREEN);
                            gotoxy(*x+col,*y+lin);
                            cprintf("%c", tartaruga_s[lin][col]);
                        }
                    cprintf("\n");
                    }
            break;
        }
}

void men(int *x)
{
    if (*x == MIN3)
        *x = MAX3;
}

void mex(int *x)
{
    if (*x == MAX3)
        *x = MIN3;
}

int menu(char *c)
{

    int lin, col;

    textcolor(GREEN);
    cprintf(" _______  _______  _______  _______  _______  _______  _______ \n");
	cprintf("(  _____)(  ____ )(  ___  )(  _____)(  _____)(  _____)(  ____ )\n");
	cprintf("( (      ( (    ))( (   ) )( (      ( (      ( (      ( (    ))\n");
	cprintf("( (__    ( (____))( (   ) )( (      ( (      ( (__    ( (____))\n");
	cprintf("(  __)   (  _  __)( (   ) )( (  ___ ( (  ___ (  __)   (  _  __)\n");
	cprintf("( (      ( ( ( )  ( (   ) )( ( (_  )( ( (_  )( (      ( ( ( )  \n");
	cprintf("( )      ( ) ( )  ( (___) )( (___) )( (___) )( (_____ ( ) ( )  \n");
	cprintf("(_)      (_) (__) (_______)(_______)(_______)(_______)(_) (__) \n");

    cprintf("\n");


    cprintf("\n\n\n\n");

    cprintf("\t \t \tNOVO JOGO(digite j)");

    cprintf("\n\n");

    cprintf("\t \t \tCONTINUAR(digite c)");

    cprintf("\n\n");

    cprintf("\t \t \tSAIR(digite q)");

    cprintf("\n\n");

    *c=getch();

    return *c;
}

void reinicio(TIPO_FASE *se, TIPO_FASE *ce1, TIPO_FASE *ce2, TIPO_FASE *ce3, TIPO_FASE *ce4,
            TIPO_FASE *ce5,TIPO_FASE *re1,TIPO_FASE *re2,TIPO_FASE *re3,TIPO_FASE *re4,TIPO_FASE *re5,
            TIPO_FASE *re6,TIPO_FASE *re7,TIPO_FASE *re8,TIPO_FASE *re9,TIPO_FASE *re10,
            TIPO_FASE *re11,TIPO_FASE *re12,TIPO_FASE *te1,TIPO_FASE *te2,TIPO_FASE *te3,
            TIPO_FASE *te4,TIPO_FASE *te5,TIPO_FASE *te6, int *p, int *var)
            {
                *p = 50;
                ce1->coluna_inicial = 51, ce1->linha_inicial = 15;//coordenadas inicias dos 5 carros no jogo
                ce2->coluna_inicial = 0, ce2->linha_inicial = 17;
                ce3->coluna_inicial = 51, ce3->linha_inicial = 19;
                ce4->coluna_inicial = 0, ce4->linha_inicial = 21;
                ce5->coluna_inicial = 51, ce5->linha_inicial = 23;
                re1->coluna_inicial = 3, re2->coluna_inicial = 7, re3->coluna_inicial = 11, re1->linha_inicial = 4, *var = 0;//coordenadas inicias das 12 tartarugas no jogo
                re4->coluna_inicial = 51, re5->coluna_inicial = 47, re6->coluna_inicial = 43, re4->linha_inicial = 8;
                re7->linha_inicial = 12;
                re7->coluna_inicial = 30, re8->coluna_inicial = 34, re9->coluna_inicial = 38;
                re10->coluna_inicial = 21, re11->coluna_inicial = 17, re12->coluna_inicial = 13;
                te1->coluna_inicial = 0,  te1->linha_inicial = 6;// coordenadas iniciais dos 6 troncos no jogo
                te2->coluna_inicial = 18,  te3->linha_inicial = 10;
                te3->coluna_inicial = 50;
                te4->coluna_inicial = 32;
                te5->coluna_inicial = 38;
                te6->coluna_inicial = 16;

                se->coluna_inicial = 29, se->linha_inicial = 25;
            }

void morte(TIPO_FASE se, int *vidas, int pontos_total, char *ini)
{
    textcolor(GREEN);
    gotoxy(se.coluna_inicial,se.linha_inicial); //morte do sapo
    cprintf("%s", "-/");
    gotoxy(se.coluna_inicial,se.linha_inicial+1);
    cprintf("%s", "/-");
    system("pause");


    *vidas -= 1;

    if(*vidas == 0)
    {
        system("cls"); //limpa a tela
        gotoxy(25,12);
        printf("GAME OVER");

        gotoxy(25,14);
        printf("PONTOS TOTAIS : %d", pontos_total);
        *ini = getch();
        system("exit");
    }
}
