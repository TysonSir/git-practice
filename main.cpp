/*

struct Node {
int val;
Node* left;
Node* right;
};

class TreeIterator {
TreeIterator (Node* root);
Node* next();
...
};
6
4      8
中序遍历4=>6=>8

*/

#include<vector>
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
};

class TreeIterator {
public:
	TreeIterator(Node* root);
	Node* next();
private:
	void doStep(Node* root);

	Node* m_pRoot;
	Node* m_pNodeNow;
	int m_nNowIndex;
	int m_nNum;
	vector<Node*> m_vetSeq;
};

TreeIterator::TreeIterator(Node* root) :m_pRoot(root)
{
	m_nNowIndex = 0;
	m_nNum = 0;
	doStep(root);
}

Node* TreeIterator::next()
{
	if (m_nNowIndex > m_nNum - 1)
	{
		return NULL;
	}

	Node* nodeTmp = m_vetSeq[m_nNowIndex];
	++m_nNowIndex;
	return nodeTmp;
}

void TreeIterator::doStep(Node* root)
{

	if (NULL != root)
	{
		doStep(m_pRoot->left);
		m_vetSeq.push_back(root);		
		++m_nNum;
		doStep(root->right);
	}


}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

