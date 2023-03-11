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
  

#line 56 "parser.tab.cc"


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
#line 129 "parser.tab.cc"

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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
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
#line 57 "parser.yy"
             {root = yystack_[0].value.as < Node * > ();}
#line 830 "parser.tab.cc"
    break;

  case 3: // Program: Goal
#line 63 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 838 "parser.tab.cc"
    break;

  case 4: // Program: Program ClassDeclaration
#line 67 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 847 "parser.tab.cc"
    break;

  case 5: // Type: INT
#line 73 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Int", "", yylineno);
            }
#line 855 "parser.tab.cc"
    break;

  case 6: // Type: BOOLEAN
#line 78 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno);
            }
#line 863 "parser.tab.cc"
    break;

  case 7: // Type: ID
#line 82 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node(yystack_[0].value.as < std::string > (), yystack_[0].value.as < std::string > (), yylineno);
            }
#line 871 "parser.tab.cc"
    break;

  case 8: // Type: INT LBRACKET RBRACKET
#line 86 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArr", "", yylineno);
            }
#line 879 "parser.tab.cc"
    break;

  case 9: // VarDeclaration: Type ID SEMICOLON
#line 90 "parser.yy"
            {
              // CHANGED THIS MIGHT DESTROY SOMETHING ELSE
              std::string dtype = yystack_[2].value.as < Node * > ()->type;
              // CHANGE TO $2 IF THIS BUGS!
              std::cout << "aLSdjLAnfraskdlnä " << yystack_[2].value.as < Node * > ()->value<<std::endl;
              yylhs.value.as < Node * > () = new Node("VarDeclaration",yystack_[1].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

              //$$->children.push_back(new Node("ID", $2, yylineno,dtype));
            }
#line 894 "parser.tab.cc"
    break;

  case 10: // Expression: Term
#line 103 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 902 "parser.tab.cc"
    break;

  case 11: // Expression: Expression DOT ID LPAREN LRArguments RPAREN
#line 107 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("FCall", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Dot", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno,"Method"));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 914 "parser.tab.cc"
    break;

  case 12: // Expression: Expression AND Expression
#line 115 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("And", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 924 "parser.tab.cc"
    break;

  case 13: // Expression: Expression OR Expression
#line 121 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Or", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 934 "parser.tab.cc"
    break;

  case 14: // Expression: Expression LT Expression
#line 127 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Lt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 944 "parser.tab.cc"
    break;

  case 15: // Expression: Expression GT Expression
#line 133 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Gt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 954 "parser.tab.cc"
    break;

  case 16: // Expression: Expression EQ Expression
#line 139 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("==", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 964 "parser.tab.cc"
    break;

  case 17: // Expression: Expression PLUS Expression
#line 145 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Plus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              //$$->children.push_back(new Node("PLUS", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 975 "parser.tab.cc"
    break;

  case 18: // Expression: Expression MINUS Expression
#line 152 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Minus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 985 "parser.tab.cc"
    break;

  case 19: // Expression: Expression TIMES Expression
#line 158 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Mult", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 995 "parser.tab.cc"
    break;

  case 20: // Expression: Expression DIVIDE Expression
#line 164 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Divide", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1005 "parser.tab.cc"
    break;

  case 21: // Expression: Expression LBRACKET Expression RBRACKET
#line 170 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1015 "parser.tab.cc"
    break;

  case 22: // Expression: Expression DOT LENGTH
#line 176 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(new Node("Dot", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Lenght", "", yylineno));
            }
#line 1025 "parser.tab.cc"
    break;

  case 23: // Term: NUM
#line 183 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Num", "", yylineno, "Int");
            }
#line 1033 "parser.tab.cc"
    break;

  case 24: // Term: TRUE
#line 187 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("True", "", yylineno);
            }
#line 1041 "parser.tab.cc"
    break;

  case 25: // Term: FALSE
#line 191 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("False", "", yylineno);
            }
#line 1049 "parser.tab.cc"
    break;

  case 26: // Term: ID
#line 195 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);

            }
#line 1058 "parser.tab.cc"
    break;

  case 27: // Term: THIS
#line 200 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("This", "", yylineno);
            }
#line 1066 "parser.tab.cc"
    break;

  case 28: // Term: NEW INT LBRACKET Expression RBRACKET
#line 204 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("New", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Int", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1077 "parser.tab.cc"
    break;

  case 29: // Term: NEW ID LPAREN RPAREN
