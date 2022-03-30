#include "NodeBST.h"
#include "BST.h"
#include "Utils.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Profissao.h"

// Número de funcionários no total para ler
#define MAXFUNCIONARIOS 123193

BST::BST() {
	this->m_Root = nullptr;
	this->count = 0;
}

BST::~BST()
{
	Clear();
}

NodeBST* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

int BST::getCount() {
	return count;
}

void BST::Destroy(NodeBST* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string BST::TraverseInOrder(std::string oque) const
{
	return TraverseInOrderInternal(m_Root, oque);
}

std::string BST::TraverseInOrderInternal(const NodeBST* node, std::string oque) const {
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft(), oque);

		if (oque == "cargo") {
			oss << node->GetID() << '(' << node->GetData().cargo << ") ";
		} else if( oque == "nome") {
			oss << node->GetID() << '(' << node->GetData().nome << ") " << endl;
		} else {
			oss << node->GetID() << '(' << node->GetData().salario << ") ";
		}

		oss << TraverseInOrderInternal(node->GetRight(), oque);
		return oss.str();
	}
	return "";

}

std::string BST::TraversePreOrder( std::string oque ) const
{
	return TraversePreOrderInternal(m_Root, oque );
}

std::string BST::TraversePreOrderInternal(const NodeBST* node, std::string oque) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;

		if (oque == "cargo") {
			oss << node->GetID() << '(' << node->GetData().cargo << ") ";
		} else if( oque == "nome") {
			oss << node->GetID() << '(' << node->GetData().nome << ") ";
		} else {
			oss << node->GetID() << '(' << node->GetData().salario << ") ";
		}

		oss << TraversePreOrderInternal(node->GetLeft(), oque);
		oss << TraversePreOrderInternal(node->GetRight(), oque);
		return oss.str();
	}
	return "";
}

std::string BST::TraversePostOrder( std::string oque ) const
{
	return TraversePostOrderInternal(m_Root, oque);
}

std::string BST::TraversePostOrderInternal(const NodeBST* node, std::string oque) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft(), oque);
		oss << TraversePostOrderInternal(node->GetRight(), oque);
		
		if (oque == "cargo") {
			oss << node->GetID() << '(' << node->GetData().cargo << ") ";
		} else if( oque == "nome") {
			oss << node->GetID() << '(' << node->GetData().nome << ") ";
		} else {
			oss << node->GetID() << '(' << node->GetData().salario << ") ";
		}

		return oss.str();
	}
	return "";
}

NodeBST* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeBST* BST::FindMinInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeBST* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeBST* BST::FindMaxInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeBST* BST::Predecessor(long id) const
{
	NodeBST* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeBST* BST::PredecessorInternal(NodeBST* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::Successor(long id) const
{
	NodeBST* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeBST* BST::SuccessorInternal(NodeBST* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::SearchIterative(long id) const
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetID() != id)
	{
		if (current->GetID() > id)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

NodeBST* BST::Search(long id) const
{
	return SearchInternal(m_Root, id);
}

NodeBST* BST::SearchInternal(NodeBST* node, long &id) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		return node;
	else if (node->GetID() > id)
		return SearchInternal(node->GetLeft(), id);
	else
		return SearchInternal(node->GetRight(), id);
}

NodeBST* BST::InsertIterative(long id, Funcionario func)
{
	NodeBST* newNode = new NodeBST(id, func);
	if (IsEmpty())
	{
		m_Root = newNode;
	}
	else
	{
		NodeBST* current = m_Root;
		NodeBST* currentParent = nullptr;
		while (current != nullptr)
		{
			currentParent = current;

			// Error! Cannot insert duplicate.
			if (current->GetID() == id)
			{
				delete newNode;
				return nullptr;
			}

			if (current->GetID() > id)
				current = current->GetLeft();
			else
				current = current->GetRight();
		}

		if (currentParent != nullptr)
		{
			if (currentParent->GetID() > id)
				currentParent->SetLeft(newNode);
			else
				currentParent->SetRight(newNode);
		}
	}

	return newNode;
}

NodeBST* BST::Insert(long id, Funcionario func)
{
	count++;
	if (IsEmpty())
	{
		m_Root = new NodeBST(id, func);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, id, func);
}

NodeBST* BST::InsertInternal(NodeBST* node, NodeBST* parent, long id, Funcionario func)
{
	if (node == nullptr)
		node = new NodeBST(id, func, parent);
	else if (node->GetID() >= id)
		node->SetLeft(InsertInternal(node->GetLeft(), node, id, func));
	else if (node->GetID() < id)
		node->SetRight(InsertInternal(node->GetRight(), node, id, func));

	return node;	
}

bool BST::RemoveIterative(long id)
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetID() != id)
	{
		if (current->GetID() > id)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	if (current == nullptr)
		return false;

	RemoveNode(current);
	return true;
}

void BST::Remove(long id)
{
	count--;
	RemoveInternal(m_Root, id);
}

NodeBST* BST::RemoveInternal(NodeBST* node, long id)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		node = RemoveNode(node);
	else if (node->GetID() > id)
		node->SetLeft(RemoveInternal(node->GetLeft(), id));
	else
		node->SetRight(RemoveInternal(node->GetRight(), id));
	
	return node;
}

NodeBST* BST::RemoveNode(NodeBST* node)
{
	NodeBST* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		NodeBST* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		NodeBST* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		NodeBST* predecessor = Predecessor(node->GetID());

		// Instead of only updating pointers, we are copying the data from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetID()));
	}

	return node;
}

