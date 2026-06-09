package frontend;

import java.io.Console;
import java.util.ArrayList;
import java.util.Objects;

public class Grammar {
    ArrayList<Token> tokens;
    public GramNode root = new GramNode();
    int curPos = 0;
    public ArrayList<Error> errors = new ArrayList<>();

    public Grammar(ArrayList<Token> tokens){
        this.tokens = tokens;
        root = this.CompUnit();
    }

    public GramNode CompUnit() {

        //CompUnit → {Decl} {FuncDef} MainFuncDef
        GramNode compUnit = new GramNode();
        compUnit.gramType = GramType.CompUnit;

        GramNode decl;
        while((decl = Decl()) != null){
            decl.parent = compUnit;
            compUnit.children.add(decl);
        }

        GramNode funcDef;
        while((funcDef = FuncDef()) != null){
            funcDef.parent = compUnit;
            compUnit.children.add(funcDef);
        }

        GramNode mainFuncDef = MainFuncDef();
        if(mainFuncDef == null) return null;
        mainFuncDef.parent = compUnit;
        compUnit.children.add(mainFuncDef);

        System.out.println("compUnit");
        return compUnit;
    }

    private GramNode MainFuncDef() {
        //MainFuncDef → 'int' 'main' '(' ')' Block
        int startPos = curPos;
        GramNode mainFuncDef = new GramNode();
        mainFuncDef.gramType = GramType.MainFuncDef;
        
        if(!tokens.get(curPos).word.equals("int") || !Objects.equals(tokens.get(curPos + 1).word, "main") || !Objects.equals(tokens.get(curPos + 2).word, "(")) {
            return null;
        }else{

            mainFuncDef.children.add(tokens.get(curPos).token2node(mainFuncDef));
            mainFuncDef.children.add(tokens.get(curPos+1).token2node(mainFuncDef));
            mainFuncDef.children.add(tokens.get(curPos+2).token2node(mainFuncDef));
            
            curPos = curPos + 3;

            if(!Objects.equals(tokens.get(curPos).word, ")")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "j"));
                Token missToken = new Token(")", LexType.RPARENT, curLine);
                mainFuncDef.children.add(missToken.token2node(mainFuncDef));
            }else mainFuncDef.children.add(tokens.get(curPos++).token2node(mainFuncDef));

            GramNode block = Block();
            if(block==null) {
                curPos = startPos;
                return null;
            }
            block.parent = mainFuncDef;
            mainFuncDef.children.add(block);

