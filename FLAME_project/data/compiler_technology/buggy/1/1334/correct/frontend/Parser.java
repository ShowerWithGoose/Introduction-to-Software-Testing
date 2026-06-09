package frontend;

import java.awt.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * @author
 * @Description
 * @date 2024/10/10 22:07
 */
public class Parser {
    private ArrayList<Token> wordList = new ArrayList<>();
    private ArrayList<Error> errorList = new ArrayList<>();
    Integer index;
    Integer len;
    public ArrayList<Token> tokenList = new ArrayList<>();
    public boolean haveError;
    Integer tempIndex;


    public void parseTestFile() {
        CompUnit();

        errorList.sort(new Comparator<Error>() {
            @Override
            public int compare(Error e1, Error e2) {
                return Integer.compare(e1.getLineno(), e2.getLineno());
            }
        });

        log();
    }

    private void CompUnit(){
        while (now() != null && (now().getType() == Token.TokenType.INTTK || now().getType() == Token.TokenType.CHARTK
                || now().getType() == Token.TokenType.CONSTTK || now().getType() == Token.TokenType.VOIDTK)){
            if (now().getContent().equals("const")){
                Decl();
            } else {
                if (preRead().getType() == Token.TokenType.IDENFR) {
                    if (prePreRead().getContent().equals("(")) {
                        FuncDef();
                    } else {
                        Decl();
                    }
                } else if (preRead().getContent().equals("main")) {
                    MainFuncDef();
                }
            }
        }
        index=len-1;
        tokenList.add(new Token(Token.TokenType.NONTERM, "<CompUnit>", lastLineno()));
    }

    private void Decl(){
        if (now().getType() == Token.TokenType.CONSTTK){
            ConstDecl();
        }else {
            VarDecl();
        }
//        tokenList.add(new Token(Token.TokenType.NONTERM, "<Decl>", lastLineno()));
    }

