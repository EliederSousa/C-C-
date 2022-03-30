#include "Profissao.h"
#include <string>

using namespace std;

/*
 * class Profissao
 * @brief Uma classe que guarda alguns dados úteis relativos a um cargo específico.
 */
Profissao::Profissao(std::string CARGO, int QUANTIDADE, double SALARIO_TOTAL){
    this->cargo= CARGO;
    this->quantidade= QUANTIDADE;
    this->salario_total= SALARIO_TOTAL;
    this->media_salarial = calculaMedia();
}

// dummmy constructor :)
// Foi só para o VS Code e o compilador não reclamar.
Profissao::Profissao(){}

/*
 * double Profissao::calculaMedia()
 * @brief Calcula a média salarial de uma determinada profissão.
 */
double Profissao::calculaMedia() {
    return this->salario_total / this->quantidade;
}