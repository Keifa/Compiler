// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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


// First part of user declarations.

#line 37 "binary.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 10 "binary.yy" // lalr1.cc:413

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  Node root("root");
  int counter = 0;

#line 60 "binary.tab.cc" // lalr1.cc:413


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 127 "binary.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // elseifLoop
      case 60: // laststat
      case 61: // funcname
      case 62: // varlist
      case 63: // var
      case 64: // namelist
      case 65: // explist
      case 66: // exp
      case 67: // addSubExp
      case 68: // divMulExp
      case 69: // baseExp
      case 70: // prefixexp
      case 71: // functioncall
      case 72: // args
      case 73: // function
      case 74: // funcbody
      case 75: // parlist
      case 76: // tableconstructor
      case 77: // fieldlist
      case 78: // field
      case 79: // fieldsep
      case 80: // binop
      case 81: // unop
        value.move< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // STR
      case 5: // NUMBER
      case 6: // DO
      case 7: // END
      case 8: // WHILE
      case 9: // UNTIL
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // FOR
      case 15: // IN
      case 16: // FUNCTION
      case 17: // LOCAL
      case 18: // RETURN
      case 19: // BREAK
      case 20: // NIL
      case 21: // FALSE
      case 22: // TRUE
      case 23: // AND
      case 24: // OR
      case 25: // NOT
      case 26: // REPEAT
      case 27: // START_SQUARE_BRACKET
      case 28: // END_SQUARE_BRACKET
      case 29: // START_PARENTHESES
      case 30: // END_PARENTHESES
      case 31: // START_BRACKET
      case 32: // END_BRACKET
      case 33: // EQUAL
      case 34: // EQUALEQUAL
      case 35: // COMMA
      case 36: // NEWLINE
      case 37: // SEMICOLON
      case 38: // COLON
      case 39: // PLUS
      case 40: // MINUS
      case 41: // STAR
      case 42: // SLASH
      case 43: // CARET
      case 44: // PERCENT
      case 45: // DOT
      case 46: // DOTDOT
      case 47: // DOTDOTDOT
      case 48: // LESS
      case 49: // LESSEQUAL
      case 50: // BIGGER
      case 51: // BIGGEREQUAL
      case 52: // NOTEQUAL
      case 53: // HASHTAG
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // elseifLoop
      case 60: // laststat
      case 61: // funcname
      case 62: // varlist
      case 63: // var
      case 64: // namelist
      case 65: // explist
      case 66: // exp
      case 67: // addSubExp
      case 68: // divMulExp
      case 69: // baseExp
      case 70: // prefixexp
      case 71: // functioncall
      case 72: // args
      case 73: // function
      case 74: // funcbody
      case 75: // parlist
      case 76: // tableconstructor
      case 77: // fieldlist
      case 78: // field
      case 79: // fieldsep
      case 80: // binop
      case 81: // unop
        value.copy< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // STR
      case 5: // NUMBER
      case 6: // DO
      case 7: // END
      case 8: // WHILE
      case 9: // UNTIL
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // FOR
      case 15: // IN
      case 16: // FUNCTION
      case 17: // LOCAL
      case 18: // RETURN
      case 19: // BREAK
      case 20: // NIL
      case 21: // FALSE
      case 22: // TRUE
      case 23: // AND
      case 24: // OR
      case 25: // NOT
      case 26: // REPEAT
      case 27: // START_SQUARE_BRACKET
      case 28: // END_SQUARE_BRACKET
      case 29: // START_PARENTHESES
      case 30: // END_PARENTHESES
      case 31: // START_BRACKET
      case 32: // END_BRACKET
      case 33: // EQUAL
      case 34: // EQUALEQUAL
      case 35: // COMMA
      case 36: // NEWLINE
      case 37: // SEMICOLON
      case 38: // COLON
      case 39: // PLUS
      case 40: // MINUS
      case 41: // STAR
      case 42: // SLASH
      case 43: // CARET
      case 44: // PERCENT
      case 45: // DOT
      case 46: // DOTDOT
      case 47: // DOTDOTDOT
      case 48: // LESS
      case 49: // LESSEQUAL
      case 50: // BIGGER
      case 51: // BIGGEREQUAL
      case 52: // NOTEQUAL
      case 53: // HASHTAG
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
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

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // elseifLoop
      case 60: // laststat
      case 61: // funcname
      case 62: // varlist
      case 63: // var
      case 64: // namelist
      case 65: // explist
      case 66: // exp
      case 67: // addSubExp
      case 68: // divMulExp
      case 69: // baseExp
      case 70: // prefixexp
      case 71: // functioncall
      case 72: // args
      case 73: // function
      case 74: // funcbody
      case 75: // parlist
      case 76: // tableconstructor
      case 77: // fieldlist
      case 78: // field
      case 79: // fieldsep
      case 80: // binop
      case 81: // unop
        yylhs.value.build< Node > ();
        break;

      case 3: // NAME
      case 4: // STR
      case 5: // NUMBER
      case 6: // DO
      case 7: // END
      case 8: // WHILE
      case 9: // UNTIL
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // FOR
      case 15: // IN
      case 16: // FUNCTION
      case 17: // LOCAL
      case 18: // RETURN
      case 19: // BREAK
      case 20: // NIL
      case 21: // FALSE
      case 22: // TRUE
      case 23: // AND
      case 24: // OR
      case 25: // NOT
      case 26: // REPEAT
      case 27: // START_SQUARE_BRACKET
      case 28: // END_SQUARE_BRACKET
      case 29: // START_PARENTHESES
      case 30: // END_PARENTHESES
      case 31: // START_BRACKET
      case 32: // END_BRACKET
      case 33: // EQUAL
      case 34: // EQUALEQUAL
      case 35: // COMMA
      case 36: // NEWLINE
      case 37: // SEMICOLON
      case 38: // COLON
      case 39: // PLUS
      case 40: // MINUS
      case 41: // STAR
      case 42: // SLASH
      case 43: // CARET
      case 44: // PERCENT
      case 45: // DOT
      case 46: // DOTDOT
      case 47: // DOTDOTDOT
      case 48: // LESS
      case 49: // LESSEQUAL
      case 50: // BIGGER
      case 51: // BIGGEREQUAL
      case 52: // NOTEQUAL
      case 53: // HASHTAG
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 104 "binary.yy" // lalr1.cc:859
    { root = yystack_[0].value.as< Node > (); }
