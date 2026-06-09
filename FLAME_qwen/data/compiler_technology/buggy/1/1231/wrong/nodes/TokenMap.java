package nodes;

import java.util.EnumMap;
import java.util.HashMap;
import java.util.Map;

public class TokenMap {
    // 枚举到字符串的映射
    private static final EnumMap<TokenType, String> enumToStringMap = new EnumMap<>(TokenType.class);
    // 字符串到枚举的映射
    private static final HashMap<String, TokenType> stringToEnumMap = new HashMap<>();

    static {

        // enumToStringMap.put(TokenType.IDENFR, "Ident");
        // enumToStringMap.put(TokenType.INTCON, "IntConst");
        // enumToStringMap.put(TokenType.STRCON, "StringConst");
        // enumToStringMap.put(TokenType.CHRCON, "CharConst");

        enumToStringMap.put(TokenType.MAINTK, "main");
        enumToStringMap.put(TokenType.CONSTTK, "const");
        enumToStringMap.put(TokenType.INTTK, "int");
        enumToStringMap.put(TokenType.CHARTK, "char");
        enumToStringMap.put(TokenType.BREAKTK, "break");
        enumToStringMap.put(TokenType.CONTINUETK, "continue");

        enumToStringMap.put(TokenType.IFTK, "if");
        enumToStringMap.put(TokenType.ELSETK, "else");
        enumToStringMap.put(TokenType.NOT, "!");
        enumToStringMap.put(TokenType.AND, "&&");
        enumToStringMap.put(TokenType.OR, "||");

        enumToStringMap.put(TokenType.FORTK, "for");
        enumToStringMap.put(TokenType.GETINTTK, "getint");
        enumToStringMap.put(TokenType.GETCHARTK, "getchar");
        enumToStringMap.put(TokenType.PRINTFTK, "printf");
        enumToStringMap.put(TokenType.RETURNTK, "return");

        enumToStringMap.put(TokenType.PLUS, "+");
        enumToStringMap.put(TokenType.MINU, "-");
        enumToStringMap.put(TokenType.VOIDTK, "void");
        enumToStringMap.put(TokenType.MULT, "*");
        enumToStringMap.put(TokenType.DIV, "/");
        enumToStringMap.put(TokenType.MOD, "%");

        enumToStringMap.put(TokenType.LSS, "<");
        enumToStringMap.put(TokenType.LEQ, "<=");
        enumToStringMap.put(TokenType.GRE, ">");
        enumToStringMap.put(TokenType.GEQ, ">=");
        enumToStringMap.put(TokenType.EQL, "==");
        enumToStringMap.put(TokenType.NEQ, "!=");
        enumToStringMap.put(TokenType.ASSIGN, "=");

        enumToStringMap.put(TokenType.SEMICN, ";");
        enumToStringMap.put(TokenType.COMMA, ",");
        enumToStringMap.put(TokenType.LPARENT, "(");
        enumToStringMap.put(TokenType.RPARENT, ")");
        enumToStringMap.put(TokenType.LBRACK, "[");
        enumToStringMap.put(TokenType.RBRACK, "]");
        enumToStringMap.put(TokenType.LBRACE, "{");
        enumToStringMap.put(TokenType.RBRACE, "}");

        enumToStringMap.put(TokenType.UNDEFINE, "undefined");

        // 初始化字符串到枚举的映射
        for (Map.Entry<TokenType, String> entry : enumToStringMap.entrySet()) {
            stringToEnumMap.put(entry.getValue(), entry.getKey());
        }
    }

    public static String getTokenString(TokenType tokenType) {
        return enumToStringMap.get(tokenType);
    }

    public static TokenType getTokenType(String tokenString) {
        TokenType tokenType = stringToEnumMap.get(tokenString);
        if (tokenType == null) {
            return TokenType.IDENFR;
        } else {
            return tokenType;
        }
    }
}