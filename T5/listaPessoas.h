#ifndef LISTAPESSOAS_H_
#define LISTAPESSOAS_H_

typedef void *listaPessoa;

listaPessoa criaPessoa(char *cpf, char *nome, char *sobrenome, char sexo, char* nasc);

char *getCpfPessoa(listaPessoa lista);

char *getNomePessoa(listaPessoa lista);

char *getSobrenomePessoa(listaPessoa lista);

char getSexoPessoa(listaPessoa lista);

char *getNascPessoa(listaPessoa lista);

void setCpfPessoa(listaPessoa lista, char *cpf);

void setNomePessoa(listaPessoa lista, char *nome);

void setSobrenomePessoa(listaPessoa lista, char *sobrenome);

void setSexoPessoa(listaPessoa lista, char sexo);

void setNascPessoa(listaPessoa lista, char *nasc);

#endif