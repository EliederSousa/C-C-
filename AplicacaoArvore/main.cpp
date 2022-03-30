/*
 * Introdução a data science com estrutura de dados.
 * Universidade Presbiteriana Mackenzie
 * Turma: 04G
 *
 * 32095971 | VALDIR LOPES JUNIOR
 * 32093659 | ELIEDER DAMASCENO SOUSA
 * 32092921 | MATHEUS HENRIQUE DA SILVA APOSTULO
 * 42019877 | JOSÉ EDUARDO BERNARDINO JORGE
 * 
 */
#include <iostream>
#include <string>
#include <locale.h> // Para fins de localização
#include <iomanip>  // Necessário para usar std::setprecision()
#include <fstream>  // Necessário para ler o arquivo
#include "Funcionario.h" // Classe Funcionario
#include "BST.h"
#include <algorithm> // Para funções de conversão
#include <cstring>

using namespace std;

#define MAXFUNCIONARIOS 123193

BST bst = BST();

/* 
 *  converteStringFloat( string str )
 *  @brief   Função para converter string para float
 */
float converteStringFloat( string str ) {
    // Devido ao arquivo conter valores numéricos com os milhares separados por pontos, 
    // ex: 2.4003,23 ; precisamos remover os mesmos antes de fazer a conversão dos salários.
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
	// converte string para float
    float num_float = std::stod(str);
    return num_float;
}

/* 
 *  converteStringInt( string str )
 *  @brief   Função para converter string para int
 */
int converteStringInt( string str ) {
    // Devido ao arquivo conter valores numéricos com os milhares separados por pontos, 
    // ex: 2.4003,23 ; precisamos remover os mesmos antes de fazer a conversão dos salários.
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
	// converte string para int
    int num_int = stoi(str);
    return num_int;
}

/* 
 *  void leDados()
 *  @brief   Função para ler os dados do banco de dados
 */
void leDados() {
    // Caminho relativo do arquivo a ser lido
    string fileName = "assets/dados.csv";
    
    cout << "Lendo os dados do arquivo... por favor, aguarde...\n";

    ifstream input_file( fileName );
    string dado;
    int w = 0;

    // Array que recebe os atributos nome
    string temp[8] = {"","","","","","",""};

    // Loop que lê cada linha do arquivo csv
    while( input_file.good()) {
        string line;
        // Como o arquivo csv tem 7 colunas separadas por ponnto-vírgula,
        // usamos um switch para analisar o resto da divisão entre um contador e o número 7.
        // Ou seja, cada case é chamado de acordo com uma coluna a ser lida.
        switch( w++ % 7 ) {
            case 0:
                // Nome
                getline(input_file, dado, ';');
                temp[1] = dado;
                break;

            case 1:
                // Cargo
                getline(input_file, dado, ';');
                temp[2] = dado;
                break;

            case 2:
                // Salário - Remuneração do mês
                getline(input_file, dado, ';');
                temp[0] = dado;
                break;
                
            case 3:
                // Elementos da remuneração
                getline(input_file, dado, ';');
                temp[3] = dado;
                break; 

            case 4:
                // Remuneração Bruta
                getline(input_file, dado, ';');
                temp[4] = dado;
                break;

            case 5: 
                // Unidade
                getline(input_file, dado, ';');
                temp[5] = dado;
                break;
                 
            case 6:
                {
                    // Jornada
                    getline(input_file, dado, '\n');
                    temp[6] = dado;

                    // Após a leitura das 7 colunas de uma linha, temos a array "temp" preenchida.
                    // Definimos o ID do nó da nossa árvore BST (garantia de ID diferentes). ((Salário * 1000) + incremento do while)
                    long tempID = ((converteStringInt(temp[0]) * 100000) + w);
                    // Encapsulamos todos os dados lidos em uma instância da classe "Funcionario"
                    Funcionario func = Funcionario(temp[1], temp[2], converteStringFloat(temp[0]), converteStringFloat(temp[3]), converteStringFloat(temp[4]), temp[5], temp[6] );
                    // E inserimos um novo nó na BST com a instância.
                    bst.Insert(tempID, func);

                    // Esvazia array temporária para receber os dados do próximo funcionário
                    for( string w : temp ) {
                        w.clear();
                    }; 
                }
                
            default:
                continue;
        }
    }
    cout << "Dados lidos com sucesso!\n\n";
}

