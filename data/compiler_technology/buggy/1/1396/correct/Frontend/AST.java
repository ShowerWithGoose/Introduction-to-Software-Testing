package Frontend;

import java.util.ArrayList;

import Driver.Driver;
import Utils.*;
import Utils.SymbolTable.*;
import Utils.SymbolTable.SymbolTable.*;

public class AST {
    public CompUnit compUnit;
    public static MainSymbolTable mainSymbolTable;

    public AST(TokenList tokenList) { this.compUnit = new CompUnit(tokenList); }

    public class CompUnit {
        // CompUnit -> {Decl} {FuncDef} MainFuncDef
        public ArrayList<Decl> decls = new ArrayList<>();
        public ArrayList<FuncDef> funcDefs = new ArrayList<>();
        public MainFuncDef mainFuncDef;

        public CompUnit(TokenList tokenList) {
            while (tokenList.hasNext()) {
                try { decls.add(new Decl(tokenList)); }
                catch (NotCorrespondingClassException e) { break; }
            }
            while (tokenList.hasNext()) {
                try { funcDefs.add(new FuncDef(tokenList)); }
                catch (NotCorrespondingClassException e) { break; }
            }
            try {
                mainFuncDef = new MainFuncDef(tokenList);
                System.out.println("Successfully Parsed");
            } catch (NotCorrespondingClassException e) {
                System.err.println("Tokens are not all parsed.");
                System.err.println("Stopped at " + tokenList.nowat());
            }
        }

        @Override
        public String toString() {
            String res = "";
            for (Decl decl: decls) res += decl;
            for (FuncDef funcDef: funcDefs) res += funcDef;
            res += mainFuncDef;
            return res + "<CompUnit>";
        }

        public void toSymbolTable(MainSymbolTable symbolTable) {
            for (Decl decl: decls) decl.toSymbolTable(symbolTable);
            for (FuncDef funcDef: funcDefs) funcDef.toSymbolTable(symbolTable);
            mainFuncDef.toSymbolTable(symbolTable);
        }
    }

    public interface ASTUnit {}

    public class Decl implements ASTUnit, BlockItem.BlockItemUnit {
        // Decl -> ConstDecl | VarDecl
        public DeclUnit decl;

        public Decl(TokenList tokenList)  throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                decl = new ConstDecl(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                decl = new VarDecl(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("Decl: not match");
            }
        }

        public interface DeclUnit {}

