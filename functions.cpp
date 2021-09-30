#include <iostream>
#include <fstream>
#include <stack>
#include "Header.h"

Node::Node(char c) {
	ch = c;
	endOfWord = false;
}

std::vector<Node*>& Node::getChildren() {
	return children;
}

char Node::getChar() {
	return ch;
}

bool Node::isLeaf() {
	return children.empty();
}

Node::~Node() {
	for (size_t i = 0; i < children.size(); i++)
		delete children[i];
}

int Node::childExists(char c) {
	for (size_t i = 0; i < children.size(); i++)
		if (children[i]->ch == c)
			return i;

	return -1;
}

void Root::addWord(std::string newWord) {
	Node* currNode = this;
	
	for (size_t i = 0; i < newWord.size(); i++) {
		int found = currNode->childExists(newWord[i]);

		if (found == -1) {
			currNode->children.push_back(new Node(newWord[i]));
			currNode = currNode->children.back();
		} else {													
			currNode = currNode->children[found];
		}
	}

	currNode->endOfWord = true;
}

void Tree::addWord(std::string word) {
	root.addWord(word);
}

Root& Tree::getRoot() {
	return root;
}

Tree::Tree() {
	std::ifstream txtFile("manjereci.txt");

	std::string tempString;
	while (txtFile >> tempString) {
		addWord(tempString);
	}

	txtFile.close();
}

void Node::recursivePrint(std::ostream& out, std::string currentStr) {
	if (ch != '\0')
		currentStr.push_back(ch);

	if (endOfWord)
		out << currentStr << '\n';
	
	for (Node* son : children)
		son->recursivePrint(out, currentStr);
}

void Tree::printAllWords(std::ostream& out) {
	root.recursivePrint(out);
}
/*void Tree::printAllWords() {
	typedef struct visitedNode {
		Node* node;
		bool visited;
	}VNode;

	//preorder

	std::stack<Node*> stack1;
	std::stack<int> stack2;
	std::string currWord;
	int charCounter = 0;
	Node* currNode = &this->root;

	do {
		charCounter++;

		if (!currNode->children.empty()) {
			for (size_t i = currNode->children.size(); i >= 0; i--) {
				stack1.push(currNode->children[i]);
			}
		}
		

		Node* currSon = stack1.top();
		stack1.pop();

		currWord.push_back(currSon->ch);

		if (currSon->endOfWord && !currSon->children.empty()) {
			std::cout << currWord << '\n';
			//charCounter = 0;
		}
			


		if (currSon->endOfWord && currSon->isLeaf()) {
			for (charCounter; charCounter > 0; charCounter--) {
				currWord.pop_back();
			   }
		}


	} while (!stack1.empty());
}*/

bool Tree::checkWordValidation(std::string myWord) {
	Node* currNode = &root;
	size_t i;

	for (i = 0; i < myWord.size(); i++) {
		size_t j = currNode->childExists(myWord[i]);

		if (j >= 0)
			currNode = currNode->children[j];
		else
			return false;
	}

	return i == myWord.size() - 1;
}