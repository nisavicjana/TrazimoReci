#include <iostream>
#include <fstream>
#include "Header.h"

/*Tree createTree() {
	return Tree();
}

bool checkWordValidation(Tree& tree, string myWord) {

	bool isWordValid = false;
	Node* ptreeRoot = tree.getRoot();	//ja stvarno ne znam, ovo ne radi, nista korisno nisam nasla osim
	//da sam nasla da je lik ovako sredio neki slican problem lol:

	/*Node treeRoot = tree.getRoot();
	Node* ptreeRoot = &treeRoot;
	
	

	for (size_t i = 0; i < myWord.size(); i++) {
		bool valid = false;
		size_t j;
		
		for ( j = 0; j < ptreeRoot->getChildren().size(); j++) {
			if (ptreeRoot->getChildren()[j]->getChar() == myWord[i]) {
				if (i == myWord.size() - 1 && ptreeRoot->getChildren()[j]->endOfWord)
					return true;

				valid = true;
				break;
			 }

		}

		if (!valid)
			return false;

		ptreeRoot = ptreeRoot->getChildren()[j];
		
	 }
	
	return ptreeRoot->endOfWord;

}*/ 

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