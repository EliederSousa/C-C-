// BST.h
#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"
#include "Profissao.h"

// Modificações no código feitas a fim de possibilitar guardar em um nó uma instância
// da classe "Funcionario" estão mostradas como comentários "AQUI"
class BST
{
public:
	BST();
	~BST();

	NodeBST* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	int getCount();
	Profissao profissoes[290];

	std::string TraverseInOrder( std::string oque ) const; // AQUI
	std::string TraversePreOrder( std::string oque ) const; // AQUI
	std::string TraversePostOrder( std::string oque ) const; // AQUI

	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(long id) const;
	NodeBST* Successor(long id) const;

	NodeBST* SearchIterative(long id) const;
	NodeBST* Search(long id) const;
	NodeBST* InsertIterative(long id, Funcionario func); // AQUI
	NodeBST* Insert(long id, Funcionario func); // AQUI
	bool RemoveIterative(long id);
	void Remove(long id);

	// Métodos definidos pelo grupo
	double gastosPublicos();
	double gastosDeterminadaProfissao(string profissao);
	void maiorMediaSalarialCargo(double valor_usuario);
	void mostraOutliersCargos(int quantas_vezes);
	void dadosProfissoes();
	//void salarioAcima(float maxsalario);
	//void procuraSalarioAcimaEmPreOrdem(const NodeBST* node, long maxsalario);

private:
	NodeBST* m_Root;

	void Destroy(NodeBST *node);
	
	int GetDegreeInternal(const NodeBST* node) const;

	int count;

	std::string TraverseInOrderInternal(const NodeBST* node, std::string oque) const; // AQUI
	std::string TraversePreOrderInternal(const NodeBST* node, std::string oque) const; // AQUI
	std::string TraversePostOrderInternal(const NodeBST* node, std::string oque) const; // AQUI

	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, long &id) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, long id, Funcionario func); // AQUI
	NodeBST* RemoveInternal(NodeBST* node, long id);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif