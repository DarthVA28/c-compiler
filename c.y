%code requires {
	#include <iostream>
	#include "ASTNode.hpp"
	#include <string>
	using namespace std;
}

%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "ASTNode.hpp"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

ASTNode* AST = NULL;

%}

%union {
	ASTNode* node;
	ASTNodeList* nodelist;
	int ival;
	float fval;
	char* sval;
	// vector<ASTNode*> nodelist;
}

/* Token Declarations */

%token <sval> STRING_LITERAL IDENTIFIER ELLIPSIS
%token <ival> I_CONSTANT 
%token <fval> F_CONSTANT 
%token <node> FUNC_NAME SIZEOF
%token <node> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <node> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <node> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <node> XOR_ASSIGN OR_ASSIGN
%token <node> TYPEDEF_NAME ENUMERATION_CONSTANT
%token <node> TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token <node> CONST RESTRICT VOLATILE
%token <node> BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token <node> COMPLEX IMAGINARY 
%token <node> STRUCT UNION ENUM 
%token <node> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token <node> ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

/* Non Terminal Semantic Value Declarations */
%type <nodelist> translation_unit expression init_declarator_list argument_expression_list
%type <nodelist> parameter_type_list parameter_list identifier_list block_item_list initializer_list

%type <node> primary_expression type_specifier constant enumeration_constant string
%type <node> start_state  external_declaration function_definition 
%type <node> declaration_list declaration_specifiers declaration
%type <node> direct_declarator parameter_declaration declarator init_declarator
%type <node> compound_statement block_item statement type_qualifier
%type <node> expression_statement jump_statement 
%type <node> labeled_statement selection_statement iteration_statement
%type <node> postfix_expression unary_expression unary_operator cast_expression
%type <node> multiplicative_expression additive_expression shift_expression relational_expression
%type <node> equality_expression and_expression exclusive_or_expression inclusive_or_expression
%type <node> logical_and_expression logical_or_expression conditional_expression
%type <node> assignment_expression assignment_operator constant_expression initializer

%type <ival> pointer


%start start_state
%%

/* Standard Nonterminals */ 
start_state
	: translation_unit {ASTNode* root = new ASTNode(ASTNode::TRANSLATION_UNIT, "START"); $$ = root; 
	for(int i = 0; i < $1->getLength(); i++) {
			$$->addChild($1->get(i));
		}
	AST = $$;}
	;

primary_expression
	: IDENTIFIER {$$ = new ASTNode(ASTNode::ID, $1);}
	| constant {$$ = $1;}
	| string {$$ = $1;}
	| '(' expression ')' {$$ = ($2->get(0));}
	| generic_selection
	;

type_specifier
	: VOID 		{$$ = new ASTNode(ASTNode::TYPE, "VOID");}
	| CHAR 		{$$ = new ASTNode(ASTNode::TYPE, "CHAR");}
	| SHORT 	{$$ = new ASTNode(ASTNode::TYPE, "SHORT");}
	| INT 		{$$ = new ASTNode(ASTNode::TYPE, "INT");}
	| LONG 		{$$ = new ASTNode(ASTNode::TYPE, "LONG");}
	| FLOAT 	{$$ = new ASTNode(ASTNode::TYPE, "FLOAT");}
	| DOUBLE 	{$$ = new ASTNode(ASTNode::TYPE, "DOUBLE");}
	| SIGNED 	{$$ = new ASTNode(ASTNode::TYPE, "SIGNED");}
	| UNSIGNED 	{$$ = new ASTNode(ASTNode::TYPE, "UNSIGNED");}
	| BOOL 		{$$ = new ASTNode(ASTNode::TYPE, "BOOL");}
	| COMPLEX 	{$$ = new ASTNode(ASTNode::TYPE, "COMPLEX");}
	| IMAGINARY	  	/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */
	;

constant
	: I_CONSTANT		{$$ = new ASTNode(ASTNode::ICONST, $1);}
	| F_CONSTANT		{$$ = new ASTNode(ASTNode::FCONST, $1);}
	| STRING_LITERAL 	{
	std::string s = $1;
	std::size_t pos = s.find("\\n");
    if (pos != std::string::npos) {
		s.replace(pos, 2, "\n");
	}
    
	$$ = new ASTNode(ASTNode::SCONST, s);}
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		
	: IDENTIFIER {$$ = new ASTNode(ASTNode::TYPE, $1);} /* before it has been defined as such */
	;