void BST::UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}


// MÉTODOS CRIADOS PELO GRUPO

/* 
 *  double BST::gastosPublicos()
 *  @brief   [2] Calcula os gastos publicos com todos os servidores e a media salarial
 *  Esta função soma o salário de cada servidor, e retorna a soma total.
 */
double BST::gastosPublicos() {
	// Nó auxiliar temporário
    NodeBST* nodeTemp;
    double somaTotal = 0;
	// Método usado similar ao TransverseInOrder para percorrer a BST
    for( int w=0; w<=MAXFUNCIONARIOS; w++ ) {
        if( w==0 ) {
            nodeTemp = FindMin();
        } else {
            nodeTemp = Successor(nodeTemp->GetID());
        }
        somaTotal += (double)nodeTemp->GetData().remuneracao_bruta;
    }
	delete nodeTemp; // desalocando nodeTemp
    return somaTotal; // retornando a somaTotal dos gastos 
}

/* 
 *  double gastosDeterminadaProfissao(string profissao)
 *  @brief   [3] Método da árvore BST para calcular o gasto total com a profissão selecionada para o usuário
 */
double BST::gastosDeterminadaProfissao(string profissao){
	NodeBST* nodeTemp; //nó auxiliar temporário
    long somaTotalProfissao = 0;
	int flag_achou = 0; //flag para verificação de existência do cargo
	// Método usado similar ao TransverseInOrder para percorrer a BST
    for( int i=0; i<=MAXFUNCIONARIOS; i++ ) {
        if( i==0 ) {
            nodeTemp = FindMin();
        } else {
            nodeTemp = Successor(nodeTemp->GetID());
        }
		// Se o cargo for igual a profissão dada pelo usuário, somamos a remuneração do funcionario desse cargo
		if(nodeTemp->GetData().cargo == profissao){
			somaTotalProfissao += (double)nodeTemp->GetData().remuneracao_bruta;
			flag_achou = 1; // flag sinalizando que achou
		}
		// flag para identificar se não foi encontrada a profissão dada pelo usuário
		if(flag_achou == 0){
			somaTotalProfissao = -1;
		}
    }

	delete nodeTemp; // desalocando nodeTemp
    return somaTotalProfissao; // retornando a somaTotal dos gastos com a profissao buscada
}

/* 
 *  void BST::maiorMediaSalarialCargo(double valor_usuario)
 *  @brief   [4] Método da árvore BST para calcular os cargos que tem maior média salarial que o valor de entrada do usuário
 */
