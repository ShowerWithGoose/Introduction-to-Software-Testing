import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private MyFileReader reader;
    private List<Token> tokens;

    public Lexer(String filePath) {
        this.reader = new MyFileReader(filePath);
        this.tokens = new ArrayList<>();
    }


    public List<Token> lexer() {
        while (true) {
            Symbol symbol = Symbol.IGNORE;
            reader.clearToken();
            /* 清除无关空白符 */
            while (reader.isSpace() || reader.isNewlineN() || reader.isNewlineR() || reader.isTab()) {
                // 假设仅计 \n
                if (reader.isNewlineN()) {
                    reader.pushLine();
                }
                reader.getChar();
            }

            /* 枚举优先级：保留字 - 标识符 - 常整数 - 分界符 - 字符串 */
            // 保留字与标识符
            if (reader.isLetter()) {
                while (reader.isLetter() || reader.isDigit()) {
                    reader.catToken();
                    reader.getChar();
                }
                reader.retract();
                Symbol resultValue = reserve(reader.getToken().toString());
                if (resultValue == Symbol.UNKNOWN)
                    symbol = Symbol.IDENFR;
                else
                    symbol = resultValue;
            }
            // 常整数, 不允许前置零
            else if (reader.isDigit()) {
                while (reader.isDigit()) {
                    reader.catToken();
                    reader.getChar();
                }
                reader.retract();
                symbol = Symbol.INTCON;
//                // 非零整数
//                if (reader.isNZeroDigit()) {
//                    while (reader.isDigit()) {
//                        reader.catToken();
//                        reader.getChar();
//                    }
//                    reader.retract();
//                    symbol = Symbol.INTCON;
//                }
//                // 零
//                else {
//                    reader.catToken();
//                    reader.getChar();
//                    if (!reader.isDigit()) {
//                        reader.retract();
//                        symbol = Symbol.INTCON;
//                    } else
//                        Error.lexError(reader.getCurLine(), Symbol.INTCON);
//                }
            }
            // 字符串常量
            else if (reader.isDouQuotation()) {
                reader.catToken();
                reader.getChar();
                while (!reader.isDouQuotation()) {
                    reader.catToken();
                    reader.getChar();
                }
                if (reader.isDouQuotation()) {
                    reader.catToken();
                    symbol = Symbol.STRCON;
                }
            }
            // 字符常量
            else if (reader.isSinQuotation()) {
                reader.catToken();
                reader.getChar();
                if (reader.isEscape()) {
                    reader.catToken();
                    reader.getChar();
                }
                reader.catToken();
                reader.getChar();
                if (reader.isSinQuotation()) {
                    reader.catToken();
                    symbol = Symbol.CHRCON;
                }
            } else if (reader.isAnd()) {
                // &&
                reader.catToken();
                reader.getChar();
                if (reader.isAnd()) {
                    reader.catToken();
                    symbol = Symbol.AND;
                } else {
                    Error.lexErrorA(reader.getCurLine());
                }
            } else if (reader.isOr()) {
                // ||
                reader.catToken();
                reader.getChar();
                if (reader.isOr()) {
                    reader.catToken();
                    symbol = Symbol.OR;
                } else {
                    Error.lexErrorA(reader.getCurLine());
                }
            }
            // 双分界符
            else if (reader.isLss()) {
                // < <=
                reader.catToken();
                reader.getChar();
                if (reader.isEqu()) {
                    reader.catToken();
                    symbol = Symbol.LEQ;
                } else {
                    reader.retract();
                    symbol = Symbol.LSS;
                }
            } else if (reader.isGre()) {
                // > >=
                reader.catToken();
                reader.getChar();
                if (reader.isEqu()) {
                    reader.catToken();
                    symbol = Symbol.GEQ;
                } else {
                    reader.retract();
                    symbol = Symbol.GRE;
                }
            } else if (reader.isEqu()) {
                // = ==
                reader.catToken();
                reader.getChar();
                if (reader.isEqu()) {
                    reader.catToken();
                    symbol = Symbol.EQL;
                } else {
                    reader.retract();
                    symbol = Symbol.ASSIGN;
                }
            } else if (reader.isExclamation()) {
                // ! !=
                reader.catToken();
                reader.getChar();
                if (reader.isEqu()) {
                    reader.catToken();
                    symbol = Symbol.NEQ;
                } else {
                    reader.retract();
                    symbol = Symbol.NOT;
                }
            }
            /* 单分界符号 */
            else if (reader.isPlus()) {
                reader.catToken();
                symbol = Symbol.PLUS;
            } else if (reader.isMinus()) {
                reader.catToken();
                symbol = Symbol.MINU;
            } else if (reader.isMulti()) {
                reader.catToken();
                symbol = Symbol.MULT;
            } else if (reader.isDiv()) {
                reader.catToken();
                reader.getChar();
                // 进入单行注释
                if (reader.isDiv()) {
                    // 仅计 \n
                    while (!reader.isNewlineN()) {
                        reader.getChar();
                    }
                    reader.pushLine();   // 进行换行处理
                    symbol = Symbol.IGNORE;
                }
                // 进入多行注释
                else if (reader.isMulti()) {
                    reader.getChar();
                    while (true) {
                        while (!reader.isMulti()) {
                            // 仅计 \n
                            if (reader.isNewlineN()) {
                                reader.pushLine();
                            }
                            reader.getChar();
                        }
                        reader.getChar();
                        if (reader.isDiv()) {
                            break;
                        } else {
                            continue;
                        }
                    }
                    symbol = Symbol.IGNORE;
                    // 多行注释的最后一个换行符留到了下一次循环进行处理
                } else {
                    reader.retract();
                    symbol = Symbol.DIV;
                }
            } else if (reader.isMod()) {
                reader.catToken();
                symbol = Symbol.MOD;
            } else if (reader.isSemi()) {
                reader.catToken();
                symbol = Symbol.SEMICN;
            } else if (reader.isComma()) {
                reader.catToken();
                symbol = Symbol.COMMA;
            } else if (reader.isLeftParent()) {
                reader.catToken();
                symbol = Symbol.LPARENT;
            } else if (reader.isRightParent()) {
                reader.catToken();
                symbol = Symbol.RPARENT;
            } else if (reader.isLeftBracket()) {
                reader.catToken();
                symbol = Symbol.LBRACK;
            } else if (reader.isRightBracket()) {
                reader.catToken();
                symbol = Symbol.RBRACK;
            } else if (reader.isLeftBrace()) {
                reader.catToken();
                symbol = Symbol.LBRACE;
            } else if (reader.isRightBrace()) {
                reader.catToken();
                symbol = Symbol.RBRACE;
            } else if (reader.isEOT()) {
                break;
            }

            if (symbol != Symbol.IGNORE) {
                this.tokens.add(new Token(symbol, reader.getToken().toString(), reader.getCurLine()));
            }

            reader.getChar();
        }
        return this.tokens;
    }


    public Symbol reserve(String value) {
        if (value.equals("main")) return Symbol.MAINTK;
        else if (value.equals("const")) return Symbol.CONSTTK;
        else if (value.equals("int")) return Symbol.INTTK;
        else if (value.equals("char")) return Symbol.CHARTK;
        else if (value.equals("break")) return Symbol.BREAKTK;
        else if (value.equals("continue")) return Symbol.CONTINUETK;
        else if (value.equals("if")) return Symbol.IFTK;
        else if (value.equals("else")) return Symbol.ELSETK;
        else if (value.equals("for")) return Symbol.FORTK;
        else if (value.equals("getint")) return Symbol.GETINTTK;
        else if (value.equals("getchar")) return Symbol.GETCHARTK;
        else if (value.equals("printf")) return Symbol.PRINTFTK;
        else if (value.equals("return")) return Symbol.RETURNTK;
        else if (value.equals("void")) return Symbol.VOIDTK;
        else return Symbol.UNKNOWN;
    }
}