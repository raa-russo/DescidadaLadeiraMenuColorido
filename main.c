#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>


void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[11][45]);
void textColor(int letras, int fundo);

//COR DA LETRA
enum{BLACK, //0
BLUE, //1
GREEN, //2
CYAN, //3
RED, //4
MAGENTA, //5
BROWN, //6
LIGHTGRAY, //7
DARKGRAY, //8
LIGHTBLUE, //9
LIGHTGREEN, //10
LIGHTCYAN, //11
LIGHTRED, //12
LIGHTMAGENTA, //13
YELLOW, //14
WHITE //15

};
//COR DO FUNDO
enum{_BLACK=0, //0
_BLUE=16, //1
_GREEN=32, //2
_CYAN=48, //3
_RED=64, //4
_MAGENTA=80, //5
_BROWN=96, //6
_LIGHTGRAY=112, //7
_DARKGRAY=128, //8
_LIGHTBLUE=144, //9
_LIGHTGREEN=160, //10
_LIGHTCYAN=176, //11
_LIGHTRED=192, //12
_LIGHTMAGENTA=208, //13
_YELLOW=224, //14
_WHITE=240 //15
};

void textColor(int letra, int fundo){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}

void linhaCol(int lin, int col){
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});// coorddenada na tela


//funcao para deixar o cursor invisivel
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
info.dwSize = 100;
info.bVisible = FALSE;
SetConsoleCursorInfo(consoleHandle, &info);
}
void box(int lin1, int col1, int lin2, int col2){
int i,j , tamlin, tamcol;

//achar o tamanho do box
tamlin = lin2 - lin1;
tamcol = col2 - col1;

//Monta o Box

for (i=col1; i<=col2; i++){ // linhas
linhaCol(lin1,i);
printf("%c",196);
linhaCol(lin2,i);
printf("%c",196);
}

for (i=lin1; i<=lin2; i++){ //colunas
linhaCol(i,col1);
printf("%c",179);
linhaCol(i,col2);
printf("%c",179);
}
for (i=lin1+1;i<lin2;i++){
for(j=col1+1;j<col2;j++){
linhaCol(i,j);printf(" ");
}
}
//Posição dos cantos
linhaCol(lin1,col1);
printf("%c",218);
linhaCol(lin1,col2);
printf("%c",191);
linhaCol(lin2,col1);
printf("%c",192);
linhaCol(lin2,col2);
printf("%c",217);

}
int menu(int lin1, int col1, int qtd, char lista[11][45]){
int opc=1, lin2, col2, linha,i,tamMaxItem, tecla;

//calcula as coordenadas
tamMaxItem = strlen(lista[0]);
//tamanho maximo do item
for(i=1; i<qtd;i++){
if(strlen(lista[i])>tamMaxItem){
tamMaxItem = strlen(lista[i]);
}
}
lin2 = lin1+(qtd*2+2);
col2 = col1+tamMaxItem+4;

//Monta Tela
textColor(WHITE, _BLUE);
setlocale(LC_ALL,"C");
box(lin1,col1,lin2,col2);
setlocale(LC_ALL,"");
//laço das opcões
while(1){

linha=lin1+2;
for(i=0;i<qtd;i++){
if(i+1==opc)textColor(BLACK, _LIGHTGREEN);
else textColor(WHITE, _BLUE);
linhaCol(linha,col1+2);
printf("%s",lista[i]);
linha +=2;
}

//Aguarda tecla
linhaCol(1,1);
tecla= getch();
linhaCol(22,1);
//printf(" tecla: %d ",tecla);
//Opção
if(tecla==27){ //ESC
opc=0; break;
}
else if(tecla==13){ //ENTER
break;
}
//Seta para cima
else if(tecla==72){ //se possivel seleciona o item anterior - seta para cima
if(opc>1)opc--; // se opcao for maior que 1, pode voltar

}
else if(tecla==80 ){ //seta para baixo
if (opc<qtd)opc++; //Se opcao for menor que quantidade de itens, posso avançar

//printf("tecla: %d ",opc);
}
}
return opc;
}
//AQUI ONDE ESTA ANOTADO TUDO QUE SERA ESPOXTO NO MENU PRINCIPAL
int main()
{
int opc;
char lista[11][45]={ ">>>>>>>>>> FAST SYSTEM <<<<<<<<<<","MENU PRINCIPAL - DIGITE A OPÇÃO DESEJADA\n  " , "1. BATERIA 01" , "2. BATERIA 02" , "3. BATERIA 03" , "4. OBTER CLASSIFICAÇÃO GERAL NA TELA" , "5. EXPORTAR CLASSIFICAÇÃO GERAL" ,"6. SAIR DO SISTEMA"};

setlocale(LC_ALL,"");
while(true)
{
opc = menu(10,10,8,lista);

if (opc==8)
{
break;
}

linhaCol(1,1);
textColor(WHITE, _RED);
//printf("\nEscolheu a opção %d", opc);

textColor(WHITE, _BLACK);
linhaCol(24,1);
printf("");

 //variaveis que receberão o tempo de cada uma das equipes
    int eq1bat1min, eq1bat1seg, eq1bat1mile;
    int eq2bat1min, eq2bat1seg, eq2bat1mile;
    int eq3bat1min, eq3bat1seg, eq3bat1mile;
    int eq4bat1min, eq4bat1seg, eq4bat1mile;
    int eq5bat1min, eq5bat1seg, eq5bat1mile;
    int eq1bat2min, eq1bat2seg, eq1bat2mile;
    int eq2bat2min, eq2bat2seg, eq2bat2mile;
    int eq3bat2min, eq3bat2seg, eq3bat2mile;
    int eq4bat2min, eq4bat2seg, eq4bat2mile;
    int eq5bat2min, eq5bat2seg, eq5bat2mile;
    int eq1bat3min, eq1bat3seg, eq1bat3mile;
    int eq2bat3min, eq2bat3seg, eq2bat3mile;
    int eq3bat3min, eq3bat3seg, eq3bat3mile;
    int eq4bat3min, eq4bat3seg, eq4bat3mile;
    int eq5bat3min, eq5bat3seg, eq5bat3mile;
    //variaveis que receberão o tempo convertido em milésimos de segundos de cada uma das equipes
    int eq1bat1min_convert_mile, eq1bat1seg_convert_mile, TempoTotal_em_mile_Eq1Bat1;
    int eq2bat1min_convert_mile, eq2bat1seg_convert_mile, TempoTotal_em_mile_Eq2Bat1;
    int eq3bat1min_convert_mile, eq3bat1seg_convert_mile, TempoTotal_em_mile_Eq3Bat1;
    int eq4bat1min_convert_mile, eq4bat1seg_convert_mile, TempoTotal_em_mile_Eq4Bat1;
    int eq5bat1min_convert_mile, eq5bat1seg_convert_mile, TempoTotal_em_mile_Eq5Bat1;
    int eq1bat2min_convert_mile, eq1bat2seg_convert_mile, TempoTotal_em_mile_Eq1Bat2;
    int eq2bat2min_convert_mile, eq2bat2seg_convert_mile, TempoTotal_em_mile_Eq2Bat2;
    int eq3bat2min_convert_mile, eq3bat2seg_convert_mile, TempoTotal_em_mile_Eq3Bat2;
    int eq4bat2min_convert_mile, eq4bat2seg_convert_mile, TempoTotal_em_mile_Eq4Bat2;
    int eq5bat2min_convert_mile, eq5bat2seg_convert_mile, TempoTotal_em_mile_Eq5Bat2;
    int eq1bat3min_convert_mile, eq1bat3seg_convert_mile, TempoTotal_em_mile_Eq1Bat3;
    int eq2bat3min_convert_mile, eq2bat3seg_convert_mile, TempoTotal_em_mile_Eq2Bat3;
    int eq3bat3min_convert_mile, eq3bat3seg_convert_mile, TempoTotal_em_mile_Eq3Bat3;
    int eq4bat3min_convert_mile, eq4bat3seg_convert_mile, TempoTotal_em_mile_Eq4Bat3;
    int eq5bat3min_convert_mile, eq5bat3seg_convert_mile, TempoTotal_em_mile_Eq5Bat3;
    //variaveis criadas anteriormente
    int min1bat1,seg1bat1,mele1bat1;
    int min1bat2,seg1bat2,mele1bat2;
    int min1bat3,seg1bat3,mele1bat3;
    int min2bat1,seg2bat1,mele2bat1;
    int min2bat2,seg2bat2,mele2bat2;
    int min2bat3,seg2bat3,mele2bat3;
    int min3bat1,seg3bat1,mele3bat1;
    int min3bat2,seg3bat2,mele3bat2;
    int min3bat3,seg3bat3,mele3bat3;
    int min4bat1,seg4bat1,mele4bat1;
    int min4bat2,seg4bat2,mele4bat2;
    int min4bat3,seg4bat3,mele4bat3;
    int min5bat1,seg5bat1,mele5bat1;
    int min5bat2,seg5bat2,mele5bat2;
    int min5bat3,seg5bat3,mele5bat3;
    int pmaior1, smaior1;
    int pmaior2, smaior2;
    int pmaior3, smaior3;
    int pmaior4, smaior4;
    int pmaior5, smaior5;
    int media1, media2, media3, media4, media5;
    int min1, seg1, mm1;
    int min2, seg2, mm2;
    int min3, seg3, mm3;
    int min4, seg4, mm4;
    int min5, seg5, mm5;
    int tempoTotalM1;
    int tempoTotalM2;
    int tempoTotalM3;
    int tempoTotalM4;
    int tempoTotalM5;
    int melhores_tempos_Eq1 = 0;
    int melhores_tempos_Eq2 = 0;
    int melhores_tempos_Eq3 = 0;
    int melhores_tempos_Eq4 = 0;
    int melhores_tempos_Eq5 = 0;
    int sel, i;

system ("cls");
//AQUI COMECA OS SWITC CASE.
    switch(opc){

    case 1:
            {
            int opc;
            char lista[11][45]={ ">>>>>>>>>> FAST SYSTEM <<<<<<<<<<","       SEJAM BEM VINDOS!","  NOSSO SISTEMA FOI DESENVOLVIDO","      COM O OBJETIVO DE MARCAR","O TEMPO DAS EQUIPES NA DESCIDA DA LADEIRA"," EVENTO REALIZADO NO DIA 21/05/2022","* VOLTAR AO MENU PRINCIPAL"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);


            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a opção %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            }
            }
            break;
            system ("cls");
    case 2:
            {
            int opc;
            char lista[11][45]={ "* SISTEMA FAST SYSTEM","* TRABALHO FEITO POR ALUNOS ADS NOTURNO:","* ROGERIO A.AUGUSTO","* LUIGI C.DE OLIVEIRA","* PEDRO C.NOBRE","* LUIZ GUST.CASTIGLIONI","* LUIZ MATEUS S.OLIVEIRA","* VOLTAR AO MENU PRINCIPAL"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);


            if (opc==8)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a opção %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            }
            }
            break;
            system ("cls");
//AQUI COMECA A MARCAÇÃO DOS TEMPOS DAS EQUIPES. MENU DA 1 BATERIA.

    case 3:
            system ("cls");
            {
            int opc;
            char lista[11][45]={ " DIGITE O TEMPO DAS EQUIPES BATERIA 1","1. Tempo da Equipe 1 na bateria 1:","2. Tempo da Equipe 2 na bateria 1:","3. Tempo da Equipe 3 na bateria 1:","4. Tempo da Equipe 4 na bateria 1:","5. Tempo da Equipe 5 na bateria 1:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,7,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a opção %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 1 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq1bat1min);
                printf("segundos: ");
                scanf("%d",&eq1bat1seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq1bat1mile);
                printf("Tempo %d:%d:%d \n", eq1bat1min, eq1bat1seg, eq1bat1mile);
                eq1bat1min_convert_mile = eq1bat1min*60000;
                eq1bat1seg_convert_mile = eq1bat1seg*1000;
                TempoTotal_em_mile_Eq1Bat1 = eq1bat1min_convert_mile + eq1bat1seg_convert_mile + eq1bat1mile;
                system("pause");
                system ("cls");

                }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 2 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq2bat1min);
                printf("segundos: ");
                scanf("%d",&eq2bat1seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq2bat1mile);
                printf("Tempo %d:%d:%d \n", eq2bat1min, eq2bat1seg, eq2bat1mile);
                eq2bat1min_convert_mile = eq2bat1min*60000;
                eq2bat1seg_convert_mile = eq2bat1seg*1000;
                TempoTotal_em_mile_Eq2Bat1 = eq2bat1min_convert_mile + eq2bat1seg_convert_mile + eq2bat1mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 3 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq3bat1min);
                printf("segundos: ");
                scanf("%d",&eq3bat1seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq3bat1mile);
                printf("Tempo %d:%d:%d \n", eq3bat1min, eq3bat1seg, eq3bat1mile);
                eq3bat1min_convert_mile = eq3bat1min*60000;
                eq3bat1seg_convert_mile = eq3bat1seg*1000;
                TempoTotal_em_mile_Eq3Bat1 = eq3bat1min_convert_mile + eq3bat1seg_convert_mile + eq3bat1mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 4 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq4bat1min);
                printf("segundos: ");
                scanf("%d",&eq4bat1seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq4bat1mile);
                printf("Tempo %d:%d:%d \n", eq4bat1min, eq4bat1seg, eq4bat1mile);
                eq4bat1min_convert_mile = eq4bat1min*60000;
                eq4bat1seg_convert_mile = eq4bat1seg*1000;
                TempoTotal_em_mile_Eq4Bat1 = eq4bat1min_convert_mile + eq4bat1seg_convert_mile + eq4bat1mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 5 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq5bat1min);
                printf("segundos: ");
                scanf("%d",&eq5bat1seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq5bat1mile);
                printf("Tempo %d:%d:%d \n", eq5bat1min, eq5bat1seg, eq5bat1mile);
                eq5bat1min_convert_mile = eq5bat1min*60000;
                eq5bat1seg_convert_mile = eq5bat1seg*1000;
                TempoTotal_em_mile_Eq5Bat1 = eq5bat1min_convert_mile + eq5bat1seg_convert_mile + eq5bat1mile;
                system("pause");
                system("cls");
             }
            }
            }
            break;
            system ("cls");


    case 4:
            system ("cls");
            {
            int opc;
            char lista[11][45]={ "DIGITE O TEMPO DAS EQUIPES DA BATERIA 2","1. Tempo da Equipe 1 na bateria 2:","2. Tempo da Equipe 2 na bateria 2:","3. Tempo da Equipe 3 na bateria 2:","4. Tempo da Equipe 4 na bateria 2:","5. Tempo da Equipe 5 na bateria 2:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,7,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a opção %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 1 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq1bat2min);
                printf("segundos: ");
                scanf("%d",&eq1bat2seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq1bat2mile);
                printf("Tempo %d:%d:%d \n", eq1bat2min, eq1bat2seg, eq1bat2mile);
                eq1bat2min_convert_mile = eq1bat2min*60000;
                eq1bat2seg_convert_mile = eq1bat2seg*1000;
                TempoTotal_em_mile_Eq1Bat2 = eq1bat2min_convert_mile + eq1bat2seg_convert_mile + eq1bat2mile;
                system("pause");
                system ("cls");

                }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 2 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq2bat2min);
                printf("segundos: ");
                scanf("%d",&eq2bat2seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq2bat2mile);
                printf("Tempo %d:%d:%d \n", eq2bat2min, eq2bat2seg, eq2bat2mile);
                eq2bat2min_convert_mile = eq2bat2min*60000;
                eq2bat2seg_convert_mile = eq2bat2seg*1000;
                TempoTotal_em_mile_Eq2Bat2 = eq2bat2min_convert_mile + eq2bat2seg_convert_mile + eq2bat2mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 3 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq3bat2min);
                printf("segundos: ");
                scanf("%d",&eq3bat2seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq3bat2mile);
                printf("Tempo %d:%d:%d \n", eq3bat2min, eq3bat2seg, eq3bat2mile);
                eq3bat2min_convert_mile = eq3bat2min*60000;
                eq3bat2seg_convert_mile = eq3bat2seg*1000;
                TempoTotal_em_mile_Eq3Bat2 = eq3bat2min_convert_mile + eq3bat2seg_convert_mile + eq3bat2mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 4 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq4bat2min);
                printf("segundos: ");
                scanf("%d",&eq4bat2seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq4bat2mile);
                printf("Tempo %d:%d:%d \n", eq4bat2min, eq4bat2seg, eq4bat2mile);
                eq4bat2min_convert_mile = eq4bat2min*60000;
                eq4bat2seg_convert_mile = eq4bat2seg*1000;
                TempoTotal_em_mile_Eq4Bat2 = eq4bat2min_convert_mile + eq4bat2seg_convert_mile + eq4bat2mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 5 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq5bat2min);
                printf("segundos: ");
                scanf("%d",&eq5bat2seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq5bat2mile);
                printf("Tempo %d:%d:%d \n", eq5bat2min, eq5bat2seg, eq5bat2mile);
                eq5bat2min_convert_mile = eq5bat2min*60000;
                eq5bat2seg_convert_mile = eq5bat2seg*1000;
                TempoTotal_em_mile_Eq5Bat2 = eq5bat2min_convert_mile + eq5bat2seg_convert_mile + eq5bat2mile;
                system("pause");
                system("cls");
             }
            }
            }
            break;
            system ("cls");

    case 5:
            system ("cls");
            {
            int opc;
            char lista[11][45]={ "DIGITE O TEMPO DAS EQUIPES DA BATERIA 3","1. Tempo da Equipe 1 na bateria 3:","2. Tempo da Equipe 2 na bateria 3:","3. Tempo da Equipe 3 na bateria 3:","4. Tempo da Equipe 4 na bateria 3:","5. Tempo da Equipe 5 na bateria 3:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,7,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a opção %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 1 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq1bat3min);
                printf("segundos: ");
                scanf("%d",&eq1bat3seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq1bat3mile);
                printf("Tempo %d:%d:%d \n", eq1bat3min, eq1bat3seg, eq1bat3mile);
                eq1bat3min_convert_mile = eq1bat3min*60000;
                eq1bat3seg_convert_mile = eq1bat3seg*1000;
                TempoTotal_em_mile_Eq1Bat3 = eq1bat3min_convert_mile + eq1bat3seg_convert_mile + eq1bat3mile;
                system("pause");
                system ("cls");

                }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 2 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq2bat3min);
                printf("segundos: ");
                scanf("%d",&eq2bat3seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq2bat3mile);
                printf("Tempo %d:%d:%d \n", eq2bat3min, eq2bat3seg, eq2bat3mile);
                eq2bat3min_convert_mile = eq2bat3min*60000;
                eq2bat3seg_convert_mile = eq2bat3seg*1000;
                TempoTotal_em_mile_Eq2Bat3 = eq2bat3min_convert_mile + eq2bat3seg_convert_mile + eq2bat3mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 3 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq3bat3min);
                printf("segundos: ");
                scanf("%d",&eq3bat3seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq3bat3mile);
                printf("Tempo %d:%d:%d \n", eq3bat3min, eq3bat3seg, eq3bat3mile);
                eq3bat3min_convert_mile = eq3bat3min*60000;
                eq3bat3seg_convert_mile = eq3bat3seg*1000;
                TempoTotal_em_mile_Eq3Bat3 = eq3bat3min_convert_mile + eq3bat3seg_convert_mile + eq3bat3mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 4 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq4bat3min);
                printf("segundos: ");
                scanf("%d",&eq4bat3seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq4bat3mile);
                printf("Tempo %d:%d:%d \n", eq4bat3min, eq4bat3seg, eq4bat3mile);
                eq4bat3min_convert_mile = eq4bat3min*60000;
                eq4bat3seg_convert_mile = eq4bat3seg*1000;
                TempoTotal_em_mile_Eq4Bat3 = eq4bat3min_convert_mile + eq4bat3seg_convert_mile + eq4bat3mile;
                system("pause");
                system ("cls");
            }
        //AQUI PEGAMOS OS TEMPOS DA EQUIPE 5 E JA TRANSFORMAMOS EM CENTESIMOS DE SEGUNDO.
             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma:\n");
                printf("minutos: ");
                scanf("%d",&eq5bat3min);
                printf("segundos: ");
                scanf("%d",&eq5bat3seg);
                printf("centésimos-segundos: ");
                scanf("%d",&eq5bat3mile);
                printf("Tempo %d:%d:%d \n", eq5bat3min, eq5bat3seg, eq5bat3mile);
                eq5bat3min_convert_mile = eq5bat3min*60000;
                eq5bat3seg_convert_mile = eq5bat3seg*1000;
                TempoTotal_em_mile_Eq5Bat3 = eq5bat3min_convert_mile + eq5bat3seg_convert_mile + eq5bat3mile;
                system("pause");
                system("cls");
             }
            }
            }

            break;
            system ("cls");


    case 6:

            system("cls");
            printf("********************** CLASSIFICAÇÃO GERAL POR EQUIPES **********************\n\n");

            printf("Calculando resultados - Aguarde um momento!\n\n");
            Sleep(2000);
            system("cls");
            printf("CLASSIFICAÇÃO GERAL POR EQUIPES\n\n");

                /*printf("O tempo cadastrado foi \n\n");

                printf("%d \t %d \t %d \t \n\n", eq1bat1min, eq1bat1seg, eq1bat1mile);
                printf("%d \t %d \t %d \t \n\n", eq2bat1min, eq2bat1seg, eq2bat1mile);
                printf("%d \t %d \t %d \t \n\n", eq3bat1min, eq3bat1seg, eq3bat1mile);
                printf("%d \t %d \t %d \t \n\n", eq4bat1min, eq4bat1seg, eq4bat1mile);
                printf("%d \t %d \t %d \t \n\n", eq5bat1min, eq5bat1seg, eq5bat1mile);
                printf("%d \t %d \t %d \t \n\n", eq1bat2min, eq1bat2seg, eq1bat2mile);
                printf("%d \t %d \t %d \t \n\n", eq2bat2min, eq2bat2seg, eq2bat2mile);
                printf("%d \t %d \t %d \t \n\n", eq3bat2min, eq3bat2seg, eq3bat2mile);
                printf("%d \t %d \t %d \t \n\n", eq4bat2min, eq4bat2seg, eq4bat2mile);
                printf("%d \t %d \t %d \t \n\n", eq5bat2min, eq5bat2seg, eq5bat2mile);
                printf("%d \t %d \t %d \t \n\n", eq1bat3min, eq1bat3seg, eq1bat3mile);
                printf("%d \t %d \t %d \t \n\n", eq2bat3min, eq2bat3seg, eq2bat3mile);
                printf("%d \t %d \t %d \t \n\n", eq3bat3min, eq3bat3seg, eq3bat3mile);
                printf("%d \t %d \t %d \t \n\n", eq4bat3min, eq4bat3seg, eq4bat3mile);
                printf("%d \t %d \t %d \t \n\n", eq5bat3min, eq5bat3seg, eq5bat3mile);

                printf("BATERIA 1\n\n");
                printf("Tempo total da equipe 1 na bateria 1 %d \n", TempoTotal_em_mile_Eq1Bat1);
                printf("Tempo total da equipe 2 na bateria 1 %d \n", TempoTotal_em_mile_Eq2Bat1);
                printf("Tempo total da equipe 3 na bateria 1 %d \n", TempoTotal_em_mile_Eq3Bat1);
                printf("Tempo total da equipe 4 na bateria 1 %d \n", TempoTotal_em_mile_Eq4Bat1);
                printf("Tempo total da equipe 5 na bateria 1 %d \n", TempoTotal_em_mile_Eq5Bat1);

                printf("BATERIA 2\n\n");
                printf("Tempo total da equipe 1 na bateria 2 %d \n", TempoTotal_em_mile_Eq1Bat2);
                printf("Tempo total da equipe 2 na bateria 2 %d \n", TempoTotal_em_mile_Eq2Bat2);
                printf("Tempo total da equipe 3 na bateria 2 %d \n", TempoTotal_em_mile_Eq3Bat2);
                printf("Tempo total da equipe 4 na bateria 2 %d \n", TempoTotal_em_mile_Eq4Bat2);
                printf("Tempo total da equipe 5 na bateria 2 %d \n", TempoTotal_em_mile_Eq5Bat2);

                printf("BATERIA 3\n\n");
                printf("Tempo total da equipe 1 na bateria 3 %d \n", TempoTotal_em_mile_Eq1Bat3);
                printf("Tempo total da equipe 2 na bateria 3 %d \n", TempoTotal_em_mile_Eq2Bat3);
                printf("Tempo total da equipe 3 na bateria 3 %d \n", TempoTotal_em_mile_Eq3Bat3);
                printf("Tempo total da equipe 4 na bateria 3 %d \n", TempoTotal_em_mile_Eq4Bat3);
                printf("Tempo total da equipe 5 na bateria 3 %d \n", TempoTotal_em_mile_Eq5Bat3);
                */

            //formula para pegar os 2 melhores tempos

            //equipe 01 ver qal os maiores tempos.mele1bat1, mele1bat2, mele1bat3

                 int menorTempo1Eq1;
                int menorTempo2Eq1;
                menorTempo1Eq1 = TempoTotal_em_mile_Eq1Bat1;
                if (TempoTotal_em_mile_Eq1Bat2 < menorTempo1Eq1){
                    menorTempo2Eq1 = menorTempo1Eq1;
                    menorTempo1Eq1 = TempoTotal_em_mile_Eq1Bat2;
                }else{
                menorTempo2Eq1 = TempoTotal_em_mile_Eq1Bat2;
                }
                if (TempoTotal_em_mile_Eq1Bat3 < menorTempo1Eq1){
                    menorTempo2Eq1 = menorTempo1Eq1;
                    menorTempo1Eq1 = TempoTotal_em_mile_Eq1Bat3;
                }else
                if(TempoTotal_em_mile_Eq1Bat3 < menorTempo2Eq1){
                    menorTempo2Eq1 = TempoTotal_em_mile_Eq1Bat3;
                }
                //printf("%d\t %d\n\n",menorTempo1Eq1, menorTempo2Eq1);

                //equipe 02 ver qal os maiores tempos.mele2bat1, mele2bat2, mele2bat3

                int menorTempo1Eq2;
                int menorTempo2Eq2;
                menorTempo1Eq2 = TempoTotal_em_mile_Eq2Bat1;
                if (TempoTotal_em_mile_Eq2Bat2 < menorTempo1Eq2){
                    menorTempo2Eq2 = menorTempo1Eq2;
                    menorTempo1Eq2 = TempoTotal_em_mile_Eq2Bat2;
                }else{
                menorTempo2Eq2 = TempoTotal_em_mile_Eq2Bat2;
                }
                if (TempoTotal_em_mile_Eq2Bat3 < menorTempo1Eq2){
                    menorTempo2Eq2 = menorTempo1Eq2;
                    menorTempo1Eq2 = TempoTotal_em_mile_Eq2Bat3;
                }else
                if(TempoTotal_em_mile_Eq1Bat3 < menorTempo2Eq2){
                    menorTempo2Eq2 = TempoTotal_em_mile_Eq2Bat3;
                }
                //printf("%d\t %d\n\n",menorTempo1Eq2, menorTempo2Eq2);

                int menorTempo1Eq3;
                int menorTempo2Eq3;
                menorTempo1Eq3 = TempoTotal_em_mile_Eq3Bat1;
                if (TempoTotal_em_mile_Eq3Bat2 < menorTempo1Eq3){
                    menorTempo2Eq3 = menorTempo1Eq3;
                    menorTempo1Eq3 = TempoTotal_em_mile_Eq3Bat2;
                }else{
                menorTempo2Eq3 = TempoTotal_em_mile_Eq3Bat2;
                }
                if (TempoTotal_em_mile_Eq3Bat3 < menorTempo1Eq3){
                    menorTempo2Eq3 = menorTempo1Eq3;
                    menorTempo1Eq3 = TempoTotal_em_mile_Eq3Bat3;
                }else
                if(TempoTotal_em_mile_Eq3Bat3 < menorTempo2Eq3){
                    menorTempo2Eq3 = TempoTotal_em_mile_Eq3Bat3;
                }
                //printf("%d\t %d\n\n",menorTempo1Eq3, menorTempo2Eq3);

                int menorTempo1Eq4;
                int menorTempo2Eq4;
                menorTempo1Eq4 = TempoTotal_em_mile_Eq4Bat1;
                if (TempoTotal_em_mile_Eq4Bat2 < menorTempo1Eq4){
                    menorTempo2Eq4 = menorTempo1Eq4;
                    menorTempo1Eq4 = TempoTotal_em_mile_Eq4Bat2;
                }else{
                menorTempo2Eq4 = TempoTotal_em_mile_Eq4Bat2;
                }
                if (TempoTotal_em_mile_Eq4Bat3 < menorTempo1Eq4){
                    menorTempo2Eq4 = menorTempo1Eq4;
                    menorTempo1Eq4 = TempoTotal_em_mile_Eq4Bat3;
                }else
                if(TempoTotal_em_mile_Eq4Bat3 < menorTempo2Eq4){
                    menorTempo2Eq4 = TempoTotal_em_mile_Eq4Bat3;
                }
                //printf("%d\t %d\n\n",menorTempo1Eq4, menorTempo2Eq4);

                int menorTempo1Eq5;
                int menorTempo2Eq5;
                menorTempo1Eq5 = TempoTotal_em_mile_Eq5Bat1;
                if (TempoTotal_em_mile_Eq5Bat2 < menorTempo1Eq5){
                    menorTempo2Eq5 = menorTempo1Eq5;
                    menorTempo1Eq5 = TempoTotal_em_mile_Eq5Bat2;
                }else{
                menorTempo2Eq5 = TempoTotal_em_mile_Eq5Bat2;
                }
                if (TempoTotal_em_mile_Eq5Bat3 < menorTempo1Eq5){
                    menorTempo2Eq5 = menorTempo1Eq5;
                    menorTempo1Eq5 = TempoTotal_em_mile_Eq5Bat3;
                }else
                if(TempoTotal_em_mile_Eq5Bat3 < menorTempo2Eq5){
                    menorTempo2Eq5 = TempoTotal_em_mile_Eq5Bat3;
                }
                //printf("%d\t %d\n\n",menorTempo1Eq5, menorTempo2Eq5);

                //achando a media entre os 2 melhores tempos
                int mediaFinalEq1;
                int mediaFinalEq2;
                int mediaFinalEq3;
                int mediaFinalEq4;
                int mediaFinalEq5;

                mediaFinalEq1 = (menorTempo1Eq1 + menorTempo2Eq1)/2;
                mediaFinalEq2 = (menorTempo1Eq2 + menorTempo2Eq2)/2;
                mediaFinalEq3 = (menorTempo1Eq3 + menorTempo2Eq3)/2;
                mediaFinalEq4 = (menorTempo1Eq4 + menorTempo2Eq4)/2;
                mediaFinalEq5 = (menorTempo1Eq5 + menorTempo2Eq5)/2;


                 //Convertendo o tempo em milesegundos para minutos:segudos:milesegundos
                //Equipe 1
                int tempoFinalMinEq1;
                int tempoFinalSegEq1;
                int tempoFinalMmEq1;

                tempoFinalMinEq1 = (mediaFinalEq1/60000);
                tempoFinalSegEq1 = (mediaFinalEq1%60000)/1000;
                tempoFinalMmEq1 = (mediaFinalEq1%60000)%1000;
                //Equipe 2
                int tempoFinalMinEq2;
                int tempoFinalSegEq2;
                int tempoFinalMmEq2;

                tempoFinalMinEq2 = (mediaFinalEq2/60000);
                tempoFinalSegEq2 = (mediaFinalEq2%60000)/1000;
                tempoFinalMmEq2 = (mediaFinalEq2%60000)%1000;
                //Equipe 3
                int tempoFinalMinEq3;
                int tempoFinalSegEq3;
                int tempoFinalMmEq3;

                tempoFinalMinEq3 = (mediaFinalEq3/60000);
                tempoFinalSegEq3 = (mediaFinalEq3%60000)/1000;
                tempoFinalMmEq3 = (mediaFinalEq3%60000)%1000;
                //Equipe 4
                int tempoFinalMinEq4;
                int tempoFinalSegEq4;
                int tempoFinalMmEq4;

                tempoFinalMinEq4 = (mediaFinalEq4/60000);
                tempoFinalSegEq4 = (mediaFinalEq4%60000)/1000;
                tempoFinalMmEq4 = (mediaFinalEq4%60000)%1000;
                //Equipe 5
                int tempoFinalMinEq5;
                int tempoFinalSegEq5;
                int tempoFinalMmEq5;

                tempoFinalMinEq5 = (mediaFinalEq5/60000);
                tempoFinalSegEq5 = (mediaFinalEq5%60000)/1000;
                tempoFinalMmEq5 = (mediaFinalEq5%60000)%1000;

                printf("********************** CLASSIFICAÇÃO GERAL POR EQUIPES **********************\n\n");
                //colocar em ordem crescente a classificação.
                int v [5] = {mediaFinalEq1, mediaFinalEq2, mediaFinalEq3, mediaFinalEq4, mediaFinalEq5};
                int aux;
                int x,y;

                for(x=0;x<4;x++)
                {
                    for(y=x+1; y<=4; y++)
                    {
                        if(v[y]<v[x])
                        {
                            aux=v[y];
                            v[y]=v[x];
                            v[x]=aux;
                        }
                    }
                }
                for (i=0; i<=4;i++){
                    if(i == 0)
                    {
                        printf(" 1° Lugar ");
                    }else
                        if(i == 1)
                        {
                            printf("2° Lugar ");
                        }else
                            if(i == 2)
                            {
                                printf("3° Lugar ");
                            }else
                                if(i == 3)
                                {
                                    printf("4° Lugar ");
                                }else
                                    if(i == 4)
                                    {
                                        printf("5° Lugar ");
                                    }

                    if( v[i] == mediaFinalEq1)
                    {
                    printf("- EQUIPE 1 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq1,tempoFinalSegEq1,tempoFinalMmEq1);
                    }

                    if( v[i] == mediaFinalEq2)
                    {
                    printf("- EQUIPE 2 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq2,tempoFinalSegEq2,tempoFinalMmEq2);
                    }

                    if( v[i] == mediaFinalEq3)
                    {
                    printf("- EQUIPE 3 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq3,tempoFinalSegEq3,tempoFinalMmEq3);
                    }

                    if( v[i] == mediaFinalEq4)
                    {
                    printf("- EQUIPE 4 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq4,tempoFinalSegEq4,tempoFinalMmEq4);
                    }

                    if( v[i] == mediaFinalEq5)
                    {
                    printf("- EQUIPE 5 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq5,tempoFinalSegEq5,tempoFinalMmEq5);
                    }
            }

            system("pause");
            system("cls");
            break;



    case 7:

        system("cls");
                printf("5. Exportar classificação geral \n");

                printf("Gerando arquivo...");
                Sleep(2000);
                system("cls");
                printf("5. Exportar classificação geral \n");
                FILE *arq;

                arq = fopen("Resultados.txt", "w");

                fprintf(arq," ===================== CORRIDA DA LADEIRA - RESULTADOS ===================== \n\n");
                fprintf(arq,"                       Classificação geral das equipes                       \n\n");

                for (i=0; i<=4;i++){

                    if(i == 0)
                    {
                        fprintf(arq," 1° Lugar ");
                    }else
                    if(i == 1)
                    {
                        fprintf(arq,"2° Lugar ");
                    }else
                    if(i == 2)
                    {
                        fprintf(arq,"3° Lugar ");
                    }else
                    if(i == 3)
                    {
                        fprintf(arq,"4° Lugar ");
                    }else
                    if(i == 4)
                    {
                        fprintf(arq,"5° Lugar ");
                    }

                    if( v[i] == mediaFinalEq1)
                    {
                        fprintf(arq,"- EQUIPE 1 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq1,tempoFinalSegEq1,tempoFinalMmEq1);
                    }
                    else{
                        if( v[i] == mediaFinalEq2)
                        {
                            fprintf(arq,"- EQUIPE 2 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq2,tempoFinalSegEq2,tempoFinalMmEq2);
                        }
                        else{
                            if( v[i] == mediaFinalEq3)
                            {
                                fprintf(arq,"- EQUIPE 3 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq3,tempoFinalSegEq3,tempoFinalMmEq3);
                            }
                            else{
                                if( v[i] == mediaFinalEq4)
                                {
                                    fprintf(arq,"- EQUIPE 4 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq4,tempoFinalSegEq4,tempoFinalMmEq4);
                                }
                                else{
                                    if( v[i] == mediaFinalEq5)
                                    {
                                        fprintf(arq,"- EQUIPE 5 - Tempo (minutos:segundos:centésimos-segundos): %d:%.2d:%.2d\n\n ",tempoFinalMinEq5,tempoFinalSegEq5,tempoFinalMmEq5);
                                    }
                                    }
                                }
                            }
                        }
                }

                fclose(arq);
                printf("\nExporção concluída com sucesso!\n");
                system("pause");
                system("cls");
                break;


    printf("\n\tPressione ENTER para continuar!\n");
    getchar();
    }
}

return 0;
}