void BST::maiorMediaSalarialCargo(double valor_usuario){
	// Vamos criar um vetor que guardará as profissões, um nó auxiliar que nos ajudará a percorrer a árvore e um contador auxiliar para o array de profissoes
	NodeBST* nodeTempProfissao;

	// Arrays temporárias (cache) dos cargos, quantidade de funcionários para aquele cargo
	// E o salário total referente aquele cargo.
	string cargos[290]; 
	int quantidade[290]; 
	double salario[290]; 
	int auxiliar_tamanho_array = 0;

	// Método usado similar ao TransverseInOrder para percorrer a BST
	/* Depois, iremos percorrer a árvore para poder armazenar nos vetores as profissões, quantidade de cada funcionário
	que encontrarmos e já vamos incrementando o salário desse funcionário*/
	for( int i=0; i<=MAXFUNCIONARIOS; i++ ) {
        if( i==0 ) {
            nodeTempProfissao = FindMin();
			cargos[0] = nodeTempProfissao->GetData().cargo;
			quantidade[0] = 1;
			salario[0] = nodeTempProfissao->GetData().remuneracao_bruta;
			auxiliar_tamanho_array++;
        } else {
            nodeTempProfissao = Successor(nodeTempProfissao->GetID());

			// Laço para analisar se a profissão está presente ou não no array, se estiver
			int flag_possui_profissao = 0;
			for(int j = 0; j < auxiliar_tamanho_array; j++){
				if(cargos[j] == nodeTempProfissao->GetData().cargo){
					quantidade[j]++;
					salario[j] += nodeTempProfissao->GetData().remuneracao_bruta;
					flag_possui_profissao = 1;
					break;
				}
			}

			// Verifica se há a profissão ou não no vetor
			if(flag_possui_profissao == 0){ // Cria um cargo
				cargos[auxiliar_tamanho_array] = nodeTempProfissao->GetData().cargo;
				quantidade[auxiliar_tamanho_array] = 1;
				salario[auxiliar_tamanho_array] = nodeTempProfissao->GetData().remuneracao_bruta;
				auxiliar_tamanho_array++;
			}
        }		
	}

	// Instancia o vetor do tipo profissões
	Profissao profissoes[290];
	// Laço para percorrer o vetor de profissões
	for( int w=0; w<290; w++ ) {
		profissoes[w] = Profissao(cargos[w], quantidade[w], salario[w]);
		cout << fixed << std::setprecision(2);
		// Condicional que verifica se a média salarial daquele cargo é maior que o salário dado pelo usuário
		if(profissoes[w].media_salarial > valor_usuario){
			cout << "O cargo " << profissoes[w].cargo << " tem media salarial " << profissoes[w].media_salarial << ", e eh maior que o valor " << valor_usuario << " que voce digitou!" << endl;
		}
	}

}

/* 
 *  mostraOutliersCargos()
 *  @brief   [5] Método da árvore BST que mostra os servidores que ganham mais que o normal em certo cargo
 */
void BST::mostraOutliersCargos(int quantas_vezes){
	// Vamos criar um vetor que guardará as profissões, um nó auxiliar que nos ajudará a percorrer a árvore e um contador auxiliar para o array de profissoes
	NodeBST* nodeTempProfissao;

	// Arrays temporárias (cache) dos cargos, quantidade de funcionários para aquele cargo
	// E o salário total referente aquele cargo.
	string cargos[290]; 
	int quantidade[290]; 
	double salario[290]; 
	int auxiliar_tamanho_array = 0;

	// Método usado similar ao TransverseInOrder para percorrer a BST
	/* Depois, iremos percorrer a árvore para poder armazenar nos vetores as profissões, quantidade de cada funcionário
	que encontrarmos e já vamos incrementando o salário desse funcionário*/
	for( int i=0; i<=MAXFUNCIONARIOS; i++ ) {
        if( i==0 ) {
            nodeTempProfissao = FindMin();
			cargos[0] = nodeTempProfissao->GetData().cargo;
			quantidade[0] = 1;
			salario[0] = nodeTempProfissao->GetData().remuneracao_bruta;
			auxiliar_tamanho_array++;
        } else {
            nodeTempProfissao = Successor(nodeTempProfissao->GetID());

			// Laço para analisar se a profissão está presente ou não no array, se estiver
			int flag_possui_profissao = 0;
			for(int j = 0; j < auxiliar_tamanho_array; j++){
				if(cargos[j] == nodeTempProfissao->GetData().cargo){
					quantidade[j]++;
					salario[j] += nodeTempProfissao->GetData().remuneracao_bruta;
					flag_possui_profissao = 1;
					break;
				}
			}

			// Verifica se há a profissão ou não no vetor
			if(flag_possui_profissao == 0){ // Cria um cargo
				cargos[auxiliar_tamanho_array] = nodeTempProfissao->GetData().cargo;
				quantidade[auxiliar_tamanho_array] = 1;
				salario[auxiliar_tamanho_array] = nodeTempProfissao->GetData().remuneracao_bruta;
				auxiliar_tamanho_array++;
			}
        }		
	}

	// Instancia o vetor do tipo profissões
	Profissao profissoes[290];
	for( int w=0; w<290; w++ ) {
		profissoes[w] = Profissao(cargos[w], quantidade[w], salario[w]);
	}

	// Método usado similar ao TransverseInOrder para percorrer a BST
	// Laço para prever outliers
	// Laço para percorrer todos cargos
	for(int i = 0; i < 290; i++){
		// Laço para percorrer cada indice(profissao) exibindo o funcionario
		//cout << "Outliers possiveis para os cargos " << profissoes[i].cargo << ". A media para essa profissao eh: " << profissoes[i].media_salarial << endl << endl;
		//cout << "\nOs salarios do cargo " << profissoes[i].cargo << " que ganham " << quantas_vezes << "X a mais que a media salarial "<< profissoes[i].media_salarial << " sao: " << endl;
		for(int j = 0; j < profissoes[i].quantidade; j++){
			NodeBST* nodeTemp;
			if( j==0 ) {
            	nodeTemp = FindMin();
       		}else {
         	   	nodeTemp = Successor(nodeTemp->GetID());
        	}
			// Exibe os servidores que ganham X vezes a mais que a media salarial do cargo
			if((nodeTemp->GetData().cargo == profissoes[i].cargo) && (nodeTemp->GetData().remuneracao_bruta > (quantas_vezes*profissoes[i].media_salarial)) ){	
				cout << "CARGO: " << profissoes[i].cargo << " | NOME: " << nodeTemp->GetData().nome << " | SALARIO: " << nodeTemp->GetData().remuneracao_bruta  << " | MEDIA SALARIAL DO CARGO: " << profissoes[i].media_salarial << endl;  	
			}
		}	
	}
}

