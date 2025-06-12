#include "cminusf_builder.hpp"

#define CONST_FP(num) ConstantFP::get((float)num, module.get())
#define CONST_INT(num) ConstantInt::get(num, module.get())

// types
Type *VOID_T;
Type *INT1_T;
Type *INT32_T;
Type *INT32PTR_T;
Type *FLOAT_T;
Type *FLOATPTR_T;
Type *INT_T;
/*
 * use CMinusfBuilder::Scope to construct scopes
 * scope.enter: enter a new scope
 * scope.exit: exit current scope
 * scope.push: add a new binding to current scope
 * scope.find: find and return the value bound to the name
 */

//  void InitValCalc::store_value(Module *module, IRBuilder *builder,
//     AllocaInst *alloca_inst, Scope &scope) {
// if (single_val != nullptr) {
// if (single_val->get_type()->is_float_type() && type->is_integer_type())
// single_val = builder->create_fptosi(single_val, type);
// else if (single_val->get_type()->is_integer_type() &&
// type->is_float_type())
// single_val = builder->create_sitofp(single_val, type);
// builder->create_store(single_val, alloca_inst);
// return;
// }
// #ifndef ZERO_ASSIGN_RATIO
// #define ZERO_ASSIGN_RATIO 0.5
// #endif
// int zero_count = 0;
// for (int i = 0; i < (int)suffix_product[0]; i++) {
// if (dynamic_cast<Constant *>(vals[i]) == nullptr)
// continue;
// if (dynamic_cast<ConstantInt *>(vals[i]) != nullptr &&
// dynamic_cast<ConstantInt *>(vals[i])->get_value() != 0)
// continue;
// if (dynamic_cast<ConstantFP *>(vals[i]) != nullptr &&
// dynamic_cast<ConstantFP *>(vals[i])->get_value() != 0.)
// continue;
// zero_count++;
// if (zero_count > (int)suffix_product[0] * ZERO_ASSIGN_RATIO)
// break;
// }
// bool assign_zero = false;
// if (zero_count > (int)suffix_product[0] * ZERO_ASSIGN_RATIO) {
// auto cast =
// builder->create_bitcast(alloca_inst, module->get_int8_ptr_type());
// builder->create_call(
// scope.find("memset").first,
// {cast, ConstantInt::get(0, module),
// ConstantInt::get(
// (long long)alloca_inst->get_alloca_type()->get_size(),
// module)});
// assign_zero = true;
// }
// #undef ZERO_ASSIGN_RATIO
// for (int i = 0; i < (int)suffix_product[0]; i++) {
// if (assign_zero) {
// if (dynamic_cast<ConstantInt *>(vals[i]) != nullptr &&
// dynamic_cast<ConstantInt *>(vals[i])->get_value() == 0)
// continue;
// if (dynamic_cast<ConstantFP *>(vals[i]) != nullptr &&
// dynamic_cast<ConstantFP *>(vals[i])->get_value() == 0.)
// continue;
// }
// if (vals[i]->get_type()->is_float_type() && type->is_integer_type())
// vals[i] = builder->create_fptosi(vals[i], type);
// else if (vals[i]->get_type()->is_integer_type() &&
// type->is_float_type())
// // vals[i] = builder->create_sitofp(vals[i], type);
// vals[i] = ConstantFP::get(
// (float)(dynamic_cast<ConstantInt *>(vals[i])->get_value()),
// module);

// if (is_const && dynamic_cast<Constant *>(vals[i]) == nullptr)
// ASSERT(false && "initializer is not a constant");
// std::vector<Value *> idxs;
// int idx = i;
// for (int j = 0; j < (int)array_size.size(); j++) {
// idxs.push_back(ConstantInt::get(idx / suffix_product[j], module));
// idx = idx % suffix_product[j];
// }
// idxs.push_back(ConstantInt::get(idx, module));
// auto ptr = builder->create_gep(alloca_inst, idxs);
// builder->create_store(vals[i], ptr);
// }
// }

void InitValCalc::store_value(Module *module, IRBuilder *builder,
                              AllocaInst *alloca_inst, Scope &scope)
{
    if (single_val != nullptr)
    {
        if (single_val->get_type()->is_float_type() && type->is_integer_type())
            single_val = builder->create_fptosi(single_val, type);
        else if (single_val->get_type()->is_integer_type() &&
                 type->is_float_type())
            single_val = builder->create_sitofp(single_val, type);
        builder->create_store(single_val, alloca_inst);
        return;
    }

    auto cast = builder->create_bitcast(alloca_inst, module->get_int8_ptr_type());
    builder->create_call(
        scope.find("memset").first,
        {cast,
         ConstantInt::get(0, module),
         ConstantInt::get(
             (long long)alloca_inst->get_alloca_type()->get_size(),
             module)});

    for (int i = 0; i < (int)suffix_product[0]; i++)
    {
        if (dynamic_cast<ConstantInt *>(vals[i]) != nullptr &&
            dynamic_cast<ConstantInt *>(vals[i])->get_value() == 0)
        {
            continue;
        }
        if (dynamic_cast<ConstantFP *>(vals[i]) != nullptr &&
            dynamic_cast<ConstantFP *>(vals[i])->get_value() == 0.)
        {
            continue;
        }
        if (vals[i]->get_type()->is_float_type() && type->is_integer_type())
        {
            vals[i] = builder->create_fptosi(vals[i], type);
        }
        else if (vals[i]->get_type()->is_integer_type() &&
                 type->is_float_type())
        {
            if (dynamic_cast<ConstantInt *>(vals[i]) != nullptr)
            {
                vals[i] = ConstantFP::get((float)(dynamic_cast<ConstantInt *>(vals[i])->get_value()), module);
            }
            else
            {

                vals[i] = builder->create_sitofp(vals[i], type);
            }
        }
        if (is_const && dynamic_cast<Constant *>(vals[i]) == nullptr)
            ASSERT(false && "initializer is not a constant"); // 初始化必须为const

        std::vector<Value *> idxs;
        int idx = i;
        idxs.push_back(ConstantInt::get(0, module));
        for (int j = 0; j < (int)array_size.size(); j++)
        {
            idxs.push_back(ConstantInt::get(idx / suffix_product[j], module));
            idx = idx % suffix_product[j];
        }
        auto ptr = builder->create_gep(alloca_inst, {ConstantInt::get(0, module), ConstantInt::get(i, module)});
        builder->create_store(vals[i], ptr);
    }
}