unary_operator
	: '&' {$$ = new ASTNode(ASTNode::UNOP, "&");}
	| '*' {$$ = new ASTNode(ASTNode::UNOP, "*");}
	| '+' {$$ = new ASTNode(ASTNode::UNOP, "+");}
	| '-' {$$ = new ASTNode(ASTNode::UNOP, "-");}
	| '~' {$$ = new ASTNode(ASTNode::UNOP, "~");}
	| '!' {$$ = new ASTNode(ASTNode::UNOP, "!");}
	;

string
	: FUNC_NAME 
	/* | FUNC_NAME */
	;

/* Function NTerms */

translation_unit
	: external_declaration {$$ = new ASTNodeList($1);}
	| translation_unit external_declaration {$1->add($2); $$ = $1;}
	;

external_declaration
	: function_definition {$$ = $1;}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {$$ = new ASTNode(ASTNode::FUNC, "FUNCTION"); $$->addChild($1); $$->addChild($2); $$->addChild($3); $$->addChild($4);}
	| declaration_specifiers declarator compound_statement {$$ = new ASTNode(ASTNode::FUNC, "FUNCTION"); $$->addChild($1); $$->addChild($2); $$->addChild($3); }
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier {$$ = $1;}
	| type_qualifier declaration_specifiers
	| type_qualifier {$$ = $1;}
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;

/* declaration: */
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';' {
		$$ = new ASTNode(ASTNode::VARDEC, "DECL");
		$$->addChild($1);
		for(int i = 0; i < $2->getLength(); i++) {
			$$->addChild($2->get(i));
		}
	}
	| static_assert_declaration
	;

declarator
	: pointer direct_declarator {int np = $1;
	ASTNode* tmp = new ASTNode(ASTNode::POINTER, "POINTER");
	$$ = tmp;
	ASTNode* tmp1;
	for(int i = 0; i < np-1; i++) {
		tmp1 = new ASTNode(ASTNode::POINTER, "POINTER");
		tmp->addChild(tmp1);
		tmp = tmp1;
	}
	tmp -> addChild($2);
	}
	| direct_declarator {$$ = $1;}
	;

direct_declarator
	: IDENTIFIER {$$ = new ASTNode(ASTNode::ID, $1);}
	| '(' declarator ')'
	| direct_declarator '[' ']' {$$ = new ASTNode(ASTNode::ARRAY, "ARRAY"); $$->addChild($1); }
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']' 
	{$$ = new ASTNode(ASTNode::ARRAY, "ARRAY"); $$->addChild($1); $$->addChild($3);
	}

	| direct_declarator '(' parameter_type_list ')' {$$ = new ASTNode(ASTNode::FUNCDEF, "FUNCDEF"); 
	$$->addChild($1); 
	for(int i = 0; i < $3->getLength(); i++) {
			$$->addChild($3->get(i));
		}
	}
	| direct_declarator '(' ')' {$$ = new ASTNode(ASTNode::FUNCDEF, "FUNCDEF"); 
	$$->addChild($1); 
	}
	| direct_declarator '(' identifier_list ')'
	;

init_declarator_list
	: init_declarator {$$ = new ASTNodeList($1);}
	| init_declarator_list ',' init_declarator {$1->add($3); $$ = $1;}
	;

init_declarator
	: declarator '=' initializer {ASTNode* tmp = new ASTNode(ASTNode::ASSIGNEXP, "="); $$ = new ASTNode(ASTNode::ASSIGNEXP, "ASSIGN", $1, tmp, $3);}
	| declarator {$$ = $1;}
	;

parameter_type_list
	: parameter_list ',' ELLIPSIS {$$ = $1; ASTNode* moreparam = new ASTNode(ASTNode::ID, $3); $$->add(moreparam);}
	| parameter_list {$$ = $1;}
	;

parameter_list
	: parameter_declaration {$$ = new ASTNodeList($1);}
	| parameter_list ',' parameter_declaration {$1->add($3); $$ = $1;}
	;

parameter_declaration
	: declaration_specifiers IDENTIFIER {$$ = new ASTNode(ASTNode::PARAMETER, "PARAM"); $$->addChild($1); ASTNode* id = new ASTNode(ASTNode::ID, $2); $$->addChild(id);}
	| declaration_specifiers pointer IDENTIFIER {$$ = new ASTNode(ASTNode::PARAMETER, "PARAM"); 
	int ptrs = $2;
	for(int i =0; i<ptrs; i++){
		$1->repr = $1->repr + "*";
	}
	$$->addChild($1); 
	ASTNode* id = new ASTNode(ASTNode::ID, $3); $$->addChild(id);}
	| declaration_specifiers abstract_declarator 
	| declaration_specifiers
	| declaration_specifiers IDENTIFIER '[' ']' {$$ = new ASTNode(ASTNode::PARAMETER, "PARAM"); $$->addChild($1); ASTNode* id = new ASTNode(ASTNode::ID, $2); ASTNode* arr = new ASTNode(ASTNode::ARRAY, "ARRAY"); arr->addChild(id); $$->addChild(arr);}
	;
	
