import java.util.ArrayList;

import frontend.Lexer;
import frontend.TokenIterator;
import frontend.parser.CompUnit;
import nodes.Token;
import utils.GlobalVars;
import utils.Reader;
import utils.Writer;

public class Compiler {
    public static void main(String[] args) throws Exception {
        ArrayList<String> sourceCode = Reader.read();
        Lexer lexer = new Lexer(sourceCode);
        lexer.process();
        ArrayList<Token> tokens = lexer.getTokens();
        if (GlobalVars.curLab == GlobalVars.CurLab.LEXER) {
            Writer.writeTokens(tokens, lexer.isHasError());
            return;
        }
        TokenIterator tokenIterator = new TokenIterator(tokens);
        CompUnit compUnit = new CompUnit(tokenIterator);
        compUnit.parse();
        if (GlobalVars.curLab.equals(GlobalVars.CurLab.PARSER)) {
            Writer.writeSyntaxTree(compUnit);
        }
    }
}