Constant *InitValCalc::get_const_value(Module *module)
{
    if (single_val != nullptr)
    {
        auto single_val = dynamic_cast<Constant *>(this->single_val);
        if (single_val == nullptr)
            ASSERT(false && "initializer is not a constant");

        if (dynamic_cast<ConstantInt *>(single_val) == nullptr &&
            type->is_integer_type())
        {
            return ConstantInt::get(
                (int)(dynamic_cast<ConstantFP *>(single_val)->get_value()),
                module);
        }
        else if (dynamic_cast<ConstantFP *>(single_val) == nullptr &&
                 type->is_float_type())
            return ConstantFP::get(
                (float)(dynamic_cast<ConstantInt *>(single_val)->get_value()),
                module);
        else
            return dynamic_cast<Constant *>(single_val);
    }
    bool all_zero = true;
    std::vector<Constant *> constant_array;
    for (int i = 0; i < (int)suffix_product[0]; i++)
    {
        auto val = dynamic_cast<Constant *>(vals[i]);
        if (val == nullptr)
            ASSERT(false && "initializer is not a constant");
        if (dynamic_cast<ConstantInt *>(val) == nullptr &&
            type->is_integer_type())
            return ConstantInt::get(
                (int)dynamic_cast<ConstantFP *>(val)->get_value(), module);
        else if (dynamic_cast<ConstantFP *>(val) == nullptr &&
                 type->is_float_type())
            constant_array.push_back(ConstantFP::get(
                (float)(dynamic_cast<ConstantInt *>(val)->get_value()), module));
        else
            constant_array.push_back(val);
        if (dynamic_cast<ConstantInt *>(val) != nullptr &&
            dynamic_cast<ConstantInt *>(val)->get_value() != 0)
            all_zero = false;
        if (dynamic_cast<ConstantFP *>(val) != nullptr &&
            dynamic_cast<ConstantFP *>(val)->get_value() != 0.)
            all_zero = false;
    }
    if (all_zero)
        return ConstantZero::get(type, module);
    std::vector<Constant *> new_constant_array;
    for (int i = (int)array_size.size() - 1; i >= 0; i--)
    {
        std::vector<Constant *> sub_constant_array;
        for (int j = 0; j < (int)constant_array.size(); j++)
        {
            sub_constant_array.push_back(constant_array[j]);
            if ((j + 1) % array_size[i] == 0)
            {
                new_constant_array.push_back(ConstantArray::get(
                    ArrayType::get(sub_constant_array[0]->get_type(),
                                   array_size[i]),
                    sub_constant_array));
                sub_constant_array.clear();
            }
        }
        constant_array = new_constant_array;
        new_constant_array.clear();
    }
    ASSERT(constant_array.size() == 1 && "constant array size error");
    return constant_array[0];
}


bool CminusfBuilder::promote(Value **l_val_p, Value **r_val_p, const_val *l_num, const_val *r_num)
{
    bool is_int = false;
    auto &l_val = *l_val_p;
    auto &r_val = *r_val_p;
    if (l_val->get_type() == r_val->get_type())
    {
        is_int = l_val->get_type()->is_integer_type();
    }
    else
    {
        if (l_val->get_type()->is_integer_type())
        {
            if (context.is_const_exp)
            {
                l_num->f_val = (float)l_num->i_val;
            }
            else if (scope.in_global())
                l_num->f_val = (float)l_num->i_val;
            // context.val.f_val = (float)context.val.i_val;
            else
                l_val = builder->create_sitofp(l_val, FLOAT_T);
        }
        else
        {
            if (context.is_const_exp)
                r_num->f_val = (float)r_num->i_val;
            //    context.val.i_val = (int)context.val.f_val;
            else if (scope.in_global())
                r_num->f_val = (float)r_num->i_val;
            //    context.val.i_val = (int)context.val.f_val;
            else
                r_val = builder->create_sitofp(r_val, FLOAT_T);
        }
    }
    return is_int;
}


Value *CminusfBuilder::visit(ASTProgram &node)
{
    VOID_T = module->get_void_type();
    INT_T  = module->get_int32_type();
    INT1_T = module->get_int1_type();
    INT32_T = module->get_int32_type();
    INT32PTR_T = module->get_int32_ptr_type();
    FLOAT_T = module->get_float_type();
    FLOATPTR_T = module->get_float_ptr_type();

    Value *ret_val = nullptr;
    printf("program");
    for (auto &unit : node.compunits)
    {
        ret_val = unit->accept(*this);
    }
    return ret_val;
}

Value *CminusfBuilder::visit(ASTMainDef &node) {
    FunctionType *fun_type;
    printf("main");
    Type *ret_type=INT_T;
    std::vector<Type *> param_types;
    param_types.push_back(VOID_T);
    fun_type = FunctionType::get(ret_type, param_types);
    auto func = Function::create(fun_type, node.id, module.get());
    scope.push(node.id, func);
    context.func = func;
    auto funBB = BasicBlock::create(module.get(), "entry", func);
    builder->set_insert_point(funBB);
    node.block->accept(*this);
    return nullptr;
};

Value *CminusfBuilder::visit(ASTFuncDef &node)
{   
    printf("func");
    FunctionType *fun_type;
    Type *ret_type;
    std::vector<Type *> param_types;
    if (node.type == TYPE_INT)
        ret_type = INT32_T;
    else if (node.type == TYPE_FLOAT)
        ret_type = FLOAT_T;
    else
        ret_type = VOID_T;

    for (auto &param : node.params)
    {
        param->accept(*this);
        param_types.push_back(context.type_return);
    }

    fun_type = FunctionType::get(ret_type, param_types);
    auto func = Function::create(fun_type, node.id, module.get());
    scope.push(node.id, func);
    context.func = func;
    auto funBB = BasicBlock::create(module.get(), "entry", func);
    builder->set_insert_point(funBB);
    scope.enter();
    std::vector<Value *> args;
    for (auto &arg : func->get_args())
    {
        args.push_back(&arg);
    }
    for (int i = 0; i < node.params.size(); ++i)
    {
        auto ptr = builder->create_alloca(param_types[i]);
        builder->create_store(args[i], ptr);
        scope.push(node.params[i]->id, ptr, false);
        // TODO: You need to deal with params and store them in the scope.
    }
    context.is_func_block = true;
    node.block->accept(*this);
    if (not builder->get_insert_block()->is_terminated())
    {
        if (context.func->get_return_type()->is_void_type())
            builder->create_void_ret();
        else if (context.func->get_return_type()->is_float_type())
            builder->create_ret(CONST_FP(0.));
        else
            builder->create_ret(CONST_INT(0));
    }
    scope.exit();
    return nullptr;
}

// 函数声明待实现
Value *CminusfBuilder::visit(ASTDecl &node)
{
    if (node.decl_kind == Const)
    {
        context.is_const = true;
        // context.type = node.decl_kind;
    }
    else if (node.decl_kind == Var)
    {
        context.is_const = false;
        // context.type = node.decl_kind;
    }

    if (context.is_const == true)
    {
        for (auto &def : node.cdef_lists)
        {
            def->accept(*this);
        }
    }
    else
    {
        for (auto &def : node.vdef_lists)
        {
            def->accept(*this);
        }
    }
    return nullptr;
}

