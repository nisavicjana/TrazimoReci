#pragma once

#include <string>
#include <vector>

class Node {
public:
	Node(char c = '\0') : ch(c) {};
	~Node();

	int childExists(char c);
	void recursivePrint(std::ostream& out, std::string currentStr = "");

	friend class Root;
	friend class Tree;
private:
	std::vector<Node*> children;
	char ch;
	bool endOfWord = false;
};

class Root : public Node {
public:
	void addWord(std::string word);
};

class Tree {
public:
	Tree();

	void addWord(std::string word) { root.addWord(word); }
	bool checkWordValidation(std::string myWord);
	void printAllWords(std::ostream& out);
private:
	Root root;
};