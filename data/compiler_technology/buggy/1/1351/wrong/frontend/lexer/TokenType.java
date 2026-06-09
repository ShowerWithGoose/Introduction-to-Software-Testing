package frontend.lexer;

import frontend.DataType;

public enum TokenType {
    IDENFR(),
    INTCON(),
    STRCON(),
    CHRCON(),
    MAINTK(),
    CONSTTK(),
    INTTK(),
    CHARTK(),
    BREAKTK(),
    CONTINUETK(),
    IFTK(),
    ELSETK(),
    NOT(),
    AND(),
    OR(),
    FORTK(),
    GETINTTK(),
    GETCHARTK(),
    PRINTFTK(),
    RETURNTK(),
    PLUS(),
    MINU(),
    VOIDTK(),
    MULT(),
    DIV(),
    MOD(),
    LSS(),
    LEQ(),
    GRE(),
    GEQ(),
    EQL(),
    NEQ(),
    ASSIGN(),
    SEMICN(),
    COMMA(),
    LPARENT(),
    RPARENT(),
    LBRACK(),
    RBRACK(),
    LBRACE(),
    RBRACE(),
    ;
    public DataType downToDataType() {
        if (this == INTTK) {
            return DataType.INT;
        }
        if (this == VOIDTK) {
            return DataType.VOID;
        }
        if (this == CHARTK) {
            return DataType.CHAR;
        }
        return null;
    }
}