#line 211 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("NewVar", yystack_[2].value.as < std::string > (), yylineno, "Class");
              //$$->children.push_back(new Node("New", "", yylineno));
              //$$->children.push_back(new Node("Identifier", $2, yylineno, "Class"));
            }
#line 1087 "parser.tab.cc"
    break;

  case 30: // Term: NOT Expression
#line 217 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Not", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1096 "parser.tab.cc"
    break;

  case 31: // Term: LPAREN Expression RPAREN
#line 222 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1104 "parser.tab.cc"
    break;

  case 32: // Term: CLASS
#line 226 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Class", "", yylineno);
            }
#line 1112 "parser.tab.cc"
    break;

  case 33: // Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
#line 230 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrModifier", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

            }
#line 1125 "parser.tab.cc"
    break;

  case 34: // Statement: ID EQUALSIGN Expression SEMICOLON
#line 239 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1136 "parser.tab.cc"
    break;

  case 35: // Statement: PRINT LPAREN Expression RPAREN SEMICOLON
#line 246 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1145 "parser.tab.cc"
    break;

  case 36: // Statement: WHILE LPAREN Expression RPAREN Statement
#line 251 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1155 "parser.tab.cc"
    break;

  case 37: // Statement: LBRACE LRStatement RBRACE
#line 257 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1163 "parser.tab.cc"
    break;

  case 38: // Statement: IF LPAREN Expression RPAREN Statement StateEpsilon
#line 262 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("If statement", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1174 "parser.tab.cc"
    break;

  case 39: // MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE LRStatement RBRACE RBRACE
#line 269 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[15].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Method Identifier", yystack_[5].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1185 "parser.tab.cc"
    break;

  case 40: // MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
#line 276 "parser.yy"
            {
              std::string dtype = yystack_[10].value.as < Node * > ()->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[9].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Public", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[9].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1201 "parser.tab.cc"
    break;

  case 41: // ClassDeclaration: CLASS ID LBRACE LRVarDec LRMethodDec RBRACE
#line 288 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1212 "parser.tab.cc"
    break;

  case 42: // Goal: MainClass LRClassDec "end of file"
#line 304 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1222 "parser.tab.cc"
    break;

  case 43: // LRStatement: Statement
#line 332 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1230 "parser.tab.cc"
    break;

  case 44: // LRStatement: LRStatement Statement
#line 336 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1240 "parser.tab.cc"
    break;

  case 45: // LRVarDec: %empty
#line 346 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
              }
#line 1248 "parser.tab.cc"
    break;

  case 46: // LRVarDec: VarDeclaration
#line 350 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1256 "parser.tab.cc"
    break;

  case 47: // LRVarDec: LRVarDec VarDeclaration
#line 354 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRVarDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1266 "parser.tab.cc"
    break;

  case 48: // LRParamater: %empty
#line 364 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno);
              }
#line 1274 "parser.tab.cc"
    break;

  case 49: // LRParamater: Type ID
#line 368 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno, yystack_[1].value.as < Node * > ()->type));
                //$$ = $1;
              }
#line 1284 "parser.tab.cc"
    break;

  case 50: // LRParamater: LRParamater COMMA Type ID
#line 374 "parser.yy"
              {
                yystack_[3].value.as < Node * > ()->children.push_back(new Node("Identifer", yystack_[0].value.as < std::string > (), yylineno, yystack_[1].value.as < Node * > ()->type));
                yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();

              }
#line 1294 "parser.tab.cc"
    break;

  case 51: // LRArguments: %empty
#line 380 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
              }
#line 1302 "parser.tab.cc"
    break;

  case 52: // LRArguments: Expression
#line 384 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1311 "parser.tab.cc"
    break;

  case 53: // LRArguments: LRArguments COMMA Expression
#line 389 "parser.yy"
              {
                yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
              }
#line 1320 "parser.tab.cc"
    break;

  case 54: // LRVarOrStatementDec: %empty
#line 399 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
              }
#line 1328 "parser.tab.cc"
    break;

  case 55: // LRVarOrStatementDec: Statement
#line 403 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Statement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1337 "parser.tab.cc"
    break;

  case 56: // LRVarOrStatementDec: VarDeclaration
#line 408 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Statement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

                //$$->children.push_back($1);
              }
#line 1348 "parser.tab.cc"
    break;

  case 57: // LRVarOrStatementDec: LRVarOrStatementDec Statement
#line 415 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1357 "parser.tab.cc"
    break;

  case 58: // LRVarOrStatementDec: LRVarOrStatementDec VarDeclaration
