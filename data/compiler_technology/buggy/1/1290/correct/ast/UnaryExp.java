package ast;

import error.ParserError;
import error.SemanticError;
import lexical.LexerMark;
import lexical.TokenType;
import semantic.*;

import java.util.ArrayList;

public class UnaryExp extends Symbol {

    private DecType type;

    private IdType idType;

    public static Symbol of(SymbolTable table) {
        UnaryExp unaryExp = new UnaryExp();
        Symbol symbol;
        if (token.getType().equals(TokenType.IDENFR)) {
            LexerMark mark = lexer.mark();
            token = lexer.nextToken();
            if (token.getType().equals(TokenType.LPARENT)) {
                lexer.back(mark);
                token = lexer.getToken();
                unaryExp.idType = IdType.Var;
                unaryExp.type = DecType.Void;
                if ((symbol = Ident.of()) != null) {
                    String ident = ((Ident) symbol).getIdent();
                    int line = symbol.getLine();
                    Info info;
                    if ((info = table.getInfo(ident)) == null) {
                        logger.log(new SemanticError(line, "c"));
                    }
                    unaryExp.add(symbol);
                    if (!token.getType().equals(TokenType.LPARENT)) {
                        return null;
                    }
                    unaryExp.add(token);
                    token = lexer.nextToken();
                    int r = 0;
                    ArrayList<DecType> list = new ArrayList<>();
                    ArrayList<IdType> list1 = new ArrayList<>();
                    if ((symbol = FuncRParams.of(table)) != null) {
                        unaryExp.add(symbol);
                        line = symbol.getLine();
                        r = ((FuncRParams) symbol).getParams().size();
                        list = ((FuncRParams) symbol).getParams();
                        list1 = ((FuncRParams) symbol).getParamsId();
                    }
                    if (info instanceof FuncInfo) {
                        FuncInfo funcInfo = (FuncInfo) info;
                        if (funcInfo instanceof IntFuncInfo) {
                            unaryExp.type = DecType.Int;
                        } else if (funcInfo instanceof CharFuncInfo) {
                            unaryExp.type = DecType.Char;
                        }
                        if (r == funcInfo.getParamsNum()) {
                            if (r != 0) {
                                ArrayList<Info> infos = funcInfo.getParamsList();
                                for (int i = 0; i < infos.size(); i++) {
                                    DecType decType = list.get(i);
                                    IdType idType = list1.get(i);
                                    Info info1 = infos.get(i);
                                    if (info1 instanceof VarCharArrayInfo) {
                                        if (idType.equals(IdType.Var)) {
                                            logger.log(new SemanticError(line, "e"));
                                        } else if (decType.equals(DecType.Int)) {
                                            logger.log(new SemanticError(line, "e"));
                                        }
                                    } else if (info1 instanceof VarIntArrayInfo) {
                                        if (idType.equals(IdType.Var)) {
                                            logger.log(new SemanticError(line, "e"));
                                        } else if (decType.equals(DecType.Char)) {
                                            logger.log(new SemanticError(line, "e"));
                                        }
                                    } else {
                                        if (idType.equals(IdType.Array)) {
                                            logger.log(new SemanticError(line, "e"));
                                        }
                                    }
                                }
                            }
                        } else {
                            logger.log(new SemanticError(line, "d"));
                        }
                    }
                    if (!token.getType().equals(TokenType.RPARENT)) {
                        logger.log(new ParserError(line, "j"));
                        return unaryExp;
                    }
                    unaryExp.add(token);
                    token = lexer.nextToken();
                    return unaryExp;
                }
                return null;
            }
            lexer.back(mark);
            token = lexer.getToken();

        }


        if ((symbol = PrimaryExp.of(table)) != null) {
            unaryExp.add(symbol);
            unaryExp.type = ((PrimaryExp) symbol).getType();
            unaryExp.idType = ((PrimaryExp) symbol).getIdType();
            return unaryExp;
        }

        if ((symbol = UnaryOp.of()) != null) {
            unaryExp.add(symbol);
            if ((symbol = UnaryExp.of(table)) == null) {
                return null;
            }
            unaryExp.add(symbol);
            unaryExp.type = ((UnaryExp) symbol).getType();
            unaryExp.idType = ((UnaryExp) symbol).getIdType();
            return unaryExp;
        }
        return null;
    }

    protected DecType getType() {
        return type;
    }

    protected IdType getIdType() {
        return idType;
    }
}