Value *CminusfBuilder::visit(ASTConstDef &node)
{   
    printf("constdef");
    Type *var_type;
    if (node.type == TYPE_INT)
    {
        var_type = INT32_T;
    }
    else if (node.type == TYPE_FLOAT)
    {
        var_type = FLOAT_T;
    }
    else
    {
        ASSERT(false && "Unknown type");
    }

    std::vector<int> array_size;
    for (auto exp = node.exp_lists.rbegin(); exp != node.exp_lists.rend();
         exp++)
    {
        auto const_ptr = dynamic_cast<ConstantInt *>((*exp)->accept(*this));
        ASSERT(const_ptr != nullptr && "Array size must be a constant integer");
        array_size.push_back(const_ptr->get_value());
        ASSERT(const_ptr->get_value() > 0 && "Array size must be positive number");
        var_type = ArrayType::get(var_type, const_ptr->get_value());
    }

    array_size = std::vector<int>(array_size.rbegin(), array_size.rend());
    if (node.initval_list!= nullptr)
    {

        context.init_val_calc = std::make_shared<InitValCalc>(
            module.get(), builder.get(), array_size,
            node.type == TYPE_INT ? INT_T : FLOAT_T, true,
            node.initval_list->is_singlevalue);
        node.initval_list->accept(*this);

        if (scope.in_global())
        {
            scope.push(
                node.id,
                GlobalVariable::create(
                    node.id, module.get(), var_type, true,
                    context.init_val_calc->get_const_value(module.get())),
                true);
        }
        else
        {
            auto alloca_inst = builder->create_alloca(var_type);
            scope.push(node.id, alloca_inst, true);
            context.init_val_calc->store_value(module.get(), builder.get(),
                                               alloca_inst, scope);
        }
    }
    else
        ASSERT(false && "Constant must be initialized");
    return nullptr;
}

Value *CminusfBuilder::visit(ASTVarDef &node)
{   
    printf("vardef");
    Type *var_type;

    if (node.type == TYPE_INT)
    {
        var_type = INT32_T;
    }
    else if (node.type == TYPE_FLOAT)
    {
        var_type = FLOAT_T;
    }
    else
    {
        ASSERT(false && "Unknown type");
    }

    std::vector<int> exp_lists;
    for (auto exp = node.exp_lists.rbegin(); exp != node.exp_lists.rend();
         exp++)
    {
        auto const_ptr = dynamic_cast<ConstantInt *>((*exp)->accept(*this));
        ASSERT(const_ptr != nullptr && "Array size must be a constant integer");
        exp_lists.push_back(const_ptr->get_value());
        ASSERT(const_ptr->get_value() > 0 && "Array size must be positive number");
        var_type = ArrayType::get(var_type, const_ptr->get_value());
    }

    exp_lists = std::vector<int>(exp_lists.rbegin(), exp_lists.rend());
    if (node.initval_list != nullptr)
    {
        context.init_val_calc = std::make_shared<InitValCalc>(
            module.get(), builder.get(), exp_lists,
            node.type == TYPE_INT ? INT_T : FLOAT_T, false,
            node.initval_list->is_singlevalue);
        node.initval_list->accept(*this);

        if (scope.in_global())
        {
            scope.push(
                node.id,
                GlobalVariable::create(
                    node.id, module.get(), var_type, false,
                    context.init_val_calc->get_const_value(module.get())),
                false);
        }
        else
        {
            auto alloca_inst = builder->create_alloca(var_type);
            scope.push(node.id, alloca_inst, false);
            context.init_val_calc->store_value(module.get(), builder.get(),
                                               alloca_inst, scope);
        }
    }
    else
    {
        if (scope.in_global())
        {
            scope.push(node.id,
                       GlobalVariable::create(
                           node.id, module.get(), var_type, false,
                           ConstantZero::get(var_type, module.get())),
                       false);
        }
        else
        {
            scope.push(node.id, builder->create_alloca(var_type), false);
        }
    }
    return nullptr;
}

Value *CminusfBuilder::visit(ASTInitVal &node) { 
    printf("init");
    auto &calculator = context.init_val_calc;
    if (calculator->is_single_val()) {
        calculator->single_val = node.value->accept(*this);
        ASSERT(calculator->single_val != nullptr && "Initializer expression did not produce a valid Value*");
        return nullptr;
    }

    for (auto &init_val : node.initval_list) {
        if (init_val->is_singlevalue) {
            calculator->vals[calculator->cur_idx] =
                init_val->value->accept(*this);
            calculator->cur_idx++;
        } else {
            int next = -1;
            for (int i = 1; i < (int)calculator->suffix_product.size(); i++) {
                if (calculator->cur_idx % calculator->suffix_product[i] == 0) {
                    next = calculator->cur_idx + calculator->suffix_product[i];
                    break;
                }
            }
            if (next == -1) {
                ASSERT(false && "array size error");
            }
            init_val->accept(*this);
            calculator->cur_idx = next;
        }
    }
    return nullptr;
}

Value *CminusfBuilder::visit(ASTParam &node)
{
    if (node.type == TYPE_VOID)
    {
        context.type_return = VOID_T;
        return nullptr;
    }
    Type *var_type;
    if (node.type == TYPE_FLOAT)
        var_type = FLOAT_T;
    else if (node.type == TYPE_INT)
        var_type = INT32_T;
    else
        ASSERT(false && "Unknown type,must be float or int");
    if (node.isarray == false)
    {
        context.type_return = var_type;
        return nullptr;
    }
    for (auto dim = node.array_lists.rbegin(); dim != node.array_lists.rend();
         dim++)
    {
        context.is_const_exp = true;
        auto const_val = static_cast<ConstantInt *>((*dim)->accept(*this));
        context.is_const_exp = false;
        if (const_val == nullptr)
            ASSERT(false && "Array size must be a constant integer");
        if (const_val->get_value() <= 0)
            ASSERT(false && "Array size must be positive number");

        var_type = ArrayType::get(var_type, const_val->get_value());
    }
    var_type = PointerType::get(var_type);
    context.type_return = var_type;
    return nullptr;
}

Value *CminusfBuilder::visit(ASTBlock &node) { 
    printf("Block");
    // bool need_exit_scope = !context.pre_enter_scope;
    // if (context.pre_enter_scope)
    //     context.pre_enter_scope = false;
    // else
        scope.enter();
    auto it_stmt = node.stmt_lists.begin();
    auto it_decl = node.decl_lists.begin();
    for (auto &it : node.list_type)
    {
        if (it == 0)
        {
            (*it_decl)->accept(*this);
            it_decl++;
        }
        else
        {
            (*it_stmt)->accept(*this);
            it_stmt++;
            if (builder->get_insert_block()->is_terminated())
                break;
        }
    }
    // if (need_exit_scope)
    // {
        scope.exit();
    // }
    // LOG(DEBUG) << "ASTBlock_end";
    return nullptr;

}

Value *CminusfBuilder::visit(ASTAssignStmt &node)
{
    // 1) 先生成右侧表达式的值
    Value *expr_val = node.expression->accept(*this);

    // 2) 要把左侧当 L-value（地址）来处理
    context.require_lvalue = true;
    Value *var_addr = node.var->accept(*this);
    context.require_lvalue = false;

    // 3) 如果左右类型不匹配，就补一个 int<->float 的转换
    if (var_addr->get_type()->get_pointer_element_type() != expr_val->get_type())
    {
        if (expr_val->get_type()->is_integer_type())
            expr_val = builder->create_sitofp(expr_val, module->get_float_type());
        else
            expr_val = builder->create_fptosi(expr_val, module->get_int32_type());
    }

    // 4) 生成 store 指令
    builder->create_store(expr_val, var_addr);

    return expr_val;
}

