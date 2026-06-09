package frontend;

import assist.*;
import defRelated.*;
import expRelated.*;
import funcRelated.*;
import others.*;
import stmtRelated.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokenList;
    private int cur;
    private int peek;
    private int limit;
    private boolean hasError;
    private ArrayList<String> errorList;

    public Parser(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.cur = 0;
        this.peek = 0;
        this.limit = tokenList.size();
        this.errorList = new ArrayList<>();
        this.hasError = false;
    }

    public void printNode(Node node, String toFile) throws IOException {
        if (node.getType() == Node.SyntaxType.LeafType) {
            Files.write(Paths.get(toFile), ((LeafNode) node).toString().getBytes(),
                    StandardOpenOption.APPEND, StandardOpenOption.CREATE);
        } else {
            ArrayList<Node> children = node.getChildren();
            for (Node child : children) {
                printNode(child, toFile);
            }
            if (node.getType() != Node.SyntaxType.Private) {
                Files.write(Paths.get(toFile), ("<" + node.getType().name() + ">" + "\n").getBytes(),
                        StandardOpenOption.APPEND, StandardOpenOption.CREATE);
            }
        }
    }

    public void printError(Node node, String toFile) throws IOException {
        //截止到语法分析为止，所有错误都出现在单个叶节点上
        if (node.getType() == Node.SyntaxType.LeafType && ((LeafNode) node).showError() != '\0') {
            Files.write(Paths.get(toFile), (((LeafNode) node).getStartLine() + " " + ((LeafNode) node).showError() + '\n').getBytes(),
                    StandardOpenOption.APPEND, StandardOpenOption.CREATE);
        } else {
            ArrayList<Node> children = node.getChildren();
            for (Node child : children) {
                printError(child, toFile);
            }
        }
    }

    public ArrayList<String> showErrorList() {
        return errorList;
    }

    public boolean isHasError() {
        return hasError;
    }

    private Token getCur() {
        if (cur >= limit) {
            return null;
        }
        return tokenList.get(cur);
    }

    private Token doPeek(int p) {
        if (p >= limit) {
            return null;
        }
        return tokenList.get(p);
    }

    public Node parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        compUnit.setStartLine(getCur().getLineNo());
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur() == null) { //非正常情况的函数出口
                return compUnit;
            }

            if (getCur().getType() == Token.Type.CONSTTK) {
                compUnit.addChildNode(parseConstDecl());
            } else if (getCur().getType() == Token.Type.VOIDTK) {
                compUnit.addChildNode(parseFuncDef());
            } else if (getCur().getType() == Token.Type.CHARTK) {
                peek = cur;
                peek += 2;
                if (doPeek(peek) == null) {
                    cur++;
                    continue;
                }
                if (doPeek(peek).getType() == Token.Type.LPARENT) {
                    compUnit.addChildNode(parseFuncDef());
                } else { //缺少分号也会进入这VarDecl分支
                    compUnit.addChildNode(parseVarDecl());
                }
            } else if (getCur().getType() == Token.Type.INTTK) {
                peek = cur;
                peek += 1;
                if (doPeek(peek) == null) {
                    cur++;
                    continue;
                }
                if (doPeek(peek).getType() == Token.Type.MAINTK) {
                    compUnit.addChildNode(parseMainFuncDef());
                    compUnit.setEndLine(tokenList.get(limit-1).getLineNo());
                    endFlag = true; //正常情况下的函数出口
                } else {
                    peek += 1;
                    if (doPeek(peek) == null) {
                        cur++;
                        continue;
                    }
                    if (doPeek(peek).getType() == Token.Type.LPARENT) {
                        compUnit.addChildNode(parseFuncDef());
                    } else { //缺少分号也会进入这个分支
                        compUnit.addChildNode(parseVarDecl());
                    }
                }
            }
        }
        return compUnit;
    }

    public Node parseConstDecl() {
        //能进入这个函数，证明cur一定是'const'
        //由于可能出现的错误类型只有i，所以省去了许多判断，后面的解析函数同理
        ConstDecl constDecl = new ConstDecl();
        constDecl.setStartLine(getCur().getLineNo());
        boolean endFlag = false;
        //'const'
        LeafNode leafNode = new LeafNode(Token.Type.CONSTTK,
                "const", getCur().getLineNo(),'\0');
        constDecl.addChildNode(leafNode);
        cur++;
        //BType: 'int'/'char'
        LeafNode leafNode1 = new LeafNode(getCur().getType(),
                getCur().getValue(), getCur().getLineNo(),'\0');
        constDecl.addChildNode(leafNode1);
        cur++;
        //ConstDef
        constDecl.addChildNode(parseConstDef());
        while (!endFlag) {
            if (getCur() == null) {
                return constDecl;
            }

            if (getCur().getType() == Token.Type.COMMA) {
                constDecl.addChildNode(new LeafNode(Token.Type.COMMA,
                        ",", getCur().getLineNo(), '\0'));
                cur++;
                constDecl.addChildNode(parseConstDef());
            } else if (getCur().getType() == Token.Type.SEMICN) {
                constDecl.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", getCur().getLineNo(),'\0'));
                constDecl.setEndLine(getCur().getLineNo());
                cur++;
                endFlag = true; //正常情况下的函数出口
            } else { //ConstDef后缺少;
                LeafNode leafNode2 = new LeafNode(Token.Type.SEMICN,
                        ";", doPeek(cur-1).getLineNo(), 'i');
                constDecl.addChildNode(leafNode2);
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+"i");
                endFlag = true; //非正常
            }
        }
        constDecl.setEndLine(doPeek(cur-1).getLineNo());
        return constDecl;
    }

    public Node parseFuncDef() {
        //只可能出现j型错误，缺少右小括号
        FuncDef funcDef = new FuncDef();
        funcDef.setStartLine(getCur().getLineNo());
        //FuncType
        funcDef.addChildNode(parseFuncType());
        //Ident
        funcDef.addChildNode(new LeafNode(Token.Type.IDENFR,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //'('
        funcDef.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //[FuncFParams]
        Token.Type temTp = doPeek(cur).getType();
        if (temTp == Token.Type.INTTK || temTp == Token.Type.CHARTK) {
            funcDef.addChildNode(parseFuncFParams());
        }
        //')'
        if (getCur().getType() == Token.Type.RPARENT) {
            funcDef.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        } else { //j
            funcDef.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        }
        //Block
        funcDef.addChildNode(parseBlock());
        funcDef.setEndLine(doPeek(cur-1).getLineNo());
        return funcDef;
    }

    public Node parseVarDecl() {
        //只会出现i型错误
        VarDecl varDecl = new VarDecl();
        varDecl.setStartLine(getCur().getLineNo());
        boolean endFlag = false;
        //BType
        varDecl.addChildNode(new LeafNode(getCur().getType(),
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //VarDef
        varDecl.addChildNode(parseVarDef());
        //{',', VarDef}
        while (!endFlag) {
            Token.Type temTp = doPeek(cur).getType();
            if (temTp == Token.Type.COMMA) {
                varDecl.addChildNode(new LeafNode(Token.Type.COMMA,
                        ",", getCur().getLineNo(), '\0'));
                cur++;
                varDecl.addChildNode(parseVarDef());
            } else if (temTp == Token.Type.SEMICN) {
                varDecl.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", getCur().getLineNo(), '\0'));
                varDecl.setEndLine(getCur().getLineNo());
                cur++;
                endFlag = true; //正常
            } else {
                varDecl.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", doPeek(cur-1).getLineNo(), 'i'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
                endFlag = true; //非正常
            }
        }
        varDecl.setEndLine(doPeek(cur-1).getLineNo());
        return varDecl;
    }

    public Node parseMainFuncDef() {
        //只可能出现j型错误
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.setStartLine(getCur().getLineNo());
        //'int'
        mainFuncDef.addChildNode(new LeafNode(Token.Type.INTTK,
                "int", getCur().getLineNo(), '\0'));
        cur++;
        //'main'
        mainFuncDef.addChildNode(new LeafNode(Token.Type.MAINTK,
                "main", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        mainFuncDef.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //')'
        if (getCur().getType() != Token.Type.RPARENT) {
            mainFuncDef.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        } else {
            mainFuncDef.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        }
        //Block
        mainFuncDef.addChildNode(parseBlock());
        mainFuncDef.setEndLine(doPeek(cur-1).getLineNo());
        return mainFuncDef;
    }

    public Node parseConstDef() {
        //可能出现k型错误：缺少右中括号
        ConstDef constDef = new ConstDef();
        constDef.setStartLine(getCur().getLineNo());
        //Ident
        constDef.addChildNode(new LeafNode(Token.Type.IDENFR,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //['['ConstExp']']
        if (getCur().getType() == Token.Type.LBRACK) {
            constDef.addChildNode(new LeafNode(Token.Type.LBRACK,
                    "[", getCur().getLineNo(), '\0'));
            cur++;
            constDef.addChildNode(parseConstExp());
            if (getCur().getType() != Token.Type.RBRACK) {
                //缺少右中括号
                constDef.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", doPeek(cur-1).getLineNo(),'k'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'k');
            } else {
                constDef.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", getCur().getLineNo(), '\0'));
                cur++;
            }
        }
        //'='
        constDef.addChildNode(new LeafNode(Token.Type.ASSIGN,
                "=", getCur().getLineNo(), '\0'));
        cur++;
        //ConstInitVal
        constDef.addChildNode(parseConstInitVal());
        constDef.setEndLine(doPeek(cur-1).getLineNo());
        return constDef;
    }

    public Node parseFuncType() {
        FuncType funcType = new FuncType();
        funcType.setStartLine(getCur().getLineNo());
        funcType.addChildNode(new LeafNode(getCur().getType(),
                getCur().getValue(), getCur().getLineNo(), '\0'));
        funcType.setEndLine(getCur().getLineNo());
        cur++;
        return funcType;
    }

    public Node parseFuncFParams() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.setStartLine(getCur().getLineNo());
        boolean endFlag = false;
        //FuncFParam
        funcFParams.addChildNode(parseFuncFParam());
        //{',',FuncFParam}
        while (!endFlag) {
            if (getCur().getType() == Token.Type.COMMA) {
                funcFParams.addChildNode(new LeafNode(Token.Type.COMMA,
                        ",", getCur().getLineNo(), '\0'));
                cur++;
                funcFParams.addChildNode(parseFuncFParam());
            } else {
                endFlag = true;
            }
        }
        funcFParams.setEndLine(doPeek(cur-1).getLineNo());
        return funcFParams;
    }

    public Node parseBlock() {
        Block block = new Block();
        block.setStartLine(getCur().getLineNo());
        //'{'
        block.addChildNode(new LeafNode(Token.Type.LBRACE,
                "{", getCur().getLineNo(), '\0'));
        cur++;
        //{ConstDecl | VarDecl | Stmt} '}'
        if (getCur().getType() == Token.Type.RBRACE) {
            block.addChildNode(new LeafNode(Token.Type.RBRACE,
                    "}", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            //{ConstDecl | VarDecl | Stmt}
            boolean endFlag = false;
            while (!endFlag) {
                Token.Type temTp = getCur().getType();
                if (temTp == Token.Type.CONSTTK) {
                    block.addChildNode(parseConstDecl());
                } else if (temTp == Token.Type.INTTK || temTp == Token.Type.CHARTK) {
                    block.addChildNode(parseVarDecl());
                } else if (temTp == Token.Type.IFTK || temTp == Token.Type.FORTK
                || temTp == Token.Type.BREAKTK || temTp == Token.Type.CONTINUETK
                || temTp == Token.Type.RETURNTK || temTp == Token.Type.PRINTFTK
                || temTp == Token.Type.LBRACE || temTp == Token.Type.IDENFR
                || temTp == Token.Type.PLUS || temTp == Token.Type.MINU
                        || temTp == Token.Type.INTCON || temTp == Token.Type.CHRCON
                ||temTp == Token.Type.LPARENT || temTp == Token.Type.SEMICN) {
                    //FIRST(Stmt)
                    block.addChildNode(parseStmt());
                } else {
                    endFlag = true;
                }
            }
            //'}'
            block.addChildNode(new LeafNode(Token.Type.RBRACE,
                    "}", getCur().getLineNo(), '\0'));
            cur++;
        }
        block.setEndLine(doPeek(cur-1).getLineNo());
        return block;
    }

    public Node parseVarDef() {
        //可能出现k型错误
        VarDef varDef = new VarDef();
        varDef.setStartLine(getCur().getLineNo());
        //Ident
        varDef.addChildNode(new LeafNode(Token.Type.IDENFR,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //['['ConstExp']']
        if (getCur().getType() == Token.Type.LBRACK) {
            varDef.addChildNode(new LeafNode(Token.Type.LBRACK,
                    "[", getCur().getLineNo(), '\0'));
            cur++;
            varDef.addChildNode(parseConstExp());
            if (getCur().getType() == Token.Type.RBRACK) {
                varDef.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", getCur().getLineNo(), '\0'));
                cur++;
            } else { //缺少右中括号]
                varDef.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", doPeek(cur-1).getLineNo(), 'k'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'k');
            }
        }
        // ['=' InitVal]
        if (getCur().getType() == Token.Type.ASSIGN) {
            varDef.addChildNode(new LeafNode(Token.Type.ASSIGN,
                    "=", getCur().getLineNo(), '\0'));
            cur++;
            varDef.addChildNode(parseInitVal());
        }
        varDef.setEndLine(doPeek(cur-1).getLineNo());
        return varDef;
    }

    public Node parseConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.setStartLine(getCur().getLineNo());
        //AddExp
        constExp.addChildNode(parseAddExp());
        constExp.setEndLine(doPeek(cur-1).getLineNo());
        return constExp;
    }

    public Node parseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        constInitVal.setStartLine(getCur().getLineNo());
        //判断进入哪个分支
        if (getCur().getType() == Token.Type.LBRACE) {
            // '{'[ConstExp{','ConstExp}]'}'
            constInitVal.addChildNode(new LeafNode(Token.Type.LBRACE,
                    "{", getCur().getLineNo(), '\0'));
            cur++;
            //[ConstExp{','ConstExp}]'}'
            if (getCur().getType() != Token.Type.RBRACE) {
                constInitVal.addChildNode(parseConstExp());
                boolean endFlag = false;
                while (!endFlag) {
                    if (getCur().getType() == Token.Type.COMMA) {
                        constInitVal.addChildNode(new LeafNode(Token.Type.COMMA,
                                ",", getCur().getLineNo(), '\0'));
                        cur++;
                        constInitVal.addChildNode(parseConstExp());
                    } else {
                        endFlag = true;
                    }
                }
            }
            constInitVal.addChildNode(new LeafNode(Token.Type.RBRACE,
                    "}", getCur().getLineNo(), '\0'));
            cur++;
        } else if (getCur().getType() == Token.Type.STRCON) {
            // StringConst
            constInitVal.addChildNode(new LeafNode(Token.Type.STRCON,
                    getCur().getValue(), getCur().getLineNo(), '\0'));
            cur++;
        } else {
            // ConstExp(头符号集与上述两个分支无交集)
            // ConstExp,Exp,AddExp的头符号集相同，为:INTCON,CHRCON,(,IDENFR,+,-,!(!只出现在条件表达式中)
            constInitVal.addChildNode(parseConstExp());
        }
        constInitVal.setEndLine(doPeek(cur-1).getLineNo());
        return constInitVal;
    }

    public Node parseFuncFParam() {
        //可能出现k型错误
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.setStartLine(getCur().getLineNo());
        //BType: int | char
        funcFParam.addChildNode(new LeafNode(getCur().getType(),
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //Ident
        funcFParam.addChildNode(new LeafNode(Token.Type.IDENFR,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        // ['['']']
        if (getCur().getType() == Token.Type.LBRACK) {
            funcFParam.addChildNode(new LeafNode(Token.Type.LBRACK,
                    "[", getCur().getLineNo(), '\0'));
            cur++;
            if (getCur().getType() != Token.Type.RBRACK) {
                funcFParam.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", getCur().getLineNo(), 'k'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'k');
            } else {
                funcFParam.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", getCur().getLineNo(), '\0'));
                cur++;
            }
        }
        funcFParam.setEndLine(doPeek(cur-1).getLineNo());
        return funcFParam;
    }

    public Node parseStmt() {
        //可能出现i、j型错误
        Stmt stmt = new Stmt();
        stmt.setStartLine(getCur().getLineNo());
        //'break'';'和'continue'';'//i 没有额外创建句式
        if (getCur().getType() == Token.Type.BREAKTK) {
            stmt.addChildNode(new LeafNode(Token.Type.BREAKTK,
                    "break", getCur().getLineNo(), '\0'));
            cur++;
            if (getCur().getType() == Token.Type.SEMICN) {
                stmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", getCur().getLineNo(), '\0'));
                cur++;
            } else {
                stmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", doPeek(cur-1).getLineNo(), 'i'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
            }
        } else if (getCur().getType() == Token.Type.CONTINUETK) {
            stmt.addChildNode(new LeafNode(Token.Type.CONTINUETK,
                    "continue", getCur().getLineNo(), '\0'));
            cur++;
            if (getCur().getType() == Token.Type.SEMICN) {
                stmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", getCur().getLineNo(), '\0'));
                cur++;
            } else {
                stmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", doPeek(cur-1).getLineNo(), 'i'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
            }
        } else if (getCur().getType() == Token.Type.LBRACE) {
            //BlockStmt -> Block
            stmt.addChildNode(parseBlockStmt());
        } else if (getCur().getType() == Token.Type.IFTK) {
            //IfStmt -> 'if''('Cond')'Stmt['else'Stmt] //j
            stmt.addChildNode(parseIfStmt());
        } else if (getCur().getType() == Token.Type.FORTK) {
            //RecStmt -> 'for''('[ForStmt]';'[Cond]';'[ForStmt]')'Stmt
            stmt.addChildNode(parseRecStmt());
        } else if (getCur().getType() == Token.Type.RETURNTK) {
            //ReturnStmt -> 'return'[Exp]';' //i
            stmt.addChildNode(parseReturnStmt());
        } else if (getCur().getType() == Token.Type.PRINTFTK) {
            //PrintfStmt -> 'printf''('StringConst{','Exp}')'';' //i,j
            stmt.addChildNode(parsePrintfStmt());
        } else if (getCur().getType() == Token.Type.IDENFR) {
            int rec = cur;
            LVal lVal = (LVal)parseLVal();
            //特殊设计: 解析到Ident '(' [FuncRParams] ')'返回空指针
            if (lVal == null) {
                cur = rec;
                stmt.addChildNode(parseExpStmt());
            } else {
                if (getCur().getType() == Token.Type.ASSIGN) {
                    if (doPeek(cur + 1).getType() == Token.Type.GETINTTK) {
                        cur = rec;
                        stmt.addChildNode(parseGetIntStmt());
                    } else if (doPeek(cur + 1).getType() == Token.Type.GETCHARTK) {
                        cur = rec;
                        stmt.addChildNode(parseGetCharStmt());
                    } else {
                        cur = rec;
                        stmt.addChildNode(parseAssignStmt());
                    }
                } else {
                    cur = rec;
                    stmt.addChildNode(parseExpStmt());
                }
            }
        } else {
            //ExpStmt -> [Exp]';' //i
            stmt.addChildNode(parseExpStmt());
        }
        stmt.setEndLine(doPeek(cur-1).getLineNo());
        return stmt;
    }

    public Node parseAssignStmt() {
        //AssignStmt -> LVal '=' Exp';' //i
        AssignStmt assignStmt = new AssignStmt();
        assignStmt.setStartLine(getCur().getLineNo());
        //LVal
        assignStmt.addChildNode(parseLVal());
        //'='
        assignStmt.addChildNode(new LeafNode(Token.Type.ASSIGN,
                "=", getCur().getLineNo(), '\0'));
        cur++;
        //Exp
        assignStmt.addChildNode(parseExp());
        //';'
        if (getCur().getType() == Token.Type.SEMICN) {
            assignStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            assignStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", doPeek(cur-1).getLineNo(), 'i'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
        }
        assignStmt.setEndLine(doPeek(cur-1).getLineNo());
        return assignStmt;
    }

    public Node parseExpStmt() {
        //ExpStmt -> [Exp]';' //i
        ExpStmt expStmt = new ExpStmt();
        expStmt.setStartLine(getCur().getLineNo());
        //[Exp]';'
        if (getCur().getType() == Token.Type.SEMICN) {
            expStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            expStmt.addChildNode(parseExp());
            if (getCur().getType() == Token.Type.SEMICN) {
                expStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", getCur().getLineNo(), '\0'));
                cur++;
            } else {
                expStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                        ";", doPeek(cur-1).getLineNo(), 'i'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
            }
        }
        expStmt.setEndLine(doPeek(cur-1).getLineNo());
        return expStmt;
    }

    public Node parseBlockStmt() {
        //BlockStmt -> Block
        BlockStmt blockStmt = new BlockStmt();
        blockStmt.setStartLine(getCur().getLineNo());
        //Block
        blockStmt.addChildNode(parseBlock());
        blockStmt.setEndLine(doPeek(cur-1).getLineNo());
        return blockStmt;
    }

    public Node parseIfStmt() {
        //IfStmt -> 'if''('Cond')'Stmt['else'Stmt] //j
        IfStmt ifStmt = new IfStmt();
        ifStmt.setStartLine(getCur().getLineNo());
        //'if'
        ifStmt.addChildNode(new LeafNode(Token.Type.IFTK,
                "if", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        ifStmt.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //Cond
        ifStmt.addChildNode(parseCond());
        //')'
        if (getCur().getType() == Token.Type.RPARENT) {
            ifStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            ifStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        }
        //Stmt
        ifStmt.addChildNode(parseStmt());
        //['else' Stmt]
        if (getCur().getType() == Token.Type.ELSETK) {
            ifStmt.addChildNode(new LeafNode(Token.Type.ELSETK,
                    "else", getCur().getLineNo(), '\0'));
            cur++;
            ifStmt.addChildNode(parseStmt());
        }
        ifStmt.setEndLine(doPeek(cur-1).getLineNo());
        return ifStmt;
    }

    public Node parseRecStmt() {
        //RecStmt -> 'for''('[ForStmt]';'[Cond]';'[ForStmt]')'Stmt
        RecStmt recStmt = new RecStmt();
        recStmt.setStartLine(getCur().getLineNo());
        //'for'
        recStmt.addChildNode(new LeafNode(Token.Type.FORTK,
                "for", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        recStmt.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //[ForStmt]';'
        if (getCur().getType() == Token.Type.SEMICN) {
            recStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            recStmt.addChildNode(parseForStmt());
            recStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        }
        //[Cond]';'
        if (getCur().getType() == Token.Type.SEMICN) {
            recStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            recStmt.addChildNode(parseCond());
            recStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        }
        //[ForStmt]')'
        if (getCur().getType() == Token.Type.RPARENT) {
            recStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            recStmt.addChildNode(parseForStmt());
            recStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        }
        //Stmt
        recStmt.addChildNode(parseStmt());
        recStmt.setEndLine(doPeek(cur-1).getLineNo());
        return recStmt;
    }

    public Node parseReturnStmt() {
        //ReturnStmt -> 'return'[Exp]';' //i
        ReturnStmt returnStmt = new ReturnStmt();
        returnStmt.setStartLine(getCur().getLineNo());
        //'return'
        returnStmt.addChildNode(new LeafNode(Token.Type.RETURNTK,
                "return", getCur().getLineNo(), '\0'));
        cur++;
        //[Exp]';' //i
        Token.Type temTp = getCur().getType();
        if (temTp == Token.Type.CHRCON || temTp == Token.Type.INTCON ||
        temTp == Token.Type.LPARENT || temTp == Token.Type.IDENFR ||
        temTp == Token.Type.PLUS || temTp == Token.Type.MINU ||
        temTp == Token.Type.NOT) { //FIRST(Exp)
            returnStmt.addChildNode(parseExp());
        }
        //';' //i
        if (getCur().getType() == Token.Type.SEMICN) {
            returnStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        } else {
            returnStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", doPeek(cur-1).getLineNo(), 'i'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
        }
        returnStmt.setEndLine(doPeek(cur-1).getLineNo());
        return returnStmt;
    }

    public Node parseGetIntStmt() {
        //GetIntStmt -> LVal '=' 'getint''('')'';' //i,j
        GetIntStmt getIntStmt = new GetIntStmt();
        getIntStmt.setStartLine(getCur().getLineNo());
        //LVal
        getIntStmt.addChildNode(parseLVal());
        //'='
        getIntStmt.addChildNode(new LeafNode(Token.Type.ASSIGN,
                "=", getCur().getLineNo(), '\0'));
        cur++;
        //'getint'
        getIntStmt.addChildNode(new LeafNode(Token.Type.GETINTTK,
                "getint", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        getIntStmt.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //')'
        if (getCur().getType() != Token.Type.RPARENT) {
            getIntStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        } else {
            getIntStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        }
        //';'
        if (getCur().getType() != Token.Type.SEMICN) {
            getIntStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", doPeek(cur-1).getLineNo(), 'i'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
        } else {
            getIntStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        }
        getIntStmt.setEndLine(doPeek(cur-1).getLineNo());
        return getIntStmt;
    }

    public Node parseGetCharStmt() {
        //GetCharStmt -> LVal '=' 'getchar''('')'';' //i,j
        GetCharStmt getCharStmt = new GetCharStmt();
        getCharStmt.setStartLine(getCur().getLineNo());
        //LVal
        getCharStmt.addChildNode(parseLVal());
        //'='
        getCharStmt.addChildNode(new LeafNode(Token.Type.ASSIGN,
                "=", getCur().getLineNo(), '\0'));
        cur++;
        //'getchar'
        getCharStmt.addChildNode(new LeafNode(Token.Type.GETCHARTK,
                "getchar", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        getCharStmt.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //')'
        if (getCur().getType() != Token.Type.RPARENT) {
            getCharStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        } else {
            getCharStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        }
        //';'
        if (getCur().getType() != Token.Type.SEMICN) {
            getCharStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", doPeek(cur-1).getLineNo(), 'i'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
        } else {
            getCharStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        }
        getCharStmt.setEndLine(doPeek(cur-1).getLineNo());
        return getCharStmt;
    }

    public Node parsePrintfStmt() {
        //PrintfStmt -> 'printf''('StringConst{','Exp}')'';' //i,j
        PrintfStmt printfStmt = new PrintfStmt();
        printfStmt.setStartLine(getCur().getLineNo());
        //'printf'
        printfStmt.addChildNode(new LeafNode(Token.Type.PRINTFTK,
                "printf", getCur().getLineNo(), '\0'));
        cur++;
        //'('
        printfStmt.addChildNode(new LeafNode(Token.Type.LPARENT,
                "(", getCur().getLineNo(), '\0'));
        cur++;
        //StringConst
        printfStmt.addChildNode(new LeafNode(Token.Type.STRCON,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //{','Exp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.COMMA) {
                printfStmt.addChildNode(new LeafNode(Token.Type.COMMA,
                        ",", getCur().getLineNo(), '\0'));
                cur++;
                printfStmt.addChildNode(parseExp());
            } else {
                endFlag = true;
            }
        }
        //')'
        if (getCur().getType() != Token.Type.RPARENT) {
            printfStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", doPeek(cur-1).getLineNo(), 'j'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
        } else {
            printfStmt.addChildNode(new LeafNode(Token.Type.RPARENT,
                    ")", getCur().getLineNo(), '\0'));
            cur++;
        }
        //';'
        if (getCur().getType() != Token.Type.SEMICN) {
            printfStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", doPeek(cur-1).getLineNo(), 'i'));
            hasError = true;
            errorList.add(doPeek(cur-1).getLineNo()+" "+'i');
        } else {
            printfStmt.addChildNode(new LeafNode(Token.Type.SEMICN,
                    ";", getCur().getLineNo(), '\0'));
            cur++;
        }
        printfStmt.setEndLine(doPeek(cur-1).getLineNo());
        return printfStmt;
    }

    public Node parseInitVal() {
        InitVal initVal = new InitVal();
        initVal.setStartLine(getCur().getLineNo());
        //判断进入哪个分支
        if (getCur().getType() == Token.Type.LBRACE) {
            //'{'[Exp{','Exp}]'}'
            initVal.addChildNode(new LeafNode(Token.Type.LBRACE,
                    "{", getCur().getLineNo(), '\0'));
            cur++;
            if (getCur().getType() == Token.Type.RBRACE) {
                initVal.addChildNode(new LeafNode(Token.Type.RBRACE,
                        "}", getCur().getLineNo(), '\0'));
                cur++;
            } else { //Exp{','Exp}
                initVal.addChildNode(parseExp());
                boolean endFlag = false;
                while (!endFlag) {
                    if (getCur().getType() == Token.Type.COMMA) {
                        initVal.addChildNode(new LeafNode(Token.Type.COMMA,
                                ",", getCur().getLineNo(), '\0'));
                        cur++;
                        initVal.addChildNode(parseExp());
                    } else {
                        endFlag = true;
                    }
                }
                initVal.addChildNode(new LeafNode(Token.Type.RBRACE,
                        "}", getCur().getLineNo(), '\0'));
                cur++;
            }
        } else if (getCur().getType() == Token.Type.STRCON) {
            initVal.addChildNode(new LeafNode(Token.Type.STRCON,
                    getCur().getValue(), getCur().getLineNo(), '\0'));
            cur++;
        } else {
            initVal.addChildNode(parseExp());
        }
        initVal.setEndLine(doPeek(cur-1).getLineNo());
        return initVal;
    }

    public Node parseAddExp() {
        //消除了左递归，需要额外处理，使生成的语法树不变
        //MulExp
        Node temNode = new Node();
        temNode.addChildNode(parseMulExp());
        //{('+'|'-')MulExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.PLUS || getCur().getType() == Token.Type.MINU) {
                temNode.addChildNode(new LeafNode(getCur().getType(),
                        getCur().getValue(), getCur().getLineNo(), '\0'));
                cur++;
                temNode.addChildNode(parseMulExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        AddExp temAddExp = new AddExp();
        temAddExp.setStartLine(startLine);
        temAddExp.setEndLine(children.get(k).getEndLine());
        temAddExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            AddExp temAddExp2 = new AddExp();
            temAddExp2.setStartLine(startLine);
            temAddExp2.addChildNode(temAddExp);
            temAddExp2.addChildNode(children.get(k++));
            temAddExp2.setEndLine(children.get(k).getEndLine());
            temAddExp2.addChildNode(children.get(k++));
            temAddExp = temAddExp2;
        }
        temAddExp.setEndLine(doPeek(cur-1).getLineNo());
        return temAddExp;
    }

    public Node parseLVal() {
        //可能出现k型错误
        LVal lVal = new LVal();
        lVal.setStartLine(getCur().getLineNo());
        //Ident
        lVal.addChildNode(new LeafNode(Token.Type.IDENFR,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        //特殊：解析到Ident '(' [FuncRParams] ')'返回空指针，用于stmt解析时区分不同分支
        if (getCur().getType() == Token.Type.LPARENT) {
            return null;
        }
        //['['Exp']']
        if (getCur().getType() == Token.Type.LBRACK) {
            lVal.addChildNode(new LeafNode(Token.Type.LBRACK,
                    "[", getCur().getLineNo(), '\0'));
            cur++;
            lVal.addChildNode(parseExp());
            if (getCur().getType() != Token.Type.RBRACK) {
                lVal.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", doPeek(cur-1).getLineNo(), 'k'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'k');
            } else {
                lVal.addChildNode(new LeafNode(Token.Type.RBRACK,
                        "]", getCur().getLineNo(), '\0'));
                cur++;
            }
        }
        lVal.setEndLine(doPeek(cur-1).getLineNo());
        return lVal;
    }

    public Node parseCond() {
        Cond cond = new Cond();
        cond.setStartLine(getCur().getLineNo());
        //LOrExp
        cond.addChildNode(parseLOrExp());
        cond.setEndLine(doPeek(cur-1).getLineNo());
        return cond;
    }

    public Node parseForStmt() {
        ForStmt forStmt = new ForStmt();
        forStmt.setStartLine(getCur().getLineNo());
        //LVal
        forStmt.addChildNode(parseLVal());
        //'='
        forStmt.addChildNode(new LeafNode(Token.Type.ASSIGN,
                "=", getCur().getLineNo(), '\0'));
        cur++;
        //Exp
        forStmt.addChildNode(parseExp());
        forStmt.setEndLine(doPeek(cur-1).getLineNo());
        return forStmt;
    }

    public Node parseExp() {
        Exp exp = new Exp();
        exp.setStartLine(getCur().getLineNo());
        //AddExp
        exp.addChildNode(parseAddExp());
        exp.setEndLine(doPeek(cur-1).getLineNo());
        return exp;
    }

    public Node parseMulExp() {
        //UnaryExp
        Node temNode = new Node();
        temNode.addChildNode(parseUnaryExp());
        //{('*'|'/'|'%')UnaryExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.MULT
                    || getCur().getType() == Token.Type.DIV
                    || getCur().getType() == Token.Type.MOD) {
                temNode.addChildNode(new LeafNode(getCur().getType(),
                        getCur().getValue(), getCur().getLineNo(), '\0'));
                cur++;
                temNode.addChildNode(parseUnaryExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        MulExp temMulExp = new MulExp();
        temMulExp.setStartLine(startLine);
        temMulExp.setEndLine(children.get(k).getEndLine());
        temMulExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            MulExp temMulExp2 = new MulExp();
            temMulExp2.setStartLine(startLine);
            temMulExp2.addChildNode(temMulExp);
            temMulExp2.addChildNode(children.get(k++));
            temMulExp2.setEndLine(children.get(k).getEndLine());
            temMulExp2.addChildNode(children.get(k++));
            temMulExp = temMulExp2;
        }
        temMulExp.setEndLine(doPeek(cur-1).getLineNo());
        return temMulExp;
    }

    public Node parseLOrExp() {
        //可能出现a型错误
        //LAndExp
        Node temNode = new Node();
        temNode.addChildNode(parseLAndExp());
        //{('||')LAndExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.OR) {
                if (getCur().getValue().equals("|")) {
                    temNode.addChildNode(new LeafNode(getCur().getType(),
                            getCur().getValue(), getCur().getLineNo(), 'a'));
                    hasError = true;
                    errorList.add(doPeek(cur).getLineNo()+" "+'a');
                } else {
                    temNode.addChildNode(new LeafNode(getCur().getType(),
                            getCur().getValue(), getCur().getLineNo(), '\0'));
                }
                cur++;
                temNode.addChildNode(parseLAndExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        LOrExp temLOrExp = new LOrExp();
        temLOrExp.setStartLine(startLine);
        temLOrExp.setEndLine(children.get(k).getEndLine());
        temLOrExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            LOrExp temLOrExp2 = new LOrExp();
            temLOrExp2.setStartLine(startLine);
            temLOrExp2.addChildNode(temLOrExp);
            temLOrExp2.addChildNode(children.get(k++));
            temLOrExp2.setEndLine(children.get(k).getEndLine());
            temLOrExp2.addChildNode(children.get(k++));
            temLOrExp = temLOrExp2;
        }
        temLOrExp.setEndLine(doPeek(cur-1).getLineNo());
        return temLOrExp;
    }

    public Node parseUnaryExp() {
        //可能出现j型错误:缺少右小括号
        UnaryExp unaryExp = new UnaryExp();
        unaryExp.setStartLine(getCur().getLineNo());
        //
        Token.Type temTp = getCur().getType();
        if (temTp == Token.Type.PLUS
            || temTp == Token.Type.MINU
            || temTp == Token.Type.NOT) {
            //FIRST(UnaryOp)
            unaryExp.addChildNode(parseUnaryOp());
            unaryExp.addChildNode(parseUnaryExp());
        } else if (temTp == Token.Type.LPARENT
            || temTp == Token.Type.INTCON
            || temTp == Token.Type.CHRCON) {
            //FIRST(PrimaryExp) - Ident
            unaryExp.addChildNode(parsePrimaryExp());
        } else if (temTp == Token.Type.IDENFR) {
            //peek = cur + 1;
            if (doPeek(cur+1).getType() == Token.Type.LPARENT) {
                unaryExp.addChildNode(new LeafNode(Token.Type.IDENFR,
                        getCur().getValue(), getCur().getLineNo(), '\0'));
                cur++;
                unaryExp.addChildNode(new LeafNode(Token.Type.LPARENT,
                        "(", getCur().getLineNo(), '\0'));
                cur++;
                //[FuncRParams]')'
                Token.Type temType = getCur().getType();
                if (temType == Token.Type.CHRCON || temType == Token.Type.INTCON
                || temType == Token.Type.LPARENT || temType == Token.Type.IDENFR
                || temType == Token.Type.PLUS || temType == Token.Type.MINU
                || temType == Token.Type.NOT) {
                    //F(FuncRParams) = F(Exp)
                    unaryExp.addChildNode(parseFuncRParams());
                }
                if (getCur().getType() != Token.Type.RPARENT) {
                    unaryExp.addChildNode(new LeafNode(Token.Type.RPARENT,
                            ")", doPeek(cur-1).getLineNo(), 'j'));
                    hasError = true;
                    errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
                } else {
                    unaryExp.addChildNode(new LeafNode(Token.Type.RPARENT,
                            ")", doPeek(cur-1).getLineNo(), '\0'));
                    cur++;
                }
            } else {
                unaryExp.addChildNode(parsePrimaryExp());
            }
        }
        unaryExp.setEndLine(doPeek(cur-1).getLineNo());
        return unaryExp;
    }

    public Node parseLAndExp() {
        //可能出现a型错误
        //EqExp
        Node temNode = new Node();
        temNode.addChildNode(parseEqExp());
        //{('&&')EqExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.AND) {
                if (getCur().getValue().equals("&")) {
                    temNode.addChildNode(new LeafNode(getCur().getType(),
                            getCur().getValue(), getCur().getLineNo(), 'a'));
                    hasError = true;
                    errorList.add(doPeek(cur).getLineNo()+" "+'a');
                } else {
                    temNode.addChildNode(new LeafNode(getCur().getType(),
                            getCur().getValue(), getCur().getLineNo(), '\0'));
                }
                cur++;
                temNode.addChildNode(parseEqExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        LAndExp temLAndExp = new LAndExp();
        temLAndExp.setStartLine(startLine);
        temLAndExp.setEndLine(children.get(k).getEndLine());
        temLAndExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            LAndExp temLAndExp2 = new LAndExp();
            temLAndExp2.setStartLine(startLine);
            temLAndExp2.addChildNode(temLAndExp);
            temLAndExp2.addChildNode(children.get(k++));
            temLAndExp2.setEndLine(children.get(k).getEndLine());
            temLAndExp2.addChildNode(children.get(k++));
            temLAndExp = temLAndExp2;
        }
        temLAndExp.setEndLine(doPeek(cur-1).getLineNo());
        return temLAndExp;
    }

    public Node parseUnaryOp() {
        UnaryOp unaryOp = new UnaryOp();
        unaryOp.setStartLine(getCur().getLineNo());
        //'+'|'-'|'!'
        unaryOp.addChildNode(new LeafNode(getCur().getType(),
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        unaryOp.setEndLine(doPeek(cur-1).getLineNo());
        return unaryOp;
    }

    public Node parsePrimaryExp() {
        //可能出现j型错误
        PrimaryExp primaryExp = new PrimaryExp();
        primaryExp.setStartLine(getCur().getLineNo());
        if (getCur().getType() == Token.Type.LPARENT) {
            primaryExp.addChildNode(new LeafNode(Token.Type.LPARENT,
                    "(", getCur().getLineNo(), '\0'));
            cur++;
            primaryExp.addChildNode(parseExp());
            if (getCur().getType() != Token.Type.RPARENT) {
                primaryExp.addChildNode(new LeafNode(Token.Type.RPARENT,
                        ")", doPeek(cur-1).getLineNo(), 'j'));
                hasError = true;
                errorList.add(doPeek(cur-1).getLineNo()+" "+'j');
            } else {
                primaryExp.addChildNode(new LeafNode(Token.Type.RPARENT,
                        ")", getCur().getLineNo(), '\0'));
                cur++;
            }
        } else if (getCur().getType() == Token.Type.IDENFR) {
            primaryExp.addChildNode(parseLVal());
        } else if (getCur().getType() == Token.Type.INTCON) {
            primaryExp.addChildNode(parseNumber());
        } else if (getCur().getType() == Token.Type.CHRCON) {
            primaryExp.addChildNode(parseCharacter());
        }
        primaryExp.setEndLine(doPeek(cur-1).getLineNo());
        return primaryExp;
    }

    public Node parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.setStartLine(getCur().getLineNo());
        //Exp
        funcRParams.addChildNode(parseExp());
        //{','Exp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.COMMA) {
                funcRParams.addChildNode(new LeafNode(Token.Type.COMMA,
                        ",", getCur().getLineNo(), '\0'));
                cur++;
                funcRParams.addChildNode(parseExp());
            } else {
                endFlag = true;
            }
        }
        funcRParams.setEndLine(doPeek(cur-1).getLineNo());
        return funcRParams;
    }

    public Node parseEqExp() {
        //RelExp
        Node temNode = new Node();
        temNode.addChildNode(parseRelExp());
        //{('=='|'!=')RelExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.EQL
                    || getCur().getType() == Token.Type.NEQ) {
                temNode.addChildNode(new LeafNode(getCur().getType(),
                        getCur().getValue(), getCur().getLineNo(), '\0'));
                cur++;
                temNode.addChildNode(parseRelExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        EqExp temEqExp = new EqExp();
        temEqExp.setStartLine(startLine);
        temEqExp.setEndLine(children.get(k).getEndLine());
        temEqExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            EqExp temEqExp2 = new EqExp();
            temEqExp2.setStartLine(startLine);
            temEqExp2.addChildNode(temEqExp);
            temEqExp2.addChildNode(children.get(k++));
            temEqExp2.setEndLine(children.get(k).getEndLine());
            temEqExp2.addChildNode(children.get(k++));
            temEqExp = temEqExp2;
        }
        temEqExp.setEndLine(doPeek(cur-1).getLineNo());
        return temEqExp;
    }

    public Node parseNumber() {
        MyNumber number = new MyNumber();
        number.setStartLine(getCur().getLineNo());
        //IntConst
        number.addChildNode(new LeafNode(Token.Type.INTCON,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        number.setEndLine(doPeek(cur-1).getLineNo());
        return number;
    }

    public Node parseCharacter() {
        MyCharacter character = new MyCharacter();
        character.setStartLine(getCur().getLineNo());
        //CharConst
        character.addChildNode(new LeafNode(Token.Type.CHRCON,
                getCur().getValue(), getCur().getLineNo(), '\0'));
        cur++;
        character.setEndLine(doPeek(cur-1).getLineNo());
        return character;
    }

    public Node parseRelExp() {
        //AddExp
        Node temNode = new Node();
        temNode.addChildNode(parseAddExp());
        //{('<'|'>'|'<='|'>=')AddExp}
        boolean endFlag = false;
        while (!endFlag) {
            if (getCur().getType() == Token.Type.LSS
                    || getCur().getType() == Token.Type.LEQ
                    || getCur().getType() == Token.Type.GRE
                    || getCur().getType() == Token.Type.GEQ) {
                temNode.addChildNode(new LeafNode(getCur().getType(),
                        getCur().getValue(), getCur().getLineNo(), '\0'));
                cur++;
                temNode.addChildNode(parseAddExp());
            } else {
                endFlag = true;
            }
        }
        //处理temNode
        ArrayList<Node> children = temNode.getChildren();
        int startLine = children.get(0).getStartLine();
        int k = 0;
        RelExp temRelExp = new RelExp();
        temRelExp.setStartLine(startLine);
        temRelExp.setEndLine(children.get(k).getEndLine());
        temRelExp.addChildNode(children.get(k++));
        while (k < children.size()) {
            RelExp temRelExp2 = new RelExp();
            temRelExp2.setStartLine(startLine);
            temRelExp2.addChildNode(temRelExp);
            temRelExp2.addChildNode(children.get(k++));
            temRelExp2.setEndLine(children.get(k).getEndLine());
            temRelExp2.addChildNode(children.get(k++));
            temRelExp = temRelExp2;
        }
        temRelExp.setEndLine(doPeek(cur-1).getLineNo());
        return temRelExp;
    }
}
