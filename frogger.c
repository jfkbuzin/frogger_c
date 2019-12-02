//Josué Filipe Keglevich de Buzin
#include <conio2.h>
#include <stdio.h>
#include "josue.h"
#define MAX3 51
#define MIN3 0
#define CIMA 72
#define BAIXO 80
#define ESQ 77
#define DIR 75
#define QUIT 113

int main( void )
{
    TIPO_FASE se = {'s', 1, 0, 0, 25, 29}; // 1 unidade = matriz 2x2

    TIPO_FASE re1 = {'r', 1, 0, 0.1 , 4, 3};
    TIPO_FASE re2 = {'r', 2, 0, 0.1 , 4, 7};
    TIPO_FASE re3 = {'r', 1, 0, 0.1 , 4, 11};
    TIPO_FASE re4 = {'r', 1, 0, 0.1 , 8, 51};
    TIPO_FASE re5 = {'r', 2, 0, 0.1 , 8, 47};
    TIPO_FASE re6 = {'r', 1, 0, 0.1 , 8, 43};
    TIPO_FASE re7 = {'r', 1, 0, 0.1 , 12, 30};
    TIPO_FASE re8 = {'r', 2, 0, 0.1 , 12, 34};
    TIPO_FASE re9 = {'r', 1, 0, 0.1 , 12, 38};
    TIPO_FASE re10 = {'r', 1, 0, 0.1 , 8, 21};
    TIPO_FASE re11 = {'r', 2, 0, 0.1 , 8, 17};
    TIPO_FASE re12 = {'r', 1, 0, 0.1 , 8, 13};

    TIPO_FASE te1 = {'t', 4, 0, 0.1, 6, 0};
    TIPO_FASE te2 = {'t', 2, 0, 0.1, 6, 18};
    TIPO_FASE te3 = {'t', 2, 0, 0.1, 10, 50};
    TIPO_FASE te4 = {'t', 4, 0, 0.1, 10, 32};
    TIPO_FASE te5 = {'t', 4, 0, 0.1, 6, 38};
    TIPO_FASE te6 = {'t', 4, 0, 0.1, 10, 16};

    TIPO_FASE ce1 = {'c', 4, 0, 0.1, 15, 51};
    TIPO_FASE ce2 = {'c', 4, 0, 0.1, 17, 0};
    TIPO_FASE ce3 = {'c', 4, 0, 0.1, 19, 51};
    TIPO_FASE ce4 = {'c', 4, 0, 0.1, 21, 0};
    TIPO_FASE ce5 = {'c', 4, 0, 0.1, 23, 51};

    int lin, col;//indices que serão usados na função principal
    char ini = 'a'; //para funcionamento do menu
    int vidas;//contador de vidas
    int pontos = 50; //contador de pontos durante uma partida do jogo
    int pontos_total = 00; //contador de pontos totais do jogo

    char um[3] = "@@";//corpo do sapo
    char dois[3] = "OO";
    char c;//para o input no teclado

    char c1[2][8] = {' ', '_', '_', '/', '=', '|', '_', ' ' , '/', '_', 'o', '_', '_', '_', 'o', '\\'};//carro que se movimenta para esquerda
    char c2[2][8] = {' ', '_', '|', '=', '\\', '_', '_', ' ' , '/', 'o', '_', '_', '_', 'o', '_', '\\'};//carro que se movimenta para direita

    char tartaruga[2][4] = {'/', '\\','/', '\\', '\\', '/', '\\', '/'};//tartaruga
    char tartaruga_s[2][4] = {'\\','/','\\','/','/', '\\','/', '\\'};//tartaruga submergindo
    int var = 0; //contador para controlar o momento em que a tartaruga submerge

    char agua[12][60] = {//a agua no jogo
    "  |~~~~|      |~~~~|      |~~~~|      |~~~~|      |~~~~|  ",
    "__|~~~~|______|~~~~|______|~~~~|______|~~~~|______|~~~~|__",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    };

    int N1 = 4; //quantidade de colunas dos troncos
    int N2 = 8;


    while(ini != 'j')
    {
        menu(&ini); //função que mostra o menu inicial do jogo

        if(ini == 'q')
        {
            vidas = 0;//termina o jogo se digitada a tecla q
            break;
        }

        if(ini == 'c')//carrega um jogo salvo se foi digitada a tecla c, ocorre erro se não for salvo um arquivo antes
        {
            char buf[100];

            FILE *salva;

            salva = fopen("salva.txt", "r");

            if (salva != NULL)
            {
                while(!feof(salva))
                {
                    if(fgets(buf,100,salva) != NULL)
                    {
                        se.coluna_inicial = atoi(strtok(buf,"#"));
                        se.linha_inicial = atoi(strtok(NULL,"#"));
                        ce1.coluna_inicial = atoi(strtok(NULL,"#"));
                        ce2.coluna_inicial = atoi(strtok(NULL,"#"));
                        ce3.coluna_inicial = atoi(strtok(NULL,"#"));
                        ce4.coluna_inicial = atoi(strtok(NULL,"#"));
                        ce5.coluna_inicial = atoi(strtok(NULL,"#"));

                        re1.coluna_inicial = atoi(strtok(NULL,"#"));
                        re2.coluna_inicial = atoi(strtok(NULL,"#"));
                        re3.coluna_inicial = atoi(strtok(NULL,"#"));
                        re4.coluna_inicial = atoi(strtok(NULL,"#"));
                        re5.coluna_inicial = atoi(strtok(NULL,"#"));
                        re6.coluna_inicial = atoi(strtok(NULL,"#"));
                        re7.coluna_inicial = atoi(strtok(NULL,"#"));
                        re8.coluna_inicial = atoi(strtok(NULL,"#"));
                        re9.coluna_inicial = atoi(strtok(NULL,"#"));
                        re10.coluna_inicial = atoi(strtok(NULL,"#"));
                        re11.coluna_inicial = atoi(strtok(NULL,"#"));
                        re12.coluna_inicial = atoi(strtok(NULL,"#"));

                        te1.coluna_inicial = atoi(strtok(NULL,"#"));
                        te2.coluna_inicial = atoi(strtok(NULL,"#"));
                        te3.coluna_inicial = atoi(strtok(NULL,"#"));
                        te4.coluna_inicial = atoi(strtok(NULL,"#"));
                        te5.coluna_inicial = atoi(strtok(NULL,"#"));
                        te6.coluna_inicial = atoi(strtok(NULL,"#"));

                        vidas = atoi(strtok(NULL,"#"));
                        pontos = atoi(strtok(NULL,"#"));
                        pontos_total = atoi(strtok(NULL,"#"));
                        var = atoi(strtok(NULL,"#"));
                    }
                }

            fclose(salva);
            }
            else
            {
                printf("Erro ao abrir o Arquivo");
                return 0;
            }




            system("mode con:cols=58 lines=28");//limita o tamanho da tela

            textcolor(GREEN);
            gotoxy(se.coluna_inicial,se.linha_inicial); //ponto de partida do sapo
            cprintf("%s", um);
            gotoxy(se.coluna_inicial,se.linha_inicial+1);
            cprintf("%s", dois);
            break;
        }

        if(ini == 'j')//começa o jogo se digitada a tecla j
        {
            vidas = 3;

            system("mode con:cols=58 lines=28");//limita o tamanho da tela

            textcolor(GREEN);
            gotoxy(se.coluna_inicial,se.linha_inicial); //ponto de partida do sapo
            cprintf("%s", um);
            gotoxy(se.coluna_inicial,se.linha_inicial+1);
            cprintf("%s", dois);
        }
        system("cls");//limpa a tela
    }


    while (vidas>0)
    {

        if(kbhit())//coordenadas para o movimento do sapo com o teclado
		{

            getch();

            c=getch();

            int tecla = (int)c;

            system("cls");//limpa a tela

            if(tecla == QUIT)//termina o jogo se digitada a tecla q
            {
                return 0;
            }
            else
                if(tecla == 's')//Salva o jogo se digitada a tecla s, dopois de salvo, o jogo termina
                {
                    FILE *salva;

                    salva = fopen("salva.txt", "w");

                    if (salva != NULL)
                    {

                        fprintf(salva, "%d#", se.coluna_inicial);
                        fprintf(salva, "%d#", se.linha_inicial);

                        fprintf(salva, "%d#", ce1.coluna_inicial);
                        fprintf(salva, "%d#", ce2.coluna_inicial);
                        fprintf(salva, "%d#", ce3.coluna_inicial);
                        fprintf(salva, "%d#", ce4.coluna_inicial);
                        fprintf(salva, "%d#", ce5.coluna_inicial);

                        fprintf(salva, "%d#", re1.coluna_inicial);
                        fprintf(salva, "%d#", re2.coluna_inicial);
                        fprintf(salva, "%d#", re3.coluna_inicial);
                        fprintf(salva, "%d#", re4.coluna_inicial);
                        fprintf(salva, "%d#", re5.coluna_inicial);
                        fprintf(salva, "%d#", re6.coluna_inicial);
                        fprintf(salva, "%d#", re7.coluna_inicial);
                        fprintf(salva, "%d#", re8.coluna_inicial);
                        fprintf(salva, "%d#", re9.coluna_inicial);
                        fprintf(salva, "%d#", re10.coluna_inicial);
                        fprintf(salva, "%d#", re11.coluna_inicial);
                        fprintf(salva, "%d#", re12.coluna_inicial);

                        fprintf(salva, "%d#", te1.coluna_inicial);
                        fprintf(salva, "%d#", te2.coluna_inicial);
                        fprintf(salva, "%d#", te3.coluna_inicial);
                        fprintf(salva, "%d#", te4.coluna_inicial);
                        fprintf(salva, "%d#", te5.coluna_inicial);
                        fprintf(salva, "%d#", te6.coluna_inicial);

                        fprintf(salva, "%d#", vidas);
                        fprintf(salva, "%d#", pontos);
                        fprintf(salva, "%d#", pontos_total);
                        fprintf(salva, "%d", var);

                        fclose(salva);
                        system("cls");
                        gotoxy(25,12);
                        printf("Jogo Salvo");
                        return 0;

                    }
                    else
                    {
                        system("cls");
                        printf("Erro ao abrir o Arquivo");
                    }

                }
            else
            {
                textcolor(GREEN);
                switch (tecla)
                {
                    case CIMA:
                        pontos--;
                        if(se.linha_inicial != 2) se.linha_inicial--; //limita o movimento do sapo até os extremos da tela
                        gotoxy(se.coluna_inicial,se.linha_inicial);
                        cprintf("%s", um);
                        gotoxy(se.coluna_inicial,se.linha_inicial+1);
                        cprintf("%s", dois);
                    break;

                    case BAIXO:
                        pontos--;
                        if (se.linha_inicial != 26) se.linha_inicial++;//limita o movimento do sapo até os extremos da tela
                        gotoxy(se.coluna_inicial,se.linha_inicial);
                        cprintf("%s", um);
                        gotoxy(se.coluna_inicial,se.linha_inicial+1);
                        cprintf("%s", dois);
                    break;

                    case ESQ:
                        pontos--;
                        if (se.coluna_inicial != 57) se.coluna_inicial++;//limita o movimento do sapo até os extremos da tela
                        gotoxy(se.coluna_inicial,se.linha_inicial);
                        cprintf("%s", um);
                        gotoxy(se.coluna_inicial,se.linha_inicial+1);
                        cprintf("%s", dois);
                    break;

                    case DIR:
                        pontos--;
                        if (se.coluna_inicial != 1) se.coluna_inicial--;//limita o movimento do sapo até os extremos da tela
                        gotoxy(se.coluna_inicial,se.linha_inicial);
                        cprintf("%s", um);
                        gotoxy(se.coluna_inicial,se.linha_inicial+1);
                        cprintf("%s", dois);
                    break;
                }

            }

		}


        system("cls");//limpa a tela

        textcolor(GREEN);

        cputsxy(0,0,"VIDAS: ");
        gotoxy(8,0);
        cprintf("%d", vidas);

        cputsxy(12,0,"  PONTOS: ");
        gotoxy(22,0);
        cprintf("%d", pontos);

        cputsxy(25,0,"                    PONTOS TOTAIS: ");
        gotoxy(50,0);
        cprintf("%03d", pontos_total);

        menuf(agua);//função que cria a agua toda vez que o laço reinicia

        ce2.coluna_inicial++, ce4.coluna_inicial++;//contadores para as coordenadas das colunas onde estão os carros
        ce1.coluna_inicial--, ce3.coluna_inicial--, ce5.coluna_inicial--;

        carro(c1, ce1);//função que cria um carro toda vez que o laço reinicia
        carro(c2, ce2);
        carro(c1, ce3);
        carro(c2, ce4);
        carro(c1, ce5);

        te1.coluna_inicial++, te2.coluna_inicial++, te5.coluna_inicial++;//contadores para as coordenadas das colunas onde estão os troncos
        te3.coluna_inicial--, te4.coluna_inicial--, te6.coluna_inicial--;

        troncos(te1, &N2);//função que cria um tronco toda vez que o laço reinicia
        troncos(te2, &N1);
        troncos(te3, &N1);
        troncos(te4, &N2);
        troncos(te5, &N2);
        troncos(te6, &N2);

        re1.coluna_inicial++, re2.coluna_inicial++, re3.coluna_inicial++;//contadores para as coordenadas das colunas onde estão as tartarugas
        re4.coluna_inicial--, re5.coluna_inicial--, re6.coluna_inicial--;
        re7.coluna_inicial++, re8.coluna_inicial++, re9.coluna_inicial++;
        re10.coluna_inicial--; re11.coluna_inicial--; re12.coluna_inicial--;
        tartaruga1(tartaruga, tartaruga_s, &re1.coluna_inicial, &re1.linha_inicial, &var);//função que cria uma tartaruga toda vez que o laço reinicia
        tartaruga1(tartaruga, tartaruga_s, &re2.coluna_inicial, &re1.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re3.coluna_inicial, &re1.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re4.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re5.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re6.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re1.coluna_inicial, &re7.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re2.coluna_inicial, &re7.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re3.coluna_inicial, &re7.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re7.coluna_inicial, &re1.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re8.coluna_inicial, &re1.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re9.coluna_inicial, &re1.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re10.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re11.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re12.coluna_inicial, &re4.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re7.coluna_inicial, &re7.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re8.coluna_inicial, &re7.linha_inicial, &var);
        tartaruga1(tartaruga, tartaruga_s, &re9.coluna_inicial, &re7.linha_inicial, &var);

        if(!kbhit())
        {
            if((se.linha_inicial == re1.linha_inicial)||(se.linha_inicial == re7.linha_inicial)) //para o sapo se mover junto com as tartarugas e morrer se elas submergirem
            {
                if((se.coluna_inicial == re1.coluna_inicial)||(se.coluna_inicial == re7.coluna_inicial)) se.coluna_inicial++;
                else
                    if((se.coluna_inicial == re1.coluna_inicial+1)||(se.coluna_inicial == re7.coluna_inicial+1)) se.coluna_inicial++;
                    else
                        if((se.coluna_inicial == re1.coluna_inicial+2)||(se.coluna_inicial == re7.coluna_inicial+2)) se.coluna_inicial++;
                        else
                            if((se.coluna_inicial == re1.coluna_inicial+3)||(se.coluna_inicial == re7.coluna_inicial+3)) se.coluna_inicial++;
                            else
                if((se.coluna_inicial == re2.coluna_inicial)||(se.coluna_inicial == re8.coluna_inicial)) se.coluna_inicial++;
                else
                    if((se.coluna_inicial == re2.coluna_inicial+1)||(se.coluna_inicial == re8.coluna_inicial+1)) se.coluna_inicial++;
                    else
                        if((se.coluna_inicial == re2.coluna_inicial+2)||(se.coluna_inicial == re8.coluna_inicial+2)) se.coluna_inicial++;
                        else
                            if((se.coluna_inicial == re2.coluna_inicial+3)||(se.coluna_inicial == re8.coluna_inicial+3)) se.coluna_inicial++;
                            else
                if((se.coluna_inicial == re3.coluna_inicial)||(se.coluna_inicial == re9.coluna_inicial)) se.coluna_inicial++;
                else
                    if((se.coluna_inicial == re3.coluna_inicial+1)||(se.coluna_inicial == re9.coluna_inicial+1)) se.coluna_inicial++;
                    else
                        if((se.coluna_inicial == re3.coluna_inicial+2)||(se.coluna_inicial == re9.coluna_inicial+2)) se.coluna_inicial++;
                        else
                            if((se.coluna_inicial == re3.coluna_inicial+3)||(se.coluna_inicial == re9.coluna_inicial+3)) se.coluna_inicial++;
                if((var>0)&&(var<11))
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
            }

            if(se.linha_inicial == re4.linha_inicial) //para o sapo se mover junto com as tartarugas e morrer se elas submergirem
            {
                if((se.coluna_inicial == re4.coluna_inicial)||(se.coluna_inicial == re10.coluna_inicial)) se.coluna_inicial--;
                else
                    if((se.coluna_inicial == re4.coluna_inicial+1)||(se.coluna_inicial == re10.coluna_inicial+1)) se.coluna_inicial--;
                    else
                        if((se.coluna_inicial == re4.coluna_inicial+2)||(se.coluna_inicial == re10.coluna_inicial+2)) se.coluna_inicial--;
                        else
                            if((se.coluna_inicial == re4.coluna_inicial+3)||(se.coluna_inicial == re10.coluna_inicial+3)) se.coluna_inicial--;
                            else
                if((se.coluna_inicial == re5.coluna_inicial)||(se.coluna_inicial == re11.coluna_inicial)) se.coluna_inicial--;
                else
                    if((se.coluna_inicial == re5.coluna_inicial+1)||(se.coluna_inicial == re11.coluna_inicial+1)) se.coluna_inicial--;
                    else
                        if((se.coluna_inicial == re5.coluna_inicial+2)||(se.coluna_inicial == re11.coluna_inicial+2)) se.coluna_inicial--;
                        else
                            if((se.coluna_inicial == re5.coluna_inicial+3)||(se.coluna_inicial == re11.coluna_inicial+3)) se.coluna_inicial--;
                            else
                if((se.coluna_inicial == re6.coluna_inicial)||(se.coluna_inicial == re12.coluna_inicial)) se.coluna_inicial--;
                else
                    if((se.coluna_inicial == re6.coluna_inicial+1)||(se.coluna_inicial == re12.coluna_inicial+1)) se.coluna_inicial--;
                    else
                        if((se.coluna_inicial == re6.coluna_inicial+2)||(se.coluna_inicial == re12.coluna_inicial+2)) se.coluna_inicial--;
                        else
                            if((se.coluna_inicial == re6.coluna_inicial+3)||(se.coluna_inicial == re12.coluna_inicial+3)) se.coluna_inicial--;

                if((var>0)&&(var<11))
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
            }

            if(se.linha_inicial == te1.linha_inicial) //para o sapo se mover junto com os troncos
            {
                for(col=N1;col>0;col--)
                {
                    if(se.coluna_inicial == te2.coluna_inicial+col) se.coluna_inicial++;
                }

                for(col=N2;col>0;col--)
                {
                    if(se.coluna_inicial == te1.coluna_inicial+col) se.coluna_inicial++;
                    if(se.coluna_inicial == te5.coluna_inicial+col) se.coluna_inicial++;
                }
            }

            if(se.linha_inicial == te3.linha_inicial) //para o sapo se mover junto com os troncos
            {
                for(col=0;col<N2;col++)
                {
                    if(se.coluna_inicial == te6.coluna_inicial+col) se.coluna_inicial--;
                    if(se.coluna_inicial == te4.coluna_inicial+col) se.coluna_inicial--;
                }

                for(col=0;col<N1;col++)
                {
                    if(se.coluna_inicial == te3.coluna_inicial+col) se.coluna_inicial--;
                }
            }

        }

        if(((se.linha_inicial == re1.linha_inicial)||(se.linha_inicial == re1.linha_inicial+1))||
           ((se.linha_inicial == re7.linha_inicial)||(se.linha_inicial == re7.linha_inicial+1)))//morte se o sapo cair na agua, na linha das tartarugas
        {
            if(se.coluna_inicial != re1.coluna_inicial)
                if(se.coluna_inicial != re1.coluna_inicial+1)
                    if(se.coluna_inicial != re1.coluna_inicial+2)
                        if(se.coluna_inicial != re1.coluna_inicial+3)
            if(se.coluna_inicial != re2.coluna_inicial)
                if(se.coluna_inicial != re2.coluna_inicial+1)
                    if(se.coluna_inicial != re2.coluna_inicial+2)
                        if(se.coluna_inicial != re2.coluna_inicial+3)
            if(se.coluna_inicial != re3.coluna_inicial)
                if(se.coluna_inicial != re3.coluna_inicial+1)
                    if(se.coluna_inicial != re3.coluna_inicial+2)
                        if(se.coluna_inicial != re3.coluna_inicial+3)
            if(se.coluna_inicial != re7.coluna_inicial)
                if(se.coluna_inicial != re7.coluna_inicial+1)
                    if(se.coluna_inicial != re7.coluna_inicial+2)
                        if(se.coluna_inicial != re7.coluna_inicial+3)
            if(se.coluna_inicial != re8.coluna_inicial)
                if(se.coluna_inicial != re8.coluna_inicial+1)
                    if(se.coluna_inicial != re8.coluna_inicial+2)
                        if(se.coluna_inicial != re8.coluna_inicial+3)
            if(se.coluna_inicial != re9.coluna_inicial)
                if(se.coluna_inicial != re9.coluna_inicial+1)
                    if(se.coluna_inicial != re9.coluna_inicial+2)
                        if(se.coluna_inicial != re9.coluna_inicial+3)
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
        }

        if((se.linha_inicial == re4.linha_inicial)||(se.linha_inicial == re4.linha_inicial+1)) //morte se o sapo cair na agua, na linha das tartarugas
        {
            if(se.coluna_inicial != re4.coluna_inicial)
                if(se.coluna_inicial != re4.coluna_inicial+1)
                    if(se.coluna_inicial != re4.coluna_inicial+2)
                        if(se.coluna_inicial != re4.coluna_inicial+3)
            if(se.coluna_inicial != re5.coluna_inicial)
                if(se.coluna_inicial != re5.coluna_inicial+1)
                    if(se.coluna_inicial != re5.coluna_inicial+2)
                        if(se.coluna_inicial != re5.coluna_inicial+3)
            if(se.coluna_inicial != re6.coluna_inicial)
                if(se.coluna_inicial != re6.coluna_inicial+1)
                    if(se.coluna_inicial != re6.coluna_inicial+2)
                        if(se.coluna_inicial != re6.coluna_inicial+3)
            if(se.coluna_inicial != re10.coluna_inicial)
                if(se.coluna_inicial != re10.coluna_inicial+1)
                    if(se.coluna_inicial != re10.coluna_inicial+2)
                        if(se.coluna_inicial != re10.coluna_inicial+3)
            if(se.coluna_inicial != re11.coluna_inicial)
                if(se.coluna_inicial != re11.coluna_inicial+1)
                    if(se.coluna_inicial != re11.coluna_inicial+2)
                        if(se.coluna_inicial != re11.coluna_inicial+3)
            if(se.coluna_inicial != re12.coluna_inicial)
                if(se.coluna_inicial != re12.coluna_inicial+1)
                    if(se.coluna_inicial != re12.coluna_inicial+2)
                        if(se.coluna_inicial != re12.coluna_inicial+3)
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
        }


        if((se.linha_inicial == te1.linha_inicial)||(se.linha_inicial == te1.linha_inicial+1)) //morte se o sapo cair na agua, na linha dos troncos
        {
            if(se.coluna_inicial != te1.coluna_inicial)
                if(se.coluna_inicial != te1.coluna_inicial+1)
                    if(se.coluna_inicial != te1.coluna_inicial+2)
                        if(se.coluna_inicial != te1.coluna_inicial+3)
            if(se.coluna_inicial != te1.coluna_inicial+4)
                if(se.coluna_inicial != te1.coluna_inicial+5)
                    if(se.coluna_inicial != te1.coluna_inicial+6)
                        if(se.coluna_inicial != te1.coluna_inicial+7)
            if(se.coluna_inicial != te2.coluna_inicial)
                if(se.coluna_inicial != te2.coluna_inicial+1)
                    if(se.coluna_inicial != te2.coluna_inicial+2)
                        if(se.coluna_inicial != te2.coluna_inicial+3)
            if(se.coluna_inicial != te5.coluna_inicial)
                if(se.coluna_inicial != te5.coluna_inicial+1)
                    if(se.coluna_inicial != te5.coluna_inicial+2)
                        if(se.coluna_inicial != te5.coluna_inicial+3)
            if(se.coluna_inicial != te5.coluna_inicial+4)
                if(se.coluna_inicial != te5.coluna_inicial+5)
                    if(se.coluna_inicial != te5.coluna_inicial+6)
                        if(se.coluna_inicial != te5.coluna_inicial+7)
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
        }

        if((se.linha_inicial == te3.linha_inicial)||(se.linha_inicial == te3.linha_inicial+1)) //morte se o sapo cair na agua, na linha dos troncos
        {
            if(se.coluna_inicial != te3.coluna_inicial)
                if(se.coluna_inicial != te3.coluna_inicial+1)
                    if(se.coluna_inicial != te3.coluna_inicial+2)
                        if(se.coluna_inicial != te3.coluna_inicial+3)
            if(se.coluna_inicial != te4.coluna_inicial)
                if(se.coluna_inicial != te4.coluna_inicial+1)
                    if(se.coluna_inicial != te4.coluna_inicial+2)
                        if(se.coluna_inicial != te4.coluna_inicial+3)
            if(se.coluna_inicial != te4.coluna_inicial+4)
                if(se.coluna_inicial != te4.coluna_inicial+5)
                    if(se.coluna_inicial != te4.coluna_inicial+6)
                        if(se.coluna_inicial != te4.coluna_inicial+7)
            if(se.coluna_inicial != te6.coluna_inicial)
                if(se.coluna_inicial != te6.coluna_inicial+1)
                    if(se.coluna_inicial != te6.coluna_inicial+2)
                        if(se.coluna_inicial != te6.coluna_inicial+3)
            if(se.coluna_inicial != te6.coluna_inicial+4)
                if(se.coluna_inicial != te6.coluna_inicial+5)
                    if(se.coluna_inicial != te6.coluna_inicial+6)
                        if(se.coluna_inicial != te6.coluna_inicial+7)
                        {
                            morte(se, &vidas, pontos_total, &ini);

                            reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                        }
        }

        mex(&re1.coluna_inicial);//função para trazer o objeto à coordenada incial após chegar ao extremo da tela do jogo
        mex(&re2.coluna_inicial);
        mex(&re3.coluna_inicial);
        men(&re4.coluna_inicial);
        men(&re5.coluna_inicial);
        men(&re6.coluna_inicial);
        mex(&re7.coluna_inicial);
        mex(&re8.coluna_inicial);
        mex(&re9.coluna_inicial);
        men(&re10.coluna_inicial);
        men(&re11.coluna_inicial);
        men(&re12.coluna_inicial);

        men(&ce1.coluna_inicial);
        mex(&ce2.coluna_inicial);
        men(&ce3.coluna_inicial);
        mex(&ce4.coluna_inicial);
        men(&ce5.coluna_inicial);

        mex(&te1.coluna_inicial);
        mex(&te2.coluna_inicial);
        mex(&te5.coluna_inicial);
        men(&te3.coluna_inicial);
        men(&te4.coluna_inicial);
        men(&te6.coluna_inicial);

        var++;//contador para deixar o submergir da tartaruga mais lento
        if (var == 41)
            var = 0;

        for(lin = 0; lin<2; lin++)//subtrair vidas se ocorrer choque com um carro
        {
            for(col = 0; col <8; col++)
            {
                if(((se.coluna_inicial == ce1.coluna_inicial+col)&&(se.linha_inicial == ce1.linha_inicial+lin))||
                    ((se.coluna_inicial == ce2.coluna_inicial+col)&&(se.linha_inicial == ce2.linha_inicial+lin))||
                    ((se.coluna_inicial == ce3.coluna_inicial+col)&&(se.linha_inicial == ce3.linha_inicial+lin))||
                    ((se.coluna_inicial == ce4.coluna_inicial+col)&&(se.linha_inicial == ce4.linha_inicial+lin))||
                    ((se.coluna_inicial == ce5.coluna_inicial+col)&&(se.linha_inicial == ce5.linha_inicial+lin))||
                    (pontos == 0))
                {
                    morte(se, &vidas, pontos_total, &ini);

                    reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);

                }
            }
        }

        for(lin = 0; lin<2; lin++)//passar de fase
        {
            for(col = 0; col <4; col++)
            {
                if(((se.coluna_inicial == 3+col)&&(se.linha_inicial == 1+lin))||
                    ((se.coluna_inicial == 15+col)&&(se.linha_inicial == 1+lin))||
                    ((se.coluna_inicial == 27+col)&&(se.linha_inicial == 1+lin))||
                    ((se.coluna_inicial == 39+col)&&(se.linha_inicial == 1+lin))||
                    ((se.coluna_inicial == 51+col)&&(se.linha_inicial == 1+lin)))
                {
                    pontos_total += pontos;

                    system("cls"); //limpa a tela
                    gotoxy(25,12);
                    printf("PARABENS");

                    gotoxy(25,14);
                    printf("PROXIMA FASE");
                    ini = getch();

                    reinicio(&se, &ce1,  &ce2,  &ce3,  &ce4, &ce5, &re1, &re2, &re3, &re4, &re5, &re6, &re7, &re8, &re9, &re10,
                            &re11, &re12, &te1, &te2, &te3, &te4, &te5, &te6, &pontos, &var);
                }
            }
        }

    textcolor(GREEN);//para que o sapo apareça na tela mesmo se não estiver se movimentando
    gotoxy(se.coluna_inicial,se.linha_inicial);
    cprintf("%s", um);
    gotoxy(se.coluna_inicial,se.linha_inicial+1);
    cprintf("%s", dois);


    }
    return 0;
}
