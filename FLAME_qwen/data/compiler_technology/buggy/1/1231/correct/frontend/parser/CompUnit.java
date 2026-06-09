package frontend.parser;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.decl.Decl;
import frontend.parser.func.FuncDef;
import frontend.parser.func.MainFuncDef;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/* 
编译单元		
CompUnit       ==> {Decl} {FuncDef} MainFuncDef 
*/
public class CompUnit implements SyntaxNode {
    private String name = "<CompUnit>";
    private TokenIterator tokens;
    private ArrayList<Decl> decls = new ArrayList<>(); //optinal
    private ArrayList<FuncDef> funcDefs = new ArrayList<>(); //optinal
    private MainFuncDef mainFuncDef;

    public CompUnit(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public String syntaxPrinter() {
        StringBuffer s = new StringBuffer();
        decls.forEach(d -> s.append(d.syntaxPrinter()));
        funcDefs.forEach(f -> s.append(f.syntaxPrinter()));
        s.append(mainFuncDef.syntaxPrinter());
        s.append(name + '\n');
        return s.toString();
    }

    @Override
    public boolean parse() {
        return parseDecls() && parseFuncDefs() && parseMainFuncDef();
    }

    private boolean parseDecls() {
        Token token1 = tokens.next();
        Token token2 = tokens.next();
        while (tokens.hasNext()) {
            Token token3 = tokens.next();
            if (token3.getType().equals(TokenType.LPARENT)) {
                tokens.stepBack(3);
                break;
            }
            tokens.stepBack(1);
            if (token1.getType().equals(TokenType.CONSTTK)
                    || token1.getType().equals(TokenType.INTTK) && token2.getType().equals(TokenType.IDENFR)
                    || token1.getType().equals(TokenType.CHARTK) && token2.getType().equals(TokenType.IDENFR)) {
                tokens.stepBack(2);

                Decl decl = new Decl(tokens);
                decl.parse();
                decls.add(decl);

                token1 = tokens.next();
                token2 = tokens.next();
            } else {
                tokens.stepBack(2);
                break;
            }
        }
        return true;
    }

    private boolean parseFuncDefs() {
        Token token1 = tokens.next();
        Token token2 = tokens.next();
        while (tokens.hasNext()) {
            if (!token2.getType().equals(TokenType.MAINTK)) {
                tokens.stepBack(2);
                FuncDef funcDef = new FuncDef(tokens);
                funcDef.parse();
                funcDefs.add(funcDef);
            } else {
                tokens.stepBack(2);
                break;
            }
            token1 = tokens.next();
            token2 = tokens.next();
        }
        return true;
    }

    private boolean parseMainFuncDef() {
        mainFuncDef = new MainFuncDef(tokens);
        return mainFuncDef.parse();
    }
}
