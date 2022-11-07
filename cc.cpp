#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "c.tab.hpp"
#include <iostream>
#include <string>
#include "Scope.hpp"
#include "TypeChecker.hpp"
#include "Optimizer.hpp"
#include "CodeGen.hpp"


extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
extern "C" ASTNode *AST;

static void usage()
{
  std::cout << "CC - C Compiler" << std::endl;
  std::cout << "-----------------------" << std::endl;
  std::cout << "Usage: ./cc <filename> <outfile> <0/1 for dumping AST> <0/1 for code optimization> <0/1 for dumping optimized AST>" << std::endl; 
}

int
main(int argc, char **argv)
{
    if (argc < 3) {
      usage();
      exit(1);
    }

    char const *filename = argv[1];
    char const *outfile = argv[2];
    int dump_ast = 0;
    int optimize = 0;
    int dump_opt = 0;

    if (argc > 3) {
      dump_ast = atoi(argv[3]);
    }
    if (argc > 4) {
      optimize = atoi(argv[4]);
    }
    if (argc > 5) {
      dump_opt = atoi(argv[5]);
    }

    yyin = fopen(filename, "r");
    assert(yyin);

    int ret = yyparse();
    if (dump_ast == 1) { 
      AST->printAST();
    }

    // Scope Checking
    ScopeStack scopes = ScopeStack();
    bool scopechk = scopes.check_node(AST, false);
    if (!scopechk) {
      std::cout << "Scoping check failed." << std::endl;
      ret = 1;
      printf("retv = %d\n", ret);
      exit(1);
    }
    

    TypeChecker tcheck = TypeChecker();
    int typecheck = 0;
    typecheck = tcheck.check_node(AST);
    if (typecheck < 0) {
      std::cout << "Program failed the typing check..." << std::endl; 
      ret = 1;
      printf("retv = %d\n", ret);
      exit(1);
    }

    
    if (optimize == 1) {
      Optimizer optimizer = Optimizer();

      optimizer.optimizeAST(AST);
      std::cout << "Optimized the AST! " << std::endl;
      if (dump_opt == 1) { 
        AST->printAST();
      }
    }

    CodeGen cgen = CodeGen();
    cgen.TreeCodeGen(AST, outfile);
    
    printf("retv = %d\n", ret);
    exit(0);
}
