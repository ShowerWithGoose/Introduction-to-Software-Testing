package treeNode;

import frontend.LexType;
import frontend.Parser;
import error.ErrorType;
import java.io.BufferedWriter;
import java.io.IOException;

public class Stmt {
    public Stmt parse(Parser parser,BufferedWriter writer) throws IOException{

        if (parser.match(LexType.IFTK)) {
            // 匹配 if 语句
            writer.write("IFTK if\n");
            parser.match(LexType.LPARENT);
            writer.write("LPARENT (\n");
            new Cond().parse(parser,writer);
            writer.write("<Cond>\n");
            if (parser.match(LexType.RPARENT)) {
                writer.write("RPARENT )\n");
                new Stmt().parse(parser,writer);
                writer.write("<Stmt>\n");
                if (parser.match(LexType.ELSETK)) {
                    writer.write("ELSETK else\n");
                    new Stmt().parse(parser,writer);
                    writer.write("<Stmt>\n");
                }
            } else {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
            }
        } else if (parser.match(LexType.FORTK)) {
            // 匹配 for 语句
            writer.write("FORTK for\n");
            parser.match(LexType.LPARENT);
            writer.write("LPARENT (\n");
            if (!parser.match(LexType.SEMICN)) {
                new ForStmt().parse(parser,writer);
                writer.write("<ForStmt>\n");
                parser.match(LexType.SEMICN);
            }
            writer.write("SEMICN ;\n");
            if (!parser.match(LexType.SEMICN)){
                new Cond().parse(parser,writer);
                writer.write("<Cond>\n");
                parser.match(LexType.SEMICN);
            }
            writer.write("SEMICN ;\n");
            if (!parser.match(LexType.RPARENT)){
                new ForStmt().parse(parser,writer);
                writer.write("<ForStmt>\n");
                parser.match(LexType.RPARENT);
            }
            writer.write("RPARENT )\n");
            new Stmt().parse(parser,writer);
            writer.write("<Stmt>\n");
        } else if (parser.match(LexType.RETURNTK)) {
            writer.write("RETURNTK return\n");
            if (parser.getCurrentToken().type != LexType.SEMICN){
                new Exp().parse(parser,writer);
                writer.write("<Exp>\n");
            }
            if (!parser.match(LexType.SEMICN)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
            }else{
                writer.write("SEMICN ;\n");
            }
        } else if (parser.getCurrentToken().type == LexType.LBRACE) {
            new Block().parse(parser,writer);
            writer.write("<Block>\n");
        } else if (parser.match(LexType.BREAKTK) || parser.match(LexType.CONTINUETK)) {
            // 匹配 break 或 continue 语句
            writer.write(parser.tokens.get(parser.currentTokenIndex-1).type+" "+parser.tokens.get(parser.currentTokenIndex-1).word+"\n");
            if (!parser.match(LexType.SEMICN)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
            }else{
                writer.write("SEMICN ;\n");
            }
        } else if (parser.match(LexType.PRINTFTK)){
            writer.write("PRINTFTK printf\n");
            parser.match(LexType.LPARENT);
            writer.write("LPARENT (\n");
            writer.write("STRCON "+parser.getCurrentToken().word+"\n");
            parser.match(LexType.STRCON);
            while (parser.match(LexType.COMMA)) {
                writer.write("COMMA ,\n");
                new Exp().parse(parser,writer);
                writer.write("<Exp>\n");
            }
            if(!parser.match(LexType.RPARENT)){
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
            }else{
                writer.write("RPARENT )\n");
            }
            if(!parser.match(LexType.SEMICN)){
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
            }else{
                writer.write("SEMICN ;\n");
            }
        } else if (parser.currentLineHasToken(LexType.ASSIGN)){
            new LVal().parse(parser,writer);
            writer.write("<LVal>\n");
            parser.match(LexType.ASSIGN);
            writer.write("ASSIGN =\n");
            if(parser.getCurrentToken().type == LexType.GETINTTK){
                writer.write("GETINTTK getint\n");
                parser.match(LexType.GETINTTK);
                parser.match(LexType.LPARENT);
                writer.write("LPARENT (\n");
                if(!parser.match(LexType.RPARENT)){
                    parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
                }else{
                    writer.write("RPARENT )\n");
                }
                if(!parser.match(LexType.SEMICN)){
                    parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
                }else{
                    writer.write("SEMICN ;\n");
                }
            } else if (parser.getCurrentToken().type == LexType.GETCHARTK){
                writer.write("GETCHARTK getchar\n");
                parser.match(LexType.GETCHARTK);
                parser.match(LexType.LPARENT);
                writer.write("LPARENT (\n");
                if(!parser.match(LexType.RPARENT)){
                    parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
                }else{
                    writer.write("RPARENT )\n");
                }
                if(!parser.match(LexType.SEMICN)){
                    parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
                }else{
                    writer.write("SEMICN ;\n");
                }
            } else {
                new Exp().parse(parser,writer);
                writer.write("<Exp>\n");
                if(!parser.match(LexType.SEMICN)){
                    parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
                }else{
                    writer.write("SEMICN ;\n");
                }
            }
        } else {
            // 匹配表达式语句
            if(parser.getCurrentToken().type != LexType.SEMICN){
                new Exp().parse(parser,writer);
                writer.write("<Exp>\n");
            }
            if (!parser.match(LexType.SEMICN)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
            }else{
                writer.write("SEMICN ;\n");
            }
        }
        writer.flush();
        return this;
    }
}
