package parser.Normal;

import common.GlobalData;
import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;
import parser.Var.ExpParser;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class StmtParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        Token tt = iterator.next();
        //处理 Block
        if(tt.getType() == TokenType.LBRACE) {
            iterator.unread(1);
            BlockParser blockParser = new BlockParser();
            children.add(blockParser.run(iterator));
        }
        //处理 if
        else if(tt.getType() == TokenType.IFTK) {
            children.add(leafParser.run(tt));
            // '(' Cond
            children.add(leafParser.run(iterator.next()));
            CondParser condParser = new CondParser();
            children.add(condParser.run(iterator));
            // ')'
            tt = iterator.next();
            if(tt.getType() != TokenType.RPARENT) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'j');
            }
            else children.add(leafParser.run(tt));
            // Stmt
            StmtParser stmtParser = new StmtParser();
            children.add(stmtParser.run(iterator));
            //[ 'else' Stmt ]
            tt = iterator.next();
            if(tt.getType() == TokenType.ELSETK) {
                children.add(leafParser.run(tt));
                children.add(stmtParser.run(iterator));
            }
            else iterator.unread(1);
        }
        //处理 for
        else if(tt.getType() == TokenType.FORTK) {
            ForStmtParser forStmtParser = new ForStmtParser();
            StmtParser stmtParser = new StmtParser();

            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt]
                // 'for' '('
            children.add(leafParser.run(tt));
            children.add(leafParser.run(iterator.next()));
                // [ForStmt] ';'
            tt = iterator.next();
            if(tt.getType() != TokenType.SEMICN) {
                iterator.unread(1);
                children.add(forStmtParser.run(iterator));
                children.add(leafParser.run(iterator.next()));
            }
            else children.add(leafParser.run(tt));
                // [Cond] ';'
            tt = iterator.next();
            if(tt.getType() != TokenType.SEMICN) {
                iterator.unread(1);
                CondParser condParser = new CondParser();
                children.add(condParser.run(iterator));
                children.add(leafParser.run(iterator.next()));
            }
            else children.add(leafParser.run(tt));
                // [ForStmt]
            tt = iterator.next();
            if(tt.getType() != TokenType.RPARENT) {
                iterator.unread(1);
                children.add(forStmtParser.run(iterator));
                // ')'
                children.add(leafParser.run(iterator.next()));
            }
            // ')'
            else children.add(leafParser.run(tt));
            //Stmt
            children.add(stmtParser.run(iterator));
        }
        //处理 break 或 continue
        else if(tt.getType() == TokenType.BREAKTK || tt.getType() == TokenType.CONTINUETK) {
            children.add(leafParser.run(tt));

            Token tmp = iterator.next();
            if(tmp.getType() == TokenType.SEMICN) {
                children.add(leafParser.run(tmp));
            }
            else {
                iterator.unread(2);
                tmp = iterator.next();
                ErrorSave.error("Parser", tmp.getLineno(), 'i');
            }
        }
        //处理 return
        else if(tt.getType() == TokenType.RETURNTK) {
            children.add(leafParser.run(tt));
            tt = iterator.next();
            if(tt.getType() != TokenType.SEMICN) {
                //判断是否属于Exp
                if(tt.getType() != TokenType.LPARENT && tt.getType() != TokenType.IDENFR && tt.getType() != TokenType.CHRCON &&
                tt.getType() != TokenType.INTCON && tt.getType() != TokenType.PLUS && tt.getType() != TokenType.MINU && tt.getType() != TokenType.NOT) {
                    //不属于Exp,直接报错
                    iterator.unread(2);
                    tt = iterator.next();
                    ErrorSave.error("Parser", tt.getLineno(), 'i');
                }
                else {
                    //属于Exp,处理完在判断分号
                    iterator.unread(1);
                    ExpParser expParser = new ExpParser();
                    children.add(expParser.run(iterator));
                    tt = iterator.next();
                    if(tt.getType() == TokenType.SEMICN) {
                        children.add(leafParser.run(tt));
                    }
                    else {
                        iterator.unread(2);
                        tt = iterator.next();
                        ErrorSave.error("Parser", tt.getLineno(), 'i');
                    }
                }

            }
            //读到分号,没有Exp
            else children.add(leafParser.run(tt));
        }
        //处理 printf
        else if(tt.getType() == TokenType.PRINTFTK) {
            ExpParser expParser = new ExpParser();

            //'printf''('StringConst {','Exp}
            children.add(leafParser.run(tt));
            children.add(leafParser.run(iterator.next()));
            children.add(leafParser.run(iterator.next()));
            tt = iterator.next();
            while(tt.getType() == TokenType.COMMA) {
                children.add(leafParser.run(tt));
                children.add(expParser.run(iterator));
                tt = iterator.next();
            }
            // ')' ';'
            if(tt.getType() != TokenType.RPARENT) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'j');
            }
            else children.add(leafParser.run(tt));
            tt = iterator.next();

            if(tt.getType() != TokenType.SEMICN) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'i');
            }
            else children.add(leafParser.run(tt));
        }
        //处理Ident 开头的， 包括三种 LVal '=' , [Exp]中的 LVal, 和[Exp]中的 Ident '('
        else if(tt.getType() == TokenType.IDENFR) {
            Token tmp = iterator.next();
            iterator.unread(2);
            //处理 Ident '('
            if(tmp.getType() == TokenType.LPARENT) {
                ExpParser expParser = new ExpParser();
                children.add(expParser.run(iterator));
                tt = iterator.next();
                if(tt.getType() != TokenType.SEMICN) {
                    iterator.unread(2);
                    tt = iterator.next();
                    ErrorSave.error("Parser", tt.getLineno(), 'i');
                }
                else children.add(leafParser.run(tt));
            }
            //三种 LVal '=' , [Exp]中的 LVal
            else {
                int CursorBefore = iterator.getCursor();
                int ErrorsSize = GlobalData.Errors.size();
                //处理 LVal , 记得判断是LVal还是Exp中的LVal, 先假装直接处理掉LVal
                LValParser lValParser = new LValParser();
                children.add(lValParser.run(iterator));
                tt = iterator.next();

                //如果是 '='
                if(tt.getType() == TokenType.ASSIGN) {
                    children.add(leafParser.run(tt));
                    tt = iterator.next();
                    // getint 或 getchar
                    if(tt.getType() == TokenType.GETINTTK || tt.getType() == TokenType.GETCHARTK) {
                        children.add(leafParser.run(tt));
                        children.add(leafParser.run(iterator.next()));
                        // ')'
                        tt = iterator.next();
                        if(tt.getType() != TokenType.RPARENT) {
                            iterator.unread(2);
                            tt = iterator.next();
                            ErrorSave.error("Parser", tt.getLineno(), 'j');
                        }
                        else children.add(leafParser.run(tt));
                        // ';'
                        tt = iterator.next();
                        if(tt.getType() != TokenType.SEMICN) {
                            iterator.unread(2);
                            tt = iterator.next();
                            ErrorSave.error("Parser", tt.getLineno(), 'i');
                        }
                        else children.add(leafParser.run(tt));
                    }
                    // Exp
                    else {
                        iterator.unread(1);
                        ExpParser expParser = new ExpParser();
                        children.add(expParser.run(iterator));
                        // ';'
                        tt = iterator.next();
                        if(tt.getType() != TokenType.SEMICN) {
                            iterator.unread(2);
                            tt = iterator.next();
                            ErrorSave.error("Parser", tt.getLineno(), 'i');
                        }
                        else children.add(leafParser.run(tt));
                    }
                }
                //LVal 是[Exp]中的，把之前加入children的LVal删掉，使用ExpParser处理
                else {
                    //移除之前children中的LVal 和 Errors 中的错误
                    children.remove(children.size()-1);
                    if(GlobalData.Errors.size() > ErrorsSize) {
                        GlobalData.Errors.remove(GlobalData.Errors.size()-1);
                    }

                    //让iterator返回到当时的位置
                    iterator.setCursor(CursorBefore);
                    //用Exp处理
                    ExpParser expParser = new ExpParser();
                    children.add(expParser.run(iterator));
                    tt = iterator.next();
                    if(tt.getType() != TokenType.SEMICN) {
                        iterator.unread(2);
                        tt = iterator.next();
                        ErrorSave.error("Parser", tt.getLineno(), 'i');
                    }
                    else children.add(leafParser.run(tt));
                }
            }
        }
        //处理[Exp]不存在, 只有';'的情况
        else if(tt.getType() == TokenType.SEMICN) {
            children.add(leafParser.run(tt));
        }
        //处理[Exp]存在的情况
        else {
            iterator.unread(1);
            ExpParser expParser = new ExpParser();
            children.add(expParser.run(iterator));
            // ';'
            tt = iterator.next();
            if(tt.getType() != TokenType.SEMICN) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'i');
            }
            else children.add(leafParser.run(tt));
        }

        return new SyntaxTreeNode("<Stmt>", null, children);
    }
}
