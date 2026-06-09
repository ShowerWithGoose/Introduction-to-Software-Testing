package front.lexer;

/**
 * token 种类枚举类
 */
public enum TokenType {
    IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
    ELSETK, NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU,
    VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    /**
     * 额外的 token 类型，用于在语法分析时代表空串
     */
    EPSILON;

//    /**
//     * 判断 token 种类是否为 IDENFR
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 IDENFR
//     */
//    static public boolean isIDENFR(Token token) {
//        return token.getTokenType() == IDENFR;
//    }
//
//    /**
//     * 判断 token 种类是否为 INTCON
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 INTCON
//     */
//    static public boolean isINTCON(Token token) {
//        return token.getTokenType() == INTCON;
//    }
//
//    /**
//     * 判断 token 种类是否为 STRCON
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 STRCON
//     */
//    static public boolean isSTRCON(Token token) {
//        return token.getTokenType() == STRCON;
//    }
//
//    /**
//     * 判断 token 种类是否为 CHRCON
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 CHRCON
//     */
//    static public boolean isCHRCON(Token token) {
//        return token.getTokenType() == CHRCON;
//    }
//
//    /**
//     * 判断 token 种类是否为 MAINTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 MAINTK
//     */
//    static public boolean isMAINTK(Token token) {
//        return token.getTokenType() == MAINTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 CONSTTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 CONSTTK
//     */
//    static public boolean isCONSTTK(Token token) {
//        return token.getTokenType() == CONSTTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 INTTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 INTTK
//     */
//    static public boolean isINTTK(Token token) {
//        return token.getTokenType() == INTTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 CHARTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 CHARTK
//     */
//    static public boolean isCHARTK(Token token) {
//        return token.getTokenType() == CHARTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 BREAKTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 BREAKTK
//     */
//    static public boolean isBREAKTK(Token token) {
//        return token.getTokenType() == BREAKTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 CONTINUETK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 CONTINUETK
//     */
//    static public boolean isCONTINUETK(Token token) {
//        return token.getTokenType() == CONTINUETK;
//    }
//
//    /**
//     * 判断 token 种类是否为 IFTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 IFTK
//     */
//    static public boolean isIFTK(Token token) {
//        return token.getTokenType() == IFTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 ELSETK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 ELSETK
//     */
//    static public boolean isELSETK(Token token) {
//        return token.getTokenType() == ELSETK;
//    }
//
//    /**
//     * 判断 token 种类是否为 NOT
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 NOT
//     */
//    static public boolean isNOT(Token token) {
//        return token.getTokenType() == NOT;
//    }
//
//    /**
//     * 判断 token 种类是否为 AND
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 AND
//     */
//    static public boolean isAND(Token token) {
//        return token.getTokenType() == AND;
//    }
//
//    /**
//     * 判断 token 种类是否为 OR
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 OR
//     */
//    static public boolean isOR(Token token) {
//        return token.getTokenType() == OR;
//    }
//
//    /**
//     * 判断 token 种类是否为 FORTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 FORTK
//     */
//    static public boolean isFORTK(Token token) {
//        return token.getTokenType() == FORTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 GETINTTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 GETINTTK
//     */
//    static public boolean isGETINTTK(Token token) {
//        return token.getTokenType() == GETINTTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 GETCHARTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 GETCHARTK
//     */
//    static public boolean isGETCHARTK(Token token) {
//        return token.getTokenType() == GETCHARTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 PRINTFTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 PRINTFTK
//     */
//    static public boolean isPRINTFTK(Token token) {
//        return token.getTokenType() == PRINTFTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 RETURNTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 RETURNTK
//     */
//    static public boolean isRETURNTK(Token token) {
//        return token.getTokenType() == RETURNTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 PLUS
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 PLUS
//     */
//    static public boolean isPLUS(Token token) {
//        return token.getTokenType() == PLUS;
//    }
//
//    /**
//     * 判断 token 种类是否为 MINU
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 MINU
//     */
//    static public boolean isMINU(Token token) {
//        return token.getTokenType() == MINU;
//    }
//
//    /**
//     * 判断 token 种类是否为 VOIDTK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 VOIDTK
//     */
//    static public boolean isVOIDTK(Token token) {
//        return token.getTokenType() == VOIDTK;
//    }
//
//    /**
//     * 判断 token 种类是否为 MULT
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 MULT
//     */
//    static public boolean isMULT(Token token) {
//        return token.getTokenType() == MULT;
//    }
//
//    /**
//     * 判断 token 种类是否为 DIV
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 DIV
//     */
//    static public boolean isDIV(Token token) {
//        return token.getTokenType() == DIV;
//    }
//
//    /**
//     * 判断 token 种类是否为 MOD
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 MOD
//     */
//    static public boolean isMOD(Token token) {
//        return token.getTokenType() == MOD;
//    }
//
//    /**
//     * 判断 token 种类是否为 LSS
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 LSS
//     */
//    static public boolean isLSS(Token token) {
//        return token.getTokenType() == LSS;
//    }
//
//    /**
//     * 判断 token 种类是否为 LEQ
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 LEQ
//     */
//    static public boolean isLEQ(Token token) {
//        return token.getTokenType() == LEQ;
//    }
//
//    /**
//     * 判断 token 种类是否为 GRE
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 GRE
//     */
//    static public boolean isGRE(Token token) {
//        return token.getTokenType() == GRE;
//    }
//
//    /**
//     * 判断 token 种类是否为 GEQ
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 GEQ
//     */
//    static public boolean isGEQ(Token token) {
//        return token.getTokenType() == GEQ;
//    }
//
//    /**
//     * 判断 token 种类是否为 EQL
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 EQL
//     */
//    static public boolean isEQL(Token token) {
//        return token.getTokenType() == EQL;
//    }
//
//    /**
//     * 判断 token 种类是否为 NEQ
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 NEQ
//     */
//    static public boolean isNEQ(Token token) {
//        return token.getTokenType() == NEQ;
//    }
//
//    /**
//     * 判断 token 种类是否为 ASSIGN
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 ASSIGN
//     */
//    static public boolean isASSIGN(Token token) {
//        return token.getTokenType() == ASSIGN;
//    }
//
//    /**
//     * 判断 token 种类是否为 SEMICN
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 SEMICN
//     */
//    static public boolean isSEMICN(Token token) {
//        return token.getTokenType() == SEMICN;
//    }
//
//    /**
//     * 判断 token 种类是否为 COMMA
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 COMMA
//     */
//    static public boolean isCOMMA(Token token) {
//        return token.getTokenType() == COMMA;
//    }
//
//    /**
//     * 判断 token 种类是否为 LPARENT
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 LPARENT
//     */
//    static public boolean isLPARENT(Token token) {
//        return token.getTokenType() == LPARENT;
//    }
//
//    /**
//     * 判断 token 种类是否为 RPARENT
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 RPARENT
//     */
//    static public boolean isRPARENT(Token token) {
//        return token.getTokenType() == RPARENT;
//    }
//
//    /**
//     * 判断 token 种类是否为 LBRACK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 LBRACK
//     */
//    static public boolean isLBRACK(Token token) {
//        return token.getTokenType() == LBRACK;
//    }
//
//    /**
//     * 判断 token 种类是否为 RBRACK
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 RBRACK
//     */
//    static public boolean isRBRACK(Token token) {
//        return token.getTokenType() == RBRACK;
//    }
//
//    /**
//     * 判断 token 种类是否为 LBRACE
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 LBRACE
//     */
//    static public boolean isLBRACE(Token token) {
//        return token.getTokenType() == LBRACE;
//    }
//
//    /**
//     * 判断 token 种类是否为 RBRACE
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 RBRACE
//     */
//    static public boolean isRBRACE(Token token) {
//        return token.getTokenType() == RBRACE;
//    }
//
//    /**
//     * 判断 token 种类是否为 EPSILON
//     *
//     * @param token 需要判断的 token
//     * @return 种类是否为 EPSILON
//     */
//    static public boolean isEPSILON(Token token) {
//        return token.getTokenType() == EPSILON;
//    }
}
