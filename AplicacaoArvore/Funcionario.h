#ifndef __FUNCIONARIO_H__
#define __FUNCIONARIO_H__

#include <string>

using namespace std;

class Funcionario {
    public:
    string nome;
    string cargo;
    float salario;    
    float elementos_remuneracao;
    float remuneracao_bruta;
    string unidade;
    string jornada;

    public:
    Funcionario(string nome, string cargo, float salario, float elementos_remuneracao, float remuneracao_bruta, string unidade, string jornada );
};
#endif