int main() { 
    setlocale(LC_ALL, "");

    /* Então, elaborar um programa contendo opções de um menu para:
    1. Leitura dos dados: no qual o arquivo original deve ter sido mapeado para um arquivo contendo
    os atributos relevantes para o grupo ler e montar a árvore BST ou AVL. Pensar na melhor forma
    de montar a estrutura de dados e o que carregar nela.
    
    2. Cinco opções contendo métodos para análise de dados, como: buscar o nome das pessoas com
    o maior e menor salário; apresentar o montante $$ gasto com os salários de um tipo de cargo;
    e/ou outras questões pertinentes para análise de dados. Cada grupo irá planejar as questões que
    deseja responder sobre os dados mapeados na estrutura montada. Com os resultados obtidos
    em cada um dos cinco métodos, apresentar uma descrição textual e/ou criar tabelas/gráficos ou
    outros recursos que julgar pertinentes para demonstrar esses resultados.
    
    3. Encerra a Aplicação: os dados alocados são liberados e a aplicação desenvolvida é finalizada. */
    
    // Loop infinito para o menu.
    bool run = true;
    while( run ) {
        cout << "\n\n";
        cout << "+---------------------------------------------------------------------------------+" << endl;   
        cout << "|                                     MENU                                        |" << endl;   
        cout << "+---------------------------------------------------------------------------------+" << endl;   
        cout << "| [1] Le os dados do arquivo                                                      |" << endl;
        cout << "| [2] Calcula os gastos publicos com todos os servidores e a media salarial       |" << endl;
        cout << "| [3] Mostra total gasto com determinada profissao                                |" << endl;
        cout << "| [4] Mostra cargos com media salarial maior que um salario digitado pelo usuario |" << endl;
        cout << "| [5] Possiveis servidores de um cargo especifico fora do padrao                  |" << endl;
        cout << "| [6] Mostra dados de todos os cargos                                             |" << endl;
        cout << "| [7] Finaliza a aplicacao                                                        |" << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;

        cout << "Digite a sua escolha: " << endl;
        int entrada;
        cin >> entrada;

        switch( entrada ) {
            case 1:
                // [1] Le os dados do arquivo.
                leDados();
                cout << "\nBase de dados com " << bst.getCount() << " elementos. \n\n";
                break;
            
            case 2:
                // [2] Calcula os gastos publicos com todos os servidores e a media salarial
                cout << fixed << std::setprecision(2);
                cout << "Gastos publicos totais: R$ " << bst.gastosPublicos() << "\n";
                cout << "A media salarial de todos os servidores e: R$ " << bst.gastosPublicos() / bst.getCount() << endl;
                break;

            case 3:
            {
                // [3] Mostra total gasto com determinada profissão
                cout << "Determine a profissao que queira mostrar o gasto: " << endl;
                string escolha_profissao;
                // Habilita ler a entrada do cin inteira (inclusive os espaços)
                cin.ignore();
                getline(cin, escolha_profissao);
                double total_profissao = bst.gastosDeterminadaProfissao(escolha_profissao);
                // Verifica se a profissão existe na base de dados
                if(total_profissao != -1) {
                    cout << fixed << setprecision(2);
                    cout << "O total gasto com a profissao " << escolha_profissao << " foi: " << total_profissao;
                } else {
                    cout << "Profissao nao encontrada na base de dados!";
                }
                 
                break;
            }
            case 4:
            {   
                // [4] Mostra cargos com media salarial maior que um salario digitado pelo usuário
                cout << "Digite um salario para que voce saiba quais cargos tem media salarial maior: " << endl;
                double salario_usuario;
                cin >> salario_usuario;
                bst.maiorMediaSalarialCargo(salario_usuario);
                break;
            }

            case 5:
            {
                // [5] Possíveis outliers de um cargo específico
                cout << "Digite um valor X para saber os servidores que ganham X vezes a media salarial daquele cargo: " << endl;
                cout << "Ex: entrar com o valor 10 ira pesquisar quais servidores ganham 10x acima da media salarial do seu cargo:";
                int razaoSalarial;
                cin >> razaoSalarial;
                bst.mostraOutliersCargos( razaoSalarial );
                break;
            }                
                
            case 6:
                // [6] Mostra dados de todos os cargos 
                bst.dadosProfissoes();
                break;

            case 7:
                // [7] Finaliza a aplicacao.
                run = false;
                break;

            default: 
                cout << "Opcao invalida!\n";
                break;
        }
    }
    return 0;
}