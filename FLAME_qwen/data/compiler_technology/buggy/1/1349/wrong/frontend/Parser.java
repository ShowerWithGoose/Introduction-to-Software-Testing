package frontend;

import frontend.Token.Token;
import frontend.Token.TokenType;
import frontend.Node.Node;
import frontend.Node.NodeType;

import java.io.BufferedWriter;
import java.util.ArrayList;

public class Parser {
    private int pos = 0;

    private final ErrorHandler errorHandler;

    private final BufferedWriter stdWriter = Config.PARSER_WRITER;

    private Token token;

    private final ArrayList<Token> tokens;

    private final Node compUnit = new Node(NodeType.CompUnit);

    public Parser(ArrayList<Token> tokens, ErrorHandler errorHandler) {
        this.errorHandler = errorHandler;
        this.tokens = tokens;
        parse_CompUnit(compUnit);
    }

    public void printResult() {
        compUnit.print(stdWriter);
    }

    public Node getCompUnit() {
        return compUnit;
    }

    private boolean match(TokenType type) {  // 匹配类型
        if (tokens.isEmpty()) {
            return false;
        } else if (tokens.get(pos).getType() == type) {
            token = tokens.get(pos);
            pos++;
            return true;
        } else {
            return false;
        }
    }

    private void unmatch(int n) {
        pos -= n;
    }

    private void parse_CompUnit(Node father) {
        int prevPos;
        while (true) {
            prevPos = pos;
            if (match(TokenType.CONSTTK)) {
                // 匹配到const
                unmatch(1);
                parse_Decl(father);
            } else if ((match(TokenType.INTTK) || match(TokenType.CHARTK)) && match(TokenType.IDENFR) &&
                    (match(TokenType.ASSIGN) || match(TokenType.LBRACK) || match(TokenType.COMMA) || match(TokenType.SEMICN))) {
                // 匹配到int或char，然后匹配到标识符，然后匹配到等号或左中括号
                unmatch(3);
                parse_Decl(father);
            } else {
                pos = prevPos;
                break;
            }
        }
        while (true) {
            prevPos = pos;
            if ((match(TokenType.INTTK) || match(TokenType.CHARTK) || match(TokenType.VOIDTK)) && match(TokenType.IDENFR)) {
                // 匹配到int、char或void，然后匹配到标识符
                unmatch(2);
                Node node = father.addNewNode(NodeType.FuncDef);
                parse_FuncDef(node);
            } else {
                pos = prevPos;
                break;
            }
        }
        Node node = father.addNewNode(NodeType.MainFuncDef);
        parse_MainFunDef(node);
    }

    private void parse_Decl(Node father) {
        if (match(TokenType.CONSTTK)) { // 匹配到const
            unmatch(1);
            Node node = father.addNewNode(NodeType.ConstDecl);
            parse_ConstDecl(node);
        } else {
            Node node = father.addNewNode(NodeType.VarDecl);
            parse_VarDecl(node);
        }
    }

    private void parse_FuncDef(Node father) {
        Node node = father.addNewNode(NodeType.FuncType);
        parse_FuncType(node);
        match(TokenType.IDENFR);
        father.addToken(token);
        match(TokenType.LPARENT);
        father.addToken(token);
        int prevPos = pos;
        if (match(TokenType.RPARENT)) {
            father.addToken(token);
        } else if (match_FuncFParams()) {
            pos = prevPos;
            Node node1 = father.addNewNode(NodeType.FuncFParams);
            parse_FuncFParams(node1);
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else { // 缺少右小括号的错误处理
                errorHandler.addError('j', token.getLine());
                father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
            }
        } else {
            pos = prevPos;
            errorHandler.addError('j', token.getLine());
            father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
        }
        Node node2 = father.addNewNode(NodeType.Block);
        parse_Block(node2);
    }

    private void parse_FuncType(Node father) {
        if (match(TokenType.INTTK) || match(TokenType.CHARTK) || match(TokenType.VOIDTK)) {
            father.addToken(token);
        }
    }