// ========== 2) if / else 语句：visit(ASTSelectionStmt) ==========  
Value *CminusfBuilder::visit(ASTSelectionStmt &node) {
    Function *currentFunc = context.func;  
    // 每次进来都给本次 if 生成一个唯一编号
    static int ifCount = 0;
    std::string id = std::to_string(ifCount++);

    // 1) 创建若干基本块：then 分支、else 分支（若无 else 则用 mergeBB 代替）、以及 mergeBB
    BasicBlock *thenBB = BasicBlock::create(module.get(), "if.then." + id, currentFunc);
    BasicBlock *elseBB = nullptr;
    if (node.else_stmt != nullptr) {
        elseBB = BasicBlock::create(module.get(), "if.else." + id, currentFunc);
    }
    BasicBlock *mergeBB = BasicBlock::create(module.get(), "if.end." + id, currentFunc);

    // 2) 将 then/else 的目标入栈，让后面访问 cond 时能取到
    context.true_bb_stk.push(thenBB);
    if (node.else_stmt) {
        context.false_bb_stk.push(elseBB);
    } else {
        context.false_bb_stk.push(mergeBB);
    }

    // 3) 先处理条件表达式（cond），cond->accept 里应当最终发出 icmp + create_cond_br
    node.cond->accept(*this);

    // 4) 切到 thenBB，生成 then-body
    builder->set_insert_point(thenBB);
    node.if_stmt->accept(*this);
    // 如果 thenBB 里没有 terminator，就补一条 br mergeBB
    if (!builder->get_insert_block()->is_terminated()) {
        builder->create_br(mergeBB);
    }

    // 5) 若有 else 分支，则处理 elseBB
    if (node.else_stmt) {
        builder->set_insert_point(elseBB);
        node.else_stmt->accept(*this);
        if (!builder->get_insert_block()->is_terminated()) {
            builder->create_br(mergeBB);
        }
    }

    // 6) 切回 mergeBB，后续代码就在 mergeBB 中继续生成
    builder->set_insert_point(mergeBB);

    // 7) 弹出栈顶
    context.true_bb_stk.pop();
    context.false_bb_stk.pop();

    return nullptr;
}


// ========== 3) while 循环：visit(ASTIterationStmt) ==========  
Value *CminusfBuilder::visit(ASTIterationStmt &node) {
    Function *currentFunc = context.func;

    // “上一块” 末尾插入无条件跳转到 condBB 的逻辑会在 condBB 创建后 patch
    BasicBlock *prevBB = builder->get_insert_block();

    // 1) 创建判断条件块 condBB，并将当前插入点改为 condBB
    static int whileCount = 0;
    std::string wid = std::to_string(whileCount++);
    BasicBlock *condBB = BasicBlock::create(module.get(), "while.cond." + wid, currentFunc);
    // 如果 prevBB 没 terminator，就现在让它跳转到 condBB
    if (prevBB && !prevBB->is_terminated()) {
        builder->set_insert_point(prevBB);
        builder->create_br(condBB);
    }
    builder->set_insert_point(condBB);

    // 2) 创建循环体和循环退出块
    BasicBlock *bodyBB = BasicBlock::create(module.get(), "while.body." + wid, currentFunc);
    BasicBlock *endBB  = BasicBlock::create(module.get(), "while.end."  + wid, currentFunc);

    // 3) 压栈：循环体的“真”目标是 bodyBB，“假”目标是 endBB
    context.true_bb_stk.push(bodyBB);
    context.false_bb_stk.push(endBB);
    // 同时也要记录“condBB”以便 continue 使用，“endBB”以便 break 使用
    context.cond_bb_stk.push(condBB);
    context.next_bb_stk.push(endBB);

    // 4) 访问条件表达式，cond->accept 会在 ASTRelExp 中生成 
    //    “icmp + create_cond_br(condVal, bodyBB, endBB)”
    node.cond->accept(*this);

    // 5) 切到循环体 bodyBB，生成循环体内部代码
    builder->set_insert_point(bodyBB);
    node.stmt->accept(*this);
    // bodyBB 末尾若无终结（比如没有 return/break/continue），就在末尾加一句“跳回 condBB”
    if (!builder->get_insert_block()->is_terminated()) {
        builder->create_br(condBB);
    }

    // 6) 切到 endBB，循环外的代码将从这里继续
    builder->set_insert_point(endBB);

    // 7) 弹栈：bodyBB/endBB/condBB 对应的所有 stack
    context.true_bb_stk.pop();
    context.false_bb_stk.pop();
    context.cond_bb_stk.pop();
    context.next_bb_stk.pop();

    return nullptr;
}

// ========== 4) break 语句：visit(ASTBreak) ==========
Value *CminusfBuilder::visit(ASTBreak & /*node*/)
{
    // break 直接跳转到最内层循环的 endBB，也就是 next_bb_stk.top()
    BasicBlock *targetBB = context.next_bb_stk.top();
    return builder->create_br(targetBB);
}

// ========== 5) continue 语句：visit(ASTContinue) ==========
Value *CminusfBuilder::visit(ASTContinue & /*node*/)
{
    // continue 要跳转到最内层循环的 condBB
    BasicBlock *targetBB = context.cond_bb_stk.top();
    return builder->create_br(targetBB);
}

// ========== 6) return 语句：visit(ASTReturnStmt) ==========
Value *CminusfBuilder::visit(ASTReturnStmt &node)
{
    // 如果没有返回值，就生成空返回
    if (!node.expression) {
        builder->create_void_ret();
        return nullptr;
    }

    // 否则先计算返回值
    Value *retVal     = node.expression->accept(*this);
    Type  *retTypeFun = context.func->get_return_type();

    // 如果类型不一致，就插入 int<->float 转换
    if (retVal->get_type() != retTypeFun) {
        if (retTypeFun->is_integer_type())
            retVal = builder->create_fptosi(retVal, retTypeFun);
        else
            retVal = builder->create_sitofp(retVal, retTypeFun);
    }

    // 生成 return
    builder->create_ret(retVal);
    return nullptr;
}
// Exp -> AddExp
Value *CminusfBuilder::visit(ASTExp &node)
{
    // // LOG(INFO) << node.is_const;
    // // LOG(WARNING) << (context.is_const_exp ? 1 : 0);
    // LOG(DEBUG) << "ASTExp";
    auto const_ori = node.is_const;
    if (node.is_const)
    {
        // node.is_const = true;
        context.is_const_exp = true;
    }
    auto *ret_val = node.add_exp->accept(*this);
    // // LOG(INFO) << "+++++++++++++++++++++++++++++++++++=";
    if (ret_val != nullptr)
    {
        if (ret_val->get_type()->is_integer_type())
        {
            node.val.i_val = context.val.i_val;
        }
        else
            node.val.f_val = context.val.f_val;
    }
    // // LOG(DEBUG) << ret_val->print();
    node.is_const = const_ori;
    context.is_const_exp = false;
    // LOG(DEBUG) << "ASTExp_end";
    return ret_val;
}
// Value *CminusfBuilder::visit(ASTVar &node)
// {
//     auto [var, is_declared_const] = scope.find(node.id);
//     auto is_int = var->get_type()->get_pointer_element_type()->is_integer_type();
//     auto is_float = var->get_type()->get_pointer_element_type()->is_float_type();
//     auto is_ptr = var->get_type()->get_pointer_element_type()->is_pointer_type();
//     bool should_return_lvalue = context.require_lvalue;

