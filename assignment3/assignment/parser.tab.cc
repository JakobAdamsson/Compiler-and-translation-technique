// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 22 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  
  Node* root;
  extern int yylineno;
  

#line 57 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 130 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
      case symbol_kind::S_LRArguments: // LRArguments
      case symbol_kind::S_LRVarOrStatementDec: // LRVarOrStatementDec
      case symbol_kind::S_LRMethodDec: // LRMethodDec
      case symbol_kind::S_StateEpsilon: // StateEpsilon
      case symbol_kind::S_LRClassDec: // LRClassDec
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_EQUALSIGN: // EQUALSIGN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_TOKEN_DOLLAR: // TOKEN_DOLLAR
      case symbol_kind::S_TOKEN_CARET: // TOKEN_CARET
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
      case symbol_kind::S_LRArguments: // LRArguments
      case symbol_kind::S_LRVarOrStatementDec: // LRVarOrStatementDec
      case symbol_kind::S_LRMethodDec: // LRMethodDec
      case symbol_kind::S_StateEpsilon: // StateEpsilon
      case symbol_kind::S_LRClassDec: // LRClassDec
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_EQUALSIGN: // EQUALSIGN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_TOKEN_DOLLAR: // TOKEN_DOLLAR
      case symbol_kind::S_TOKEN_CARET: // TOKEN_CARET
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
      case symbol_kind::S_LRArguments: // LRArguments
      case symbol_kind::S_LRVarOrStatementDec: // LRVarOrStatementDec
      case symbol_kind::S_LRMethodDec: // LRMethodDec
      case symbol_kind::S_StateEpsilon: // StateEpsilon
      case symbol_kind::S_LRClassDec: // LRClassDec
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_EQUALSIGN: // EQUALSIGN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_TOKEN_DOLLAR: // TOKEN_DOLLAR
      case symbol_kind::S_TOKEN_CARET: // TOKEN_CARET
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
      case symbol_kind::S_LRArguments: // LRArguments
      case symbol_kind::S_LRVarOrStatementDec: // LRVarOrStatementDec
      case symbol_kind::S_LRMethodDec: // LRMethodDec
      case symbol_kind::S_StateEpsilon: // StateEpsilon
      case symbol_kind::S_LRClassDec: // LRClassDec
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_EQUALSIGN: // EQUALSIGN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_TOKEN_DOLLAR: // TOKEN_DOLLAR
      case symbol_kind::S_TOKEN_CARET: // TOKEN_CARET
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
      case symbol_kind::S_LRArguments: // LRArguments
      case symbol_kind::S_LRVarOrStatementDec: // LRVarOrStatementDec
      case symbol_kind::S_LRMethodDec: // LRMethodDec
      case symbol_kind::S_StateEpsilon: // StateEpsilon
      case symbol_kind::S_LRClassDec: // LRClassDec
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_EQUALSIGN: // EQUALSIGN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_TOKEN_DOLLAR: // TOKEN_DOLLAR
      case symbol_kind::S_TOKEN_CARET: // TOKEN_CARET
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: Program
#line 58 "parser.yy"
             {root = yystack_[0].value.as < Node * > ();}
#line 841 "parser.tab.cc"
    break;

  case 3: // Program: Goal
#line 64 "parser.yy"
            {
              
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 850 "parser.tab.cc"
    break;

  case 4: // Program: Program ClassDeclaration
#line 69 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 859 "parser.tab.cc"
    break;

  case 5: // Type: INT
#line 75 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Int", "", yylineno, "Int");
            }
#line 867 "parser.tab.cc"
    break;

  case 6: // Type: BOOLEAN
#line 80 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno,"Boolean");
            }
#line 875 "parser.tab.cc"
    break;

  case 7: // Type: ID
#line 84 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), yystack_[0].value.as < std::string > (), yylineno, yystack_[0].value.as < std::string > ());
            }
#line 883 "parser.tab.cc"
    break;

  case 8: // Type: INT LBRACKET RBRACKET
#line 88 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArr", "Int", yylineno,"IntArr");
            }
#line 891 "parser.tab.cc"
    break;

  case 9: // VarDeclaration: Type ID SEMICOLON
