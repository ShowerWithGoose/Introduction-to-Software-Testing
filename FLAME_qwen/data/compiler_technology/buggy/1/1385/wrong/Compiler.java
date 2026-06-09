import Io.Text;
import node.CompUnitNode;
import token.Errorz;
import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Text text = new Text();
        Lexer lexer = new Lexer();
        ArrayList<String> lines = text.getLines();
        ArrayList<Token> tokens = lexer.getTokens(lines);
        Parser parser = new Parser(tokens);
        CompUnitNode compUnitNode = parser.CompUnit();
        ArrayList<Errorz> errors = lexer.getErrors();
        errors.addAll(parser.getErrors());
        if (errors.size()==0) {
            compUnitNode.print();
        }
        else {
            Text.printError(errors);
        }
    }
}