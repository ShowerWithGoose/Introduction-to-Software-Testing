package frontend.Parser;

import frontend.Error.ErrorManager;
import frontend.Error.ErrorToken;
import frontend.Error.ErrorType;
import frontend.Lexer.Lexer;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Utils;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

public class Parser
{

    //<editor-fold> desc=单例模式
    private static final Parser instance = new Parser();

    private Parser() {
    }

    public static Parser GetInstance() {
        return instance;
    }

    //</editor-fold>
    private Token[] tokens;
    private GrammarTreeNode root;
    private int index = 0;
    private Map<NonterminalType, TokenType[]> firstMap;
    private Token token;
    private int lineNo;
    private boolean errorIgnore = false;

    private void InitFirstMap() {
        firstMap = new HashMap<>();
        firstMap.put(NonterminalType.BType, new TokenType[]{TokenType.IntTk, TokenType.CharTk});
        firstMap.put(NonterminalType.Number, new TokenType[]{TokenType.IntConst});
        firstMap.put(NonterminalType.Character, new TokenType[]{TokenType.CharConst});
        firstMap.put(NonterminalType.ConstDecl, new TokenType[]{TokenType.ConstTk});
        firstMap.put(NonterminalType.ConstDef, new TokenType[]{TokenType.Ident});
        firstMap.put(NonterminalType.PrimaryExp, new TokenType[]{TokenType.LParent, TokenType.Ident, TokenType.IntConst, TokenType.CharConst});
        firstMap.put(NonterminalType.UnaryOp, new TokenType[]{TokenType.PlusTk, TokenType.MinusTk, TokenType.NotTk});
        firstMap.put(NonterminalType.VarDef, new TokenType[]{TokenType.Ident});
        firstMap.put(NonterminalType.FuncType, new TokenType[]{TokenType.CharTk, TokenType.IntTk, TokenType.VoidTk});
        firstMap.put(NonterminalType.Block, new TokenType[]{TokenType.LBrace});
        firstMap.put(NonterminalType.FuncDef, InitTokenTypeArray(firstMap.get(NonterminalType.FuncType)));
        firstMap.put(NonterminalType.MainFuncDef, new TokenType[]{TokenType.IntTk});
        firstMap.put(NonterminalType.LVal, new TokenType[]{TokenType.Ident});

        firstMap.put(NonterminalType.FuncFParam, InitTokenTypeArray(firstMap.get(NonterminalType.BType)));
        firstMap.put(NonterminalType.FuncFParams, InitTokenTypeArray(firstMap.get(NonterminalType.FuncFParam)));
        firstMap.put(NonterminalType.VarDecl, InitTokenTypeArray(firstMap.get(NonterminalType.BType)));
        firstMap.put(NonterminalType.Decl, InitTokenTypeArray(firstMap.get(NonterminalType.ConstDecl),
                        firstMap.get(NonterminalType.VarDecl)));


        firstMap.put(NonterminalType.CompUnit, InitTokenTypeArray(firstMap.get(NonterminalType.Decl)
                        , firstMap.get(NonterminalType.FuncDef), firstMap.get(NonterminalType.MainFuncDef)));
        firstMap.put(NonterminalType.UnaryExp, InitTokenTypeArray(firstMap.get(NonterminalType.PrimaryExp)
                        , firstMap.get(NonterminalType.UnaryOp), new TokenType[]{TokenType.Ident}));
        firstMap.put(NonterminalType.MulExp, InitTokenTypeArray(firstMap.get(NonterminalType.UnaryExp)));
        firstMap.put(NonterminalType.AddExp, InitTokenTypeArray(firstMap.get(NonterminalType.MulExp)));
        firstMap.put(NonterminalType.Exp, InitTokenTypeArray(firstMap.get(NonterminalType.AddExp)));
        firstMap.put(NonterminalType.FuncRParams, InitTokenTypeArray(firstMap.get(NonterminalType.Exp)));

        firstMap.put(NonterminalType.ConstExp, InitTokenTypeArray(firstMap.get(NonterminalType.AddExp)));
        firstMap.put(NonterminalType.ConstInitVal, InitTokenTypeArray(new TokenType[]{TokenType.LBrace,TokenType.StringConst},
                        firstMap.get(NonterminalType.ConstExp)));
        firstMap.put(NonterminalType.InitVal, InitTokenTypeArray(new TokenType[]{TokenType.LBrace,TokenType.StringConst},
                        firstMap.get(NonterminalType.Exp)));
        firstMap.put(NonterminalType.Stmt, InitTokenTypeArray(firstMap.get(NonterminalType.LVal),
                        firstMap.get(NonterminalType.Exp), firstMap.get(NonterminalType.Block),
                        new TokenType[]{TokenType.Semicolon, TokenType.IfTk,TokenType.ForTk,
                        TokenType.BreakTk,TokenType.ContinueTk, TokenType.ReturnTk, TokenType.PrintfTk}));
        firstMap.put(NonterminalType.ForStmt, InitTokenTypeArray(firstMap.get(NonterminalType.LVal)));

        firstMap.put(NonterminalType.RelExp, InitTokenTypeArray(firstMap.get(NonterminalType.AddExp)));
        firstMap.put(NonterminalType.EqExp, InitTokenTypeArray(firstMap.get(NonterminalType.RelExp)));
        firstMap.put(NonterminalType.LAndExp, InitTokenTypeArray(firstMap.get(NonterminalType.EqExp)));
        firstMap.put(NonterminalType.LOrExp, InitTokenTypeArray(firstMap.get(NonterminalType.LAndExp)));
        firstMap.put(NonterminalType.Cond, InitTokenTypeArray(firstMap.get(NonterminalType.LOrExp)));
        firstMap.put(NonterminalType.BlockItem, InitTokenTypeArray(firstMap.get(NonterminalType.Decl),
                        firstMap.get(NonterminalType.Stmt)));

    }