        @Override
        public String toString() { return decl + ""; }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (decl instanceof ConstDecl) ((ConstDecl)decl).toSymbolTable(symbolTable);
            else ((VarDecl)decl).toSymbolTable(symbolTable);
        }
    }

    public class ConstDecl implements Decl.DeclUnit {
        // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
        public BType bType;
        public ArrayList<ConstDef> constDefs = new ArrayList<>();

        public ConstDecl(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            Token token;
            if ((token = tokenList.consume(Token.Type.CONSTTK)) == null) throw new NotCorrespondingClassException("ConstDecl: No Keyword 'Const'");
            token = tokenList.consume(BType.correspondingTokenTypeList);
            if (token == null) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("ConstDecl: No Keyword 'Int' or 'Char'");
            } this.bType = new BType(token);
            do {
                constDefs.add(new ConstDef(tokenList));
                token = tokenList.consume(Token.Type.COMMA, Token.Type.SEMICN);
                if (token == null) {
                    Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                    break;
                } if (token.getType().equals(Token.Type.SEMICN)) break;
            } while(tokenList.hasNext());
            tokenList.commit();
        }

        public String toString() {
            StringBuilder sb = new StringBuilder("CONSTTK const\n" + bType);
            for (int i = 0; i < constDefs.size() - 1; i++) sb.append(constDefs.get(i) + "COMMA ,\n");
           sb.append(constDefs.get(constDefs.size() - 1) + "SEMICN ;\n");
            return sb.append("<ConstDecl>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            for (ConstDef constDef: constDefs) {
                try {
                    SymbolType type = SymbolType.fromString(bType.type.getType().name(), false, true, !constDef.constExps.isEmpty());
                    symbolTable.addSymbol(constDef.ident.token, type);
                } catch (SymbolTable.SymbolAlreadyExistsException e) { Driver.errorRecord.addError(constDef.ident.token.line, "b"); }
            }
        }
    }

    public class ConstDef {
        // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        public Ident ident;
        public ArrayList<ConstExp> constExps = new ArrayList<>();
        public ConstInitVal constInitVal;

        public ConstDef(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(Token.Type.IDENFR);
                if (token == null) throw new NotCorrespondingClassException("ConstDef: No 'Ident'");
                this.ident = new Ident(token);
                while (true) {
                    token = tokenList.consume(Token.Type.LBRACK);
                    if (token == null) break;
                    constExps.add(new ConstExp(tokenList));
                    token = tokenList.consume(Token.Type.RBRACK);
                    if (token == null) Driver.errorRecord.addError(tokenList.previousToken().line, "k");
                } token = tokenList.consume(Token.Type.ASSIGN);
                if (token == null) throw new NotCorrespondingClassException("ConstDef: No '=' after Ident");
                constInitVal = new ConstInitVal(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(ident + "");
            for (ConstExp constExp: constExps) sb.append("LBRACK [\n" + constExp + "RBRACK ]\n");
            sb.append("ASSIGN =\n");
            return sb.append(constInitVal).append("<ConstDef>\n").toString();
        }
    }

    public class VarDecl implements Decl.DeclUnit {
        // VarDecl -> BType VarDef { ',' VarDef } ';'
        public BType bType;
        public ArrayList<VarDef> varDefs = new ArrayList<>();

        public VarDecl(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(BType.correspondingTokenTypeList);
                if (token == null) throw new NotCorrespondingClassException("VarDecl: No BType");
                this.bType = new BType(token);
                do {
                    varDefs.add(new VarDef(tokenList));
                    token = tokenList.consume(Token.Type.COMMA, Token.Type.SEMICN);
                    if (token == null) {
                        if (tokenList.tryConsume(Token.Type.LPARENT) != null)  throw new NotCorrespondingClassException("VarDecl: No ',' or ';' after VarDef");
                        Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                        break;
                    } if (token.getType().equals(Token.Type.SEMICN)) break;
                } while(tokenList.hasNext());
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(bType + "");
            for (int i = 0; i < varDefs.size() - 1; i++) sb.append(varDefs.get(i) + "COMMA ,\n");
            sb.append(varDefs.get(varDefs.size() - 1) + "SEMICN ;\n");
            return sb.append("<VarDecl>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            for (VarDef varDef: varDefs) {
                try {
                    SymbolType type = SymbolType.fromString(bType.type.getType().name(), false, false, !varDef.constExps.isEmpty());
                    symbolTable.addSymbol(varDef.ident.token, type);
                    varDef.toSymbolTable(symbolTable);
                } catch (SymbolTable.SymbolAlreadyExistsException e) { Driver.errorRecord.addError(varDef.ident.token.line, "b"); }
            }
        }
    }

    public class FuncDef implements ASTUnit {
        // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
        public Ident ident;
        public FuncType funcType;
        public FuncParams funcParams;
        public Block block;

        public FuncDef(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(FuncType.correspondingTokenTypeList);
                if (token == null) throw new NotCorrespondingClassException("FuncDef: No FuncType");
                funcType = new FuncType(token);
                token = tokenList.consume(Token.Type.IDENFR);
                if (token == null) throw new NotCorrespondingClassException("FuncDef: No Ident");
                this.ident  = new Ident(token);
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("FuncDef: No '('");
                if (tokenList.consume(Token.Type.RPARENT) == null) {
                    if (tokenList.tryConsume(Token.Type.LBRACE) == null) funcParams = new FuncParams(tokenList);
                    if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                } block = new Block(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return funcType + "" + ident + "LPARENT (\n" + (funcParams == null ? "" : funcParams) + "RPARENT )\n" + block + "<FuncDef>\n"; }

        public void toSymbolTable(MainSymbolTable symbolTable) {
            SymbolType type = SymbolType.fromString(funcType.type.getType().name(), true, false, false);
            FuncSymbolTable funcSymbolTable = new FuncSymbolTable(symbolTable, type);
            try {
                symbolTable.addSymbol(ident.token, type);
                symbolTable.addFunc(ident.token, funcSymbolTable);
            } catch (SymbolTable.SymbolAlreadyExistsException e) { Driver.errorRecord.addError(ident.token.line, "b"); }
            if (funcParams != null) funcParams.toSymbolTable(funcSymbolTable);
            block.toSymbolTable(funcSymbolTable);
        }

        public class FuncType {
            // FuncType -> 'void' | 'int' | 'char'
            public Token type;

            public FuncType(Token token) throws NotCorrespondingClassException {
                if (!java.util.Arrays.asList(correspondingTokenTypeList).contains(token.getType())) throw new NotCorrespondingClassException("FuncType: Not a Legal Type");
                this.type = token;
            }

            public static final Token.Type[] correspondingTokenTypeList = new Token.Type[] { Token.Type.VOIDTK, Token.Type.INTTK, Token.Type.CHARTK };

            @Override
            public String toString() { return type + "\n<FuncType>\n"; }
        }
    }

    public class FuncParams {
        // FuncFParams -> FuncFParam { ',' FuncFParam }
        public ArrayList<FuncFParam> funcFParams = new ArrayList<>();

        public FuncParams(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                while (true) {
                    funcFParams.add(new FuncFParam(tokenList));
                    Token token = tokenList.consume(Token.Type.COMMA);
                    if (token == null) break;
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("FuncParams: not match");
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < funcFParams.size() - 1; i++) sb.append(funcFParams.get(i) + "COMMA ,\n");
            sb.append(funcFParams.get(funcFParams.size() - 1));
            return sb.append("<FuncFParams>\n").toString();
        }

        public void toSymbolTable(FuncSymbolTable symbolTable) { for (FuncFParam funcFParam: funcFParams) funcFParam.toSymbolTable(symbolTable); }
    }

    public class FuncFParam {
        // FuncFParam -> BType Ident ['[' ']']
        public BType bType;
        public Ident ident;
        // public ArrayList<ConstExp> constExps = new ArrayList<>();
        private int count = 0;

        public FuncFParam(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(BType.correspondingTokenTypeList);
                if (token == null) throw new NotCorrespondingClassException("FuncFParam: No BType");
                this.bType = new BType(token);
                token = tokenList.consume(Token.Type.IDENFR);
                if (token == null) throw new NotCorrespondingClassException("FuncFParam: No Ident");
                this.ident = new Ident(token);
                // while (true) {
                //     token = tokenList.consume(Token.Type.LBRACK);
                //     if (token == null) break;
                //     if (tokenList.consume(Token.Type.RBRACK) == null) {
                //         constExps.add(new ConstExp(tokenList));
                //         if (tokenList.consume(Token.Type.RBRACK) == null) throw new NotCorrespondingClassException("FuncFParam: No ']' Found After '['");
                //     }
                // }
                token = tokenList.consume(Token.Type.LBRACK);
                if (token != null) {
                    count++;
                    if (tokenList.consume(Token.Type.RBRACK) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "k");
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(bType + "" + ident);
            for (int i = 0; i < count; i++) sb.append("LBRACK [\nRBRACK ]\n");
            return sb.append("<FuncFParam>\n").toString();
        }

        public void toSymbolTable(FuncSymbolTable symbolTable) {
            try {
                SymbolType type = SymbolType.fromString(bType.type.getType().name(), false, false, count > 0);
                symbolTable.addParam(ident.token, type);
            } catch (SymbolTable.SymbolAlreadyExistsException e) { Driver.errorRecord.addError(ident.token.line, "b"); }
        }
    }

    public class MainFuncDef implements ASTUnit {
        // MainFuncDef -> 'int' 'main' '(' ')' Block
        public Block block;
        public Token maintk;

        public MainFuncDef(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                if (tokenList.consume(Token.Type.INTTK) == null) throw new NotCorrespondingClassException("MainFuncDef: No 'int'");
                maintk = tokenList.consume(Token.Type.MAINTK);
                if (maintk == null) throw new NotCorrespondingClassException("MainFuncDef: No 'main'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("MainFuncDef: No '('");
                if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                block = new Block(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            return (
                "INTTK int\n" +
                "MAINTK main\n" +
                "LPARENT (\n" +
                "RPARENT )\n" +
                block +
                "<MainFuncDef>\n"
            );
        }

        public void toSymbolTable(MainSymbolTable symbolTable) {
            SymbolType type = SymbolType.fromString("INTTK", true, false, false);
            FuncSymbolTable funcSymbolTable = new FuncSymbolTable(symbolTable, type);
            try { symbolTable.addFunc(maintk, funcSymbolTable); }
            catch (SymbolTable.SymbolAlreadyExistsException e) { Driver.errorRecord.addError(block.lbrace.line, "b"); }
            block.toSymbolTable(funcSymbolTable);
        }
    }

    public class BType {
        // BType -> 'int' | 'char'
        public Token type;

        public BType(Token btype) throws NotCorrespondingClassException {
            if (btype.getType() != Token.Type.INTTK && btype.getType() != Token.Type.CHARTK)
                throw new NotCorrespondingClassException("BType: Not an Integer Type");
            this.type = btype;
        }

        public static final Token.Type[] correspondingTokenTypeList = new Token.Type[] { Token.Type.INTTK, Token.Type.CHARTK };

        @Override
        public String toString() { return type + "\n"; }
    }

    public class Ident{
        // Ident matches [_a-zA-Z][_a-zA-Z0-9]*
        public Token token;

        public Ident(Token token) throws NotCorrespondingClassException {
            String name = (String)token.getValue();
            if (name.matches("[_a-zA-Z][_a-zA-Z0-9]*"))
                this.token = token;
            else throw new NotCorrespondingClassException("Ident: Not Legal Ident \"" + name + "\"");
        }

        @Override
        public String toString() {
            return token + "\n";
        }
    }

    public class ConstExp implements ConstInitVal.ConstInitValUnit {
        // ConstExp -> AddExp
        public AddExp addExp;

        public ConstExp(TokenList tokenList) throws NotCorrespondingClassException { addExp = new AddExp(tokenList); }

        @Override
        public String toString() { return addExp + "<ConstExp>\n"; }
    }

    public class ConstInitVal {
        // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        public ConstInitValUnit constInitVal;

        public ConstInitVal(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                constInitVal = new ConstExp(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                constInitVal = new StringConst(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                constInitVal = new ConstExps(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("ConstInitVal: not match");
            }
        }

        public interface ConstInitValUnit {}

        public class ConstExps implements ConstInitValUnit {
            // ConstExps -> '{' [ ConstExp { ',' ConstExp } ] '}'
            public ArrayList<ConstExp> constExps = new ArrayList<>();

            public ConstExps(TokenList tokenList) throws NotCorrespondingClassException {
                tokenList.stamp(); Token token;
                try {
                    if ((token = tokenList.consume(Token.Type.LBRACE)) == null) throw new NotCorrespondingClassException("ConstExps: No '{'");
                    if ((token = tokenList.consume(Token.Type.RBRACE)) != null) {
                        tokenList.commit();
                        return;
                    } while (true) {
                        constExps.add(new ConstExp(tokenList));
                        token = tokenList.consume(Token.Type.COMMA);
                        if (token == null) break;
                    } if (tokenList.consume(Token.Type.RBRACE) == null) throw new NotCorrespondingClassException("ConstExps: No '}'");
                    tokenList.commit();
                } catch(NotCorrespondingClassException e) {
                    tokenList.rollback();
                    tokenList.commit();
                    throw new NotCorrespondingClassException("ConstExps: not match");
                }
            }

            @Override
            public String toString() {
                StringBuilder sb = new StringBuilder();
                sb.append("LBRACE {\n");
                if (!constExps.isEmpty()) {
                    sb.append(constExps.get(0));
                    for (int i = 1; i < constExps.size(); i++) sb.append("COMMA ,\n" + constExps.get(i));
                }
                return sb.append("RBRACE }\n").toString();
            }
        }

        @Override
        public String toString() { return constInitVal + "<ConstInitVal>\n"; }
    }

    // public class ConstInitVals implements ConstInitVal.ConstInitValUnit {
    // --------------- Deprecated --------------
    //     public ArrayList<ConstInitVal> constInitVals = new ArrayList<>();
    //
    //     public ConstInitVals(TokenList tokenList) throws NotCorrespondingClassException {
    //         tokenList.stamp();
    //         try {
    //             if (tokenList.consume(Token.Type.LBRACE) == null) throw new NotCorrespondingClassException("ConstInitVals: No '{'");
    //             if (tokenList.consume(Token.Type.RBRACE) != null) {
    //                 tokenList.commit();
    //                 return;
    //             }
    //             while (true) {
    //                 constInitVals.add(new ConstInitVal(tokenList));
    //                 Token token = tokenList.consume(Token.Type.COMMA);
    //                 if (token == null) break;
    //             } if (tokenList.consume(Token.Type.RBRACE) == null) throw new NotCorrespondingClassException("ConstInitVals: No '}'");
    //             tokenList.commit();
    //         } catch(NotCorrespondingClassException e) {
    //             tokenList.rollback();
    //             tokenList.commit();
    //             throw new NotCorrespondingClassException("ConstInitVals: not match");
    //         }
    //     }
    // }

    public class VarDef {
        // VarDef -> Ident { '[' ConstExp ']' } | Ident { '[' ConstExp ']' } '=' InitVal
        public Ident ident;
        public ArrayList<ConstExp> constExps = new ArrayList<>();
        public InitVal initVal;

        public VarDef(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(Token.Type.IDENFR);
                if (token == null) throw new NotCorrespondingClassException("VarDef: No 'Ident'");
                ident = new Ident(token);
                while (true) {
                    token = tokenList.consume(Token.Type.LBRACK);
                    if (token == null) break;
                    constExps.add(new ConstExp(tokenList));
                    token = tokenList.consume(Token.Type.RBRACK);
                    if (token == null) Driver.errorRecord.addError(tokenList.previousToken().line, "k");
                } token = tokenList.consume(Token.Type.ASSIGN);
                if (token != null) initVal = new InitVal(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("VarDef: not match");
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(ident + "");
            for (ConstExp constExp: constExps) sb.append("LBRACK [\n" + constExp + "RBRACK ]\n");
            if (initVal != null) sb.append("ASSIGN =\n" + initVal);
            return sb.append("<VarDef>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (initVal != null)
                initVal.toSymbolTable(symbolTable);
        }
    }

    public class InitVal {
        // InitVal -> Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        public InitValUnit initVal;

        public InitVal(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                initVal = new Exp(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                initVal = new StringConst(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                initVal = new Exps(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("InitVal: not match");
            }
        }

        @Override
        public String toString() { return initVal + "<InitVal>\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (initVal instanceof Exp) ((Exp)initVal).toSymbolTable(symbolTable);
            else if (initVal instanceof Exps) ((Exps)initVal).toSymbolTable(symbolTable);
        }

        public interface InitValUnit {}

        public class Exps implements InitValUnit {
            public ArrayList<Exp> exps = new ArrayList<>();
            private ArrayList<Token> tokens = new ArrayList<>();

            public Exps(TokenList tokenList) throws NotCorrespondingClassException {
                tokenList.stamp();
                try {
                    Token token;
                    if ((token = tokenList.consume(Token.Type.LBRACE)) == null) throw new NotCorrespondingClassException("Exps: No '{'");
                    tokens.add(token);
                    if ((token = tokenList.consume(Token.Type.RBRACE)) != null) {
                        tokenList.commit();
                        tokens.add(token);
                        return;
                    } while (true) {
                        exps.add(new Exp(tokenList));
                        token = tokenList.consume(Token.Type.COMMA);
                        if (token == null) break;
                        tokens.add(token);
                    } if ((token = tokenList.consume(Token.Type.RBRACE)) == null) throw new NotCorrespondingClassException("Exps: No '}'");
                    tokens.add(token);
                    tokenList.commit();
                } catch(NotCorrespondingClassException e) {
                    tokenList.rollback();
                    tokenList.commit();
                    throw new NotCorrespondingClassException("Exps: not match");
                }
            }

            @Override
            public String toString() {
                StringBuilder sb = new StringBuilder();
                for (Exp exp: exps) sb.append(tokens.remove(0) + "\n" + exp);
                return sb.append(tokens.remove(0) + "\n").toString();
            }

            public void toSymbolTable(SymbolTable symbolTable) {
                for (Exp exp: exps) exp.toSymbolTable(symbolTable);
            }
        }
    }

    public class Block implements Stmt.StmtUnit {
        // Block -> '{' { BlockItem } '}'
        public ArrayList<BlockItem> blockItems = new ArrayList<>();
        private Token lbrace, rbrace;

        public Block(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                if ((lbrace = tokenList.consume(Token.Type.LBRACE)) == null) throw new NotCorrespondingClassException("Block: No '{'");
                while (true) {
                    try { blockItems.add(new BlockItem(tokenList)); }
                    catch (NotCorrespondingClassException e) { break; }
                } if ((rbrace = tokenList.consume(Token.Type.RBRACE)) == null) throw new NotCorrespondingClassException("Block: No '}'");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(lbrace + "\n");
            for (BlockItem blockItem: blockItems) sb.append(blockItem);
            return sb.append(rbrace + "\n<Block>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            for (BlockItem blockItem: blockItems)
                blockItem.toSymbolTable(symbolTable);
            if (symbolTable instanceof FuncSymbolTable) {
                if (((FuncSymbolTable)symbolTable).returnType != SymbolType.VoidFunc) {
                    if (!blockItems.isEmpty()) {
                        BlockItem lastBlockItem = blockItems.get(blockItems.size() - 1);
                        if (lastBlockItem.blockItemUnit instanceof Stmt)
                            if (((Stmt)lastBlockItem.blockItemUnit).stmtUnit instanceof Return) return;
                    } Driver.errorRecord.addError(rbrace.line, "g");
                }
            }
        }
    }

    public class BlockItem {
        // BlockItem -> Decl | Stmt
        public BlockItemUnit blockItemUnit;

        public interface BlockItemUnit {}

        public BlockItem(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
             try {
                blockItemUnit = new Decl(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                blockItemUnit = new Stmt(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("BlockItem: not match");
            }
        }

        @Override
        public String toString() { return blockItemUnit + ""; }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (blockItemUnit instanceof Decl) ((Decl)blockItemUnit).toSymbolTable(symbolTable);
            else if (blockItemUnit instanceof Stmt) ((Stmt)blockItemUnit).toSymbolTable(symbolTable);
        }
    }

    public class Stmt implements BlockItem.BlockItemUnit {
        /*
            Stmt -> LVal '=' Exp ';'
                    | [Exp] ';'
                    | Block
                    | 'if' '(' Cond ')' Stmt ['else' Stmt]
                    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                    | 'break' ';'
                    | 'continue' ';'
                    | 'return' [Exp] ';'
                    | 'printf''('FormatString{','Exp}')'';'
                    | LVal '=' 'getint' '(' ')' ';'
                    | LVal '=' 'getchar' '(' ')' ';'
        */
        public StmtUnit stmtUnit;

        public interface StmtUnit {}

        public Stmt(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            if (tokenList.consume(Token.Type.SEMICN) != null) {
                tokenList.commit();
                return;
            } tokenList.rollback();
            try {
                stmtUnit = new Block(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new If(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new For(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new Break(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new Continue(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new Return(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new Printf(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new GetInt(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new GetChar(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new LValeqsExp(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                stmtUnit = new Exp(tokenList);
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            if (stmtUnit != null) {
                if (stmtUnit instanceof Exp) return stmtUnit + "SEMICN ;\n<Stmt>\n";
                else return stmtUnit + "<Stmt>\n";
            } else return "SEMICN ;\n<Stmt>\n";
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (stmtUnit == null) return;
            else if (stmtUnit instanceof Block) {
                SymbolTable block = new SymbolTable(symbolTable);
                ((Block)stmtUnit).toSymbolTable(block);
            } else if (stmtUnit instanceof If) ((If)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof For) ((For)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof Break) ((Break)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof Continue) ((Continue)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof Printf) ((Printf)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof LValeqsExp) ((LValeqsExp)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof GetInt) ((GetInt)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof GetChar) ((GetChar)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof Return) ((Return)stmtUnit).toSymbolTable(symbolTable);
            else if (stmtUnit instanceof Exp) ((Exp)stmtUnit).toSymbolTable(symbolTable);
        }
    }

    public class Break implements Stmt.StmtUnit {
        // Stmt -> 'break' ';'
        public Token token;

        public Break(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                token = tokenList.consume(Token.Type.BREAKTK);
                if (token == null) throw new NotCorrespondingClassException("Break: No 'break'");
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return "BREAKTK break\nSEMICN ;\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            SymbolTable current = symbolTable;
            while (current != null) {
                if (current instanceof LoopSymbolTable) {
                    return;
                } current = current.parent;
            }
            Driver.errorRecord.addError(token.line, "m");
        }
    }

    public class Continue implements Stmt.StmtUnit {
        // Stmt -> 'continue' ';'
        public Token token;

        public Continue(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                token = tokenList.consume(Token.Type.CONTINUETK);
                if (token == null) throw new NotCorrespondingClassException("Continue: No 'continue'");
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return "CONTINUETK continue\nSEMICN ;\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            SymbolTable current = symbolTable;
            while (current != null) {
                if (current instanceof LoopSymbolTable) {
                    return;
                } current = current.parent;
            }
            Driver.errorRecord.addError(token.line, "m");
        }
    }

    public class GetInt implements Stmt.StmtUnit {
        // Stmt -> LVal '=' 'getint''('')'';'
        public LVal lVal;

        public GetInt(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                lVal = new LVal(tokenList);
                if (tokenList.consume(Token.Type.ASSIGN) == null) throw new NotCorrespondingClassException("GetChar: No '=' after LVal");
                if (tokenList.consume(Token.Type.GETINTTK) == null) throw new NotCorrespondingClassException("GetInt: No 'getint'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("GetInt: No '(' after 'getint'");
                if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            return lVal + "ASSIGN =\nGETINTTK getint\nLPARENT (\nRPARENT )\nSEMICN ;\n";
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            try {
                SymbolType type = symbolTable.getSymbolType(lVal.ident.token);
                if (type == SymbolType.ConstChar || type == SymbolType.ConstInt || type == SymbolType.ConstCharArray || type == SymbolType.ConstIntArray)
                    Driver.errorRecord.addError(lVal.ident.token.line, "h");
            } catch (SymbolTable.SymbolNotFoundException e) { Driver.errorRecord.addError(lVal.ident.token.line, "c"); }
        }
    }

    public class GetChar implements Stmt.StmtUnit {
        // Stmt -> LVal '=' 'getchar''('')'';'
        public LVal lVal;
        public GetChar(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                lVal = new LVal(tokenList);
                if (tokenList.consume(Token.Type.ASSIGN) == null) throw new NotCorrespondingClassException("GetChar: No '=' after LVal");
                if (tokenList.consume(Token.Type.GETCHARTK) == null) throw new NotCorrespondingClassException("GetChar: No 'getchar'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("GetChar: No '(' after 'getchar'");
                if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return lVal + "ASSIGN =\nGETCHARTK getchar\nLPARENT (\nRPARENT )\nSEMICN ;\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            try {
                SymbolType type = symbolTable.getSymbolType(lVal.ident.token);
                if (type == SymbolType.ConstChar || type == SymbolType.ConstInt || type == SymbolType.ConstCharArray || type == SymbolType.ConstIntArray)
                    Driver.errorRecord.addError(lVal.ident.token.line, "h");
            } catch (SymbolTable.SymbolNotFoundException e) { Driver.errorRecord.addError(lVal.ident.token.line, "c"); }
        }
    }

    public class Return implements Stmt.StmtUnit {
        // Stmt -> 'return' [Exp] ';'
        public Exp exp;
        public Token token;

        public Return(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                token = tokenList.consume(Token.Type.RETURNTK);
                if (token == null) throw new NotCorrespondingClassException("Return: No 'return'");
                if (tokenList.consume(Token.Type.SEMICN) != null) {
                    tokenList.commit();
                    return;
                } try { exp = new Exp(tokenList); }
                catch(NotCorrespondingClassException e) { }
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return "RETURNTK return\n" + (exp == null ? "" : exp + "") + "SEMICN ;\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (exp != null)
                exp.toSymbolTable(symbolTable);
            SymbolTable current = symbolTable;
            while (current != null) {
                if (current instanceof FuncSymbolTable) {
                    if (((FuncSymbolTable)current).returnType == SymbolType.VoidFunc) {
                        if (exp != null) Driver.errorRecord.addError(token.line, "f");
                    } return;
                } current = current.parent;
            }
        }
    }

    public class Printf implements Stmt.StmtUnit {
        // Stmt -> 'printf''('FormatString{','Exp}')'';'
        public Token printf;
        public Token formatString;
        public ArrayList<Exp> exps = new ArrayList<>();

        public Printf(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                printf = tokenList.consume(Token.Type.PRINTFTK);
                if (printf == null) throw new NotCorrespondingClassException("Printf: No 'printf'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("Printf: No '(' after 'printf'");
                Token token = tokenList.consume(Token.Type.STRCON);
                if (token == null) throw new NotCorrespondingClassException("Printf: No Format String");
                formatString = token;
                while (true) {
                    token = tokenList.consume(Token.Type.COMMA);
                    if (token == null) break;
                    exps.add(new Exp(tokenList));
                } if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder("PRINTFTK printf\nLPARENT (\n" + formatString + "\n");
            for (Exp exp: exps) sb.append("COMMA ,\n").append(exp);
            return sb.append("RPARENT )\nSEMICN ;\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            String format = (String)formatString.getValue();
            int count = 0;
            for (int i = 0; i < format.length() - 1; i++) {
                char c1 = format.charAt(i), c2 = format.charAt(i + 1);
                if (c1 == '%') {
                    if (c2 == 'd' || c2 == 'c' || c2 == 's') {
                        count++;
                        i++;
                    }
                }
            } if (count != exps.size()) Driver.errorRecord.addError(printf.line, "l");
            for (Exp exp: exps)
                exp.toSymbolTable(symbolTable);
        }
    }

    public class Exp implements PrimaryExp.PrimaryExpUnit, Stmt.StmtUnit, InitVal.InitValUnit {
        // Exp -> AddExp
        public AddExp addExp;

        public Exp(TokenList tokenList) throws NotCorrespondingClassException {
            addExp = new AddExp(tokenList);
        }

        @Override
        public String toString() { return addExp + "<Exp>\n"; }

        public void toSymbolTable(SymbolTable symbolTable) { addExp.toSymbolTable(symbolTable); }
    }

    public class LVal implements PrimaryExp.PrimaryExpUnit {
        // LVal -> Ident {'[' Exp ']'}
        public Ident ident;
        public ArrayList<Exp> exps = new ArrayList<>();

        public LVal(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                Token token = tokenList.consume(Token.Type.IDENFR);
                if (token == null) throw new NotCorrespondingClassException("LVal: No 'Ident'");
                ident = new Ident(token);
                while (true) {
                    token = tokenList.consume(Token.Type.LBRACK);
                    if (token == null) break;
                    exps.add(new Exp(tokenList));
                    token = tokenList.consume(Token.Type.RBRACK);
                    if (token == null) Driver.errorRecord.addError(tokenList.previousToken().line, "k");
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("LVal: not match");
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(ident + "");
            for (Exp exp: exps) sb.append("LBRACK [\n" + exp + "RBRACK ]\n");
            return sb.append("<LVal>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            try { symbolTable.getSymbolType(ident.token); }
            catch (SymbolTable.SymbolNotFoundException e) { Driver.errorRecord.addError(ident.token.line, "c"); }
        }
    }

    public class Cond {
        // Cond -> LOrExp
        public LOrExp lOrExp;

        public Cond(TokenList tokenList) throws NotCorrespondingClassException {
            lOrExp = new LOrExp(tokenList);
        }

        @Override
        public String toString() { return lOrExp + "<Cond>\n"; }
    }

    public class LValeqsExp implements Stmt.StmtUnit {
        // Stmt -> LVal '=' Exp ';'
        public LVal lVal;
        public Exp exp;

        public LValeqsExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                lVal = new LVal(tokenList);
                if (tokenList.consume(Token.Type.ASSIGN) == null) throw new NotCorrespondingClassException("LValeqsExp: No '='");
                exp = new Exp(tokenList);
                if (tokenList.consume(Token.Type.SEMICN) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "i");
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() { return lVal + "ASSIGN =\n" + exp + "SEMICN ;\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            try {
                SymbolType type = symbolTable.getSymbolType(lVal.ident.token);
                if (type == SymbolType.ConstChar || type == SymbolType.ConstInt || type == SymbolType.ConstCharArray || type == SymbolType.ConstIntArray)
                    Driver.errorRecord.addError(lVal.ident.token.line, "h");
            } catch (SymbolTable.SymbolNotFoundException e) { Driver.errorRecord.addError(lVal.ident.token.line, "c"); }
            exp.toSymbolTable(symbolTable);
        }
    }

    public class If implements Stmt.StmtUnit {
        // Stmt -> 'if' '(' Cond ')' Stmt ['else' Stmt]
        public Cond cond;
        public Stmt thenStmt;
        public Stmt elseStmt;

        public If(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                if (tokenList.consume(Token.Type.IFTK) == null) throw new NotCorrespondingClassException("If: No 'if'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("If: No '('");
                cond = new Cond(tokenList);
                if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                thenStmt = new Stmt(tokenList);
                Token token = tokenList.consume(Token.Type.ELSETK);
                if (token == null) {
                    tokenList.commit();
                    return;
                } else {
                    elseStmt = new Stmt(tokenList);
                    tokenList.commit();
                }
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        @Override
        public String toString() {
            return (
                "IFTK if\n" +
                "LPARENT (\n" +
                cond + "" +
                "RPARENT )\n" +
                thenStmt + "" +
                (elseStmt == null ? "" : "ELSETK else\n" + elseStmt + "")
            );
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (thenStmt != null) thenStmt.toSymbolTable(symbolTable);
            if (elseStmt != null) elseStmt.toSymbolTable(symbolTable);
        }
    }

    public class For implements Stmt.StmtUnit {
        // Stmt -> 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        public ForStmt init;
        public ForCond check;
        public ForStmt then;
        public Stmt stmt;

        @Override
        public String toString() {
            return (
                "FORTK for\n" +
                "LPARENT (\n" +
                (init == null ? "" : init + "") +
                "SEMICN ;\n" +
                (check == null ? "" : check + "") +
                "SEMICN ;\n" +
                (then == null ? "" : then + "") +
                "RPARENT )\n" +
                stmt
            );
        }

        public For(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                if (tokenList.consume(Token.Type.FORTK) == null) throw new NotCorrespondingClassException("For: No 'for'");
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("For: No '('");
                Token token = tokenList.consume(Token.Type.SEMICN);
                if (token == null) {
                    init = new ForStmt(tokenList);
                    if (tokenList.consume(Token.Type.SEMICN) == null) throw new NotCorrespondingClassException("For: No ';' after ForStmt");
                } token = tokenList.consume(Token.Type.SEMICN);
                if (token == null) {
                    check = new ForCond(tokenList);
                    if (tokenList.consume(Token.Type.SEMICN) == null) throw new NotCorrespondingClassException("For: No ';' Found After ForCond");
                } token = tokenList.consume(Token.Type.RPARENT);
                if (token == null) {
                    then = new ForStmt(tokenList);
                    if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                } stmt = new Stmt(tokenList);
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (init != null) init.toSymbolTable(symbolTable);
            if (then != null) then.toSymbolTable(symbolTable);
            LoopSymbolTable loopSymbolTable = new LoopSymbolTable(symbolTable);
            stmt.toSymbolTable(loopSymbolTable);
        }

        public class ForStmt {
            // ForStmt -> LVal '=' Exp
            public LVal lVal;
            public Exp exp;

            public ForStmt(TokenList tokenList) throws NotCorrespondingClassException {
                tokenList.stamp();
                try {
                    lVal = new LVal(tokenList);
                    if (tokenList.consume(Token.Type.ASSIGN) == null) throw new NotCorrespondingClassException("ForStmt: No '=' after LVal");
                    exp = new Exp(tokenList);
                    tokenList.commit();
                } catch(NotCorrespondingClassException e) {
                    tokenList.rollback();
                    tokenList.commit();
                }
            }

            @Override
            public String toString() { return lVal + "ASSIGN =\n" + exp + "<ForStmt>\n"; }

            public void toSymbolTable(SymbolTable symbolTable) {
                lVal.toSymbolTable(symbolTable);
                try {
                    SymbolType type = symbolTable.getSymbolType(lVal.ident.token);
                    if (type == SymbolType.ConstChar || type == SymbolType.ConstInt || type == SymbolType.ConstCharArray || type == SymbolType.ConstIntArray)
                        Driver.errorRecord.addError(lVal.ident.token.line, "h");
                } catch (SymbolTable.SymbolNotFoundException e) { Driver.errorRecord.addError(lVal.ident.token.line, "c"); }
                exp.toSymbolTable(symbolTable);
            }
        }

        public class ForCond {
            // ForCond -> Cond
            public Cond cond;

            public ForCond(TokenList tokenList) {
                try { cond = new Cond(tokenList); }
                catch(NotCorrespondingClassException e) {}
            }

            @Override
            public String toString() { return cond + ""; }
        }
    }

    public class AddExp {
        // AddExp -> MulExp {('+'|'-') MulExp}
        public ArrayList<Pair<OpType, MulExp>> mulExps = new ArrayList<>();

        public AddExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                mulExps.add(new Pair<>(OpType.PLUS, new MulExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.PLUS, Token.Type.MINU);
                    if (token == null) break;
                    mulExps.add(new Pair<>(token.getType().equals(Token.Type.PLUS) ? OpType.PLUS : OpType.MINU, new MulExp(tokenList)));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("AddExp: not match");
            }
        }

        public enum OpType {
            MINU, PLUS;

            @Override
            public String toString() { return this.equals(MINU) ? "MINU -" : "PLUS +"; }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(mulExps.get(0).second() + "");
            for (int i = 1; i < mulExps.size(); i++) sb.append("<AddExp>\n" + mulExps.get(i).first() + "\n" + mulExps.get(i).second());
            return sb.append("<AddExp>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            for (Pair<OpType, MulExp> pair: mulExps)
                pair.second().toSymbolTable(symbolTable);
        }
    }

    public class MulExp {
        // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        public ArrayList<Pair<MulExpOpType, UnaryExp>> unaryExps = new ArrayList<>();

        public MulExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                unaryExps.add(new Pair<>(null, new UnaryExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.MULT, Token.Type.DIV, Token.Type.MOD);
                    if (token == null) break;
                    unaryExps.add(new Pair<>(token.getType().equals(Token.Type.MULT) ? MulExpOpType.MUL : token.getType().equals(Token.Type.DIV) ? MulExpOpType.DIV : MulExpOpType.MOD, new UnaryExp(tokenList)));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("MulExp: not match");
            }
        }

        public enum MulExpOpType {
            MUL, DIV, MOD;

            @Override
            public String toString() {
                return this.equals(MUL) ? "MULT *" : this.equals(DIV) ? "DIV /" : "MOD %";
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(unaryExps.get(0).second() + "");
            for (int i = 1; i < unaryExps.size(); i++) sb.append("<MulExp>\n" + unaryExps.get(i).first() + "\n" + unaryExps.get(i).second());
            return sb.append("<MulExp>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            for (Pair<MulExpOpType, UnaryExp> pair: unaryExps)
                pair.second().toSymbolTable(symbolTable);

        }
    }

    public class UnaryExp {
        // UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        public UnaryExpUnit unaryExp = null;
        public ArrayList<UnaryOp> unaryOps = new ArrayList<>();

        public UnaryExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                UnaryOp op = null;
                do {
                    Token token = tokenList.consume(Token.Type.PLUS, Token.Type.MINU, Token.Type.NOT);
                    if (token != null) {
                        op = token.getType().equals(Token.Type.PLUS) ? UnaryOp.POS : token.getType().equals(Token.Type.MINU) ? UnaryOp.NEG : UnaryOp.NOT;
                        unaryOps.add(op);
                    } else op = null;
                } while(op != null);
                tokenList.stamp();
                try {
                    unaryExp = new IdentWithFuncRParams(tokenList);
                    tokenList.commit();
                    tokenList.commit();
                    return;
                } catch(NotCorrespondingClassException e_) { tokenList.rollback(); }
                try {
                    unaryExp = new PrimaryExp(tokenList);
                    tokenList.commit();
                    tokenList.commit();
                } catch(NotCorrespondingClassException e) { throw new NotCorrespondingClassException("UnaryExp: Not Match."); }
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public interface UnaryExpUnit {}

        public enum UnaryOp {
            // UnaryOp -> '+' | '-' | '!'
            POS, NEG, NOT;

            @Override
            public String toString() {
                return (this.equals(POS) ? "PLUS +" : this.equals(NEG) ? "MINU -" : "NOT !") + "\n<UnaryOp>\n";
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (UnaryOp op : unaryOps) sb.append(op + "");
            sb.append(unaryExp + "<UnaryExp>\n");
            for (int i = 1; i <= unaryOps.size(); i++) sb.append("<UnaryExp>\n");
            return sb.toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (unaryExp instanceof PrimaryExp) ((PrimaryExp)unaryExp).toSymbolTable(symbolTable);
            else if (unaryExp instanceof IdentWithFuncRParams) ((IdentWithFuncRParams)unaryExp).toSymbolTable(symbolTable);
        }

        public class IdentWithFuncRParams implements UnaryExpUnit {
            // Ident '(' [FuncRParams] ')'
            public Ident ident;
            public FuncRParams funcRParams;

            public IdentWithFuncRParams(TokenList tokenList) throws NotCorrespondingClassException {
                tokenList.stamp();
                try {
                    Token token = tokenList.consume(Token.Type.IDENFR);
                    if (token == null) throw new NotCorrespondingClassException("UnaryExp: No 'Ident'");
                    ident = new Ident(token);
                    if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("UnaryExp: No '('");
                    funcRParams = new FuncRParams(tokenList);
                    if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                    tokenList.commit();
                } catch(NotCorrespondingClassException e) {
                    tokenList.rollback();
                    tokenList.commit();
                    throw new NotCorrespondingClassException("UnaryExp: not match");
                }
            }

            @Override
            public String toString() { return ident + "LPARENT (\n" + (funcRParams.exps == null ? "" : funcRParams + "") + "RPARENT )\n"; }

            public void toSymbolTable(SymbolTable symbolTable) {
                try {
                    symbolTable.getSymbolType(ident.token);
                    FuncSymbolTable func = AST.mainSymbolTable.funcs.get((String)ident.token.getValue());
                    funcRParams.toSymbolTable(symbolTable);
                    if (func.params.size() != funcRParams.size())
                        Driver.errorRecord.addError(ident.token.line, "d");
                    else
                        for (int i = 0; i < func.params.size(); i++) {
                            SymbolType paramType = func.params.get(i).second();
                            UnaryExpUnit unaryExp = funcRParams.exps.get(i).addExp.mulExps.get(0).second().unaryExps.get(0).second().unaryExp;
                            SymbolType RparamType = null;
                            if (unaryExp instanceof PrimaryExp) {
                                if (((PrimaryExp)unaryExp).primaryExpUnit instanceof Number) RparamType = SymbolType.Int;
                                else if (((PrimaryExp)unaryExp).primaryExpUnit instanceof Character) RparamType = SymbolType.Char;
                                else if (((PrimaryExp)unaryExp).primaryExpUnit instanceof LVal)
                                    try {
                                        RparamType = symbolTable.getSymbolType(((LVal)((PrimaryExp)unaryExp).primaryExpUnit).ident.token);
                                        if (!((LVal)((PrimaryExp)unaryExp).primaryExpUnit).exps.isEmpty())
                                            RparamType = SymbolType.Int;
                                    } catch (SymbolTable.SymbolNotFoundException e) { continue; }
                                else continue;
                            } else continue;
                            if (paramType.isArray() != RparamType.isArray()) Driver.errorRecord.addError(ident.token.line, "e");
                            else if (paramType.isArray() && (paramType.isCharArray() != RparamType.isCharArray())) Driver.errorRecord.addError(ident.token.line, "e");
                        }
                } catch (SymbolTable.SymbolNotFoundException as ) { Driver.errorRecord.addError(ident.token.line, "c"); }
            }
        }
    }

    public class PrimaryExp implements UnaryExp.UnaryExpUnit {
        // PrimaryExp -> '(' Exp ')' | LVal | Number | Character
        public PrimaryExpUnit primaryExpUnit;

        public PrimaryExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                primaryExpUnit = new Number(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException __) { tokenList.rollback(); }
            try {
                primaryExpUnit = new Character(tokenList);
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException __) { tokenList.rollback(); }
            try {
                if (tokenList.consume(Token.Type.LPARENT) == null) throw new NotCorrespondingClassException("PrimaryExp: No '(' Found");
                primaryExpUnit = new Exp(tokenList);
                if (tokenList.consume(Token.Type.RPARENT) == null) Driver.errorRecord.addError(tokenList.previousToken().line, "j");
                tokenList.commit();
                return;
            } catch(NotCorrespondingClassException e) { tokenList.rollback(); }
            try {
                primaryExpUnit = new LVal(tokenList);
                tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw new NotCorrespondingClassException("PrimaryExp: not match");
            }
        }

        public interface PrimaryExpUnit {}

        @Override
        public String toString() { return ((primaryExpUnit instanceof Exp) ? ("LPARENT (\n" + primaryExpUnit + "RPARENT )\n") : primaryExpUnit) + "<PrimaryExp>\n"; }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (primaryExpUnit instanceof Exp) ((Exp)primaryExpUnit).toSymbolTable(symbolTable);
            else if (primaryExpUnit instanceof LVal) ((LVal)primaryExpUnit).toSymbolTable(symbolTable);
        }
    }

    public class Number implements PrimaryExp.PrimaryExpUnit {
        // Number -> IntConst
        public long value;

        public Number(TokenList tokenList) throws NotCorrespondingClassException {
            Token token = tokenList.consume(Token.Type.INTCON);
            if (token == null) throw new NotCorrespondingClassException("Number: No 'INTCON' Found");
            value = (long)token.getValue();
        }

        @Override
        public String toString() { return "INTCON " + value + "\n<Number>\n"; }
    }

    public class Character implements PrimaryExp.PrimaryExpUnit {
        // Character -> CharConst
        public String value;

        public Character(TokenList tokenList) throws NotCorrespondingClassException {
            Token token = tokenList.consume(Token.Type.CHRCON);
            if (token == null) throw new NotCorrespondingClassException("Character: No 'CHRCON' Found");
            value = (String)token.getValue();
        }

        @Override
        public String toString() { return "CHRCON " + value + "\n<Character>\n"; }
    }

    public class StringConst implements ConstInitVal.ConstInitValUnit, InitVal.InitValUnit {
        // StringConst -> String
        public String value;

        public StringConst(TokenList tokenList) throws NotCorrespondingClassException {
            Token token = tokenList.consume(Token.Type.STRCON);
            if (token == null) throw new NotCorrespondingClassException("StringConst: No 'STRCON' Found");
            value = (String)token.getValue();
        }

        @Override
        public String toString() { return "STRCON " + value + "\n"; }
    }

    public class FuncRParams {
        // FuncRParams -> Exp { ',' Exp }
        public ArrayList<Exp> exps = new ArrayList<>();

        public FuncRParams(TokenList tokenList) {
            tokenList.stamp();
            try {
                exps.add(new Exp(tokenList));
                while (true) {
                    Token token = tokenList.consume(Token.Type.COMMA);
                    if (token == null) break;
                    exps.add(new Exp(tokenList));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                this.exps = null;
            }
        }

        public int size() {
            if (this.exps == null) return 0;
            return this.exps.size();
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(exps.get(0) + "");
            for (int i = 1; i < exps.size(); i++) sb.append("COMMA ,\n" + exps.get(i));
            return sb.append("<FuncRParams>\n").toString();
        }

        public void toSymbolTable(SymbolTable symbolTable) {
            if (exps == null) return;
            for (Exp exp: exps)
                exp.toSymbolTable(symbolTable);
        }
    }

    public class LOrExp {
        // LOrExp -> LAndExp | LOrExp '||' LAndExp
        public ArrayList<Pair<LOrExpOpType, LAndExp>> lAndExps = new ArrayList<>();

        public LOrExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                lAndExps.add(new Pair<>(null, new LAndExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.OR);
                    if (token == null) break;
                    LOrExpOpType op = LOrExpOpType.OR;
                    LAndExp lAndExp = new LAndExp(tokenList);
                    lAndExps.add(new Pair<>(op, lAndExp));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public enum LOrExpOpType {
            OR;

            @Override
            public String toString() { return "OR ||"; }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(lAndExps.get(0).second() + "");
            for (int i = 1; i < lAndExps.size(); i++) sb.append("<LOrExp>\n" + lAndExps.get(i).first() + "\n" + lAndExps.get(i).second());
            return sb.append("<LOrExp>\n").toString();
        }
    }

    public class LAndExp {
        // LAndExp -> EqExp | LAndExp '&&' EqExp
        public ArrayList<Pair<LAndExpOpType, EqExp>> eqExps = new ArrayList<>();

        public LAndExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                eqExps.add(new Pair<>(null, new EqExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.AND);
                    if (token == null) break;
                    LAndExpOpType op = LAndExpOpType.AND;
                    EqExp eqExp = new EqExp(tokenList);
                    eqExps.add(new Pair<>(op, eqExp));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public enum LAndExpOpType {
            AND;

            @Override
            public String toString() { return "AND &&"; }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(eqExps.get(0).second() + "");
            for (int i = 1; i < eqExps.size(); i++) sb.append("<LAndExp>\n" + eqExps.get(i).first() + "\n" + eqExps.get(i).second());
            return sb.append("<LAndExp>\n").toString();
        }
    }

    public class EqExp {
        // EqExp -> RelExp | EqExp ('==' | '!=') RelExp
        public ArrayList<Pair<EqOpType, RelExp>> relExps = new ArrayList<>();

        public EqExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                relExps.add(new Pair<>(null, new RelExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.EQL, Token.Type.NEQ);
                    if (token == null) break;
                    EqOpType op = token.getType().equals(Token.Type.EQL) ? EqOpType.EQ : EqOpType.NE;
                    relExps.add(new Pair<>(op, new RelExp(tokenList)));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public enum EqOpType {
            EQ, NE;

            @Override
            public String toString() { return this.equals(EQ) ? "EQL ==" : "NEQ !="; }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(relExps.get(0).second() + "");
            for (int i = 1; i < relExps.size(); i++) sb.append("<EqExp>\n" + relExps.get(i).first() + "\n" + relExps.get(i).second());
            return sb.append("<EqExp>\n").toString();
        }
    }

    public class RelExp {
        // RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        public ArrayList<Pair<RelOpType, AddExp>> addExps = new ArrayList<>();

        public RelExp(TokenList tokenList) throws NotCorrespondingClassException {
            tokenList.stamp();
            try {
                addExps.add(new Pair<>(null, new AddExp(tokenList)));
                while (true) {
                    Token token = tokenList.consume(Token.Type.LSS, Token.Type.LEQ, Token.Type.GRE, Token.Type.GEQ);
                    if (token == null) break;
                    RelOpType op = token.getType().equals(Token.Type.LSS) ? RelOpType.LT : token.getType().equals(Token.Type.LEQ) ? RelOpType.LE : token.getType().equals(Token.Type.GRE) ? RelOpType.GT : RelOpType.GE;
                    AddExp addExp = new AddExp(tokenList);
                    addExps.add(new Pair<>(op, addExp));
                } tokenList.commit();
            } catch(NotCorrespondingClassException e) {
                tokenList.rollback();
                tokenList.commit();
                throw e;
            }
        }

        public enum RelOpType {
            LT, GT, LE, GE;

            @Override
            public String toString() {
                return this.equals(LT) ? "LSS <" : this.equals(GT) ? "GRE >" : this.equals(LE) ? "LEQ <=" : "GEQ >=";
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder(addExps.get(0).second() + "");
            for (int i = 1; i < addExps.size(); i++) sb.append("<RelExp>\n" + addExps.get(i).first() + "\n" + addExps.get(i).second());
            return sb.append("<RelExp>\n").toString();
        }
    }

    private static class NotCorrespondingClassException extends Exception {
        public NotCorrespondingClassException(String message) { super(message); }
    }

    @Override
    public String toString() { return compUnit + ""; }

    public MainSymbolTable toSymbolTable() {
        AST.mainSymbolTable = new MainSymbolTable();
        compUnit.toSymbolTable(AST.mainSymbolTable);
        return AST.mainSymbolTable;
    }
}