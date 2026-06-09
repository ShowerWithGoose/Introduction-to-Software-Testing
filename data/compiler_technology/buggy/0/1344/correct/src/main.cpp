#include "../include/frontend/Lexer.h"

using namespace std;

#define out_for_lexer_hw

int main() {
	ifstream input;
	input.open("testfile.txt");
	ofstream output_error;
	output_error.open("error.txt");

#ifdef out_for_lexer_hw
	ofstream output_for_lexer;
	output_for_lexer.open("lexer.txt");
#endif
	
	Lexer lexer(input, output_for_lexer, output_error);
	lexer.work();
	
	input.close();
	output_error.close();

#ifdef output_for_lexer_hw
	output_for_lexer.close();
#endif

	return 0;
}