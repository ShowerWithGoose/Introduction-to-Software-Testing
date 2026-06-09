package nonTerminal;

import frontend.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls;

    private ArrayList<FuncDef> funcDefs;

    private MainFuncDef mainFuncDef;

    private int domainNum;

    public CompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
        this.domainNum = 1;
    }

    public void parser(Lexer lexer) {
        while (true) {
            if (lexer.now().getType() == Token.Type.CONSTTK) {
                Decl decl = new Decl();
                decl.parser(lexer);
                decls.add(decl);
            } else if (lexer.now().getType() == Token.Type.INTTK) {
                lexer.move();
                if (lexer.now().getType() == Token.Type.MAINTK) {
                    lexer.back();
                    mainFuncDef = new MainFuncDef();
                    mainFuncDef.parser(lexer);
                    break;
                } else {
                    lexer.move();
                    if (lexer.now().getType() == Token.Type.SEMICN ||
                            lexer.now().getType() == Token.Type.ASSIGN ||
                            lexer.now().getType() == Token.Type.LBRACK ||
                            lexer.now().getType() == Token.Type.COMMA) {
                        lexer.back();
                        lexer.back();
                        Decl decl = new Decl();
                        decl.parser(lexer);
                        decls.add(decl);
                    } else if (lexer.now().getType() == Token.Type.LPARENT) {
                        lexer.back();
                        lexer.back();
                        FuncDef funcDef = new FuncDef();
                        funcDef.parser(lexer);
                        funcDefs.add(funcDef);
                    } else {
                        lexer.back();
                        lexer.back();
                        Decl decl = new Decl();
                        decl.parser(lexer);
                        decls.add(decl);
                    }
                }
            } else if (lexer.now().getType() == Token.Type.VOIDTK) {
                FuncDef funcDef = new FuncDef();
                funcDef.parser(lexer);
                funcDefs.add(funcDef);
            } else if (lexer.now().getType() == Token.Type.CHARTK) {
                lexer.move();
                lexer.move();
                if (lexer.now().getType() == Token.Type.SEMICN ||
                        lexer.now().getType() == Token.Type.ASSIGN ||
                        lexer.now().getType() == Token.Type.LBRACK ||
                        lexer.now().getType() == Token.Type.COMMA) {
                    lexer.back();
                    lexer.back();
                    Decl decl = new Decl();
                    decl.parser(lexer);
                    decls.add(decl);
                } else if (lexer.now().getType() == Token.Type.LPARENT) {
                    lexer.back();
                    lexer.back();
                    FuncDef funcDef = new FuncDef();
                    funcDef.parser(lexer);
                    funcDefs.add(funcDef);
                } else {
                    lexer.back();
                    lexer.back();
                    Decl decl = new Decl();
                    decl.parser(lexer);
                    decls.add(decl);
                }
            }
        }
    }

    public void analyze(SymbolTable symbolTable) {
        symbolTable.addDomainCnt();
        symbolTable.addDomainNum(domainNum);
        for (Decl decl : decls) {
            decl.analyze(symbolTable);
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.analyze(symbolTable);
        }
        mainFuncDef.analyze(symbolTable);
    }
}
