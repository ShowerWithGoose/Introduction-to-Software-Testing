package frontend.Parser;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.Parser.Decl.ConstDeclParser;
import frontend.Parser.Decl.ConstDefParser;
import frontend.Parser.Decl.VarDeclParser;
import frontend.Parser.Decl.VarDefParser;
import frontend.Parser.Exp.UnaryExpParser;
import frontend.Parser.Func.*;
import frontend.symbol.SymbolTable;

import javax.swing.text.html.HTMLDocument;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;


public class Parser {

    public static boolean mark = false;

    public static boolean showFor = false;
    public static HashMap<Integer, ArrayList<String>> syntax = new HashMap<>();

    public static ArrayList<String> flush = new ArrayList<>();

    public static ArrayList<Integer> row = new ArrayList<>();

    public static HashMap<Integer,Integer> backFlush = new HashMap<>();


    public static void PrintTo(String a) {
        CompUnit();
        try {
            BufferedWriter parser = new BufferedWriter(new FileWriter(a));
            ArrayList<Token> tokenList = TokenList.GetList();
            for (int index = 0;index < tokenList.size();index++) {
                parser.write(tokenList.get(index).toString() + "\n");
                if (syntax.containsKey(index)) {
                    ArrayList<String> syntaxList = syntax.get(index);
                    for (int i = 0;i < syntaxList.size();i++) {
                        parser.write(syntaxList.get(i) + "\n");
                    }
                }
            }
            parser.flush();
        } catch (IOException e) {
            System.out.println("parser does not exist");
        }
    }
    public static void StoreSyntax(String a,int line) {
        if (!syntax.containsKey(line)) {
            ArrayList<String> arrayList = new ArrayList<>();
            arrayList.add(a);
            syntax.put(line,arrayList);
        } else {
            syntax.get(line).add(a);
        }
        if (mark) {
            if (backFlush.containsKey(line)) {
                backFlush.replace(line,backFlush.get(line) + 1);
            } else {
                backFlush.put(line,1);
            }
        }
    }



    private static void AddSyntax(String a,int line) {
        flush.add(a);
        row.add(line);
    }

    private static void ClearFlush() {
        flush.clear();
        row.clear();
    }

    private static void Flush() {
        for (int i = 0;i < flush.size();i++) {
            StoreSyntax(flush.get(i), row.get(i));
        }
        ClearFlush();
    }

    public static void Confirm() {
        backFlush.clear();
        mark = false;
    }

    public static void Back() {
        Iterator<Integer> iterator = backFlush.keySet().iterator();
        while (iterator.hasNext()) {
            int line = iterator.next();
            int num = backFlush.get(line);
            for (int i = 0;i < num;i++) {
                System.out.println(syntax.get(line).remove(syntax.get(line).size() - 1));
            }
        }
        Confirm();
    }

    public static boolean CompUnit() {
        int store = TokenList.GetIndex();
        while (Decl()) {
            store = TokenList.GetIndex();
        }
        TokenList.SetIndex(store);
        while (FuncDef()) {
            store = TokenList.GetIndex();
        }
        TokenList.SetIndex(store);
        if (MainFuncDef()) {
            StoreSyntax("<CompUnit>",TokenList.GetIndex() - 1);
            //System.out.println("<CompUnit>");
            return true;
        }
        return false;
    }
    public static boolean Decl() {
        int store = TokenList.GetIndex();
        if (ConstDecl()) {
            //StoreSyntax("<Decl>",TokenList.GetIndex() - 1);
            //System.out.println("<Decl>");
            return true;
        }
        TokenList.SetIndex(store);
        if (VarDecl()) {
            //StoreSyntax("<Decl>",TokenList.GetIndex() - 1);
            //System.out.println("<Decl>");
            return true;
        }
        return false;
    }

