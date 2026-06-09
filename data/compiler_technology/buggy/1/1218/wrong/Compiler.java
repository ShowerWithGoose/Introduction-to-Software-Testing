import Token.Token;
import frontend.*;

import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args){
        Lexer.getInstance().handle("testfile.txt");
        ArrayList<Token> tokens = Lexer.getInstance().getTokenList();
        Parser.getInstance().handle(tokens);
    }
}
