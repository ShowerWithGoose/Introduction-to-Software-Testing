package fronted.parser.parse;

import config.ErrorType;
import fronted.lexer.Lexer;
import fronted.lexer.Token;
import fronted.lexer.TokenType;
import fronted.parser.syntax.*;

import java.util.ArrayList;

public class ExpParser extends Parser {
    private final Lexer lexer;
    public ExpParser(Lexer lexer) {
        this.lexer = lexer;
    }

    //  Exp → AddExp
    @Override
    public SynNode parse() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseAddExp());
        return new SynNonLeaf(SynType.Exp, children);
    }

    // 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
    public SynNode parseConstExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseAddExp());
        return new SynNonLeaf(SynType.ConstExp, children);
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp \eq {MulExp}
    public SynNode parseAddExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseMulExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.PLUS || t.getType() == TokenType.MINU) {
                children.add(new SynLeaf(t));
                children.add(parseMulExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
//        for (SynNode child : children) {
//            System.out.println(child);
//        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.AddExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.AddExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // +, -
                    i++;
                    tmp_child.add(children.get(i)); // Mul
                    root = new SynNonLeaf(SynType.AddExp, tmp_child);
                }
            }
            return root;
        }
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp \eq UnaryExp {('*' | '/' | '%') UnaryExp}
    public SynNode parseMulExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseUnaryExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.MULT || t.getType() == TokenType.DIV || t.getType() == TokenType.MOD) {
                children.add(new SynLeaf(t));
                children.add(parseUnaryExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.MulExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.MulExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // *, / ,%
                    i++;
                    tmp_child.add(children.get(i)); // UnaryExp
                    root = new SynNonLeaf(SynType.MulExp, tmp_child);
                }
            }
            return root;
        }
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    public SynNode parseUnaryExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        Token t1 = lexer.getAndNext();
        Token t2 = lexer.getAndNext();
        if (t1.getType() == TokenType.IDENFR && t2.getType() == TokenType.LPARENT) {
            children.add(new SynLeaf(t1));
            children.add(new SynLeaf(t2));
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.RPARENT) {
                children.add(new SynLeaf(t));
            } else {
                lexer.move(-1);
                // TODO
                if (isExp(lexer)) {
                    children.add(parseFuncRParams());
                    t = lexer.getAndNext();
                    if (t.getType() == TokenType.RPARENT) {
                        children.add(new SynLeaf(t));
                    } else {
                        lexer.move(-1);
                        addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.j));
                    }
                } else {
                    addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.j));
                }
            }
        } else if (t1.getType() == TokenType.PLUS || t1.getType() == TokenType.MINU || t1.getType() == TokenType.NOT) {
            lexer.move(-2);
            children.add(parseUnaryOp());
            children.add(parseUnaryExp());
        } else {
            lexer.move(-2);
            children.add(parsePrimaryExp());
        }

        return new SynNonLeaf(SynType.UnaryExp, children);
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character // j
    // MODIFY: EMPTY
    public SynNode parsePrimaryExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        Token t = lexer.getAndNext();
        lexer.move(-1);
        if (t.getType() == TokenType.LPARENT) {
            lexer.move(1);
            children.add(new SynLeaf(t));
            children.add(parse());
            t = lexer.getAndNext();
            if (t.getType() == TokenType.RPARENT) {
                children.add(new SynLeaf(t));
            } else {
                lexer.move(-1);
                addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.j));
            }
        } else if (t.getType() == TokenType.IDENFR) {
            children.add(parseLVal());
        } else if (t.getType() == TokenType.INTCON) {
            children.add(parseNumber());
        } else if (t.getType() == TokenType.CHRCON) {
            children.add(parseCharacter());
        } else { // empty
            children.add(new SynNonLeaf(SynType.EMPTY, new ArrayList<>()));
        }

        return new SynNonLeaf(SynType.PrimaryExp, children);
    }

    // FuncRParams → Exp { ',' Exp }
    public SynNode parseFuncRParams() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parse());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.COMMA) {
                children.add(new SynLeaf(t));
                children.add(parse());
            } else {
                lexer.move(-1);
                break;
            }
        }
        return new SynNonLeaf(SynType.FuncRParams, children);
    }

    // UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    public SynNode parseUnaryOp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        return new SynNonLeaf(SynType.UnaryOp, children);
    }

    //  LOrExp → LAndExp | LOrExp '||' LAndExp
    public SynNode parseLOrExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseLAndExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.OR) {
                children.add(new SynLeaf(t));
                children.add(parseLAndExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.LOrExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.LOrExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // +, -
                    i++;
                    tmp_child.add(children.get(i)); // Mul
                    root = new SynNonLeaf(SynType.LOrExp, tmp_child);
                }
            }
            return root;
        }
    }

    // EqExp | LAndExp '&&' EqExp
    public SynNode parseLAndExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseEqExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.AND) {
                children.add(new SynLeaf(t));
                children.add(parseEqExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.LAndExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.LAndExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // +, -
                    i++;
                    tmp_child.add(children.get(i)); // Mul
                    root = new SynNonLeaf(SynType.LAndExp, tmp_child);
                }
            }
            return root;
        }
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public SynNode parseEqExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseRelExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.EQL || t.getType() == TokenType.NEQ) {
                children.add(new SynLeaf(t));
                children.add(parseRelExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.EqExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.EqExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // +, -
                    i++;
                    tmp_child.add(children.get(i)); // Mul
                    root = new SynNonLeaf(SynType.EqExp, tmp_child);
                }
            }
            return root;
        }
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public SynNode parseRelExp() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseAddExp());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.LEQ || t.getType() == TokenType.LSS ||
                    t.getType() == TokenType.GRE || t.getType() == TokenType.GEQ) {
                children.add(new SynLeaf(t));
                children.add(parseAddExp());
            } else {
                lexer.move(-1);
                break;
            }
        }
        if (children.size() == 1) {
            return new SynNonLeaf(SynType.RelExp, children);
        } else {
            SynNode root = null;
            for (int i = 0; i < children.size(); i++) {
                if (i == 0) {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(children.get(i));
                    root = new SynNonLeaf(SynType.RelExp, tmp_child);
                } else {
                    ArrayList<SynNode> tmp_child = new ArrayList<>();
                    tmp_child.add(root);
                    tmp_child.add(children.get(i)); // +, -
                    i++;
                    tmp_child.add(children.get(i)); // Mul
                    root = new SynNonLeaf(SynType.RelExp, tmp_child);
                }
            }
            return root;
        }
    }

    public SynNode parseNumber() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        return new SynNonLeaf(SynType.Number, children);
    }

    public SynNode parseCharacter() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        return new SynNonLeaf(SynType.Character, children);
    }

    // LVal → Ident ['[' Exp ']'] // k
    public SynNode parseLVal() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // Ident
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.LBRACK) {
            children.add(new SynLeaf(t));
            children.add(parse());
            t = lexer.getAndNext();
            if (t.getType() == TokenType.RBRACK) {
                children.add(new SynLeaf(t));
            } else {
                lexer.move(-1);
                addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.k));
            }
        } else {
            lexer.move(-1);
        }

        return new SynNonLeaf(SynType.LVal, children);
    }
}
/**
 * 表达式    Exp → AddExp
 * 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
 * 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
 * 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
 * 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
 * 函数实参表 FuncRParams → Exp { ',' Exp }
 * 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
 *
 * 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
 * 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
 * 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
 * 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
 *
 * 数值 Number → IntConst
 * 字符 Character → CharConst
 *
 * 语句 ForStmt → LVal '=' Exp
 * 左值表达式 LVal → Ident ['[' Exp ']'] // k
 */