    public static boolean ConstDecl() {
        /*if (TokenList.NextIs(Category.CONSTTK) && BType() && ConstDef()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.COMMA) && ConstDef()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.SEMICN)) {
                StoreSyntax("<ConstDecl>",TokenList.GetIndex() - 1);

                //System.out.println("<ConstDecl>");
                return true;
            } else {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(), 'i'));
                StoreSyntax("<ConstDecl>", TokenList.GetIndex() - 1);
                return true;
            }
        }
        return false;*/
        ConstDeclParser constDeclParser = new ConstDeclParser();
        return constDeclParser.Parser();
    }

    public static boolean BType() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.INTTK || token.GetCategory() == Category.CHARTK) {
            //StoreSyntax("<BType>",TokenList.GetIndex() - 1);
            //System.out.println("<BType>");
            return true;
        }
        return false;
    }

    public static boolean ConstDef() {
        /*if (TokenList.NextIs(Category.IDENFR)) {
            int store = TokenList.GetIndex();
            if (TokenList.NextIs(Category.LBRACK) && ConstExp()) {
                store = TokenList.GetIndex();
                if (TokenList.NextIs(Category.RBRACK)) {
                    store = TokenList.GetIndex();
                } else {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.ASSIGN) && ConstInitVal()) {
                StoreSyntax("<ConstDef>",TokenList.GetIndex() - 1);
                //System.out.println("<ConstDef>");
                return true;
            }
        }
        return false;*/
        ConstDefParser constDefParser = new ConstDefParser();
        return constDefParser.Parser();
    }

    public static boolean ConstInitVal() {
        int store = TokenList.GetIndex();
        if (ConstExp()) {
            StoreSyntax("<ConstInitVal>",TokenList.GetIndex() - 1);
            //System.out.println("<ConstInitVal>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.LBRACE)) {
            store = TokenList.GetIndex();
            if (ConstExp()) {
                store = TokenList.GetIndex();
                while (TokenList.NextIs(Category.COMMA) && ConstExp()) {
                    store = TokenList.GetIndex();
                }
                TokenList.SetIndex(store);
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RBRACE)) {
                StoreSyntax("<ConstInitVal>",TokenList.GetIndex() - 1);
                //System.out.println("<ConstInitVal>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.STRCON)) {
            StoreSyntax("<ConstInitVal>",TokenList.GetIndex() - 1);
            //System.out.println("<ConstInitVal>");
            return true;
        }
        return false;
    }
    public static boolean VarDecl() {
        /*if (BType() && VarDef()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.COMMA) && VarDef()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<VarDecl>",TokenList.GetIndex() - 1);
            //System.out.println("<VarDecl>");
            return true;
        }
        return false;*/
        VarDeclParser varDeclParser = new VarDeclParser();
        return varDeclParser.Parser();
    }
    public static boolean VarDef() {
        /*if (TokenList.NextIs(Category.IDENFR)) {
            int store = TokenList.GetIndex();
            //防止读入一个错误的定义
            if (TokenList.NextIs(Category.LPARENT)) {
                TokenList.SetIndex(store);
                return false;
            }
            TokenList.SetIndex(store);
            ////
            if (TokenList.NextIs(Category.LBRACK) && ConstExp()) {
                store = TokenList.GetIndex();
                if (TokenList.NextIs(Category.RBRACK)) {
                    store = TokenList.GetIndex();
                } else {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                }
                if (TokenList.NextIs(Category.ASSIGN) && InitVal()) {
                    StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                    //System.out.println("<VarDef>");
                    return true;
                } else {
                    TokenList.SetIndex(store);
                    StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                    //System.out.println("<VarDef>");
                    return true;
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.ASSIGN) && InitVal()) {
                StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                //System.out.println("<VarDef>");
                return true;
            }
            TokenList.SetIndex(store);
            StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
            //System.out.println("<VarDef>");
            return true;
        }
        return false;*/
        VarDefParser varDefParser = new VarDefParser();
        return varDefParser.Parser();
    }
    public static boolean InitVal() {
        int store = TokenList.GetIndex();
        if (Exp()) {
            StoreSyntax("<InitVal>",TokenList.GetIndex() - 1);
            //System.out.println("<InitVal>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.LBRACE)) {
            store = TokenList.GetIndex();
            if (Exp()) {
                store = TokenList.GetIndex();
                while (TokenList.NextIs(Category.COMMA) && Exp()) {
                    store = TokenList.GetIndex();
                }
                TokenList.SetIndex(store);
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RBRACE)) {
                StoreSyntax("<InitVal>",TokenList.GetIndex() - 1);
                //System.out.println("<InitVal>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.STRCON)) {
            StoreSyntax("<InitVal>",TokenList.GetIndex() - 1);
            //System.out.println("<InitVal>");
            return true;
        }
        return false;
    }

    public static boolean FuncDef() {
        /*if (FuncType(false) && TokenList.NextIs(Category.IDENFR) && TokenList.NextIs(Category.LPARENT)) {
            StoreSyntax("<FuncType>", TokenList.GetIndex() - 3);
            int store = TokenList.GetIndex();
            if (FuncFParams()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            }
            if (Block()) {
                StoreSyntax("<FuncDef>", TokenList.GetIndex() - 1);
                //System.out.println("<FuncDef>");
                return true;
            }
        }
        return false;*/
        FuncDefParser funcDefParser = new FuncDefParser();
        return funcDefParser.Parser();
    }

    public static boolean MainFuncDef() {
        if (TokenList.NextIs(Category.INTTK) &&
                TokenList.NextIs(Category.MAINTK) &&
                TokenList.NextIs(Category.LPARENT)) {
            int store = TokenList.GetIndex();
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            }
            if (Block()) {
                int semicn = 0;
                int ptr = -1;
                boolean error = true;
                while (TokenList.GetTokenByPtr(ptr).GetCategory() != Category.LBRACE && semicn < 2) {
                    if (TokenList.GetTokenByPtr(ptr).GetCategory() == Category.SEMICN) {
                        semicn++;
                    }
                    if (TokenList.GetTokenByPtr(ptr).GetCategory() == Category.RETURNTK) {
                        error = false;
                    }
                    ptr--;
                }
                if (error) {
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'g'));
                }
                StoreSyntax("<MainFuncDef>",TokenList.GetIndex() - 1);
                //System.out.println("<MainFuncDef>");
                return true;
            }
        }
        return false;
    }

    public static boolean FuncType(boolean write) {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.VOIDTK ||
                token.GetCategory() == Category.INTTK ||
                token.GetCategory() == Category.CHARTK) {
            if (write) {
                StoreSyntax("<FuncType>", TokenList.GetIndex() - 1);
            }
            //System.out.println("<FuncType>");
            return true;
        }
        return false;
    }

    public static boolean FuncFParams() {
        /*if (FuncFParam()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.COMMA) && FuncFParam()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            StoreSyntax("<FuncFParams>",TokenList.GetIndex() - 1);
            //System.out.println("<FuncFParams>");
            return true;
        }
        return false;*/
        FuncFParamsParser funcFParamsParser = new FuncFParamsParser();
        return funcFParamsParser.Parser();
    }

    public static boolean FuncFParam() {
        /*if (BType() && TokenList.NextIs(Category.IDENFR)) {
            int store = TokenList.GetIndex();
            if (TokenList.NextIs(Category.LBRACK)) {
                store = TokenList.GetIndex();
                if (!TokenList.NextIs(Category.RBRACK)) {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                }
                StoreSyntax("<FuncFParam>", TokenList.GetIndex() - 1);
                //System.out.println("<FuncFParam>");
                return true;
            }
            TokenList.SetIndex(store);
            StoreSyntax("<FuncFParam>",TokenList.GetIndex() - 1);
            //System.out.println("<FuncFParam>");
            return true;
        }
        return false;*/
        FuncFParamParser funcFParamParser = new FuncFParamParser();
        return funcFParamParser.Parser();
    }

    public static boolean Block() {
        /*if (TokenList.NextIs(Category.LBRACE)) {
            int store = TokenList.GetIndex();
            while (BlockItem()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RBRACE)) {
                StoreSyntax("<Block>",TokenList.GetIndex() - 1);
                //System.out.println(TokenList.GetIndex() - 1 + " " + "<Block>");
                return true;
            }
        }
        return false;*/
        BlockParser blockParser = new BlockParser();
        return blockParser.Parser();
    }

    public static boolean BlockItem() {
        int store = TokenList.GetIndex();
        if (Decl()) {
            //StoreSyntax("<BlockItem>",TokenList.GetIndex() - 1);
            //System.out.println("<BlockItem>");
            return true;
        } else {
            TokenList.SetIndex(store);
            if (Stmt()) {
                //StoreSyntax("<BlockItem>",TokenList.GetIndex() - 1);
                //System.out.println("<BlockItem>");
                return true;
            }
        }
        return false;
    }

    public static boolean Stmt() {
        int store = TokenList.GetIndex();
        mark = true;
        LValParser lValParser = new LValParser();
        if (lValParser.Parser(false) && TokenList.NextIs(Category.ASSIGN)) {
            StoreSyntax("<LVal>", TokenList.GetIndex() - 2);
            if (lValParser.CError()) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
            }
            if (lValParser.KError()) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
            }
            store = TokenList.GetIndex();
            Confirm();
            int scope = TokenList.Scope();
            String name = lValParser.GetIdent();
            while(scope != 0) {
                if (SymbolTable.HaveDefine(scope,name)) {
                    if (SymbolTable.Type(scope,name).IsConstLVal()) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(), 'h'));
                    }
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            if (Exp()) {
                store = TokenList.GetIndex();
                if (!TokenList.NextIs(Category.SEMICN)) {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
                }
                StoreSyntax("<Stmt>", TokenList.GetIndex() - 1);
                //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
                return true;
            }
            TokenList.SetIndex(store);
            Token token = TokenList.GetToken();
            if ((token.GetCategory() == Category.GETINTTK || token.GetCategory() == Category.GETCHARTK) &&
                    TokenList.NextIs(Category.LPARENT)) {
                store = TokenList.GetIndex();
                if (!TokenList.NextIs(Category.RPARENT)) {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
                } else {
                    store = TokenList.GetIndex();
                }
                if (!TokenList.NextIs(Category.SEMICN)) {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
                }
                StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
                //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        Back();
        if (Exp()) {
            store = TokenList.GetIndex();
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.SEMICN)) {
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (Block()) {
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.IFTK) && TokenList.NextIs(Category.LPARENT) && Cond()) {
            store = TokenList.GetIndex();
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            } else {
                store = TokenList.GetIndex();
            }
            if (Stmt()) {
                store = TokenList.GetIndex();
                if (TokenList.NextIs(Category.ELSETK) && Stmt()) {
                    StoreSyntax("<Stmt>", TokenList.GetIndex() - 1);
                    //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
                    return true;
                }
                TokenList.SetIndex(store);
                StoreSyntax("<Stmt>", TokenList.GetIndex() - 1);
                //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.FORTK) && TokenList.NextIs(Category.LPARENT)) {
            store = TokenList.GetIndex();
            if (ForStmt()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.SEMICN)) {
                store = TokenList.GetIndex();
                if (Cond()) {
                    store = TokenList.GetIndex();
                }
                TokenList.SetIndex(store);
                if (TokenList.NextIs(Category.SEMICN)) {
                    store = TokenList.GetIndex();
                    if (ForStmt()) {
                        store = TokenList.GetIndex();
                    }
                    TokenList.SetIndex(store);
                    if (TokenList.NextIs(Category.RPARENT) && Stmt()) {
                        StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
                        //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
                        return true;
                    }
                }
            }
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.BREAKTK)) {
            store = TokenList.GetIndex();
            if (!showFor) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'m'));
            }
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.CONTINUETK)) {
            store = TokenList.GetIndex();
            if (!showFor) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'m'));
            }
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.RETURNTK)) {
            store = TokenList.GetIndex();
            if (Exp()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        TokenList.SetIndex(store);
        if (TokenList.NextIs(Category.PRINTFTK) &&
                TokenList.NextIs(Category.LPARENT) &&
                TokenList.NextIs(Category.STRCON)) {
            store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.COMMA) && Exp()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            } else {
                store = TokenList.GetIndex();
            }
            if (!TokenList.NextIs(Category.SEMICN)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'i'));
            }
            StoreSyntax("<Stmt>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() - 1+ " " +"<Stmt>");
            return true;
        }
        return false;
    }

    public static boolean ForStmt() {
        LValParser lValParser = new LValParser();
        if (lValParser.Parser(true) && TokenList.NextIs(Category.ASSIGN) && Exp()) { // 目前安全
            int scope = TokenList.Scope();
            String name = lValParser.GetIdent();
            while(scope != 0) {
                if (SymbolTable.HaveDefine(scope,name)) {
                    if (SymbolTable.Type(scope,name).IsConstLVal()) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(), 'h'));
                    }
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            StoreSyntax("<ForStmt>",TokenList.GetIndex() - 1);
            //System.out.println("<ForStmt>");
            return true;
        }
        return false;
    }

    public static boolean Exp() {
        if (AddExp()) {
            StoreSyntax("<Exp>",TokenList.GetIndex() - 1);
            //System.out.println("<Exp>");
            return true;
        }
        return false;
    }

    public static boolean Cond() {
        if (LOrExp()) {
            StoreSyntax("<Cond>",TokenList.GetIndex() - 1);
            //System.out.println("<Cond>");
            return true;
        }
        return false;
    }

    public static boolean LVal(boolean write) {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.IDENFR) {
            String ident = token.GetContent();
            int store = TokenList.GetIndex();
            int scope = TokenList.Scope();
            boolean cError = true;
            while (scope!= 0) {
                if (SymbolTable.HaveDefine(scope,ident)) {
                    cError = false;
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            if (TokenList.NextIs(Category.LBRACK) && Exp()) { //
                store = TokenList.GetIndex();
                boolean kError = false;
                if (!TokenList.NextIs(Category.RBRACK)) {
                    TokenList.SetIndex(store);
                    kError = true;
                }
                if (write) {
                    if (cError) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
                    }
                    if (kError) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                    }
                    StoreSyntax("<LVal>", TokenList.GetIndex() - 1);
                    //System.out.println("<LVal>");
                }
                return true;
            }
            TokenList.SetIndex(store);
            if (write) {
                if (cError) {
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
                }
                StoreSyntax("<LVal>", TokenList.GetIndex() - 1);
                //System.out.println("<LVal>");
            }
            return true;
        }
        return false;
    }

    public static boolean PrimaryExp() {
        int store = TokenList.GetIndex();
        if (TokenList.NextIs(Category.LPARENT) && Exp()) {
            store = TokenList.GetIndex();
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            }
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (LVal(true)) { // 安全用法
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (Number()) {
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (Character()) {
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        return false;
    }

    public static boolean Number() {
        if (TokenList.NextIs(Category.INTCON)) {
            StoreSyntax("<Number>",TokenList.GetIndex() - 1);
            //System.out.println(TokenList.GetIndex() + " " + "<Number>");
            return true;
        }
        return false;
    }

    public static boolean Character() {
        if (TokenList.NextIs(Category.CHRCON)) {
            StoreSyntax("<Character>",TokenList.GetIndex() - 1);
            //System.out.println("<Character>");
            return true;
        }
        return false;
    }

    public static boolean UnaryExp() {
        /*int store = TokenList.GetIndex();
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.IDENFR && TokenList.NextIs(Category.LPARENT)) { // 一定是Func
            store = TokenList.GetIndex();
            String ident = token.GetContent();
            int scope = TokenList.Scope();
            boolean cError = true;
            while (scope!= 0) {
                if (SymbolTable.HaveDefine(scope,ident)) {
                    cError = false;
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            if (cError) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
            }
            FuncRparamsParser funcRparamsParser = new FuncRparamsParser();
            if (funcRparamsParser.Parser()) {
                store = TokenList.GetIndex();
            }
            if (!cError) {
                if (SymbolTable.GetParamsNumber(scope,ident) != funcRparamsParser.ParamsNumber()) {
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'d'));
                } else {

                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RPARENT)) {
                StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
                //System.out.println("<UnaryExp>");
                return true;
            } else {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
                StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
                //System.out.println("<UnaryExp>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        if (PrimaryExp()) {
            StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<UnaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (UnaryOp() && UnaryExp()) {
            StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<UnaryExp>");
            return true;
        }
        return false;*/
        UnaryExpParser unaryExpParser = new UnaryExpParser();
        return unaryExpParser.Parser();
    }

    public static boolean UnaryOp() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.PLUS ||
                token.GetCategory() == Category.MINU ||
                token.GetCategory() == Category.NOT) {
            StoreSyntax("<UnaryOp>",TokenList.GetIndex() - 1);
            //System.out.println("<UnaryOp>");
            return true;
        }
        return false;
    }

    public static boolean FuncRParams() {
        if (Exp()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.COMMA) && Exp()) {
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            StoreSyntax("<FuncRParams>",TokenList.GetIndex() - 1);
            //System.out.println("<FuncRParams>");
            return true;
        }
        return false;
    }

    public static boolean MulExp() {
        if (UnaryExp()) {
            int store = TokenList.GetIndex();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.MULT ||
                    token.GetCategory() == Category.DIV ||
                    token.GetCategory() == Category.MOD) {
                if (UnaryExp()) {
                    StoreSyntax("<MulExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<MulExp>",TokenList.GetIndex() - 1);
            //System.out.println("<MulExp>");
            return true;
        }
        return false;
    }

    public static boolean AddExp() {
        if (MulExp()) {
            int store = TokenList.GetIndex();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.PLUS ||
                    token.GetCategory() == Category.MINU) {
                if (MulExp()) {
                    StoreSyntax("<AddExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<AddExp>",TokenList.GetIndex() - 1);
            //System.out.println("<AddExp>");
            return true;
        }
        return false;
    }

    public static boolean RelExp() {
        if (AddExp()) {
            int store = TokenList.GetIndex();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.LSS ||
                    token.GetCategory() == Category.GRE ||
                    token.GetCategory() == Category.LEQ ||
                    token.GetCategory() == Category.GEQ) {
                if (AddExp()) {
                    StoreSyntax("<RelExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<RelExp>",TokenList.GetIndex() - 1);
            //System.out.println("<RelExp>");
            return true;
        }
        return false;
    }

    public static boolean EqExp() {
        if (RelExp()) {
            int store = TokenList.GetIndex();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.EQL ||
                    token.GetCategory() == Category.NEQ) {
                if (RelExp()) {
                    StoreSyntax("<EqExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<EqExp>",TokenList.GetIndex() - 1);
            //System.out.println("<EqExp>");
            return true;
        }
        return false;
    }

    public static boolean LAndExp() {
        if (EqExp()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.AND) && EqExp()) {
                StoreSyntax("<LAndExp>",store - 1);
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            StoreSyntax("<LAndExp>",TokenList.GetIndex() - 1);
            //System.out.println("<LAndExp>");
            return true;
        }
        return false;
    }

    public static boolean LOrExp() {
        if (LAndExp()) {
            int store = TokenList.GetIndex();
            while (TokenList.NextIs(Category.OR) && LAndExp()) {
                StoreSyntax("<LOrExp>",store - 1);
                store = TokenList.GetIndex();
            }
            TokenList.SetIndex(store);
            StoreSyntax("<LOrExp>",TokenList.GetIndex() - 1);
            //System.out.println("<LOrExp>");
            return true;
        }
        return false;
    }

    public static boolean ConstExp() {
        if (AddExp()) {
            StoreSyntax("<ConstExp>",TokenList.GetIndex() - 1);
            //System.out.println("<ConstExp>");
            return true;
        }
        return false;
    }

    public class Main {
        public static void main(String[] argvs) {
        }
    }
 }
