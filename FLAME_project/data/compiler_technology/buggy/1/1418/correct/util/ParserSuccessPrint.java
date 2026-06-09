package util;

import model.SyntaxTreeNode;

public class ParserSuccessPrint {
    public void run(SyntaxTreeNode root, StringBuilder sb, ParserSuccessPrint psp) {
        if(root.getName().equals("leaf")) {
            sb.append(root.getToken().getType()).append(" ").append(root.getToken().getName()).append("\n");
        }
        else {
            for(SyntaxTreeNode child: root.getChildren()) {
                psp.run(child, sb, psp);
            }
            if(!root.getName().equals("<BlockItem>") && !root.getName().equals("<Decl>") && !root.getName().equals("<BType>")) {
                sb.append(root.getName()).append("\n");
            }
        }
    }
}
