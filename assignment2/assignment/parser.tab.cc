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
#line 21 "parser.yy"

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
      case symbol_kind::S_LRExp: // LRExp
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
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
      case symbol_kind::S_LRExp: // LRExp
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
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
      case symbol_kind::S_LRExp: // LRExp
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
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
      case symbol_kind::S_LRExp: // LRExp
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
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
      case symbol_kind::S_LRExp: // LRExp
      case symbol_kind::S_LRStatement: // LRStatement
      case symbol_kind::S_LRVarDec: // LRVarDec
      case symbol_kind::S_LRParamater: // LRParamater
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
#line 56 "parser.yy"
             {root = yystack_[0].value.as < Node * > ();}
#line 830 "parser.tab.cc"
    break;

  case 3: // Program: Goal
#line 62 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 838 "parser.tab.cc"
    break;

  case 4: // Program: Program ClassDeclaration
#line 66 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 847 "parser.tab.cc"
    break;

  case 5: // Type: INT
#line 72 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Int", "", yylineno);
            }
#line 855 "parser.tab.cc"
    break;

  case 6: // Type: BOOLEAN
#line 77 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno);
            }
#line 863 "parser.tab.cc"
    break;

  case 7: // Type: ID
#line 81 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);
            }
#line 871 "parser.tab.cc"
    break;

  case 8: // Type: INT LBRACKET RBRACKET
#line 85 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArr", "", yylineno);
            }
#line 879 "parser.tab.cc"
    break;

  case 9: // VarDeclaration: Type ID SEMICOLON
#line 89 "parser.yy"
            {
              // CHANGED THIS MIGHT DESTROY SOMETHING ELSE
              std::string dtype = yystack_[2].value.as < Node * > ()->type;
              // CHANGE TO $2 IF THIS BUGS!
              yylhs.value.as < Node * > () = new Node("VarDeclaration",yystack_[1].value.as < std::string > (), yylineno, dtype);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("ID", yystack_[1].value.as < std::string > (), yylineno));
            }
#line 892 "parser.tab.cc"
    break;

  case 10: // Expression: Term
#line 100 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 900 "parser.tab.cc"
    break;

  case 11: // Expression: Expression AND Expression
#line 105 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("And", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 910 "parser.tab.cc"
    break;

  case 12: // Expression: Expression OR Expression
#line 111 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Or", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 920 "parser.tab.cc"
    break;

  case 13: // Expression: Expression LT Expression
#line 117 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Lt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 930 "parser.tab.cc"
    break;

  case 14: // Expression: Expression GT Expression
#line 123 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Gt", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 940 "parser.tab.cc"
    break;

  case 15: // Expression: Expression EQ Expression
#line 129 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("==", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 950 "parser.tab.cc"
    break;

  case 16: // Expression: Expression PLUS Expression
#line 135 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Plus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("PLUS", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 961 "parser.tab.cc"
    break;

  case 17: // Expression: Expression MINUS Expression
#line 142 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Minus", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 971 "parser.tab.cc"
    break;

  case 18: // Expression: Expression TIMES Expression
#line 148 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Mult", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 981 "parser.tab.cc"
    break;

  case 19: // Expression: Expression DIVIDE Expression
#line 154 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Divide", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 991 "parser.tab.cc"
    break;

  case 20: // Expression: Expression LBRACKET Expression RBRACKET
#line 160 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1001 "parser.tab.cc"
    break;

  case 21: // Expression: Expression DOT LENGTH
#line 166 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
              yylhs.value.as < Node * > ()->children.push_back(new Node("Dot", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Lenght", "", yylineno));
            }
#line 1011 "parser.tab.cc"
    break;

  case 22: // Expression: Expression DOT ID LPAREN LRExp RPAREN
#line 173 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("FCall", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Dot", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno,"Method"));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1023 "parser.tab.cc"
    break;

  case 23: // Term: NUM
#line 182 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Num", "", yylineno);
            }
#line 1031 "parser.tab.cc"
    break;

  case 24: // Term: TRUE
#line 186 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("True", "", yylineno);
            }
#line 1039 "parser.tab.cc"
    break;

  case 25: // Term: FALSE
#line 190 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("False", "", yylineno);
            }
#line 1047 "parser.tab.cc"
    break;

  case 26: // Term: ID
#line 194 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);
            }
#line 1055 "parser.tab.cc"
    break;

  case 27: // Term: THIS