#line 92 "parser.yy"
            {
              // CHANGED THIS MIGHT DESTROY SOMETHING ELSE
              std::string dtype = yystack_[2].value.as < Node * > ()->type;
              // CHANGE TO $2 IF THIS BUGS!
              yylhs.value.as < Node * > () = new Node("VarDeclaration",yystack_[1].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

              //$$->children.push_back(new Node("ID", $2, yylineno,dtype));
            }
#line 905 "parser.tab.cc"
    break;

  case 10: // Expression: Term
#line 104 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 913 "parser.tab.cc"
    break;

  case 11: // Expression: Expression DOT ID LPAREN RPAREN
#line 108 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("FCall", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              //$$->children.push_back(new Node("Dot", "", yylineno, $3));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno,"Method"));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Arguments", "", yylineno));
            }
#line 925 "parser.tab.cc"
    break;

  case 12: // Expression: Expression DOT ID LPAREN LRArguments RPAREN
#line 116 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("FCall", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              //$$->children.push_back(new Node("Dot", "", yylineno, $3));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno,"Method"));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 937 "parser.tab.cc"
    break;

  case 13: // Expression: Expression AND Expression
#line 124 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("And", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 947 "parser.tab.cc"
    break;

  case 14: // Expression: Expression OR Expression
#line 130 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Or", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 957 "parser.tab.cc"
    break;

  case 15: // Expression: Expression LT Expression
#line 136 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Lt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 967 "parser.tab.cc"
    break;

  case 16: // Expression: Expression GT Expression
#line 142 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Gt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 977 "parser.tab.cc"
    break;

  case 17: // Expression: Expression EQ Expression
#line 148 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("==", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 987 "parser.tab.cc"
    break;

  case 18: // Expression: Expression PLUS Expression
#line 154 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Plus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              //$$->children.push_back(new Node("PLUS", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 998 "parser.tab.cc"
    break;

  case 19: // Expression: Expression MINUS Expression
#line 161 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Minus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1008 "parser.tab.cc"
    break;

  case 20: // Expression: Expression TIMES Expression
#line 167 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Mult", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1018 "parser.tab.cc"
    break;

  case 21: // Expression: Expression DIVIDE Expression
#line 173 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Divide", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1028 "parser.tab.cc"
    break;

  case 22: // Expression: Expression LBRACKET Expression RBRACKET
#line 179 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1038 "parser.tab.cc"
    break;

  case 23: // Expression: Expression DOT LENGTH
#line 185 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();

              yylhs.value.as < Node * > ()->children.push_back(new Node("Lenght", "", yylineno,"Int"));
            }
#line 1048 "parser.tab.cc"
    break;

  case 24: // Term: NUM
#line 192 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Num", yystack_[0].value.as < std::string > (), yylineno, "Int");
            }
#line 1056 "parser.tab.cc"
    break;

  case 25: // Term: TRUE
#line 196 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node( "Boolean","True", yylineno, "Boolean");
            }
#line 1064 "parser.tab.cc"
    break;

  case 26: // Term: FALSE
#line 200 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Boolean", "False", yylineno, "Boolean");
            }
#line 1072 "parser.tab.cc"
    break;

  case 27: // Term: ID
#line 204 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);

            }
#line 1081 "parser.tab.cc"
    break;

  case 28: // Term: THIS
#line 209 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("this", "", yylineno);
            }
#line 1089 "parser.tab.cc"
    break;

  case 29: // Term: NEW INT LBRACKET Expression RBRACKET
#line 213 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("New", "Int", yylineno, "Int"));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Int", "Int", yylineno, "Int"));

              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1101 "parser.tab.cc"
    break;

  case 30: // Term: NEW ID LPAREN RPAREN
#line 221 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("NewVar", yystack_[2].value.as < std::string > (), yylineno, yystack_[2].value.as < std::string > ());
              //$$->children.push_back(new Node("New", "", yylineno));
              //$$->children.push_back(new Node("Identifier", $2, yylineno, "Class"));
            }
#line 1111 "parser.tab.cc"
    break;

  case 31: // Term: NOT Expression
#line 227 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Not", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1120 "parser.tab.cc"
    break;

  case 32: // Term: LPAREN Expression RPAREN