compound_statement
	: '{' '}' {$$ = new ASTNode(ASTNode::BLOCK, "STBLOCK"); }
	| '{'  block_item_list '}' {$$ = new ASTNode(ASTNode::BLOCK, "STBLOCK");
		for(int i = 0; i < $2->getLength(); i++) {
			$$->addChild($2->get(i));
		}
	}
	;

block_item_list
	: block_item {$$ = new ASTNodeList($1);}
	| block_item_list block_item {$1->add($2); $$ = $1;}
	;

block_item
	: declaration {$$ = $1;}
	| statement {$$ = $1;}
	;

statement
	: labeled_statement {$$ = $1;}
	| compound_statement {$$ = $1;}
	| expression_statement {$$ = $1;}
	| selection_statement {$$ = $1;}
	| iteration_statement {$$ = $1;}
	| jump_statement {$$ = $1;}
	;

expression_statement
	: ';' 
	| expression ';' {$$ = new ASTNode(ASTNode::EXPRESSION, "EXPBLOCK");
		for(int i = 0; i < $1->getLength(); i++) {
			$$->addChild($1->get(i));
		}
	}
	;

labeled_statement
	: IDENTIFIER ':' statement {$$ = new ASTNode(ASTNode::LABEL, $1); $$->addChild($3);}
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement {$$ = new ASTNode(ASTNode::ITE, "ITE"); 
		$$->addChild($3->get(0));
		$$->addChild($5); $$->addChild($7);
	}
	| IF '(' expression ')' statement {$$ = new ASTNode(ASTNode::ITE, "ITE"); 
		$$->addChild($3->get(0)); $$->addChild($5);
	}
	| SWITCH '(' expression ')' statement 
	;

iteration_statement
	: WHILE '(' expression ')' statement { $$ = new ASTNode(ASTNode::WHILE, "WHILE");
		$$->addChild($3->get(0));
		$$->addChild($5); 
	}
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement { $$ = new ASTNode(ASTNode::FOR, "FOR");
		$$->addChild($3);
		$$->addChild($4); 
		$$->addChild($5->get(0));
		$$->addChild($7); 
	}
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';' {$$ = new ASTNode(ASTNode::GOTO, "GOTO"); ASTNode* temp = new ASTNode(ASTNode::ID, $2); $$->addChild(temp);}
	| CONTINUE ';'
	| BREAK ';' 
	| RETURN ';' {}
	| RETURN expression ';' {$$ = new ASTNode(ASTNode::RETURN, "RETURN"); $$-> addChild($2->get(0));}
	;

/* expression: Expressions */

postfix_expression
	: primary_expression  {$$ = $1;}
	| postfix_expression '[' expression ']' {$$ = new ASTNode(ASTNode::ARRELEM, $1->repr);  
	ASTNode* tmp = new ASTNode(ASTNode::EXPRESSION, "INDEX");
	for(int i = 0; i < $3->getLength(); i++) {
		tmp->addChild($3->get(i));
	}
	$$->addChild(tmp);}
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')' {$$ = new ASTNode(ASTNode::FUNCALL, "FUNCALL");
		$$->addChild($1);
		for(int i = 0; i < $3->getLength(); i++) {
			$$->addChild($3->get(i));
		}
	}
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP {$$ = new ASTNode(ASTNode::UNEXP, "POSTINCR", $1);} 
	| postfix_expression DEC_OP {$$ = new ASTNode(ASTNode::UNEXP, "POSTDECR", $1);} 
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

// FUNCTION CALLS
argument_expression_list
	: assignment_expression {$$ = new ASTNodeList($1);}
	| argument_expression_list ',' assignment_expression {$1->add($3); $$ = $1;}
	;

unary_expression
	: postfix_expression {$$ = $1;}
	| INC_OP unary_expression {$$ = new ASTNode(ASTNode::UNEXP, "++", $2);} 
	| DEC_OP unary_expression {$$ = new ASTNode(ASTNode::UNEXP, "--", $2);} 
	| unary_operator cast_expression 
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	| ALIGNOF '(' type_name ')'
	;

cast_expression
	: unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression 
	;