//     Value *ret_val = nullptr;
//     if (node.length == 0)
//     {
//         if (should_return_lvalue)
//         {
//             ret_val = var;
//             context.require_lvalue = false;
//         }
//         else
//         {
//             // 对常量的引用
//             if (context.is_const_exp)
//             {
//                 auto const_var = scope.find_const({node.id, {}});
//                 if (is_int)
//                 {
//                     context.val.i_val = const_var.i_val;
//                     ret_val = CONST_INT((int)context.val.i_val);
//                 }
//                 else if (is_float)
//                 {
//                     context.val.f_val = const_var.f_val;
//                     ret_val = CONST_FP(context.val.f_val);
//                 }
//             }
//             else
//             {
//                 if (is_int || is_float || is_ptr)
//                 {
//                     ret_val = builder->create_load(var);
//                 }
//                 else
//                 {
//                     ret_val = builder->create_gep(var, {CONST_INT(0), CONST_INT(0)});
//                 }
//             }
//         }
//     }
//     // 数组
//     else
//     {
//         Value *temp_val = var;
//         if (!context.is_const_exp)
//         {
//             if (should_return_lvalue)
//             {
//                 context.require_lvalue = false;
//             }
//             if (is_int || is_float)
//             {
//                 assert(node.array_lists.size() == 1);
//                 auto *val = node.array_lists[0]->accept(*this);
//                 temp_val = builder->create_gep(temp_val, {val});
//             }
//             else
//             {
//                 if (temp_val->get_type()->get_pointer_element_type()->is_pointer_type())
//                 {
//                     temp_val = builder->create_load(temp_val);
//                     std::vector<Value *> args;
//                     for (auto dim : node.array_lists)
//                     {
//                         args.push_back(dim->accept(*this));
//                     }
//                     temp_val = builder->create_gep(temp_val, args);
//                 }
//                 else
//                 {
//                     std::vector<Value *> args;
//                     args.push_back(CONST_INT(0));
//                     for (auto dim : node.array_lists)
//                     {
//                         args.push_back(dim->accept(*this));
//                     }
//                     temp_val = builder->create_gep(temp_val, args);
//                 }
//             }
//             if (should_return_lvalue)
//             {
//                 ret_val = temp_val;
//                 context.require_lvalue = false;
//             }
//             else
//             {
//                 if (temp_val->get_type()->get_pointer_element_type()->is_array_type())
//                 {
//                     temp_val = builder->create_gep(temp_val, {CONST_INT(0), CONST_INT(0)});
//                     ret_val = temp_val;
//                 }
//                 else
//                     ret_val = builder->create_load(temp_val);
//             }
//         }
//         else
//         {
//             if (should_return_lvalue)
//             {
//                 context.require_lvalue = false;
//             }
//             std::vector<unsigned> num_list;
//             for (auto dim : node.array_lists)
//             {
//                 dim->accept(*this);
//                 num_list.push_back(context.val.i_val);
//             }
//             auto const_var = scope.find_const({node.id, num_list});
//             if (is_int)
//             {
//                 ret_val = CONST_INT((int)const_var.i_val);
//                 context.val.i_val = std::stoi(ret_val->print());
//             }
//             else if (is_float)
//             {
//                 ret_val = CONST_FP(const_var.f_val);
//                 // LOG(INFO) << ret_val->print();
//                 context.val.f_val = std::stof(ret_val->print());
//             }
//         }
//     }
//     return ret_val;
// }

