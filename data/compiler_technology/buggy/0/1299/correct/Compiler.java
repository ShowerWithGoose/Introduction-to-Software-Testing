import lexical_analysis.myLexical;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        myLexical lexical = new myLexical();
        lexical.printLexicalRes();
    }
}
