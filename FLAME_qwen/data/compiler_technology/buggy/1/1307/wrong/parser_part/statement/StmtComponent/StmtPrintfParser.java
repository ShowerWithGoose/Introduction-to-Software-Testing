package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.FormatString;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class StmtPrintfParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private int formatCnt;
    private ArrayList<Exp> exps;

    public StmtPrintfParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        formatCnt = 0;
        exps = new ArrayList<>();
    }

    public StmtPrintf parseStmtPrintf() {
        Token printf = tokenList.getNextToken();
        Token leftParent = tokenList.getNextToken();
        FormatString formatString = new FormatString(tokenList.getNextToken());
        //check a error
        //checkFormatString(formatString);
        ArrayList<Token> commas = new ArrayList<>();
        Token token = tokenList.getNextToken();
        while (token.getType() == Token.TokenType.COMMA) {
            commas.add(token);
            ExpParser expParser = new ExpParser(tokenList, symbolList);
            exps.add(expParser.parseExp());
            token = tokenList.getNextToken();
        }
        Token rightParent = token;
        //check j error
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
        }
        checkExpCnt(formatString, printf);
        Token semicn = tokenList.getNextToken();
        //check j error
        if (semicn.getType() != Token.TokenType.SEMICN) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new StmtPrintf(printf, leftParent, formatString, commas, exps, rightParent, semicn);
    }

    //check a error
    public void checkFormatString(FormatString formatString) {
        String s = formatString.getContent();
        int len = s.length();
        s = s.substring(1, len - 1);
        boolean hasError = false;
        len = s.length();
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            if (ch != 32 && ch != 33 && !(ch >= 40 && ch <= 126)) {
                if (ch == '%') {
                    if (i == len - 1) {
                        hasError = true;
                        break;
                    } else if (s.charAt(i + 1) != 'd' && s.charAt(i + 1) != 'c') {
                        hasError = true;
                        break;
                    } else {
                        continue;
                    }
                }
                hasError = true;
                break;
            }
            if (ch == '\\') {
                if (i == len - 1) {
                    hasError = true;
                    break;
                } else if (s.charAt(i + 1) != 'n') {
                    hasError = true;
                    break;
                }
            }
        }
//        if (hasError) {
//            ErrorList.addError(new Error(formatString.getLineIndex(), Error.ErrorType.ILLEGAL_SYMBOL));
//        }
    }

    public void checkExpCnt(FormatString formatString, Token printf) {
        String format1 = "%d";
        //String format2 = "%f";
        String format3 = "%c";
        int expCnt = exps.size();
        int formatCnt = (formatString.getContent().length() -
                formatString.getContent().replace(format1, "")
                        //.replace(format2, "")
                        .replace(format3,"").length()) / 2;
        if (expCnt != formatCnt) {
            ErrorList.addError(new Error(printf.getLineIndex(), Error.ErrorType.PRINTF_LACK_EXP));
        }
    }
}
