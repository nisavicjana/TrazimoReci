#include <iostream>
#include <fstream>
#include <stack>
#include "Header.h"

Node::~Node() {
	for(auto child : children)
		delete child;
}

int Node::childExists(char c) {
	auto it = std::find(children.begin(), children.end(), c);

	if(it != children.end())
		return std::distance(it, children.begin());
	else
		return -1;
}

void Root::addWord(std::string newWord) {
	Node* currNode = this;

	for(size_t i = 0; i < newWord.size(); i++) {
		int found = currNode->childExists(newWord[i]);

		if(found == -1) {
			currNode->children.push_back(new Node(newWord[i]));
			currNode = currNode->children.back();
		} else {
			currNode = currNode->children[found];
		}
	}

	currNode->endOfWord = true;
}

Tree::Tree() {
	std::ifstream txtFile("manjereci.txt");

	std::string tempString;
	while(txtFile >> tempString) {
		addWord(tempString);
	}

	txtFile.close();
}

void Node::recursivePrint(std::ostream& out, std::string currentStr) {
	if(ch != '\0')
		currentStr.push_back(ch);

	if(endOfWord)
		out << currentStr << '\n';

	for(Node* son : children)
		son->recursivePrint(out, currentStr);
}

void Tree::printAllWords(std::ostream& out) {
	root.recursivePrint(out);
}

bool Tree::checkWordValidation(std::string myWord) {
	Node* currNode = &root;

	for(size_t i = 0; i < myWord.size(); i++) {
		int j = currNode->childExists(myWord[i]);

		if(j >= 0)
			currNode = currNode->children[j];
		else
			return false;
	}

	return true;
}