    private TokenType[] InitTokenTypeArray(TokenType[]... type) {
        List<TokenType> types = new ArrayList<>();
        for (TokenType[] tokenTypes : type) {
            types.addAll(Arrays.asList(tokenTypes));
        }
        return types.toArray(new TokenType[0]);
    }

    public void Init() {
        tokens = Lexer.GetLexer().getTokens().toArray(new Token[0]);
        InitFirstMap();
        root = new GrammarTreeNode(new Nonterminal(NonterminalType.CompUnit), true);
    }

    public void Process() {
        token = Next();
        if (token !=null && IsFirstOf(token.getType(), NonterminalType.CompUnit)) {
            CompUnit.Process(root);
        }
        else {
            Error();
        }
    }


    private void Error() {
        return;
    }

    private void Error(ErrorType errorType) {
        if(errorIgnore) return;
        ErrorToken errorToken = new ErrorToken(null, lineNo, errorType);
        ErrorManager.GetInstance().setError(true);
        ErrorManager.GetInstance().addError(errorToken);
    }
    private void ResetIndex(int index) {
        this.index = index;
    }

    private boolean IsFirstOf(TokenType tokenType, NonterminalType nonterminalType) {
        if (!firstMap.containsKey(nonterminalType)) {
            throw new RuntimeException();
        }
        TokenType[] tokenTypes = firstMap.get(nonterminalType);
        for (TokenType type : tokenTypes) {
            if (tokenType.equals(type)) {
                return true;
            }
        }
        return false;
    }

    private Token Next() {
        if (index < tokens.length) {
            if(token!=null)lineNo = token.getLineNo();
            else lineNo = 0;
            token = tokens[index];
            index++;
            return token;
        }
        return null;
    }

    private Token PreToken(int level) {
        if (index + level < tokens.length) {
            return tokens[index + level -1];
        }
        return null;
    }

    public void PrintTree() throws IOException {
        GrammarTreeNode.PrintFromRoot(root);
    }

    public GrammarTreeNode GetTree() {
        return root;
    }

