// XISM-8 Assembler
// Input: main.asm
// Output: main.bin

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to convert instruction to binary representation
string instructionToBinary(const string& instruction) {
	unordered_map<string, string> instructionMap = {
		{"ADD", "0001"},
		{"SUB", "0010"},
		{"LDA", "1000"},
		{"HLT", "0000"},
		{"OUT", "1100"},
		{"add", "0001"},
		{"sub", "0010"},
		{"lda", "1000"},
		{"hlt", "0000"},
		{"out", "1100"}
	};

	auto it = instructionMap.find(instruction);
	if (it != instructionMap.end()) {
		return it->second;
	}
	else {
		return ""; // Return empty string if instruction not found
	}
}

int main() {
	ifstream inputFile("main.asm");
	ofstream outputFile("main.bin");

	if (!inputFile.is_open()) {
		cerr << "Error: Couldn't open input file." << endl;
		return 1;
	}

	if (!outputFile.is_open()) {
		cerr << "Error: Couldn't open output file." << endl;
		return 1;
	}

	string instruction;
	while (inputFile >> instruction) {
		// Check if instruction exists in the map
		string binary = instructionToBinary(instruction);
		if (!binary.empty()) {
			outputFile << binary << endl; // Write binary representation to output file
		}
	}

	inputFile.close();
	outputFile.close();

	cout << "Binary output generated successfully in main.bin" << endl;

	return 0;
}
