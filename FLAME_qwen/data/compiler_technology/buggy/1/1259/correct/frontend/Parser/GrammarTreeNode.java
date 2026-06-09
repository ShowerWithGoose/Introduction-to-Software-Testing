package frontend.Parser;

import frontend.IOManager;
import frontend.Lexer.Token;
import frontend.Utils;
import frontend.Visitor.Visitor;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class GrammarTreeNode
{
    //data
    private GrammarWord grammarWord;

    private GrammarTreeNode parent = null;
    private List<GrammarTreeNode> children = null;

    public GrammarTreeNode(GrammarWord word, boolean isNonterminal) {
        grammarWord = word;
        if (isNonterminal) {
            children = new ArrayList<>();
        }
    }

    public static void LinkChild(GrammarTreeNode parent, GrammarTreeNode child) {
        parent.children.add(child);
        child.parent = parent;
    }

//    public static void ReplaceChild(GrammarTreeNode parent, int childBeforeIndex, GrammarTreeNode childAfter) {
//        GrammarTreeNode childBefore = parent.children.get(childBeforeIndex);
//        parent.children.remove(childBefore);
//        List<GrammarTreeNode> newChildren = new ArrayList<>();
//        newChildren.add(childAfter);
//        newChildren.addAll(parent.children);
//        parent.children = newChildren;
//    }
    public static void ResetChildren(GrammarTreeNode oriParent, GrammarTreeNode newParent) {
        newParent.children = oriParent.children;
        for(GrammarTreeNode child : newParent.children) {
            child.parent = newParent;
        }
        oriParent.children = new ArrayList<>();
    }

    public static void PrintFromRoot(GrammarTreeNode root) throws IOException {
        DFS(root);
    }

    public static void Visit(GrammarTreeNode node, int choice) {
        switch (choice) {
            case 1 -> {
                PrintVisit(node);
            }
        }

    }

    private static void PrintVisit(GrammarTreeNode node) {
        if (node.grammarWord instanceof Token token) {
            //终结符
            IOManager.Write(token.toString(), true);
        }
        else if (node.grammarWord instanceof Nonterminal nonterminal) {
            if (Utils.IsNonterminalTypeIn(nonterminal, NonterminalType.BlockItem, NonterminalType.Decl, NonterminalType.BType)) {
                return;
            }
            IOManager.Write(nonterminal.toString(), true);
        }
    }

    public static void DFS(GrammarTreeNode node) {
        if (node.children == null) {
            Visit(node,1);
            return;
        }
        for (int i = 0; i < node.children.size(); i++) {
            GrammarTreeNode child = node.children.get(i);
            DFS(child);
        }
        Visit(node,1);
    }

    public GrammarWord getGrammarWord() {
        return grammarWord;
    }


    public GrammarTreeNode getParent() {
        return parent;
    }

    public List<GrammarTreeNode> getChildren() {
        return children;
    }

    public void ClearChildren() {
        if(children != null) {
            children.clear();
        }
    }

}
