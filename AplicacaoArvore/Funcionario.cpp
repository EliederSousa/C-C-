#include "Funcionario.h"
#include <string>

using namespace std;

// Classe que encapsula os dados dos servidores para guardar em um nó da BST.
Funcionario::Funcionario( string NOME, string CARGO, float SALARIO, float ELEMENTOS_REMUNERACAO, float REMUNERACAO_BRUTA, string UNIDADE, string JORNADA ) {
    this->nome = NOME;
    this->cargo = CARGO;
    this->salario = SALARIO;
    this->elementos_remuneracao = ELEMENTOS_REMUNERACAO;
    this->remuneracao_bruta = REMUNERACAO_BRUTA;
    this->unidade = UNIDADE;
    this->jornada = JORNADA;

};