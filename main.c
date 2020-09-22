/*Nome: Vitor Moreira               Numero:33953
Curso: Engenharia Informatica
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////ESTRUTURAS/////////////////////////////////////
// estruturas permitem definir novos tipos de dados


struct Filme {

    char nomeFilme [50];
    int idade;
    char sinopse [100];
    struct genero *nomeGenero;
    struct Ator *ator2;
    int numeroAtores;

}Filme;


struct cinema {
    char nomeCinema [50];
    int  numeroFilmes;
    struct Filme *filme2  ;

}cinema;

struct Ator {
    char nomeAtor [50];
    int idade;
}Ator;

struct genero {
    char nomeGenero[50];
}genero;

struct cinema cinema1[500];
struct Filme filme1[500];
struct Ator ator1 [500];

///////////////////////////////BIBLIOTECA DE FUNCOES////////////////////////////////////////////

int numeroCinemas;
int numeroFilmes;
int numeroAtores;


void menu_principal();
void criar_filme();
void criar_cinema();
void criar_ator();
void editar_filmes();
void listar_filmes();
void listar_atores();
void editar_atores();
void remover_filmes();
void remover_atores();


/////////////////////////FUNCAO MAIN///////////////////////////////////////////////////////////

int main() {
    menu_principal();

}




void menu_principal()
{
    int opcao;

    printf("\n\n---------------------Menu----------------------\n\n");
    printf("1.  Criar Cinema\n");
    printf("2.  Criar Filme\n");
    printf("3.  Criar Ator\n");
    printf("4.  Inserir Filme\n");
    printf("5.  Inserir Ator\n");
    printf("6.  Listar Cinemas\n");
    printf("7.  Listar Filmes\n");
    printf("8.  Listar Atores\n");
    printf("9.  Listar Filmes de um Cinema\n");
    printf("10. Listar Atores de um Filme\n");
    printf("11. Editar Filmes\n");
    printf("12. Editar Atores\n");
    printf("13. Remover Filmes\n");
    printf("14. Remover Atores\n");
    printf("0. Sair\n");

    printf("-----------------------------------------------\n\n");
    do
    {

        printf("\n\nO que pretende fazer: ");
        scanf(" %d",&opcao);
        // mostra as opcoes do menu
        // le a opcao escolhida

        switch (opcao)
        {
            case 1:
                //Criaçao de um cinema
               criar_cinema();
            case 2:
                //criar filme
                criar_filme();
                break;
            case 3:
                //criar ator
                criar_ator();
                break;
            case 4:
                //inserir filme
                inserir_filme();
                break;
            case 5:
                //inserir ator
                inserir_ator();
                break;
            case 6:
                //listar cinemas
                listar_cinemas();
                break;

            case 7:
                //listar filmes
                listar_filmes();
                break;

            case 8:
                //listar atores
                listar_atores();
                break;
            case 9:
                //Listar filmes do cinema
                listar_filmes_cinema();
                break;
            case 10:
                //listar atores do filme
                listar_atores_filme();
                break;
            case 11:
                //editar os filmes
                editar_filmes();
                break;
            case 12:
                //editar atores
                editar_atores();
                break;
            case 13:
                //remover filmes
                remover_filmes();
                break;
            case 14:
                //remover atores
                remover_atores();
                break;
            case 0:
                //terminar o programa
                exit(0);

            default:
                // erro: opcao invalida
                break;
        }
    }
    while (opcao != 0);
}

void criar_cinema() {
    //funçao para criar um cinema

    int idCinema;
    fflush(stdin);
    printf("Nome do Cinema: ");
    fflush(stdin);
    fgets (cinema1[idCinema].nomeCinema, 100, stdin);
    numeroCinemas++;

}


void criar_filme (){

    int l=0,  auxFilme=0, idFilme;

    printf("Quantos filmes pretende criar: ");
    scanf("%d", &numeroFilmes);
    gets(numeroFilmes);

    for(l=0; l<numeroFilmes; l++)
    {
        auxFilme++;
    }

    fflush(stdin);
    printf("\nNome do filme: ");
    gets(filme1[idFilme].nomeFilme);

    fflush(stdin);
    printf("Genero: ");
    gets(filme1[idFilme].nomeGenero);

    fflush(stdin);
    printf("Idade Minima: ");
    scanf("%d", &(filme1[idFilme].idade));

    fflush(stdin);
    printf("Sinopse: ");
    gets(filme1[idFilme].sinopse);

    numeroFilmes++;
}

void criar_ator()
{
   int p=0, auxAtor=0, idAtor;

    printf("Quantos atores pretende criar: ");
    scanf("%d", &numeroAtores);
    gets(numeroAtores);

    for(p=0; p<numeroAtores; p++)
    {
        auxAtor++;
    }

    fflush(stdin);
    printf("\nNome: ");
    gets(ator1[idAtor].nomeAtor);

    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &(ator1[idAtor].idade));

    numeroAtores++;
}

void inserir_filme()
{
    char nomeCinema[50];  char nomeFilme[50];
    int inserirFilme, inserirCinema;
    int idCinema, idFilme, aux;

    fflush(stdin);
    printf("Nome do filme que pretende inserir: ");
    gets(inserirFilme);
    fflush(stdin);
    printf("Nome do cinema em que o pretende inserir o filme: ");
    gets(inserirCinema);
    inserir_filme(inserirCinema, inserirFilme);

    idCinema = procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeFilme);

    aux = cinema1[idCinema].numeroFilmes;

    strcpy(cinema1[idCinema].filme2[aux].nomeFilme, filme1[idFilme].nomeFilme);
    strcpy(cinema1[idCinema].filme2[aux].nomeGenero, filme1[idFilme].nomeGenero);
    cinema1[idCinema].filme2[aux].idade = filme1[idFilme].idade;

    cinema1[idCinema].numeroFilmes++;
}

void inserir_ator()
{
    char nomeCinema[50]; char nomeFilme[50]; char nomeAtor[50];
    int inserirAtor, inserirFilme, inserirCinema;
    int idCinema, idFilme, idAtor, aux;

    fflush(stdin);
    printf("Nome do ator que pretende inserir: ");
    gets(inserirAtor);
    fflush(stdin);
    printf("Nome do filme em que pretende inserir o ator: ");
    gets(inserirFilme);
    fflush(stdin);
    printf("Nome do cinema em que o pretende inserir: ");
    gets(inserirCinema);
    inserir_ator(inserirCinema, inserirFilme, inserirAtor);


    idCinema = procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeCinema, nomeFilme);
    idAtor = procurar_ator(nomeAtor);

    aux = cinema1[idCinema].filme2[idFilme].numeroAtores;

    strcpy(cinema1[idCinema].filme2[idFilme].ator2[aux].nomeAtor, ator1[idAtor].nomeAtor);
    cinema1[idCinema].filme2[idFilme].ator2[aux].idade = ator1[idAtor].idade;

    cinema1[idCinema].filme2[idFilme].numeroAtores++;
}


void listar_cinemas()
{
    int i;

    if(numeroCinemas==0)
    {
        printf("Nao existem cinemas disponiveis.\n");
    }

    printf("Cinemas disponiveis: \n");
    for(i=0; i<numeroCinemas; i++)
    {
        printf("Cinema %d: %s\n", i+1, cinema1[i].nomeCinema);
    }
}

void listar_filmes()
{
    int i;

    if(numeroFilmes==0)
    {
        printf("Nao existem filmes disponiveis. \n");
    }

    printf("Filmes disponiveis: \n");
    for(i=0; i<numeroFilmes; i++)
    {
        printf("Filme %d: %s\n", i+1, filme1[i].nomeFilme);
    }
}

void listar_atores()
{
    int i;

    if(numeroAtores==0)
    {
        printf("Nao existem atores disponiveis. \n");
    }
    printf("Atores disponiveis: \n");
    for(i=0; i<numeroAtores; i++)
    {
        printf("Ator %d: %s\n", i+1, ator1[i].nomeAtor);
    }
}

void listar_filmes_cinema()
{
    int listarCinemas, i, idCinema;
    char nomeCinema[50];

    fflush(stdin);
    printf("Nome do  cinema que pretende listar os filmes: ");
    gets(listarCinemas);
    listar_filmes_cinema(listarCinemas);
    idCinema = procurar_cinema(nomeCinema);

    printf("Existem os seguintes filmes no cinema: \n");

    for(i=0; i < cinema.numeroFilmes; i++)
    {
        printf("Filme %d: %s", i+1, cinema1[idCinema].filme2[i].nomeFilme);
    }
}
void listar_atores_filme()
{

    char nomeCinema[50]; char nomeFilme[50];
    int i, idCinema, idFilme, listarFilmes, listarCinemas;
    fflush(stdin);
    printf("Nome do filme que pretende listar os atores: ");
    gets(listarFilmes);
    fflush(stdin);
    printf("Nome do cinema que pretende listar os atores: ");
    gets(listarCinemas);
    listar_atores_filme(listarCinemas, listarFilmes);

    idCinema = procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeCinema, nomeFilme);

    printf("Existem os seguintes atores no filme: \n");

    for(i=0; i < cinema1[idCinema].filme2[idFilme].numeroAtores; i++)
    {
        printf("Ator %d: %s", i+1, cinema1[idCinema].filme2[idFilme].ator2[i].nomeAtor);
    }
}

int procurar_cinema(char nomeCinema[]){
    int i;
    for(i=0; i<numeroCinemas; i++){
        if((strcmp(nomeCinema, cinema1[i].nomeCinema)==0)){
            return i;
        }
    }
    printf("\nNao existem cinemas com esse nome.\n");
}

int procurar_filme(){
    int i;
    char ch; char nomeFilme[50];

    for(i=0; i<numeroFilmes; i++){
        if((strcmp(nomeFilme, filme1[i].nomeFilme)==0)){
            return i;
        }
    }
    printf("\nNao existem filmes com esse nome.\n");
}

int procurar_ator(){
    int i, idCinema, idFilme;
    char ch ;char nomeCinema[50]; char nomeFilme[50]; char nomeAtor[50];

    idCinema=procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeCinema, nomeFilme);

    for(i=0; i<cinema1[idCinema].filme2[idFilme].numeroAtores; i++){
        if((strcmp(nomeAtor, cinema1[idCinema].filme2[idFilme].ator2[i].nomeAtor)==0)){
            return i;
        }
    }
    printf("\nNqo existe nenhum ator disponivel na procura.\n");
}

void editar_filmes(){
    int idCinema, idFilme, nomeCinema, nomeFilmes;

    idCinema = procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeCinema, nomeFilmes);

    fflush(stdin);
    printf("\nNome do filme que deseja alterar: ");
    gets(cinema1[idCinema].filme2[idFilme].nomeFilme);

    fflush(stdin);
    printf("Genero: ");
    gets(cinema1[idCinema].filme2[idFilme].nomeGenero);

    fflush(stdin);
    printf("Sinopse: ");
    gets(cinema1[idCinema].filme2[idFilme].sinopse);

    fflush(stdin);
    printf("Idade minima: ");
    scanf("%d", &(cinema1[idCinema].filme2[idFilme].idade));

    }


void editar_atores(){
    char nomeCinema[50]; char nomeFilme[50]; char nomeAtor[50]; int idCinema; int idFilme; int idAtor;

    idCinema = procurar_cinema(nomeCinema);
    idFilme = procurar_filme(nomeCinema, nomeFilme);
    idAtor = procurar_ator(nomeCinema, nomeFilme, nomeAtor);

    fflush(stdin);
    printf("\nNome: ");
    gets(cinema1[idCinema].filme2[idFilme].ator2[idAtor].idade);

    fflush(stdin);
    printf("\nIdade: ");
    scanf("%d", &(cinema1[idCinema].filme2[idFilme].ator2[idAtor].idade));

}

void remover_filmes(){
        printf("Qual o filme que deseja remover? ");
        int idFilme;
        scanf("%d", &idFilme);
        idFilme-- ; //para ajustar aos indices que começam em 0

        if (idFilme >= 0 && idFilme < numeroFilmes){ //se a posição é valida
            int i;

            //andar todos um para trás a partir da posição a remover
            for (i = idFilme;i < numeroFilmes - 1; ++i){
                filme1[i] = filme1[i + 1];
            }

            idFilme = realloc(idFilme, --numeroFilmes * sizeof(idFilme)); //reduzir o tamanho do array em 1 unidade
        }
    }

void remover_atores(){
    printf("Qual o ator que deseja remover? ");
    int idAtor;
    scanf("%d", &idAtor);
    idAtor-- ; //para ajustar aos indices que começam em 0

    if (idAtor >= 0 && idAtor < numeroFilmes){ //se a posição é valida
        int i;

        //andar todos um para trás a partir da posição a remover
        for (i = idAtor;i < numeroFilmes - 1; ++i){
            ator1[i] = ator1[i + 1];
        }

        idAtor = realloc(idAtor, --numeroAtores * sizeof(idAtor)); //reduzir o tamanho do array em 1 unidade
    }
}
