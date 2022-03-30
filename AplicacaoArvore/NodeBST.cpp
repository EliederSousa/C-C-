// NodeBST.cpp
#include "NodeBST.h"
#include "Funcionario.h"
#include "Utils.h"
#include <iostream>


using namespace std;

// Modificações no código feitas a fim de possibilitar guardar em um nó uma instância
// da classe "Funcionario" estão mostradas como comentários "AQUI"
// AQUI
NodeBST::NodeBST(long id, Funcionario func, NodeBST* parent, NodeBST* left, NodeBST* right)
	: m_ID(id)
	, m_Func(func) // AQUI
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
{
}

NodeBST::~NodeBST()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

void NodeBST::CopyDataFrom(const NodeBST* node)
{
	m_ID = node->GetID();
	m_Func = node->GetData(); // AQUI
}

long NodeBST::GetID() const
{
	return m_ID;
}

void NodeBST::SetID(long id)
{
	m_ID = id;
}

// AQUI
Funcionario NodeBST::GetData() const
{
	return m_Func; // AQUI
}

// AQUI
void NodeBST::SetData(Funcionario func)
{
	m_Func = func; // AQUI
}

NodeBST* NodeBST::GetParent() const
{
	return m_Parent;
}

void NodeBST::SetParent(NodeBST* parent)
{
	m_Parent = parent;
}

NodeBST* NodeBST::GetLeft() const
{
	return m_Left;
}

void NodeBST::SetLeft(NodeBST* left)
{
	m_Left = left;
}

NodeBST* NodeBST::GetRight() const
{
	return m_Right;
}

void NodeBST::SetRight(NodeBST* right)
{
	m_Right = right;
}

bool NodeBST::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeBST::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeBST::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeBST::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeBST::GetDepthInternal(const NodeBST* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeBST::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeBST::GetHeightInternal(const NodeBST* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}