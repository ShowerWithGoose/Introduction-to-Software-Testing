#include <vector>
#include "Parser.h"
#include <iostream>

#include "Error.h"
int parsingTime = 0;

void traverseLeaves(const std::shared_ptr<TreeNode>& node, std::ofstream& output) {
    if (!node) return;  // 如果节点为空，直接返回
    // 判断是否是叶节点
    if (node->children.empty()) {
        output << node->type << " " << node->value << std::endl;
        if(node->value=="if")
        {
            parsingTime=0;
        }
        if(node->isLastChild())
        {
            auto parent = node->parent;
            if(parent->type!="BlockItem"&&parent->type!="BType"&&parent->type!="Decl")
                output << "<" << parent->type << ">" << std::endl;
            while(parent->isLastChild())
            {
                if(parent->parent->type!="BlockItem"&&parent->parent->type!="BType"&&parent->parent->type!="Decl")
                    output << "<" << parent->parent->type << ">" << std::endl;
                parent = parent->parent;
            }
        }
    }
    // 递归遍历每个子节点
    for (const auto& child : node->children) {
        traverseLeaves(child, output);
    }
}

std::shared_ptr<TreeNode> parsing()
{
    auto root = std::make_shared<TreeNode>("CompUnit", false);
    CompUnit(0, root);
    return root;
}
bool CompUnit(int i, std::shared_ptr<TreeNode>& node)
{
    while(Decl(i, node)){i=parsingTime;}
    while(FuncDef(i, node)){i=parsingTime;}
    MainFuncDef(i, node);
    return true;
}
bool Decl(int i, std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto decl = std::make_shared<TreeNode>("Decl", false);
    node->addChild(decl);
    if(ConstDecl(i, decl)){return true;}
    else if(VarDecl(i, decl)){return true;}
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool ConstDecl(int i, std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto constdecl = std::make_shared<TreeNode>("ConstDecl", false);
    node->addChild(constdecl);
    if(tokens[i].value == "const")
    {
        auto Const = std::make_shared<TreeNode>("const", "CONSTTK", true);
        constdecl->addChild(Const);
        parsingTime++;
        i = parsingTime;
        if(BType(i, constdecl))
        {
            i = parsingTime;
            if(ConstDef(i, constdecl))
            {
                i=parsingTime;
                while(tokens[i].value==",")
                {
                    auto comma = std::make_shared<TreeNode>(",","COMMA", true);
                    constdecl->addChild(comma);
                    parsingTime++;
                    i = parsingTime;
                    if(!ConstDef(i, constdecl))
                    {
                        node->children.pop_back();
                        parsingTime = start;
                        return false;
                    }
                    i = parsingTime;
                }
                if(tokens[i].value==";")
                {
                    auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                    constdecl->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (";");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"i", line});
                    hasError = true;
                    auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                    constdecl->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool BType(int i, std::shared_ptr<TreeNode> &node)
{
    int start = parsingTime;
    auto btype = std::make_shared<TreeNode>("BType", false);
    node->addChild(btype);
    if(tokens[i].value == "int")
    {
        auto Int = std::make_shared<TreeNode>("int","INTTK", true);
        btype->addChild(Int);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value == "char")
    {
        auto Char = std::make_shared<TreeNode>("char","CHARTK", true);
        btype->addChild(Char);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool ConstDef(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto constdef = std::make_shared<TreeNode>("ConstDef", false);
    node->addChild(constdef);
    if(tokens[i].type == "IDENFR")
    {
        auto idenfr = std::make_shared<TreeNode>(tokens[i].value, "IDENFR", true);
        constdef->addChild(idenfr);
        parsingTime++;
        i = parsingTime;
        while(tokens[i].value == "[")
        {
            auto lbrack = std::make_shared<TreeNode>("[", "LBRACK", true);
            constdef->addChild(lbrack);
            parsingTime++;
            i = parsingTime;
            if(ConstExp(i, constdef))
            {
                i = parsingTime;
                if(tokens[i].value == "]")
                {
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    constdef->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = ("]");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"k", line});
                    hasError = true;
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    constdef->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                }
            }
        }
        if(tokens[i].value == "=")
        {
            auto assign = std::make_shared<TreeNode>("=", "ASSIGN", true);
            constdef->addChild(assign);
            parsingTime++;
            i = parsingTime;
            if(ConstInitVal(i, constdef))
            {
                i = parsingTime;
                return true;
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool ConstInitVal(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto constinitval = std::make_shared<TreeNode>("ConstInitVal", false);
    node->addChild(constinitval);
    if(ConstExp(i, constinitval))
    {
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value == "{")
    {
        auto lbrace = std::make_shared<TreeNode>("{", "LBRACE", true);
        constinitval->addChild(lbrace);
        parsingTime++;
        i = parsingTime;
        if(ConstExp(i, constinitval))
        {
            i = parsingTime;
            while(tokens[i].value==",")
            {
                auto comma = std::make_shared<TreeNode>(",","COMMA", true);
                constinitval->addChild(comma);
                parsingTime++;
                i = parsingTime;
                if(!ConstExp(i, constinitval))
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
                i = parsingTime;
            }
        }
        if(tokens[i].value=="}")
        {
            auto rbrace = std::make_shared<TreeNode>("}", "RBRACE", true);
            constinitval->addChild(rbrace);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    else if(tokens[i].type == "STRCON")
    {
        auto strcon = std::make_shared<TreeNode>(tokens[i].value, "STRCON", true);
        constinitval->addChild(strcon);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool VarDecl(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto vardecl = std::make_shared<TreeNode>("VarDecl", false);
    node->addChild(vardecl);
    if(BType(i, vardecl))
    {
        i = parsingTime;
        if(VarDef(i, vardecl))
        {
            i = parsingTime;
            while(tokens[i].value==",")
            {
                auto comma = std::make_shared<TreeNode>(",","COMMA", true);
                vardecl->addChild(comma);
                parsingTime++;
                i = parsingTime;
                if(!VarDef(i, vardecl))
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
                i = parsingTime;
            }
            if(tokens[i].value==";")
            {
                auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                vardecl->addChild(semicn);
                parsingTime++;
                i = parsingTime;
                return true;
            }
            else if(tokens[i].value=="(")
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
            else
            {
                int line = tokens[i-1].line;
                std::string temp = (";");
                tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                errors.push_back({"i", line});
                hasError = true;
                auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                vardecl->addChild(semicn);
                parsingTime++;
                i = parsingTime;
                return true;
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool VarDef(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto vardef = std::make_shared<TreeNode>("VarDef", false);
    node->addChild(vardef);
    if(tokens[i].type=="IDENFR")
    {
        auto idenfr = std::make_shared<TreeNode>(tokens[i].value,"IDENFR", true);
        vardef->addChild(idenfr);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="[")
        {
            auto lbrack = std::make_shared<TreeNode>("[", "LBRACK", true);
            vardef->addChild(lbrack);
            parsingTime++;
            i = parsingTime;
            if(ConstExp(i, vardef))
            {
                i = parsingTime;
            }
            else
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
            if(tokens[i].value=="]")
            {
                auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                vardef->addChild(rbrack);
                parsingTime++;
                i = parsingTime;
            }
            else
            {
                int line = tokens[i-1].line;
                std::string temp = ("]");
                tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                errors.push_back({"k", line});
                hasError = true;
                auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                vardef->addChild(rbrack);
                parsingTime++;
                i = parsingTime;
            }
        }
        if(tokens[i].value=="=")
        {
            auto assign = std::make_shared<TreeNode>("=","ASSIGN", true);
            vardef->addChild(assign);
            parsingTime++;
            i = parsingTime;
            if(InitVal(i, vardef))
            {
                i = parsingTime;
                return true;
            }
            else
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
        }
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool InitVal(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto initval = std::make_shared<TreeNode>("InitVal", false);
    node->addChild(initval);
    if(Exp(i, initval))
    {
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value=="{")
    {
        auto lbrace = std::make_shared<TreeNode>("{", "LBRACE", true);
        initval->addChild(lbrace);
        parsingTime++;
        i = parsingTime;
        if(Exp(i, initval))
        {
            i = parsingTime;
            while(tokens[i].value==",")
            {
                auto comma = std::make_shared<TreeNode>(",", "COMMA", true);
                initval->addChild(comma);
                parsingTime++;
                i = parsingTime;
                if(!Exp(i, initval))
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
                i = parsingTime;
            }
        }
        if(tokens[i].value=="}")
        {
            auto rbrace = std::make_shared<TreeNode>("}", "RBRACE", true);
            initval->addChild(rbrace);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    else if(tokens[i].type=="STRCON")
    {
        auto strcon = std::make_shared<TreeNode>(tokens[i].value, "STRCON", true);
        initval->addChild(strcon);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool FuncDef(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto funcdef = std::make_shared<TreeNode>("FuncDef", false);
    node->addChild(funcdef);
    if(FuncType(i, funcdef))
    {
        i = parsingTime;
        if(tokens[i].type=="IDENFR")
        {
            auto idenfr = std::make_shared<TreeNode>(tokens[i].value, "IDENFR", true);
            funcdef->addChild(idenfr);
            parsingTime++;
            i = parsingTime;
            if(tokens[i].value=="(")
            {
                auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
                funcdef->addChild(lparent);
                parsingTime++;
                i = parsingTime;
                if(FuncFParams(i, funcdef))
                {
                    i = parsingTime;
                }
                if(tokens[i].value==")")
                {
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    funcdef->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (")");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"j", line});
                    hasError = true;
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    funcdef->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                if(Block(i, funcdef))
                {
                    i = parsingTime;
                    return true;
                }
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool MainFuncDef(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto mainfuncdef = std::make_shared<TreeNode>("MainFuncDef", false);
    node->addChild(mainfuncdef);
    if(tokens[i].value=="int")
    {
        auto Int = std::make_shared<TreeNode>("int", "INTTK", true);
        mainfuncdef->addChild(Int);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="main")
        {
            auto mainfunc = std::make_shared<TreeNode>("main", "MAINTK", true);
            mainfuncdef->addChild(mainfunc);
            parsingTime++;
            i = parsingTime;
            if(tokens[i].value=="(")
            {
                auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
                mainfuncdef->addChild(lparent);
                parsingTime++;
                i = parsingTime;
                if(tokens[i].value==")")
                {
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    mainfuncdef->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (")");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"j", line});
                    hasError = true;
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    mainfuncdef->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                if(Block(i, mainfuncdef))
                {
                    i = parsingTime;
                    return true;
                }
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool FuncType(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto functype = std::make_shared<TreeNode>("FuncType", false);
    node->addChild(functype);
    if(tokens[i].value == "void")
    {
        auto Void = std::make_shared<TreeNode>("void","VOIDTK", true);
        functype->addChild(Void);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value == "int")
    {
        auto Int = std::make_shared<TreeNode>("int","INTTK", true);
        functype->addChild(Int);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value == "char")
    {
        auto Char = std::make_shared<TreeNode>("char","CHARTK", true);
        functype->addChild(Char);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool FuncFParams(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto funcfparams = std::make_shared<TreeNode>("FuncFParams", false);
    node->addChild(funcfparams);
    if(FuncFParam(i, funcfparams))
    {
        i = parsingTime;
        while(tokens[i].value==",")
        {
            auto comma = std::make_shared<TreeNode>(",", "COMMA", true);
            funcfparams->addChild(comma);
            parsingTime++;
            i = parsingTime;
            if(!FuncFParam(i, funcfparams))
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
            i = parsingTime;
        }
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool FuncFParam(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto funcfparam = std::make_shared<TreeNode>("FuncFParam", false);
    node->addChild(funcfparam);
    if(BType(i, funcfparam))
    {
        i = parsingTime;
        if(tokens[i].type=="IDENFR")
        {
            auto IDENFR = std::make_shared<TreeNode>(tokens[i].value, "IDENFR", true);
            funcfparam->addChild(IDENFR);
            parsingTime++;
            i = parsingTime;
            if(tokens[i].value=="[")
            {
                auto lbrack = std::make_shared<TreeNode>("[", "LBRACK", true);
                funcfparam->addChild(lbrack);
                parsingTime++;
                i = parsingTime;
                if(tokens[i].value=="]")
                {
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    funcfparam->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = ("]");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"k", line});
                    hasError = true;
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    funcfparam->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                }
                return true;
            }
            return true;
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool Block(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto block = std::make_shared<TreeNode>("Block", false);
    node->addChild(block);
    if(tokens[i].value=="{")
    {
        auto lbrace = std::make_shared<TreeNode>("{", "LBRACE", true);
        block->addChild(lbrace);
        parsingTime++;
        i = parsingTime;
        while(BlockItem(i, block))
        {
            i = parsingTime;
        }
        if(tokens[i].value=="}")
        {
            auto rbrace = std::make_shared<TreeNode>("}", "RBRACE", true);
            block->addChild(rbrace);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool BlockItem(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto blockitem = std::make_shared<TreeNode>("BlockItem", false);
    node->addChild(blockitem);
    if(Decl(i, blockitem))
    {
        i = parsingTime;
        return true;
    }
    else if(Stmt(i, blockitem))
    {
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool Stmt(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto stmt = std::make_shared<TreeNode>("Stmt", false);
    node->addChild(stmt);
    if(LVal(i, stmt))
    {
        i = parsingTime;
        if(tokens[i].value=="=")
        {
            auto assign = std::make_shared<TreeNode>("=", "ASSIGN", true);
            stmt->addChild(assign);
            parsingTime++;
            i = parsingTime;
            if(tokens[i].value=="getint")
            {
                auto getint = std::make_shared<TreeNode>("getint", "GETINTTK", true);
                stmt->addChild(getint);
                parsingTime++;
                i = parsingTime;
                if(tokens[i].value=="(")
                {
                    auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
                    stmt->addChild(lparent);
                    parsingTime++;
                    i = parsingTime;
                    if(tokens[i].value==")")
                    {
                        auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                        stmt->addChild(rparent);
                        parsingTime++;
                        i = parsingTime;
                    }
                    else
                    {
                        int line = tokens[i-1].line;
                        std::string temp = (")");
                        tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                        errors.push_back({"j", line});
                        hasError = true;
                        auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                        stmt->addChild(rparent);
                        parsingTime++;
                        i = parsingTime;
                    }
                    if(tokens[i].value==";")
                    {
                        auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                        stmt->addChild(semicn);
                        parsingTime++;
                        i = parsingTime;
                        return true;
                    }
                    else
                    {
                        int line = tokens[i-1].line;
                        std::string temp = (";");
                        tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                        errors.push_back({"i", line});
                        hasError = true;
                        auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                        stmt->addChild(semicn);
                        parsingTime++;
                        i = parsingTime;
                        return true;
                    }
                }
            }
            else if(tokens[i].value=="getchar")
            {
                auto getchar = std::make_shared<TreeNode>("getchar", "GETCHARTK", true);
                stmt->addChild(getchar);
                parsingTime++;
                i = parsingTime;
                if(tokens[i].value=="(")
                {
                    auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
                    stmt->addChild(lparent);
                    parsingTime++;
                    i = parsingTime;
                    if(tokens[i].value==")")
                    {
                        auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                        stmt->addChild(rparent);
                        parsingTime++;
                        i = parsingTime;
                    }
                    else
                    {
                        int line = tokens[i-1].line;
                        std::string temp = (")");
                        tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                        errors.push_back({"j", line});
                        hasError = true;
                        auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                        stmt->addChild(rparent);
                        parsingTime++;
                        i = parsingTime;
                    }
                    if(tokens[i].value==";")
                    {
                        auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                        stmt->addChild(semicn);
                        parsingTime++;
                        i = parsingTime;
                        return true;
                    }
                    else
                    {
                        int line = tokens[i-1].line;
                        std::string temp = (";");
                        tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                        errors.push_back({"i", line});
                        hasError = true;
                        auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                        stmt->addChild(semicn);
                        parsingTime++;
                        i = parsingTime;
                        return true;
                    }
                }
            }
            else if(Exp(i, stmt))
            {
                i = parsingTime;
                if(tokens[i].value==";")
                {
                    auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                    stmt->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (";");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"i", line});
                    hasError = true;
                    auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                    stmt->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
            }
        }
        stmt->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    if(tokens[i].value==";")
    {
        auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
        stmt->addChild(semicn);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(Block(i, stmt))
    {
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value=="if")
    {
        auto If = std::make_shared<TreeNode>("if", "IFTK", true);
        stmt->addChild(If);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="(")
        {
            auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
            stmt->addChild(lparent);
            parsingTime++;
            i = parsingTime;
            if(Cond(i, stmt))
            {
                i = parsingTime;
                if(tokens[i].value==")")
                {
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    stmt->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (")");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"j", line});
                    hasError = true;
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT",  true);
                    stmt->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                if(Stmt(i, stmt))
                {
                    i = parsingTime;
                    if(tokens[i].value=="else")
                    {
                        auto Else = std::make_shared<TreeNode>("else", "ELSETK", true);
                        stmt->addChild(Else);
                        parsingTime++;
                        i = parsingTime;
                        if(Stmt(i, stmt))
                        {
                            i = parsingTime;
                        }
                        else
                        {
                            node->children.pop_back();
                            parsingTime = start;
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        stmt->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    else if(tokens[i].value=="for")
    {
        auto For = std::make_shared<TreeNode>("for", "FORTK", true);
        stmt->addChild(For);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="(")
        {
            auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
            stmt->addChild(lparent);
            parsingTime++;
            i = parsingTime;
            if(ForStmt(i, stmt))
            {
                i = parsingTime;
            }
            if(tokens[i].value==";")
            {
                auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                stmt->addChild(semicn);
                parsingTime++;
                i = parsingTime;
                if(Cond(i, stmt))
                {
                    i = parsingTime;
                }
                if(tokens[i].value==";")
                {
                    auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                    stmt->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    if(ForStmt(i, stmt))
                    {
                        i = parsingTime;
                    }
                    if(tokens[i].value==")")
                    {
                        auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                        stmt->addChild(rparent);
                        parsingTime++;
                        i = parsingTime;
                        if(Stmt(i, stmt))
                        {
                            i = parsingTime;
                            return true;
                        }
                    }
                }
            }
        }
        stmt->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    else if(tokens[i].value=="break")
    {
        auto Break = std::make_shared<TreeNode>("break", "BREAKTK", true);
        stmt->addChild(Break);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value==";")
        {
            auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
        else
        {
            int line = tokens[i-1].line;
            std::string temp = (";");
            tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
            errors.push_back({"i", line});
            hasError = true;
            auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    else if(tokens[i].value=="continue")
    {
        auto Continue = std::make_shared<TreeNode>("continue", "CONTINUETK", true);
        stmt->addChild(Continue);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value==";")
        {
            auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
        else
        {
            int line = tokens[i-1].line;
            std::string temp = (";");
            tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
            errors.push_back({"i", line});
            hasError = true;
            auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    else if(tokens[i].value=="return")
    {
        auto Return = std::make_shared<TreeNode>("return", "RETURNTK", true);
        stmt->addChild(Return);
        parsingTime++;
        i = parsingTime;
        if(Exp(i, stmt))
        {
            i = parsingTime;
        }
        if(tokens[i].value==";")
        {
            auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
        else
        {
            int line = tokens[i-1].line;
            std::string temp = (";");
            tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
            errors.push_back({"i", line});
            hasError = true;
            auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
        stmt->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    else if(tokens[i].value=="printf")
    {
        auto printf = std::make_shared<TreeNode>("printf", "PRINTFTK", true);
        stmt->addChild(printf);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="(")
        {
            auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
            stmt->addChild(lparent);
            parsingTime++;
            i = parsingTime;
            if(tokens[i].type=="STRCON")
            {
                auto strcon = std::make_shared<TreeNode>(tokens[i].value, "STRCON", true);
                stmt->addChild(strcon);
                parsingTime++;
                i = parsingTime;
                while(tokens[i].value==",")
                {
                    auto comma = std::make_shared<TreeNode>(",", "COMMA", true);
                    stmt->addChild(comma);
                    parsingTime++;
                    i = parsingTime;
                    if(Exp(i, stmt))
                    {
                        i = parsingTime;
                    }
                    else
                    {
                        node->children.pop_back();
                        parsingTime = start;
                        return false;
                    }
                }
                if(tokens[i].value==")")
                {
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    stmt->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (")");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"j", line});
                    hasError = true;
                    auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                    stmt->addChild(rparent);
                    parsingTime++;
                    i = parsingTime;
                }
                if(tokens[i].value==";")
                {
                    auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
                    stmt->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = (";");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"i", line});
                    hasError = true;
                    auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
                    stmt->addChild(semicn);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
            }
        }
        stmt->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    if(Exp(i, stmt))
    {
        i = parsingTime;
        if(tokens[i].value==";")
        {
            auto semicn = std::make_shared<TreeNode>(";", "SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
        else
        {
            int line = tokens[i-1].line;
            std::string temp = (";");
            tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
            errors.push_back({"i", line});
            hasError = true;
            auto semicn = std::make_shared<TreeNode>(";","SEMICN", true);
            stmt->addChild(semicn);
            parsingTime++;
            i = parsingTime;
            return true;
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool ForStmt(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto forstmt = std::make_shared<TreeNode>("ForStmt", false);
    node->addChild(forstmt);
    if(LVal(i, forstmt))
    {
        i = parsingTime;
        if(tokens[i].value=="=")
        {
            auto assign = std::make_shared<TreeNode>("=", "ASSIGN", true);
            forstmt->addChild(assign);
            parsingTime++;
            i = parsingTime;
            if(Exp(i, forstmt))
            {
                i = parsingTime;
                return true;
            }
        }
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool Exp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto exp = std::make_shared<TreeNode>("Exp", false);
        node->addChild(exp);
        if(AddExp(i, exp))
        {
            i = parsingTime;
            while(tokens[i].value=="+"||tokens[i].value=="-")
            {
                if(tokens[i].value=="+")
                {
                    auto plus = std::make_shared<TreeNode>("+", "PLUS", true);
                    exp->addChild(plus);
                }
                else if(tokens[i].value=="-")
                {
                    auto minus = std::make_shared<TreeNode>("-", "MINU", true);
                    exp->addChild(minus);
                }
                parsingTime++;
                i = parsingTime;
                if(AddExp(i, exp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool Cond(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto cond = std::make_shared<TreeNode>("Cond", false);
        node->addChild(cond);
        if(LOrExp(i, cond))
        {
            i = parsingTime;
            while(tokens[i].value=="||"||tokens[i].value=="|")
            {
                if(tokens[i].value=="|")
                {
                    int line = tokens[i-1].line;
                    errors.push_back({"a", line});
                    hasError = true;
                }
                auto Or = std::make_shared<TreeNode>("||", "OR", true);
                cond->addChild(Or);
                parsingTime++;
                i = parsingTime;
                if(LOrExp(i, cond))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool LVal(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto lval = std::make_shared<TreeNode>("LVal", false);
    node->addChild(lval);
    if(tokens[i].type=="IDENFR")
    {
        auto id = std::make_shared<TreeNode>(tokens[i].value, "IDENFR", true);
        lval->addChild(id);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="[")
        {
            auto lbrack = std::make_shared<TreeNode>("[", "LBRACK", true);
            lval->addChild(lbrack);
            parsingTime++;
            i = parsingTime;
            if(Exp(i, lval))
            {
                i = parsingTime;
                if(tokens[i].value=="]")
                {
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    lval->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
                else
                {
                    int line = tokens[i-1].line;
                    std::string temp = ("]");
                    tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                    errors.push_back({"k", line});
                    hasError = true;
                    auto rbrack = std::make_shared<TreeNode>("]", "RBRACK", true);
                    lval->addChild(rbrack);
                    parsingTime++;
                    i = parsingTime;
                    return true;
                }
            }
            else
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
        }
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool PrimaryExp(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto prim = std::make_shared<TreeNode>("PrimaryExp", false);
    node->addChild(prim);
    if(tokens[i].value=="(")
    {
        auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
        prim->addChild(lparent);
        parsingTime++;
        i = parsingTime;
        if(Exp(i, prim))
        {
            i = parsingTime;
            if(tokens[i].value==")")
            {
                auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                prim->addChild(rparent);
                parsingTime++;
                i = parsingTime;
            }
            else
            {
                int line = tokens[i-1].line;
                std::string temp = (")");
                tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                errors.push_back({"j", line});
                hasError = true;
                auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                prim->addChild(rparent);
                parsingTime++;
                i = parsingTime;
            }
            return true;
        }
    }
    else if(Number(i, prim))
    {
        i = parsingTime;
        return true;
    }
    else if(Character(i, prim))
    {
        i = parsingTime;
        return true;
    }
    else if(LVal(i, prim))
    {
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool Number(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto number = std::make_shared<TreeNode>("Number", false);
    node->addChild(number);
    if(tokens[i].type=="INTCON")
    {
        auto Intcon = std::make_shared<TreeNode>(tokens[i].value,"INTCON", true);
        number->addChild(Intcon);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool Character(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto character = std::make_shared<TreeNode>("Character", false);
    node->addChild(character);
    if(tokens[i].type=="CHRCON")
    {
        auto chrcon = std::make_shared<TreeNode>(tokens[i].value,"CHRCON", true);
        character->addChild(chrcon);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool UnaryExp(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto unaryexp = std::make_shared<TreeNode>("UnaryExp", false);
    node->addChild(unaryexp);
    if(tokens[i].type=="IDENFR")
    {
        auto idenfr = std::make_shared<TreeNode>(tokens[i].value, "IDENFR", true);
        unaryexp->addChild(idenfr);
        parsingTime++;
        i = parsingTime;
        if(tokens[i].value=="(")
        {
            auto lparent = std::make_shared<TreeNode>("(", "LPARENT", true);
            unaryexp->addChild(lparent);
            parsingTime++;
            i = parsingTime;
            if(FuncRParams(i, unaryexp))
            {
                i = parsingTime;
            }
            if(tokens[i].value==")")
            {
                auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                unaryexp->addChild(rparent);
                parsingTime++;
                i = parsingTime;
                return true;
            }
            else
            {
                int line = tokens[i-1].line;
                std::string temp = (")");
                tokens.insert(tokens.begin()+i, {operators[temp],temp, line});
                errors.push_back({"j", line});
                hasError = true;
                auto rparent = std::make_shared<TreeNode>(")", "RPARENT", true);
                unaryexp->addChild(rparent);
                parsingTime++;
                i = parsingTime;
                return true;
            }
        }
        unaryexp->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    if(UnaryOp(i, unaryexp))
    {
        i = parsingTime;
        if(UnaryExp(i, unaryexp))
        {
            i = parsingTime;
            return true;
        }
        unaryexp->children.pop_back();
        parsingTime = start;
        i = parsingTime;
    }
    if(PrimaryExp(i, unaryexp))
    {
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool UnaryOp(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto unaryop = std::make_shared<TreeNode>("UnaryOp", false);
    node->addChild(unaryop);
    if(tokens[i].value=="+")
    {
        auto plus = std::make_shared<TreeNode>("+", "PLUS", true);
        unaryop->addChild(plus);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value=="-")
    {
        auto minus = std::make_shared<TreeNode>("-", "MINU", true);
        unaryop->addChild(minus);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    else if(tokens[i].value=="!")
    {
        auto Not = std::make_shared<TreeNode>("!", "NOT", true);
        unaryop->addChild(Not);
        parsingTime++;
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool FuncRParams(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto funR = std::make_shared<TreeNode>("FuncRParams", false);
    node->addChild(funR);
    if(Exp(i, funR))
    {
        i = parsingTime;
        while(tokens[i].value==",")
        {
            auto comma = std::make_shared<TreeNode>(",", "COMMA", true);
            funR->addChild(comma);
            parsingTime++;
            i = parsingTime;
            if(Exp(i, funR))
            {
                i = parsingTime;
            }
            else
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
        }
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool MulExp(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto mulexp = std::make_shared<TreeNode>("MulExp", false);
    node->addChild(mulexp);
    if(UnaryExp(i, mulexp))
    {
        i = parsingTime;
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool AddExp(int i, const std::shared_ptr<TreeNode>& node)
{
    int start = parsingTime;
    auto addexp = std::make_shared<TreeNode>("AddExp", false);
    node->addChild(addexp);
    if(MulExp(i, addexp))
    {
        i = parsingTime;
        while(tokens[i].value=="*"||tokens[i].value=="/"||tokens[i].value=="%")
        {
            if(tokens[i].value=="*")
            {
                auto mult = std::make_shared<TreeNode>("*", "MULT", true);
                addexp->addChild(mult);
            }
            else if(tokens[i].value=="/")
            {
                auto div = std::make_shared<TreeNode>("/", "DIV", true);
                addexp->addChild(div);
            }
            else if(tokens[i].value=="%")
            {
                auto mod = std::make_shared<TreeNode>("%", "MOD", true);
                addexp->addChild(mod);
            }
            parsingTime++;
            i = parsingTime;
            if(MulExp(i, addexp))
            {
                i = parsingTime;
            }
            else
            {
                node->children.pop_back();
                parsingTime = start;
                return false;
            }
        }
        return true;
    }
    node->children.pop_back();
    parsingTime = start;
    return false;
}
bool RelExp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto relexp = std::make_shared<TreeNode>("RelExp", false);
        node->addChild(relexp);
        if(AddExp(i, relexp))
        {
            i = parsingTime;
            while(tokens[i].value=="+"||tokens[i].value=="-")
            {
                if(tokens[i].value=="+")
                {
                    auto plus = std::make_shared<TreeNode>("+", "PLUS", true);
                    relexp->addChild(plus);
                }
                else if(tokens[i].value=="-")
                {
                    auto minus = std::make_shared<TreeNode>("-", "MINU", true);
                    relexp->addChild(minus);
                }
                parsingTime++;
                i = parsingTime;
                if(AddExp(i, relexp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool EqExp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto eqexp = std::make_shared<TreeNode>("EqExp", false);
        node->addChild(eqexp);
        if(RelExp(i, eqexp))
        {
            i = parsingTime;
            while(tokens[i].value=="<"||tokens[i].value==">"||tokens[i].value=="<="||tokens[i].value==">=")
            {
                if(tokens[i].value=="<")
                {
                    auto lss = std::make_shared<TreeNode>("<", "LSS", true);
                    eqexp->addChild(lss);
                }
                else if(tokens[i].value==">")
                {
                    auto gre = std::make_shared<TreeNode>(">", "GRE", true);
                    eqexp->addChild(gre);
                }
                else if(tokens[i].value=="<=")
                {
                    auto leq = std::make_shared<TreeNode>("<=", "LEQ", true);
                    eqexp->addChild(leq);
                }
                else if(tokens[i].value==">=")
                {
                    auto geq = std::make_shared<TreeNode>(">=", "GEQ", true);
                    eqexp->addChild(geq);
                }
                parsingTime++;
                i = parsingTime;
                if(RelExp(i, eqexp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool LAndExp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto landexp = std::make_shared<TreeNode>("LAndExp", false);
        node->addChild(landexp);
        if(EqExp(i, landexp))
        {
            i = parsingTime;
            while(tokens[i].value=="=="||tokens[i].value=="!=")
            {
                if(tokens[i].value=="==")
                {
                    auto eql = std::make_shared<TreeNode>("==", "EQL", true);
                    landexp->addChild(eql);
                }
                else if(tokens[i].value=="!=")
                {
                    auto neq = std::make_shared<TreeNode>("!=", "NEQ", true);
                    landexp->addChild(neq);
                }
                parsingTime++;
                i = parsingTime;
                if(EqExp(i, landexp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool LOrExp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto lorexp = std::make_shared<TreeNode>("LOrExp", false);
        node->addChild(lorexp);
        if(LAndExp(i, lorexp))
        {
            i = parsingTime;
            while(tokens[i].value=="&&"||tokens[i].value=="&")
            {
                if(tokens[i].value=="&")
                {
                    int line = tokens[i-1].line;
                    errors.push_back({"a", line});
                    hasError = true;
                }
                auto And = std::make_shared<TreeNode>("&&", "AND", true);
                lorexp->addChild(And);
                parsingTime++;
                i = parsingTime;
                if(LAndExp(i, lorexp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
bool ConstExp(int i, const std::shared_ptr<TreeNode>& node)
{
    if(tokens[i].value=="("||tokens[i].value=="+"||tokens[i].value=="-"||tokens[i].value=="!"||tokens[i].type=="INTCON"||tokens[i].type=="CHRCON"||tokens[i].type=="IDENFR")
    {
        int start = parsingTime;
        auto constexp = std::make_shared<TreeNode>("ConstExp", false);
        node->addChild(constexp);
        if(AddExp(i, constexp))
        {
            i = parsingTime;
            while(tokens[i].value=="+"||tokens[i].value=="-")
            {
                if(tokens[i].value=="+")
                {
                    auto plus = std::make_shared<TreeNode>("+", "PLUS", true);
                    constexp->addChild(plus);
                }
                else if(tokens[i].value=="-")
                {
                    auto minus = std::make_shared<TreeNode>("-", "MINU", true);
                    constexp->addChild(minus);
                }
                parsingTime++;
                i = parsingTime;
                if(AddExp(i, constexp))
                {
                    i = parsingTime;
                }
                else
                {
                    node->children.pop_back();
                    parsingTime = start;
                    return false;
                }
            }
            return true;
        }
        node->children.pop_back();
        parsingTime = start;
        return false;
    }
    return false;
}
//bug
//node->addChild
//std::make_shared<TreeNode>("if", "IFTK", true);
//左递归解决
//primaryexp unaryexp