#line 232 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1128 "parser.tab.cc"
    break;

  case 33: // Statement: LBRACE LRStatement RBRACE
#line 236 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1136 "parser.tab.cc"
    break;

  case 34: // Statement: RBRACE LBRACE
#line 240 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
            }
#line 1144 "parser.tab.cc"
    break;

  case 35: // Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
#line 244 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrModifier", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              //$$->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

            }
#line 1157 "parser.tab.cc"
    break;

  case 36: // Statement: ID EQUALSIGN Expression SEMICOLON
#line 253 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
              //$$->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1168 "parser.tab.cc"
    break;

  case 37: // Statement: PRINT LPAREN Expression RPAREN SEMICOLON
#line 260 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1177 "parser.tab.cc"
    break;

  case 38: // Statement: WHILE LPAREN Expression RPAREN Statement
#line 265 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1187 "parser.tab.cc"
    break;

  case 39: // Statement: IF LPAREN Expression RPAREN Statement StateEpsilon
#line 271 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("If statement", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1198 "parser.tab.cc"
    break;

  case 40: // MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
#line 278 "parser.yy"
            {
              std::string dtype = yystack_[10].value.as < Node * > ()->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[9].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Public", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[9].value.as < std::string > (), yylineno, yystack_[10].value.as < Node * > ()->dtype));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1214 "parser.tab.cc"
    break;

  case 41: // MethodDeclaration: PUBLIC Type ID LPAREN RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
#line 290 "parser.yy"
            {
              std::string dtype = yystack_[9].value.as < Node * > ()->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[8].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Public", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[8].value.as < std::string > (), yylineno, yystack_[9].value.as < Node * > ()->dtype));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1229 "parser.tab.cc"
    break;

  case 42: // MethodDeclaration: PUBLIC Type ID LPAREN RPAREN LBRACE RETURN Expression SEMICOLON RBRACE
#line 301 "parser.yy"
            {
              std::string dtype = yystack_[8].value.as < Node * > ()->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[7].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Public", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[7].value.as < std::string > (), yylineno, yystack_[8].value.as < Node * > ()->dtype));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1243 "parser.tab.cc"
    break;

  case 43: // MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE RETURN Expression SEMICOLON RBRACE
#line 311 "parser.yy"
            {
              std::string dtype = yystack_[9].value.as < Node * > ()->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[8].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Public", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[8].value.as < std::string > (), yylineno, yystack_[9].value.as < Node * > ()->dtype));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

            }
#line 1259 "parser.tab.cc"
    break;

  case 44: // ClassDeclaration: CLASS ID LBRACE LRVarDec LRMethodDec RBRACE
#line 323 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1270 "parser.tab.cc"
    break;

  case 45: // ClassDeclaration: CLASS ID LBRACE LRVarDec RBRACE
#line 330 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[3].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1280 "parser.tab.cc"
    break;

  case 46: // ClassDeclaration: CLASS ID LBRACE RBRACE
#line 336 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[2].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
            }
#line 1289 "parser.tab.cc"
    break;

  case 47: // ClassDeclaration: CLASS ID LBRACE LRMethodDec RBRACE
#line 341 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[3].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1299 "parser.tab.cc"
    break;

  case 48: // MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE Statement RBRACE RBRACE
#line 348 "parser.yy"
            {
 
              yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[15].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Method Identifier", yystack_[5].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1311 "parser.tab.cc"
    break;

  case 49: // Goal: MainClass LRClassDec "end of file"
#line 365 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1321 "parser.tab.cc"
    break;

  case 50: // Goal: MainClass "end of file"
#line 371 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1330 "parser.tab.cc"
    break;

  case 51: // LRStatement: Statement
#line 398 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Statement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1339 "parser.tab.cc"
    break;

  case 52: // LRStatement: LRStatement Statement
#line 403 "parser.yy"
              {
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();

              }
#line 1349 "parser.tab.cc"
    break;

  case 53: // LRVarDec: VarDeclaration
#line 413 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("VarDeclarations", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

              }
#line 1359 "parser.tab.cc"
    break;

  case 54: // LRVarDec: LRVarDec VarDeclaration
#line 419 "parser.yy"
              {
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
          
              }
#line 1369 "parser.tab.cc"
    break;

  case 55: // LRParamater: Type ID
#line 429 "parser.yy"
              {
  
                yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno, yystack_[1].value.as < Node * > ()->type);
                yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno, yystack_[1].value.as < Node * > ()->type));
                //$$ = $1;
              }
