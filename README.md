
# Compiler for the C Language 
This project contains an implementation of a compiler for the C language. The compiler emits LLVM IR for the input program which can be interpreted using the LLVM Interpreter ```lli``` or compiled using the LLVM Compiler ```llc```.

## Using the Compiler 
To compile a program, first build the compiler from the source files using ```make```. Then, run the following command: 

    >> ./cc <filename> <outfile> <0/1 for dumping AST> 
    <0/1 for code optimization> <0/1 for dumping optimized AST>

The output file is ```outfile```. For the sake of convention, the outfile may be named as ```<filename>.ll```. 

The output file may be run using the ```lli``` interpreter for LLVM IR. The interpreter may be called as

    >> lli <filename>.ll

## Components
This compiler is a large project consisting of the following components:

1. **Lexer**: The lexer has been implemented using Lex. The implementation is contained in the ```c.lex``` file.

2. **Parser**: The parser has been implemented using Bison. The implementation is contained in the ```c.y``` file. The code for the generation of the Abstract Syntax Tree (AST) is also contained within this file. The AST generation uses the functionality of specifying semantics corresponding to production rules inbuilt in Bison.

3. **Scope Checker**: The scope checker performs a semantic check on the code to ensure that variables are correctly scoped: each variable is declared in the scope before use, there are no double declarations, etc. The implementation is contained in ```Scope.cpp``` file. 

4. **Type Checker**: The type checker also performs a semantic check on the code. It ensures that expressions and statements in the code are well typed and agree with the typing rules of the language. The implementation is contained in the ```TypeChecker.cpp``` file. 

5. **Code Generator**: The code generator emits code written in LLVM IR, which is machine independent, and can be compiled using ```llc``` or interpreted using the LLVM interpreter ```lli```. LLVM Optimization passes can then be run on this generated code. The implementation is contained in the ```CodeGen.cpp``` file. 

6. **Optimizer**: The optimizer can either run on the AST or the generated code. The objective is to tweak the code to ensure that the runtime of programs is as fast as possible. 

## Features 
Some extra features in addition to Parts 1-4 specified in the lab are as follows:

1. **Arrays:** Support for local and global arrays has been added to the compiler. Arrays may also be passed by reference to functions. 

2. **For Loops:** There is also support for C-style for loops. 

3. **Type Checking:** As mentioned in the components above, type checking on the AST for statements and expressions has also been implemented. 

There are some extra tests which have been added in the examples subdirectory. Interested readers may run the compiler on them and observe the output.

### Acknowledgements
---
1. The C language grammar (c.y and c.l files) have been taken from: http://www.quut.com/c/ANSI-C-grammar-y-2011.html
2. Code Generation using LLVM Tutorial: https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html