Value *CminusfBuilder::visit(ASTVar &node) {
    // 使用 C++17 结构化绑定，直接获取 Value* 和 is_declared_const
    // 如果不支持 C++17，请使用 std::pair<Value*, bool> var_info = scope.find(node.id);
    // 然后再 Value *var = var_info.first; bool is_declared_const = var_info.second;
    auto [var, is_declared_const] = scope.find(node.id);

    // 检查 var 是否为 nullptr，以防 find 内部的 ASSERT 未触发或在某些情况下返回了 nullptr
    if (var == nullptr) {
        ASSERT(false && "Name not found in scope"); // 再次确认变量存在
        return nullptr;
    }

    // 获取 var 指向的元素类型，这里假设 var 是一个指针类型（如 int*, float*, int**）
    // var 本身是存储在 ALLOC 区域的变量的地址，所以它的类型是指针
    // get_pointer_element_type() 获取的是它所指向的实际数据类型
    Type *element_type = var->get_type()->get_pointer_element_type();
    auto is_int = element_type->is_integer_type();
    auto is_float = element_type->is_float_type();
    auto is_ptr = element_type->is_pointer_type(); // 例如，指向数组的指针

    bool should_return_lvalue = context.require_lvalue;
    Value *ret_val = nullptr;

    // 处理非数组变量 (node.length == 0 表示不是数组引用)
    if (node.length == 0) {
        if (should_return_lvalue) {
            // 如果需要左值 (例如用于赋值的左侧)
            ret_val = var; // 返回变量的地址
            context.require_lvalue = false; // 重置标志
        } else {
            // 如果不需要左值 (例如用于表达式求值)
            // 对常量的处理：只有当 context.is_const_exp 为 true 且变量本身被声明为常量时
            if (context.is_const_exp && is_declared_const) {
                // 如果是常量表达式，并且变量是常量
                // 此时 var 应该指向一个 ConstantInt 或 ConstantFP 类型的 Value
                // 我们直接从 var 中提取值，不再需要 find_const
                if (is_int) {
                    // 强制转换为 ConstantInt* 并获取其值
                    context.val.i_val = static_cast<ConstantInt*>(var)->get_value();
                    ret_val = CONST_INT((int)context.val.i_val);
                } else if (is_float) {
                    // 强制转换为 ConstantFP* 并获取其值 (注意：这里已将 ConstantFloat 改为 ConstantFP)
                    context.val.f_val = static_cast<ConstantFP*>(var)->get_value();
                    ret_val = CONST_FP(context.val.f_val);
                } else {
                    // 处理其他类型的常量（如果你的语言支持）
                    ASSERT(false && "Unsupported constant type (neither int nor float)");
                    return nullptr;
                }
            } else {
                // 对于非常量引用或者非常量表达式中的常量引用
                // 普通变量或数组变量的基地址，需要通过 load 获取其值
                if (is_int || is_float || is_ptr) {
                    ret_val = builder->create_load(var); // 从地址加载值
                } else {
                    // 数组变量名，表示整个数组的地址（如 int a[10]，这里的 var 是 int(*)[10] 类型）
                    // Cminusf 语法可能允许直接引用数组名为指针，或者需要解引用
                    // 这里创建一个 GEP (Get Element Pointer) 指令来获取数组的基地址
                    // {CONST_INT(0), CONST_INT(0)} 通常用于获取数组第一个元素的地址
                    // 第一个 0 用于跳过指向整个数组的指针，第二个 0 用于指向数组的第一个元素
                    ret_val = builder->create_gep(var, {CONST_INT(0), CONST_INT(0)});
                }
            }
        }
    }
    // 处理数组变量引用 (node.length > 0 表示有数组索引)
    else {
        Value *temp_val = var; // 从变量的地址开始
        if (!context.is_const_exp) {
            // 非常量表达式情况下的数组访问
            if (should_return_lvalue) {
                context.require_lvalue = false;
            }

            // 对于普通类型数组 (如 int[], float[])，只有一个索引
            if (is_int || is_float) {
                ASSERT(node.array_lists.size() == 1 && "Array index for non-pointer simple type should be 1D");
                auto *val_idx = node.array_lists[0]->accept(*this); // 访问索引表达式
                temp_val = builder->create_gep(temp_val, {val_idx}); // 计算元素地址
            }
            // 对于多维数组或数组指针 (如 int[][], int**)，可能有多个索引
            else {
                if (temp_val->get_type()->get_pointer_element_type()->is_pointer_type()) {
                    // 如果是数组指针（如参数传入的 int*），需要先 load 拿到实际的数组基地址
                    temp_val = builder->create_load(temp_val);
                    std::vector<Value *> args;
                    for (auto dim : node.array_lists) {
                        args.push_back(dim->accept(*this)); // 获取所有维度索引的值
                    }
                    temp_val = builder->create_gep(temp_val, args); // 计算元素地址
                } else {
                    // 对于 C 风格数组，第一个索引通常是 0（跳过数组本身）
                    std::vector<Value *> args;
                    args.push_back(CONST_INT(0)); // 用于数组本身，指向数组的第一个元素
                    for (auto dim : node.array_lists) {
                        args.push_back(dim->accept(*this)); // 获取所有维度索引的值
                    }
                    temp_val = builder->create_gep(temp_val, args); // 计算元素地址
                }
            }

            // 再次判断是否需要返回左值或右值
            if (should_return_lvalue) {
                ret_val = temp_val; // 返回计算后的元素地址
                context.require_lvalue = false;
            } else {
                // 如果计算出的 temp_val 仍然是一个数组类型（部分索引），则返回其基地址
                // 否则，从地址加载实际值
                if (temp_val->get_type()->get_pointer_element_type()->is_array_type()) {
                    // 返回子数组的基地址，例如 a[0] 可能是个 int[]
                    temp_val = builder->create_gep(temp_val, {CONST_INT(0), CONST_INT(0)});
                    ret_val = temp_val;
                } else {
                    ret_val = builder->create_load(temp_val); // 从元素地址加载值
                }
            }
        } else {
            // 常量表达式情况下的数组访问
            if (should_return_lvalue) {
                context.require_lvalue = false;
            }
            std::vector<unsigned> num_list;
            for (auto dim : node.array_lists) {
                dim->accept(*this); // 访问索引表达式，将其值放入 context.val.i_val
                num_list.push_back(context.val.i_val); // 收集所有索引值
            }

            // --- 核心修改：处理 ConstantArray 元素的获取 ---
            // 确保 var 是 ConstantArray*
            if (auto* const_array = dynamic_cast<ConstantArray*>(var)) {
                // 这里假设 num_list 提供了正确的扁平化索引或只有一个索引用于单维数组
                // 你可能需要根据你实际的 ConstantArray::get_element_value 接口和多维数组规则进行调整
                if (!num_list.empty()) {
                    int index = num_list[0]; // 假设索引为第一个元素，如果多维，需要计算实际偏移

                    // 从 ConstantArray 中获取指定索引的 Constant* 元素
                    Constant *element_const = const_array->get_element_value(index);

                    // 根据获取到的元素类型（ConstantInt 或 ConstantFP）提取值
                    if (auto* int_const = dynamic_cast<ConstantInt*>(element_const)) {
                        context.val.i_val = int_const->get_value();
                        ret_val = CONST_INT((int)context.val.i_val); // 构建 IR 常量
                    } else if (auto* fp_const = dynamic_cast<ConstantFP*>(element_const)) {
                        context.val.f_val = fp_const->get_value();
                        ret_val = CONST_FP(context.val.f_val); // 构建 IR 常量
                    } else {
                        ASSERT(false && "ConstantArray element is neither integer nor float constant.");
                        return nullptr;
                    }
                } else {
                    ASSERT(false && "Constant array accessed without index in constant expression.");
                    return nullptr;
                }
            } else {
                ASSERT(false && "Variable declared as const, but not a ConstantArray type when array accessed in constant expression.");
                return nullptr;
            }
        }
    }
    return ret_val;
}



Value *CminusfBuilder::visit(ASTNum &node)
{
    if (node.type == TYPE_INT)
    {
        context.val.i_val = node.i_val; 
        return CONST_INT(node.i_val);
    }
    else
    {

        context.val.f_val = node.f_val; 
        return CONST_FP(node.f_val);
    }
}

Value *CminusfBuilder::visit(ASTUnaryExp &node)
{
    if (node.call_exp != nullptr)
    {
        Value *ret_val;
        if (!context.logic_op)
        {
            context.logic_op = true;
            ret_val = node.call_exp->accept(*this);
            context.logic_op = false;
        }
        else
            ret_val = node.call_exp->accept(*this);
        if (!context.logic_op)
        {
            if (ret_val->get_type()->is_integer_type())
                ret_val = builder->create_icmp_eq(CONST_INT(0), ret_val);
            else
                ret_val = builder->create_fcmp_eq(CONST_FP(0.), ret_val);
            ret_val = builder->create_zext(ret_val, INT32_T);
            context.logic_op = true;
        }
        return ret_val;
    }
    if (node.primary_exp != nullptr)
    {
        Value *ret_val;
        if (!context.logic_op)
        {
            context.logic_op = true;
            ret_val = node.primary_exp->accept(*this);
            context.logic_op = false;
        }
        else
            ret_val = node.primary_exp->accept(*this);
        if (!context.logic_op)
        {
            if (ret_val->get_type()->is_integer_type())
                ret_val = builder->create_icmp_eq(CONST_INT(0), ret_val);
            else
                ret_val = builder->create_fcmp_eq(CONST_FP(0.), ret_val);
            ret_val = builder->create_zext(ret_val, INT32_T);
            context.logic_op = true;
        }
        return ret_val;
    }
    if (node.unary_exp != nullptr)
    {
        if (node.unary_op == OP_MINUS)
        {
            Value *ret_val = nullptr;
            auto *exp_val = node.unary_exp->accept(*this);
            auto *type = exp_val->get_type();
            if (type->is_integer_type())
            {
                context.val.i_val = -context.val.i_val;
                if (context.is_const_exp)
                    ret_val = CONST_INT((int)context.val.i_val);
                else if (scope.in_global())
                {
                    ret_val = CONST_INT((int)context.val.i_val);
                }
                else
                    ret_val = builder->create_isub(CONST_INT(0), exp_val);
            }
            else
            {
                context.val.f_val = -context.val.f_val;
                if (context.is_const_exp)
                    ret_val = CONST_FP(context.val.f_val);
                else if (scope.in_global())
                    ret_val = CONST_FP(context.val.f_val);
                else
                {
                    ret_val = builder->create_fsub(CONST_FP(0.), exp_val);
                }
            }
            return ret_val;
        }
        else if (node.unary_op == OP_NOT)
        {
            context.logic_op = (!context.logic_op);
        }
        else
        {
        }
        return node.unary_exp->accept(*this);
    }
    return nullptr;
}