    //<editor-fold> desc=子程序
    static class CompUnit
    {
        static void Process(GrammarTreeNode node) {
            while (true) {
                if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Decl)) {
                    if (instance.IsFirstOf(instance.token.getType(), NonterminalType.FuncDef)) {
                        if (instance.IsFirstOf(instance.token.getType(), NonterminalType.MainFuncDef)) {
                            //int 开头
                            Token token1 = instance.PreToken(1);
                            if (token1 == null) {
                                instance.Error();
                                return;
                            }
                            if (token1.getType().equals(TokenType.MainTk)) {
                                break;
                            }
                            else {
                                Token token2 = instance.PreToken(2);
                                if (token2 == null) {
                                    instance.Error();
                                    return;
                                }
                                if (token2.getType().equals(TokenType.LParent)) {
                                    break;
                                }
                                else {
                                    Decl.Process(node);
                                }
                            }
                        }
                        else {
                            //int 或 char
                            Token token2 = instance.PreToken(2);
                            if (token2 == null) {
                                instance.Error();
                                return;
                            }
                            if (token2.getType().equals(TokenType.LParent)) {
                                break;
                            }
                            else {
                                Decl.Process(node);
                            }
                        }
                    }
                    else {
                        Decl.Process(node);
                    }
                }
                else {
                    break;
                }
            }
            while (true) {
                if (instance.IsFirstOf(instance.token.getType(), NonterminalType.FuncDef)) {
                    if (instance.IsFirstOf(instance.token.getType(), NonterminalType.MainFuncDef)) {
                        Token token1 = instance.PreToken(1);
                        if (token1 == null) {
                            instance.Error();
                            return;
                        }
                        if (token1.getType().equals(TokenType.MainTk)) {
                            break;
                        }
                        else {
                            FuncDef.Process(node);
                        }
                    }
                    else {
                        FuncDef.Process(node);
                    }
                }
                else {
                    break;
                }
            }
            MainFuncDef.Process(node);
        }
    }

    static class Decl
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Decl), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.ConstDecl)) {
                ConstDecl.Process(newNode);
            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.VarDecl)) {
                VarDecl.Process(newNode);
            }
            else {
                instance.Error();
            }
        }
