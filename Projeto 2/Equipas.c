#include "Equipas.h"
#include "Hash.h"
#define MAX 1024
#define HASH 1777

equipa cria_equipa(char* nome)
{
    equipa nova_equipa;
    nova_equipa.nome = (char*) malloc(strlen(nome)+1);
    strcpy(nova_equipa.nome, nome);
    nova_equipa.vitorias = 0;
    return nova_equipa;
}

equipa* procura_equipa_hash(char* nome, lista_equipas** hash_table_equipas)
{
    int hash_nome = hash(nome, HASH);
    node_equipa* aux = hash_table_equipas[hash_nome] -> inicio;
    while (aux)
    {
        if (!strcmp(aux -> equipa.nome, nome))
        {
            return &(aux -> equipa);
        }
        aux = aux -> prox;
    }
    return NULL;
}

lista_equipas* cria_lista_equipas()
{
    lista_equipas* novo = malloc(sizeof(lista_equipas));
    novo -> inicio = novo -> fim = NULL;
    return novo;
}

void cria_hash_table_equipas(lista_equipas** hash_table_equipas, int hash)
{
    int i;
    for (i = 0; i < hash; i++)
    {
        hash_table_equipas[i] = cria_lista_equipas();
    }
}

void insere_fim_equipa(lista_equipas* l, equipa nova_equipa)
{
    node_equipa* n = (node_equipa*) malloc(sizeof(node_equipa));
    n -> prox = NULL;
    n -> ant = l -> fim;
    n -> equipa = nova_equipa;
    if (l -> fim)
        l -> fim -> prox = n;
    l -> fim = n;
    if (!l -> inicio)
        l -> inicio = n;
}

void insere_equipa_hash(lista_equipas** hash_table_equipas, equipa nova_equipa)
{
    int hash_nome = hash(nova_equipa.nome, HASH);
    insere_fim_equipa(hash_table_equipas[hash_nome], nova_equipa);
}

void destroi_lista_equipas(lista_equipas* l)
{
    while (l -> fim)
    {
        node_equipa* aux = l -> fim -> ant;
        free(l -> fim -> equipa.nome);
        free(l -> fim);
        l -> fim = aux;
    }
    free(l);
}

void destroi_hash_table_equipas(lista_equipas** hash_table_equipas, int hash)
{
    int i;
    for (i = 0; i < hash; i++)
    {
        destroi_lista_equipas(hash_table_equipas[i]);
    }
}