Value *CminusfBuilder::visit(ASTAddExp &node)
{
    if (node.add_exp == nullptr)
    {
        return node.mul_exp->accept(*this);
    }
    const_val l_num, r_num;
    auto *l_val = node.add_exp->accept(*this);
    if (l_val->get_type()->is_integer_type())
        l_num.i_val = context.val.i_val;
    else
        l_num.f_val = context.val.f_val;
    auto *r_val = node.mul_exp->accept(*this);
    if (r_val->get_type()->is_integer_type())
        r_num.i_val = context.val.i_val;
    else
        r_num.f_val = context.val.f_val;
    bool is_int = promote(&l_val, &r_val, &l_num, &r_num);
    Value *ret_val = nullptr;
    switch (node.op)
    {
    case OP_ADD:
        if (is_int)
        {
            context.val.i_val = l_num.i_val + r_num.i_val;
            if (context.is_const_exp)
                ret_val = CONST_INT((int)context.val.i_val);
            else
                ret_val = builder->create_iadd(l_val, r_val);
        }
        else
        {
            context.val.f_val = l_num.f_val + r_num.f_val;
            if (context.is_const_exp)
                ret_val = CONST_FP(context.val.f_val);
            else
                ret_val = builder->create_fadd(l_val, r_val);
        }
        break;
    case OP_SUB:
        if (is_int)
        {
            context.val.i_val = l_num.i_val - r_num.i_val;
            if (context.is_const_exp)
                ret_val = CONST_INT((int)context.val.i_val);
            else
                ret_val = builder->create_isub(l_val, r_val);
        }
        else
        {
            context.val.f_val = l_num.f_val - r_num.f_val;
            if (context.is_const_exp)
                ret_val = CONST_FP(context.val.f_val);
            else
                ret_val = builder->create_fsub(l_val, r_val);
        }
    }
    return ret_val;
}

Value *CminusfBuilder::visit(ASTMulExp &node)
{
    if (node.mul_exp == nullptr)
    {
        return node.unary_exp->accept(*this);
    }
    const_val l_num, r_num;
    auto *l_val = node.mul_exp->accept(*this);
    if (l_val->get_type()->is_integer_type())
        l_num.i_val = context.val.i_val;
    else
        l_num.f_val = context.val.f_val;
    auto *r_val = node.unary_exp->accept(*this);
    if (r_val->get_type()->is_integer_type())
        r_num.i_val = context.val.i_val;
    else
        r_num.f_val = context.val.f_val;
    bool is_int = promote(&l_val, &r_val, &l_num, &r_num);
    Value *ret_val = nullptr;
    switch (node.op)
    {
    case OP_MUL:
        if (is_int)
        {
            context.val.i_val = l_num.i_val * r_num.i_val;
            if (context.is_const_exp)
                ret_val = CONST_INT((int)context.val.i_val);
            else
                ret_val = builder->create_imul(l_val, r_val);
        }
        else
        {
            context.val.f_val = l_num.f_val * r_num.f_val;
            if (context.is_const_exp)
                ret_val = CONST_FP(context.val.f_val);
            else
                ret_val = builder->create_fmul(l_val, r_val);
        }
        break;
    case OP_DIV:
        if (is_int)
        {
            if (context.is_const_exp)
            {
                if (r_num.i_val != 0) // TODO:
                    context.val.i_val = l_num.i_val / r_num.i_val;
                ret_val = CONST_INT((int)context.val.i_val);
            }
            else
                ret_val = builder->create_isdiv(l_val, r_val);
        }
        else
        {
            if (context.is_const_exp)
            {
                context.val.f_val = l_num.f_val / r_num.f_val;
                ret_val = CONST_FP(context.val.f_val);
            }
            else
                ret_val = builder->create_fdiv(l_val, r_val);
        }
        break;
        
    case OP_MOD:
    //     if (is_int)
    //     {
    //         if (context.is_const_exp)
    //         {
    //             if (r_num.i_val != 0)
    //                 context.val.i_val = l_num.i_val % r_num.i_val;
    //             ret_val = CONST_INT((int)context.val.i_val);
    //         }
    //         else
    //             ret_val = builder->create_isrem(l_val, r_val);
    //     }
    //     else
    //     {
    //         std::cerr << "Only integer can use mod instruction" << std::endl;
    //         std::cerr << "Wrong Type !" << std::endl;
    //         std::abort();
    //     }
        break;
    }

    // LOG(DEBUG) << "ASTMulExp_end";
    return ret_val;
}

Value *CminusfBuilder::visit(ASTRelExp &node)
{
    if (node.rel_exp == nullptr)
    {
        auto *ret_val = node.add_exp->accept(*this);
        return ret_val;
    }
    const_val l_num, r_num;
    auto *l_val = node.rel_exp->accept(*this);
    if (l_val->get_type()->is_integer_type())
    {
        if (l_val->get_type()->is_int1_type())
            l_val = builder->create_zext(l_val, INT32_T);
        l_num.i_val = context.val.i_val;
    }
    else
    {
        l_num.f_val = context.val.f_val;
    }
    auto *r_val = node.add_exp->accept(*this);
    if (r_val->get_type()->is_integer_type())
    {
        if (r_val->get_type()->is_int1_type())
            r_val = builder->create_zext(r_val, INT32_T);
        r_num.i_val = context.val.i_val;
    }
    else
        r_num.f_val = context.val.f_val;
    bool is_int = promote(&l_val, &r_val, &l_num, &r_num);
    Value *cmp;
    switch (node.op)
    {
    case OP_LT:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val < r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_lt(l_val, r_val);
        }
        else
        {
            context.val.i_val = (l_num.f_val < r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_lt(l_val, r_val);
        }
        break;
    case OP_LE:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val <= r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_le(l_val, r_val);
        }
        else
        {
            context.val.i_val = (l_num.f_val <= r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_le(l_val, r_val);
        }
        break;
    case OP_GT:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val > r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_gt(l_val, r_val);
        }
        else
        {
            context.val.i_val = (l_num.f_val > r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_gt(l_val, r_val);
        }
        break;
    case OP_GE:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val >= r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_ge(l_val, r_val);
        }
        else
        {
            context.val.i_val = (l_num.f_val >= r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_ge(l_val, r_val);
        }
        break;
    }
    return cmp;
}