multiplicative_expression
	: cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression {$$ = new ASTNode(ASTNode::BINEXP, "TIMES", $1, $3);} 
	| multiplicative_expression '/' cast_expression {$$ = new ASTNode(ASTNode::BINEXP, "DIV", $1, $3);} 
	| multiplicative_expression '%' cast_expression {$$ = new ASTNode(ASTNode::BINEXP, "MOD", $1, $3);} 
	;

additive_expression
	: multiplicative_expression {$$ = $1;}
	| additive_expression '+' multiplicative_expression {$$ = new ASTNode(ASTNode::BINEXP, "PLUS", $1, $3);} 
	| additive_expression '-' multiplicative_expression {$$ = new ASTNode(ASTNode::BINEXP, "MINUS", $1, $3);} 
	;

shift_expression
	: additive_expression {$$ = $1;}
	| shift_expression LEFT_OP additive_expression {$$ = new ASTNode(ASTNode::BINEXP, "<<", $1, $3);} 
	| shift_expression RIGHT_OP additive_expression {$$ = new ASTNode(ASTNode::BINEXP, ">>", $1, $3);} 
	;

relational_expression
	: shift_expression {$$ = $1;}
	| relational_expression '<' shift_expression {$$ = new ASTNode(ASTNode::BINEXP, "LT", $1, $3);} 
	| relational_expression '>' shift_expression {$$ = new ASTNode(ASTNode::BINEXP, "GT", $1, $3);} 
	| relational_expression LE_OP shift_expression {$$ = new ASTNode(ASTNode::BINEXP, "LE", $1, $3);} 
	| relational_expression GE_OP shift_expression {$$ = new ASTNode(ASTNode::BINEXP, "GE", $1, $3);} 
	;

equality_expression
	: relational_expression {$$ = $1;}
	| equality_expression EQ_OP relational_expression {$$ = new ASTNode(ASTNode::BINEXP, "EQ", $1, $3);} 
	| equality_expression NE_OP relational_expression {$$ = new ASTNode(ASTNode::BINEXP, "NEQ", $1, $3);} 
	;

and_expression
	: equality_expression {$$ = $1;}
	| and_expression '&' equality_expression {$$ = new ASTNode(ASTNode::BINEXP, "&", $1, $3);} 
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {$$ = new ASTNode(ASTNode::BINEXP, "XOR", $1, $3);} 
	;

inclusive_or_expression
	: exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new ASTNode(ASTNode::BINEXP, "IOR", $1, $3);} 
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression {$$ = new ASTNode(ASTNode::BINEXP, "AND", $1, $3);} 
	;

logical_or_expression
	: logical_and_expression {$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression {$$ = new ASTNode(ASTNode::BINEXP, "OR", $1, $3);} 
	;

conditional_expression
	: logical_or_expression {$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression {$$ = $1;}
	| unary_expression assignment_operator assignment_expression {$$ = new ASTNode(ASTNode::ASSIGNEXP, "ASSIGN", $1, $2, $3);}
	;

assignment_operator
	: '=' 			{$$ = new ASTNode(ASTNode::ASSIGNEXP, "=");}
	| MUL_ASSIGN 	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "*=");}
	| DIV_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "/=");}
	| MOD_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "%=");}
	| ADD_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "+=");}
	| SUB_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "-=");}
	| LEFT_ASSIGN	
	| RIGHT_ASSIGN	
	| AND_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "&=");}
	| XOR_ASSIGN	{$$ = new ASTNode(ASTNode::ASSIGNEXP, "^=");}
	| OR_ASSIGN		{$$ = new ASTNode(ASTNode::ASSIGNEXP, "|=");}
	;

expression
	: assignment_expression  {$$ = new ASTNodeList($1);}
	| expression ',' assignment_expression {$1->add($3); $$ = $1;}
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;


struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: ':' constant_expression
	| declarator ':' constant_expression
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator	
	: enumeration_constant '=' constant_expression /* identifiers must be flagged as ENUMERATION_CONSTANT */
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	;

function_specifier
	: INLINE
	| NORETURN
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer {$$ = $2 + 1;}
	| '*' {$$ = 1;}
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;


initializer
	: '{' initializer_list '}' {	
		$$ = new ASTNode(ASTNode::LIST, "LIST");	
		for(int i = 0; i < $2->getLength(); i++) {
			$$->addChild($2->get(i));
		}
		}
	| '{' initializer_list ',' '}'
	| assignment_expression {$$ = $1;}
	;

initializer_list
	: designation initializer
	| initializer {$$ = new ASTNodeList($1);}
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer {$1->add($3); $$ = $1;}
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}

void replace_first(std::string& s, std::string const& toReplace, std::string const& replaceWith) {
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return;
    s.replace(pos, toReplace.length(), replaceWith);
}
