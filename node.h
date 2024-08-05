#include <iostream>
#include <vector>
#include <llvm/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;


class Node
{
public:
    virtual ~Node() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) {}
};


class NExpression : public Node {};


class NStatement : public Node {};


class NInteger : public NExpression
{
public:
    long long value; // 64 bits
    NInteger(long long value) : value(value) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NDouble : public NExpression
{
public:
    double value;
    NDouble(double value) : value(value) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NIdentifier : public NExpression
{
public:
    std::string name;
    NIdentifier(const std::string& name) name(name) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NMethodCall : public NExpression
{

};