#line 1380 "parser.tab.cc"
    break;

  case 56: // LRParamater: LRParamater COMMA Type ID
#line 436 "parser.yy"
              {
                yystack_[3].value.as < Node * > ()->children.push_back(new Node("Identifer", yystack_[0].value.as < std::string > (), yylineno, yystack_[1].value.as < Node * > ()->type));
                yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();

              }
#line 1390 "parser.tab.cc"
    break;

  case 57: // LRArguments: Expression
#line 445 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1399 "parser.tab.cc"
    break;

  case 58: // LRArguments: LRArguments COMMA Expression
#line 450 "parser.yy"
              {
                yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
              }
#line 1408 "parser.tab.cc"
    break;

  case 59: // LRVarOrStatementDec: Statement
#line 460 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Statement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1417 "parser.tab.cc"
    break;

  case 60: // LRVarOrStatementDec: VarDeclaration
#line 465 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("VarDeclarations", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

                //$$->children.push_back($1);
              }
#line 1428 "parser.tab.cc"
    break;

  case 61: // LRVarOrStatementDec: LRVarOrStatementDec Statement
#line 472 "parser.yy"
              {
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                //$$->children.push_back($2);
              }
#line 1438 "parser.tab.cc"
    break;

  case 62: // LRVarOrStatementDec: LRVarOrStatementDec VarDeclaration
#line 478 "parser.yy"
              {
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                //$$->children.push_back($2);

              }
#line 1449 "parser.tab.cc"
    break;

  case 63: // LRMethodDec: MethodDeclaration
#line 491 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("MethodDeclarations", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1458 "parser.tab.cc"
    break;

  case 64: // LRMethodDec: LRMethodDec MethodDeclaration
#line 496 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                
              }
#line 1468 "parser.tab.cc"
    break;

  case 65: // StateEpsilon: %empty
#line 504 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("EMPTY", "", yylineno);
              }
#line 1476 "parser.tab.cc"
    break;

  case 66: // StateEpsilon: ELSE Statement
#line 508 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("ELSE", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1485 "parser.tab.cc"
    break;

  case 67: // LRClassDec: ClassDeclaration
#line 518 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1493 "parser.tab.cc"
    break;

  case 68: // LRClassDec: LRClassDec ClassDeclaration
#line 522 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRClassDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1503 "parser.tab.cc"
    break;


