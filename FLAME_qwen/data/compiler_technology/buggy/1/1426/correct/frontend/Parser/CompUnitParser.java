package frontend.Parser;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Decl.Decl;
import frontend.Parser.Decl.DeclParser;

import java.util.ArrayList;

public class CompUnitParser{
    private final String name = "<Compunit>";
    private ArrayList<Token> tokens = new ArrayList<>();
    private TokenListReader reader;
    private ArrayList<Decl> decls= new ArrayList<>();
    private ArrayList<FuncDef> funcs = new ArrayList<>();
    private MainFuncDef mainFuncDef;

    public CompUnitParser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.reader = new TokenListReader(tokens);
        this.decls = new ArrayList<>();
        this.funcs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public CompUnit parseCompUnit() {
        parse1();
        parse2();
        parseMain();
        CompUnit compUnit = new CompUnit(this.decls, this.funcs, this.mainFuncDef);
        return compUnit;
    }
    public void parse1(){
        Token first = this.reader.getnextToken();
        Token second = this.reader.getnextToken();
        while (this.reader.hasNextToken()) {
            Token third = this.reader.getnextToken();
            if (third.getType().equals(TokenType.LPARENT)) {
                this.reader.backward(3);
                return;
            } else {
                this.reader.backward(1);
            }
            if ((first.getType().equals(TokenType.CONSTTK) && second.getType().equals(TokenType.INTTK)) ||
                    (first.getType().equals(TokenType.CONSTTK) && second.getType().equals(TokenType.CHARTK)) ||
                    (first.getType().equals(TokenType.INTTK) && second.getType().equals(TokenType.IDENFR)) ||
                    (first.getType().equals(TokenType.CHARTK) && second.getType().equals(TokenType.IDENFR))
            ) {
                this.reader.backward(2);
                DeclParser declParser = new DeclParser(this.reader);
                this.decls.add(declParser.parseDecl());
            } else {
                this.reader.backward(2);
                break;
            }
            first = this.reader.getnextToken();
            second = this.reader.getnextToken();
        }
    }
    public void parse2(){
        Token first = this.reader.getnextToken();
        Token second = this.reader.getnextToken();
        while (this.reader.hasNextToken()) {
            if ((first.getType().equals(TokenType.INTTK) ||
                    first.getType().equals(TokenType.VOIDTK) ||
                    first.getType().equals(TokenType.CHARTK)) &&
                    second.getType().equals(TokenType.IDENFR)) {
                this.reader.backward(2);
                FuncDefParser funcDefParser = new FuncDefParser(this.reader);
                this.funcs.add(funcDefParser.parseFuncDef());
            } else {
                this.reader.backward(2);
                break;
            }
            first = this.reader.getnextToken();
                second = this.reader.getnextToken();
        }
    }
    public void parseMain(){
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(this.reader);
        this.mainFuncDef = mainFuncDefParser.parseMainFuncDef();
    }
}
