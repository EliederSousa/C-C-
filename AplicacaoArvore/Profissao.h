#ifndef PROFISSAO
#define PROFISSAO

#include <string>

using namespace std;

class Profissao{
    public:
        std::string cargo;
        int quantidade;
        double salario_total;
        double media_salarial;

    public:
        Profissao(std::string cargo, int quantidade, double salario_total);
        Profissao();
        double calculaMedia();

};


#endif