#include <algorithm>
#include <vector>

const int ALPHABETS = 'z' - 'a' + 1;

int toNumber(char ch)
{
	return ch - 'A';
}

struct TrieNode
{
	TrieNode* children[ALPHABETS];

	bool terminal;
	TrieNode()
		: terminal(false)
	{
	}

	~TrieNode()
	{
		for (auto& child : children)
		{
			if (child)
			{
				delete child;
			}
		}
	}

	void insert(const char* key)
	{
		if (*key == '\0')
		{
			terminal = true;
			return;
		}

		int next = toNumber(*key);
		if (children[next] == nullptr)
		{
			children[next] = new TrieNode();
		}
		children[next]->insert(key + 1);
	}

	TrieNode* find(const char* key)
	{
		if (*key == '\0')
		{
			return this;
		}

		int next = toNumber(*key);
		if (children[next] == '\0')
		{
			return nullptr;
		}
		return children[next]->find(key + 1);
	}
};

int main()
{
	TrieNode trie;

	trie.insert("Insert");
	trie.insert("delete");



	return 0;
}