//        static int Check(List<Token> tokens, boolean isOrigin) {
//            if(tokens.isEmpty()){
//                if(isOrigin){return -1;}
//                else {return 0;}
//            }
//            int currentIndex = 0;
//            //先用first集判断
//            boolean flag = instance.IsFirstOf(tokens.get(0).getType(), NonterminalType.Decl);
//            if(!flag) return -1;
//            currentIndex++;
//            //first集满足后，递归判断
//            if(tokens.size() == 1) return currentIndex;
//            int check1 =  ConstDecl.Check(tokens.subList(currentIndex, tokens.size()), false);
//            if(check1 == -1) {
//                return -1;
//            }
//            currentIndex += check1;
//            if(currentIndex < tokens.size()) {
//                //token有剩余
//                if(isOrigin) {
//                    //如果是递归的根，有剩余token，则不是该条文法
//                    return -1;
//                }
//                //如果不是递归的根，有剩余token，返回匹配成功个数，允许上级节点继续匹配
//                return currentIndex;
//            }
//            //刚好匹配完全，或者提前终止，返回匹配成功的个数
//            return currentIndex;
//        }
    }

    static class ConstDecl
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.ConstDecl), true);
            GrammarTreeNode.LinkChild(node, newNode);

            if (instance.token.getType().equals(TokenType.ConstTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            BType.Process(newNode);
            ConstDef.Process(newNode);
            while (true) {
                if (instance.token.getType().equals(TokenType.Comma)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                    ConstDef.Process(newNode);
                }
                else {
                    break;
                }
            }

            if (instance.token.getType().equals(TokenType.Semicolon)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfSemicolon);
                GrammarTreeNode node2 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node2);
            }

        }
    }

    static class BType
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.BType), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (Utils.IsTokenTypeIn(instance.token, TokenType.IntTk, TokenType.CharTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class ConstDef
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.ConstDef), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.ConstDef)) {
                //是First集（Ident）
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            if (instance.token.getType().equals(TokenType.LBracket)) {
                //是[
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                ConstExp.Process(newNode);
                if (instance.token.getType().equals(TokenType.RBracket)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRBracket);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RBracket, "]", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                }
            }

            if (instance.token.getType().equals(TokenType.AssignTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }

            ConstInitVal.Process(newNode);

        }

    }

    static class ConstExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.ConstExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            AddExp.Process(newNode);
        }

    }

    static class ConstInitVal
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.ConstInitVal), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.ConstExp)) {
                ConstExp.Process(newNode);
            }
            else if (instance.token.getType().equals(TokenType.LBrace)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (instance.IsFirstOf(instance.token.getType(), NonterminalType.ConstExp)) {
                    ConstExp.Process(newNode);
                    while (true) {
                        if (instance.token.getType().equals(TokenType.Comma)) {
                            GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                            GrammarTreeNode.LinkChild(newNode, node2);
                            instance.Next();
                            ConstExp.Process(newNode);
                        }
                        else {
                            break;
                        }
                    }
                }
                if (instance.token.getType().equals(TokenType.RBrace)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error();
                }
            }
            else if (instance.token.getType().equals(TokenType.StringConst)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }

    }

    static class AddExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.AddExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            MulExp.Process(newNode);
            while (true) {
                if (Utils.IsTokenTypeIn(instance.token, TokenType.PlusTk, TokenType.MinusTk)) {
                    //新的add节点
                    GrammarTreeNode node2 = new GrammarTreeNode(new Nonterminal(NonterminalType.AddExp), true);
//                    GrammarTreeNode.LinkChild(newNode, node2);
                    //将newNode的孩子交给新node，newNode的孩子是新node
                    GrammarTreeNode.ResetChildren(newNode, node2);
                    GrammarTreeNode.LinkChild(newNode, node2);

                    GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node1);
                    instance.Next();
                    MulExp.Process(newNode);

                }
                else {
                    break;
                }
            }
        }

    }

    static class MulExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.MulExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            UnaryExp.Process(newNode);
            while (true) {
                if (Utils.IsTokenTypeIn(instance.token, TokenType.MulTk, TokenType.DivTk, TokenType.ModTk)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(new Nonterminal(NonterminalType.MulExp), true);
                    GrammarTreeNode.ResetChildren(newNode, node2);
                    GrammarTreeNode.LinkChild(newNode, node2);

                    GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node1);
                    instance.Next();
                    UnaryExp.Process(newNode);
                }
                else {
                    break;
                }
            }

        }

    }

    static class UnaryExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.UnaryExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.UnaryOp)) {
                UnaryOp.Process(newNode);
                UnaryExp.Process(newNode);
            }
            else if (instance.token.getType().equals(TokenType.Ident)) {
                //预读一位
                Token token = instance.PreToken(1);
                if (token != null) {
                    if (token.getType().equals(TokenType.LParent)) {
                        GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                        GrammarTreeNode.LinkChild(newNode, node1);
                        instance.Next();
                        GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                        GrammarTreeNode.LinkChild(newNode, node2);
                        instance.Next();
                        if (instance.IsFirstOf(instance.token.getType(), NonterminalType.FuncRParams)) {
                            FuncRParams.Process(newNode);
                        }
                        if (instance.token.getType().equals(TokenType.RParent)) {
                            GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                            GrammarTreeNode.LinkChild(newNode, node3);
                            instance.Next();
                        }
                        else {
                            instance.Error(ErrorType.LackOfRParent);
                            GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                            GrammarTreeNode.LinkChild(newNode, node3);

                        }
                    }
                    else {
                        PrimaryExp.Process(newNode);
                    }
                }
                else {
                    PrimaryExp.Process(newNode);
                }
            }
            else {
                PrimaryExp.Process(newNode);
            }
        }
    }

    static class UnaryOp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.UnaryOp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (Utils.IsTokenTypeIn(instance.token, TokenType.PlusTk, TokenType.MinusTk, TokenType.NotTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class PrimaryExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.PrimaryExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                Exp.Process(newNode);
                if (instance.token.getType().equals(TokenType.RParent)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRParent);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                }

            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.LVal)) {
                LVal.Process(newNode);
            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Number)) {
                Number.Process(newNode);
            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Character)) {
                Character.Process(newNode);
            }
            else {
                instance.Error();
            }
        }
    }

    static class Exp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Exp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            AddExp.Process(newNode);
        }
    }

    static class Number
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Number), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.IntConst)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class Character
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Character), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.CharConst)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class LVal
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.LVal), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.Ident)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            if (instance.token.getType().equals(TokenType.LBracket)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                Exp.Process(newNode);
                if (instance.token.getType().equals(TokenType.RBracket)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRBracket);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RBracket, "]", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
        }
    }

    static class FuncRParams
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.FuncRParams), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Exp)) {
                Exp.Process(newNode);
            }
            else {
                instance.Error();
            }

            while (true) {
                if (instance.token.getType().equals(TokenType.Comma)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node1);
                    instance.Next();
                    Exp.Process(newNode);
                }
                else {
                    break;
                }
            }
        }
    }

    static class VarDecl
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.VarDecl), true);
            GrammarTreeNode.LinkChild(node, newNode);
            BType.Process(newNode);
            VarDef.Process(newNode);
            while (true) {
                if (instance.token.getType().equals(TokenType.Comma)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node1);
                    instance.Next();
                    VarDef.Process(newNode);
                }
                else {
                    break;
                }
            }
            if (instance.token.getType().equals(TokenType.Semicolon)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfSemicolon);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }
        }
    }

    static class VarDef
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.VarDef), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.VarDef)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (instance.token.getType().equals(TokenType.LBracket)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                ConstExp.Process(newNode);
                if (instance.token.getType().equals(TokenType.RBracket)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRBracket);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RBracket, "]", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
            if (instance.token.getType().equals(TokenType.AssignTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                InitVal.Process(newNode);
            }
        }
    }

    static class InitVal
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.InitVal), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Exp)) {
                Exp.Process(newNode);
            }
            else if (instance.token.getType().equals(TokenType.LBrace)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Exp)) {
                    Exp.Process(newNode);
                    while (true) {
                        if (instance.token.getType().equals(TokenType.Comma)) {
                            GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                            GrammarTreeNode.LinkChild(newNode, node2);
                            instance.Next();
                            Exp.Process(newNode);
                        }
                        else {
                            break;
                        }
                    }
                }
                if (instance.token.getType().equals(TokenType.RBrace)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error();
                }
            }
            else if (instance.token.getType().equals(TokenType.StringConst)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

        }
    }

    static class FuncDef
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.FuncDef), true);
            GrammarTreeNode.LinkChild(node, newNode);
            FuncType.Process(newNode);
            if (instance.token.getType().equals(TokenType.Ident)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node3);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.FuncDef)) {
                FuncFParams.Process(newNode);
            }
            if (instance.token.getType().equals(TokenType.RParent)) {
                GrammarTreeNode node4 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node4);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfRParent);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }
            Block.Process(newNode);


        }
    }

    static class FuncType
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.FuncType), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (Utils.IsTokenTypeIn(instance.token, TokenType.IntTk, TokenType.CharTk, TokenType.VoidTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class MainFuncDef
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.MainFuncDef), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.IntTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }

            if (instance.token.getType().equals(TokenType.MainTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            if (instance.token.getType().equals(TokenType.RParent)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfRParent);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }

            Block.Process(newNode);
        }
    }

    static class FuncFParams
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.FuncFParams), true);
            GrammarTreeNode.LinkChild(node, newNode);
            FuncFParam.Process(newNode);
            while (true) {
                if (instance.token.getType().equals(TokenType.Comma)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node1);
                    instance.Next();
                    FuncFParam.Process(newNode);
                }
                else {
                    break;
                }
            }
        }
    }

    static class FuncFParam
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.FuncFParam), true);
            GrammarTreeNode.LinkChild(node, newNode);
            BType.Process(newNode);
            if (instance.token.getType().equals(TokenType.Ident)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }

            if (instance.token.getType().equals(TokenType.LBracket)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (instance.token.getType().equals(TokenType.RBracket)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRBracket);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RBracket, "]", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
        }
    }

    static class Block
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Block), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.LBrace)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
            while(true){
                if(!instance.token.getType().equals(TokenType.RBrace)){
                    BlockItem.Process(newNode);
                }
                else {
                    break;
                }
            }
            if (instance.token.getType().equals(TokenType.RBrace)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
            }
            else {
                instance.Error();
            }
        }
    }

    static class BlockItem
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.BlockItem), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Decl)) {
                Decl.Process(newNode);
            }
            else {
                Stmt.Process(newNode);
            }
        }

    }

    static class Stmt
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Stmt), true);
            GrammarTreeNode.LinkChild(node, newNode);
            if (instance.token.getType().equals(TokenType.IfTk)) {
                IfProcess(newNode);
            }
            else if (instance.token.getType().equals(TokenType.ForTk)) {
                ForProcess(newNode);
            }
            else if (instance.token.getType().equals(TokenType.BreakTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (instance.token.getType().equals(TokenType.Semicolon)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfSemicolon);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
            else if (instance.token.getType().equals(TokenType.ContinueTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (instance.token.getType().equals(TokenType.Semicolon)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfSemicolon);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
            else if (instance.token.getType().equals(TokenType.ReturnTk)) {
                GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node1);
                instance.Next();
                if (!instance.token.getType().equals(TokenType.Semicolon)) {
                    Exp.Process(newNode);
                }
                if (instance.token.getType().equals(TokenType.Semicolon)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfSemicolon);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
            else if (instance.token.getType().equals(TokenType.PrintfTk)) {
                PrintProcess(newNode);
            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.Block)) {
                Block.Process(newNode);
            }
            else if (instance.IsFirstOf(instance.token.getType(), NonterminalType.LVal)) {
                //预读，直到遇到等号或分号
                boolean isExp = false;
                int index = instance.index;
                instance.errorIgnore = true;
                LVal.Process(newNode);
                if(!instance.token.getType().equals(TokenType.AssignTk)) {
                    isExp = true;
                }
                //回溯
                newNode.ClearChildren();
                instance.index = index;
                instance.token = instance.tokens[index-1];
                instance.errorIgnore = false;
                if (isExp) {
                    if (!instance.token.getType().equals(TokenType.Semicolon)) {
                        Exp.Process(newNode);
                    }
                    if (instance.token.getType().equals(TokenType.Semicolon)) {
                        GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                        GrammarTreeNode.LinkChild(newNode, node1);
                        instance.Next();
                    }
                    else {
                        instance.Error(ErrorType.LackOfSemicolon);
                        GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                        GrammarTreeNode.LinkChild(newNode, node3);

                    }
                }
                else {
                    LValProcess(newNode);
                }
            }
            else{
                    if(!instance.token.getType().equals(TokenType.Semicolon)){
                        Exp.Process(newNode);
                        if(!instance.token.getType().equals(TokenType.Semicolon)){
                            instance.Error(ErrorType.LackOfSemicolon);
                            GrammarTreeNode node1 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                            GrammarTreeNode.LinkChild(newNode, node1);
                        }
                        else {
                            GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                            GrammarTreeNode.LinkChild(newNode, node1);
                            instance.Next();
                        }
                    }
                    else{
                        GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
                        GrammarTreeNode.LinkChild(newNode, node1);
                        instance.Next();
                    }
            }
        }

        static void IfProcess(GrammarTreeNode newNode) {
            GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
            GrammarTreeNode.LinkChild(newNode, node1);
            instance.Next();
            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            Cond.Process(newNode);
            if (instance.token.getType().equals(TokenType.RParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfRParent);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }
            Stmt.Process(newNode);
            if (instance.token.getType().equals(TokenType.ElseTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                Stmt.Process(newNode);
            }
        }

        static void ForProcess(GrammarTreeNode newNode) {
            GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
            GrammarTreeNode.LinkChild(newNode, node1);
            instance.Next();
            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (!instance.token.getType().equals(TokenType.Semicolon)) {
                ForStmt.Process(newNode);
            }
            if (instance.token.getType().equals(TokenType.Semicolon)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (!instance.token.getType().equals(TokenType.Semicolon)) {
                Cond.Process(newNode);
            }
            if (instance.token.getType().equals(TokenType.Semicolon)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (!instance.token.getType().equals(TokenType.RParent)) {
                ForStmt.Process(newNode);
            }
            if (instance.token.getType().equals(TokenType.RParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            Stmt.Process(newNode);
        }

        static void PrintProcess(GrammarTreeNode newNode) {
            GrammarTreeNode node1 = new GrammarTreeNode(instance.token, false);
            GrammarTreeNode.LinkChild(newNode, node1);
            instance.Next();
            if (instance.token.getType().equals(TokenType.LParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (instance.token.getType().equals(TokenType.StringConst)) {
                GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node3);
                instance.Next();
            }
            else {
                instance.Error();
            }
            while (true) {
                if (instance.token.getType().equals(TokenType.Comma)) {
                    GrammarTreeNode node4 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node4);
                    instance.Next();
                    Exp.Process(newNode);
                }
                else {
                    break;
                }
            }
            if (instance.token.getType().equals(TokenType.RParent)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfRParent);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }
            if (instance.token.getType().equals(TokenType.Semicolon)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error(ErrorType.LackOfSemicolon);
                GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                GrammarTreeNode.LinkChild(newNode, node3);

            }
        }

        static void LValProcess(GrammarTreeNode newNode) {
            LVal.Process(newNode);
            if (instance.token.getType().equals(TokenType.AssignTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            if (instance.token.getType().equals(TokenType.GetIntTk) || instance.token.getType().equals(TokenType.GetCharTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
                if (instance.token.getType().equals(TokenType.LParent)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error();
                }
                if (instance.token.getType().equals(TokenType.RParent)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfRParent);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.RParent, ")", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
                if (instance.token.getType().equals(TokenType.Semicolon)) {
                    GrammarTreeNode node3 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node3);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfSemicolon);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
            else {
                Exp.Process(newNode);
                if (instance.token.getType().equals(TokenType.Semicolon)) {
                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                }
                else {
                    instance.Error(ErrorType.LackOfSemicolon);
                    GrammarTreeNode node3 = new GrammarTreeNode(new Token(TokenType.Semicolon, ";", instance.lineNo), false);
                    GrammarTreeNode.LinkChild(newNode, node3);

                }
            }
        }
    }

    static class Cond
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.Cond), true);
            GrammarTreeNode.LinkChild(node, newNode);
            LOrExp.Process(newNode);
        }
    }

    static class LOrExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.LOrExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            LAndCond.Process(newNode);
            while (true) {
                if (instance.token.getType().equals(TokenType.OrTk)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(new Nonterminal(NonterminalType.LOrExp), true);
                    GrammarTreeNode.ResetChildren(newNode, node1);
                    GrammarTreeNode.LinkChild(newNode, node1);

                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                    LAndCond.Process(newNode);
                }
                else {
                    break;
                }
            }
        }
    }

    static class LAndCond
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.LAndExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            EqExp.Process(newNode);
            while (true) {
                if (instance.token.getType().equals(TokenType.AndTk)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(new Nonterminal(NonterminalType.LAndExp), true);
                    GrammarTreeNode.ResetChildren(newNode, node1);
                    GrammarTreeNode.LinkChild(newNode, node1);

                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                    EqExp.Process(newNode);
                }
                else {
                    break;
                }
            }
        }
    }

    static class EqExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.EqExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            RelExp.Process(newNode);
            while (true) {
                if (Utils.IsTokenTypeIn(instance.token, TokenType.EqualTk, TokenType.NotEqualTk)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(new Nonterminal(NonterminalType.EqExp), true);
                    GrammarTreeNode.ResetChildren(newNode, node1);
                    GrammarTreeNode.LinkChild(newNode, node1);

                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                    RelExp.Process(newNode);
                }
                else {
                    break;
                }
            }
        }
    }

    static class RelExp
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.RelExp), true);
            GrammarTreeNode.LinkChild(node, newNode);
            AddExp.Process(newNode);
            while (true) {
                if (Utils.IsTokenTypeIn(instance.token, TokenType.GreaterTk, TokenType.GreaterEqTk,TokenType.LessTk,TokenType.LessEqTk)) {
                    GrammarTreeNode node1 = new GrammarTreeNode(new Nonterminal(NonterminalType.RelExp), true);
                    GrammarTreeNode.ResetChildren(newNode, node1);
                    GrammarTreeNode.LinkChild(newNode, node1);

                    GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                    GrammarTreeNode.LinkChild(newNode, node2);
                    instance.Next();
                    AddExp.Process(newNode);
                }
                else {
                    break;
                }
            }
        }

    }

    static class ForStmt
    {
        static void Process(GrammarTreeNode node) {
            GrammarTreeNode newNode = new GrammarTreeNode(new Nonterminal(NonterminalType.ForStmt), true);
            GrammarTreeNode.LinkChild(node, newNode);
            LVal.Process(newNode);
            if (instance.token.getType().equals(TokenType.AssignTk)) {
                GrammarTreeNode node2 = new GrammarTreeNode(instance.token, false);
                GrammarTreeNode.LinkChild(newNode, node2);
                instance.Next();
            }
            else {
                instance.Error();
            }
            Exp.Process(newNode);
        }
    }
    //</editor-fold>

}
