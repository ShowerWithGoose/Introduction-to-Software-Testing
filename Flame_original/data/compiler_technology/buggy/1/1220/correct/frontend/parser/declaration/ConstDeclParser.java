package frontend.parser.declaration;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class ConstDeclParser {
    //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private TokenIterator iterator;
    private Token constTk;
    private BType bType;
    private ConstDef firstConstDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> constDefs;
    private Token semicn; //;

    public ConstDeclParser(TokenIterator iterator) {
        this.iterator = iterator;
        constTk = null;
        bType = null;
        firstConstDef = null;
        commas = new ArrayList<>();
        constDefs = new ArrayList<>();
        semicn = null;
    }

    public DeclUnit parseConstDecl() {
        //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        Token t1 = iterator.getNextToken();
        if (t1.getType() != TokenType.CONSTTK) {
            System.out.println("parseConstDecl WA!-1");
            return null;
        }
        constTk = t1;
        Token t2 = iterator.getNextToken();
        if (t2.getType() != TokenType.INTTK
                && t2.getType() != TokenType.CHARTK) {
            System.out.println("parseConstDecl WA!-2");
            return null;
        }
        bType = new BType(t2);
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Token t3 = iterator.getNextToken();
        if (t3.getType() !=TokenType.IDENFR) {
            System.out.println("parseConstDecl WA!-3");
            return null;
        }
        iterator.ungetToken(1);
        ConstDefParser constDefParser = new ConstDefParser(iterator);
        firstConstDef = constDefParser.parseConstDef();
        //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'

        Token t4 = iterator.getNextToken();
        while (t4.getType() == TokenType.COMMA) {
            commas.add(t4);
            ConstDefParser constDefParser1 = new ConstDefParser(iterator);
            constDefs.add(constDefParser1.parseConstDef());
            t4 = iterator.getNextToken();
        }
        iterator.ungetToken(1);

        Token t5 = iterator.getNextToken();
        if (t5.getType() == TokenType.SEMICN) {
            semicn = t5;
        } else {
            //缺少结尾分号
            iterator.ungetToken(2);
            Token t6 = iterator.getNextToken();
            Error error = new Error(t6.getLineNum(), "i");
            ErrorList.addErrorList(error);
        }

        return new ConstDecl(constTk, bType, firstConstDef, commas, constDefs, semicn);
    }
}
