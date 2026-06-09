package frontend.parser;

import frontend.error.TokenError;
import frontend.parser.declaration.Decl;
import frontend.parser.function.FuncDef;
import frontend.parser.function.MainFuncDef;

import java.util.ArrayList;

// CompUnit -> {Decl} {FuncDef} MainFuncDef
// 三个部分的先后顺序确定
public class CompUnit extends Node {

    public CompUnit(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        // 最开始startLine和endLine还未知
        super(startLine, endLine, name, nodes);
    }


}
