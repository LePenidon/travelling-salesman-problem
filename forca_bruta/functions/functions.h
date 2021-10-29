#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../lista_info/lista_info.h"
#include "../lista_mov/lista_mov.h"

/*a funcao procura_caminhos analisa as informacoes dentro de lista info e as 
trata para que o acesso seja mais facil*/
boolean procura_caminhos(LISTA_INFO* input, MOV* mov, int cidades);

/*cria uma matriz que guarda a guia para a resolucao do problema*/
int** guia_criar(int cidades, int cidade_origem);

/*cria um vetor que guarda o caminho final*/
int* final_criar(int cidades);

/*verifica se o movimento intermediario eh valido*/
boolean pre_condicoes(IT_MOV* aux, int** guia, int cidades, int lugar);

/*completa o caminho com as possibilidades*/
int completa(MOV* mov, int** guia, int cidades, int k);

/*volta no caminho auxiliar ate uma casa que haja movimento possivel*/
int volta(MOV* mov, int** guia, int cidades, int lugar);

/*verifica se o ultimo termo atende as restricoes do problema*/
boolean pos_condicoes(int** guia, int* final, int cidades);

/*verifica se ainda ha mais algum caminho possivel*/
boolean verificador(int** guia, int cidades);

/*printa a rota final*/
void printa_final(int* final, int cidades);

/*funcao que reune a resolucao completa do problema*/
void resolve(MOV* mov, int** guia, int* final, int cidades);

/*le o aquirvo com o input dinamicamente*/
int ler_arquivo(LISTA_INFO* input, char* arquivo);

/*apaga as estruturas guia e final, usadas para a resolucao do problema*/
void apaga_aux(int** guia, int* final);

#endif
