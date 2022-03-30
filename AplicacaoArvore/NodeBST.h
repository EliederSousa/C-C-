// NodeBST.h
#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include "Funcionario.h"

#include <string>

// Modificações no código feitas a fim de possibilitar guardar em um nó uma instância
// da classe "Funcionario" estão mostradas como comentários "AQUI"
class NodeBST
{
public:
	NodeBST(long id, Funcionario func, NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST(); // aqui

	void CopyDataFrom(const NodeBST* node);

	long GetID() const;
	void SetID(long id);

	Funcionario GetData() const; // aqui
	void SetData(Funcionario data); // aqui

	/* 
		*  PrintNodeInfo( NodeBST* node )
		*  @brief   Imprime as informações de um funcionário.
		*/
	void PrintNodeInfo(); // aqui

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	long m_ID;
	Funcionario m_Func; // aqui
	
	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
