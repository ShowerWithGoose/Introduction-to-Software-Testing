package frontend.parser;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Decl.ConstDecl;
import frontend.parser.Decl.Decl;
import frontend.parser.Decl.VarDecl;
import frontend.parser.Function.FuncDef;
import frontend.parser.Function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls; //可以没有
    private ArrayList<FuncDef> funcDefs; //可以没有
    private MainFuncDef mainFuncDef;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "CompUnit";

    public CompUnit(TokenList tokens) {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        parseDecls();
        parseFuncDefs();
        parseMainFuncDef();
        return errorNum;
    }

    private void parseDecls() {
        Token first = tokens.nextToken();
        Token second = tokens.nextToken();
        Token third = tokens.nextToken();
        while (!third.equals(LexType.LPARENT)) { //decl
            if (first.equals(LexType.CONSTTK)) { //const decl
                tokens.rollBack(3);
                ConstDecl constDecl = new ConstDecl(tokens);
                errorNum += constDecl.parse();
                decls.add(constDecl);
            } else { //var decl
                tokens.rollBack(3);
                VarDecl varDecl = new VarDecl(tokens);
                errorNum += varDecl.parse();
                decls.add(varDecl);
            }
            first = tokens.nextToken();
            second = tokens.nextToken();
            third = tokens.nextToken();
        }
        tokens.rollBack(3); //funcDefs or mainFuncDef
    }

    private void parseFuncDefs() {
        Token first = tokens.nextToken();
        Token second = tokens.nextToken();
        while (!second.equals(LexType.MAINTK)) { //func decl
            tokens.rollBack(2);
            FuncDef funcDef = new FuncDef(tokens);
            errorNum += funcDef.parse();
            funcDefs.add(funcDef);
            first = tokens.nextToken();
            second = tokens.nextToken();
        }
        tokens.rollBack(2); //mainFuncDef
    }

    private void parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef(tokens);
        errorNum += mainFuncDef.parse();
        this.mainFuncDef = mainFuncDef;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : decls) {
            sb.append(decl.toSyntaxTree());
        }
        for (FuncDef funcDef : funcDefs) {
            sb.append(funcDef.toSyntaxTree());
        }
        sb.append(mainFuncDef.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
