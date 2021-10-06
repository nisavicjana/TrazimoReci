#ifndef MyFile
#define MyFile

#include <string>
#include <vector>

class Node {
public:
	Node(char c = '\0');
	~Node();

	int childExists(char c);
	void recursivePrint(std::ostream& out, std::string currentStr = "");

	friend class Root;
	friend class Tree;
private:
	std::vector<Node*> children;
	char ch;
	bool endOfWord;
};

class Root : public Node {
public:
	void addWord(std::string word);
};

class Tree {
public:
	Tree();

	void addWord(std::string word);
	bool checkWordValidation(std::string myWord);
	void printAllWords(std::ostream& out);
private:
	Root root;
};

#endif 