#line 420 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

              }
#line 1367 "parser.tab.cc"
    break;

  case 59: // LRMethodDec: MethodDeclaration
#line 432 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("MethodDeclarations", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1376 "parser.tab.cc"
    break;

  case 60: // LRMethodDec: LRMethodDec MethodDeclaration
#line 437 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                
              }
#line 1386 "parser.tab.cc"
    break;

  case 61: // StateEpsilon: %empty
#line 445 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("EMPTY", "", yylineno);
              }
#line 1394 "parser.tab.cc"
    break;

  case 62: // StateEpsilon: ELSE Statement
#line 449 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("ELSE", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1403 "parser.tab.cc"
    break;

  case 63: // LRClassDec: ClassDeclaration
#line 459 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1411 "parser.tab.cc"
    break;

  case 64: // LRClassDec: LRClassDec ClassDeclaration
#line 463 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRClassDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1421 "parser.tab.cc"
    break;


#line 1425 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -34,   -37,    57,   -21,   -21,   -57,    66,   -57,    71,   -57,
     -57,    11,    53,    54,   -57,   -57,    58,    69,    51,    87,
     -57,   -57,   101,   -57,    17,   100,   106,   129,    69,   -57,
     -57,    37,   102,   -57,   -57,   134,   -57,   -57,   128,   131,
     103,    69,   144,   164,   -12,   167,   -57,   145,    69,   168,
      62,   169,   158,     2,    72,   162,   163,   165,   -57,   -57,
      52,   -57,   151,    21,    21,     2,   -57,    70,    21,    21,
      21,    21,   -57,   -57,    72,   -57,   -57,   -57,   -57,   -57,
      64,    21,    21,   -57,   109,   -57,   132,   -57,   -57,   143,
     166,   177,   200,    81,   201,   191,   314,   211,    21,   171,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    -5,
     -57,    72,    72,   202,   180,   182,    21,   196,   -57,   234,
      21,    98,   300,   314,   314,   308,    15,    15,     3,     3,
     198,   -57,   181,   -57,   -57,   -57,   -57,   244,   -57,   -57,
     267,    21,    72,   -57,   -57,   -57,   277,    40,   -57,   -57,
      21,   277
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     3,     0,     1,     0,     4,
      63,     0,     0,     0,    42,    64,     0,    45,     0,     5,
       6,     7,     0,    46,     0,     0,     0,     0,     0,    47,
      59,     0,     0,     8,     9,     0,    41,    60,     0,     0,
       0,    48,     0,     0,     0,     0,    49,     0,     0,     0,
      54,     0,     0,     7,     0,     0,     0,     0,    56,    55,
       0,    50,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,    58,    57,     0,    26,    23,    24,    25,    27,
       0,     0,     0,    32,     0,    10,     0,    37,    44,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    22,    61,    36,    35,    40,    39,     0,    29,    21,
       0,    51,     0,    38,    28,    33,    52,     0,    62,    11,
       0,    53
  };

  const short
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,    97,   -23,   -56,   -57,   -50,   -57,   185,
       5,   -57,   170,   -57,   -57,   -57,   -57,   -57,   -57,   -57
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    22,    23,    84,    85,    66,     4,    30,
       9,     5,    67,    24,    44,   147,    60,    31,   143,    11
  };

  const unsigned char
  parser::yytable_[] =
  {
      59,    29,   130,     1,    47,     6,    63,    98,    86,    10,
      73,    14,    89,    90,    91,    92,    15,    88,    48,    98,
      19,     8,   131,    20,    21,    96,    97,    58,    75,   109,
      76,    77,    78,    79,    80,    81,    82,    72,    64,   107,
     108,   109,   119,    88,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,    28,    19,   149,     7,    20,    53,
     137,   132,   133,    83,   140,    19,    36,    94,    20,    53,
     150,    95,    19,    12,    28,    20,    21,    65,    13,    65,
      54,    16,    17,    55,    71,   146,    56,    57,    65,    25,
      54,    26,   148,    55,   151,    18,    56,    57,    54,    87,
      54,    55,    98,    55,    56,    57,    56,    57,    27,    54,
     115,    33,    55,    98,    99,    56,    57,   102,   103,   104,
     105,   106,   107,   108,   109,    35,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    98,    34,    43,    32,
     110,    39,    38,    40,    42,    51,    41,    98,    45,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   111,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      98,    46,    49,    50,    62,    52,    61,    68,    69,    74,
      70,    98,   112,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   113,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    98,   116,   117,   120,   114,   135,
     134,   136,   138,   141,   142,    98,    37,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   118,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    98,   139,
       0,     0,     0,     0,    93,     0,     0,     0,    98,   144,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    98,     0,     0,     0,   145,     0,     0,     0,     0,
       0,    98,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    98,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,   100,    98,   102,
     103,   104,   105,   106,   107,   108,   109,   102,   103,     0,
     105,   106,   107,   108,   109,     0,   105,   106,   107,   108,
     109
  };

  const short
  parser::yycheck_[] =
  {
      50,    24,     7,    37,    16,    42,     4,     4,    64,     4,
      60,     0,    68,    69,    70,    71,    11,    67,    30,     4,
       3,    42,    27,     6,     7,    81,    82,    50,     7,    26,
       9,    10,    11,    12,    13,    14,    15,    60,    36,    24,
      25,    26,    98,    93,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    42,    37,     3,    16,     0,     6,     7,
     116,   111,   112,    42,   120,     3,    29,     3,     6,     7,
      30,     7,     3,     7,    37,     6,     7,     7,     7,     7,
      28,    28,    28,    31,    32,   141,    34,    35,     7,    38,
      28,     4,   142,    31,   150,    37,    34,    35,    28,    29,
      28,    31,     4,    31,    34,    35,    34,    35,     7,    28,
      29,     5,    31,     4,     5,    34,    35,    19,    20,    21,
      22,    23,    24,    25,    26,    28,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     4,     8,    41,    39,
       8,     7,    40,    15,    41,    48,    15,     4,     4,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       4,     7,     5,    28,    16,     7,     7,    15,    15,    28,
      15,     4,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     4,     4,    15,    36,     8,    29,
       8,    29,    16,    15,    33,     4,    31,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     4,     5,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,     4,     5,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     4,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    17,     4,    19,
      20,    21,    22,    23,    24,    25,    26,    19,    20,    -1,
      22,    23,    24,    25,    26,    -1,    22,    23,    24,    25,
      26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    37,    44,    45,    51,    54,    42,     0,    42,    53,
      53,    62,     7,     7,     0,    53,    28,    28,    37,     3,
       6,     7,    46,    47,    56,    38,     4,     7,    37,    47,
      52,    60,    39,     5,     8,    46,    29,    52,    40,     7,
      15,    15,    41,    46,    57,     4,     7,    16,    30,     5,
      28,    46,     7,     7,    28,    31,    34,    35,    47,    50,
      59,     7,    16,     4,    36,     7,    50,    55,    15,    15,
      15,    32,    47,    50,    28,     7,     9,    10,    11,    12,
      13,    14,    15,    42,    48,    49,    48,    29,    50,    48,
      48,    48,    48,    55,     3,     7,    48,    48,     4,     5,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       8,    16,    16,    16,     8,    29,     4,    15,    16,    48,
      36,    48,    48,    48,    48,    48,    48,    48,    48,    48,
       7,    27,    50,    50,     8,    29,    29,    48,    16,     5,
      48,    15,    33,    61,     5,     8,    48,    58,    50,    16,
      30,    48
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    46,    46,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    51,
      52,    53,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    62
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     3,     3,
       1,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     1,     7,     4,     5,     5,     3,     6,    18,
      12,     6,     3,     1,     2,     0,     1,     2,     0,     2,
       4,     0,     1,     3,     0,     1,     1,     2,     2,     1,
       2,     0,     2,     1,     2
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
  "STATIC", "VOID", "MAIN", "STRING", "CLASS", "$accept", "root",
  "Program", "Type", "VarDeclaration", "Expression", "Term", "Statement",
  "MainClass", "MethodDeclaration", "ClassDeclaration", "Goal",
  "LRStatement", "LRVarDec", "LRParamater", "LRArguments",
  "LRVarOrStatementDec", "LRMethodDec", "StateEpsilon", "LRClassDec", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    57,    57,    62,    66,    72,    77,    81,    85,    89,
     102,   106,   114,   120,   126,   132,   138,   144,   151,   157,
     163,   169,   175,   182,   186,   190,   194,   199,   203,   210,
     216,   221,   225,   229,   238,   245,   250,   256,   261,   268,
     275,   287,   303,   331,   335,   345,   349,   353,   363,   367,
     373,   379,   383,   388,   398,   402,   407,   414,   419,   431,
     436,   444,   448,   458,   462
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
#line 2021 "parser.tab.cc"

