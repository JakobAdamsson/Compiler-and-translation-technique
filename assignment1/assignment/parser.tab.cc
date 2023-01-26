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
#line 11 "parser.yy"

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
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_lrecexp: // lrecexp
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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INTARR: // INTARR
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
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_lrecexp: // lrecexp
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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INTARR: // INTARR
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
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_lrecexp: // lrecexp
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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INTARR: // INTARR
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
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_lrecexp: // lrecexp
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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INTARR: // INTARR
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
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Term: // Term
      case symbol_kind::S_lrecexp: // lrecexp
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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INTARR: // INTARR
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
  case 2: // root: Expression
#line 34 "parser.yy"
                 {root = yystack_[0].value.as < Node * > ();}
#line 720 "parser.tab.cc"
    break;

  case 3: // Expression: Term
#line 68 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 729 "parser.tab.cc"
    break;

  case 4: // Expression: Expression AND Term
#line 74 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("AND", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 740 "parser.tab.cc"
    break;

  case 5: // Expression: Expression OR Term
#line 81 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("OR", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 751 "parser.tab.cc"
    break;

  case 6: // Expression: Expression LT Term
#line 88 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("LT", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 762 "parser.tab.cc"
    break;

  case 7: // Expression: Expression GT Term
#line 95 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("GT", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 773 "parser.tab.cc"
    break;

  case 8: // Expression: Expression EQ Term
#line 102 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("EQ", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 784 "parser.tab.cc"
    break;

  case 9: // Expression: Expression PLUS Term
#line 109 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("PLUS", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 795 "parser.tab.cc"
    break;

  case 10: // Expression: Expression MINUS Term
#line 116 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("MINUS", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 806 "parser.tab.cc"
    break;

  case 11: // Expression: Expression TIMES Term
#line 123 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("TIMES", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 817 "parser.tab.cc"
    break;

  case 12: // Expression: Expression DIVIDE Term
#line 130 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("DIVIDE", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 828 "parser.tab.cc"
    break;

  case 13: // Expression: Expression LBRACKET Expression RBRACKET
#line 137 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", yystack_[2].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 840 "parser.tab.cc"
    break;

  case 14: // Expression: Expression DOT LENGTH
#line 145 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("DOT", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("LENGTH", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 851 "parser.tab.cc"
    break;

  case 15: // Expression: Expression DOT ID LPAREN lrecexp RPAREN
#line 153 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("DOT", yystack_[4].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("ID", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", yystack_[2].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 865 "parser.tab.cc"
    break;

  case 16: // Term: NUM
#line 163 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("NUM", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 874 "parser.tab.cc"
    break;

  case 17: // Term: TRUE
#line 168 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("TRUE", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 883 "parser.tab.cc"
    break;

  case 18: // Term: FALSE
#line 174 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("FALSE", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 892 "parser.tab.cc"
    break;

  case 19: // Term: ID
#line 180 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("ID", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 901 "parser.tab.cc"
    break;

  case 20: // Term: THIS
#line 186 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("THIS", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 910 "parser.tab.cc"
    break;

  case 21: // Term: NEW INT LBRACKET Expression RBRACKET
#line 192 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", yystack_[4].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("INT", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", yystack_[2].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 923 "parser.tab.cc"
    break;

  case 22: // Term: NEW ID LPAREN RPAREN
#line 202 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", yystack_[3].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("ID", yystack_[2].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 935 "parser.tab.cc"
    break;

  case 23: // Term: NOT Expression
#line 211 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("NOT", yystack_[1].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 945 "parser.tab.cc"
    break;

  case 24: // Term: LPAREN Expression RPAREN
#line 218 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", yystack_[2].value.as < std::string > (), yylineno));
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 956 "parser.tab.cc"
    break;

  case 26: // lrecexp: Expression
#line 224 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 962 "parser.tab.cc"
    break;

  case 27: // lrecexp: lrecexp COMMA Expression
#line 225 "parser.yy"
      {
        yylhs.value.as < Node * > () = new Node("lrecexp", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(new Node("COMMA", yystack_[1].value.as < std::string > (), yylineno));
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 973 "parser.tab.cc"
    break;


#line 977 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -14;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      82,   -14,   -14,   -14,   -14,   -14,     1,    82,    82,     5,
      53,   -14,     2,    -8,    53,     7,   -14,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    -5,    82,    -4,
     -14,    30,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,    -6,   -14,    41,   -14,   -14,    82,   -14,    53,   -13,
     -14,    82,    53
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    19,    16,    17,    18,    20,     0,     0,     0,     0,
       2,     3,     0,     0,    23,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    14,     0,    22,    13,    25,    21,    26,     0,
      15,     0,    27
  };

  const signed char
  parser::yypgoto_[] =
  {
     -14,   -14,    -7,    62,   -14
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     9,    10,    11,    49
  };

  const signed char
  parser::yytable_[] =
  {
      14,    15,    41,    50,    12,    16,    28,    29,    13,    46,
      31,    17,    44,     0,     0,     0,     0,    51,     0,     0,
       0,    43,    42,    30,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    17,    45,     0,     0,     0,    48,
       0,     0,     0,     0,    52,    17,    47,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     1,
       0,     2,     3,     4,     5,     6,     7,     8
  };

  const signed char
  parser::yycheck_[] =
  {
       7,     8,     7,    16,     3,     0,     4,    15,     7,    15,
      17,     4,    16,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    28,    27,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     4,     5,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,     4,     5,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     4,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     7,
      -1,     9,    10,    11,    12,    13,    14,    15
  };

  const signed char
  parser::yystos_[] =
  {
       0,     7,     9,    10,    11,    12,    13,    14,    15,    37,
      38,    39,     3,     7,    38,    38,     0,     4,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     4,    15,
      16,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,     7,    27,    38,    16,     5,    15,     5,    38,    40,
      16,    30,    38
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    40,    40,    40
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     6,     1,     1,     1,     1,
       1,     5,     4,     2,     3,     0,     1,     3
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
  "IF", "ELSE", "WHILE", "PRINT", "INTARR", "$accept", "root",
  "Expression", "Term", "lrecexp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    34,    34,    67,    73,    80,    87,    94,   101,   108,
     115,   122,   129,   136,   144,   152,   162,   167,   173,   179,
     185,   191,   201,   210,   217,   224,   224,   224
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
#line 1475 "parser.tab.cc"