#line 701 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 108 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 709 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 111 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 717 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 114 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("chunk", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< std::string > ()); }
#line 725 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 117 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 733 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 120 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 741 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 123 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 749 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 129 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("block", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 757 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 135 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 766 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 139 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 772 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 140 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 780 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 143 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 789 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 147 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 798 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 151 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 807 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 155 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp = Node("else");
      temp.children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 819 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 162 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[5].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 829 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 167 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[7].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 840 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 173 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[8].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[7].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 851 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 179 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 861 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 184 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 870 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 188 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 879 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 192 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 887 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 198 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 898 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 204 "binary.yy" // lalr1.cc:859
    {
      Node temp("elseif");
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yystack_[4].value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); }
#line 909 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 213 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("RETURN")); }
#line 917 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 216 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 925 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 219 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ()); }
#line 931 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 223 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", yystack_[0].value.as< std::string > ()); }
#line 937 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 224 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 945 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 227 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 953 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 233 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("varlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 961 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 236 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 969 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 242 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ()); }
#line 975 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 243 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 984 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 247 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 993 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 254 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("namelist", "");
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1001 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 257 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1009 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 263 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("explist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1017 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 266 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1025 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 272 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1031 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 273 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
    }
#line 1042 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 279 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1051 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 286 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1057 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 287 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1067 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 292 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1077 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 300 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1083 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 301 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1093 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 306 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1103 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 314 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1109 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 315 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1115 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 316 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1121 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 317 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1127 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 318 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1135 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 321 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1141 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 322 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1147 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 323 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1153 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 324 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1159 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 328 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1165 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 329 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1171 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 330 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1177 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 334 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1186 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 338 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp("name", yystack_[1].value.as< std::string > ());
      temp.children.push_back(Node(yystack_[3].value.as< Node > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1198 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 348 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", ""); }
#line 1205 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 350 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1213 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 353 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1221 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 356 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("args", yystack_[0].value.as< std::string > ()); }
#line 1229 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 362 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("function", "");
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[2].value.as< std::string > ()));
      Node temp("name");
      temp.children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1241 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 372 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1249 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 375 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1258 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 382 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1266 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 385 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1274 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 388 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1282 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 391 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1291 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 398 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", ""); }
