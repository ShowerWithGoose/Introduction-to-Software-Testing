package common;
import frontend.Token;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ParseTree {
    public final SyntaxElem syntaxElem;
    public final Token token;
    private final ArrayList<ParseTree> children = new ArrayList<>();

    public ParseTree(SyntaxElem syntaxElem) {
        assert (syntaxElem != SyntaxElem.Terminal);
        this.syntaxElem = syntaxElem;
        this.token = null;
    }

    public ParseTree(SyntaxElem syntaxElem, Token terminalTk) {
        assert (syntaxElem == SyntaxElem.Terminal);
        this.syntaxElem = syntaxElem;
        this.token = terminalTk;
    }

    public void addChild(ParseTree child) {
        children.add(child);
    }

    public List<ParseTree> preOrderTraversal() {
        List<ParseTree> res = new LinkedList<>();
        for (ParseTree child: children) {
            res.addAll(child.preOrderTraversal());
        }
        res.add(this);
        return res;
    }

    public String printNode() {
        if (syntaxElem == SyntaxElem.Terminal) {
            assert token != null;
            return token.toString();
        } else {
            return "<" + syntaxElem + ">";
        }
    }

    public void debugPrint(String prefix, boolean isTail) {
        System.out.print(prefix + (isTail ? "└── " : "├── ") + printNode() + "\n");
        for (int i = 0; i < children.size() - 1; i++) {
            children.get(i).debugPrint(prefix + (isTail ? "    " : "│   "), false);
        }
        if (children.size() > 0) {
            children.get(children.size() - 1).debugPrint(prefix + (isTail ? "    " : "│   "), true);
        }
    }
}
