package nonTerminal;

import frontend.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls = new ArrayList<>();

    private ArrayList<FuncDef> funcDefs = new ArrayList<>();

    private MainFuncDef mainFuncDef;

    private boolean endParser;

    public CompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
        this.endParser = false;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        while (!endParser) {
            if (lexer.now().getType() == Token.Type.CONSTTK) {
                Decl decl = new Decl();
                decl.parser(lexer, errors);
                decls.add(decl);
            } else if (lexer.now().getType() == Token.Type.INTTK) {
                lexer.move();
                if (lexer.now().getType() == Token.Type.MAINTK) {
                    lexer.back();
                    mainFuncDef = new MainFuncDef();
                    mainFuncDef.parser(lexer, errors);
                    endParser = true;
                } else {
                    lexer.move();
                    if (lexer.now().getType() == Token.Type.SEMICN ||
                            lexer.now().getType() == Token.Type.ASSIGN ||
                            lexer.now().getType() == Token.Type.LBRACK ||
                            lexer.now().getType() == Token.Type.COMMA) {
                        lexer.back();
                        lexer.back();
                        Decl decl = new Decl();
                        decl.parser(lexer, errors);
                        decls.add(decl);
                    } else if (lexer.now().getType() == Token.Type.LPARENT) {
                        lexer.back();
                        lexer.back();
                        FuncDef funcDef = new FuncDef();
                        funcDef.parser(lexer, errors);
                        funcDefs.add(funcDef);
                    } else {
                        lexer.back();
                        lexer.back();
                        Decl decl = new Decl();
                        decl.parser(lexer, errors);
                        decls.add(decl);
                    }
                }
            } else if (lexer.now().getType() == Token.Type.VOIDTK) {
                FuncDef funcDef = new FuncDef();
                funcDef.parser(lexer, errors);
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
                    decl.parser(lexer, errors);
                    decls.add(decl);
                } else if (lexer.now().getType() == Token.Type.LPARENT) {
                    lexer.back();
                    lexer.back();
                    FuncDef funcDef = new FuncDef();
                    funcDef.parser(lexer, errors);
                    funcDefs.add(funcDef);
                } else {
                    lexer.back();
                    lexer.back();
                    Decl decl = new Decl();
                    decl.parser(lexer, errors);
                    decls.add(decl);
                }
            }
        }
    }

    public void output(ArrayList<String> parserResult) {
        for (Decl decl : decls) {
            decl.output(parserResult);
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.output(parserResult);
        }
        mainFuncDef.output(parserResult);
        parserResult.add("<CompUnit>");
    }
}
