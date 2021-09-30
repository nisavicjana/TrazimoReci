#ifndef MyFile
#define MyFile

#include <string>
#include <vector>

class Node {
public:
	Node(char c = '\0');
	~Node();

	int childExists(char c);
	std::vector<Node*>& getChildren();
	void recursivePrint(std::ostream& out, std::string currentStr = "");

	friend class Root;
	friend class Tree;
protected:
	std::vector<Node*> children;

private:
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

