package frontend.lexer;

import frontend.error.Error;
import frontend.error.ErrorList;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*完成了跳过注释、空格的总体功能，具体的内部移动由kernelLexer完成*/
public class TokenLexer {
    //private boolean stop;
    private ArrayList<Token> tokenList;
    //private ArrayList<Error> errorList;
    private KernelLexer kernelLexer;

    public TokenLexer(KernelLexer kernelLexer) {
        //stop = false;
        this.tokenList = new ArrayList<>();
        this.kernelLexer = kernelLexer;
        tokenize();
    }

    public ArrayList<Token> getTokenList() {
        return tokenList;
    }

    public void tokenize() {
        while (kernelLexer.endOfFile() == false) {
            while (skipSpace() || skipComment()) {
                if (kernelLexer.endOfFile()) {
                    return;
                }
                continue;
            }
            if (kernelLexer.endOfFile()) {
                return;
            }
            addToken();
        }
    }

    public boolean skipSpace() {
        boolean flag = false;
        /*
        if (kernelLexer.curLine() == 163) {
            System.out.println("111");
        }
        */
        while(kernelLexer.peekChar() == ' ' || kernelLexer.peekChar() == '\t'
        || kernelLexer.peekChar() == '\r' || kernelLexer.peekChar() == '\n') {
            //System.out.println("SKIP A SPACE");
            flag = true;
            kernelLexer.moveSteps(1);
            if (kernelLexer.endOfFile()) {
                break;
            }
        }
        return flag;
    }

    public boolean skipComment() {
        /*匹配’//‘*/
        Pattern pat1 = Pattern.compile("^//");
        Matcher matcher1 = pat1.matcher(kernelLexer.curLineStr_remain());
        if (matcher1.find()) {
            kernelLexer.moveToNextLine();
            return true;
        }
        /*匹配多行注释，需要注意多行处理*/
        Pattern pat2 = Pattern.compile("^/\\*");
        Pattern pat3 = Pattern.compile("\\*/");
        Matcher matcher2 = pat2.matcher(kernelLexer.curLineStr_remain());
        if (matcher2.find()) {
            //int start = matcher2.start();
            kernelLexer.moveSteps(2);//跳过‘/*’
            //System.out.println(kernelLexer.curLineStr_remain());
            while (true) {
                Matcher matcher3 = pat3.matcher(kernelLexer.curLineStr_remain());
                if (matcher3.find()) {
                    int end = matcher3.end();
                    //System.out.println("end:" + end);
                    kernelLexer.moveSteps(end);
                    break;
                } else {
                    //该行无’*/‘
                    kernelLexer.moveToNextLine();
                }
            }
            return true;
        }
        return false;
    }

    public String printTokenList() {
        String tokenListString = "";
        for (Token token: tokenList) {
            tokenListString += token.getType() + " " + token.getContent() + "\n";
        }
        return tokenListString;
    }

    public void addToken() {
        if (kernelLexer.endOfFile()) {
            return;
        }
        boolean canMatch = false;
        for (TokenType tokenType: TokenType.values()) {
            Pattern pattern = tokenType.getPattern();
            //得到pattern
            Token token = kernelLexer.tryMatch(pattern);
            //尝试匹配字符串--这一步给kernellexer
            if (token != null) {
                //不为空，则add token
                token.setType(tokenType);
                tokenList.add(token);
                canMatch = true;
                //System.out.println(token.getContent() + " " + token.getType() + " " + token.getLineNum());
                return;
            } else {
                continue;
            }
        }
        if (true) {
            //error
            // 假如到最后也没有匹配上，那么判断出错（？）
            //出错和正确需要一个变量来传递给main----errorList不为空

            Pattern errorPattern1 = Pattern.compile("^(?<!&)&(?!&)");
            Pattern errorPattern2 = Pattern.compile("^(?<!\\|)\\|(?!\\|)");
            Token token = kernelLexer.tryMatch(errorPattern1);
            if (token != null) {
                token.setType(TokenType.AND);
                tokenList.add(token);
            } else {
                token = kernelLexer.tryMatch(errorPattern2);
                if (token != null) {
                    token.setType(TokenType.OR);
                    tokenList.add(token);
                }
            }
            if (token != null) {
                Error error = new Error(token.getLineNum(), "a");
                ErrorList.addErrorList(error);
                //errorList.add(error);
            }
        }
    }
}
