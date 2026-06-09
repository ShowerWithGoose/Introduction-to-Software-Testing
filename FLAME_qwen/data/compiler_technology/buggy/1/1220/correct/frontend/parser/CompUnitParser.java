package frontend.parser;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;
import frontend.parser.function.*;

import frontend.lexer.Token;

import java.util.ArrayList;

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
public class CompUnitParser {
    Compiler compiler;
    private ArrayList<Token> tokenList;
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;
    private TokenIterator iterator;

    public CompUnitParser(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
        this.iterator = new TokenIterator(tokenList);
    }

    public CompUnit parseCompUnit() {
        parseDecls();
        parseFuncDefs();
        parseMainFuncDef();
        //把parse的结果加入parser的属性里
        //所以unitparser的属性最后和unit的属性是完全一致的？
        CompUnit compUnit = new CompUnit(decls, funcDefs, mainFuncDef);
        return compUnit;
    }

    public void parseDecls() {
        // Decl → ConstDecl | VarDecl
        // 把Iterator（一个类的实例）传递给别的构造函数，在别的类中对其进行操作，这里的Iterator也会随之改变
        while (iterator.hasNext()) {
            Token t1 = iterator.getNextToken();
            if (t1.getType() == TokenType.CONSTTK) {
                //Decl
                this.iterator.ungetToken(1);
                DeclParser declParser = new DeclParser(iterator);
                this.decls.add(declParser.parseDecl());
            } else if (t1.getType() == TokenType.VOIDTK) {
                //not Decl
                this.iterator.ungetToken(1);
                return;
            } else {
                Token t2 = iterator.getNextToken();
                Token t3 = iterator.getNextToken();
                if (t3.getType() == TokenType.LPARENT) {
                    //not Decl
                    iterator.ungetToken(3);
                    return;
                } else {
                    iterator.ungetToken(3);
                    DeclParser declParser = new DeclParser(iterator);
                    decls.add(declParser.parseDecl());
                }
            }
        }
    }

    public void parseFuncDefs() {
        // {FuncDef}
        while (iterator.hasNext()) {
            Token t1 = iterator.getNextToken();
            Token t2 = iterator.getNextToken();
            if (t2.getType() == TokenType.MAINTK) {
                iterator.ungetToken(2);
                return;
            } else {
                iterator.ungetToken(2);
                FuncDefParser funcDefParser = new FuncDefParser(iterator);
                funcDefs.add(funcDefParser.parseFuncDef());
            }
        }
    }

    public void parseMainFuncDef() {
        Token t1 = iterator.getNextToken();
        Token t2 = iterator.getNextToken();
        if (t2.getType() != TokenType.MAINTK) {
            System.out.println("parseMainFuncDef WA!");
        } else {
            iterator.ungetToken(2);
            MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(iterator);
            mainFuncDef = mainFuncDefParser.parseMainFuncDef();
        }
    }
}