Value *CminusfBuilder::visit(ASTEqExp &node)
{
    if (node.eq_exp == nullptr)
    {
        auto *ret_val = node.rel_exp->accept(*this);
        return ret_val;
    }
    const_val l_num, r_num;
    auto *l_val = node.eq_exp->accept(*this);
    if (l_val->get_type()->is_integer_type())
    {
        if (l_val->get_type()->is_int1_type())
            l_val = builder->create_zext(l_val, INT32_T);
        l_num.i_val = context.val.i_val;
    }
    else
        l_num.f_val = context.val.f_val;
    auto *r_val = node.rel_exp->accept(*this);
    if (r_val->get_type()->is_integer_type())
    {
        if (r_val->get_type()->is_int1_type())
            r_val = builder->create_zext(r_val, INT32_T);
        r_num.i_val = context.val.i_val;
    }
    else
        r_num.f_val = context.val.f_val;
    bool is_int = promote(&l_val, &r_val, &l_num, &r_num);
    Value *cmp;
    switch (node.op)
    {
    case OP_EQ:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val == r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_eq(l_val, r_val);
        }
        else
        {
            context.val.f_val = (l_num.f_val == r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_eq(l_val, r_val);
        }
        break;
    case OP_NEQ:
        if (is_int)
        {
            context.val.i_val = (l_num.i_val == r_num.i_val);
            if (context.is_const_exp)
                cmp = CONST_INT((int)context.val.i_val);
            else
                cmp = builder->create_icmp_ne(l_val, r_val);
        }
        else
        {
            context.val.i_val = (l_num.f_val != r_num.f_val);
            if (context.is_const_exp)
                cmp = CONST_FP(context.val.f_val);
            else
                cmp = builder->create_fcmp_ne(l_val, r_val);
        }
        break;
    }
    return cmp;
}

Value *CminusfBuilder::visit(ASTAndExp &node)
{
    Value *ret_val = nullptr;
    auto *true_bb = context.true_bb_stk.top();
    auto *false_bb = context.false_bb_stk.top();
    // 没有 && 逻辑
    if (node.land_exp == nullptr)
    {
        ret_val = node.eq_exp->accept(*this);
        if (ret_val->get_type()->is_int32_type())
            ret_val = builder->create_icmp_ne(CONST_INT(0), ret_val);
        else if (ret_val->get_type()->is_float_type())
            ret_val = builder->create_fcmp_ne(CONST_FP(0.), ret_val);
        ret_val = builder->create_cond_br(ret_val, true_bb, false_bb);
        // // LOG(INFO) << "reach here";
        return ret_val;
    }
    // LAndExp -> LAndExp && EqExp
    auto *mid_bb = BasicBlock::create(module.get(), "", context.func);

    context.true_bb_stk.push(mid_bb);
    context.false_bb_stk.push(false_bb);
    auto *l_val = node.land_exp->accept(*this);
    context.true_bb_stk.pop();
    context.false_bb_stk.pop();
    if (not builder->get_insert_block()->is_terminated())
        builder->create_cond_br(l_val, mid_bb, false_bb);

    builder->set_insert_point(mid_bb);
    // if (l_val->get_type()->is_int1_type())
    //     l_val = builder->create_zext(l_val, INT32_T);
    auto *r_val = node.eq_exp->accept(*this);
    if (r_val->get_type()->is_int32_type())
        r_val = builder->create_icmp_ne(CONST_INT(0), r_val);
    else if (r_val->get_type()->is_float_type())
        r_val = builder->create_fcmp_ne(CONST_FP(0.), r_val);
    builder->create_cond_br(r_val, true_bb, false_bb);
    // if (r_val->get_type()->is_int1_type())
    //     r_val = builder->create_zext(r_val, INT32_T);
    // auto *ret_val_true = builder->create_and(l_val, r_val);
    // if (ret_val_true->get_type()->is_int1_type())
    //     return builder->create_zext(ret_val_true, INT32_T);
    // LOG(DEBUG) << "ASTLAndExp_end";
    return nullptr;
}

Value *CminusfBuilder::visit(ASTOrExp &node)
{
    // // LOG(WARNING) << (context.is_const_exp ? 1 : 0);
    // // LOG(INFO) << context.is_const;
    // 这里不需要处理！逻辑
    // LOG(DEBUG) << "ASTLOrExp";

    // get true_bb and false_bb from upper astnode
    auto *true_bb = context.true_bb_stk.top();
    auto *false_bb = context.false_bb_stk.top();
    // 这一层并没有||,但需要给下层传递truebb和falsebb
    if (node.lor_exp == nullptr)
    {
        context.true_bb_stk.push(true_bb);
        context.false_bb_stk.push(false_bb);
        node.land_exp->accept(*this);
        context.true_bb_stk.pop();
        context.false_bb_stk.pop();
        return nullptr;
    }
    // 短路中间节点
    auto *mid_bb = BasicBlock::create(module.get(), "", context.func);
    // auto *next_bb = BasicBlock::create(module.get(), "", context.func);
    // LOrExp -> LOrExp || LAndExp
    // 左侧布尔表达式
    context.true_bb_stk.push(true_bb);
    context.false_bb_stk.push(mid_bb);
    node.lor_exp->accept(*this);
    context.true_bb_stk.pop();
    context.false_bb_stk.pop();

    builder->set_insert_point(mid_bb);
    // 右侧布尔表达式
    context.true_bb_stk.push(true_bb);
    context.false_bb_stk.push(false_bb);
    node.land_exp->accept(*this);
    context.true_bb_stk.pop();
    context.false_bb_stk.pop();
    return nullptr;
}

Value *CminusfBuilder::visit(ASTFuncExp &node) {
    // auto *func = dynamic_cast<Function *>(scope.find(node.id));
    std::pair<Value *, bool> func_info = scope.find(node.id);
    Value *found_val = func_info.first; // 这是实际的 Value*
    std::vector<Value *> args;
    // 参数类型转化
    Function *func = dynamic_cast<Function *>(found_val);
    auto param_type = func->get_function_type()->param_begin();
    for (auto &arg : node.args)
    {
        auto *arg_val = arg->accept(*this);
        // 非数组类型, 转化为相应类型
        // // LOG(WARNING) << arg_val->get_type()->print();
        if (!arg_val->get_type()->is_array_type() && *param_type != arg_val->get_type())
        {
            if (arg_val->get_type()->is_pointer_type())
            {
                args.push_back(arg_val);
                param_type++;
                continue;
            }
            if (arg_val->get_type()->is_integer_type())
                arg_val = builder->create_sitofp(arg_val, FLOAT_T);
            else
                arg_val = builder->create_fptosi(arg_val, INT32_T);
        }
        args.push_back(arg_val);
        param_type++;
    }
    for (auto arg : args)
    {
        // LOG(INFO) << arg->get_type()->print();
        // LOG(INFO) << arg->print();
    }
    auto *ret_val = builder->create_call(static_cast<Function *>(func), args);

    return ret_val;
}

Value *CminusfBuilder::visit(ASTCompoundAssignStmt &node) { return nullptr; }


// Value *CminusfBuilder::visit(ASTAssignStmt &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTCompoundAssignStmt &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTSelectionStmt &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTIterationStmt &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTBreak &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTContinue &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTReturnStmt &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTVar &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTNum &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTUnaryExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTFuncExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTAddExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTMulExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTRelExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTEqExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTAndExp &node) { return nullptr; }
// Value *CminusfBuilder::visit(ASTOrExp &node) { return nullptr; }