    private void ConstDecl(){
        if (now().getType() == Token.TokenType.CONSTTK){
            tokenList.add(now());
            index++;
        }
        BType();
        ConstDef();
        while(now().getType() == Token.TokenType.COMMA){
            tokenList.add(now());
            index++;
            ConstDef();
        }
        if(now().getType() == Token.TokenType.SEMICN){
            tokenList.add(now());
            index++;
        }else {
            haveError = true;
            errorList.add(new Error(lastLineno(), 'i'));
            tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<ConstDecl>", lastLineno()));
    }

    private void BType(){
        if (now().getType() == Token.TokenType.INTTK || now().getType() == Token.TokenType.CHARTK){
            tokenList.add(now());
            index++;
        }
//        tokenList.add(new Token(Token.TokenType.NONTERM, "<BType>", lastLineno()));
    }

    private void ConstDef(){
        if (now().getType() == Token.TokenType.IDENFR){
            tokenList.add(now());
            index++;
        }
        if (now().getType() == Token.TokenType.LBRACK){
            tokenList.add(now());
            index++;
            ConstExp();
            if(now().getType() != Token.TokenType.RBRACK){
                haveError = true;
                errorList.add(new Error(lastLineno(), 'k'));
                tokenList.add(new Token(Token.TokenType.RBRACK, "]", lastLineno()));
            }else {
                tokenList.add(now());
                index++;
            }
        }
        if (now().getType() == Token.TokenType.ASSIGN){
            tokenList.add(now());
            index++;
        }
        ConstInitVal();
        tokenList.add(new Token(Token.TokenType.NONTERM, "<ConstDef>", lastLineno()));
    }

    private void ConstInitVal(){
        if (now().getType() == Token.TokenType.LBRACE){
            tokenList.add(now());
            index++;
            ConstExp();
            while(now().getType() == Token.TokenType.COMMA){
                tokenList.add(now());
                index++;
                ConstExp();
            }
            tokenList.add(now());
            index++;
        } else if (now().getType() == Token.TokenType.STRCON) {
            tokenList.add(now());
            index++;
        } else {
            ConstExp();
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<ConstInitVal>", lastLineno()));
    }

    private void VarDecl(){
        BType();
        VarDef();
        while(now().getType() == Token.TokenType.COMMA){
            tokenList.add(now());
            index++;
            VarDef();
        }
        if(now().getType() == Token.TokenType.SEMICN){
            tokenList.add(now());
            index++;
        }else {
            haveError = true;
            errorList.add(new Error(lastLineno(), 'i'));
            tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<VarDecl>", lastLineno()));
    }

    private void VarDef(){
        if (now().getType() == Token.TokenType.IDENFR){
            tokenList.add(now());
            index++;
        }
        if (now().getType() == Token.TokenType.LBRACK){
            tokenList.add(now());
            index++;
            ConstExp();
            if(now().getType() != Token.TokenType.RBRACK){
                haveError = true;
                errorList.add(new Error(lastLineno(), 'k'));
                tokenList.add(new Token(Token.TokenType.RBRACK, "]", lastLineno()));
            }else {
                tokenList.add(now());
                index++;
            }
        }
        if (now().getType() == Token.TokenType.ASSIGN){
            tokenList.add(now());
            index++;
            InitVal();
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<VarDef>", lastLineno()));
    }

    private void InitVal(){
        if (now().getType() == Token.TokenType.LBRACE){
            tokenList.add(now());
            index++;
            Exp(true);
            while(now().getType() == Token.TokenType.COMMA){
                tokenList.add(now());
                index++;
                Exp(true);
            }
            tokenList.add(now());
            index++;
        } else if (now().getType() == Token.TokenType.STRCON) {
            tokenList.add(now());
            index++;
        } else {
            Exp(true);
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<InitVal>", lastLineno()));
    }

    private void FuncDef(){
        FuncType();
        if (now().getType() == Token.TokenType.IDENFR){
            tokenList.add(now());
            index++;
        }
        if (now().getType() == Token.TokenType.LPARENT){
            tokenList.add(now());
            index++;
        }
        if (now().getType() != Token.TokenType.RPARENT && now().getType() != Token.TokenType.LBRACE){
            FuncFParams();
        }
        if (now().getType() == Token.TokenType.RPARENT){
            tokenList.add(now());
            index++;
        } else {
            haveError = true;
            errorList.add(new Error(lastLineno(), 'j'));
            tokenList.add(new Token(Token.TokenType.RPARENT, ")", lastLineno()));
        }
        Block();
        tokenList.add(new Token(Token.TokenType.NONTERM, "<FuncDef>", lastLineno()));
    }

    private void MainFuncDef(){
        tokenList.add(now());
        index++;
        tokenList.add(now());
        index++;
        if (now().getType() == Token.TokenType.LPARENT){
            tokenList.add(now());
            index++;
        }
        if (now().getType() == Token.TokenType.RPARENT){
            tokenList.add(now());
            index++;
        } else {
            haveError = true;
            errorList.add(new Error(lastLineno(), 'j'));
            tokenList.add(new Token(Token.TokenType.RBRACK, ")", lastLineno()));
        }
        Block();
        tokenList.add(new Token(Token.TokenType.NONTERM, "<MainFuncDef>", lastLineno()));
    }

    private void FuncType(){
        tokenList.add(now());
        index++;
        tokenList.add(new Token(Token.TokenType.NONTERM, "<FuncType>", lastLineno()));
    }

    private void FuncFParams(){
        FuncFParam();
        while(now().getType() == Token.TokenType.COMMA){
            tokenList.add(now());
            index++;
            FuncFParam();
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<FuncFParams>", lastLineno()));
    }

    private void FuncFParam(){
        BType();
        tokenList.add(now());
        index++;
        if (now().getType() == Token.TokenType.LBRACK){
            tokenList.add(now());
            index++;
            if (now().getType() == Token.TokenType.RBRACK){
                tokenList.add(now());
                index++;
            } else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'k'));
                tokenList.add(new Token(Token.TokenType.RBRACK, "]", lastLineno()));
            }
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<FuncFParam>", lastLineno()));
    }

    private void Block(){
        tokenList.add(now());
        index++;
        while (now().getType() != Token.TokenType.RBRACE){
            BlockItem();
        }
        tokenList.add(now());
        index++;
        tokenList.add(new Token(Token.TokenType.NONTERM, "<Block>", lastLineno()));
    }

    private void BlockItem(){
        if (now().getType() == Token.TokenType.CONSTTK
                || now().getType() == Token.TokenType.INTTK || now().getType() == Token.TokenType.CHARTK){
            Decl();
        }else {
            Stmt();
        }
//        tokenList.add(new Token(Token.TokenType.NONTERM, "<BlockItem>", lastLineno()));
    }

    private void Stmt(){
        if(now().getType() == Token.TokenType.LBRACE){
            Block();
        } else if (now().getType() == Token.TokenType.IFTK) {
            tokenList.add(now());
            index++;
            tokenList.add(now());
            index++;
            Cond();
            if (now().getType() == Token.TokenType.RPARENT){
                tokenList.add(now());
                index++;
            } else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'j'));
                tokenList.add(new Token(Token.TokenType.RPARENT, ")", lastLineno()));
            }
            Stmt();
            if (now().getType() == Token.TokenType.ELSETK){
                tokenList.add(now());
                index++;
                Stmt();
            }
        } else if (now().getType() == Token.TokenType.FORTK) {
            tokenList.add(now());
            index++;
            tokenList.add(now());
            index++;
            if (now().getType() != Token.TokenType.SEMICN){
                ForStmt();
            }
            tokenList.add(now());
            index++;
            if (now().getType() != Token.TokenType.SEMICN){
                Cond();
            }
            tokenList.add(now());
            index++;
            if (now().getType() != Token.TokenType.RPARENT){
                ForStmt();
            }
            tokenList.add(now());
            index++;
            Stmt();
        } else if (now().getType() == Token.TokenType.BREAKTK || now().getType() == Token.TokenType.CONTINUETK) {
            tokenList.add(now());
            index++;
            if(now().getType() == Token.TokenType.SEMICN){
                tokenList.add(now());
                index++;
            }else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'i'));
                tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
            }
        } else if (now().getType() == Token.TokenType.RETURNTK) {
            tokenList.add(now());
            index++;
            Token.TokenType type = now().getType();
            if (type == Token.TokenType.LPARENT || type == Token.TokenType.IDENFR
                    || type == Token.TokenType.INTCON || type == Token.TokenType.CHRCON
                    || type == Token.TokenType.PLUS || type == Token.TokenType.MINU || type == Token.TokenType.NOT){
                Exp(true);
            }
            if(now().getType() == Token.TokenType.SEMICN){
                tokenList.add(now());
                index++;
            }else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'i'));
                tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
            }
        } else if (now().getType() == Token.TokenType.PRINTFTK) {
            tokenList.add(now());
            index++;
            tokenList.add(now());
            index++;
            tokenList.add(now());
            index++;
            while(now().getType() == Token.TokenType.COMMA){
                tokenList.add(now());
                index++;
                Exp(true);
            }
            if (now().getType() == Token.TokenType.RPARENT){
                tokenList.add(now());
                index++;
            } else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'j'));
                tokenList.add(new Token(Token.TokenType.RPARENT, ")", lastLineno()));
            }
            if(now().getType() == Token.TokenType.SEMICN){
                tokenList.add(now());
                index++;
            }else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'i'));
                tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
            }
        } else if (now().getType() == Token.TokenType.IDENFR) {
            tempIndex = index;
            LVal(false);
            if (now().getType() == Token.TokenType.ASSIGN){
                index = tempIndex;
                LVal(true);
                tokenList.add(now());
                index++;
                if (now().getType() == Token.TokenType.GETINTTK || now().getType() == Token.TokenType.GETCHARTK){
                    tokenList.add(now());
                    index++;
                    tokenList.add(now());
                    index++;
                    if (now().getType() == Token.TokenType.RPARENT){
                        tokenList.add(now());
                        index++;
                    } else {
                        haveError = true;
                        errorList.add(new Error(lastLineno(), 'j'));
                        tokenList.add(new Token(Token.TokenType.RPARENT, ")", lastLineno()));
                    }
                } else {
                    Exp(true);
                }
            } else {
                index = tempIndex;
                Exp(true);
            }
            if(now().getType() == Token.TokenType.SEMICN){
                tokenList.add(now());
                index++;
            }else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'i'));
                tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
            }
        } else {
            Token.TokenType type = now().getType();
            if (type == Token.TokenType.LPARENT || type == Token.TokenType.IDENFR
                    || type == Token.TokenType.INTCON || type == Token.TokenType.CHRCON
                    || type == Token.TokenType.PLUS || type == Token.TokenType.MINU || type == Token.TokenType.NOT){
                Exp(true);
            }
            if(now().getType() == Token.TokenType.SEMICN){
                tokenList.add(now());
                index++;
            }else {
                haveError = true;
                errorList.add(new Error(lastLineno(), 'i'));
                tokenList.add(new Token(Token.TokenType.SEMICN, ";", lastLineno()));
            }
        }
        tokenList.add(new Token(Token.TokenType.NONTERM, "<Stmt>", lastLineno()));
    }

    private void ForStmt(){
        LVal(true);
        tokenList.add(now());
        index++;
        Exp(true);
        tokenList.add(new Token(Token.TokenType.NONTERM, "<ForStmt>", lastLineno()));
    }

    private void Exp(boolean reading){
        AddExp(reading);
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<Exp>", lastLineno()));
    }

    private void Cond(){
        LOrExp(true);
        tokenList.add(new Token(Token.TokenType.NONTERM, "<Cond>", lastLineno()));
    }

    private void LVal(boolean reading){
        if(reading) tokenList.add(now());
        index++;
        if (now().getType() == Token.TokenType.LBRACK){
            if(reading) tokenList.add(now());
            index++;
            Exp(reading);
            if (now().getType() == Token.TokenType.RBRACK){
                if(reading) tokenList.add(now());
                index++;
            } else {
                haveError = true;
                if(reading){
                    errorList.add(new Error(lastLineno(), 'k'));
                    tokenList.add(new Token(Token.TokenType.RBRACK, "]", lastLineno()));
                }
            }
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<LVal>", lastLineno()));
    }

    private void PrimaryExp(boolean reading){
        if (now().getType() == Token.TokenType.LPARENT){
            if(reading) tokenList.add(now());
            index++;
            Exp(reading);
            if (now().getType() == Token.TokenType.RPARENT){
                if(reading) tokenList.add(now());
                index++;
            } else {
                haveError = true;
                if(reading){
                    errorList.add(new Error(lastLineno(), 'j'));
                    tokenList.add(new Token(Token.TokenType.RBRACK, ")", lastLineno()));
                }
            }
        } else if (now().getType() == Token.TokenType.INTCON) {
            Number(reading);
        } else if (now().getType() == Token.TokenType.CHRCON) {
            Character(reading);
        } else {
            LVal(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<PrimaryExp>", lastLineno()));
    }

    private void Number(boolean reading){
        if(reading) tokenList.add(now());
        index++;
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<Number>", lastLineno()));
    }

    private void Character(boolean reading){
        if(reading) tokenList.add(now());
        index++;
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<Character>", lastLineno()));
    }

    private void UnaryExp(boolean reading){
        if (now().getType() == Token.TokenType.PLUS || now().getType() == Token.TokenType.MINU
                || now().getType() == Token.TokenType.NOT){
            UnaryOp(reading);
            UnaryExp(reading);
        } else if (now().getType() == Token.TokenType.IDENFR && preRead().getType() == Token.TokenType.LPARENT) {
            if(reading) tokenList.add(now());
            index++;
            if(reading) tokenList.add(now());
            index++;
            Token.TokenType type = now().getType();
            if (type == Token.TokenType.LPARENT || type == Token.TokenType.IDENFR
                    || type == Token.TokenType.INTCON || type == Token.TokenType.CHRCON
                    || type == Token.TokenType.PLUS || type == Token.TokenType.MINU || type == Token.TokenType.NOT){
                FuncRParams(reading);
            }
            if (now().getType() == Token.TokenType.RPARENT){
                if(reading) tokenList.add(now());
                index++;
            } else {
                haveError = true;
                if(reading){
                    errorList.add(new Error(lastLineno(), 'j'));
                    tokenList.add(new Token(Token.TokenType.RBRACK, ")", lastLineno()));
                }
            }
        } else {
            PrimaryExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<UnaryExp>", lastLineno()));
    }

    private void UnaryOp(boolean reading){
        if(reading) tokenList.add(now());
        index++;
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<UnaryOp>", lastLineno()));
    }

    private void FuncRParams(boolean reading){
        Exp(reading);
        while(now().getType() == Token.TokenType.COMMA){
            if(reading) tokenList.add(now());
            index++;
            Exp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<FuncRParams>", lastLineno()));
    }

    private void MulExp(boolean reading){
        UnaryExp(reading);
        while(now().getType() == Token.TokenType.MULT || now().getType() == Token.TokenType.DIV
                || now().getType() == Token.TokenType.MOD){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<MulExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            UnaryExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<MulExp>", lastLineno()));
    }

    private void AddExp(boolean reading){
        MulExp(reading);
        while(now().getType() == Token.TokenType.PLUS || now().getType() == Token.TokenType.MINU){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<AddExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            MulExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<AddExp>", lastLineno()));
    }

    private void RelExp(boolean reading){
        AddExp(reading);
        while(now().getType() == Token.TokenType.LSS || now().getType() == Token.TokenType.GRE
                || now().getType() == Token.TokenType.LEQ || now().getType() == Token.TokenType.GEQ){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<RelExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            AddExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<RelExp>", lastLineno()));
    }

    private void EqExp(boolean reading){
        RelExp(reading);
        while(now().getType() == Token.TokenType.EQL || now().getType() == Token.TokenType.NEQ){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<EqExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            RelExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<EqExp>", lastLineno()));
    }

    private void LAndExp(boolean reading){
        EqExp(reading);
        while(now().getType() == Token.TokenType.AND){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<LAndExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            EqExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<LAndExp>", lastLineno()));
    }

    private void LOrExp(boolean reading){
        LAndExp(reading);
        while(now().getType() == Token.TokenType.OR){
            if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<LOrExp>", lastLineno()));
            if(reading) tokenList.add(now());
            index++;
            LAndExp(reading);
        }
        if(reading) tokenList.add(new Token(Token.TokenType.NONTERM, "<LOrExp>", lastLineno()));
    }

    private void ConstExp(){
        AddExp(true);
        tokenList.add(new Token(Token.TokenType.NONTERM, "<ConstExp>", lastLineno()));
    }


    private void log(){
        if(haveError){
//            System.out.println("输出错误文件中");
            try {
                String path="./error.txt";
                File file=new File(new File(path).getCanonicalPath());
                file.delete();
                if (!file.exists()) {
                    file.getParentFile().mkdirs();
                    file.createNewFile();
                }
                FileWriter writer=new FileWriter(file,true);
                for(Error error: errorList)
                    writer.write(error.toString()+"\n");
                writer.close();
            }catch (IOException e){
                System.out.println("File operation failed");
            }
        }else{
//            System.out.println("输出语法分析文件中");
            try {
                String path="./parser.txt";
                File file=new File(new File(path).getCanonicalPath());
                file.delete();
                if (!file.exists()) {
                    file.getParentFile().mkdirs();
                    file.createNewFile();
                }
                FileWriter writer=new FileWriter(file,true);
                for(Token token: tokenList)
                    if(token.getType()!= Token.TokenType.EOF)
                        writer.write(token.toString()+"\n");
                writer.close();
            }catch (IOException e){
                System.out.println("File operation failed");
            }
        }
    }


    private int lastLineno(){
        if(index>0){
            return wordList.get(index-1).getLineno();
        }else {
            return now().getLineno();
        }
    }

    Token now(){
        if (index<len) return wordList.get(index);
        else return null;
    }

    Token preRead(){
        if (index<len-1) return wordList.get(index+1);
        else return null;
    }

    Token prePreRead(){
        if (index<len-2) return wordList.get(index+2);
        else return null;
    }


    public Parser(){}

    public Parser(ArrayList<Token> wordList, ArrayList<Error> errorList){
        this.wordList = wordList;
        this.errorList = errorList;
        this.len = wordList.size();
        this.index = 0;
        this.haveError = !errorList.isEmpty();
    }
}
