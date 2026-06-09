package frontend.parser.declaration;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class VarDeclParser {
    private TokenIterator iterator;
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicn; //;

    public VarDeclParser(TokenIterator iterator) {
        this.iterator = iterator;
        bType = null;
        firstVarDef = null;
        commas = new ArrayList<>();
        varDefs = new ArrayList<>();
        semicn = null;
    }

    public VarDecl parseVarDecl() {
        // VarDecl → BType VarDef { ',' VarDef } ';'
        // BType → 'int' | 'char'
        Token t1 = iterator.getNextToken();
        if (t1.getType() != TokenType.INTTK && t1.getType() != TokenType.CHARTK) {
            System.out.println("parseVarDecl WA!-1");
            return null;
        }
        bType = new BType(t1);
        VarDefParser varDefParser = new VarDefParser(iterator);
        firstVarDef = varDefParser.parseVarDef();

        Token t2 = iterator.getNextToken();
        while (t2.getType() == TokenType.COMMA) {
            commas.add(t2);
            VarDefParser varDefParser1 = new VarDefParser(iterator);
            varDefs.add(varDefParser1.parseVarDef());
            t2 = iterator.getNextToken();
        }

        if (t2.getType() == TokenType.SEMICN) {
            semicn = t2;
        } else {
            //没有分号
            iterator.ungetToken(2);
            Token t3 = iterator.getNextToken();
            //退到上一个token
            Error error = new Error(t3.getLineNum(), "i");
            ErrorList.addErrorList(error);
        }
        return new VarDecl(bType, firstVarDef, commas, varDefs, semicn);
    }
}
