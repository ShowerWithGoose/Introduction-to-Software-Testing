//
// Created by  on 2024-09-04.
//

#ifndef SYS_COMPILER_VALUE_H
#define SYS_COMPILER_VALUE_H

#include <string>
#include <utility>
#include <algorithm>
#include "Type.h"

namespace ir {
    class Value;
    class User;
    class Function;
    class Argument;
    class GlobalVariable;
    class BasicBlock;
    class Instruction;
    class Constant;

    class Value {
    public:
        void addUser(User *u);

        void removeUser(User *u);

        void replaceAllUsesWith(Value *replacement);

        // 重载 == 与 != 运算符
        bool operator==(const Value &other) const { return id == other.id; }
        bool operator!=(const Value &other) const { return id != other.id; }

    public:
        Value(std::string name, Type *type, Value *parent) :
        id(generateId()), name(std::move(name)), type(type), parent(parent) {}

        std::string getName() const { return name; }
        Type *getType() const { return type; }
        Value *getParent() const { return parent; }
        std::vector<User *> &getUsers() { return users; }

        void setType(Type *newType) { this->type = newType; }
        void setParent(Value *newParent) { this->parent = newParent; }
        void setName(const std::string &newName) { this->name = newName; }

    protected:
        int id;  // 唯一标识
        std::string name;  // 名字，用于打印ir
        Type *type;  // Value 的类型
        Value *parent;  // 父节点
        std::vector<User *> users;  // Value 的所有使用者

    private:
        static int generateId();
    };


    class User : public Value {
    public:
        std::vector<Value *> &getOperators() { return operators; }

        Value *getOperator(int index) { return operators[index]; }

        // 替换掉index索引位置上的value，并实现双向修改
        void setOperator(int index, Value *newValue);

        // 获取操作数数量
        int getNumOfOps() { return (int) operators.size(); }

        void addOperator(Value *op) { operators.push_back(op); }

        // 移除操作数
        void removeOperator(Value *op);
        void removeOperator(int index) { removeOperator(operators[index]); }

        // 删除所有操作数
        void removeAllOperators();

        // 按值替换操作数
        void replaceOperator(Value *oldValue, Value *newValue);

    public:
        User(const std::string &name, Type *type, Value *parent) : Value(name, type, parent) {}

        User(const std::string &name, Type *type, Value *parent, std::vector<Value *> &operators);

    private:
        void initUsers();

    private:
        std::vector<Value *> operators;  // Value 的所有操作数
    };


} // ir

#endif //SYS_COMPILER_VALUE_H
