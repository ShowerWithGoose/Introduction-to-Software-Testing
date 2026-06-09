package frontend.parser;

import frontend.error.Error;
import frontend.error.ErrorProcess;
import frontend.lexer.LexType;
import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.node.*;
import frontend.parser.node.Character;
import frontend.parser.node.Number;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Parser {
    private CompUnit parent;
    public int cnt = 0;
    public int tokenCnt;
    public HashMap<Integer, Token> lexerHashMap;
    public ErrorProcess errorProcess;
    public Token cur_token;
    private Lexer lexer;
    public Parser(Lexer lexer, ErrorProcess errorProcess) {
        this.tokenCnt = lexer.getCnt();
        this.lexerHashMap = lexer.getHashMap();
        this.errorProcess = errorProcess;
        this.lexer = lexer;
    }

    public CompUnit getParent() {
        return parent;
    }

    public void outputResult() {
        BufferedWriter bufferedWriter = null;
        boolean isError = this.errorProcess.isError();
        try {
            if (!isError) {
                bufferedWriter = new BufferedWriter(new FileWriter("parser.txt"));
                postOrderTraversal(parent, bufferedWriter);
            } else {
                bufferedWriter = new BufferedWriter(new FileWriter("error.txt"));
                List<Map.Entry<Integer, Error>> list = new ArrayList<>(this.errorProcess.getErrorHashMap().entrySet());
                Collections.sort(list, new Comparator<Map.Entry<Integer, Error>>() {
                    public int compare(Map.Entry<Integer, Error> o1,
                                       Map.Entry<Integer, Error> o2) {
                        return (o1.getValue().getLineNum()-o2.getValue().getLineNum());
                    }
                });
                for (Map.Entry<Integer, Error> entry : list) {
                    bufferedWriter.write(entry.getValue().getLineNum() + " " + entry.getValue().getErrorType());
                    bufferedWriter.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (bufferedWriter != null) {
                try {
                    bufferedWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void buildTree() {
        parent = processCompUnit(this.cnt);
    }
    public CompUnit processCompUnit(int head) {
        CompUnit compUnit = null;
        if (this.cnt < this.tokenCnt) {
            cur_token = this.lexerHashMap.get(this.cnt);
            while (cur_token.getLexType().equals(LexType.CONSTTK) || cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
                Decl decl = processDecl(this.cnt);
                if (decl == null) {
                    this.cnt = head;
                    cur_token = this.lexerHashMap.get(this.cnt);
                    break;
                } else {
                    head = this.cnt;
                    if (compUnit == null) {
                        compUnit = new CompUnit(ParserType.CompUnit, null);
                    }
                    compUnit.setDeclArrayList(decl);
                    compUnit.setChildren(decl);
                }
            }
            while (cur_token.getLexType().equals(LexType.VOIDTK) || cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
                FuncDef funcDef = processFuncDef(this.cnt);
                if (funcDef == null) {
                    this.cnt = head;
                    cur_token = this.lexerHashMap.get(this.cnt);
                    break;
                } else {
                    if (compUnit == null) {
                        compUnit = new CompUnit(ParserType.CompUnit, null);
                    }
                    head = this.cnt;
                    compUnit.setFuncDefArrayList(funcDef);
                    compUnit.setChildren(funcDef);
                }
            }
            if (cur_token.getLexType().equals(LexType.INTTK)) {
                MainFuncDef mainFuncDef = processMainFuncDef(this.cnt);
                if (compUnit == null) {
                    compUnit = new CompUnit(ParserType.CompUnit, null);
                }
                compUnit.setMainFuncDefArrayList(mainFuncDef);
                compUnit.setChildren(mainFuncDef);
            }
        }
        return compUnit;
    }

    public Decl processDecl(int head) {
        Decl decl = null;
        if (cur_token.getLexType().equals(LexType.CONSTTK)) {
            ConstDecl constDecl = processConstDecl(this.cnt);
            if (constDecl == null) {
                this.cnt = head;
                cur_token = this.lexerHashMap.get(this.cnt);
                return null;
            } else {
                decl = new Decl(ParserType.Decl, null);
                decl.setConstDecl(constDecl);
                decl.setChildren(constDecl);
            }
        } else if ((cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) && !this.lexerHashMap.get(this.cnt + 2).getLexType().equals(LexType.LPARENT)) {
            VarDecl varDecl = processVarDecl(this.cnt);
            if (varDecl == null) {
                this.cnt = head;
                cur_token = this.lexerHashMap.get(this.cnt);
                return null;
            } else {
                if (decl == null) {
                    decl = new Decl(ParserType.Decl, null);
                }
                decl.setVarDecl(varDecl);
                decl.setChildren(varDecl);
            }
        }
        return decl;
    }

    public FuncDef processFuncDef(int head) {
        FuncDef funcDef = null;
        FuncType funcType = processFuncType(this.cnt);
        if (funcType == null) {
            this.cnt = head;
            cur_token = this.lexerHashMap.get(this.cnt);
            return funcDef;
        } else {
            funcDef = new FuncDef(ParserType.FuncDef, null);
            funcDef.setFuncType(funcType);
            funcDef.setChildren(funcType);
            if (cur_token.getLexType().equals(LexType.IDENFR)) {
                TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                funcDef.setIdentToken(cur_token);
                funcDef.setChildren(treeNode);
                if (this.cnt + 1 < this.tokenCnt) {
                    cur_token = this.lexerHashMap.get(++this.cnt);
                } else {
                    cur_token = null;
                }
                if (cur_token.getLexType().equals(LexType.LPARENT)) {
                    TreeNode treeNode1 = new TreeNode(ParserType.TOKEN, cur_token);
                    funcDef.setlToken(cur_token);
                    funcDef.setChildren(treeNode1);
                    if (this.cnt + 1 < this.tokenCnt) {
                        cur_token = this.lexerHashMap.get(++this.cnt);
                    } else {
                        cur_token = null;
                    }
                    if (cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
                        FuncFParams funcFParams = processFuncFParams(this.cnt);
                        funcDef.setFuncFParams(funcFParams);
                        funcDef.setChildren(funcFParams);
                    }
                    if (cur_token.getLexType().equals(LexType.RPARENT)) {
                        TreeNode treeNode2 = new TreeNode(ParserType.TOKEN, cur_token);
                        funcDef.setrToken(cur_token);
                        funcDef.setChildren(treeNode2);
                        if (this.cnt + 1 < this.tokenCnt) {
                            cur_token = this.lexerHashMap.get(++this.cnt);
                        } else {
                            cur_token = null;
                        }
                    } else {
                        Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                        errorProcess.setError(error);
                    }
                    if (cur_token.getLexType().equals(LexType.LBRACE)) {
                        Block block = processBlock(this.cnt);
                        funcDef.setBlock(block);
                        funcDef.setChildren(block);
                    }
                } else {
                    this.cnt = head;
                    cur_token = this.lexerHashMap.get(this.cnt);
                    funcDef.getChildren().remove(treeNode);
                    funcDef.getChildren().remove(funcType);
                    funcDef = null;
                    return funcDef;
                }
            } else {
                this.cnt = head;
                cur_token = this.lexerHashMap.get(this.cnt);
                funcDef.getChildren().remove(funcType);
                funcDef = null;
                return funcDef;
            }
        }
        return funcDef;
    }

    public MainFuncDef processMainFuncDef(int head) {
        MainFuncDef mainFuncDef = null;
        Token token1, token2;
        if (this.cnt + 2 < this.tokenCnt) {
            token1 = this.lexerHashMap.get(++this.cnt);
            token2 = this.lexerHashMap.get(++this.cnt);
        } else {
            token1 = null;
            token2 = null;
        }
        if (cur_token.getLexType().equals(LexType.INTTK) && token1.getLexType().equals(LexType.MAINTK) && token2.getLexType().equals(LexType.LPARENT)) {
            mainFuncDef = new MainFuncDef(ParserType.MainFuncDef, null);
            TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            mainFuncDef.setIntToken(cur_token);
            mainFuncDef.setChildren(treeNode);
            treeNode = new TreeNode(ParserType.TOKEN, token1);
            mainFuncDef.setMainToken(token1);
            mainFuncDef.setChildren(treeNode);
            treeNode = new TreeNode(ParserType.TOKEN, token2);
            mainFuncDef.setlToken(token2);
            mainFuncDef.setChildren(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                return null;
            }
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                mainFuncDef.setrToken(cur_token);
                mainFuncDef.setChildren(treeNode);
                if (this.cnt + 1 < this.tokenCnt) {
                    cur_token = this.lexerHashMap.get(++this.cnt);
                } else {
                    cur_token =  null;
                }
            } else {
                Error error = new Error(token2.getLineNum(), 'j');
                errorProcess.setError(error);
            }
            if (cur_token.getLexType().equals(LexType.LBRACE)) {
                Block block = processBlock(this.cnt);
                mainFuncDef.setBlock(block);
                mainFuncDef.setChildren(block);
            }
        }
        return mainFuncDef;
    }

    public Block processBlock(int head) {
        Block block = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.LBRACE)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            block = new Block(ParserType.Block, null);
            block.setLtoken(cur_token);
            block.setChildren(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
        }
        while (!cur_token.getLexType().equals(LexType.RBRACE)) {
            BlockItem blockItem = processBlockItem(this.cnt);
            block.setBlockItemArrayList(blockItem);
            block.setChildren(blockItem);
        }
        if (cur_token.getLexType().equals(LexType.RBRACE)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            block.setRtoken(cur_token);
            this.addNode(treeNode, block);
        }
        return block;
    }

    public ConstDecl processConstDecl(int head) {
        ConstDecl constDecl = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.CONSTTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            constDecl = new ConstDecl(ParserType.ConstDecl, null);
            constDecl.setConstToken(cur_token);
            constDecl.setChildren(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            Btype btype = processBType(this.cnt);
            constDecl.setBtype(btype);
            constDecl.setChildren(btype);
            ConstDef constDef = processConstDef(this.cnt);
            constDecl.setConstDefNodeArrayList(constDef);
            constDecl.setChildren(constDef);
            while (cur_token.getLexType().equals(LexType.COMMA)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                constDecl.setCommaArraylist(cur_token);
                this.addNode(treeNode, constDecl);
                constDef = processConstDef(this.cnt);
                constDecl.setConstDefNodeArrayList(constDef);
                constDecl.setChildren(constDef);
            }
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                constDecl.setSemicnToken(cur_token);
                this.addNode(treeNode, constDecl);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        }
        return constDecl;
    }

    public VarDecl processVarDecl(int head) {
        VarDecl varDecl = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
            Btype btype = processBType(this.cnt);
            varDecl = new VarDecl(ParserType.VarDecl, null);
            varDecl.setBtype(btype);
            varDecl.setChildren(btype);
            VarDef varDef = processVarDef(this.cnt);
            if (varDef == null) {
                this.cnt = head;
                cur_token = this.lexerHashMap.get(this.cnt);
                return null;
            }
            varDecl.setVarDefs(varDef);
            varDecl.setChildren(varDef);
            while (cur_token.getLexType().equals(LexType.COMMA)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                varDecl.setCommas(cur_token);
                this.addNode(treeNode, varDecl);
                varDef = processVarDef(this.cnt);
                varDecl.setVarDefs(varDef);
                varDecl.setChildren(varDef);
            }
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                varDecl.setSemicnToken(cur_token);
                this.addNode(treeNode, varDecl);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        }
        return varDecl;
    }

    public VarDef processVarDef(int head) {
        VarDef varDef = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.IDENFR)) {
            varDef = new VarDef(ParserType.VarDef, null);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            varDef.setIdentToken(cur_token);
            this.addNode(treeNode, varDef);
            if (cur_token.getLexType().equals(LexType.LBRACK)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                varDef.setlToken(cur_token);
                this.addNode(treeNode, varDef);
                ConstExp constExp = processConstExp(this.cnt);
                varDef.setConstExp(constExp);
                varDef.setChildren(constExp);
                if (cur_token.getLexType().equals(LexType.RBRACK)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    varDef.setrToken(cur_token);
                    this.addNode(treeNode, varDef);
                } else {
                    Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'k');
                    errorProcess.setError(error);
                }
            }
            if (cur_token.getLexType().equals(LexType.ASSIGN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                varDef.setAssignToken(cur_token);
                this.addNode(treeNode, varDef);
                InitVal initVal = processInitVal(this.cnt);
                varDef.setInitVal(initVal);
                varDef.setChildren(initVal);
            }
        }
        return varDef;
    }
    public InitVal processInitVal(int head) {
        InitVal initVal = new InitVal(ParserType.InitVal, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.STRCON)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            initVal.setStrToken(cur_token);
            this.addNode(treeNode, initVal);
        } else if (cur_token.getLexType().equals(LexType.LBRACE)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            initVal.setlToken(cur_token);
            this.addNode(treeNode, initVal);
            if (cur_token.getLexType().equals(LexType.RBRACE)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                initVal.setrToken(cur_token);
                this.addNode(treeNode, initVal);
            } else {
                Exp exp = processExp(this.cnt);
                initVal.setExpArrayList(exp);
                initVal.setChildren(exp);
                while(cur_token.getLexType().equals(LexType.COMMA)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    initVal.setCommaArrayList(cur_token);
                    this.addNode(treeNode, initVal);
                    exp = processExp(this.cnt);
                    initVal.setExpArrayList(exp);
                    initVal.setChildren(exp);
                }
                if (cur_token.getLexType().equals(LexType.RBRACE)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    initVal.setrToken(cur_token);
                    this.addNode(treeNode, initVal);
                }
            }
        } else {
            Exp exp = processExp(this.cnt);
            initVal.setExpArrayList(exp);
            initVal.setChildren(exp);
        }
        return initVal;
    }
    public Exp processExp(int head) {
        Exp exp = new Exp(ParserType.Exp, null);
        AddExp addExp = processAddExp(this.cnt);
        exp.setAddExp(addExp);
        exp.setChildren(addExp);
        return exp;
    }
    public AddExp processAddExp(int head) {
        AddExp addExp = null;
        MulExp mulExp = processMulExp(this.cnt);
        ArrayList<MulExp> arrayList = new ArrayList<>();
        arrayList.add(mulExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.MINU) || cur_token.getLexType().equals(LexType.PLUS)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            mulExp = processMulExp(this.cnt);
            arrayList.add(mulExp);
        }
        ArrayList<AddExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            addExp = new AddExp(ParserType.AddExp, null);
            if (i > 0) {
                addExp.setAddExp(arrayList1.get(i - 1));
                addExp.setChildren(arrayList1.get(i - 1));
                addExp.setNodeToken(treeNodeArrayList.get(i - 1).getToken());
                addExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            addExp.setMulExp(arrayList.get(i));
            addExp.setChildren(arrayList.get(i));
            arrayList1.add(addExp);
        }
        return addExp;
    }
    public MulExp processMulExp(int head) {
        MulExp mulExp = null;
        UnaryExp unaryExp = processUnaryExp(this.cnt);
        ArrayList<UnaryExp> arrayList = new ArrayList<>();
        arrayList.add(unaryExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.MULT) || cur_token.getLexType().equals(LexType.DIV) || cur_token.getLexType().equals(LexType.MOD)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            unaryExp = processUnaryExp(this.cnt);
            arrayList.add(unaryExp);
        }
        ArrayList<MulExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            mulExp = new MulExp(ParserType.MulExp, null);
            if (i > 0) {
                mulExp.setMulExp(arrayList1.get(i - 1));
                mulExp.setChildren(arrayList1.get(i - 1));
                mulExp.setOpToken(treeNodeArrayList.get(i - 1).getToken());
                mulExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            mulExp.setUnaryExp(arrayList.get(i));
            mulExp.setChildren(arrayList.get(i));
            arrayList1.add(mulExp);
        }
        return mulExp;
    }
    public UnaryExp processUnaryExp(int head) {
        UnaryExp unaryExp = new UnaryExp(ParserType.UnaryExp, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.PLUS) || cur_token.getLexType().equals(LexType.MINU) || cur_token.getLexType().equals(LexType.NOT)) {
            UnaryOp unaryOp = processUnaryOp(this.cnt);
            unaryExp.setUnaryOp(unaryOp);
            unaryExp.setChildren(unaryOp);
            UnaryExp unaryExp1 = processUnaryExp(this.cnt);
            unaryExp.setUnaryExp(unaryExp1);
            unaryExp.setChildren(unaryExp1);
        } else if (cur_token.getLexType().equals(LexType.IDENFR) && this.lexerHashMap.get(this.cnt + 1).getLexType().equals(LexType.LPARENT)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            unaryExp.setIdentToken(cur_token);
            this.addNode(treeNode, unaryExp);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            unaryExp.setlToken(cur_token);
            this.addNode(treeNode, unaryExp);
            if (cur_token.getLexType().equals(LexType.PLUS) || cur_token.getLexType().equals(LexType.MINU) || cur_token.getLexType().equals(LexType.NOT)  || cur_token.getLexType().equals(LexType.IDENFR)  || cur_token.getLexType().equals(LexType.LPARENT) || cur_token.getLexType().equals(LexType.INTCON)  || cur_token.getLexType().equals(LexType.CHRCON)) {
                FuncRParams funcRParams = processFuncRParams(this.cnt);
                unaryExp.setFuncRParams(funcRParams);
                unaryExp.setChildren(funcRParams);
            }
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                unaryExp.setrToken(cur_token);
                this.addNode(treeNode, unaryExp);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                errorProcess.setError(error);
            }
        } else {
            PrimaryExp primaryExp = processPrimaryExp(this.cnt);
            unaryExp.setPrimaryExp(primaryExp);
            unaryExp.setChildren(primaryExp);
        }
        return unaryExp;
    }
    public UnaryOp processUnaryOp(int head) {
        UnaryOp unaryOp = new UnaryOp(ParserType.UnaryOp, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.PLUS) || cur_token.getLexType().equals(LexType.MINU) || cur_token.getLexType().equals(LexType.NOT)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            unaryOp.setOpToken(cur_token);
            this.addNode(treeNode, unaryOp);
        }
        return unaryOp;
    }
    public FuncRParams processFuncRParams(int head) {
        FuncRParams funcRParams = new FuncRParams(ParserType.FuncRParams, null);
        Exp exp = processExp(this.cnt);
        funcRParams.setExps(exp);
        funcRParams.setChildren(exp);
        TreeNode treeNode;
        while (cur_token.getLexType().equals(LexType.COMMA)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            funcRParams.setCommas(cur_token);
            this.addNode(treeNode, funcRParams);
            exp = processExp(this.cnt);
            funcRParams.setExps(exp);
            funcRParams.setChildren(exp);
        }
        return funcRParams;
    }
    public PrimaryExp processPrimaryExp(int head) {
        PrimaryExp primaryExp = new PrimaryExp(ParserType.PrimaryExp, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.LPARENT)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            primaryExp.setlToken(cur_token);
            this.addNode(treeNode, primaryExp);
            Exp exp = processExp(this.cnt);
            primaryExp.setExp(exp);
            primaryExp.setChildren(exp);
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                primaryExp.setrToken(cur_token);
                this.addNode(treeNode, primaryExp);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                errorProcess.setError(error);
            }
        } else if (cur_token.getLexType().equals(LexType.IDENFR)) {
            LVal lVal = processLVal(this.cnt);
            primaryExp.setlVal(lVal);
            primaryExp.setChildren(lVal);
        } else if (cur_token.getLexType().equals(LexType.INTCON)) {
            Number number = processNumber(this.cnt);
            primaryExp.setNumber(number);
            primaryExp.setChildren(number);
        } else if (cur_token.getLexType().equals(LexType.CHRCON)) {
            Character character = processCharacter(this.cnt);
            primaryExp.setCharacter(character);
            primaryExp.setChildren(character);
        }
        return primaryExp;
    }
    public Number processNumber(int head) {
        Number number = new Number(ParserType.Number, null);
        TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
        number.setIntConstToken(cur_token);
        this.addNode(treeNode, number);
        return number;
    }

    public Character processCharacter(int head) {
        Character character = new Character(ParserType.Character, null);
        TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
        character.setCharConstToken(cur_token);
        this.addNode(treeNode, character);
        return character;
    }
    public FuncType processFuncType(int head) {
        FuncType funcType = null;
        TreeNode treeNode;
        if(cur_token.getLexType().equals(LexType.VOIDTK) || cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
            funcType = new FuncType(ParserType.FuncType, null);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            funcType.setTypeToken(cur_token);
            this.addNode(treeNode, funcType);
        }
        return funcType;
    }

    public FuncFParams processFuncFParams(int head) {
        FuncFParams funcFParams = new FuncFParams(ParserType.FuncFParams, null);
        TreeNode treeNode;
        FuncFParam funcFParam = processFuncFParam(this.cnt);
        funcFParams.setFuncFParams(funcFParam);
        funcFParams.setChildren(funcFParam);
        while (cur_token.getLexType().equals(LexType.COMMA)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            funcFParams.setCommas(cur_token);
            this.addNode(treeNode, funcFParams);
            funcFParam = processFuncFParam(this.cnt);
            funcFParams.setFuncFParams(funcFParam);
            funcFParams.setChildren(funcFParam);
        }
        return funcFParams;
    }
    public FuncFParam processFuncFParam(int head) {
        FuncFParam funcFParam = new FuncFParam(ParserType.FuncFParam, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK)) {
            Btype btype = processBType(this.cnt);
            funcFParam.setBtype(btype);
            funcFParam.setChildren(btype);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            funcFParam.setIdentToken(cur_token);
            this.addNode(treeNode, funcFParam);
            if (cur_token.getLexType().equals(LexType.LBRACK)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                funcFParam.setlToken(cur_token);
                this.addNode(treeNode, funcFParam);
                if (cur_token.getLexType().equals(LexType.RBRACK)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    funcFParam.setrToken(cur_token);
                    this.addNode(treeNode, funcFParam);
                } else {
                    Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'k');
                    errorProcess.setError(error);
                }
            }
        }
        return funcFParam;
    }
    public BlockItem processBlockItem(int head) {
        BlockItem blockItem = new BlockItem(ParserType.BlockItem, null);
        if (cur_token.getLexType().equals(LexType.INTTK) || cur_token.getLexType().equals(LexType.CHARTK) || cur_token.getLexType().equals(LexType.CONSTTK)) {
            Decl decl = processDecl(this.cnt);
            blockItem.setDecl(decl);
            blockItem.setChildren(decl);
        } else {
            Stmt stmt = processStmt(this.cnt);
            blockItem.setStmt(stmt);
            blockItem.setChildren(stmt);
        }
        return blockItem;
    }
    public Stmt processStmt(int head) {
        Stmt stmt = new Stmt(ParserType.Stmt, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.IFTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            Cond cond = processCond(this.cnt);
            stmt.setCond(cond);
            stmt.setChildren(cond);
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                errorProcess.setError(error);
            }
            Stmt stmt1 = processStmt(this.cnt);
            stmt.setStmts(stmt1);
            stmt.setChildren(stmt1);
            if (cur_token.getLexType().equals(LexType.ELSETK)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
                stmt1 = processStmt(this.cnt);
                stmt.setStmts(stmt1);
                stmt.setChildren(stmt1);
            }
        } else if (cur_token.getLexType().equals(LexType.FORTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                ForStmt forStmt = processForStmt(this.cnt);
                stmt.setForStmts(forStmt);
                stmt.setChildren(forStmt);
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            }
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Cond cond = processCond(this.cnt);
                stmt.setCond(cond);
                stmt.setChildren(cond);
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            }
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                ForStmt forStmt = processForStmt(this.cnt);
                stmt.setForStmts(forStmt);
                stmt.setChildren(forStmt);
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            }
            Stmt stmt1 = processStmt(this.cnt);
            stmt.setStmts(stmt);
            stmt.setChildren(stmt1);
        } else if (cur_token.getLexType().equals(LexType.BREAKTK) || cur_token.getLexType().equals(LexType.CONTINUETK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        } else if (cur_token.getLexType().equals(LexType.RETURNTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            if (cur_token.getLexType().equals(LexType.LPARENT) || cur_token.getLexType().equals(LexType.IDENFR) || cur_token.getLexType().equals(LexType.PLUS) || cur_token.getLexType().equals(LexType.MINU) || cur_token.getLexType().equals(LexType.NOT) || cur_token.getLexType().equals(LexType.INTCON) || cur_token.getLexType().equals(LexType.CHRCON)) {
                Exp exp = processExp(this.cnt);
                stmt.setExps(exp);
                stmt.setChildren(exp);
            }
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        } else if (cur_token.getLexType().equals(LexType.PRINTFTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
            while (cur_token.getLexType().equals(LexType.COMMA)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
                Exp exp = processExp(this.cnt);
                stmt.setExps(exp);
                stmt.setChildren(exp);
            }
            if (cur_token.getLexType().equals(LexType.RPARENT)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                errorProcess.setError(error);
            }
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        } else if (cur_token.getLexType().equals(LexType.LBRACE)) {
            Block block = processBlock(this.cnt);
            stmt.setBlock(block);
            stmt.setChildren(block);
        } else if (cur_token.getLexType().equals(LexType.IDENFR)) {
            head = this.cnt;
            LVal lVal = processLVal(this.cnt);
            if (!cur_token.getLexType().equals(LexType.ASSIGN)) {
                this.cnt = head;
                cur_token = this.lexerHashMap.get(this.cnt);
                Exp exp = processExp(this.cnt);
                stmt.setExps(exp);
                stmt.setChildren(exp);
                if (cur_token.getLexType().equals(LexType.SEMICN)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    stmt.setTokens(cur_token);
                    this.addNode(treeNode, stmt);
                } else {
                    Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                    errorProcess.setError(error);
                }
            } else {
                stmt.setlVal(lVal);
                stmt.setChildren(lVal);
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
                if (cur_token.getLexType().equals(LexType.GETINTTK) || cur_token.getLexType().equals(LexType.GETCHARTK)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    stmt.setTokens(cur_token);
                    this.addNode(treeNode, stmt);
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    stmt.setTokens(cur_token);
                    this.addNode(treeNode, stmt);
                    if (cur_token.getLexType().equals(LexType.RPARENT)) {
                        treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                        stmt.setTokens(cur_token);
                        this.addNode(treeNode, stmt);
                    } else {
                        Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'j');
                        errorProcess.setError(error);
                    }
                    if (cur_token.getLexType().equals(LexType.SEMICN)) {
                        treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                        stmt.setTokens(cur_token);
                        this.addNode(treeNode, stmt);
                    } else {
                        Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                        errorProcess.setError(error);
                    }
                } else {
                    Exp exp = processExp(this.cnt);
                    stmt.setExps(exp);
                    stmt.setChildren(exp);
                    if (cur_token.getLexType().equals(LexType.SEMICN)) {
                        treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                        stmt.setTokens(cur_token);
                        this.addNode(treeNode, stmt);
                    } else {
                        Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                        errorProcess.setError(error);
                    }
                }
            }
        } else if (cur_token.getLexType().equals(LexType.SEMICN)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            stmt.setTokens(cur_token);
            this.addNode(treeNode, stmt);
        } else {
            Exp exp = processExp(this.cnt);
            stmt.setExps(exp);
            stmt.setChildren(exp);
            if (cur_token.getLexType().equals(LexType.SEMICN)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                stmt.setTokens(cur_token);
                this.addNode(treeNode, stmt);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'i');
                errorProcess.setError(error);
            }
        }
        return stmt;
    }
    public Cond processCond(int head) {
        Cond cond = new Cond(ParserType.Cond, null);
        LOrExp lOrExp = processLOrExp(this.cnt);
        cond.setlOrExp(lOrExp);
        cond.setChildren(lOrExp);
        return cond;
    }

    public LOrExp processLOrExp(int head) {
        LOrExp lOrExp = null;
        LAndExp lAndExp = processLAndExp(this.cnt);
        ArrayList<LAndExp> arrayList = new ArrayList<>();
        arrayList.add(lAndExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.OR)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            lAndExp = processLAndExp(this.cnt);
            arrayList.add(lAndExp);
        }
        ArrayList<LOrExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            lOrExp = new LOrExp(ParserType.LOrExp, null);
            if (i > 0) {
                lOrExp.setlOrExp(arrayList1.get(i - 1));
                lOrExp.setChildren(arrayList1.get(i - 1));
                lOrExp.setOpToken(treeNodeArrayList.get(i - 1).getToken());
                lOrExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            lOrExp.setlAndExp(arrayList.get(i));
            lOrExp.setChildren(arrayList.get(i));
            arrayList1.add(lOrExp);
        }
        return lOrExp;
    }
    public LAndExp processLAndExp(int head) {
        LAndExp lAndExp = null;
        EqExp eqExp = processEqExp(this.cnt);
        ArrayList<EqExp> arrayList = new ArrayList<>();
        arrayList.add(eqExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.AND)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            eqExp = processEqExp(this.cnt);
            arrayList.add(eqExp);
        }
        ArrayList<LAndExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            lAndExp = new LAndExp(ParserType.LAndExp, null);
            if (i > 0) {
                lAndExp.setlAndExp(arrayList1.get(i - 1));
                lAndExp.setChildren(arrayList1.get(i - 1));
                lAndExp.setOpToken(treeNodeArrayList.get(i - 1).getToken());
                lAndExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            lAndExp.setEqExp(arrayList.get(i));
            lAndExp.setChildren(arrayList.get(i));
            arrayList1.add(lAndExp);
        }
        return lAndExp;
    }
    public EqExp processEqExp(int head) {
        EqExp eqExp = null;
        ArrayList<RelExp> arrayList = new ArrayList<>();
        RelExp relExp = processRelExp(this.cnt);
        arrayList.add(relExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.EQL) || cur_token.getLexType().equals(LexType.NEQ)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            relExp = processRelExp(this.cnt);
            arrayList.add(relExp);
        }
        ArrayList<EqExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            eqExp = new EqExp(ParserType.EqExp, null);
            if (i > 0) {
                eqExp.setEqExp(arrayList1.get(i - 1));
                eqExp.setChildren(arrayList1.get(i - 1));
                eqExp.setOpToken(treeNodeArrayList.get(i - 1).getToken());
                eqExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            eqExp.setRelExp(arrayList.get(i));
            eqExp.setChildren(arrayList.get(i));
            arrayList1.add(eqExp);
        }
        return eqExp;
    }
    public RelExp processRelExp(int head) {
        RelExp relExp = null;
        ArrayList<AddExp> arrayList = new ArrayList<>();
        AddExp addExp = processAddExp(this.cnt);
        arrayList.add(addExp);
        TreeNode treeNode;
        ArrayList<TreeNode> treeNodeArrayList = new ArrayList<>();
        while (cur_token.getLexType().equals(LexType.LEQ) || cur_token.getLexType().equals(LexType.LSS) || cur_token.getLexType().equals(LexType.GEQ) || cur_token.getLexType().equals(LexType.GRE)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            treeNodeArrayList.add(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
            addExp = processAddExp(this.cnt);
            arrayList.add(addExp);
        }
        ArrayList<RelExp> arrayList1 = new ArrayList<>();
        for (int i = 0; i < arrayList.size(); i++) {
            relExp = new RelExp(ParserType.RelExp, null);
            if (i > 0) {
                relExp.setRelExp(arrayList1.get(i - 1));
                relExp.setChildren(arrayList1.get(i - 1));
                relExp.setOpToken(treeNodeArrayList.get(i - 1).getToken());
                relExp.setChildren(treeNodeArrayList.get(i - 1));
            }
            relExp.setAddExp(arrayList.get(i));
            relExp.setChildren(arrayList.get(i));
            arrayList1.add(relExp);
        }
        return relExp;
    }
    public ForStmt processForStmt(int head) {
        ForStmt forStmt = new ForStmt(ParserType.ForStmt, null);
        LVal lVal = processLVal(this.cnt);
        forStmt.setlVal(lVal);
        forStmt.setChildren(lVal);
        TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
        forStmt.setAssignToken(cur_token);
        this.addNode(treeNode, forStmt);
        Exp exp = processExp(this.cnt);
        forStmt.setExp(exp);
        forStmt.setChildren(exp);
        return forStmt;
    }
    public LVal processLVal(int head) {
        LVal lVal = new LVal(ParserType.LVal, null);
        TreeNode treeNode = new TreeNode(ParserType.TOKEN, cur_token);
        lVal.setIdentToken(cur_token);
        this.addNode(treeNode, lVal);
        if (cur_token.getLexType().equals(LexType.LBRACK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            lVal.setlToken(cur_token);
            this.addNode(treeNode, lVal);
            Exp exp = processExp(this.cnt);
            lVal.setExp(exp);
            lVal.setChildren(exp);
            if (cur_token.getLexType().equals(LexType.RBRACK)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                lVal.setrToken(cur_token);
                this.addNode(treeNode, lVal);
            } else {
                Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'k');
                errorProcess.setError(error);
            }
        }
        return lVal;
    }
    public Btype processBType(int head) {
        Btype btype = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.INTTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            btype = new Btype(ParserType.BType, null);
            btype.setTypeToken(cur_token);
            btype.setChildren(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
        } else if (cur_token.getLexType().equals(LexType.CHARTK)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            btype = new Btype(ParserType.BType, null);
            btype.setTypeToken(cur_token);
            btype.setChildren(treeNode);
            if (this.cnt + 1 < this.tokenCnt) {
                cur_token = this.lexerHashMap.get(++this.cnt);
            } else {
                cur_token = null;
            }
        }
        return btype;
    }
    public ConstDef processConstDef(int head) {
        ConstDef constDef = null;
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.IDENFR)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            constDef = new ConstDef(ParserType.ConstDef, null);
            constDef.setIdentToken(cur_token);
            this.addNode(treeNode, constDef);
            if (cur_token.getLexType().equals(LexType.LBRACK)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                constDef.setlToken(cur_token);
                this.addNode(treeNode, constDef);
                ConstExp constExp = processConstExp(this.cnt);
                constDef.setConstExp(constExp);
                constDef.setChildren(constExp);
                if (cur_token.getLexType().equals(LexType.RBRACK)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    constDef.setrToken(cur_token);
                    this.addNode(treeNode, constDef);
                } else {
                    Error error = new Error(this.lexerHashMap.get(this.cnt - 1).getLineNum(), 'k');
                    errorProcess.setError(error);
                }
            }
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            constDef.setAssignToken(cur_token);
            this.addNode(treeNode, constDef);
            ConstInitVal constInitVal = processConstInitVal(this.cnt);
            constDef.setConstInitVal(constInitVal);
            constDef.setChildren(constInitVal);
        }
        return constDef;
    }
    public ConstExp processConstExp(int head) {
        ConstExp constExp = new ConstExp(ParserType.ConstExp, null);
        AddExp addExp = processAddExp(this.cnt);
        constExp.setAddExp(addExp);
        constExp.setChildren(addExp);
        return constExp;
    }
    public ConstInitVal processConstInitVal(int head) {
        ConstInitVal constInitVal = new ConstInitVal(ParserType.ConstInitVal, null);
        TreeNode treeNode;
        if (cur_token.getLexType().equals(LexType.STRCON)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            constInitVal.setStrToken(cur_token);
            this.addNode(treeNode, constInitVal);
        } else if (cur_token.getLexType().equals(LexType.LBRACE)) {
            treeNode = new TreeNode(ParserType.TOKEN, cur_token);
            constInitVal.setlToken(cur_token);
            this.addNode(treeNode, constInitVal);
            if (cur_token.getLexType().equals(LexType.RBRACE)) {
                treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                constInitVal.setrToken(cur_token);
                this.addNode(treeNode, constInitVal);
            } else {
                ConstExp constExp = processConstExp(this.cnt);
                constInitVal.setConstExpArrayList(constExp);
                constInitVal.setChildren(constExp);
                while(cur_token.getLexType().equals(LexType.COMMA)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    constInitVal.setCommaArrayList(cur_token);
                    this.addNode(treeNode, constInitVal);
                    constExp = processConstExp(this.cnt);
                    constInitVal.setConstExpArrayList(constExp);
                    constInitVal.setChildren(constExp);
                }
                if (cur_token.getLexType().equals(LexType.RBRACE)) {
                    treeNode = new TreeNode(ParserType.TOKEN, cur_token);
                    constInitVal.setrToken(cur_token);
                    this.addNode(treeNode, constInitVal);
                }
            }
        } else {
            ConstExp constExp = processConstExp(this.cnt);
            constInitVal.setConstExpArrayList(constExp);
            constInitVal.setChildren(constExp);
        }
        return constInitVal;
    }
    public void postOrderTraversal(TreeNode treeNode, BufferedWriter bufferedWriter) {
        try {
            if (treeNode.getChildren().isEmpty()) {
                if (treeNode.getParserType().equals(ParserType.TOKEN)) {
                    bufferedWriter.write(treeNode.getToken().getLexType() + " " + treeNode.getToken().getValue());
                    bufferedWriter.newLine();
                } else {
                    if (isWrite(treeNode.getParserType())) {
                        bufferedWriter.write("<" + treeNode.getParserType() + ">");
                        bufferedWriter.newLine();
                    }
                }
            } else {
                for (int i = 0; i < treeNode.getChildren().size(); i++) {
                    postOrderTraversal(treeNode.getChildren().get(i), bufferedWriter);
                }
                if (isWrite(treeNode.getParserType())) {
                    bufferedWriter.write("<" + treeNode.getParserType() + ">");
                    bufferedWriter.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public boolean isWrite(ParserType parserType) {
        if (parserType.equals(ParserType.BlockItem) || parserType.equals(ParserType.Decl) || parserType.equals(ParserType.BType)) {
            return false;
        }
        return true;
    }

    public void addNode(TreeNode treeNode, TreeNode rootNode) {
        rootNode.setChildren(treeNode);
        if (this.cnt + 1 < this.tokenCnt) {
            cur_token = this.lexerHashMap.get(++this.cnt);
        } else {
            cur_token = null;
        }
    }
}