/* 
 *  dadosProfissoes()
 *  @brief   [6] Método da árvore BST para calcular diversos dados dos funcionários 
 */
void BST::dadosProfissoes(){
	// Vamos criar um vetor que guardará as profissões, um nó auxiliar que nos ajudará a percorrer a árvore e um contador auxiliar para o array de profissoes
	NodeBST* nodeTempProfissao;

	// Arrays temporárias (cache) dos cargos, quantidade de funcionários para aquele cargo
	// E o salário total referente aquele cargo.
	string cargos[290]; 
	int quantidade[290]; 
	double salario[290]; 
	int auxiliar_tamanho_array = 0;

	// Método usado similar ao TransverseInOrder para percorrer a BST
	/* Depois, iremos percorrer a árvore para poder armazenar nos vetores as profissões, quantidade de cada funcionário
	que encontrarmos e já vamos incrementando o salário desse funcionário*/
	for( int i=0; i<=MAXFUNCIONARIOS; i++ ) {
        if( i==0 ) {
            nodeTempProfissao = FindMin();
			cargos[0] = nodeTempProfissao->GetData().cargo;
			quantidade[0] = 1;
			salario[0] = nodeTempProfissao->GetData().remuneracao_bruta;
			auxiliar_tamanho_array++;
        } else {
            nodeTempProfissao = Successor(nodeTempProfissao->GetID());

			// Laço para analisar se a profissão está presente ou não no array, se estiver
			int flag_possui_profissao = 0;
			for(int j = 0; j < auxiliar_tamanho_array; j++){
				if(cargos[j] == nodeTempProfissao->GetData().cargo){
					quantidade[j]++;
					salario[j] += nodeTempProfissao->GetData().remuneracao_bruta;
					flag_possui_profissao = 1;
					break;
				}
			}

			// Verifica se há a profissão ou não no vetor
			if(flag_possui_profissao == 0){ // Cria um cargo
				cargos[auxiliar_tamanho_array] = nodeTempProfissao->GetData().cargo;
				quantidade[auxiliar_tamanho_array] = 1;
				salario[auxiliar_tamanho_array] = nodeTempProfissao->GetData().remuneracao_bruta;  //AQUI MUDEI PARA REMUNERACAO BRUTA
				auxiliar_tamanho_array++;
			}
        }		
	}

	// Instancia o vetor do tipo profissões
	Profissao profissoes[290];
	for( int w=0; w<290; w++ ) {
		profissoes[w] = Profissao(cargos[w], quantidade[w], salario[w]);
		cout << fixed << std::setprecision(2);
		cout << "CARGO: " << profissoes[w].cargo << ", QUANT: " << profissoes[w].quantidade << ", SOMATOTAL: " << profissoes[w].salario_total << ", MEDIA: " << profissoes[w].calculaMedia() << "\n";
	}

}