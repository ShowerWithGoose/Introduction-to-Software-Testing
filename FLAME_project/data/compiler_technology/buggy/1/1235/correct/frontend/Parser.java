package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Parser {
    private final String outputPathTrue;
    private final String outputPathFalse;
    private final List<Token> tokens;
    private final ArrayList<String> grammars = new ArrayList<>();
    private int currentTokenIndex = 0;
    private Token currentToken = null;


    // 获取当前 token
    private Token getCurrentToken() {
        if (currentTokenIndex < tokens.size()) {
            return tokens.get(currentTokenIndex);
        }
        return null;
    }

    // 获取下一个 token
    private Token getNextToken() {
        grammars.add(currentToken.writeString());
        currentTokenIndex++;
        if (currentTokenIndex < tokens.size()) {
            return tokens.get(currentTokenIndex);
        }
        return null;
    }

    // 获取上一个 token
    private Token getLastToken() {
        return tokens.get(currentTokenIndex - 1);
    }



    // 检查当前 token 的类型是否匹配
    private boolean checkToken(Token token, String expectedType) {
        return token != null && token.getType().equals(expectedType);
    }

    // 获取文件路径
    public Parser(List<Token> tokens, String outputPathTrue, String outputPathFalse) throws IOException {
        this.tokens = tokens;;
        this.outputPathTrue = outputPathTrue;
        this.outputPathFalse = outputPathFalse;
    }

    // 主函数
    public void analysis() throws IOException {
        currentToken = getCurrentToken();
        ParseTreeNode root = parseCompUnit();
        ParseTreeNode.setRootNode(root);
    }

    // CompUnit → {Decl} {FuncDef} MainFuncDef
    private ParseTreeNode parseCompUnit() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<CompUnit>");

        while (checkToken(currentToken, "CONSTTK")
                || ((checkToken(currentToken, "INTTK") || checkToken(currentToken, "CHARTK"))
                && checkToken(tokens.get(currentTokenIndex + 1), "IDENFR")
                && !checkToken(tokens.get(currentTokenIndex + 2), "LPARENT"))) {
            node.addChild(parseDecl());
        }
        while ((checkToken(currentToken, "INTTK") || checkToken(currentToken, "CHARTK") || checkToken(currentToken, "VOIDTK"))
                && checkToken(tokens.get(currentTokenIndex + 1), "IDENFR")
                && checkToken(tokens.get(currentTokenIndex + 2), "LPARENT")) {
            node.addChild(parseFuncDef());
        }
        if(checkToken(currentToken, "INTTK") && checkToken(tokens.get(currentTokenIndex + 1), "MAINTK") && checkToken(tokens.get(currentTokenIndex + 2), "LPARENT")){
            node.addChild(parseMainFuncDef());
        }else {
            error();
        }

        grammars.add("<CompUnit>");
        return node;
    }

    // Decl → ConstDecl | VarDecl
    private ParseTreeNode parseDecl() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Decl>");

        if (checkToken(currentToken, "CONSTTK")) {
            node.addChild(parseConstDecl());
        } else if (checkToken(currentToken, "INTTK") || checkToken(currentToken, "CHARTK")) {
            node.addChild(parseVarDecl());
        }

        // grammars.add("<Decl>");
        return node;
    }

    //  ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    //  i
    private ParseTreeNode parseConstDecl() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<ConstDecl>");

        // const
        if(!checkToken(currentToken, "CONSTTK")){
            error();
        }else {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            node.addChild(parseBType()); // 解析 BType
            node.addChild(parseConstDef()); // 解析 ConstDef

            while (checkToken(getCurrentToken(), "COMMA")) {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ','
                currentToken = getNextToken();
                node.addChild(parseConstDef()); // 解析 ConstDef
            }

            if (!checkToken(getCurrentToken(), "SEMICN")) {
                errorHanding_I();
            } else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }
        }

        grammars.add("<ConstDecl>");
        return node;
    }

    //  BType → 'int' | 'char'
    private ParseTreeNode parseBType() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<BType>");

        if(!checkToken(currentToken, "INTTK") && !checkToken(currentToken, "CHARTK")){
            error();
        }else {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        }
        // grammars.add("<BType>");
        return node;
    }

    //  ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    //  k
    private ParseTreeNode parseConstDef() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<ConstDef>");

        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 Ident
        currentToken = getNextToken();

        if (checkToken(currentToken, "LBRACK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '['
            currentToken = getNextToken();

            node.addChild(parseConstExp()); // 解析 ConstExp
            if (!checkToken(getCurrentToken(), "RBRACK")) {
                errorHanding_K();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ']'
                currentToken = getNextToken();
            }
        }

        if(!checkToken(currentToken, "ASSIGN")) {
            error();
        }else {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '='
            currentToken = getNextToken();

            node.addChild(parseConstInitVal()); // 解析 ConstInitVal
        }

        grammars.add("<ConstDef>");
        return node;
    }

    //  ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ParseTreeNode parseConstInitVal() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<ConstInitVal>");

        if (checkToken(getCurrentToken(), "LBRACE")) {
            // 情况 2: 一维数组初值，花括号 '{'
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '{'
            currentToken = getNextToken();

            if (!checkToken(currentToken, "RBRACE")) {
                node.addChild(parseConstExp()); // 解析第一个 ConstExp

                // 处理逗号分隔的多个 ConstExp
                while (checkToken(getCurrentToken(), "COMMA")) {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ','
                    currentToken = getNextToken();

                    node.addChild(parseConstExp());
                }
            }

            if(checkToken(currentToken, "RBRACE")) {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '}'
                currentToken = getNextToken();
            }else {
                error();
            }
        } else if (checkToken(getCurrentToken(), "STRCON")) {
            // 情况 3: 字符串常量初值
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 StringConst
            currentToken = getNextToken();
        } else {
            // 情况 1: 常表达式初值
            node.addChild(parseConstExp()); // 解析 ConstExp
        }

        grammars.add("<ConstInitVal>");
        return node;
    }

    //  VarDecl → BType VarDef { ',' VarDef } ';'
    //  i
    private ParseTreeNode parseVarDecl() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<VarDecl>");

        node.addChild(parseBType());    // 解析 BType
        node.addChild(parseVarDef());   // 解析第一个 VarDef

        // 可选的 { ',' VarDef }
        while (checkToken(getCurrentToken(), "COMMA")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ','
            currentToken = getNextToken();

            node.addChild(parseVarDef());
        }

        // 检查是否有 ';'
        if (!checkToken(getCurrentToken(), "SEMICN")) {
            errorHanding_I();
        } else {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
            currentToken = getNextToken();
        }

        grammars.add("<VarDecl>");
        return node;
    }

    //  VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    //  VarDef → Ident [ '[' ConstExp ']' ] [ '=' InitVal ]
    //  k
    private ParseTreeNode parseVarDef() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<VarDef>");

        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 Ident
        currentToken = getNextToken();

        if (checkToken(currentToken, "LBRACK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '['
            currentToken = getNextToken();

            node.addChild(parseConstExp()); // 解析 ConstExp

            if (!checkToken(getCurrentToken(), "RBRACK")) {
                errorHanding_K();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ']'
                currentToken = getNextToken();
            }
        }

        if(checkToken(currentToken, "ASSIGN")){
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '='
            currentToken = getNextToken();

            node.addChild(parseInitVal()); // 解析 InitVal
        }

        grammars.add("<VarDef>");
        return node;
    }

    //  InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private ParseTreeNode parseInitVal() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<InitVal>");

        if (checkToken(currentToken, "LBRACE")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            // 检查是否 '}'
            if (!checkToken(currentToken, "RBRACE")) {
                node.addChild(parseExp());

                while (checkToken(currentToken, "COMMA")) {
                    node.addChild(new ParseTreeNode(currentToken.writeString()));
                    currentToken = getNextToken();

                    node.addChild(parseExp());
                }
            }

            if (!checkToken(currentToken, "RBRACE")) {
                error();
            } else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '}'
                currentToken = getNextToken();
            }
        } else if (checkToken(getCurrentToken(), "STRCON")) {
            // 处理字符串常量
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            node.addChild(parseExp()); // 解析表达式
        }

        grammars.add("<InitVal>");
        return node;
    }

    //  FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    //  j
    private ParseTreeNode parseFuncDef() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<FuncDef>");

        node.addChild(parseFuncType()); // 解析 FuncType

        // 解析 Ident (函数名)
        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 Ident
        currentToken = getNextToken();

        // 解析 '('
        if (checkToken(currentToken, "LPARENT")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
            currentToken = getNextToken();

            // 判断是不是 FuncFParams
            // FuncFParams -> FuncFParam -> BType
            if (checkToken(currentToken, "INTTK") || checkToken(currentToken, "CHARTK")) {
                node.addChild(parseFuncFParams()); // 解析参数列表
            }

            // 解析 ')'
            if (!checkToken(currentToken, "RPARENT")) {
                errorHanding_J();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                currentToken = getNextToken();

            }
            node.addChild(parseBlock());
        }else {
            error();
        }

        grammars.add("<FuncDef>");
        return node;
    }

    //  MainFuncDef → 'int' 'main' '(' ')' Block
    //  j
    private ParseTreeNode parseMainFuncDef() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<MainFuncDef>");

        if (checkToken(currentToken, "INTTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        if (checkToken(currentToken, "MAINTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        if (checkToken(currentToken, "LPARENT")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        if (checkToken(currentToken, "RPARENT")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            errorHanding_J();
        }

        node.addChild(parseBlock());

        grammars.add("<MainFuncDef>");
        return node;
    }

    //  FuncType → 'void' | 'int' | 'char'
    private ParseTreeNode parseFuncType() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<FuncType>");

        if (checkToken(currentToken, "VOIDTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else if (checkToken(currentToken, "INTTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else if (checkToken(currentToken, "CHARTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        grammars.add("<FuncType>");
        return node;
    }

    //  FuncFParams → FuncFParam { ',' FuncFParam }
    private ParseTreeNode parseFuncFParams() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<FuncFParams>");

        node.addChild(parseFuncFParam());

        while (checkToken(getCurrentToken(), "COMMA")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            node.addChild(parseFuncFParam());
        }

        grammars.add("<FuncFParams>");
        return node;
    }

    //  FuncFParam → BType Ident ['[' ']']
    //  k
    private ParseTreeNode parseFuncFParam() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<FuncFParam>");

        node.addChild(parseBType());    // 解析基本类型 BType

        // 解析标识符 Ident
        if (checkToken(getCurrentToken(), "IDENFR")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        // 检查是否存在 '[' ']'
        if (checkToken(currentToken, "LBRACK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '['
            currentToken = getNextToken();

            if (checkToken(currentToken, "RBRACK")) {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ']'
                currentToken = getNextToken();
            } else {
                errorHanding_K();
            }
        }

        grammars.add("<FuncFParam>"); // 将 FuncFParam 文法添加到文法输出中
        return node;
    }

    //  Block → '{' { BlockItem } '}'
    private ParseTreeNode parseBlock() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Block>"); // 创建 Block 语法树节点

        // 检查是否是 '{'
        if (checkToken(getCurrentToken(), "LBRACE")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '{'
            currentToken = getNextToken(); // 获取下一个 token

            // 判断是不是 '}'
            while (!checkToken(getCurrentToken(), "RBRACE")) {
                node.addChild(parseBlockItem()); // 解析 BlockItem 并将其添加到 Block 语法树中
            }

            // 检查是否是 '}'
            if (checkToken(getCurrentToken(), "RBRACE")) {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '}'
                currentToken = getNextToken();
            } else {
                error();
            }
        } else {
            error();
        }

        grammars.add("<Block>"); // 将 Block 文法添加到文法输出中
        return node;
    }

    //  BlockItem → Decl | Stmt
    private ParseTreeNode parseBlockItem() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<BlockItem>");

        // 检查当前 token，判断是声明还是语句
        if (checkToken(currentToken, "CONSTTK") || ((checkToken(currentToken, "INTTK") || checkToken(currentToken, "CHARTK")) && checkToken(tokens.get(currentTokenIndex + 1), "IDENFR"))) {
            node.addChild(parseDecl()); // 解析声明
        } else {
            node.addChild(parseStmt()); // 解析语句
        }

        //  grammars.add("<BlockItem>");
        return node;
    }

    /*  Stmt →  | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                | 'break' ';'
                | 'continue' ';'
                | 'return' [Exp] ';'
                | 'printf''('StringConst {','Exp}')'';'
                | Block
                | LVal '=' (Exp | 'getint''('')' | 'getchar''('')') ';'
                | [Exp] ';'
     */
    //  i j
    private ParseTreeNode parseStmt() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Stmt>");

        //  'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //  j
        if (checkToken(getCurrentToken(), "IFTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'if'
            currentToken = getNextToken();

            if (!checkToken(getCurrentToken(), "LPARENT")) {
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
                currentToken = getNextToken();
            }

            node.addChild(parseCond()); // 解析条件表达式

            if (!checkToken(getCurrentToken(), "RPARENT")) {
                errorHanding_J();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                currentToken = getNextToken();
            }

            node.addChild(parseStmt()); // 解析 if 语句体

            if (checkToken(currentToken, "ELSETK")) {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'else'
                currentToken = getNextToken();

                node.addChild(parseStmt()); // 解析 else 语句体
            }
        }
        //  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //  i j ???
        else if (checkToken(getCurrentToken(), "FORTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'for'
            currentToken = getNextToken();

            if (!checkToken(getCurrentToken(), "LPARENT")) {
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
                currentToken = getNextToken();
            }

            // ForStmt → LVal '=' Exp
            // LVal → Ident ['[' Exp ']']
            if (checkToken(currentToken, "IDENFR")) {
                node.addChild(parseForStmt());
            }

            if (!checkToken(getCurrentToken(), "SEMICN")) {
                //errorHanding_I();
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }

            // 可选的 Cond
            // First(Cond) : '(' | ident | '+' | '-' | '!' | num | char
            if (checkToken(currentToken, "LPARENT")
                    || checkToken( currentToken, "IDENFR")
                    || checkToken( currentToken, "PLUS")
                    || checkToken( currentToken, "MINU")
                    || checkToken( currentToken, "NOT")
                    || checkToken( currentToken, "INTCON")
                    || checkToken( currentToken, "CHRCON")) {
                node.addChild(parseCond()); // 解析条件
            }

            if (!checkToken(getCurrentToken(), "SEMICN")) {
               // errorHanding_I();
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }

            // 解析 ForStmt
            if (checkToken(currentToken, "IDENFR")) {
                node.addChild(parseForStmt());
            }

            if (!checkToken(getCurrentToken(), "RPARENT")) {
                //errorHanding_J();
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                currentToken = getNextToken();
            }

            node.addChild(parseStmt()); // 解析循环体
        }
        //  'break' ';'
        //  i
        else if (checkToken(getCurrentToken(), "BREAKTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'break'
            currentToken = getNextToken();

            if (!checkToken(getCurrentToken(), "SEMICN")) {
                errorHanding_I();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }
        }
        //  'continue' ';'
        //  i
        else if (checkToken(getCurrentToken(), "CONTINUETK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'continue'
            currentToken = getNextToken();

            if (!checkToken(getCurrentToken(), "SEMICN")) {
                errorHanding_I();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }
        }
        //  'return' [Exp] ';'
        //  i
        else if (checkToken(getCurrentToken(), "RETURNTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'return'
            currentToken = getNextToken();

            if (checkToken(currentToken, "LPARENT")
                    || checkToken(currentToken, "IDENFR")
                    || checkToken(currentToken, "INTCON")
                    || checkToken(currentToken, "CHRCON")
                    || checkToken(currentToken, "PLUS")
                    || checkToken(currentToken, "MINU")
                    || checkToken(currentToken, "NOT")) {
                node.addChild(parseExp());
            }

            if(!checkToken(currentToken, "SEMICN")){
                errorHanding_I();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }
        }
        //  'printf''('StringConst {','Exp}')'';'
        //  i j
        else if (checkToken(getCurrentToken(), "PRINTFTK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 'printf'
            currentToken = getNextToken();

            if (!checkToken(getCurrentToken(), "LPARENT")) {
                error();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
                currentToken = getNextToken();

                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 StringConst
                currentToken = getNextToken();

                // 可选的表达式
                while (checkToken(getCurrentToken(), "COMMA")) {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ','
                    currentToken = getNextToken();

                    node.addChild(parseExp()); // 解析表达式
                }

                if (!checkToken(getCurrentToken(), "RPARENT")) {
                    errorHanding_J();
                }else {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                    currentToken = getNextToken();
                }

                if (!checkToken(getCurrentToken(), "SEMICN")) {
                    errorHanding_I();
                }else {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                    currentToken = getNextToken();
                }
            }
        }
        // Block
        else if (checkToken(getCurrentToken(), "LBRACE")) {
            node.addChild(parseBlock()); // 解析代码块
        }
        //  LVal '=' (Exp | 'getint''('')' | 'getchar''('')') ';'
        //  i j
        //  注意 [Exp] ';'
        //  Exp -> AddExp -> MulExp -> UnaryExp -> PrimaryExp -> LVaL
        else if (checkToken(currentToken, "IDENFR") && !checkToken(tokens.get(currentTokenIndex + 1), "LPARENT")) {
            Token next1Token = tokens.get(currentTokenIndex + 1);

            int i = 2;
            if (checkToken(next1Token, "LBRACK")) {
                next1Token = tokens.get(currentTokenIndex + i);
                i++;

                while (!checkToken(next1Token, "RBRACK")        // ]
                        && !checkToken(next1Token, "ASSIGN")    // =
                        && !checkToken(next1Token, "SEMICN")    // ;
                        && !checkToken(next1Token, "IFTK")      // if
                        && !checkToken(next1Token, "ELSETK")    // else
                        && !checkToken(next1Token, "WHILETK")   // while
                        && !checkToken(next1Token, "BREAKTK")   // break
                        && !checkToken(next1Token, "CONTINUETK") // continue
                        && !checkToken(next1Token, "RETURNTK")  // return
                        && !checkToken(next1Token, "PRINTFTK")){ // printf
                    next1Token = tokens.get(currentTokenIndex + i);
                    i++;
                }
                if(checkToken(next1Token, "RBRACK")) {
                    next1Token = tokens.get(currentTokenIndex + i);
                }
            }
            // Exp -> AddExp -> MulExp -> UnaryExp -> PrimaryExp -> LVaL
            if(!checkToken(next1Token, "ASSIGN")){
                node.addChild(parseExp());

                if(!checkToken(currentToken, "SEMICN")){
                    errorHanding_I();
                }else {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                    currentToken = getNextToken();
                }
            }
            // LVaL '='
            else {
                node.addChild(parseLVal()); // 解析 LVal

                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '='
                currentToken = getNextToken();

                // 解析右侧表达式
                if (checkToken(currentToken, "GETINTTK") || checkToken(currentToken, "GETCHARTK")) {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 getint 或 getchar
                    currentToken = getNextToken();

                    if (!checkToken(getCurrentToken(), "LPARENT")) {
                        error();
                    }else {
                        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
                        currentToken = getNextToken();
                    }

                    if (!checkToken(getCurrentToken(), "RPARENT")) {
                        errorHanding_J();
                    }else {
                        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                        currentToken = getNextToken();
                    }

                } else {
                    node.addChild(parseExp()); // 解析表达式
                }


                if (!checkToken(getCurrentToken(), "SEMICN")) {
                    errorHanding_I();
                }else {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                    currentToken = getNextToken();
                }
            }
        }
        //  [Exp] ';'
        //  i
        else {
            if (checkToken(currentToken, "LPARENT")
                    || checkToken(currentToken, "IDENFR")
                    || checkToken(currentToken, "INTCON")
                    || checkToken(currentToken, "CHRCON")
                    || checkToken(currentToken, "PLUS")
                    || checkToken(currentToken, "MINU")
                    || checkToken(currentToken, "NOT")) {
                node.addChild(parseExp());
            }

            if (!checkToken(getCurrentToken(), "SEMICN")) {
                errorHanding_I();
            }else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ';'
                currentToken = getNextToken();
            }
        }

        grammars.add("<Stmt>");
        return node;
    }

    //  ForStmt → LVal '=' Exp
    private ParseTreeNode parseForStmt() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<ForStmt>");

        node.addChild(parseLVal());

        if (!checkToken(getCurrentToken(), "ASSIGN")) {
            error();
        }else {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            node.addChild(parseExp());
        }

        grammars.add("<ForStmt>");
        return node;
    }

    //  Exp → AddExp
    private ParseTreeNode parseExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Exp>");

        node.addChild(parseAddExp());

        grammars.add("<Exp>");
        return node;
    }

    //  Cond → LOrExp
    private ParseTreeNode parseCond() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Cond>");

        node.addChild(parseLOrExp());

        grammars.add("<Cond>");
        return node;
    }

    //  LVal → Ident ['[' Exp ']']
    //  k
    private ParseTreeNode parseLVal() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<LVal>");

        node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 Ident
        currentToken = getNextToken();

        if (checkToken(currentToken, "LBRACK")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '['
            currentToken = getNextToken();

            node.addChild(parseExp()); // 解析表达式

            if (!checkToken(currentToken, "RBRACK")) {
                errorHanding_K();
            } else {
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ']'
                currentToken = getNextToken();
            }
        }

        grammars.add("<LVal>");
        return node;
    }

    //  PrimaryExp → '(' Exp ')' | LVal | Number | Character
    //  j
    private ParseTreeNode parsePrimaryExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<PrimaryExp>");

        if (checkToken(currentToken, "LPARENT")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
            currentToken = getNextToken();

            node.addChild(parseExp()); // 解析表达式

            if (!checkToken(currentToken, "RPARENT")) { // ')'
                errorHanding_J();
            } else {
                node.addChild(new ParseTreeNode(currentToken.writeString()));
                currentToken = getNextToken();
            }
        } else if (checkToken(currentToken, "IDENFR")) { // LVal
            node.addChild(parseLVal());
        } else if (checkToken(currentToken, "INTCON")) { // Number
            node.addChild(parseNumber());
        } else if (checkToken(currentToken, "CHRCON")) { // Character
            node.addChild(parseCharacter());
        } else {
            error();
        }

        grammars.add("<PrimaryExp>");
        return node; // 返回解析树节点
    }

    //  Number → IntConst
    private ParseTreeNode parseNumber() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Number>");

        if (checkToken(currentToken, "INTCON")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        grammars.add("<Number>");
        return node;
    }

    //  Character → CharConst
    private ParseTreeNode parseCharacter() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<Character>");

        if (checkToken(currentToken, "CHRCON")) {
            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        grammars.add("<Character>");
        return node;
    }

    //  UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    //  j
    private ParseTreeNode parseUnaryExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<UnaryExp>");

        if (checkToken(currentToken, "IDENFR")
                && checkToken(tokens.get(currentTokenIndex + 1), "LPARENT")) { // Ident '(' [FuncRParams] ')'
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 Ident
            currentToken = getNextToken();

            if (checkToken(currentToken, "LPARENT")) { // '('
                node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 '('
                currentToken = getNextToken();

                if (checkToken(currentToken, "LPARENT")
                        || checkToken(currentToken, "IDENFR")
                        || checkToken(currentToken, "INTCON")
                        || checkToken(currentToken, "CHRCON")
                        || checkToken(currentToken, "PLUS")
                        || checkToken(currentToken, "MINU")
                        || checkToken(currentToken, "NOT")) {
                    node.addChild(parseFuncRParams());
                }

                if (!checkToken(currentToken, "RPARENT")) {
                    errorHanding_J();
                }else {
                    node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ')'
                    currentToken = getNextToken();
                }
            }
        } else if (checkToken(currentToken, "PLUS")
                || checkToken(currentToken, "MINU")
                || checkToken(currentToken, "NOT")) { // UnaryOp

            node.addChild(parseUnaryOp()); // 添加 UnaryOp

            node.addChild(parseUnaryExp()); // 递归解析 UnaryExp

        } else { // PrimaryExp
            node.addChild(parsePrimaryExp());
        }

        grammars.add("<UnaryExp>");
        return node;
    }

    //   UnaryOp → '+' | '−' | '!'
    private ParseTreeNode parseUnaryOp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<UnaryOp>");

        // 检查当前 token 是否是 '+'、'−' 或 '!'
        if (checkToken(currentToken, "PLUS")
                || checkToken(currentToken, "MINU")
                || checkToken(currentToken, "NOT")) {

            node.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();
        } else {
            error();
        }

        grammars.add("<UnaryOp>");
        return node;
    }

    //  FuncRParams → Exp { ',' Exp }
    private ParseTreeNode parseFuncRParams() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<FuncRParams>");

        node.addChild(parseExp());

        while (checkToken(getCurrentToken(), "COMMA")) {
            node.addChild(new ParseTreeNode(currentToken.writeString())); // 添加 ','
            currentToken = getNextToken();

            node.addChild(parseExp());
        }

        grammars.add("<FuncRParams>");
        return node;
    }

    //  MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
    //  MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private ParseTreeNode parseMulExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<MulExp>");

        node.addChild(parseUnaryExp());

        while (checkToken(getCurrentToken(), "MULT") ||
                checkToken(getCurrentToken(), "DIV") ||
                checkToken(getCurrentToken(), "MOD")) {
            ParseTreeNode recursiveNode = new ParseTreeNode("<MulExp>");
            recursiveNode.addChild(node);
            grammars.add("<MulExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseUnaryExp());

            node = recursiveNode;
        }

        grammars.add("<MulExp>");
        return node;
    }

    //  AddExp → MulExp { ('+' | '−') MulExp }
    //  AddExp → MulExp | AddExp ('+' | '−') MulExp
    private ParseTreeNode parseAddExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<AddExp>");

        node.addChild(parseMulExp());

        while (checkToken(getCurrentToken(), "PLUS") || checkToken(getCurrentToken(), "MINU")) {
            ParseTreeNode recursiveNode = new ParseTreeNode("<AddExp>");
            recursiveNode.addChild(node);
            grammars.add("<AddExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseMulExp());

            node = recursiveNode;
        }

        grammars.add("<AddExp>");
        return node;
    }

    //  RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    //  RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private ParseTreeNode parseRelExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<RelExp>");

        node.addChild(parseAddExp());

        while (checkToken(getCurrentToken(), "LSS") ||  // '<'
                checkToken(getCurrentToken(), "GRE") ||  // '>'
                checkToken(getCurrentToken(), "LEQ") ||  // '<='
                checkToken(getCurrentToken(), "GEQ")) {

            ParseTreeNode recursiveNode = new ParseTreeNode("<RelExp>");
            recursiveNode.addChild(node);
            grammars.add("<RelExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseAddExp());

            node = recursiveNode;
        }

        grammars.add("<RelExp>");
        return node;
    }

    //  EqExp → RelExp { ('==' | '!=') RelExp }
    //  EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private ParseTreeNode parseEqExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<EqExp>");

        node.addChild(parseRelExp());

        while (checkToken(getCurrentToken(), "EQL") || checkToken(getCurrentToken(), "NEQ")) {
            ParseTreeNode recursiveNode = new ParseTreeNode("<EqExp>");
            recursiveNode.addChild(node);
            grammars.add("<EqExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseRelExp());

            node = recursiveNode;
        }

        grammars.add("<EqExp>");
        return node;
    }

    //  LAndExp → EqExp { '&&' EqExp }
    //  LAndExp → EqExp | LAndExp '&&' EqExp
    private ParseTreeNode parseLAndExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<LAndExp>");

        node.addChild(parseEqExp());

        while (checkToken(getCurrentToken(), "AND")) {  // '&&' 的类别码
            ParseTreeNode recursiveNode = new ParseTreeNode("<LAndExp>");
            recursiveNode.addChild(node);
            grammars.add("<LAndExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseEqExp());

            node = recursiveNode;
        }

        grammars.add("<LAndExp>");
        return node;
    }

    //  LOrExp → LAndExp { '||' LAndExp }
    //  LOrExp → LAndExp | LOrExp '||' LAndExp
    private ParseTreeNode parseLOrExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<LOrExp>");

        node.addChild(parseLAndExp());

        while (checkToken(getCurrentToken(), "OR")) {  // '||' 的类别码
            ParseTreeNode recursiveNode = new ParseTreeNode("<LOrExp>");
            recursiveNode.addChild(node);
            grammars.add("<LOrExp>");

            recursiveNode.addChild(new ParseTreeNode(currentToken.writeString()));
            currentToken = getNextToken();

            recursiveNode.addChild(parseLAndExp());

            node = recursiveNode;
        }

        grammars.add("<LOrExp>");
        return node;
    }

    //  ConstExp → AddExp
    private ParseTreeNode parseConstExp() throws IOException {
        ParseTreeNode node = new ParseTreeNode("<ConstExp>");

        node.addChild(parseAddExp());

        grammars.add("<ConstExp>");
        return node;
    }


    // 错误处理：缺少分号 ;
    private void errorHanding_I(){
        int lineNum = getLastToken().getLineNum();
        Error error = new Error(";", "i", lineNum);
        error.addErrors(error);
    }

    // 错误处理：缺少右小括 )
    private void errorHanding_J(){
        int lineNum = getLastToken().getLineNum();
        Error error = new Error(")", "j", lineNum);
        error.addErrors(error);
    }

    // 错误处理：缺少右中括号 ]
    private void errorHanding_K(){
        int lineNum = getLastToken().getLineNum();
        Error error = new Error("]", "k", lineNum);
        error.addErrors(error);
    }

    private void error(){
    }

    public void writeTokensToFile() throws IOException {
        BufferedWriter trueFile = new BufferedWriter(new FileWriter(outputPathTrue));
        for(String token: grammars){
            trueFile.write(token);
            trueFile.newLine();
        }
        trueFile.flush();
        trueFile.close();
    }

    public void writeErrorsToFile() throws IOException {
        BufferedWriter falseFile = new BufferedWriter(new FileWriter(outputPathFalse));
        List<Error> errors = new ArrayList<>();
        Error errorAll = new Error();
        errorAll.sortErrors();
        errors = errorAll.getErrors();
        for(Error error: errors){
            falseFile.write(error.writeString());
            falseFile.newLine();
        }
        falseFile.flush();
        falseFile.close();
    }
}
