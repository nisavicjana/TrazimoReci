#include <iostream>
#include <fstream>
#include "Header.h"



int main() {
	Tree tree;

	tree.addWord("jana");
	tree.addWord("jastuk");
	tree.addWord("djole");
	tree.addWord("dan");

	bool valid = tree.checkWordValidation("da");
	std::cout << (valid ? "jeste" : "nije") << '\n';

	std::ofstream outWords("output.txt");
	if (!outWords) {
		std::cerr << "Error: file could not be created!\n";
		exit(0);
	}
	tree.printAllWords(outWords);
	outWords.close();
}