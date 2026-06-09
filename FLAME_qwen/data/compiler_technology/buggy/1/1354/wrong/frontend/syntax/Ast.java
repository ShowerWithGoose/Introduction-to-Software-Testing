package frontend.syntax;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class Ast {
    private final CompUnit compUnit;

    public Ast(CompUnit compUnit) {
        this.compUnit = compUnit;
    }

    @Override
    public String toString() {
        return compUnit.toString() + "<CompUnit>\n";
    }


    /** CompUnit → {Decl} {FuncDef} MainFuncDef
     * */
    public static class CompUnit {
        private final ArrayList<Decl> decls;
        private final ArrayList<FuncDef> funcDefs;
        private final MainFuncDef mainFuncDef;

        public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
            this.decls = decls;
            this.funcDefs = funcDefs;
            this.mainFuncDef = mainFuncDef;
        }
        public ArrayList<Decl> getDecls() {
            return decls;
        }
        public ArrayList<FuncDef> getFuncDefs(){
            return funcDefs;
        }

        public MainFuncDef getMainFuncDef() {
            return mainFuncDef;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (Decl decl : decls) {
                sb.append(decl);
                if (decl instanceof ConstDecl) {
                    sb.append("<ConstDecl>\n");
                } else if (decl instanceof VarDecl) {
                    sb.append("<VarDecl>\n");
                } else {
                    sb.append("what decl \n");
                }
            }
            for (FuncDef funcDef : funcDefs) {
                sb.append(funcDef);
                sb.append("<FuncDef>\n");
            }
            sb.append(mainFuncDef);
            sb.append("<MainFuncDef>\n");
            return sb.toString();
        }
    }

    /**
     * Decl → ConstDecl | VarDecl*/
    public static class Decl implements BlockItem {
        private final Token type;

        public Decl(Token type) {
            assert type.type == TokenType.INTTK ||  type.type == TokenType.CHARTK ||  type.type == TokenType.VOIDTK;
            this.type = type;
        }

        public Token getType() {
            return type;
        }
    }

    /**
     * FuncDef → FuncType Ident ‘(’ [FuncFParams] ‘)’ Block
     * MainFuncDef → 'int' 'main' '(' ')' Block // 存在main函数
     */
    public static class FuncDef extends Decl {
        private final Ident ident;
        private ArrayList<FuncFParam> funcFParams = null;
        private final Block block;

        public FuncDef(Token funcType, Ident ident, ArrayList<FuncFParam> funcFParams, Block block) {
            super(funcType);
            this.ident = ident;
            this.funcFParams = funcFParams;
            this.block = block;
        }


        public Ident getIdent() {
            return ident;
        }

        public ArrayList<FuncFParam> getFuncFParams() {
            return funcFParams;
        }

        public Block getBlock() {
            return block;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(super.getType());
            if (this instanceof MainFuncDef) {
                ;
            } else {
                sb.append("<FuncType>\n");
            }
            sb.append(ident);
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            if (funcFParams != null) {
                sb.append(funcFParams.get(0));
                sb.append("<FuncFParam>\n");
                for (int i = 1; i < funcFParams.size(); i++) {
                    sb.append(new Token(TokenType.COMMA, ",", -1));
                    sb.append(funcFParams.get(i));
                    sb.append("<FuncFParam>\n");
                }
                sb.append("<FuncFParams>\n");
            }
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(block);
            sb.append("<Block>\n");
            return sb.toString();
        }
    }

    public static class MainFuncDef extends FuncDef {

        // Main function definition doesn't have parameters, and return type is always 'int'
        public MainFuncDef(Token inter,Ident mainer,Block block) {
            // Call the parent constructor with "int" as the function type, "main" as the identifier
            // and an empty parameter list (since main doesn't take parameters)
            super(inter, mainer, null, block);
        }

        // You can add specific methods for MainFuncDef if needed
    }

    /**
     * Block → ‘{’ { BlockItem } ‘}’
     */
    public static class Block {

        private final ArrayList<BlockItem> blockItems;

        public Block(ArrayList<BlockItem> blockItems) {
            this.blockItems = blockItems;
        }

        public ArrayList<BlockItem> getBlockItems() {
            return blockItems;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.LBRACE, "{", -1));
            for (BlockItem blockItem : blockItems) {
                sb.append(blockItem);
                if (blockItem instanceof Stmt) {
                    sb.append("<Stmt>\n");
                }
                if (blockItem instanceof ConstDecl) {
                    sb.append("<ConstDecl>\n");
                }
                if (blockItem instanceof VarDecl) {
                    sb.append("<VarDecl>\n");
                }
            }
            sb.append(new Token(TokenType.RBRACE, "}", -1));
            return sb.toString();
        }
    }

    /**FuncFParam → BType Ident ['[' ']'] // b k
     *  FuncFParams → FuncFParam { ',' FuncFParam }
     * */
    public static class FuncFParam {
        private final Token btype;
        private final Ident ident;
        private final boolean isArray;

        public FuncFParam(Token btype, Ident ident) {
            this.ident = ident;
            this.btype = btype;
            this.isArray = false;
        }

        public FuncFParam(Token btype, Ident ident, boolean isArray) {
            this.btype = btype;
            this.ident = ident;
            this.isArray = isArray;
        }

        public Ident getIdent() {
            return ident;
        }

        public Token getBtype() {
            return btype;
        }

        public boolean isArray() {
            return isArray;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(btype);
            sb.append(ident.toString());
            if (isArray) {
                sb.append(new Token(TokenType.LBRACK, "[", -1));
                sb.append(new Token(TokenType.RBRACK, "]", -1));
            }
            return sb.toString();
        }

    }

    /** VarDecl → BType VarDef { ',' VarDef } ';' // 1.花括号内重复0次 2.花括号内重复多次
     * */
    public static class VarDecl extends Decl {
        private final Token btype;
        private final ArrayList<VarDef> varDefs;


        public VarDecl(Token btype, ArrayList<VarDef> varDefs) {
            super(btype);
            this.btype = btype;
            this.varDefs = varDefs;
        }

        public Token getBtype() {
            return btype;
        }

        public ArrayList<VarDef> getVarDefs() {
            return varDefs;
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append(btype.toString());
            builder.append(varDefs.get(0));
            builder.append("<VarDef>\n");
            for (int i = 1; i < varDefs.size(); i++) {
                builder.append(new Token(TokenType.COMMA, ",", -1));
                builder.append(varDefs.get(i).toString());
                builder.append("<VarDef>\n");
            }
            builder.append(new Token(TokenType.SEMICN, ";",-1));
            return builder.toString();
        }

    }

    /** VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='InitVal // 包含普通常量、一维数组定义
     * */
    public static class VarDef {
        private final Ident ident;

        private AddExp constExp  = null;

        private final InitVal initVal;

        public VarDef(Ident ident, AddExp constExp, InitVal initVal) {
            this.ident = ident;
            this.constExp = constExp;
            this.initVal = initVal;
        }

        public VarDef(Ident ident, AddExp constExp) {
            this.ident = ident;
            this.constExp = constExp;
            this.initVal = new InitVal();
        }

        public VarDef(Ident ident, InitVal initVal) {
            this.ident = ident;
            this.initVal = initVal;
        }

        public VarDef(Ident ident) {
            this.ident = ident;
            this.initVal = new InitVal();
        }

        public Ident getIdent() {
            return ident;
        }

        public AddExp getConstExp() {
            return constExp;
        }

        public InitVal getInitVal() {
            return initVal;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(ident);
            if (constExp != null) {
                sb.append(new Token(TokenType.LBRACK,"[",-1));
                sb.append(constExp);
                sb.append("<AddExp>\n");
                sb.append("<ConstExp>\n");
                sb.append(new Token(TokenType.RBRACK,"]",-1));
            }
            if (initVal != null && initVal.hasInitVal()) {
                sb.append(new Token(TokenType.ASSIGN,"=",-1));
                sb.append(initVal);
                sb.append("<InitVal>\n");
            }
            return sb.toString();
        }
    }

     /**ConstDecl → ‘const’ BType ConstDef { ‘,’ ConstDef } ‘;’
     * */
    public static class ConstDecl extends Decl {
        private final Token btype;
        private final ArrayList<ConstDef> constDefs;

        public ConstDecl(Token btype, ArrayList<ConstDef> constDefs) {
            super(btype);
            this.btype = btype;
            this.constDefs = constDefs;
        }

        public Token getBtype() {
            return btype;
        }

        public ArrayList<ConstDef> getConstDefs() {
            return constDefs;
        }

         @Override
         public String toString() {
             StringBuilder builder = new StringBuilder();
             builder.append(new Token(TokenType.CONSTTK, "const", -1));
             builder.append(btype.toString());
             builder.append(constDefs.get(0));
             builder.append("<ConstDef>\n");
             for (int i = 1; i < constDefs.size(); i++) {
                 builder.append(new Token(TokenType.COMMA, ",", -1));
                 builder.append(constDefs.get(i).toString());
                 builder.append("<ConstDef>\n");
             }
             builder.append(new Token(TokenType.SEMICN, ";",-1));
             return builder.toString();
         }

    }

    /**
     * ConstDef → Ident [ ‘[’ ConstExp ‘]’ ] ‘=’ ConstInitVal
     */
    public static class ConstDef {
        private final Ident ident;
        private AddExp constExp = null;
        private final ConstInitVal constInitVal;

        public ConstDef(Ident ident, ConstInitVal constInitVal) {
            this.ident = ident;
            this.constInitVal = constInitVal;
        }

        public ConstDef(Ident ident, AddExp constExp, ConstInitVal constInitVal) {
            this.ident = ident;
            this.constExp = constExp;
            this.constInitVal = constInitVal;
        }

        public Ident getIdent() {
            return ident;
        }

        public AddExp getConstExp() {
            return constExp;
        }

        public ConstInitVal getConstInitVal() {
            return constInitVal;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(ident.toString());
            if (constExp != null) {
                sb.append(new Token(TokenType.LBRACK,"[",ident.identifier.lineIndex));
                sb.append(constExp.toString());
                sb.append("<AddExp>\n");
                sb.append("<ConstExp>\n");
                sb.append(new Token(TokenType.RBRACK,"]",ident.identifier.lineIndex));

            }
            sb.append(new Token(TokenType.ASSIGN,"=",ident.identifier.lineIndex));
            sb.append(constInitVal.toString());
            sb.append("<ConstInitVal>\n");
            return sb.toString();
        }

    }

    /**
     * Exp → AddExp
     * AddExp → MulExp | AddExp ('+' | '−') MulExp // 1.MulExp 2.+ 需覆盖 3.- 需覆盖
     * 左递归，需要改写文法
     * AddExp → MulExp + AddExpSuffix
     * AddExpSuffix → ‘+’ MulExp AddExpSuffix | ‘-’ MulExp AddExpSuffix | ε*/
    public static class AddExp {
        private final MulExp mulExp;
        private final AddExpSuffix addExpSuffix;

        public AddExp(MulExp mulExp, AddExpSuffix addExpSuffix) {
            this.mulExp = mulExp;
            this.addExpSuffix = addExpSuffix;
        }

        public MulExp getMulExp() {
            return mulExp;
        }

        public AddExpSuffix getAddExpSuffix() {
            return addExpSuffix;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(mulExp.toString());
            sb.append("<MulExp>\n");
            if (addExpSuffix != null && addExpSuffix.mulExp != null) {
                sb.append("<AddExp>\n");
            }
            sb.append(addExpSuffix.toString());
            return sb.toString();
        }

    }

    public static class AddExpSuffix {
        private MulExp mulExp = null;
        private AddExpSuffix addExpSuffix = null;
        private Token addOp = null;

        public AddExpSuffix(MulExp mulExp, AddExpSuffix addExpSuffix, Token addOp) {
            assert addOp.type == TokenType.PLUS || addOp.type == TokenType.MINU;
            this.mulExp = mulExp;
            this.addExpSuffix = addExpSuffix;
            this.addOp = addOp;
        }

        public AddExpSuffix() {}

        public AddExpSuffix getAddExpSuffix() {
            return addExpSuffix;
        }

        public MulExp getMulExp() {
            return mulExp;
        }

        public Token getAddOp() {
            return addOp;
        }

        public boolean hasMulExp() {
            return mulExp != null;
        }

        public boolean hasNext() {
            if (addExpSuffix == null) {
                return false;
            }
            if (addExpSuffix.mulExp == null) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (mulExp != null) {
                sb.append(addOp);
                sb.append(mulExp);
                sb.append("<MulExp>\n");
                if (hasNext()) {
                    sb.append("<AddExp>\n");
                }
            }
            if (hasNext()) {
                sb.append(addExpSuffix);
            }
            return sb.toString();
        }
    }

    /**
     * MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp // 1.UnaryExp 2.* 3./ 4.% 均需覆盖
     * 左递归改写文法
     * MulExp → UnaryExp + MulExpSuffix
     * MulExpSuffix → '*' UnaryExp MulExpSuffix | '/' UnaryExp MulExpSuffix | '%' UnaryExp MulExpSuffix / ε */
    public static class MulExp {
        private final UnaryExp unaryExp;
        private final MulExpSuffix mulExpSuffix;

        public MulExp(UnaryExp unaryExp, MulExpSuffix mulExpSuffix){
            this.mulExpSuffix = mulExpSuffix;
            this.unaryExp = unaryExp;
        }

        public UnaryExp getUnaryExp() {
            return unaryExp;
        }

        public MulExpSuffix getMulExpSuffix() {
            return mulExpSuffix;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(unaryExp.toString());
            sb.append("<UnaryExp>\n");
            if (mulExpSuffix != null && mulExpSuffix.unaryExp != null) {
                sb.append("<MulExp>\n");
            }
            sb.append(mulExpSuffix.toString());
            return sb.toString();
        }

    }

    public static class MulExpSuffix {
        private UnaryExp unaryExp = null;
        private MulExpSuffix mulExpSuffix = null;
        private Token mulOp = null;

        public MulExpSuffix(UnaryExp unaryExp, MulExpSuffix mulExpSuffix, Token mulOp) {
            assert mulOp.type == TokenType.MULT || mulOp.type == TokenType.DIV || mulOp.type == TokenType.MOD;
            this.mulExpSuffix = mulExpSuffix;
            this.unaryExp = unaryExp;
            this.mulOp = mulOp;
        }

        public MulExpSuffix() {}

        public Token getMulOp() {
            return mulOp;
        }

        public UnaryExp getUnaryExp() {
            return unaryExp;
        }

        public MulExpSuffix getMulExpSuffix() {
            return mulExpSuffix;
        }

        public boolean hasUnary() {
            return unaryExp != null;
        }

        public boolean hasNext() {
            if (mulExpSuffix == null) {
                return false;
            }
            if (mulExpSuffix.unaryExp == null) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (unaryExp != null) {
                sb.append(mulOp);
                sb.append(unaryExp);
                sb.append("<UnaryExp>\n");
                if (hasNext()) {
                    sb.append("<MulExp>\n");
                }
            }
            if (mulExpSuffix != null) {
                sb.append(mulExpSuffix);
            }
            return sb.toString();
        }
    }

    /** UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
     * */
    public static class UnaryExp {
        private PrimaryExp primaryExp = null;
        private Ident ident = null;
        private FuncRParams funcRParams = null;
        private Token unaryOp = null;
        private UnaryExp unaryExp = null;

        public UnaryExp(PrimaryExp primaryExp) {
            this.primaryExp = primaryExp;
        }

        public UnaryExp(Ident ident, FuncRParams funcRParams) {
            this.ident = ident;
            this.funcRParams = funcRParams;
        }

        public UnaryExp(Ident ident) {
            this.ident = ident;
        }

        public UnaryExp(Token unaryOp, UnaryExp unaryExp) {
            assert unaryOp.type == TokenType.NOT || unaryOp.type == TokenType.PLUS || unaryOp.type == TokenType.MINU;
            this.unaryOp = unaryOp;
            this.unaryExp = unaryExp;
        }

        public PrimaryExp getPrimaryExp() {
            return primaryExp;
        }

        public Ident getIdent() {
            return ident;
        }

        public FuncRParams getFuncRParams() {
            return funcRParams;
        }

        public Token getUnaryOp() {
            return unaryOp;
        }

        public UnaryExp getUnaryExp() {
            return unaryExp;
        }

        public boolean isPrimaryExp() {
            return primaryExp != null;
        }

        public boolean isFunctionCall() {
            return ident != null;
        }

        public boolean isSubUnaryExp() {
            return unaryOp != null && unaryExp != null;
        }


        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (primaryExp != null) {
                sb.append(primaryExp);
                sb.append("<PrimaryExp>\n");
                return sb.toString();
            }
            if (ident != null) {
                sb.append(ident);
                sb.append(new Token(TokenType.LPARENT, "(", -1));
                if (funcRParams != null) {
                    sb.append(funcRParams);
                    sb.append("<FuncRParams>\n");
                }
                sb.append(new Token(TokenType.RPARENT, ")", -1));
                return sb.toString();
            }
            sb.append(unaryOp);
            sb.append("<UnaryOp>\n");
            sb.append(unaryExp);
            sb.append("<UnaryExp>\n");
            return sb.toString();
        }
    }

    /**
     * FuncRParams → Exp { ',' Exp }
     * Exp → AddExp
     */
    public static class FuncRParams {
        private final ArrayList<AddExp> params;

        public FuncRParams(ArrayList<AddExp> params) {
            this.params = params;
        }

        public ArrayList<AddExp> getParams() {
            return params;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(params.get(0).toString());
            sb.append("<AddExp>\n");
            sb.append("<Exp>\n");
            for (int i = 1; i < params.size(); i++) {
                sb.append(new Token(TokenType.COMMA, ",", -1));
                sb.append(params.get(i).toString());
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
            }
            return sb.toString();
        }
    }

    /**
     * PrimaryExp → ‘(’ Exp ‘)’ | LVal | Number | Character
     * Exp → AddExp
     */
    public static class PrimaryExp {
        private AddExp exp = null;
        private Lval lval = null;
        private Token number = null;
        private Token character = null;

        public PrimaryExp(AddExp exp) {
            this.exp = exp;
        }

        public PrimaryExp(Lval lval) {
            this.lval = lval;
        }

        public PrimaryExp(Token token) {
            if (token.type == TokenType.INTCON) {
                this.number = token;
            } else if (token.type == TokenType.CHRCON){
                this.character = token;
            } else {
                System.err.println("Unknown primary exp token: " + token);
            }

        }

        public AddExp getExp() {
            return exp;
        }

        public Lval getLval() {
            return lval;
        }

        public Token getNumber() {
            return number;
        }

        public Token getCharacter() {
            return character;
        }

        public boolean isExp() {
            return exp != null;
        }

        public boolean isLval() {
            return lval != null;
        }

        public boolean isNumber() {
            return number != null;
        }

        public boolean isCharacter() {
            return character != null;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (exp != null) {
                sb.append(new Token(TokenType.LPARENT, "(", -1));
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
                sb.append(new Token(TokenType.RPARENT, ")", -1));
                return sb.toString();
            }
            if (lval != null) {
                sb.append(lval);
                sb.append("<LVal>\n");
                return sb.toString();
            }
            if (character != null) {
                sb.append(character);
                sb.append("<Character>\n");
                return sb.toString();
            }
            if (number != null) {
                sb.append(number);
                sb.append("<Number>\n");
                return sb.toString();
            }
            return "error in PrimaryExp\n";
        }
    }

    /**
     * LVal → Ident ['[' Exp ']'] // c k
     */
    public static class Lval {
        private final Ident ident;
        private AddExp exp = null;

        public Lval(Ident ident, AddExp exp) {
            this.ident = ident;
            this.exp = exp;
        }
        public Lval(Ident ident) {
            this.ident = ident;
        }
        public Ident getIdent() {
            return ident;
        }

        public AddExp getExp() {
            return exp;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(ident.toString());
            if (exp != null) {
                sb.append(new Token(TokenType.LBRACK, "[", -1));
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
                sb.append(new Token(TokenType.RBRACK, "]", -1));
            }
            return sb.toString();
        }


    }


     /** InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
      * */
     public static class InitVal {
         protected AddExp exp = null; // Single expression (can be constant or variable)
         protected ArrayList<AddExp> exps = null; // List of expressions
         protected StringConst strConst = null; // String constant

         // Constructor for a single expression (variable by default)
         public InitVal(AddExp exp) {
             this.exp = exp;
         }

         // Constructor for a list of expressions
         public InitVal(ArrayList<AddExp> exps) {
             this.exps = exps;
         }

         // Constructor for a string constant
         public InitVal(StringConst strConst) {
             this.strConst = strConst;
         }

         // Default constructor
         public InitVal() {}

         // Get the single expression
         public AddExp getExp() {
             return exp;
         }

         // Get the list of expressions
         public ArrayList<AddExp> getExps() {
             return exps;
         }

         // Get the string constant
         public StringConst getStringConst() {
             return strConst;
         }

         // Check if this InitVal has any initialization value
         public boolean hasInitVal() {
             return (exp != null) || (exps != null && !exps.isEmpty()) || (strConst != null);
         }

         @Override
         public String toString() {
             if (exp == null && exps == null && strConst == null) {
                 StringBuilder sb = new StringBuilder();
                 sb.append(new Token(TokenType.LBRACE, "{", -1));
                 sb.append(new Token(TokenType.RBRACE, "}", -1));
                 return sb.toString();
             } else if (exp != null) {
                 StringBuilder sb = new StringBuilder();
                 sb.append(exp);
                 sb.append("<AddExp>\n");
                 sb.append("<Exp>\n");
                 return sb.toString();
             } else if (strConst != null) {
                 return strConst.toString();
             } else if (exps != null) {
                 StringBuilder sb = new StringBuilder();
                 sb.append(new Token(TokenType.LBRACE, "{", -1));
                 for (int i = 0; i < exps.size(); i++) {
                     AddExp exp = exps.get(i);
                     sb.append(exp.toString());
                     sb.append("<AddExp>\n");
                     sb.append("<Exp>\n");
                     // 如果不是最后一个元素，添加逗号
                     if (i < exps.size() - 1) {
                         sb.append(new Token(TokenType.COMMA, ",", -1));
                     }
                 }
                 sb.append(new Token(TokenType.RBRACE, "}", -1));
                 return sb.toString();
             } else {
                 return "wrong in InitVal\n";
             }
         }
     }

    /**
     * ConstInitVal → ConstExp | ‘{’ [ ConstExp  { ‘,’ ConstExp  } ] ‘} | StringConst’
     */
    public static class ConstInitVal extends InitVal {

        public ConstInitVal(AddExp constExp) {
            super(constExp);
            // Ensure the expression is constant, throw an exception if not
//            if (!isConstantExp(constExp)) {
//                throw new IllegalArgumentException("ConstInitVal can only accept constant expressions.");
//            }
        }

        public ConstInitVal(ArrayList<AddExp> constExps) {
            super(new ArrayList<>(constExps));
        }

        public ConstInitVal(StringConst strConst) {
            super(strConst);
        }

        public ConstInitVal() {}

        public String toString() {
            if (exp == null && exps == null && strConst == null) {
                StringBuilder sb = new StringBuilder();
                sb.append(new Token(TokenType.LBRACE, "{", -1));
                sb.append(new Token(TokenType.RBRACE, "}", -1));
                return sb.toString();
            } else if (exp != null) {
                StringBuilder sb = new StringBuilder();
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<ConstExp>\n");
                return sb.toString();
            } else if (strConst != null) {
                return strConst.toString();
            } else if (exps != null && !exps.isEmpty()) {
                StringBuilder sb = new StringBuilder();
                sb.append(new Token(TokenType.LBRACE, "{", -1));
                for (int i = 0; i < exps.size(); i++) {
                    AddExp exp = exps.get(i);
                    sb.append(exp.toString());
                    sb.append("<AddExp>\n");
                    sb.append("<ConstExp>\n");
                    // 如果不是最后一个元素，添加逗号
                    if (i < exps.size() - 1) {
                        sb.append(new Token(TokenType.COMMA, ",", -1));
                    }
                }
                sb.append(new Token(TokenType.RBRACE, "}", -1));
                return sb.toString();
            } else {
                return "wrong in InitVal\n";
            }
        }


    }

    public static class Ident {
        public Token identifier;
        public Ident(Token token) {
            assert token.type == TokenType.IDENFR;
            this.identifier = token;
        }
        @Override
        public String toString() {
            return identifier.toString();
        }
    }

    /**StringConst → '"' {ASCII} '"'
     * */
    public static class StringConst{
        public Token stringConst;
        public StringConst(Token stringConst) {
            assert stringConst.type == TokenType.STRCON;
            this.stringConst = stringConst;
        }
        @Override
        public String toString() {
            return stringConst.toString();
        }
    }

    /** BType → ‘int’ | ‘float’
     * */

    /** BlockItem -> Decl | Stmt
     * */
    public interface BlockItem {
    }


    /**Stmt → LVal ‘=’ Exp ‘;’ | [Exp] ‘;’ | Block | ‘if’ ‘(’ Cond ‘)’ Stmt [ ‘else’ Stmt ] |
     * 'for' '(' [AssignStmt] ';' [Cond] ';' [AssignStmt] ')' Stmt | ‘break’ ‘;’ | ‘continue’ ‘;’ | ‘return’ [Exp] ‘;’|
     * LVal '=' 'getint''('')'';' | LVal '=' 'getchar''('')'';' | 'printf''('StringConst {','Exp}')'';'
     */
    public static class Stmt  implements BlockItem {}

    public static class AssignStmt extends Stmt {
        private final Lval lval;
        private final AddExp exp;

        public AssignStmt(Lval lval, AddExp exp) {
            this.lval = lval;
            this.exp = exp;
        }

        public AddExp getExp() {
            return exp;
        }

        public Lval getLval() {
            return lval;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(lval);
            sb.append("<LVal>\n");
            sb.append(new Token(TokenType.ASSIGN, "=", -1));
            sb.append(exp);
            sb.append("<AddExp>\n");
            sb.append("<Exp>\n");
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class ForAssignStmt extends Stmt{
        private final Lval lval;
        private final AddExp exp;

        public  ForAssignStmt(Lval lval, AddExp exp) {
            this.lval = lval;
            this.exp = exp;
        }

        public AddExp getExp() {
            return exp;
        }

        public Lval getLval() {
            return lval;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(lval);
            sb.append("<LVal>\n");
            sb.append(new Token(TokenType.ASSIGN, "=", -1));
            sb.append(exp);
            sb.append("<AddExp>\n");
            sb.append("<Exp>\n");
            return sb.toString();
        }
    }

    public static class ExpStmt extends Stmt {
        private final AddExp exp;

        public ExpStmt(AddExp exp) {
            this.exp = exp;
        }

        public AddExp getExp() {
            return exp;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (exp != null) {
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
            }
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class BlockStmt extends Stmt {
        private final Block block;

        public BlockStmt(Block block) {
            this.block = block;
        }

        public Block getBlock() {
            return block;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(block);
            sb.append("<Block>\n");
            return sb.toString();
        }
    }

    public static class IfStmt extends Stmt {
        private final LOrExp cond;
        private final Stmt stmt;

        public IfStmt(LOrExp cond, Stmt stmt) {
            this.cond = cond;
            this.stmt = stmt;
        }

        public Stmt getStmt() {
            return stmt;
        }

        public LOrExp getCond() {
            return cond;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.IFTK, "if", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            sb.append(cond);
            sb.append("<LOrExp>\n");
            sb.append("<Cond>\n");
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(stmt);
            sb.append("<Stmt>\n");
            return sb.toString();
        }
    }

    public static class ForStmt extends Stmt {
        private  ForAssignStmt assignStmt1 = null;
        private  ForAssignStmt assignStmt2 = null;
        private  LOrExp cond = null;
        private final Stmt stmt;
        public ForStmt(ForAssignStmt assignStmt1,LOrExp cond, ForAssignStmt assignStmt2,Stmt stmt) { //可以传null进来
            this.assignStmt1 = assignStmt1;
            this.assignStmt2 = assignStmt2;
            this.cond = cond;
            this.stmt = stmt;
        }
        public ForStmt(Stmt stmt) {
            this.stmt = stmt;
        }
        public ForAssignStmt getAssignStmt1() {
            return assignStmt1;
        }
        public ForAssignStmt getAssignStmt2() {
            return assignStmt2;
        }
        public Stmt getStmt() {
            return stmt;
        }
        public LOrExp getCond() {
            return cond;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.FORTK, "for", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            if (assignStmt1 != null) {
                sb.append(assignStmt1);
                sb.append("<ForStmt>\n");
            }
            sb.append(new Token(TokenType.SEMICN,";",-1));
            if (cond != null) {
                sb.append(cond);
                sb.append("<LOrExp>\n");
                sb.append("<Cond>\n");
            }
            sb.append(new Token(TokenType.SEMICN,";",-1));
            if (assignStmt2 != null) {
                sb.append(assignStmt2);
                sb.append("<ForStmt>\n");
            }
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(stmt);
            sb.append("<Stmt>\n");
            return sb.toString();
        }

    }

    public static class IfElStmt extends Stmt {
        private final LOrExp cond;
        private final Stmt stmt;
        private final Stmt stmt1;

        public IfElStmt(LOrExp cond, Stmt stmt, Stmt stmt1) {
            this.cond = cond;
            this.stmt = stmt;
            this.stmt1 = stmt1;
        }

        public LOrExp getCond() {
            return cond;
        }

        public Stmt getStmt() {
            return stmt;
        }

        public Stmt getStmt1() {
            return stmt1;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.IFTK, "if", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            sb.append(cond);
            sb.append("<LOrExp>\n");
            sb.append("<Cond>\n");
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(stmt);
            sb.append("<Stmt>\n");
            sb.append(new Token(TokenType.ELSETK, "else", -1));
            sb.append(stmt1);
            sb.append("<Stmt>\n");
            return sb.toString();
        }

    }

    public static class VoidStmt extends Stmt {
        public VoidStmt() {}
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class BreakStmt extends Stmt {
        public BreakStmt() {}
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.BREAKTK, "break", -1));
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class ContinueStmt extends Stmt {
        public ContinueStmt() {}
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.CONTINUETK, "continue", -1));
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class ReturnStmt extends Stmt {

        private AddExp exp = null;

        public ReturnStmt() {}

        public ReturnStmt(AddExp exp) {
            this.exp = exp;
        }

        public AddExp getExp() {
            return exp;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.RETURNTK, "return", -1));
            if (exp != null) {
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
            }
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }

    public static class GetIntStmt extends Stmt {
        private final Lval lval;

        public GetIntStmt(Lval lval) {
            this.lval = lval;
        }
        public Lval getLval() {
            return lval;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(lval);
            sb.append("<LVal>\n");
            sb.append(new Token(TokenType.ASSIGN, "=", -1));
            sb.append(new Token(TokenType.GETINTTK, "getint", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(new Token(TokenType.SEMICN,";", -1));
            return sb.toString();
        }
    }

    public static class GetCharStmt extends Stmt {
        private final Lval lval;
        public GetCharStmt(Lval lval) {
            this.lval = lval;
        }
        public Lval getLval() {
            return lval;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(lval);
            sb.append("<LVal>\n");
            sb.append(new Token(TokenType.ASSIGN, "=", -1));
            sb.append(new Token(TokenType.GETCHARTK, "getchar", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(new Token(TokenType.SEMICN,";", -1));
            return sb.toString();
        }
    }

    public static class PrintfStmt extends Stmt {
        private final StringConst stringConst;
        protected final ArrayList<AddExp> exps;

        public PrintfStmt(StringConst stringConst, ArrayList<AddExp> exps) {
            this.stringConst = stringConst;
            this.exps = exps;
        }
        public StringConst getStringConst() {
            return stringConst;
        }
        public ArrayList<AddExp> getExps() {
            return exps;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(new Token(TokenType.PRINTFTK, "printf", -1));
            sb.append(new Token(TokenType.LPARENT, "(", -1));
            sb.append(stringConst);
            for (AddExp exp : exps) {
                sb.append(new Token(TokenType.COMMA, ",", -1));
                sb.append(exp);
                sb.append("<AddExp>\n");
                sb.append("<Exp>\n");
            }
            sb.append(new Token(TokenType.RPARENT, ")", -1));
            sb.append(new Token(TokenType.SEMICN, ";", -1));
            return sb.toString();
        }
    }


    /** Cond → LOrExp
     * LOrExp → LAndExp | LOrExp '||' LAndExp
     * 改写
     * Cond → LOrExp
     * LOrExp → LAndExp LOrExpSuffix
     * LOrExpSuffix → '||' LAndExp LOrExpSuffix | ε
     * */
    public static class LOrExp  {
        private final LAndExp lAndExp;
        private final LOrExpSuffix lOrExpSuffix;
        public LOrExp(LAndExp lAndExp, LOrExpSuffix lOrExpSuffix) {
            this.lAndExp = lAndExp;
            this.lOrExpSuffix = lOrExpSuffix;
        }
        public LAndExp getLAndExp() {
            return lAndExp;
        }
        public LOrExpSuffix getLOrExpSuffix() {
            return lOrExpSuffix;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(lAndExp);
            sb.append("<LAndExp>\n");
            if (lOrExpSuffix != null && lOrExpSuffix.lAndExp != null) {
                sb.append("<LOrExp>\n");
            }
            sb.append(lOrExpSuffix);
            return sb.toString();
        }
    }
    public static class LOrExpSuffix {
        private Token op = null;
        private LAndExp lAndExp = null;
        private LOrExpSuffix lOrExpSuffix = null;
        public LOrExpSuffix(Token op, LAndExp lAndExp, LOrExpSuffix lOrExpSuffix) {
            assert op.type == TokenType.OR;
            this.op = op;
            this.lAndExp = lAndExp;
            this.lOrExpSuffix = lOrExpSuffix;
        }
        public LOrExpSuffix() {

        }
        public Token getOp() {
            return op;
        }
        public LAndExp getLAndExp() {
            return lAndExp;
        }
        public LOrExpSuffix getLOrExpSuffix() {
            return lOrExpSuffix;
        }
        public boolean hasRelExp() {
            return lAndExp != null;
        }
        public boolean hasNext() {
            if (lOrExpSuffix == null) {
                return false;
            }
            if (lOrExpSuffix.lAndExp == null) {
                return false;
            }
            return true;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (lAndExp != null) {
                sb.append(op);
                sb.append(lAndExp);
                sb.append("<LAndExp>\n");
                if (hasNext()) {
                    sb.append("<LOrExp>\n");
                }
            }
            if (hasNext()) {
                sb.append(lOrExpSuffix);
            }
            return sb.toString();
        }

    }
    /** LAndExp → EqExp | LAndExp '&&' EqExp // a
     * 改写
     * LAndExp  → EqExp LAndExpSuffix
     * LAndExpSuffix → '&&' EqExp LAndExpSuffix | ε
     * */
    public static class LAndExp {
        private final EqExp eqExp;
        private final LAndExpSuffix lAndExpSuffix;
        public LAndExp(EqExp eqExp, LAndExpSuffix lAndExpSuffix) {
            this.eqExp = eqExp;
            this.lAndExpSuffix = lAndExpSuffix;
        }
        public EqExp getEqExp() {
            return eqExp;
        }
        public LAndExpSuffix getLAndExpSuffix() {
            return lAndExpSuffix;
        }
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(eqExp);
            sb.append("<EqExp>\n");
            if (lAndExpSuffix != null && lAndExpSuffix.eqExp != null) {
                sb.append("<LAndExp>\n");
            }
            sb.append(lAndExpSuffix);
            return sb.toString();
        }
    }
    public static class LAndExpSuffix {
        private Token op = null;
        private EqExp eqExp = null;
        private LAndExpSuffix lAndExpSuffix = null;
        public LAndExpSuffix(Token op, EqExp eqExp, LAndExpSuffix lAndExpSuffix) {
            assert op.type == TokenType.AND;
            this.op = op;
            this.eqExp = eqExp;
            this.lAndExpSuffix = lAndExpSuffix;
        }
        public LAndExpSuffix() {

        }
        public EqExp getEqExp() {
            return eqExp;
        }
        public LAndExpSuffix getLAndExpSuffix() {
            return lAndExpSuffix;
        }
        public Token getOp() {
            return op;
        }
        public boolean hasEqExp(){
            return eqExp != null;
        }
        public boolean hasNext(){
            if (lAndExpSuffix == null || lAndExpSuffix.eqExp == null) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (eqExp != null) {
                sb.append(op);
                sb.append(eqExp);
                sb.append("<EqExp>\n");
                if (hasNext()) {
                    sb.append("<LAndExp>\n");
                }
            }
            if (hasNext()) {
                sb.append(lAndExpSuffix);
            }
            return sb.toString();
        }
    }
    /** EqExp → RelExp | EqExp ('==' | '!=') RelExp
     * 改写
     * EqExp  → RelExp EqExpSuffix
     * EqExpSuffix → ('==' | '!=') RelExp EqExpSuffix | ε
     * */
    public static class EqExp {
        private final RelExp relExp;
        private final EqExpSuffix eqExpSuffix;
        public EqExp(RelExp relExp, EqExpSuffix eqExpSuffix) {
            this.relExp = relExp;
            this.eqExpSuffix = eqExpSuffix;
        }
        public RelExp getRelExp() {
            return relExp;
        }
        public EqExpSuffix getEqExpSuffix() {
            return eqExpSuffix;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(relExp);
            sb.append("<RelExp>\n");
            if (eqExpSuffix != null && eqExpSuffix.relExp != null) {
                sb.append("<EqExp>\n");
            }
            sb.append(eqExpSuffix);
            return sb.toString();
        }
    }
    public static class EqExpSuffix {
        private Token op = null;
        private RelExp relExp = null;
        private EqExpSuffix eqExpSuffix = null;
        public EqExpSuffix(Token op, RelExp relExp, EqExpSuffix eqExpSuffix) {
            assert op.type == TokenType.EQL || op.type == TokenType.NEQ;
            this.op = op;
            this.relExp = relExp;
            this.eqExpSuffix = eqExpSuffix;
        }
        public EqExpSuffix(){}
        public Token getOp() {
            return op;
        }
        public RelExp getRelExp() {
            return relExp;
        }
        public EqExpSuffix getEqExpSuffix() {
            return eqExpSuffix;
        }
        public boolean hasRelExp() {
            return relExp != null;
        }
        public boolean hasNext() {
            if (eqExpSuffix == null) {
                return false;
            }
            if (eqExpSuffix.relExp == null) {
                return false;
            }
            return true;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (relExp != null) {
                sb.append(op);
                sb.append(relExp);
                sb.append("<RelExp>\n");
                if (hasNext()) {
                    sb.append("<EqExp>\n");
                }
            }
            if (hasNext()) {
                sb.append(eqExpSuffix);
            }
            return sb.toString();
        }
    }
    /** RelExp  → AddExp RelExpSuffix
     * RelExpSuffix → ('<' | '>' | '<=' | '>=') AddExp RelExpSuffix | ε
     * */
    public static class RelExp {
        private final AddExp addExpexp;
        private final RelExpSuffix relExpSuffix;
        public RelExp(AddExp addExpexp, RelExpSuffix relExpSuffix) {
            this.addExpexp = addExpexp;
            this.relExpSuffix = relExpSuffix;
        }
        public AddExp getAddExp() {
            return addExpexp;
        }
        public RelExpSuffix getRelExpSuffix() {
            return relExpSuffix;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(addExpexp);
            sb.append("<AddExp>\n");
            if (relExpSuffix != null && relExpSuffix.addExp != null) {
                sb.append("<RelExp>\n");
            }
            sb.append(relExpSuffix);
            return sb.toString();
        }
    }
    public static class RelExpSuffix {
        private Token op = null;
        private AddExp addExp = null;
        private RelExpSuffix relExpSuffix = null;
        public RelExpSuffix(Token op, AddExp addExp, RelExpSuffix relExpSuffix) {
            assert op.type == TokenType.LSS || op.type == TokenType.GRE || op.type == TokenType.GEQ || op.type == TokenType.LEQ;
            this.op = op;
            this.addExp = addExp;
            this.relExpSuffix = relExpSuffix;
        }
        public RelExpSuffix() {

        }
        public Token getOp() {
            return op;
        }
        public AddExp getAddExp() {
            return addExp;
        }
        public RelExpSuffix getRelExpSuffix() {
            return relExpSuffix;
        }
        public boolean hasAddExp() {
            return addExp != null;
        }
        public boolean hasNext() {
            if (relExpSuffix == null) {
                return false;
            }
            if (relExpSuffix.addExp == null) {
                return false;
            }
            return true;
        }
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (addExp != null) {
                sb.append(op);
                sb.append(addExp);
                sb.append("<AddExp>\n");
                if (hasNext()) {
                    sb.append("<RelExp>\n");
                }
            }
            if (hasNext()) {
                sb.append(relExpSuffix);
            }
            return sb.toString();
        }
    }

}


