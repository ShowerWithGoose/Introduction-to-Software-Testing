import javax.lang.model.type.ErrorType;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Parser {
    static GrammarTreeNode root = new GrammarTreeNode(GrammarTreeNode.ComponentType.COMPUNIT);
    static private int currentIndex = 0;
    static private boolean errorIgnorance = false;
    static public List<String> tree = new ArrayList<>();
    static ErrorToken currentErrorToken;

    public Parser(){
        CompUnitProcess();
    }

    private void CompUnitProcess(){
        if(Lexer.tokens == null){
            Error();
        }
        Token currentToken = read();
        Token nextToken1 = Preread(1);
        Token nextToken2 = Preread(2);
        if(nextToken1 == null){
            Error();
            return;
        }
        if(nextToken2 == null){
            Error();
            return;
        }
        boolean isDecl = true;
        boolean isFuncDef = true;
        while(isDecl){
            if(currentToken.type == Token.TokenType.Const){
                GrammarTreeNode node1 = root.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.DECL);
                DeclProcess(node1);
            }
            else if(currentToken.type == Token.TokenType.Int || currentToken.type == Token.TokenType.Char){
                if(nextToken2.type == Token.TokenType.Lbrack || nextToken2.type == Token.TokenType.Assign || nextToken2.type == Token.TokenType.Comma || nextToken2.type == Token.TokenType.Semicn  || nextToken2.type == Token.TokenType.Const || nextToken2.type == Token.TokenType.Int || nextToken2.type == Token.TokenType.Char){
                    GrammarTreeNode node2 = root.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.DECL);
                    DeclProcess(node2);
                }
                else {
                    isDecl = false;
                }
            }
            else {
                isDecl = false;
            }
            currentToken = read();
            nextToken1 = Preread(1);
            nextToken2 = Preread(2);
            if(nextToken1 == null){
                Error();
                return;
            }
            if(nextToken2 == null){
                Error();
                return;
            }
        }

        while(isFuncDef){
            if(nextToken1.type != Token.TokenType.Main){
                GrammarTreeNode node3 = root.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FUNCDEF);
                FuncDefProcess(node3);
            }
            else {
                isFuncDef = false;
            }
            currentToken = read();
            nextToken1 = Preread(1);
            nextToken2 = Preread(2);
            if(nextToken1 == null){
                Error();
                return;
            }
            if(nextToken2 == null){
                Error();
                return;
            }
        }

        GrammarTreeNode node4 = root.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.MAINFUNCDEF);
        MainFuncDefProcess(node4);
    }

    private void DeclProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();

        if (currentToken.type == Token.TokenType.Const) {
            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTDECL);
            ConstDeclProcess(node1);
        } else if (currentToken.type == Token.TokenType.Int || currentToken.type == Token.TokenType.Char) {
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.VARDECL);
            VarDeclProcess(node2);
        } else {
            Error();
        }
    }

    private void ConstDeclProcess(GrammarTreeNode currentNode){
        Token currentToken = read();
        if(currentToken.type != Token.TokenType.Const){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex ++;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BTYPE);
        BTypeProcess(node1);

        boolean hasMoreDefs = true;
        while (hasMoreDefs) {
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTDEF);
            ConstDefProcess(node2);

            currentToken = read();
            if (currentToken.type == Token.TokenType.Comma) {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            } else if (currentToken.type == Token.TokenType.Semicn) {
                hasMoreDefs = false;
            } else {
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
        }

        currentNode.CreateTerminatorChildNode(currentToken); // Semicn
        currentIndex++;
    }

    private void BTypeProcess(GrammarTreeNode currentNode){
        Token currentToken = read();
        if(currentToken.type != Token.TokenType.Int && currentToken.type != Token.TokenType.Char){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex ++;
    }

    private void ConstDefProcess(GrammarTreeNode currentNode){
        Token currentToken = read();
        if(currentToken.type != Token.TokenType.Ident){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex ++;
        currentToken = read();
        if(currentToken.type == Token.TokenType.Lbrack){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex ++;
            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTEXP);
            ConstExpProcess(node1);

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rbrack){
                Error(ErrorToken.ErrorTokenType.LackOfRbrack);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex ++;
            }
            currentToken = read();
        }
        if(currentToken.type != Token.TokenType.Assign){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex ++;
        GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTINITVAL);
        ConstInitValProcess(node2);
    }

    private void ConstInitValProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type == Token.TokenType.Lbrace) {
            // 一维数组初值
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            boolean hasMoreElements = currentToken.type != Token.TokenType.Rbrace;
            while (hasMoreElements) {
                GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTEXP);
                ConstExpProcess(node);

                currentToken = read();
                if (currentToken.type == Token.TokenType.Comma) {
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                } else if (currentToken.type == Token.TokenType.Rbrace) {
                    hasMoreElements = false;
                } else {
                    Error();
                    return;
                }
            }

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

        } else if (currentToken.type == Token.TokenType.StringConst) {
            // 字符串常量作为初值
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

        } else if (currentToken.type == Token.TokenType.IntConst || currentToken.type == Token.TokenType.CharConst || currentToken.type == Token.TokenType.Lparent || currentToken.type == Token.TokenType.Ident || currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu || currentToken.type == Token.TokenType.Not) {
            // 常表达式初值
            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTEXP);
            ConstExpProcess(node);

        } else {
            Error();
        }
    }

    private void VarDeclProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();

        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BTYPE);
        BTypeProcess(node1);

        boolean hasMoreDefs = true;
        while (hasMoreDefs) {
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.VARDEF);
            VarDefProcess(node2);

            currentToken = read();
            if (currentToken.type == Token.TokenType.Comma) {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            } else if (currentToken.type == Token.TokenType.Semicn) {
                hasMoreDefs = false;
            } else {
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
        }

        currentNode.CreateTerminatorChildNode(currentToken); // Semicn
        currentIndex++;
    }

    private void VarDefProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Ident) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;

        currentToken = read();
        if (currentToken.type == Token.TokenType.Lbrack) {
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CONSTEXP);
            ConstExpProcess(node);

            currentToken = read();
            if (currentToken.type != Token.TokenType.Rbrack) {
                Error(ErrorToken.ErrorTokenType.LackOfRbrack);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
            currentToken = read();
        }

        if (currentToken.type == Token.TokenType.Assign) {
            // 有初始化值
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode initValNode = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.INITVAL);
            InitValProcess(initValNode);
        }
    }

    private void InitValProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();

        if (currentToken.type == Token.TokenType.Lbrace) {
            // 一维数组初值
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            boolean hasMoreElements = currentToken.type != Token.TokenType.Rbrace;
            while (hasMoreElements) {
                GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
                ExpProcess(node); // 需要实现一个处理所有表达式类型的方法

                currentToken = read();
                if (currentToken.type == Token.TokenType.Comma) {
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                } else if (currentToken.type == Token.TokenType.Rbrace) {
                    hasMoreElements = false;
                } else {
                    Error();
                    return;
                }
            }

            currentNode.CreateTerminatorChildNode(currentToken); // Rbrace
            currentIndex++;

        }  else if (currentToken.type == Token.TokenType.StringConst) {
            // 字符串常量作为初值
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

        } else if (currentToken.type == Token.TokenType.IntConst || currentToken.type == Token.TokenType.CharConst || currentToken.type == Token.TokenType.Lparent || currentToken.type == Token.TokenType.Ident || currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu || currentToken.type == Token.TokenType.Not) {
            // 常表达式初值
            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
            ExpProcess(node);

        } else {
            Error();
        }
    }

    private void FuncDefProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FUNCTYPE);
        FuncTypeProcess(node1);

        Token identToken = read();
        if (identToken.type != Token.TokenType.Ident) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(identToken); // Ident
        currentIndex++;

        currentToken = read();
        if (currentToken.type != Token.TokenType.Lparent) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // '('
        currentIndex++;
        currentToken = read();

        // 解析函数形参表（可选）
        if (currentToken.type != Token.TokenType.Rparent) {
            if(currentToken.type != Token.TokenType.Char && currentToken.type != Token.TokenType.Int){
                Error(ErrorToken.ErrorTokenType.LackOfRparent);
                GrammarTreeNode node4 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCK);
                BlockProcess(node4);
                return;
            }
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FUNCFPARAMS);
            FuncFParamsProcess(node2);
        }

        currentToken = read();
        if (currentToken.type != Token.TokenType.Rparent) {
            Error(ErrorToken.ErrorTokenType.LackOfRparent);
            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCK);
            BlockProcess(node3);
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // ')'
        currentIndex++;

        GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCK);
        BlockProcess(node3);
    }

    private void MainFuncDefProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Int) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // 'int'
        currentIndex++;

        currentToken = read();
        if (currentToken.type != Token.TokenType.Main) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // 'main'
        currentIndex++;

        currentToken = read();
        if (currentToken.type != Token.TokenType.Lparent) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // '('
        currentIndex++;

        currentToken = read();
        if (currentToken.type != Token.TokenType.Rparent) {
            Error(ErrorToken.ErrorTokenType.LackOfRparent);
        }
        else {
            currentNode.CreateTerminatorChildNode(currentToken); // ')'
            currentIndex++;
        }

        GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCK);
        BlockProcess(node); // 解析代码块
    }

    private void FuncTypeProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Void && currentToken.type != Token.TokenType.Int && currentToken.type != Token.TokenType.Char) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken); // 'void' | 'int' | 'char'
        currentIndex++;
    }

    private void FuncFParamsProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        boolean isParam = true;
        while (isParam) {
            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FUNCFPARAM);
            FuncFParamProcess(node);
            currentToken = read(); // 读取并处理逗号
            if (currentToken.type != Token.TokenType.Comma) {
                isParam = false;
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
        }
    }

    private void FuncFParamProcess(GrammarTreeNode currentNode) {
        GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BTYPE);
        BTypeProcess(node);

        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Ident) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;

        currentToken = read();
        if (currentToken.type == Token.TokenType.Lbrack) {
            currentIndex++; // 读取左方括号
            currentNode.CreateTerminatorChildNode(currentToken);
            currentToken= read();
            if (currentToken.type != Token.TokenType.Rbrack) {
                Error(ErrorToken.ErrorTokenType.LackOfRbrack);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
        }
    }

    private void BlockProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Lbrace) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;

        currentToken = read();
        while (currentToken.type != Token.TokenType.Rbrace) {
            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCKITEM);
            BlockItemProcess(node);
            currentToken = read();
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;
    }

    private void BlockItemProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type == Token.TokenType.Const || currentToken.type == Token.TokenType.Int || currentToken.type == Token.TokenType.Char) {
            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.DECL);
            DeclProcess(node1);
        } else {
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.STMT);
            StmtProcess(node2);
        }
    }

    private void StmtProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if(currentToken.type == Token.TokenType.Ident){
            errorIgnorance = true;
            int savePoint = currentIndex;
            boolean isExp = true;
            GrammarTreeNode node = new GrammarTreeNode(GrammarTreeNode.ComponentType.LVAL);
            LValProcess(node);
            currentToken = read();
            if(currentToken.type == Token.TokenType.Assign){
                isExp = false;
            }

            currentIndex = savePoint;
            errorIgnorance = false;
            if(isExp){
                node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
                ExpProcess(node);

                currentToken = read();
                if(currentToken.type != Token.TokenType.Semicn){
                    Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                    return;
                }
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
            else {
                node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LVAL);
                LValProcess(node);

                currentToken = read();
                if(currentToken.type != Token.TokenType.Assign){
                    Error();
                    return;
                }
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;

                currentToken = read();
                if(currentToken.type == Token.TokenType.Getint){
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Lparent){
                        Error();
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Rparent){
                        Error(ErrorToken.ErrorTokenType.LackOfRparent);
                    }
                    else {
                        currentNode.CreateTerminatorChildNode(currentToken);
                        currentIndex++;
                    }

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Semicn){
                        Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
                else if(currentToken.type == Token.TokenType.Getchar){
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Lparent){
                        Error();
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Rparent){
                        Error(ErrorToken.ErrorTokenType.LackOfRparent);
                    }
                    else {
                        currentNode.CreateTerminatorChildNode(currentToken);
                        currentIndex++;
                    }

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Semicn){
                        Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
                else {
                    node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
                    ExpProcess(node);

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Semicn){
                        Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
            }
        }
        else if(currentToken.type == Token.TokenType.IntConst || currentToken.type == Token.TokenType.CharConst || currentToken.type == Token.TokenType.Lparent || currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu || currentToken.type == Token.TokenType.Not){
            GrammarTreeNode node11 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
            ExpProcess(node11);

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Semicn){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Lbrace){
            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.BLOCK);
            BlockProcess(node1);
        }
        else if(currentToken.type == Token.TokenType.Break){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Continue){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Return){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                if (currentToken.type == Token.TokenType.IntConst || currentToken.type == Token.TokenType.CharConst || currentToken.type == Token.TokenType.Lparent || currentToken.type == Token.TokenType.Ident || currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu || currentToken.type == Token.TokenType.Not){
                    GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
                    ExpProcess(node2);
                }
                else {
                    Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                    return;
                }

                currentToken = read();
                if(currentToken.type != Token.TokenType.Semicn){
                    Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                    return;
                }
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Printf){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Lparent){
                Error();
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.StringConst){
                Error();
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            boolean hasExp = true;

            currentToken = read();
            while (hasExp){
                if(currentToken.type == Token.TokenType.Comma){
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;

                    GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
                    ExpProcess(node3);

                    currentToken = read();
                }
                else {
                    hasExp = false;
                }
            }

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rparent){
                Error(ErrorToken.ErrorTokenType.LackOfRparent);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.If){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Lparent){
                Error();
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node4 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.COND);
            CondProcess(node4);

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rparent){
                Error(ErrorToken.ErrorTokenType.LackOfRparent);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }

            GrammarTreeNode node5 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.STMT);
            StmtProcess(node5);

            currentToken = read();
            if(currentToken.type == Token.TokenType.Else){
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;

                GrammarTreeNode node6 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.STMT);
                StmtProcess(node6);
            }
        }
        else if(currentToken.type == Token.TokenType.For){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Lparent){
                Error();
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                GrammarTreeNode node7 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FORSTMT);
                ForStmtProcess(node7);

                currentToken = read();
                if(currentToken.type != Token.TokenType.Semicn){
                    Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                    return;
                }
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Semicn){
                GrammarTreeNode node8 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.COND);
                CondProcess(node8);

                currentToken = read();
                if(currentToken.type != Token.TokenType.Semicn){
                    Error(ErrorToken.ErrorTokenType.LackOfSemicn);
                    return;
                }
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rparent){
                GrammarTreeNode node9 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FORSTMT);
                ForStmtProcess(node9);

                currentToken = read();
                if(currentToken.type != Token.TokenType.Rparent){
                    Error(ErrorToken.ErrorTokenType.LackOfRparent);
                }
                else {
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }

            GrammarTreeNode node10 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.STMT);
            StmtProcess(node10);
        }
    }

    private void ForStmtProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LVAL);
        LValProcess(node1);

        currentToken = read();
        if (currentToken.type != Token.TokenType.Assign) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;

        GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
        ExpProcess(node2);
    }

    private void ExpProcess(GrammarTreeNode currentNode) {
        GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.ADDEXP);
        AddExpProcess(node);
    }

    private void CondProcess(GrammarTreeNode currentNode) {
        GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LOREXP);
        LOrExpProcess(node);
    }

    private void LValProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Ident){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;

        currentToken = read();
        if (currentToken.type == Token.TokenType.Lbrack) {
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
            ExpProcess(node);

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rbrack){
                Error(ErrorToken.ErrorTokenType.LackOfRbrack);
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
        }
    }

    private void PrimaryExpProcess(GrammarTreeNode currentNode){
        Token currentToken = read();
        if (currentToken.type == Token.TokenType.Lparent){
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
            ExpProcess(node1);

            currentToken = read();
            if(currentToken.type != Token.TokenType.Rparent){
                Error(ErrorToken.ErrorTokenType.LackOfRparent);
                return;
            }
            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;
        }
        else if(currentToken.type == Token.TokenType.Ident) {
            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LVAL);
            LValProcess(node2);
        }
        else if(currentToken.type == Token.TokenType.IntConst){
            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.NUMBER);
            NumberProcess(node3);
        }
        else if(currentToken.type == Token.TokenType.CharConst){
            GrammarTreeNode node4 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.CHARACTER);
            CharacterProcess(node4);
        }
        else {
            Error();
        }
    }

    private void NumberProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.IntConst){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;
    }

    private void CharacterProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.CharConst){
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;
    }

    private void UnaryExpProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu || currentToken.type == Token.TokenType.Not) {
            GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.UNARYOP);
            UnaryOpProcess(node1);

            GrammarTreeNode node2 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.UNARYEXP);
            UnaryExpProcess(node2);
        }
        else if(currentToken.type == Token.TokenType.Ident){
            Token nextToken = Preread(1);
            if(nextToken == null){
                Error();
                return;
            }
            if (nextToken.type == Token.TokenType.Lparent) {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;

                currentToken = read();
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;

                currentToken = read();
                if(currentToken.type == Token.TokenType.Rparent) {
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
                else{
                    GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.FUNCRPARAMS);
                    FuncRParamsProcess(node3);

                    currentToken = read();
                    if(currentToken.type != Token.TokenType.Rparent){
                        Error(ErrorToken.ErrorTokenType.LackOfRparent);
                        return;
                    }
                    currentNode.CreateTerminatorChildNode(currentToken);
                    currentIndex++;
                }
            }
            else{
                GrammarTreeNode node4 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.PRIMARYEXP);
                PrimaryExpProcess(node4);
            }
        }
        else if(currentToken.type == Token.TokenType.Lparent || currentToken.type == Token.TokenType.IntConst || currentToken.type == Token.TokenType.CharConst){
            GrammarTreeNode node4 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.PRIMARYEXP);
            PrimaryExpProcess(node4);
        }
        else {
            Error();
        }
    }

    private void UnaryOpProcess(GrammarTreeNode currentNode) {
        Token currentToken = read();
        if (currentToken.type != Token.TokenType.Plus && currentToken.type != Token.TokenType.Minu && currentToken.type != Token.TokenType.Not) {
            Error();
            return;
        }
        currentNode.CreateTerminatorChildNode(currentToken);
        currentIndex++;
    }

    private void FuncRParamsProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        boolean isParam = true;
        while (isParam) {
            GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EXP);
            ExpProcess(node);
            currentToken = read(); // 读取并处理逗号
            if (currentToken.type != Token.TokenType.Comma) {
                isParam = false;
            }
            else {
                currentNode.CreateTerminatorChildNode(currentToken);
                currentIndex++;
            }
        }
    }

    private void MulExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.UNARYEXP);
        UnaryExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.Mult || currentToken.type == Token.TokenType.Div || currentToken.type == Token.TokenType.Mod) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.MULEXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.UNARYEXP);
            UnaryExpProcess(node3);

            currentToken = read();
        }
    }

    private void AddExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.MULEXP);
        MulExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.Plus || currentToken.type == Token.TokenType.Minu) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.ADDEXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.MULEXP);
            MulExpProcess(node3);

            currentToken = read();
        }
    }

    private void RelExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.ADDEXP);
        AddExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.Lss || currentToken.type == Token.TokenType.Gre || currentToken.type == Token.TokenType.Leq || currentToken.type == Token.TokenType.Geq) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.RELEXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.ADDEXP);
            AddExpProcess(node3);

            currentToken = read();
        }
    }

    private void EqExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.RELEXP);
        RelExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.Eql || currentToken.type == Token.TokenType.Neq) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.EQEXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.RELEXP);
            RelExpProcess(node3);

            currentToken = read();
        }
    }

    private void LAndExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EQEXP);
        EqExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.And) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.LANDEXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.EQEXP);
            EqExpProcess(node3);

            currentToken = read();
        }
    }

    private void LOrExpProcess(GrammarTreeNode currentNode) {
        Token currentToken;
        GrammarTreeNode node1 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LANDEXP);
        LAndExpProcess(node1);

        currentToken = read();
        while(currentToken.type == Token.TokenType.Or) {
            GrammarTreeNode node2 = new GrammarTreeNode(GrammarTreeNode.ComponentType.LOREXP);
            node2.ChildrenNode = currentNode.ChildrenNode;
            currentNode.ChildrenNode = new ArrayList<>();
            currentNode.ChildrenNode.add(node2);

            currentNode.CreateTerminatorChildNode(currentToken);
            currentIndex++;

            GrammarTreeNode node3 = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.LANDEXP);
            LAndExpProcess(node3);

            currentToken = read();
        }
    }

    private void ConstExpProcess(GrammarTreeNode currentNode) {
        GrammarTreeNode node = currentNode.CreateNonTerminatorChildNode(GrammarTreeNode.ComponentType.ADDEXP);
        AddExpProcess(node);
    }

    private Token read(){
        return Lexer.tokens.get(currentIndex);
    }

    private Token Preread(int n){
        if(currentIndex + n > Lexer.tokens.size()){
            Error();
            return null;
        }
        return Lexer.tokens.get(currentIndex + n);
    }


    private Token Exread(){
        return Lexer.tokens.get(currentIndex - 1);
    }

    private void Error(){
        Token t = read();
        System.out.print("Error in " + currentIndex + ' ' + t.type + ' ' + t.content + '\n');
    }

    private void Error(ErrorToken.ErrorTokenType t){
        if(errorIgnorance)return;
        Compiler.errorExists = true;
        ErrorToken e = new ErrorToken(t, Exread().content, Exread().lineno);
        Lexer.errorTokens.add(e);
    }

    static void output(boolean f, String filePath, String errorFilePath){
        if(f){
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFilePath))) {
                for (ErrorToken errorToken : Lexer.errorTokens) {
                    writer.write( errorToken.toString(errorToken.lineno)+ ' ' + errorToken.type.getValue());
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else{
            root.DFS();
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
                for (String node : tree) {
                    writer.write(node);
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