#line 198 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("This", "", yylineno);
            }
#line 1063 "parser.tab.cc"
    break;

  case 28: // Term: NEW INT LBRACKET Expression RBRACKET
#line 202 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntArrDec", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("New", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Int", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1074 "parser.tab.cc"
    break;

  case 29: // Term: NEW ID LPAREN RPAREN
#line 209 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("NewVar", yystack_[2].value.as < std::string > (), yylineno, "Class");
              //$$->children.push_back(new Node("New", "", yylineno));
              //$$->children.push_back(new Node("Identifier", $2, yylineno, "Class"));
            }
#line 1084 "parser.tab.cc"
    break;

  case 30: // Term: NOT Expression
#line 215 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Not", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1093 "parser.tab.cc"
    break;

  case 31: // Term: LPAREN Expression RPAREN
#line 220 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("(Expression)", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1102 "parser.tab.cc"
    break;

  case 32: // Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
#line 225 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrModifier", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

            }
#line 1115 "parser.tab.cc"
    break;

  case 33: // Statement: ID EQUALSIGN Expression SEMICOLON
#line 234 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Equal", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1126 "parser.tab.cc"
    break;

  case 34: // Statement: PRINT LPAREN Expression RPAREN SEMICOLON
#line 241 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1135 "parser.tab.cc"
    break;

  case 35: // Statement: WHILE LPAREN Expression RPAREN Statement
#line 246 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1145 "parser.tab.cc"
    break;

  case 36: // Statement: LBRACE LRStatement RBRACE
#line 252 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1153 "parser.tab.cc"
    break;

  case 37: // Statement: IF LPAREN Expression RPAREN Statement StateEpsilon
#line 257 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("If statement", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1164 "parser.tab.cc"
    break;

  case 38: // MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE LRStatement RBRACE RBRACE
#line 264 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[15].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("Method Identifier", yystack_[5].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1175 "parser.tab.cc"
    break;

  case 39: // MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
#line 271 "parser.yy"
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
#line 1191 "parser.tab.cc"
    break;

  case 40: // ClassDeclaration: CLASS ID LBRACE LRVarDec LRMethodDec RBRACE
#line 283 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < std::string > (), yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1202 "parser.tab.cc"
    break;

  case 41: // Goal: MainClass LRClassDec "end of file"
#line 299 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1212 "parser.tab.cc"
    break;

  case 42: // LRExp: %empty
#line 309 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
            }
#line 1220 "parser.tab.cc"
    break;

  case 43: // LRExp: Expression
#line 313 "parser.yy"
            {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            }
#line 1228 "parser.tab.cc"
    break;

  case 44: // LRExp: LRExp COMMA Expression
#line 317 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("LRExp", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("Comma", "", yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1239 "parser.tab.cc"
    break;

  case 45: // LRStatement: Statement
#line 328 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1247 "parser.tab.cc"
    break;

  case 46: // LRStatement: LRStatement Statement
#line 332 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1257 "parser.tab.cc"
    break;

  case 47: // LRVarDec: %empty
#line 342 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
              }
#line 1265 "parser.tab.cc"
    break;

  case 48: // LRVarDec: VarDeclaration
#line 346 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1273 "parser.tab.cc"
    break;

  case 49: // LRVarDec: LRVarDec VarDeclaration
#line 350 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRVarDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1283 "parser.tab.cc"
    break;

  case 50: // LRParamater: %empty
#line 360 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
              }
#line 1291 "parser.tab.cc"
    break;

  case 51: // LRParamater: Type ID
#line 364 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRParamater", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno));
              }
#line 1301 "parser.tab.cc"
    break;

  case 52: // LRParamater: LRParamater COMMA Type ID
#line 370 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRParamater", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("Comma", "", yylineno));
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno));
              }
#line 1313 "parser.tab.cc"
    break;

  case 53: // LRVarOrStatementDec: %empty
#line 383 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
              }
#line 1321 "parser.tab.cc"
    break;

  case 54: // LRVarOrStatementDec: VarDeclaration
#line 387 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1329 "parser.tab.cc"
    break;

  case 55: // LRVarOrStatementDec: Statement
#line 391 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1337 "parser.tab.cc"
    break;

  case 56: // LRVarOrStatementDec: LRVarOrStatementDec VarDeclaration