#line 1298 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 400 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1306 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 406 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1314 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 409 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      //$$.children.push_back($2);
    }
#line 1324 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 414 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1332 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 417 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      //$1.children.push_back($3);
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1341 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 424 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1350 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 428 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node(yystack_[2].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1362 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 435 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1370 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 441 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1376 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 442 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1382 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 446 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1388 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 447 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1394 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 448 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1400 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 449 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1406 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 450 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1412 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 451 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1418 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 452 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1424 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 453 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1430 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 454 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1436 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 455 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1442 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 456 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1448 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 460 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1454 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 461 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1460 "binary.tab.cc" // lalr1.cc:859
    break;

  case 99:
#line 462 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1466 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1470 "binary.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -58;

  const signed char parser::yytable_ninf_ = -61;

  const short int
  parser::yypact_[] =
  {
     431,   -58,   431,   308,   308,    17,    31,    14,   308,   -58,
     431,   308,   -58,     7,   448,   -58,   -58,     3,    65,    76,
      48,   448,    30,   -58,   -58,    51,   -58,   -58,   -58,   -58,
     209,   -58,   -58,   -58,   -58,    21,    96,   118,   -58,    76,
     -58,   -58,   -58,   308,   320,    15,    -9,   -58,    45,   -58,
      60,    25,    50,   532,    82,   446,   -58,   -58,   -58,   -58,
     308,    22,   -58,   308,   285,    99,   106,   -58,   -58,   -58,
      70,    79,   308,   -58,   532,   255,    73,   431,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   308,
      37,    37,    37,    37,   532,   431,   308,   308,   114,     2,
     127,   131,   -58,    70,   308,   308,   -58,    50,    78,   459,
     -58,    57,     4,   -58,   -58,   308,   489,   -58,    73,   -58,
     -58,   -58,   130,   532,   118,   118,   -58,   -58,   113,   519,
      12,   -58,   431,   -58,   -19,   110,   -58,   -58,   -58,   532,
     532,   -58,   -58,   -58,   532,   134,   -58,   -58,   -58,   308,
     431,   115,   308,   431,   141,   114,   -58,   431,   308,   351,
     164,   -58,   308,   431,    95,   176,   -58,   178,   532,   431,
     -58,   381,   181,   431,   -58,   -58,   -58,   431,   -58,   182,
     -58,   -58
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    34,     0,     0,     0,     0,     0,     0,    26,    28,
       0,     0,     5,     0,     2,     3,     4,     0,    59,     0,
      11,     9,     0,    54,    53,     0,    50,    51,    52,    98,
       0,    97,    55,    99,    59,     0,    41,    44,    47,    57,
      60,    56,    58,     0,     0,    37,     0,    29,     0,    37,
       0,    23,    27,    39,     0,     0,     1,     8,     6,     7,
       0,     0,    67,     0,     0,     0,     0,    62,    66,    12,
       0,    34,     0,    75,    83,     0,    77,     0,    95,    96,
      93,    86,    87,    88,    89,    90,    91,    92,    94,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    61,    10,    59,     0,
      64,     0,     0,    36,    68,     0,     0,    76,    79,    84,
      85,    78,     0,    42,    45,    46,    49,    48,     0,     0,
       0,    38,     0,    72,    71,     0,    31,    30,    22,    40,
      14,    35,    65,    63,    82,     0,    80,    13,    15,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    69,     0,    81,     0,
      16,     0,     0,     0,    20,    70,    24,     0,    18,     0,
      25,    19
  };

  const short int
  parser::yypgoto_[] =
  {
     -58,   -58,   190,    -1,    67,   -58,    68,   -58,   -58,     0,
       5,   -41,   112,   -58,    75,    88,     1,    29,    81,   -58,
     -57,   -58,   -15,   -58,   116,    77,   -58,   -58
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    13,    21,    22,    15,   151,    16,    48,    17,    34,
      46,    52,    53,    36,    37,    38,    39,    40,    67,    41,
     102,   135,    42,    75,    76,   121,    89,    43
  };

  const short int
  parser::yytable_[] =
  {
      18,    19,    18,    19,    68,    49,    97,    56,    62,    54,
      18,    19,    51,   114,    18,    19,   155,    49,   153,   107,
      45,    18,    19,   111,    68,     1,    98,    77,   156,    20,
      50,    20,   132,    64,    47,    30,    60,    69,    61,    20,
       1,    23,    24,    20,    78,    79,   138,   104,    96,   133,
      20,    11,   -60,    25,    70,    80,   130,    26,    27,    28,
      98,   108,    19,   103,    81,    82,    11,    83,    30,    84,
      85,    86,    87,    88,    99,   -60,   122,    18,    19,   -60,
      62,    58,    59,   100,    32,   104,   -60,   142,    58,    59,
     101,   105,   104,   -60,   128,    18,    19,    68,   -32,    99,
     -32,   173,   112,    63,   134,    64,    20,    30,   119,   113,
     120,   -33,   115,   -33,    65,    35,    44,   131,    78,    79,
     148,    66,   161,    55,    20,   149,   150,   162,   163,    80,
     136,   154,    18,    19,   137,    90,    91,   147,    81,    82,
     157,    83,    74,    84,    85,    86,    87,    88,   166,   160,
      18,    19,   165,    18,    19,    94,   167,    18,    19,    92,
      93,    20,   172,    18,    19,   124,   125,   158,   176,    18,
      19,   170,   179,    18,    19,   109,   180,    18,    19,    20,
     126,   127,    20,   174,   116,   175,    20,    74,   178,   181,
      14,   118,    20,   143,     0,   146,     0,     0,    20,     0,
       0,   123,    20,     0,     0,     0,    20,     0,   129,     0,
       0,     0,    71,    23,    24,     0,   139,   140,     0,     0,
       0,     0,     0,     0,     0,    25,     0,   144,     0,    26,
      27,    28,     0,     0,    29,     0,    72,     0,    11,     0,
      30,    73,     0,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    32,     0,    71,    23,
      24,   159,    33,     0,   164,     0,     0,     0,     0,     0,
     168,    25,     0,     0,   171,    26,    27,    28,     0,     0,
      29,     0,    72,     0,    11,     0,    30,   117,     1,    23,
      24,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,    25,    32,     0,     0,    26,    27,    28,    33,     0,
      29,     1,    23,    24,    11,   110,    30,     0,     0,     0,
       0,     0,     0,     0,    25,    31,     0,     0,    26,    27,
      28,    95,    32,    29,     0,     0,     0,    11,    33,    30,
       0,     0,     0,    78,    79,     0,     0,     0,    31,     0,
       0,     0,     0,     0,    80,    32,     0,     0,     0,     0,
       0,    33,   169,    81,    82,     0,    83,     0,    84,    85,
      86,    87,    88,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,   177,     0,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,     1,     0,     0,     2,     0,     3,
       0,     4,     0,     0,     0,     5,     0,     6,     7,     8,
       9,     1,     0,     0,     2,     0,     3,    10,     4,     0,
      11,     0,     5,     0,     6,     7,     8,     9,    12,    78,
      79,     0,     0,     0,    10,     0,   106,    11,     0,     0,
      80,     0,    78,    79,     0,    57,     0,   141,     0,    81,
      82,     0,    83,    80,    84,    85,    86,    87,    88,     0,
       0,     0,    81,    82,     0,    83,     0,    84,    85,    86,
      87,    88,    78,    79,     0,     0,     0,   145,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    82,     0,    83,     0,    84,    85,    86,
      87,    88,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,   152,    78,    79,     0,     0,     0,
       0,     0,    81,    82,     0,    83,    80,    84,    85,    86,
      87,    88,     0,     0,     0,    81,    82,     0,    83,     0,
      84,    85,    86,    87,    88
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    19,     3,    15,     0,     4,    10,
      10,    10,     7,    70,    14,    14,    35,     3,     6,    60,
       3,    21,    21,    64,    39,     3,    35,     6,    47,     0,
      16,     2,    30,    29,     3,    31,    33,     7,    35,    10,
       3,     4,     5,    14,    23,    24,   103,    35,    33,    47,
      21,    29,     4,    16,     3,    34,    97,    20,    21,    22,
      35,    61,    61,     3,    43,    44,    29,    46,    31,    48,
      49,    50,    51,    52,    29,    27,    77,    77,    77,    31,
       4,    14,    14,    38,    47,    35,    38,    30,    21,    21,
      45,     9,    35,    45,    95,    95,    95,   112,    33,    29,
      35,     6,     3,    27,    99,    29,    77,    31,    35,     3,
      37,    33,    33,    35,    38,     3,     4,     3,    23,    24,
       7,    45,     7,    11,    95,    12,    13,    12,    13,    34,
       3,   132,   132,   132,     3,    39,    40,     7,    43,    44,
      30,    46,    30,    48,    49,    50,    51,    52,     7,   150,
     150,   150,   153,   153,   153,    43,   157,   157,   157,    41,
      42,   132,   163,   163,   163,    90,    91,    33,   169,   169,
     169,     7,   173,   173,   173,    63,   177,   177,   177,   150,
      92,    93,   153,     7,    72,     7,   157,    75,     7,     7,
       0,    75,   163,   112,    -1,   118,    -1,    -1,   169,    -1,
      -1,    89,   173,    -1,    -1,    -1,   177,    -1,    96,    -1,
      -1,    -1,     3,     4,     5,    -1,   104,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,   115,    -1,    20,
      21,    22,    -1,    -1,    25,    -1,    27,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,     3,     4,
       5,   149,    53,    -1,   152,    -1,    -1,    -1,    -1,    -1,
     158,    16,    -1,    -1,   162,    20,    21,    22,    -1,    -1,
      25,    -1,    27,    -1,    29,    -1,    31,    32,     3,     4,
       5,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    16,    47,    -1,    -1,    20,    21,    22,    53,    -1,
      25,     3,     4,     5,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    40,    -1,    -1,    20,    21,
      22,    11,    47,    25,    -1,    -1,    -1,    29,    53,    31,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    34,    47,    -1,    -1,    -1,    -1,
      -1,    53,    11,    43,    44,    -1,    46,    -1,    48,    49,
      50,    51,    52,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    43,    44,    -1,    46,    -1,    48,
      49,    50,    51,    52,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,    48,
      49,    50,    51,    52,     3,    -1,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    14,    -1,    16,    17,    18,
      19,     3,    -1,    -1,     6,    -1,     8,    26,    10,    -1,
      29,    -1,    14,    -1,    16,    17,    18,    19,    37,    23,
      24,    -1,    -1,    -1,    26,    -1,    30,    29,    -1,    -1,
      34,    -1,    23,    24,    -1,    37,    -1,    28,    -1,    43,
      44,    -1,    46,    34,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    43,    44,    -1,    46,    -1,    48,    49,    50,
      51,    52,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    46,    -1,    48,    49,    50,
      51,    52,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    23,    24,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    46,    34,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,
      48,    49,    50,    51,    52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     6,     8,    10,    14,    16,    17,    18,    19,
      26,    29,    37,    55,    56,    58,    60,    62,    63,    70,
      71,    56,    57,     4,     5,    16,    20,    21,    22,    25,
      31,    40,    47,    53,    63,    66,    67,    68,    69,    70,
      71,    73,    76,    81,    66,     3,    64,     3,    61,     3,
      16,    64,    65,    66,    57,    66,     0,    37,    58,    60,
      33,    35,     4,    27,    29,    38,    45,    72,    76,     7,
       3,     3,    27,    32,    66,    77,    78,     6,    23,    24,
      34,    43,    44,    46,    48,    49,    50,    51,    52,    80,
      39,    40,    41,    42,    66,    11,    33,    15,    35,    29,
      38,    45,    74,     3,    35,     9,    30,    65,    63,    66,
      30,    65,     3,     3,    74,    33,    66,    32,    78,    35,
      37,    79,    57,    66,    68,    68,    69,    69,    57,    66,
      65,     3,    30,    47,    64,    75,     3,     3,    74,    66,
      66,    28,    30,    72,    66,    28,    79,     7,     7,    12,
      13,    59,    35,     6,    57,    35,    47,    30,    33,    66,
      57,     7,    12,    13,    66,    57,     7,    57,    66,    11,
       7,    66,    57,     6,     7,     7,    57,    11,     7,    57,
      57,     7
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       3,     1,     3,     5,     4,     5,     7,     6,     8,     9,
       7,     3,     4,     2,     4,     5,     1,     2,     1,     1,
       3,     3,     1,     3,     1,     4,     3,     1,     3,     1,
       3,     1,     3,     2,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     4,     2,     3,     1,     1,     3,     4,
       5,     1,     1,     2,     2,     2,     3,     1,     2,     2,
       3,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "STR", "NUMBER", "DO",
  "END", "WHILE", "UNTIL", "IF", "THEN", "ELSEIF", "ELSE", "FOR", "IN",
  "FUNCTION", "LOCAL", "RETURN", "BREAK", "NIL", "FALSE", "TRUE", "AND",
  "OR", "NOT", "REPEAT", "START_SQUARE_BRACKET", "END_SQUARE_BRACKET",
  "START_PARENTHESES", "END_PARENTHESES", "START_BRACKET", "END_BRACKET",
  "EQUAL", "EQUALEQUAL", "COMMA", "NEWLINE", "SEMICOLON", "COLON", "PLUS",
  "MINUS", "STAR", "SLASH", "CARET", "PERCENT", "DOT", "DOTDOT",
  "DOTDOTDOT", "LESS", "LESSEQUAL", "BIGGER", "BIGGEREQUAL", "NOTEQUAL",
  "HASHTAG", "$accept", "root", "chunk", "block", "stat", "elseifLoop",
  "laststat", "funcname", "varlist", "var", "namelist", "explist", "exp",
  "addSubExp", "divMulExp", "baseExp", "prefixexp", "functioncall", "args",
  "function", "funcbody", "parlist", "tableconstructor", "fieldlist",
  "field", "fieldsep", "binop", "unop", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   104,   104,   108,   111,   114,   117,   120,   123,   129,
     135,   139,   140,   143,   147,   151,   155,   162,   167,   173,
     179,   184,   188,   192,   198,   204,   213,   216,   219,   223,
     224,   227,   233,   236,   242,   243,   247,   254,   257,   263,
     266,   272,   273,   279,   286,   287,   292,   300,   301,   306,
     314,   315,   316,   317,   318,   321,   322,   323,   324,   328,
     329,   330,   334,   338,   348,   350,   353,   356,   362,   372,
     375,   382,   385,   388,   391,   398,   400,   406,   409,   414,
     417,   424,   428,   435,   441,   442,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   460,   461,   462
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1951 "binary.tab.cc" // lalr1.cc:1167