#line 1507 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -36,   -28,    19,    -5,     9,   -66,    18,   -66,    33,   -66,
     -66,   -66,    11,    30,    55,   -66,   -66,    77,    25,    47,
     113,   -66,   -66,   -66,   157,   103,   -66,   -66,    27,   -17,
      86,   111,   122,   128,   -66,   -66,    49,   -66,   -66,    99,
     -66,   127,   -66,   -66,   130,   112,   120,   119,   141,    -1,
     149,    62,   -66,   134,   157,   162,     2,   115,   163,   174,
     250,   175,   178,   -66,   -66,    73,    92,   187,   188,   250,
     250,     2,   -66,   123,   -66,   250,   -66,   -66,   -66,   -66,
     -66,    56,   250,   250,   151,   -66,   250,   250,   250,   -66,
     -66,   250,   106,   -66,   140,   161,   184,   163,   -66,   195,
     192,   182,    48,   218,   250,   169,   250,   250,   250,   250,
     250,   250,   250,   250,   250,     0,   229,   252,   275,   298,
     250,   172,   222,   -66,   115,   250,   208,   -66,   308,   -66,
     405,   397,    48,    48,   262,   107,   107,    -2,    -2,   265,
     -66,   115,   259,   260,   261,   331,   115,   250,   258,   341,
     -66,   -66,   216,   -66,   -66,   -66,   -66,   274,   276,   364,
     115,   -66,   -66,   -66,   374,    45,   -66,   278,   -66,   -66,
     -66,   250,   -66,   374
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     3,     0,     1,     0,     4,
      50,    67,     0,     0,     0,    49,    68,     0,     0,     0,
       5,     6,     7,    46,     0,     0,    53,    63,     0,     0,
       0,     0,     0,     0,    45,    54,     0,    47,    64,     0,
       8,     0,     9,    44,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,    60,    59,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    34,     0,    27,    24,    25,    26,
      28,     0,     0,     0,     0,    10,     0,     0,     0,    62,
      61,     0,     0,    56,     0,     0,     0,    33,    52,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,    32,     0,    42,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      23,     0,     0,     0,     0,     0,     0,     0,    65,     0,
      30,    22,     0,    38,    37,    41,    43,     0,     0,     0,
       0,    39,    29,    11,    57,     0,    40,     0,    35,    66,
      12,     0,    48,    58
  };

  const short
  parser::yypgoto_[] =
  {
     -66,   -66,   -66,    12,   -15,   -65,   -66,   -57,    52,    88,
     -66,   -66,   -66,   -66,   -66,   -66,   238,   280,   -66,   -66
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    25,    63,    84,    85,    64,    27,     9,
       4,     5,    73,    28,    49,   165,    65,    29,   161,    12
  };

  const unsigned char
  parser::yytable_[] =
  {
      72,     1,   104,    26,    95,    96,    69,   139,    90,    10,
      99,    15,    37,    35,     6,    53,    98,   102,   103,     7,
      24,   116,   117,   118,   115,    13,   119,   140,    20,    54,
      20,    21,    22,    21,    22,    90,    32,     8,    70,   128,
      14,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      89,     8,   104,     8,    23,   145,    34,    48,    17,   100,
     149,   170,    24,   101,    24,    20,    67,   148,    21,    56,
     111,   112,   113,   114,   115,   171,    20,    89,    43,    21,
      56,    38,   159,    18,   153,    30,    24,   164,    38,   158,
      57,    58,    11,    59,    60,    20,    61,    62,    21,    56,
      16,    57,    58,   169,    59,    88,   173,    61,    62,    20,
      33,   104,    21,    56,    19,    20,    40,    31,    21,    22,
      57,    58,    71,    59,    91,    39,    61,    62,    47,    41,
      71,   113,   114,   115,    57,    58,    42,    59,   120,    44,
      61,    62,    45,    57,    58,    46,    59,    51,    52,    61,
      62,    57,    97,    55,    59,   104,   121,    61,    62,   105,
      20,    50,    66,    21,    22,   104,   122,    68,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   104,    75,
      86,    74,   123,    87,    93,    94,   125,   126,   129,   104,
     146,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   124,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   104,    76,   150,    77,    78,    79,    80,    81,
      82,    83,   163,   104,   127,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   141,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   104,    76,   147,    77,
      78,    79,    80,    81,    82,    83,   104,   154,   142,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   104,
     152,   108,   109,   143,   111,   112,   113,   114,   115,   155,
     156,   160,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   104,   166,    92,   167,   144,   172,    36,     0,
       0,     0,   104,   151,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   104,     0,     0,     0,   157,
       0,     0,     0,     0,     0,   104,   162,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   104,     0,
       0,     0,   168,     0,     0,     0,     0,     0,   104,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   104,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,   106,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   108,   109,   110,   111,   112,   113,
     114,   115
  };

  const short
  parser::yycheck_[] =
  {
      57,    37,     4,    18,    69,    70,     4,     7,    65,     0,
      75,     0,    29,    28,    42,    16,    73,    82,    83,     0,
      37,    86,    87,    88,    26,     7,    91,    27,     3,    30,
       3,     6,     7,     6,     7,    92,    24,    42,    36,   104,
       7,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      65,    42,     4,    42,    29,   120,    29,    45,    28,     3,
     125,    16,    37,     7,    37,     3,    54,   124,     6,     7,
      22,    23,    24,    25,    26,    30,     3,    92,    29,     6,
       7,    29,   147,    28,   141,    38,    37,   152,    36,   146,
      28,    29,     4,    31,    32,     3,    34,    35,     6,     7,
      12,    28,    29,   160,    31,    32,   171,    34,    35,     3,
       7,     4,     6,     7,    37,     3,     5,     4,     6,     7,
      28,    29,     7,    31,    32,    39,    34,    35,    16,     7,
       7,    24,    25,    26,    28,    29,     8,    31,    32,    40,
      34,    35,    15,    28,    29,    15,    31,    28,     7,    34,
      35,    28,    29,     4,    31,     4,    16,    34,    35,     8,
       3,    41,    28,     6,     7,     4,     5,     5,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     4,    15,
      15,    28,     8,    15,     7,     7,     4,    15,    29,     4,
      28,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     4,     7,    16,     9,    10,    11,    12,    13,
      14,    15,    16,     4,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     4,     7,    36,     9,
      10,    11,    12,    13,    14,    15,     4,     8,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     4,
      15,    19,    20,     8,    22,    23,    24,    25,    26,    29,
      29,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     4,    29,    66,    29,     8,    29,    28,    -1,
      -1,    -1,     4,     5,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     4,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     4,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    19,    20,    21,    22,    23,    24,
      25,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    37,    46,    47,    55,    56,    42,     0,    42,    54,
       0,    54,    64,     7,     7,     0,    54,    28,    28,    37,
       3,     6,     7,    29,    37,    48,    49,    53,    58,    62,
      38,     4,    48,     7,    29,    49,    62,    29,    53,    39,
       5,     7,     8,    29,    40,    15,    15,    16,    48,    59,
      41,    28,     7,    16,    30,     4,     7,    28,    29,    31,
      32,    34,    35,    49,    52,    61,    28,    48,     5,     4,
      36,     7,    52,    57,    28,    15,     7,     9,    10,    11,
      12,    13,    14,    15,    50,    51,    15,    15,    32,    49,
      52,    32,    61,     7,     7,    50,    50,    29,    52,    50,
       3,     7,    50,    50,     4,     8,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    50,    50,    50,    50,
      32,    16,     5,     8,    16,     4,    15,    16,    50,    29,
      50,    50,    50,    50,    50,    50,    50,    50,    50,     7,
      27,    16,    16,     8,     8,    50,    28,    36,    52,    50,
      16,     5,    15,    52,     8,    29,    29,     8,    52,    50,
      33,    63,     5,    16,    50,    60,    29,    29,     8,    52,
      16,    30,    29,    50
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    54,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    63,    64,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     3,     3,
       1,     5,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     3,     2,     7,     4,     5,     5,     6,
      12,    11,    10,    11,     6,     5,     4,     5,    18,     3,
       2,     1,     2,     1,     2,     2,     4,     1,     3,     1,
       1,     2,     2,     1,     2,     0,     2,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INT", "LBRACKET",
  "RBRACKET", "BOOLEAN", "ID", "SEMICOLON", "NUM", "TRUE", "FALSE", "THIS",
  "NEW", "NOT", "LPAREN", "RPAREN", "AND", "OR", "LT", "GT", "EQ", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "DOT", "LENGTH", "LBRACE", "RBRACE", "COMMA",
  "IF", "RETURN", "ELSE", "WHILE", "PRINT", "EQUALSIGN", "PUBLIC",
  "STATIC", "VOID", "MAIN", "STRING", "CLASS", "TOKEN_DOLLAR",
  "TOKEN_CARET", "$accept", "root", "Program", "Type", "VarDeclaration",
  "Expression", "Term", "Statement", "MethodDeclaration",
  "ClassDeclaration", "MainClass", "Goal", "LRStatement", "LRVarDec",
  "LRParamater", "LRArguments", "LRVarOrStatementDec", "LRMethodDec",
  "StateEpsilon", "LRClassDec", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    58,    58,    63,    68,    74,    79,    83,    87,    91,
     103,   107,   115,   123,   129,   135,   141,   147,   153,   160,
     166,   172,   178,   184,   191,   195,   199,   203,   208,   212,
     220,   226,   231,   235,   239,   243,   252,   259,   264,   270,
     277,   289,   300,   310,   322,   329,   335,   340,   347,   364,
     370,   397,   402,   412,   418,   428,   435,   444,   449,   459,
     464,   471,   477,   490,   495,   503,   507,   517,   521
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2128 "parser.tab.cc"

