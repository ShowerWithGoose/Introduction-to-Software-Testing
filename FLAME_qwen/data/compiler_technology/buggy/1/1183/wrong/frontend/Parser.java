package frontend;

import error.Err;
import frontend.Node.LeafNode;
import frontend.Node.Node;
import frontend.Node.ParType;
import frontend.Token.LexType;
import frontend.Token.Token;

import java.util.ArrayList;
import java.util.ListIterator;

public class Parser {
    private ArrayList<Token> tokens;
    private ListIterator<Token> iter;
    private Token now;
    private ArrayList<Err> errorList;

    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.iter = tokens.listIterator();
        this.now = null;
        this.errorList = null;
    }

    public Node parseCompUnit(ArrayList<Err> errorList) { // CompUnit → {Decl} {FuncDef} MainFuncDef
        this.errorList = errorList;
        Node rootNode = new Node(ParType.CompUnit);
        if (iter.hasNext()) {
            next();
            while (now.getLexType() == LexType.CONSTTK || now.getLexType().isBType()) { // 解析Decl
                if (now.getLexType() == LexType.CONSTTK) {
                    Node decl = parseDecl();
                    decl.setParentNode(rootNode);
                    rootNode.addChildNode(decl);
                } else if (preRead() == LexType.IDENFR && pre2Read() != LexType.LPARENT) {
                    Node decl = parseDecl();
                    decl.setParentNode(rootNode);
                    rootNode.addChildNode(decl);
                } else {
                    break;
                }
            }
            while (preRead() == LexType.IDENFR) { // 解析FuncDef
                Node funcDef = parseFuncDef();
                funcDef.setParentNode(rootNode);
                rootNode.addChildNode(funcDef);
            }
            Node mainFuncDef = parseMainFuncDef(); // 解析MainFuncDef
            mainFuncDef.setParentNode(rootNode);
            rootNode.addChildNode(mainFuncDef);
        }
        return rootNode;
    }

    private Node parseDecl() { // Decl → ConstDecl | VarDecl
        Node decl = new Node(ParType.Decl);
        if (now.getLexType() == LexType.CONSTTK) {
            Node constDecl = parseConstDecl();
            constDecl.setParentNode(decl);
            decl.addChildNode(constDecl);
        }
        else {
            Node constDecl = parseVarDecl();
            constDecl.setParentNode(decl);
            decl.addChildNode(constDecl);
        }
        return decl;
    }

    private Node parseConstDecl() { // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        return parseDeclaration(ParType.ConstDecl, true); // true 表示是常量声明
    }

    private Node parseConstDef() { // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        return parseDefinition(ParType.ConstDef);
    }

    private Node parseConstInitVal() { // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        return parseInitValue(ParType.ConstInitVal);
    }

    private Node parseVarDecl() { // VarDecl → BType VarDef { ',' VarDef } ';'
        return parseDeclaration(ParType.VarDecl, false); // false 表示不是常量声明
    }

    private Node parseVarDef() { //  VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        return parseDefinition(ParType.VarDef);
    }

    private Node parseInitVal() { //  InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        return parseInitValue(ParType.InitVal);
    }

    private Node parseFuncDef() { //  FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        Node funcDef = new Node(ParType.FuncDef);
        Node funcType = parseFuncType();
        funcType.setParentNode(funcType);
        funcDef.addChildNode(funcType);
        LeafNode ident = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcDef);
        funcDef.addChildNode(ident);
        next(); // 默认此处一定有后一项，warning！！！
        LeafNode lParent = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcDef);
        funcDef.addChildNode(lParent);
        next(); // 默认此处一定有后一项，warning！！！
        if (now.getLexType().isBType()) {
            Node funcFParams = parseFuncFParams();
            funcFParams.setParentNode(funcDef);
            funcDef.addChildNode(funcFParams);
        }
        if (now.getLexType() == LexType.RPARENT) {
            LeafNode rParent = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcDef);
            funcDef.addChildNode(rParent);
            next();
        }
        else { // j:缺少右小括号，不需要改变now
            int num = lastNum();
            LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,funcDef);
            funcDef.addChildNode(rParent);
            errorList.add(new Err(num,"j"));
        }
        Node block = parseBlock();
        block.setParentNode(funcDef);
        funcDef.addChildNode(block);
        return funcDef;
    }

    private Node parseMainFuncDef() { // MainFuncDef → 'int' 'main' '(' ')' Block
        Node mainFuncDef = new Node(ParType.MainFuncDef);
        for (int i = 0; i < 3; i++){ // int main ( )
            LeafNode lex = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), mainFuncDef);
            mainFuncDef.addChildNode(lex);
            next(); // 默认此处一定有后一项，warning！！！
        }
        if (now.getLexType() == LexType.RPARENT) {
            LeafNode rParent = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),mainFuncDef);
            mainFuncDef.addChildNode(rParent);
            next();
        }
        else { // j:缺少右小括号，不需要改变now
            int num = lastNum();
            LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,mainFuncDef);
            mainFuncDef.addChildNode(rParent);
            errorList.add(new Err(num,"j"));
        }
        Node block = parseBlock();
        block.setParentNode(mainFuncDef);
        mainFuncDef.addChildNode(block);
        return mainFuncDef;
    }

    private Node parseFuncType() { // FuncType → 'void' | 'int' | 'char'
        Node funcType = new Node(ParType.FuncType);
        LeafNode leaf = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcType);
        funcType.addChildNode(leaf);
        next();
        return funcType;
    }

    private Node parseFuncFParams() { // FuncFParams → FuncFParam { ',' FuncFParam }
        return parseFuncParams(ParType.FuncFParams);
    }

    private Node parseFuncFParam() { // FuncFParam → BType Ident ['[' ']']
        Node funcFParam = new Node(ParType.FuncFParam);
        Node bType = parseBType();
        bType.setParentNode(funcFParam);
        funcFParam.addChildNode(bType);
        LeafNode ident = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcFParam);
        next();
        funcFParam.addChildNode(ident);
        if (now.getLexType() == LexType.LBRACK) {
            LeafNode lBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcFParam);
            funcFParam.addChildNode(lBracket);
            next();
            if (now.getLexType() == LexType.RBRACK) {
                LeafNode rBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcFParam);
                funcFParam.addChildNode(rBracket);
                next();
            }
            else { // k:右括号缺失，无需next
                int num = lastNum();
                LeafNode rBracket = new LeafNode(num,"]",0,LexType.RBRACK,funcFParam);
                funcFParam.addChildNode(rBracket);
                errorList.add(new Err(num,"k"));
            }
        }
        return funcFParam;
    }

    private Node parseBlock() { //  Block → '{' { BlockItem } '}'
        Node block = new Node(ParType.Block);
        LeafNode lBrace = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),block);
        next();
        block.addChildNode(lBrace);
        while (now.getLexType() != LexType.RBRACE) {
            Node blockItem = parseBlockItem();
            blockItem.setParentNode(block);
            block.addChildNode(blockItem);
        }
        LeafNode rBrace = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),block);
        block.addChildNode(rBrace);
        if (iter.hasNext()) {
            next();
        }
        return block;
    }

    private Node parseBlockItem() { // BlockItem → Decl | Stmt
        Node blockItem = new Node(ParType.BlockItem);
        if (now.getLexType() == LexType.CONSTTK || now.getLexType().isBType()) {
            Node decl = parseDecl();
            decl.setParentNode(blockItem);
            blockItem.addChildNode(decl);
        }
        else {
            Node stmt = parseStmt();
            stmt.setParentNode(blockItem);
            blockItem.addChildNode(stmt);
        }
        return blockItem;
    }

    private Node parseStmt() {
        Node stmt = new Node(ParType.Stmt);
        if (now.getLexType() == LexType.IDENFR && preRead() != LexType.LPARENT && hasAssign()) {
            Node lVal = parseLVal();
            lVal.setParentNode(stmt);
            stmt.addChildNode(lVal);
            LeafNode equal = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(equal);
            next();
            if (now.getLexType() == LexType.GETCHARTK || now.getLexType() == LexType.GETINTTK) {
                for (int i = 0; i < 2; i++) {
                    LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                    stmt.addChildNode(lex);
                    next();
                }
                if (now.getLexType() == LexType.RPARENT) {
                    LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                    stmt.addChildNode(rParent);
                    next();
                }
                else { // j:缺少右括号
                    int num = lastNum();
                    LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,stmt);
                    stmt.addChildNode(rParent);
                    errorList.add(new Err(num,"j"));
                }
                if (now.getLexType() == LexType.SEMICN) {
                    LeafNode semicn = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                    stmt.addChildNode(semicn);
                    next();
                }
                else { // i:缺少分号
                    int num = lastNum();
                    LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                    stmt.addChildNode(semicn);
                    errorList.add(new Err(num,"i"));
                }
            }
            else {
                Node exp = parseExp();
                exp.setParentNode(stmt);
                stmt.addChildNode(exp);
                if (now.getLexType() == LexType.SEMICN) {
                    LeafNode semicn = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                    stmt.addChildNode(semicn);
                    next();
                }
                else { // i:缺少分号
                    int num = lastNum();
                    LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                    stmt.addChildNode(semicn);
                    errorList.add(new Err(num,"i"));  // 错误的报错
                }
            }
        }
        else if (now.getLexType() == LexType.LBRACE) {
            Node block = parseBlock();
            block.setParentNode(stmt);
            stmt.addChildNode(block);
        }
        else if (now.getLexType() == LexType.IFTK) { //  'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            for (int i = 0; i < 2; i++) {
                LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(lex);
                next();
            }
            Node cond = parseCond();
            cond.setParentNode(stmt);
            stmt.addChildNode(cond);
            if (now.getLexType() == LexType.RPARENT) {
                LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(rParent);
                next();
            }
            else { // j:缺少右括号
                int num = lastNum();
                LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,stmt);
                stmt.addChildNode(rParent);
                errorList.add(new Err(num,"j"));
            }
            Node stmt1 = parseStmt();
            stmt1.setParentNode(stmt);
            stmt.addChildNode(stmt1);
            if (now.getLexType() == LexType.ELSETK) {
                LeafNode els = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(els);
                next();
                stmt1 = parseStmt();
                stmt1.setParentNode(stmt);
                stmt.addChildNode(stmt1);
            }
        }
        else if (now.getLexType() == LexType.FORTK) { //  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            for (int i = 0; i < 2; i++) {
                LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(lex);
                next();
            }
            if (now.getLexType() != LexType.SEMICN) {
                Node forStmt = parseForStmt();
                forStmt.setParentNode(stmt);
                stmt.addChildNode(forStmt);
            }
            LeafNode semicn = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(semicn);
            next();
            if (now.getLexType() != LexType.SEMICN) {
                Node cond = parseCond();
                cond.setParentNode(stmt);
                stmt.addChildNode(cond);
            }
            semicn = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(semicn);
            next();
            if (now.getLexType() != LexType.RPARENT) {
                Node forStmt = parseForStmt();
                forStmt.setParentNode(stmt);
                stmt.addChildNode(forStmt);
            }
            if (now.getLexType() == LexType.RPARENT) {
                LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(rParent);
                next();
            }
            else { // j:缺少右括号
                int num = lastNum();
                LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,stmt);
                stmt.addChildNode(rParent);
                errorList.add(new Err(num,"j"));
            }
            Node stmt1 = parseStmt();
            stmt1.setParentNode(stmt);
            stmt.addChildNode(stmt1);
        }
        else if (now.getLexType() == LexType.BREAKTK || now.getLexType() == LexType.CONTINUETK) { //  'break' ';' | 'continue' ';'
            LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(lex);
            next();
            if (now.getLexType() == LexType.SEMICN) {
                LeafNode semicn = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(semicn);
                next();
            }
            else { // i:缺少分号
                int num = lastNum();
                LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                stmt.addChildNode(semicn);
                errorList.add(new Err(num,"i"));
            }
        }
        else if (now.getLexType() == LexType.RETURNTK) { //  'return' [Exp] ';'
            LeafNode ret = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(ret);
            next();
            if (now.getLexType() == LexType.IDENFR || now.getLexType() == LexType.LPARENT ||
            now.getLexType() == LexType.INTCON || now.getLexType() == LexType.CHRCON ||
            now.getLexType() == LexType.PLUS || now.getLexType() == LexType.MINU) {
                Node exp = parseExp();
                exp.setParentNode(stmt);
                stmt.addChildNode(exp);
            }
            if (now.getLexType() == LexType.SEMICN) {
                LeafNode semicn = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(semicn);
                next();
            }
            else { // i:缺少分号
                int num = lastNum();
                LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                stmt.addChildNode(semicn);
                errorList.add(new Err(num,"i"));
            }
        }
        else if (now.getLexType() == LexType.PRINTFTK) { // 'printf''('StringConst {','Exp}')'';'
            for (int i = 0; i < 2; i++) {
                LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(lex);
                next();
            }
            LeafNode stringConst = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
            stmt.addChildNode(stringConst);
            next();
            while (now.getLexType() == LexType.COMMA) {
                LeafNode comma = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(comma);
                next();
                Node exp = parseExp();
                exp.setParentNode(stmt);
                stmt.addChildNode(exp);
            }
            if (now.getLexType() == LexType.RPARENT) {
                LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(rParent);
                next();
            }
            else { // j:缺少右括号
                int num = lastNum();
                LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,stmt);
                stmt.addChildNode(rParent);
                errorList.add(new Err(num,"j"));
            }
            if (now.getLexType() == LexType.SEMICN) {
                LeafNode semicn = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),stmt);
                stmt.addChildNode(semicn);
                next();
            }
            else { // i:缺少分号
                int num = lastNum();
                LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                stmt.addChildNode(semicn);
                errorList.add(new Err(num,"i"));
            }
        }
        else { // [Exp] ';'
            if (now.getLexType() != LexType.SEMICN) {
                Node exp = parseExp();
                exp.setParentNode(stmt);
                stmt.addChildNode(exp);
            }
            if (now.getLexType() == LexType.SEMICN) {
                LeafNode semicn = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), stmt);
                stmt.addChildNode(semicn);
                next();
            }
            else { // i:缺少分号
                int num = lastNum();
                LeafNode semicn = new LeafNode(num,";",0,LexType.SEMICN,stmt);
                stmt.addChildNode(semicn);
                errorList.add(new Err(num,"i")); // 错误的报错
            }
        }
        return stmt;
    }

    private Node parseForStmt() { // ForStmt → LVal '=' Exp
        Node forStmt = new Node(ParType.ForStmt);
        Node lVal = parseLVal();
        lVal.setParentNode(forStmt);
        forStmt.addChildNode(lVal);
        LeafNode lex = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),forStmt);
        forStmt.addChildNode(lex);
        next();
        Node exp = parseExp();
        exp.setParentNode(forStmt);
        forStmt.addChildNode(exp);
        return forStmt;
    }

    private Node parseExp() { // Exp → AddExp
        Node exp = new Node(ParType.Exp);
        Node addExp = parseAddExp();
        addExp.setParentNode(exp);
        exp.addChildNode(addExp);
        return exp;
    }

    private Node parseCond() { // Cond → LOrExp
        Node cond = new Node(ParType.Cond);
        Node lOrExp = parseLOrExp();
        lOrExp.setParentNode(cond);
        cond.addChildNode(lOrExp);
        return cond;
    }

    private Node parseLVal() { // LVal → Ident ['[' Exp ']']
        Node lVal = new Node(ParType.LVal);
        LeafNode ident = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),lVal);
        lVal.addChildNode(ident);
        next();
        if (now.getLexType() == LexType.LBRACK) {
            LeafNode lBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),lVal);
            lVal.addChildNode(lBracket);
            next();
            Node exp = parseExp();
            exp.setParentNode(lVal);
            lVal.addChildNode(exp);
            if (now.getLexType() == LexType.RBRACK) {
                LeafNode rBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),lVal);
                lVal.addChildNode(rBracket);
                next();
            }
            else { // k:右括号缺失，无需next
                int num = lastNum();
                LeafNode rBracket = new LeafNode(num,"]",0,LexType.RBRACK,lVal);
                lVal.addChildNode(rBracket);
                errorList.add(new Err(num,"k"));
            }
        }
        return lVal;
    }

    private Node parsePrimaryExp() { // PrimaryExp → '(' Exp ')' | LVal | Number | Character
        Node primaryExp = new Node(ParType.PrimaryExp);
        if (now.getLexType() == LexType.LPARENT) {
            LeafNode lParent = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),primaryExp);
            primaryExp.addChildNode(lParent);
            next();
            Node exp = parseExp();
            exp.setParentNode(primaryExp);
            primaryExp.addChildNode(exp);
            if (now.getLexType() == LexType.RPARENT) {
                LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), primaryExp);
                primaryExp.addChildNode(rParent);
                next();
            }
            else { // j:缺少右括号
                int num = lastNum();
                LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,primaryExp);
                primaryExp.addChildNode(rParent);
                errorList.add(new Err(num,"j"));
            }
        }
        else if (now.getLexType() == LexType.IDENFR) {
            Node lVal = parseLVal();
            lVal.setParentNode(primaryExp);
            primaryExp.addChildNode(lVal);
        }
        else if (now.getLexType() == LexType.INTCON) {
            Node number = parseNumber();
            number.setParentNode(primaryExp);
            primaryExp.addChildNode(number);
        }
        else {
            Node character = parseCharacter();
            character.setParentNode(primaryExp);
            primaryExp.addChildNode(character);
        }
        return primaryExp;
    }

    private Node parseNumber() {
        Node number = new Node(ParType.Number);
        LeafNode intConst = new LeafNode(now.getLineNum(),now.getName(),now.getNumber(),now.getLexType(),number);
        number.addChildNode(intConst);
        next();
        return number;
    }

    private Node parseCharacter() {
        Node character = new Node(ParType.Character);
        LeafNode charConst = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),character);
        character.addChildNode(charConst);
        next();
        return character;
    }

    private Node parseUnaryExp() { // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        Node unaryExp = new Node(ParType.UnaryExp);
        if (now.getLexType() == LexType.PLUS || now.getLexType() == LexType.MINU || now.getLexType() == LexType.NOT) {
            Node unaryOp = parseUnaryOp();
            unaryOp.setParentNode(unaryExp);
            unaryExp.addChildNode(unaryOp);
            Node unaryExp1 = parseUnaryExp();
            unaryExp1.setParentNode(unaryExp);
            unaryExp.addChildNode(unaryExp1);
        }
        else if (now.getLexType() == LexType.IDENFR && preRead() == LexType.LPARENT) {
            LeafNode ident = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),unaryExp);
            unaryExp.addChildNode(ident);
            next();
            LeafNode lParent = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),unaryExp);
            unaryExp.addChildNode(lParent);
            next();
            if (now.getLexType() == LexType.IDENFR || now.getLexType() == LexType.INTCON || now.getLexType() == LexType.CHRCON
                    || now.getLexType() == LexType.LPARENT || now.getLexType() == LexType.PLUS || now.getLexType() == LexType.MINU) { // unarayOp情况
                Node funcRParams = parseFuncRParams();
                funcRParams.setParentNode(unaryExp);
                unaryExp.addChildNode(funcRParams);
            }
            if (now.getLexType() == LexType.RPARENT) {
                LeafNode rParent = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), unaryExp);
                unaryExp.addChildNode(rParent);
                next();
            }
            else { // j:缺少右括号
                int num = lastNum();
                LeafNode rParent = new LeafNode(num,")",0,LexType.RPARENT,unaryExp);
                unaryExp.addChildNode(rParent);
                errorList.add(new Err(num,"j"));  // 错误的报错
            }
        }
        else {
            Node primaryExp = parsePrimaryExp();
            primaryExp.setParentNode(unaryExp);
            unaryExp.addChildNode(primaryExp);
        }
        return unaryExp;
    }

    private Node parseUnaryOp() { // UnaryOp → '+' | '−' | '!'
        Node unaryOp = new Node(ParType.UnaryOp);
        LeafNode op = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),unaryOp);
        next();
        unaryOp.addChildNode(op);
        return unaryOp;
    }

    private Node parseFuncRParams() { // FuncRParams → Exp { ',' Exp }
        return parseFuncParams(ParType.FuncRParams);
    }

    private Node parseMulExp() { // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        Node mulExp = new Node(ParType.MulExp);
        Node unaryExp = parseUnaryExp();
        unaryExp.setParentNode(mulExp);
        mulExp.addChildNode(unaryExp);
        while (now.getLexType() == LexType.MULT || now.getLexType() == LexType.DIV || now.getLexType() == LexType.MOD) {
            Node mulExp1 = mulExp;
            mulExp = new Node(ParType.MulExp);
            mulExp.addChildNode(mulExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),mulExp);
            mulExp.addChildNode(op);
            next();
            Node unaryExp1 = parseUnaryExp();
            unaryExp1.setParentNode(mulExp);
            mulExp.addChildNode(unaryExp1);
        }
        return mulExp;
    }

    private Node parseAddExp() { // AddExp → MulExp | AddExp ('+' | '−') MulExp
        Node addExp = new Node(ParType.AddExp);
        Node mulExp = parseMulExp();
        mulExp.setParentNode(addExp);
        addExp.addChildNode(mulExp);
        while (now.getLexType() == LexType.PLUS || now.getLexType() == LexType.MINU) {
            Node addExp1 = addExp;
            addExp = new Node(ParType.AddExp);
            addExp.addChildNode(addExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),addExp);
            addExp.addChildNode(op);
            next();
            Node mulExp1 = parseMulExp();
            mulExp1.setParentNode(addExp);
            addExp.addChildNode(mulExp1);
        }
        return addExp;
    }

    private Node parseRelExp() { //  RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        Node relExp = new Node(ParType.RelExp);
        Node addExp = parseAddExp();
        addExp.setParentNode(relExp);
        relExp.addChildNode(addExp);
        while (now.getLexType() == LexType.LSS || now.getLexType() == LexType.LEQ || now.getLexType() == LexType.GRE || now.getLexType() == LexType.GEQ) {
            Node relExp1 = relExp;
            relExp = new Node(ParType.RelExp);
            relExp.addChildNode(relExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),relExp);
            relExp.addChildNode(op);
            next();
            Node addExp1 = parseAddExp();
            addExp1.setParentNode(relExp);
            relExp.addChildNode(addExp1);
        }
        return relExp;
    }

    private Node parseEqExp() { // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        Node eqExp = new Node(ParType.EqExp);
        Node relExp = parseRelExp();
        relExp.setParentNode(eqExp);
        eqExp.addChildNode(relExp);
        while (now.getLexType() == LexType.EQL || now.getLexType() == LexType.NEQ) {
            Node eqExp1 = eqExp;
            eqExp = new Node(ParType.EqExp);
            eqExp.addChildNode(eqExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),eqExp);
            eqExp.addChildNode(op);
            next();
            Node relExp1 = parseRelExp();
            relExp1.setParentNode(eqExp);
            eqExp.addChildNode(relExp1);
        }
        return eqExp;
    }

    private Node parseLAndExp() { // LAndExp → EqExp | LAndExp '&&' EqExp
        Node lAndExp = new Node(ParType.LAndExp);
        Node eqExp = parseEqExp();
        eqExp.setParentNode(lAndExp);
        lAndExp.addChildNode(eqExp);
        while (now.getLexType() == LexType.AND) {
            Node lAndExp1 = lAndExp;
            lAndExp = new Node(ParType.LAndExp);
            lAndExp.addChildNode(lAndExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),lAndExp);
            lAndExp.addChildNode(op);
            next();
            Node eqExp1 = parseEqExp();
            eqExp1.setParentNode(lAndExp);
            lAndExp.addChildNode(eqExp1);
        }
        return lAndExp;
    }

    private Node parseLOrExp() { // LOrExp → LAndExp | LOrExp '||' LAndExp
        Node lOrExp = new Node(ParType.LOrExp);
        Node lAndExp = parseLAndExp();
        lAndExp.setParentNode(lOrExp);
        lOrExp.addChildNode(lAndExp);
        while (now.getLexType() == LexType.OR) {
            Node lOrExp1 = lOrExp;
            lOrExp = new Node(ParType.LOrExp);
            lOrExp.addChildNode(lOrExp1);
            LeafNode op = new LeafNode(now.getLineNum(), now.getName(),0,now.getLexType(),lOrExp);
            lOrExp.addChildNode(op);
            next();
            Node lAndExp1 = parseLAndExp();
            lAndExp1.setParentNode(lOrExp);
            lOrExp.addChildNode(lAndExp1);
        }
        return lOrExp;
    }

    private Node parseConstExp() { // ConstExp → AddExp
        Node constExp = new Node(ParType.ConstExp);
        Node addExp = parseAddExp();
        addExp.setParentNode(constExp);
        constExp.addChildNode(addExp);
        return constExp;
    }

    private Node parseFuncParams(ParType parType) {
        Node funcParams = new Node(parType);
        Node funcParam = (parType == ParType.FuncFParams) ? parseFuncFParam() : parseExp();
        funcParam.setParentNode(funcParams);
        funcParams.addChildNode(funcParam);
        while (now.getLexType() == LexType.COMMA) {
            LeafNode comma = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),funcParams);
            funcParams.addChildNode(comma);
            next(); // 默认此处一定有后一项，warning！！！
            Node funcParam1 = (parType == ParType.FuncFParams) ? parseFuncFParam() : parseExp();
            funcParam1.setParentNode(funcParams);
            funcParams.addChildNode(funcParam1);
        }
        return funcParams;
    }

    private Node parseInitValue(ParType parType) {
        Node initVal = new Node(parType);
        if (now.getLexType() == LexType.STRCON) { // StringConst
            LeafNode strCon = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),initVal);
            initVal.addChildNode(strCon);
            next();
        }
        else if (now.getLexType() == LexType.LBRACE) { //  '{' [ ConstExp { ',' ConstExp } ] '}'
            LeafNode lBrace = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),initVal);
            initVal.addChildNode(lBrace);
            next(); // 默认此处一定有后一项，warning！！！
            if (now.getLexType() != LexType.RBRACE) { // [ ConstExp { ',' ConstExp } ]
                Node Exp = (parType == ParType.ConstInitVal) ? parseConstExp() : parseExp();
                Exp.setParentNode(initVal);
                initVal.addChildNode(Exp);
                while (now.getLexType() == LexType.COMMA) { // { ',' ConstExp }
                    LeafNode comma = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),initVal);
                    next(); // 默认此处一定有后一项，warning！！！
                    initVal.addChildNode(comma);
                    Node Exp1 = (parType == ParType.ConstInitVal) ? parseConstExp() : parseExp();
                    Exp1.setParentNode(initVal);
                    initVal.addChildNode(Exp1);
                }
            }
            LeafNode rBrace = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),initVal);
            initVal.addChildNode(rBrace);
            next();
        }
        else {
            Node Exp = (parType == ParType.ConstInitVal) ? parseConstExp() : parseExp();
            Exp.setParentNode(initVal);
            initVal.addChildNode(Exp);
        }
        return initVal;
    }

    private Node parseBType() {
        Node bType = new Node(ParType.BType);
        if (now.getLexType() == LexType.INTTK) {
            LeafNode intTk = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),bType);
            bType.addChildNode(intTk);
        }
        else { // LexType.CHARTK
            LeafNode charTk = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),bType);
            bType.addChildNode(charTk);
        }
        next(); // 默认此处一定有后一项，warning！！！
        return bType;
    }

    private Node parseDeclaration(ParType declType, boolean isConst) {
        Node declNode = new Node(declType);
        if (isConst) { // 处理 'const' 关键字 (如果是 ConstDecl)
            LeafNode cons = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), declNode);
            declNode.addChildNode(cons);
            next(); // 假设一定有下一项，警告！
        }
        Node bType = parseBType(); // 处理类型 (BType)
        bType.setParentNode(declNode);
        declNode.addChildNode(bType);
        Node def = isConst ? parseConstDef() : parseVarDef(); // 根据标志调用不同的解析函数
        def.setParentNode(declNode);
        declNode.addChildNode(def);
        while (now.getLexType() == LexType.COMMA) { // 处理逗号分隔的多定义
            LeafNode comma = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), declNode);
            declNode.addChildNode(comma);
            next(); // 默认此处一定有后一项，警告！
            Node defNext = isConst ? parseConstDef() : parseVarDef(); // 根据标志调用不同的解析函数
            defNext.setParentNode(declNode);
            declNode.addChildNode(defNext);
        }
        if (now.getLexType() == LexType.SEMICN) { // 处理分号
            LeafNode semicolon = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), declNode);
            declNode.addChildNode(semicolon);
            next(); // 默认此处一定有后一项，警告！
        } else { // i: 缺少分号，不需要改变now
            int num = lastNum();
            errorList.add(new Err(num, "i"));
            LeafNode semicolon = new LeafNode(num, ";", 0, LexType.SEMICN, declNode);
            declNode.addChildNode(semicolon);
        }
        return declNode;
    }

    private Node parseDefinition(ParType parType) { //  VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        Node def = new Node(parType);
        LeafNode ident = new LeafNode(now.getLineNum(),now.getName(), 0,now.getLexType(),def);
        def.addChildNode(ident);
        next(); // 默认此处一定有后一项，warning！！！
        if (now.getLexType() == LexType.LBRACK) {
            LeafNode lBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),def);
            def.addChildNode(lBracket);
            next(); // 默认此处一定有后一项，warning！！！
            Node exp = parseConstExp();
            exp.setParentNode(def);
            def.addChildNode(exp);
            if (now.getLexType() == LexType.RBRACK) {
                LeafNode rBracket = new LeafNode(now.getLineNum(),now.getName(),0,now.getLexType(),def);
                def.addChildNode(rBracket);
                next(); // 默认此处一定有后一项，warning！！！
            }
            else { // k:缺少右中括号，不需要改变now
                int num = lastNum();
                errorList.add(new Err(num,"k"));
                LeafNode rBracket = new LeafNode(num,"]",0,LexType.RBRACK,def);
                def.addChildNode(rBracket);
            }
        }
        if ((parType == ParType.VarDef && now.getLexType() == LexType.ASSIGN) ||
                parType == ParType.ConstDef) {
            LeafNode assign = new LeafNode(now.getLineNum(), now.getName(), 0, now.getLexType(), def);
            def.addChildNode(assign);
            next(); // 默认此处一定有后一项，warning！！！
            Node initVal = (parType == ParType.VarDef) ? parseInitVal() : parseConstInitVal();
            initVal.setParentNode(def);
            def.addChildNode(initVal);
        }
        return def;
    }


    private LexType preRead() { // 无法预读时返回null
        LexType lexType = null;
        if (iter.hasNext()) {
            lexType = iter.next().getLexType();
            iter.previous();
        }
        return lexType;
    }

    private LexType pre2Read() {
        LexType lexType = null;
        if (iter.hasNext()) {
            iter.next();
            if (iter.hasNext()) {
                lexType = iter.next().getLexType();
                iter.previous();
            }
            iter.previous();
        }
        return lexType;
    }

    private int lastNum() { // 返回前一个token的行号，不一定是前一个非终结符，无则返回1
        if (iter.hasPrevious()) {
            iter.previous();
            int num = iter.previous().getLineNum();
            iter.next();
            iter.next();
            return num;
        }
        return 1;
    }

    private void next() {
        if (iter.hasNext()) {
            now = iter.next();
        }
        while (iter.hasNext() && now.getLexType() == LexType.NOTE) {
            now = iter.next();
        }
    }

    private boolean hasAssign() { // 区分是LVal = Exp还是[Exp]: a=8;,a[1]=8;,a*1;,a[1]*1; 当前紧邻=或]后等号 防止缺失;时exp误读
        boolean hasAssign = false;
        int count = 0; // 方括号匹配
        int currentIndex = iter.nextIndex();
        if (iter.hasNext()) {
            Token token = iter.next();
            if (token.getLexType() == LexType.ASSIGN) { // 是等号
                hasAssign = true;
            }
            else if (token.getLexType() == LexType.LBRACK) { // 匹配方括号
                count++;
                while (iter.hasNext()) {
                    token = iter.next();
                    if (token.getLexType() != LexType.SEMICN) { // 分号直接结束
                        if (token.getLexType() == LexType.ASSIGN) { // 是等号,此时缺]
                            hasAssign = true;
                            break;
                        }
                        else if (token.getLexType() == LexType.RBRACK) {
                            count--;
                        }
                        else if (token.getLexType() == LexType.LBRACK) {
                            count++;
                        }
                        if (count == 0) { // 方括号已匹配但没有=
                            if (iter.hasNext()) {
                                token = iter.next();
                                if (token.getLexType() == LexType.ASSIGN) {
                                    hasAssign = true;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }

        while (iter.previousIndex() >= currentIndex) {
            iter.previous();
        }
        return hasAssign;
    }
}
