#include <iostream>
#include <fstream>
#include "header.h"

int main() {
	Tree tree;

	tree.addWord("jana");
	tree.addWord("jastuk");
	tree.addWord("djole");
	tree.addWord("dan");

	bool valid = tree.checkWordValidation("da");
	std::cout << (valid ? "jeste" : "nije") << '\n';

	std::ofstream outWords("output.txt");
	if (outWords) {
		tree.printAllWords(outWords);

		outWords.close();
	} else
		std::cerr << "Error: file could not be created!\n";	

	return 0;
}