            System.out.println("mainFuncDef");
            return mainFuncDef;
        }
    }

    private GramNode Block() {
        // Block → '{' { BlockItem } '}'
        if(curPos >= tokens.size() - 1){
            return null;
        }
        int startPos = curPos;
        GramNode block = new GramNode();
        block.gramType = GramType.Block;
        
        if(!Objects.equals(tokens.get(curPos).word, "{")){
            return null;
        } else {
            block.children.add(tokens.get(curPos).token2node(block));
            curPos++;

            GramNode blockItem;
            while((blockItem = BlockItem()) != null){
                blockItem.parent = block;
                block.children.add(blockItem);
            }

            if(!Objects.equals(tokens.get(curPos).word, "}")){
                System.out.println(curPos + " " + tokens.size());
                curPos = startPos;
                assert curPos == tokens.size() - 1;
                return null;
            }
            block.children.add(tokens.get(curPos).token2node(block));
            curPos++;

            System.out.println("block");
            return block;
        }
    }

    private GramNode BlockItem() {
        // BlockItem → Decl | Stmt
        if(curPos >= tokens.size() - 1 ){
            return null;
        }

        int startPos = curPos;
        GramNode blockItem = new GramNode();
        blockItem.gramType = GramType.BlockItem;

        GramNode child = Decl();
        if(child != null){
            blockItem.children.add(child);
        } else {
            child = Stmt();
            if (child != null) {
                blockItem.children.add(child);
            } else {
                curPos = startPos;
                return null;
            }
        }

        child.parent = blockItem;

        System.out.println("blockItem");
        return blockItem;
    }

    private GramNode Stmt() {
        /*
         Stmt → **LVal '=' Exp ';'
            | [Exp] ';'
            | **Block
            | **'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            | **'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt 
            | **'break' ';' 
            | **'continue' ';'
            | **'return' [Exp] ';'
            | **LVal '=' 'getint''('')'';'
            | **LVal '=' 'getchar''('')'';'
            | **'printf''('StringConst {','Exp}')'';'
        */
        System.out.println("im finding stmt");
        int startPos = curPos;
        GramNode stmt = new GramNode();
        stmt.gramType = GramType.Stmt;

        if(curPos >= tokens.size() - 1){
            return null;
        }

        GramNode child = LVal();
        if(child != null && Objects.equals(tokens.get(curPos).word, "=")) {
            stmt.children.add(child);
            child.parent = stmt;

            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            if(Objects.equals(tokens.get(curPos).word, "getint") || Objects.equals(tokens.get(curPos).word, "getchar")){
                stmt.children.add(tokens.get(curPos++).token2node(stmt));
                if(!Objects.equals(tokens.get(curPos).word, "(")){
                    curPos = startPos;
                    return null;
                } else stmt.children.add(tokens.get(curPos++).token2node(stmt));

                if(!Objects.equals(tokens.get(curPos).word, ")")){
                    int curLine = tokens.get(curPos-1).line;
                    errors.add(new Error(curLine, "j"));
                    Token missToken = new Token(")", LexType.RPARENT, curLine);
                    stmt.children.add(missToken.token2node(stmt));
                }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

                if(!Objects.equals(tokens.get(curPos).word, ";")){
                    int curLine = tokens.get(curPos-1).line;
                    errors.add(new Error(curLine, "i"));
                    Token missToken = new Token(";", LexType.SEMICN, curLine);
                    stmt.children.add(missToken.token2node(stmt));
                }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

                System.out.println("stmt");
                return stmt;
            }

            GramNode exp = Exp();
            if(exp != null) {
                stmt.children.add(exp);
                exp.parent = stmt;

                if(!Objects.equals(tokens.get(curPos).word, ";")) {
                    int curLine = tokens.get(curPos-1).line;
                    errors.add(new Error(curLine, "i"));
                    Token missToken = new Token(";", LexType.SEMICN, curLine);
                    stmt.children.add(missToken.token2node( stmt));
                }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

                System.out.println("stmt");
                return stmt;
            }

            curPos = startPos;
            return null;
        } else curPos = startPos;

        child = Block();
        if(child != null) {
            stmt.children.add(child);
            child.parent = stmt;
            System.out.println("stmt");
            return stmt;
        }

        if(Objects.equals(tokens.get(curPos).word, "if")) {//'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            if(!Objects.equals(tokens.get(curPos).word, "(")) {
                curPos = startPos;
                return null;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            GramNode cond = Cond();
            if(cond == null) {
                   curPos = startPos;
                   return null;
            }
            stmt.children.add(cond);
            cond.parent = stmt;

            if(!Objects.equals(tokens.get(curPos).word, ")")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "j"));
                Token missToken = new Token(")", LexType.RPARENT, curLine);
                stmt.children.add(missToken.token2node(stmt));
            }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

            GramNode stmt1 = Stmt();
            if(stmt1 == null) {
                  curPos = startPos;
                  return null;
            }
            stmt.children.add(stmt1);
            stmt1.parent = stmt;

            if(Objects.equals(tokens.get(curPos).word, "else")) {
                stmt.children.add(tokens.get(curPos).token2node(stmt));
                curPos++;

                stmt1 = Stmt();
                if(stmt1 == null) {
                    curPos = startPos;
                    return null;
                }
                stmt.children.add(stmt1);
                stmt1.parent = stmt;
            }

            System.out.println("stmt");
            return stmt;
        }
        else if(Objects.equals(tokens.get(curPos).word, "for")) {
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            if(!Objects.equals(tokens.get(curPos).word, "(")) {
                  curPos = startPos;
                  return null;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            GramNode forStmt = ForStmt();
            if(forStmt != null) {
                 stmt.children.add(forStmt);
                 forStmt.parent = stmt;
            }

            if(!Objects.equals(tokens.get(curPos).word, ";")) {
                curPos = startPos;
                return null;
            }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

            GramNode cond = Cond();
            if(cond != null) {
                stmt.children.add(cond);
                cond.parent = stmt;
            }

            if(!Objects.equals(tokens.get(curPos).word, ";")) {
                curPos = startPos;
                return null;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            forStmt = ForStmt();
            if(forStmt != null) {
                stmt.children.add(forStmt);
                forStmt.parent = stmt;
            }

            if(!Objects.equals(tokens.get(curPos).word, ")")){
                curPos = startPos;
                return null;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            GramNode stmt1 = Stmt();
            if(stmt1 == null) {
                curPos = startPos;
                return null;
            }
            stmt.children.add(stmt1);
            stmt1.parent = stmt;

            System.out.println("stmt");
            return stmt;
        }
        else if(Objects.equals(tokens.get(curPos).word, "break") || Objects.equals(tokens.get(curPos).word, "continue") || Objects.equals(tokens.get(curPos).word, "return")) {
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;
            if(Objects.equals(tokens.get(curPos - 1).word, "return")){
                GramNode exp = Exp();
                if(exp != null) {
                    stmt.children.add(exp);
                    exp.parent = stmt;
                }
            }
            if(!Objects.equals(tokens.get(curPos).word, ";")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "i"));
                Token missToken = new Token(";", LexType.SEMICN, curLine);
                stmt.children.add(missToken.token2node( stmt));
            }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

            System.out.println("stmt");
            return stmt;
        }
        else if(Objects.equals(tokens.get(curPos).word, "printf")) {
            if(!Objects.equals(tokens.get(curPos + 1).word, "(") ||tokens.get(curPos+2).type!=LexType.STRCON){
                  curPos = startPos;
                  return null;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            stmt.children.add(tokens.get(curPos+1).token2node(stmt));
            stmt.children.add(tokens.get(curPos+2).token2node(stmt));
            curPos = curPos + 3;

            while(Objects.equals(tokens.get(curPos).word, ",")) {
                stmt.children.add(tokens.get(curPos).token2node(stmt));
                curPos++;

                GramNode exp = Exp();
                if(exp == null) {
                    curPos = startPos;
                    return null;
                }
                stmt.children.add(exp);
                exp.parent = stmt;
            }

            if(!Objects.equals(tokens.get(curPos).word, ")")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "j"));
                Token missToken = new Token(")", LexType.RPARENT, curLine);
                stmt.children.add(missToken.token2node(stmt));
            }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

            if(!Objects.equals(tokens.get(curPos).word, ";")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "i"));
                Token missToken = new Token(";", LexType.SEMICN, curLine);
                stmt.children.add(missToken.token2node(stmt));
            }else stmt.children.add(tokens.get(curPos++).token2node(stmt));

            System.out.println("stmt");
            return stmt;
        }

        child = Exp();
        if(child != null) {
            stmt.children.add(child);
            child.parent = stmt;


            if(!Objects.equals(tokens.get(curPos).word, ";")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "i"));
                Token missToken = new Token(";", LexType.SEMICN, curLine);
                stmt.children.add(missToken.token2node( stmt));
                return stmt;
            }
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;

            return stmt.children.isEmpty() ? null : stmt;
        }

        if (Objects.equals(tokens.get(curPos).word, ";")){
            stmt.children.add(tokens.get(curPos).token2node(stmt));
            curPos++;
        }

        System.out.println("stmt");
        return stmt.children.isEmpty() ? null : stmt;
    }

    private GramNode ForStmt() {
        //ForStmt → LVal '=' Exp
        int startPos = curPos;
        GramNode forStmt = new GramNode();
        forStmt.gramType = GramType.ForStmt;

        GramNode lVal = LVal();
        if(lVal == null) {
            curPos = startPos;
            return null;
        }
        forStmt.children.add(lVal);
        lVal.parent = forStmt;

        if(!Objects.equals(tokens.get(curPos).word, "=")) {
            curPos = startPos;
            return null;
        }
        forStmt.children.add(tokens.get(curPos).token2node(forStmt));
        curPos++;

        GramNode exp = Exp();
        if(exp == null){
            curPos = startPos;
            return null;
        }
        forStmt.children.add(exp);
        exp.parent = forStmt;

        System.out.println("forStmt");
        return forStmt;
    }

    private GramNode Cond() {
        // Cond → LOrExp
        int startPos = curPos;
        GramNode cond = new GramNode();
        cond.gramType = GramType.Cond;

        GramNode lOrExp = LOrExp();
        if(lOrExp == null) {
            curPos=startPos;
            return null;
        }
        cond.children.add(lOrExp);
        lOrExp.parent = cond;

        System.out.println("cond");
        return cond;
    }

    private GramNode LOrExp() {
        // LOrExp → LOrExp → LAndExp | LOrExp '||' LAndExp
        int startPos = curPos;
        GramNode lOrExp = new GramNode();
        lOrExp.gramType = GramType.LOrExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode lAndExp = LAndExp();
        if (lAndExp == null) {
            curPos = startPos;
            return null;
        }
        children.add(lAndExp);

        while (true) {
            if (!Objects.equals(tokens.get(curPos).word, "||")) break;

            operands.add(tokens.get(curPos).token2node(lOrExp));
            curPos++;

            lAndExp = LAndExp();
            if (lAndExp == null) break;

            children.add(lAndExp);
        }

        return tree(children, operands, GramType.LOrExp);
    }

    private GramNode LAndExp() {
        // LAndExp → EqExp | LAndExp '&&' EqExp
        int startPos = curPos;
        GramNode lAndExp = new GramNode();
        lAndExp.gramType = GramType.LAndExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode eqExp = EqExp();
        if (eqExp == null) {
            curPos = startPos;
            return null;
        }
        children.add(eqExp);

        while (true) {
            if (!Objects.equals(tokens.get(curPos).word, "&&")) break;

            operands.add(tokens.get(curPos).token2node(lAndExp));
            curPos++;

            eqExp = EqExp();
            if (eqExp == null) break;

            children.add(eqExp);
        }

        return tree(children, operands, GramType.LAndExp);
    }

    private GramNode EqExp() {
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        int startPos = curPos;
        GramNode eqExp = new GramNode();
        eqExp.gramType = GramType.EqExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode relExp = RelExp();
        if (relExp == null) {
            curPos = startPos;
            return null;
        }
        children.add(relExp);

        while (true) {
            if (!Objects.equals(tokens.get(curPos).word, "==") && !Objects.equals(tokens.get(curPos).word, "!=")) break;

            operands.add(tokens.get(curPos).token2node(eqExp));
            curPos++;

            relExp = RelExp();
            if (relExp == null) break;

            children.add(relExp);
        }

        return tree(children, operands, GramType.EqExp);
    }

    private GramNode RelExp() {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        int startPos = curPos;
        GramNode relExp = new GramNode();
        relExp.gramType = GramType.RelExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode addExp = AddExp();
        if (addExp == null) {
            curPos = startPos;
            return null;
        }
        children.add(addExp);

        while (true) {
            String currentToken = tokens.get(curPos).word;
            if (!Objects.equals(currentToken, "<") && !Objects.equals(currentToken, ">") &&
                    !Objects.equals(currentToken, "<=") && !Objects.equals(currentToken, ">=")) {
                break;
            }

            operands.add(tokens.get(curPos).token2node(relExp));
            curPos++;

            addExp = AddExp();
            if (addExp == null) break;

            children.add(addExp);
        }
        return tree(children, operands, GramType.RelExp);
    }

    private GramNode FuncDef() {
        //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        int startPos = curPos;
        GramNode funcDef = new GramNode();
        funcDef.gramType = GramType.FuncDef;

        GramNode funcType = FuncType();
        if(funcType == null) {
            curPos=startPos;
            return null;
        }
        funcDef.children.add(funcType);
        funcType.parent = funcDef;

        if(tokens.get(curPos).type != LexType.IDENFR) {
            curPos = startPos;
            return null;
        }
        funcDef.children.add(tokens.get(curPos++).token2node(funcDef));

        if(!Objects.equals(tokens.get(curPos).word, "(")) {
            curPos=startPos;
            return null;
        }
        funcDef.children.add(tokens.get(curPos).token2node(funcDef));
        curPos++;

        GramNode funcFParams ;
        while ((funcFParams = FuncFParams())!=null) {
            funcFParams.parent = funcDef;
            funcDef.children.add(funcFParams);
        }

        if(!Objects.equals(tokens.get(curPos).word, ")")) {
            int curLine = tokens.get(curPos-1).line;
            errors.add(new Error(curLine, "j"));
            Token missToken = new Token(")", LexType.RPARENT, curLine);
            funcDef.children.add(missToken.token2node(funcDef));
        }else funcDef.children.add(tokens.get(curPos++).token2node(funcDef));

        GramNode block = Block();
        if(block == null) {
            curPos = startPos;
            return null;
        }
        funcDef.children.add(block);
        block.parent = funcDef;

        System.out.println("funcDef");
        return funcDef;
    }

    private GramNode FuncFParams() {
        //FuncFParams → FuncFParam { ',' FuncFParam }
        int startPos = curPos;
        GramNode funcFParams = new GramNode();
        funcFParams.gramType = GramType.FuncFParams;

        GramNode funcFParam = FuncFParam();
        if(funcFParam == null) {
            curPos = startPos;
            return null;
        }
        funcFParams.children.add(funcFParam);
        funcFParam.parent = funcFParams;

        while (Objects.equals(tokens.get(curPos).word, ",")) {
            funcFParams.children.add(tokens.get(curPos).token2node(funcFParams));
            curPos++;

            funcFParam = FuncFParam();
            if(funcFParam == null) {
            	curPos = startPos;
                return null;
            }
            funcFParams.children.add(funcFParam);
            funcFParam.parent = funcFParams;
            
        }

        System.out.println("funcFParams");
        return funcFParams;

    }

    private GramNode FuncFParam() {
        //FuncFParam → BType Ident ['[' ']']
        int startPos = curPos;
        GramNode funcFParam = new GramNode();
        funcFParam.gramType = GramType.FuncFParam;

        GramNode bType = BType();
        if(bType == null) {
            curPos = startPos;
            return null;
        }
        funcFParam.children.add(bType);
        bType.parent = funcFParam;

        if(tokens.get(curPos).type != LexType.IDENFR) {
            curPos = startPos;
            return null;
        }
        funcFParam.children.add(tokens.get(curPos).token2node(funcFParam));
        curPos++;

        if(Objects.equals(tokens.get(curPos).word, "[")){
            funcFParam.children.add(tokens.get(curPos).token2node(funcFParam));
            curPos++;
            if(!Objects.equals(tokens.get(curPos).word, "]")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "k"));
                Token missToken = new Token("]", LexType.RBRACK, curLine);
                funcFParam.children.add(missToken.token2node(funcFParam));
                return funcFParam;
            }
            funcFParam.children.add(tokens.get(curPos).token2node(funcFParam));
            curPos++;
        }
        System.out.println("funcFParam");
        return funcFParam;

    }

    private GramNode BType() {
         //BType → 'int' | 'char'
         int startPos = curPos;
         GramNode bType = new GramNode();
         bType.gramType = GramType.BType;
 
         if(!Objects.equals(tokens.get(curPos).word, "int") && !Objects.equals(tokens.get(curPos).word, "char")){
             return null;
         }
         bType.children.add(tokens.get(curPos).token2node(bType));
        curPos++;
        System.out.println("bType");
         return bType;
    }

    private GramNode FuncType() {
        //FuncType → 'void' | 'int' | 'char'
        int startPos = curPos;
        GramNode funcType = new GramNode();
        funcType.gramType = GramType.FuncType;

        if(!Objects.equals(tokens.get(curPos).word, "void") && !Objects.equals(tokens.get(curPos).word, "int") && !Objects.equals(tokens.get(curPos).word, "char")){
            return null;
        }
        funcType.children.add(tokens.get(curPos).token2node(funcType));
        curPos++;
        System.out.println("funcType");
        return funcType;
    }

    private GramNode Decl() {
        //Decl → ConstDecl | VarDecl
        if(curPos >= tokens.size() - 1){
            return null;
        }
        int startPos = curPos;
        GramNode decl = new GramNode();
        decl.gramType = GramType.Decl;

        GramNode child;
        if((child = ConstDecl()) != null){
            decl.children.add(child);
        }else if((child = VarDecl()) != null){
            decl.children.add(child);
        }else{
            curPos = startPos;
            return null;
        }
        child.parent = decl;

        System.out.println("decl");
        return decl;
    }

    private GramNode VarDecl() {
        // VarDecl → BType VarDef { ',' VarDef } ';'
        int startPos = curPos;
        GramNode varDecl = new GramNode();
        varDecl.gramType = GramType.VarDecl;

        GramNode bType = BType();
        if(bType == null) {
            curPos = startPos;
            return null;
        }
        varDecl.children.add(bType);
        bType.parent = varDecl;

        GramNode varDef = VarDef();
        if(varDef == null) {
            curPos = startPos;
            return null;
        }
        varDecl.children.add(varDef);
        varDef.parent = varDecl;

        while (Objects.equals(tokens.get(curPos).word, ",")) {
            varDecl.children.add(tokens.get(curPos).token2node(varDecl));
            curPos++;

            varDef = VarDef();
            if(varDef == null) {
                curPos = startPos;
                return null;
            }
            varDecl.children.add(varDef);
            varDef.parent = varDecl;
        }

        if(!Objects.equals(tokens.get(curPos).word, ";")){
            int curLine = tokens.get(curPos-1).line;
            errors.add(new Error(curLine, "i"));
            Token missToken = new Token(";", LexType.SEMICN, curLine);
            varDecl.children.add(missToken.token2node(varDecl));
            return varDecl;
        }
        varDecl.children.add(tokens.get(curPos).token2node(varDecl));
        curPos++;

        System.out.println("varDecl");
        return varDecl;
    }

    private GramNode VarDef() {
        //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        int startPos = curPos;
        GramNode varDef = new GramNode();
        varDef.gramType = GramType.VarDef;

        if(tokens.get(curPos).type != LexType.IDENFR || Objects.equals(tokens.get(curPos + 1).word, "(")) {
            curPos = startPos;
            return null;
        }
        varDef.children.add(tokens.get(curPos).token2node(varDef));
        curPos++;

        if(Objects.equals(tokens.get(curPos).word, "[")){
            varDef.children.add(tokens.get(curPos).token2node(varDef));
            curPos++;

            GramNode constExp = ConstExp();
            if(constExp == null) {
                curPos = startPos;
                return null;
            }
            varDef.children.add(constExp);
            constExp.parent = varDef;

            if(!Objects.equals(tokens.get(curPos).word, "]")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "k"));
                Token missToken = new Token("]", LexType.RBRACK, curLine);
                constExp.children.add(missToken.token2node(constExp));
            }else varDef.children.add(tokens.get(curPos++).token2node(varDef));
        }

        if(Objects.equals(tokens.get(curPos).word, "=")) {
            varDef.children.add(tokens.get(curPos).token2node(varDef));
            curPos++;

            GramNode initVal = InitVal();
            if(initVal == null) {
                curPos = startPos;
                return null;
            }
            varDef.children.add(initVal);
            initVal.parent = varDef;
        }

        System.out.println("varDef");
        return varDef;
    }

    private GramNode InitVal() {
        //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        int startPos = curPos;
        GramNode initVal = new GramNode();
        initVal.gramType = GramType.InitVal;

        GramNode child;
        if((child = Exp()) != null) {
            initVal.children.add(child);
            child.parent = initVal;

            System.out.println("initVal");
            return initVal;
        }

        if(Objects.equals(tokens.get(curPos).word, "{")){
            initVal.children.add(tokens.get(curPos).token2node(initVal));
            curPos++;

            GramNode exp = Exp();
            if(exp != null) {
                initVal.children.add(exp);
                exp.parent = initVal;

                while (Objects.equals(tokens.get(curPos).word, ",")) {
                    initVal.children.add(tokens.get(curPos).token2node(initVal));
                    curPos++;
                    exp = Exp();
                    if(exp == null) {
                        curPos = startPos;
                        return null;
                    }
                    initVal.children.add(exp);
                    exp.parent = initVal;
                }
            }

            if(!Objects.equals(tokens.get(curPos).word, "}")) {
                curPos = startPos;
                return null;
            }
            initVal.children.add(tokens.get(curPos).token2node(initVal));
            curPos++;
            System.out.println("initVal");
            return initVal;
        }

        if(tokens.get(curPos).type == LexType.STRCON) {
            initVal.children.add(tokens.get(curPos).token2node(initVal));
            curPos++;
            System.out.println("initVal");
            return initVal;
        }

        curPos = startPos;
        return null;
    }

    private GramNode ConstDecl() {
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        int startPos = curPos;
        GramNode constDecl = new GramNode();
        constDecl.gramType = GramType.ConstDecl;

        if(!Objects.equals(tokens.get(curPos).word, "const")) {
            return null;
        }
        constDecl.children.add(tokens.get(curPos).token2node(constDecl));
        curPos++;

        GramNode bType = BType();
        if(bType == null) {
            curPos = startPos;
            return null;
        }
        constDecl.children.add(bType);
        bType.parent = constDecl;

        GramNode constDef = ConstDef();
        if(constDef == null) {
            curPos = startPos;
            return null;
        }
        constDecl.children.add(constDef);
        constDef.parent = constDecl;

        while (Objects.equals(tokens.get(curPos).word, ",")){
            constDecl.children.add(tokens.get(curPos).token2node(constDecl));
            curPos++;
            constDef = ConstDef();
            if(constDef == null) {
                curPos = startPos;
                return null;
            }
            constDecl.children.add(constDef);
            constDef.parent = constDecl;
        }

        if(!Objects.equals(tokens.get(curPos).word, ";")) {
            //curPos = startPos;
            //return null;
            int curLine = tokens.get(curPos-1).line;
            errors.add(new Error(curLine, "i"));
            Token missToken = new Token(";", LexType.SEMICN, curLine);
            constDecl.children.add(missToken.token2node(constDecl));
            return constDecl;
        }
        constDecl.children.add(tokens.get(curPos).token2node(constDecl));
        curPos++;
        System.out.println("constDecl");
        return constDecl;
    }

    private GramNode ConstDef() {
        //ConstDef → Ident { '[' ConstExp ']' } '=' ConstInitVal
        int startPos = curPos;
        GramNode constDef = new GramNode();
        constDef.gramType = GramType.ConstDef;

        if(tokens.get(curPos).type != LexType.IDENFR) {
            return null;
        }
        constDef.children.add(tokens.get(curPos).token2node(constDef));
        curPos++;

        while (Objects.equals(tokens.get(curPos).word, "[")){
            constDef.children.add(tokens.get(curPos).token2node(constDef));
            curPos++;
            GramNode constExp = ConstExp();
            if(constExp == null) {
                curPos = startPos;
                return null;
            }
            constDef.children.add(constExp);
            constExp.parent = constDef;
            if(!Objects.equals(tokens.get(curPos).word, "]")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "k"));
                Token missToken = new Token("]", LexType.RBRACK, curLine);
                constDef.children.add(missToken.token2node(constDef));
            }else constDef.children.add(tokens.get(curPos++).token2node(constDef));
        }
        if(!Objects.equals(tokens.get(curPos).word, "=")) {
            curPos = startPos;
            return null;
        }
        constDef.children.add(tokens.get(curPos).token2node(constDef));
        curPos++;

        GramNode constInitVal = ConstInitVal();
        if(constInitVal == null) {
            curPos = startPos;
            return null;
        }
        constDef.children.add(constInitVal);
        constInitVal.parent = constDef;

        System.out.println("constDef");
        return constDef;
    }

    private GramNode ConstInitVal() {
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        int startPos = curPos;
        GramNode constInitVal = new GramNode();
        constInitVal.gramType = GramType.ConstInitVal;

        GramNode child = ConstExp();
        if(child != null) {
            constInitVal.children.add(child);
            child.parent = constInitVal;
            System.out.println("constInitVal");
            return constInitVal;
        }

        if(Objects.equals(tokens.get(curPos).word, "{")){
            constInitVal.children.add(tokens.get(curPos).token2node(constInitVal));
            curPos++;

            child = ConstExp();
            if(child != null) {
                constInitVal.children.add(child);
                child.parent = constInitVal;

                while (Objects.equals(tokens.get(curPos).word, ",")) {
                    constInitVal.children.add(tokens.get(curPos).token2node(constInitVal));
                    curPos++;
                    child = ConstExp();
                    if(child == null) {
                        curPos = startPos;
                        return null;
                    }
                    constInitVal.children.add(child);
                    child.parent = constInitVal;
                }
            }

            if(!Objects.equals(tokens.get(curPos).word, "}")){
                curPos = startPos;
                return null;
            }
            constInitVal.children.add(tokens.get(curPos).token2node(constInitVal));
            curPos++;
            System.out.println("constInitVal");
            return constInitVal;
        }
        
        if(tokens.get(curPos).type != LexType.STRCON) {
            curPos = startPos;
            return null;
        }
        constInitVal.children.add(tokens.get(curPos).token2node(constInitVal));
        curPos++;
        System.out.println("constInitVal");
        return constInitVal;
    }

    private GramNode ConstExp() {
        // ConstExp → AddExp
        int startPos = curPos;
        GramNode constExp = new GramNode();
        constExp.gramType = GramType.ConstExp;

        GramNode child = AddExp();
        if(child == null) {
            curPos = startPos;
            return null;
        }
        constExp.children.add(child);
        child.parent = constExp;

        System.out.println("constExp");
        return constExp;
    }

    private GramNode AddExp() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        int startPos = curPos;
        GramNode addExp = new GramNode();
        addExp.gramType = GramType.AddExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode child = MulExp();
        if (child == null) {
            curPos = startPos;
            return null;
        }
        children.add(child);

        while (true) {
            if (Objects.equals(tokens.get(curPos).word, "+") || Objects.equals(tokens.get(curPos).word, "-")) {
                //addExp.children.add(tokens.get(curPos).token2node(addExp));
                operands.add(tokens.get(curPos).token2node(addExp));
                curPos++;

                child = MulExp();
                if (child == null) break;
                //addExp.children.add(child);
                //child.parent = addExp;
                children.add(child);

            } else {
                break;
            }
        }
        return tree(children, operands, GramType.AddExp);
    }

    private GramNode MulExp() {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        int startPos = curPos;
        GramNode mulExp = new GramNode();
        mulExp.gramType = GramType.MulExp;

        ArrayList<GramNode> children = new ArrayList<>();
        ArrayList<GramNode> operands = new ArrayList<>();

        GramNode child = UnaryExp();
        if (child == null) {
            curPos = startPos;
            return null;
        }
        children.add(child);

        while (true) {
            if (Objects.equals(tokens.get(curPos).word, "*") || Objects.equals(tokens.get(curPos).word, "/") || Objects.equals(tokens.get(curPos).word, "%")) {
                operands.add(tokens.get(curPos).token2node(mulExp));
                curPos++;

                child = UnaryExp();
                if (child == null) break;
                children.add(child);
            } else {
                break;
            }
        }
        return tree(children, operands, GramType.MulExp);
    }

    private GramNode tree(ArrayList<GramNode> children, ArrayList<GramNode> operands, GramType type) {
        GramNode root = new GramNode();
        root.gramType = type;
        root.children.add(children.get(0));

        if (children.size() > 1) {
            for (int i = 1; i < children.size(); i++) {
                GramNode newRoot = new GramNode();
                newRoot.gramType = type;

                newRoot.children.add(root);
                newRoot.children.add(operands.get(i - 1));
                newRoot.children.add(children.get(i));

                root = newRoot;
            }
        }
        return root;
    }


    private GramNode UnaryExp() {
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        int startPos = curPos;
        GramNode unaryExp = new GramNode();
        unaryExp.gramType = GramType.UnaryExp;

        GramNode child = PrimaryExp();
        if (child != null) {
            unaryExp.children.add(child);
            child.parent = unaryExp;

            System.out.println("unary");
            return unaryExp;
        }

        if (tokens.get(curPos).type == LexType.IDENFR) {
            unaryExp.children.add(tokens.get(curPos).token2node(unaryExp));
            curPos++;

            if (!Objects.equals(tokens.get(curPos).word, "(")) {
                curPos = startPos;
                return null;
            }
            unaryExp.children.add(tokens.get(curPos).token2node(unaryExp));
            curPos++;

            child = FuncRParams();
            if (child != null) {
                unaryExp.children.add(child);
                child.parent = unaryExp;
            }

            if (!Objects.equals(tokens.get(curPos).word, ")")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "j"));
                Token missToken = new Token(")", LexType.RPARENT, curLine);
                unaryExp.children.add(missToken.token2node(unaryExp));
                return unaryExp;
            }
            unaryExp.children.add(tokens.get(curPos).token2node(unaryExp));
            curPos++;

            System.out.println("unary");
            return unaryExp;
        }

        child = UnaryOp();
        if (child == null) {
            curPos = startPos;
            return null;
        }
        unaryExp.children.add(child);
        child.parent = unaryExp;

        child = UnaryExp();
        if (child == null) {
            curPos = startPos;
            return null;
        }
        unaryExp.children.add(child);
        child.parent = unaryExp;

        System.out.println("unary");
        return unaryExp;
    }

    private GramNode PrimaryExp() {
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character
        int startPos = curPos;
        GramNode primaryExp = new GramNode();
        primaryExp.gramType = GramType.PrimaryExp;

        GramNode child;

        if (Objects.equals(tokens.get(curPos).word, "(")) {
            primaryExp.children.add(tokens.get(curPos).token2node(primaryExp));
            curPos++;

            child = Exp();
            if (child == null) {
                curPos = startPos;
                return null;
            }
            primaryExp.children.add(child);
            child.parent = primaryExp;

            if (!Objects.equals(tokens.get(curPos).word, ")")) {
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "j"));
                Token missToken = new Token(")", LexType.RPARENT, curLine);
                primaryExp.children.add(missToken.token2node(primaryExp));
                return primaryExp;
            }
            primaryExp.children.add(tokens.get(curPos).token2node(primaryExp));
            curPos++;

            System.out.println("primary");
            return primaryExp;
        }

        child = LVal();
        if (child != null) {
            primaryExp.children.add(child);
            child.parent = primaryExp;
            System.out.println("primary");
            return primaryExp;
        }

        if (tokens.get(curPos).type == LexType.INTCON) {
            GramNode number = new GramNode();
            number.gramType = GramType.Number;
            number.parent = primaryExp;
            number.children.add(tokens.get(curPos).token2node(number));

            primaryExp.children.add(number);
            curPos++;
            System.out.println("primary");
            return primaryExp;
        }

        if (tokens.get(curPos).type == LexType.CHRCON) {
            GramNode character = new GramNode();
            character.gramType = GramType.Character;
            character.parent = primaryExp;
            character.children.add(tokens.get(curPos).token2node(character));

            primaryExp.children.add(character);
            curPos++;
            System.out.println("primary");
            return primaryExp;
        }

        curPos = startPos;
        return null;
    }

    private GramNode LVal() {
        // LVal → Ident ['[' Exp ']'] 
        int startPos = curPos;
        GramNode lVal = new GramNode();
        lVal.gramType = GramType.LVal;

        if(tokens.get(curPos).type != LexType.IDENFR || tokens.get(curPos+1).type == LexType.LPARENT) {
            curPos = startPos;
            return null;
        }else lVal.children.add(tokens.get(curPos++).token2node(lVal));

        if(Objects.equals(tokens.get(curPos).word, "[")){
            lVal.children.add(tokens.get(curPos).token2node(lVal));
            curPos++;

            GramNode child = Exp();
            if(child == null) {
                curPos = startPos;
                return null;
            }
            lVal.children.add(child);
            child.parent = lVal;

            if(!Objects.equals(tokens.get(curPos).word, "]")){
                int curLine = tokens.get(curPos-1).line;
                errors.add(new Error(curLine, "k"));
                Token missToken = new Token("]", LexType.RBRACK, curLine);
                lVal.children.add(missToken.token2node(lVal));
                return lVal;
            }
            lVal.children.add(tokens.get(curPos).token2node(lVal));
            curPos++;
        }
        System.out.println("lVal");
        return lVal;
    }

    private GramNode FuncRParams() {
        //FuncRParams → Exp { ',' Exp }
        int startPos = curPos;
        GramNode funcRParams = new GramNode();
        funcRParams.gramType = GramType.FuncRParams;

        GramNode child = Exp();
        if(child == null) {
            curPos = startPos;
            return null;
        }
        funcRParams.children.add(child);
        child.parent = funcRParams;

        while (Objects.equals(tokens.get(curPos).word, ",")) {
            funcRParams.children.add(tokens.get(curPos).token2node(funcRParams));
            curPos++;
            child = Exp();
            if(child == null) {
                curPos = startPos;
                return null;
            }
            funcRParams.children.add(child);
            child.parent = funcRParams;
        }

        System.out.println("funcRParams");
        return funcRParams;

    }

    private GramNode Exp() {
        //Exp → AddExp
        int startPos = curPos;
        GramNode exp = new GramNode();
        exp.gramType = GramType.Exp;

        GramNode child = AddExp();
        if(child == null) {
            curPos = startPos;
            return null;
        }
        exp.children.add(child);
        child.parent = exp;

        System.out.println("exp");
        return exp;
    }

    private GramNode UnaryOp() {
        // UnaryOp → '+' | '−' | '!'
        int startPos = curPos;
        GramNode unaryOp = new GramNode();
        unaryOp.gramType = GramType.UnaryOp;

        if(!Objects.equals(tokens.get(curPos).word, "+") && !Objects.equals(tokens.get(curPos).word, "-") && !Objects.equals(tokens.get(curPos).word, "!")) {
            curPos = startPos;
            return null;
        }
        unaryOp.children.add(tokens.get(curPos).token2node(unaryOp));
        curPos++;

        System.out.println("op");
        return unaryOp;
    }
}
