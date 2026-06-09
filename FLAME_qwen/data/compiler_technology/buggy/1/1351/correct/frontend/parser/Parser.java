package frontend.parser;

import frontend.BinaryType;
import frontend.DataType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import output.MyStream;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Parser {
    private final TokenList tokenList;
    private static final HashMap<BinaryType, BinaryType> downMap = new HashMap<>();
    
    static {
        downMap.put(BinaryType.LOR, BinaryType.LAND);
        downMap.put(BinaryType.LAND, BinaryType.EQ);
        downMap.put(BinaryType.EQ, BinaryType.REL);
        downMap.put(BinaryType.REL, BinaryType.ADD);
        downMap.put(BinaryType.ADD, BinaryType.MUL);
    }

    public Parser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    //CompUnit → {Decl} {FuncDef} MainFuncDef
    public Ast parse() throws IOException {
        ArrayList<Ast.CompUnit> nodes = new ArrayList<>();
        Ast ast = new Ast(nodes);
        while (tokenList.hasNext()) {
            if (tokenList.look(2).getType() == TokenType.LPARENT) {
                nodes.add(parseFuncDef());
            } else {
                nodes.add(parseDecl());
            }
        }
        MyStream.printParser("<CompUnit>\n");
        return ast;
    }

    /*
    * anon: 规定所有的解析语法函数，都只能读取到自己的范围结束，不能越界
    * */
    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private Ast.FuncDef parseFuncDef() throws IOException {
        Token funcType = tokenList.getAndAdd();
        Token ident = tokenList.look(0);
        if (!ident.getContent().equals("main")) {
            MyStream.printParser("<FuncType>\n");
        }
        tokenList.skip(); // 'ident'
        ArrayList<Ast.FuncFParam> params = new ArrayList<>();

        /*
        * anon：
        *  当前第一个是（ =》 跳过，看是否为）
        *  解析参数后剩下的是 ），{
        * */
        tokenList.skip(); // ’(‘
        while (tokenList.look(0).getType() != TokenType.RPARENT) {
            if (tokenList.look(0).getType() == TokenType.LBRACE) {
                break;
            }
            if (tokenList.look(0).getType() == TokenType.COMMA) {
                tokenList.skip();
            }
            params.add(parseFuncFParam());//anon：要保证不会把）或，读走
        }
        if (!params.isEmpty()) {
            MyStream.printParser("<FuncFParams>\n");
        }
        err(TokenType.RPARENT);
        //anon: 当前的为左大括号
        Ast.Block block = parseBlock();
        if (ident.getContent().equals("main")) {
            MyStream.printParser("<MainFuncDef>\n");
        } else {
            MyStream.printParser("<FuncDef>\n");
        }
        return new Ast.FuncDef(funcType.getType().downToDataType(), ident, params, block);
    }

    //anon:会留下一个，或者（
    private Ast.FuncFParam parseFuncFParam() throws IOException {
        DataType type = tokenList.getAndAdd().getType().downToDataType();
        Token ident = tokenList.getAndAdd();
        boolean isArray = false;
        if (tokenList.look(0).getType() == TokenType.LBRACK) {
            isArray = true;
            tokenList.skip();
            err(TokenType.RBRACK);
        }
        MyStream.printParser("<FuncFParam>\n");
        return new Ast.FuncFParam(type, ident, isArray);
    }

    private Ast.Block parseBlock() throws IOException {
        tokenList.skip(); //'{'
        ArrayList<Ast.BlockItem> blockItems = new ArrayList<>();
        while (tokenList.look(0).getType() != TokenType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        tokenList.skip(); //'}'
        MyStream.printParser("<Block>\n");
        return new Ast.Block(blockItems);
    }

    private Ast.BlockItem parseBlockItem() throws IOException {
        TokenType type = tokenList.look(0).getType();
        if (type ==  TokenType.INTTK || type == TokenType.CHARTK || type == TokenType.CONSTTK) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    private Ast.Stmt parseStmt() throws IOException {
        TokenType curType = tokenList.look(0).getType();
        Ast.Stmt stmt = null;
        switch (curType) {
            case LBRACE -> stmt = parseBlock();
            case IFTK -> stmt = parseIfStmt();
            case FORTK -> stmt = parseLoopStmt();
            case BREAKTK -> stmt = parseBreakStmt();
            case CONTINUETK -> stmt = parseContinueStmt();
            case RETURNTK -> stmt = parseReturnStmt();
            case PRINTFTK -> stmt = parsePrintfStmt();
            case IDENFR -> stmt = parseAssign();
            default -> {
                stmt = parseExpStmt();
            }

        }

        //if (curType == TokenType.LBRACE) {
        //    stmt = parseBlock();
        //} else if (curType == TokenType.IFTK) {
        //    stmt = parseIfStmt();
        //} else if (curType == TokenType.FORTK) {
        //    stmt = parseLoopStmt();
        //} else if (curType == TokenType.BREAKTK) {
        //    stmt = parseBreakStmt();
        //} else if (curType == TokenType.CONTINUETK) {
        //    stmt = parseContinueStmt();
        //} else if (curType == TokenType.RETURNTK) {
        //    stmt = parseReturnStmt();
        //} else if (curType ==  TokenType.PRINTFTK) {
        //    stmt = parsePrintfStmt();
        //} else if (curType == TokenType.IDENFR) {
        //    stmt = parseAssign();
        //} else {
        //    stmt = new Ast.ExpStmt(parseExp(false));
        //    tokenList.skip();
        //}
        MyStream.printParser("<Stmt>\n");
        return stmt;
    }

    private Ast.ExpStmt parseExpStmt() throws IOException {
        Ast.ExpStmt expStmt = new Ast.ExpStmt(parseExp(false));
        err(TokenType.SEMICN);
        return expStmt;
    }

    private Ast.Stmt parseAssign() throws IOException {
        boolean isAssign = false;
        if (tokenList.look(1).getType() == TokenType.LBRACK) {
            int cnt = 2;
            while (true) {
                if (tokenList.look(cnt).getType() == TokenType.ASSIGN) {
                    isAssign = true;
                    break;
                } else if (tokenList.look(cnt).getType() == TokenType.SEMICN) {
                    break;
                }
                cnt++;
            }
        } else {
            isAssign = tokenList.look(1).getType() == TokenType.ASSIGN;
        }
        if (!isAssign) {
            return parseExpStmt();
        }
        Ast.LVal lVal = parseLVal();
        Ast.Stmt stmt = null;
        tokenList.skip(); //'='
        if (tokenList.look(0).getType() == TokenType.GETINTTK) {
            tokenList.skip(); //'getint'
            tokenList.skip(); //'('
            err(TokenType.RPARENT);
            err(TokenType.SEMICN);
            stmt = new Ast.GetIntStmt(lVal);
        } else if (tokenList.look(0).getType() == TokenType.GETCHARTK) {
            tokenList.skip();
            tokenList.skip();
            err(TokenType.RPARENT);
            err(TokenType.SEMICN);
            stmt = new Ast.GetCharStmt(lVal);
        } else {
            Ast.Exp exp = parseExp(false);
            err(TokenType.SEMICN);
            stmt = new Ast.Assign(lVal, exp);
        }
        return stmt;
    }

    private void err(TokenType type) throws IOException {
        String str = switch (type) {
            case SEMICN -> "i";
            case RPARENT -> "j";
            case RBRACK -> "k";
            default -> "something wrong";
        };
        if (tokenList.look(0).getType() != type) {
            MyStream.errThrow(tokenList.look(-1).getLineNo(), str);
        } else {
            tokenList.skip();
        }
    }

    private Ast.ReturnStmt parseReturnStmt() throws IOException {
        tokenList.skip();//return
        Ast.Exp exp = null;
        if (tokenList.look(0).getType() != TokenType.SEMICN) {
            exp = parseExp(false);
            err(TokenType.SEMICN);
        } else {
            tokenList.skip();
        }
        return new Ast.ReturnStmt(exp);
    }

    private Ast.PrintfStmt parsePrintfStmt() throws IOException {
        tokenList.skip();//printf
        tokenList.skip();//(
        Ast.StringConst stringConst = new Ast.StringConst(tokenList.getAndAdd().getContent());

        ArrayList<Ast.Exp> exps = new ArrayList<>();
        while (tokenList.look(0).getType() == TokenType.COMMA) {
            tokenList.skip();
            exps.add(parseExp(false));
        }
        err(TokenType.RPARENT);
        err(TokenType.SEMICN);
        return new Ast.PrintfStmt(stringConst, exps);
    }

    private Ast.ContinueStmt parseContinueStmt() throws IOException {
        tokenList.skip();
        err(TokenType.SEMICN);
        return new Ast.ContinueStmt();
    }

    private Ast.BreakStmt parseBreakStmt() throws IOException {
        tokenList.skip();
        err(TokenType.SEMICN);
        return new Ast.BreakStmt();
    }

    private Ast.LoopStmt parseLoopStmt() throws IOException {
        tokenList.skip();
        tokenList.skip();

        Ast.ForStmt begin = parseForStmt();
        tokenList.skip();

        Ast.Exp cond = null;
        if (tokenList.look(0).getType() != TokenType.SEMICN) {
            cond = parseBinaryExp(BinaryType.LOR);
            MyStream.printParser("<Cond>\n");
        }
        tokenList.skip();

        Ast.ForStmt end = parseForStmt();
        tokenList.skip();

        Ast.Stmt stmt = parseStmt();

        return new Ast.LoopStmt(begin, cond, end, stmt);
    }

    private Ast.ForStmt parseForStmt() throws IOException {
        TokenType curType = tokenList.look(0).getType();
        if (curType == TokenType.SEMICN || curType == TokenType.RPARENT) {
            return null;
        }
        Ast.LVal lVal = parseLVal();
        tokenList.skip(); //'='
        Ast.Exp exp = parseExp(false);
        MyStream.printParser("<ForStmt>\n");

        return new Ast.ForStmt(lVal, exp);
    }

    private Ast.IfStmt parseIfStmt() throws IOException {
        tokenList.skip(); // 'if'
        tokenList.skip(); // '('

        Ast.Exp cond = parseBinaryExp(BinaryType.LOR);
        MyStream.printParser("<Cond>\n");
        err(TokenType.RPARENT);

        Ast.Stmt thenStmt = parseStmt();
        Ast.Stmt elseStmt = null;

        if (tokenList.look(0).getType() == TokenType.ELSETK) {
            tokenList.skip(); // 'else'
            elseStmt = parseStmt();
        }

        return new Ast.IfStmt(cond, thenStmt, elseStmt);
    }


    private void check(TokenType type) {
//        if ()
    }

    private Ast.Decl parseDecl() throws IOException {
        boolean isConst = false;
        Token btype = tokenList.getAndAdd();
        if (btype.getType() == TokenType.CONSTTK) {
            isConst = true;
            btype = tokenList.getAndAdd();
        }
        DataType dataType = btype.getType().downToDataType();
        ArrayList<Ast.Def> defs = new ArrayList<>();
        defs.add(parseDef(dataType, isConst));
        //anon: 会留下def后的符号
        while (tokenList.look(0).getType() == TokenType.COMMA) {
            tokenList.skip();
            defs.add(parseDef(dataType, isConst));
        }
        err(TokenType.SEMICN);
        if (isConst) {
            MyStream.printParser("<ConstDecl>\n");
        } else {
            MyStream.printParser("<VarDecl>\n");
        }
        return new Ast.Decl(isConst, btype.getType().downToDataType(), defs);
    }

    private Ast.Def parseDef(DataType dataType, boolean isConst) throws IOException {
        Token ident = tokenList.getAndAdd();
        Ast.Exp length = null;
        if (tokenList.look(0).getType() == TokenType.LBRACK) {
            tokenList.skip();
            length = parseExp(true);
            err(TokenType.RBRACK);
        }
        Ast.InitValue initValue = null;
        if (isConst) {
            tokenList.skip(); // '='
            initValue = parseInitVal(isConst);
            MyStream.printParser("<ConstDef>\n");
        } else {
            if (tokenList.look(0).getType() == TokenType.ASSIGN) {
                tokenList.skip(); // '='
                initValue = parseInitVal(isConst);
            }
            MyStream.printParser("<VarDef>\n");
        }
        return new Ast.Def(dataType, ident, length, initValue);
    }
    //anon: parse之后再次需要再次get，才能得到下个token
    private Ast.InitValue parseInitVal(boolean isConst) throws IOException {
        boolean isString = false;
        boolean isSimpleArray = false;
        ArrayList<Ast.Exp> valueList = new ArrayList<>();
        Ast.StringConst stringConst = null;
        if (tokenList.look(0).getType() == TokenType.LBRACE) {
            tokenList.skip();
            //array init
            isSimpleArray = true;
            while (tokenList.look(0).getType() != TokenType.RBRACE) {
                if (tokenList.look(0).getType() == TokenType.COMMA) {
                    tokenList.skip();
                }
                valueList.add(parseExp(isConst));
            }
            tokenList.skip();
        } else if (tokenList.look(0).getType() == TokenType.STRCON) {
            //StringConst
            isString = true;
            stringConst = new Ast.StringConst(tokenList.getAndAdd().getContent());
        } else {
            valueList.add(parseExp(isConst));
        }
        if (isConst) {
            MyStream.printParser("<ConstInitVal>\n");
        } else {
            MyStream.printParser("<InitVal>\n");
        }
        return new Ast.InitValue(isString, valueList, stringConst, isSimpleArray);
    }

    // Exp -> BinaryExp | UnaryExp
    private Ast.Exp parseExp(boolean isConst) throws IOException {
        if (tokenList.look(0).getType() == TokenType.SEMICN) {
            return null;
        }
        Ast.Exp exp = parseBinaryExp(BinaryType.ADD);
        if (isConst) {
            MyStream.printParser("<ConstExp>\n");
        } else {
            MyStream.printParser("<Exp>\n");
        }
        return exp;
    }

    private Ast.Exp parseBinaryExp(BinaryType type) throws IOException {
        ArrayList<Ast.Exp> exps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        exps.add((type == BinaryType.MUL) ? parseUnaryExp() : parseBinaryExp(downMap.get(type)));
        MyStream.printParser(type.print());
        while (type.contains(tokenList.look(0).getType())) {
            ops.add(tokenList.getAndAdd().getContent());
            exps.add((type == BinaryType.MUL) ? parseUnaryExp() : parseBinaryExp(downMap.get(type)));
            MyStream.printParser(type.print());
        }
        return new Ast.BinaryExp(exps, ops);
    }

    private Ast.Exp parseUnaryExp() throws IOException {
        ArrayList<String> ops = new ArrayList<>();
        while (tokenList.look(0).getType() == TokenType.PLUS ||
                tokenList.look(0).getType() == TokenType.MINU ||
                tokenList.look(0).getType() == TokenType.NOT) {
            ops.add(tokenList.getAndAdd().getContent());
            MyStream.printParser("<UnaryOp>\n");
        }
        Ast.PrimaryExp primaryExp = parsePrimaryExp();
        MyStream.printParser("<UnaryExp>\n");
        for (int i = 0; i < ops.size(); i++) {
            MyStream.printParser("<UnaryExp>\n");
        }
        return new Ast.UnaryExp(primaryExp, ops);
    }

    // PrimaryExp -> Call | '(' Exp ')' | LVal | Number | Character
    private Ast.PrimaryExp parsePrimaryExp() throws IOException {
        Token curToken = tokenList.look(0);
        Ast.PrimaryExp primaryExp = null;
        if (curToken.getType() == TokenType.LPARENT) {
            tokenList.skip();
            primaryExp = parseExp(false);
            err(TokenType.RPARENT);
        } else if (curToken.getType() == TokenType.INTCON) {
            primaryExp = parseNumber();

        } else if (curToken.getType() == TokenType.CHRCON) {
            primaryExp = parseCharacter();

        } else if (curToken.getType() == TokenType.IDENFR) {
            if (tokenList.look(1).getType() == TokenType.LPARENT) {
                return parseCall();
            } else {
                primaryExp = parseLVal();
            }
        }
        MyStream.printParser("<PrimaryExp>\n");
        return primaryExp;
    }

    private Ast.Number parseNumber() throws IOException {
        Ast.Number number = new Ast.Number(tokenList.getAndAdd());
        MyStream.printParser("<Number>\n");
        return number;
    }

    //TODO: 转义字符？
    private Ast.Character parseCharacter() throws IOException {
        Ast.Character character = new Ast.Character(tokenList.getAndAdd());
        MyStream.printParser("<Character>\n");
        return character;
    }

    private Ast.Call parseCall() throws IOException {
        Token ident = tokenList.getAndAdd();
        tokenList.skip();
        ArrayList<Ast.Exp> params = new ArrayList<>();
        //TODO：这里的错误怎么处理？ 现在处理方式是：没有识别到右括号 就一直识别rparam
        if (tokenList.look(0).getType() != TokenType.RPARENT) {
            params.add(parseExp(false));
            while (tokenList.look(0).getType() == TokenType.COMMA) {
                tokenList.skip();
                params.add(parseExp(false));
            }
        }

        if (!params.isEmpty()) {
            MyStream.printParser("<FuncRParams>\n");
        }
        err(TokenType.RPARENT);
        return new Ast.Call(ident, params);
    }

    private Ast.LVal parseLVal() throws IOException {
        Token ident = tokenList.getAndAdd();
        Ast.Exp exp = null;
        if (tokenList.look(0).getType() == TokenType.LBRACK) {
            tokenList.skip();
            exp = parseExp(false);
            err(TokenType.RBRACK);
        }
        MyStream.printParser("<LVal>\n");
        return new Ast.LVal(ident, exp);
    }


    //TODO: 检查所有err的行号！
}