#line 395 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRVarOrStatementDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1347 "parser.tab.cc"
    break;

  case 57: // LRVarOrStatementDec: LRVarOrStatementDec Statement
#line 401 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRVarOrStatementDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1357 "parser.tab.cc"
    break;

  case 58: // LRMethodDec: MethodDeclaration
#line 413 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1365 "parser.tab.cc"
    break;

  case 59: // LRMethodDec: LRMethodDec MethodDeclaration
#line 417 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRMethodDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1375 "parser.tab.cc"
    break;

  case 60: // StateEpsilon: %empty
#line 425 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("EMPTY", "", yylineno);
              }
#line 1383 "parser.tab.cc"
    break;

  case 61: // StateEpsilon: ELSE Statement
#line 429 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("ELSE", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1392 "parser.tab.cc"
    break;

  case 62: // LRClassDec: ClassDeclaration
#line 439 "parser.yy"
              {
                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              }
#line 1400 "parser.tab.cc"
    break;

  case 63: // LRClassDec: LRClassDec ClassDeclaration
#line 443 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("LRClassDec", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1410 "parser.tab.cc"
    break;


#line 1414 "parser.tab.cc"

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
     -18,   -20,    34,    -7,    -7,   -57,    49,   -57,    68,   -57,
     -57,    11,    52,    60,   -57,   -57,    53,    59,    56,   103,
     -57,   -57,   117,   -57,    -1,    98,   105,   128,    59,   -57,
     -57,    -5,   100,   -57,   -57,   134,   -57,   -57,   123,   127,
     102,    59,   140,   138,   -12,   166,   -57,   119,    59,   172,
      61,   197,   189,     3,    71,   191,   193,   194,   -57,   -57,
      51,   -57,   182,   163,   163,     3,   -57,    69,   163,   163,
     163,   163,   -57,   -57,    71,   -57,   -57,   -57,   -57,   -57,
      74,   163,   163,   108,   -57,   131,   -57,   -57,   142,   165,
     176,   199,    80,   207,   198,    48,   210,   163,   179,   163,
     163,   163,   163,   163,   163,   163,   163,   163,    -4,   -57,
      71,    71,   204,   211,   212,   163,   223,   -57,   233,   163,
      97,   299,    48,    48,   307,     5,     5,    12,    12,   227,
     -57,   213,   -57,   -57,   -57,   -57,   243,   -57,   -57,   266,
     163,    71,   -57,   -57,   -57,   276,    39,   -57,   -57,   163,
     276
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     3,     0,     1,     0,     4,
      62,     0,     0,     0,    41,    63,     0,    47,     0,     5,
       6,     7,     0,    48,     0,     0,     0,     0,     0,    49,
      58,     0,     0,     8,     9,     0,    40,    59,     0,     0,
       0,    50,     0,     0,     0,     0,    51,     0,     0,     0,
      53,     0,     0,     7,     0,     0,     0,     0,    54,    55,
       0,    52,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    56,    57,     0,    26,    23,    24,    25,    27,
       0,     0,     0,     0,    10,     0,    36,    46,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      21,    60,    35,    34,    39,    38,     0,    29,    20,     0,
      42,     0,    37,    28,    32,    43,     0,    61,    22,     0,
      44
  };

  const short
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,    -8,   -23,   -56,   -57,   -50,   -57,   214,
      17,   -57,   -57,   169,   -57,   -57,   -57,   -57,   -57,   -57
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    22,    23,    83,    84,    66,     4,    30,
       9,     5,   146,    67,    24,    44,    60,    31,   142,    11
  };

  const unsigned char
  parser::yytable_[] =
  {
      59,    29,    19,   129,    47,    20,    21,    63,    85,    97,
      73,    14,    88,    89,    90,    91,    97,    87,    48,     1,
      35,    10,     6,   130,    36,    95,    96,    58,    15,   106,
     107,   108,    28,    43,     7,     8,    28,    72,   108,    64,
      51,   118,    87,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    97,     8,    19,   148,    12,    20,    53,   136,
     131,   132,    19,   139,    19,    20,    21,    20,    53,   149,
     104,   105,   106,   107,   108,    13,    65,    93,    65,    54,
      16,    94,    55,    71,   145,    56,    57,    65,    17,    54,
      18,   147,    55,   150,    25,    56,    57,    54,    86,    54,
      55,    97,    55,    56,    57,    56,    57,    26,    54,   114,
      33,    55,    97,    98,    56,    57,   101,   102,   103,   104,
     105,   106,   107,   108,    27,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    97,    34,    32,    40,   109,
      38,    39,    41,    42,    45,    46,    97,    50,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   110,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    97,
      75,    49,    76,    77,    78,    79,    80,    81,    82,    52,
      97,   111,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   112,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    97,    61,    62,    68,   113,    69,    70,
      74,   115,   133,   116,    97,   119,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   117,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    97,   138,   137,
     134,   135,   140,    92,     0,    37,   141,    97,   143,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      97,     0,     0,     0,   144,     0,     0,     0,     0,     0,
      97,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    97,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,    99,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   101,   102,     0,   104,
     105,   106,   107,   108
  };

  const short
  parser::yycheck_[] =
  {
      50,    24,     3,     7,    16,     6,     7,     4,    64,     4,
      60,     0,    68,    69,    70,    71,     4,    67,    30,    37,
      28,     4,    42,    27,    29,    81,    82,    50,    11,    24,
      25,    26,    37,    41,     0,    42,    37,    60,    26,    36,
      48,    97,    92,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     4,    42,     3,    16,     7,     6,     7,   115,
     110,   111,     3,   119,     3,     6,     7,     6,     7,    30,
      22,    23,    24,    25,    26,     7,     7,     3,     7,    28,
      28,     7,    31,    32,   140,    34,    35,     7,    28,    28,
      37,   141,    31,   149,    38,    34,    35,    28,    29,    28,
      31,     4,    31,    34,    35,    34,    35,     4,    28,    29,
       5,    31,     4,     5,    34,    35,    19,    20,    21,    22,
      23,    24,    25,    26,     7,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     4,     8,    39,    15,     8,
      40,     7,    15,    41,     4,     7,     4,    28,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     4,
       7,     5,     9,    10,    11,    12,    13,    14,    15,     7,
       4,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     4,     7,    16,    15,     8,    15,    15,
      28,     4,     8,    15,     4,    36,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     4,     5,    16,
      29,    29,    15,    74,    -1,    31,    33,     4,     5,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       4,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    19,    20,    -1,    22,
      23,    24,    25,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    37,    44,    45,    51,    54,    42,     0,    42,    53,
      53,    62,     7,     7,     0,    53,    28,    28,    37,     3,
       6,     7,    46,    47,    57,    38,     4,     7,    37,    47,
      52,    60,    39,     5,     8,    46,    29,    52,    40,     7,
      15,    15,    41,    46,    58,     4,     7,    16,    30,     5,
      28,    46,     7,     7,    28,    31,    34,    35,    47,    50,
      59,     7,    16,     4,    36,     7,    50,    56,    15,    15,
      15,    32,    47,    50,    28,     7,     9,    10,    11,    12,
      13,    14,    15,    48,    49,    48,    29,    50,    48,    48,
      48,    48,    56,     3,     7,    48,    48,     4,     5,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     8,
      16,    16,    16,     8,    29,     4,    15,    16,    48,    36,
      48,    48,    48,    48,    48,    48,    48,    48,    48,     7,
      27,    50,    50,     8,    29,    29,    48,    16,     5,    48,
      15,    33,    61,     5,     8,    48,    55,    50,    16,    30,
      48
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    46,    46,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    51,    52,
      53,    54,    55,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     6,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     7,     4,     5,     5,     3,     6,    18,    12,
       6,     3,     0,     1,     3,     1,     2,     0,     1,     2,
       0,     2,     4,     0,     1,     1,     2,     2,     1,     2,
       0,     2,     1,     2
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
  "MainClass", "MethodDeclaration", "ClassDeclaration", "Goal", "LRExp",
  "LRStatement", "LRVarDec", "LRParamater", "LRVarOrStatementDec",
  "LRMethodDec", "StateEpsilon", "LRClassDec", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    56,    56,    61,    65,    71,    76,    80,    84,    88,
      99,   104,   110,   116,   122,   128,   134,   141,   147,   153,
     159,   165,   172,   181,   185,   189,   193,   197,   201,   208,
     214,   219,   224,   233,   240,   245,   251,   256,   263,   270,
     282,   298,   308,   312,   316,   327,   331,   341,   345,   349,
     359,   363,   369,   382,   386,   390,   394,   400,   412,   416,
     424,   428,   438,   442
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
#line 2008 "parser.tab.cc"