    private void parse_ConstDecl(Node father) {
        match(TokenType.CONSTTK);
        father.addToken(token);
        if (match(TokenType.INTTK)) {
            father.addToken(token);
        } else if (match(TokenType.CHARTK)) {
            father.addToken(token);
        }
        Node node = father.addNewNode(NodeType.ConstDef);
        parse_ConstDef(node);
        while (match(TokenType.COMMA)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.ConstDef);
            parse_ConstDef(node1);
        }
        if (match(TokenType.SEMICN)) {
            father.addToken(token);
        } else {  // 缺少分号的错误处理
            errorHandler.addError('i', token.getLine());
            father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
        }
    }

    private void parse_ConstDef(Node father) {
        match(TokenType.IDENFR);
        father.addToken(token);
        if (match(TokenType.LBRACK)) {
            father.addToken(token);
            Node node = father.addNewNode(NodeType.ConstExp);
            parse_Exp(node);
            if (match(TokenType.RBRACK)) {
                father.addToken(token);
            } else { // 缺少右中括号的错误处理
                errorHandler.addError('k', token.getLine());
                father.addToken(new Token(TokenType.RBRACK, "]", token.getLine()));

            }
        }
        match(TokenType.ASSIGN);
        father.addToken(token);
        Node node1 = father.addNewNode(NodeType.ConstInitVal);
        parse_ConstInitVal(node1);
    }

    private void parse_ConstInitVal(Node father) {
        if (match(TokenType.STRCON)) {
            father.addToken(token);
        } else if (match(TokenType.LBRACE)) {
            father.addToken(token);
            if (match(TokenType.RBRACE)) {
                father.addToken(token);
            } else {
                Node node = father.addNewNode(NodeType.ConstExp);
                parse_ConstExp(node);
                while (match(TokenType.COMMA)) {
                    father.addToken(token);
                    Node node1 = father.addNewNode(NodeType.ConstExp);
                    parse_ConstExp(node1);
                }
                match(TokenType.RBRACE);
                father.addToken(token);
            }
        } else {
            Node node = father.addNewNode(NodeType.ConstExp);
            parse_ConstExp(node);
        }
    }

    private void parse_ConstExp(Node father) {
        Node node = father.addNewNode(NodeType.AddExp);
        parse_addExp(node);
    }

    private void parse_VarDecl(Node father) {
        if (match(TokenType.INTTK) || match(TokenType.CHARTK)) {
            father.addToken(token);
        }
        Node node = father.addNewNode(NodeType.VarDef);
        parse_VarDef(node);
        while (match(TokenType.COMMA)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.VarDef);
            parse_VarDef(node1);
        }
        if (match(TokenType.SEMICN)) {
            father.addToken(token);
        } else { // 缺少分号的错误处理
            errorHandler.addError('i', token.getLine());
            father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
        }
    }

    private void parse_VarDef(Node father) {
        match(TokenType.IDENFR);
        father.addToken(token);
        if (match(TokenType.LBRACK)) {
            father.addToken(token);
            Node node = father.addNewNode(NodeType.ConstExp);
            parse_ConstExp(node);
            if (match(TokenType.RBRACK)) {
                father.addToken(token);
            } else { // 缺少右中括号的错误处理
                errorHandler.addError('k', token.getLine());
                father.addToken(new Token(TokenType.RBRACK, "]", token.getLine()));
            }
        }
        if (match(TokenType.ASSIGN)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.InitVal);
            parse_InitVal(node1);
        }
    }

    private void parse_InitVal(Node father) {
        if (match(TokenType.LBRACE)) {
            father.addToken(token);
            if (match(TokenType.RBRACE)) {
                father.addToken(token);
            } else {
                Node node = father.addNewNode(NodeType.Exp);
                parse_Exp(node);
                while (match(TokenType.COMMA)) {
                    father.addToken(token);
                    Node node1 = father.addNewNode(NodeType.Exp);
                    parse_Exp(node1);
                }
                match(TokenType.RBRACE);
                father.addToken(token);
            }
        } else if (match(TokenType.STRCON)) {
            father.addToken(token);
        } else {
            Node node = father.addNewNode(NodeType.Exp);
            parse_Exp(node);
        }
    }

    private void parse_MainFunDef(Node father) {
        match(TokenType.INTTK);
        father.addToken(token);
        match(TokenType.MAINTK);
        father.addToken(token);
        match(TokenType.LPARENT);
        father.addToken(token);
        if (match(TokenType.RPARENT)) {
            father.addToken(token);
        } else { // 缺少右小括号的错误处理
            errorHandler.addError('j', token.getLine());
            father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
        }
        Node node = father.addNewNode(NodeType.Block);
        parse_Block(node);
    }

    private void parse_Block(Node father) {
        match(TokenType.LBRACE);
        father.addToken(token);
        while (true) {
            if (match(TokenType.RBRACE)) {
                father.addToken(token);
                break;
            } else if (match(TokenType.INTTK) || match(TokenType.CHARTK) || match(TokenType.CONSTTK)) {
                unmatch(1);
                parse_Decl(father);
            } else {
                Node node = father.addNewNode(NodeType.Stmt);
                parse_Stmt(node);
            }
        }
    }

    private void parse_Stmt(Node father) {  // 解析方法较为特殊,也许可优化？
        int prevPos = pos;
        if (match(TokenType.IFTK)) {       // if语句
            father.addToken(token);
            match(TokenType.LPARENT);
            father.addToken(token);
            Node node = father.addNewNode(NodeType.Cond);
            parse_Cond(node);
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else { // 缺少右小括号的错误处理
                errorHandler.addError('j', token.getLine());
                father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
            }
            Node node1 = father.addNewNode(NodeType.Stmt);
            parse_Stmt(node1);
            if (match(TokenType.ELSETK)) {
                father.addToken(token);
                Node node2 = father.addNewNode(NodeType.Stmt);
                parse_Stmt(node2);
            }
        } else if (match(TokenType.FORTK)) {   // for语句
            father.addToken(token);
            match(TokenType.LPARENT);
            father.addToken(token);
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else {
                Node node = father.addNewNode(NodeType.ForStmt);
                parse_ForStmt(node);
                match(TokenType.SEMICN);
                father.addToken(token);
            }
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else {
                Node node1 = father.addNewNode(NodeType.Cond);
                parse_Cond(node1);
                match(TokenType.SEMICN);
                father.addToken(token);
            }
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else {
                Node node2 = father.addNewNode(NodeType.ForStmt);
                parse_ForStmt(node2);
                match(TokenType.RPARENT);
                father.addToken(token);
            }
            Node node3 = father.addNewNode(NodeType.Stmt);
            parse_Stmt(node3);
        } else if (match(TokenType.BREAKTK) || match(TokenType.CONTINUETK)) { // break或continue语句
            father.addToken(token);
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else { // 缺少分号的错误处理
                errorHandler.addError('i', token.getLine());
                father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
            }
        } else if (match(TokenType.RETURNTK)) {  // return语句
            father.addToken(token);
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else {
                if (match_AddExp()) {
                    pos = prevPos;
                    match(TokenType.RETURNTK);
                    Node node = father.addNewNode(NodeType.Exp);
                    parse_Exp(node);
                    if (match(TokenType.SEMICN)) {
                        father.addToken(token);
                    } else {
                        errorHandler.addError('i', token.getLine());
                        father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
                    }
                } else {
                    pos = prevPos;
                    match(TokenType.RETURNTK);
                    errorHandler.addError('i', token.getLine());
                    father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
                }
            }
        } else if (match(TokenType.PRINTFTK)) { // printf语句
            father.addToken(token);
            match(TokenType.LPARENT);
            father.addToken(token);
            match(TokenType.STRCON);
            father.addToken(token);
            while (match(TokenType.COMMA)) {
                father.addToken(token);
                Node node = father.addNewNode(NodeType.Exp);
                parse_Exp(node);
            }
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else { // 缺少右小括号的错误处理
                errorHandler.addError('j', token.getLine());
                father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
            }
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else {
                errorHandler.addError('i', token.getLine());
                father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
            }
        } else if (match(TokenType.LBRACE)) { // 大括号
            unmatch(1);
            Node node = father.addNewNode(NodeType.Block);
            parse_Block(node);
        } else if (match_LVal() && match(TokenType.ASSIGN)) {  // 赋值语句
            pos = prevPos;
            Node node = father.addNewNode(NodeType.LVal);
            parse_LVal(node);
            match(TokenType.ASSIGN);
            father.addToken(token);
            if (match(TokenType.GETINTTK) || match(TokenType.GETCHARTK)) {
                father.addToken(token);
                match(TokenType.LPARENT);
                father.addToken(token);
                if (match(TokenType.RPARENT)) {
                    father.addToken(token);
                } else { // 缺少右小括号的错误处理
                    errorHandler.addError('j', token.getLine());
                    father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
                }
            } else {
                Node node1 = father.addNewNode(NodeType.Exp);
                parse_Exp(node1);
            }
            if (match(TokenType.SEMICN)) {
                father.addToken(token);
            } else { // 缺少分号的错误处理
                errorHandler.addError('i', token.getLine());
                father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
            }
        } else {
            pos = prevPos;
            if (match(TokenType.SEMICN)) { // 表达式语句
                father.addToken(token);
            } else {
                Node node = father.addNewNode(NodeType.Exp);
                parse_Exp(node);
                if (match(TokenType.SEMICN)) {
                    father.addToken(token);
                } else { // 缺少分号的错误处理
                    errorHandler.addError('i', token.getLine());
                    father.addToken(new Token(TokenType.SEMICN, ";", token.getLine()));
                }
            }
        }
    }

    private void parse_Exp(Node father) {
        Node node = father.addNewNode(NodeType.AddExp);
        parse_addExp(node);
    }

    private void parse_addExp(Node father) {
        Node node = father.addNewNode(NodeType.MulExp);
        parse_MulExp(node);
        while (match(TokenType.PLUS) || match(TokenType.MINU)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.MulExp);
            parse_MulExp(node1);
        }
    }

    private void parse_MulExp(Node father) {
        Node node = father.addNewNode(NodeType.UnaryExp);
        parse_UnaryExp(node);
        while (match(TokenType.MULT) || match(TokenType.DIV) || match(TokenType.MOD)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.UnaryExp);
            parse_UnaryExp(node1);

        }
    }

    private void parse_UnaryExp(Node father) {
        int prevPos = pos;
        if (match(TokenType.PLUS) || match(TokenType.MINU) || match(TokenType.NOT)) {
            unmatch(1);
            Node node = father.addNewNode(NodeType.UnaryOp);
            parse_UnaryOp(node);
            Node node1 = father.addNewNode(NodeType.UnaryExp);
            parse_UnaryExp(node1);
        } else if (match(TokenType.IDENFR) && match(TokenType.LPARENT)) {
            unmatch(2);
            match(TokenType.IDENFR);
            father.addToken(token);
            match(TokenType.LPARENT);
            father.addToken(token);
            prevPos = pos;
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else if (match_FuncRParams()) {
                pos = prevPos;
                Node node = father.addNewNode(NodeType.FuncRParams);
                parse_FuncRParams(node);
                if (match(TokenType.RPARENT)) {
                    father.addToken(token);
                } else if (match_FuncRParams()) { // 缺少右小括号的错误处理
                    errorHandler.addError('j', token.getLine());
                    father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
                }
            } else {
                pos = prevPos;
                errorHandler.addError('j', token.getLine());
                father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
            }
        } else {
            pos = prevPos;
            Node node = father.addNewNode(NodeType.PrimaryExp);
            parse_PrimaryExp(node);
        }
    }

    private void parse_UnaryOp(Node father) {
        if (match(TokenType.PLUS) || match(TokenType.MINU) || match(TokenType.NOT)) {
            father.addToken(token);
        }
    }

    private void parse_PrimaryExp(Node father) {
        if (match(TokenType.LPARENT)) {
            father.addToken(token);
            Node node = father.addNewNode(NodeType.Exp);
            parse_Exp(node);
            if (match(TokenType.RPARENT)) {
                father.addToken(token);
            } else { // 缺少右小括号的错误处理
                errorHandler.addError('j', token.getLine());
                father.addToken(new Token(TokenType.RPARENT, ")", token.getLine()));
            }
        } else if (match(TokenType.INTCON)) {
            unmatch(1);
            Node node = father.addNewNode(NodeType.Number);
            parse_Number(node);
        } else if (match(TokenType.CHRCON)) {
            unmatch(1);
            Node node = father.addNewNode(NodeType.Character);
            parse_Character(node);
        } else {
            Node node = father.addNewNode(NodeType.LVal);
            parse_LVal(node);
        }
    }


    private void parse_LVal(Node father) {
        match(TokenType.IDENFR);
        father.addToken(token);
        if (match(TokenType.LBRACK)) {
            father.addToken(token);
            Node node = father.addNewNode(NodeType.Exp);
            parse_Exp(node);
            if (match(TokenType.RBRACK)) {
                father.addToken(token);
            } else { // 缺少右中括号的错误处理
                errorHandler.addError('k', token.getLine());
                father.addToken(new Token(TokenType.RBRACK, "]", token.getLine()));
            }
        }
    }

    private void parse_Cond(Node father) {
        Node node = father.addNewNode(NodeType.LOrExp);
        parse_LOrExp(node);
    }

    private void parse_LOrExp(Node father) {
        Node node = father.addNewNode(NodeType.LAndExp);
        parse_LAndExp(node);
        while (match(TokenType.OR)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.LAndExp);
            parse_LAndExp(node1);
        }
    }

    private void parse_LAndExp(Node father) {
        Node node = father.addNewNode(NodeType.EqExp);
        parse_EqExp(node);
        while (match(TokenType.AND)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.EqExp);
            parse_EqExp(node1);
        }
    }

    private void parse_EqExp(Node father) {
        Node node = father.addNewNode(NodeType.RelExp);
        parse_RelExp(node);
        while (match(TokenType.EQL) || match(TokenType.NEQ)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.RelExp);
            parse_RelExp(node1);
        }
    }

    private void parse_RelExp(Node father) {
        Node node = father.addNewNode(NodeType.AddExp);
        parse_addExp(node);
        while (match(TokenType.LSS) || match(TokenType.LEQ) || match(TokenType.GRE) || match(TokenType.GEQ)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.AddExp);
            parse_addExp(node1);
        }
    }

    private void parse_FuncFParams(Node father) {
        Node node = father.addNewNode(NodeType.FuncFParam);
        parse_FuncFParam(node);
        while (match(TokenType.COMMA)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.FuncFParam);
            parse_FuncFParam(node1);
        }
    }

    private void parse_FuncFParam(Node father) {
        if (match(TokenType.INTTK) || match(TokenType.CHARTK)) {
            father.addToken(token);
        }
        match(TokenType.IDENFR);
        father.addToken(token);
        if (match(TokenType.LBRACK)) {
            father.addToken(token);
            if (match(TokenType.RBRACK)) {
                father.addToken(token);
            } else { // 缺少右中括号的错误处理
                errorHandler.addError('k', token.getLine());
                father.addToken(new Token(TokenType.RBRACK, "]", token.getLine()));
            }
        }
    }

    private void parse_FuncRParams(Node father) {
        Node node = father.addNewNode(NodeType.Exp);
        parse_Exp(node);
        while (match(TokenType.COMMA)) {
            father.addToken(token);
            Node node1 = father.addNewNode(NodeType.Exp);
            parse_Exp(node1);
        }
    }

    private void parse_ForStmt(Node father) {
        Node node = father.addNewNode(NodeType.LVal);
        parse_LVal(node);
        match(TokenType.ASSIGN);
        father.addToken(token);
        Node node1 = father.addNewNode(NodeType.Exp);
        parse_Exp(node1);
    }

    private void parse_Number(Node father) {
        match(TokenType.INTCON);
        father.addToken(token);
    }

    private void parse_Character(Node father) {
        match(TokenType.CHRCON);
        father.addToken(token);
    }

    private boolean match_LVal() {
        if (!match(TokenType.IDENFR)) {
            return false;
        }
        if (match(TokenType.LBRACK)) {
            if (match_AddExp()) {
                match(TokenType.RBRACK);
            } else {
                return false;
            }
        }
        return true;
    }

    private boolean match_AddExp() {
        if (!match_MulExp()) {
            return false;
        }
        while (match(TokenType.PLUS) || match(TokenType.MINU)) {
            if (!match_MulExp()) {
                return false;
            }
        }
        return true;
    }

    private boolean match_MulExp() {
        if (!match_UnaryExp()) {
            return false;
        }
        while (match(TokenType.MULT) || match(TokenType.DIV) || match(TokenType.MOD)) {
            if (!match_UnaryExp()) {
                return false;
            }
        }
        return true;
    }

    private boolean match_UnaryExp() {
        int prevPos = pos;
        if (match(TokenType.PLUS) || match(TokenType.MINU) || match(TokenType.NOT)) {
            return match_UnaryExp();
        } else if (match(TokenType.IDENFR) && match(TokenType.LPARENT)) {
            if (!match(TokenType.RPARENT)) {
                if (!match_FuncRParams()) {
                    return false;
                }
                match(TokenType.RPARENT);
                return true;
            }
            return true;
        } else {
            pos = prevPos;
            return match_PrimaryExp();
        }
    }

    private boolean match_FuncRParams() {
        if (!match_AddExp()) {
            return false;
        }
        while (match(TokenType.COMMA)) {
            if (!match_AddExp()) {
                return false;
            }
        }
        return true;
    }

    private boolean match_PrimaryExp() {
        if (match(TokenType.LPARENT)) {
            if (!match_AddExp()) {
                return false;
            }
            match(TokenType.RPARENT);
        } else if (match(TokenType.INTCON)) {
            return true;
        } else if (match(TokenType.CHRCON)) {
            return true;
        } else return match_LVal();
        return true;
    }

    private boolean match_FuncFParams() {
        if (!match_FuncFParam()) {
            return false;
        }
        while (match(TokenType.COMMA)) {
            if (!match_FuncFParam()) {
                return false;
            }
        }
        return true;
    }

    private boolean match_FuncFParam() {
        if (match(TokenType.INTTK) || match(TokenType.CHARTK)) {
            if (!match(TokenType.IDENFR)) {
                return false;
            }
            if (match(TokenType.LBRACK)) {
                match(TokenType.RBRACK);
            }
        } else {
            return false;
        }
        return true;
    }
}
