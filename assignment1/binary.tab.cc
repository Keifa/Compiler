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
#line 105 "binary.yy" // lalr1.cc:859
    { root = yystack_[0].value.as< Node > (); }
#line 701 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 109 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 709 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 112 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 717 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 115 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 725 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 118 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("chunk", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 733 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 121 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 741 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 124 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 749 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 127 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 757 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 130 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 765 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 136 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("block", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 773 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 142 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 782 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 146 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 788 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 147 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 796 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 150 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 805 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 154 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 814 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 158 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 823 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 162 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< std::string > ()); }
#line 833 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 167 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[5].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 843 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 172 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[7].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 854 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 178 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[8].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[7].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 865 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 184 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 875 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 189 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 884 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 193 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 893 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 197 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 901 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 203 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 914 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 211 "binary.yy" // lalr1.cc:859
    {
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yystack_[4].value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); }
#line 927 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 222 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("RETURN")); }
#line 935 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 225 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 943 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 228 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ()); }
#line 949 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 232 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", yystack_[0].value.as< std::string > ()); }
#line 955 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 233 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 963 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 236 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 971 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 242 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("varlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 979 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 245 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 987 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 251 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ()); }
#line 993 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 252 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1002 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 256 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1011 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 263 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("namelist", "");
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1019 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 266 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1027 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 272 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("explist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1035 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 275 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1043 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 281 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1049 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 282 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
    }
#line 1060 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 288 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1069 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 295 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1075 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 296 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1085 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 301 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1095 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 309 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1101 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 310 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1111 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 315 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1121 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 323 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1127 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 324 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1133 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 325 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1139 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 326 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1145 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 327 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1153 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 330 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1159 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 331 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1165 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 332 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1171 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 333 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1177 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 337 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1183 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 338 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1189 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 339 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1195 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 343 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1204 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 347 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp("name", yystack_[1].value.as< std::string > ());
      temp.children.push_back(Node(yystack_[3].value.as< Node > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1216 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 357 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", ""); }
#line 1223 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 359 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1231 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 362 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1239 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 365 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("args", yystack_[0].value.as< std::string > ()); }
#line 1247 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 371 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("function", "");
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[2].value.as< std::string > ()));
      Node temp("name");
      temp.children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1259 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 381 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1267 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 384 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1276 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 391 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1284 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 394 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1292 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 397 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1301 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 401 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1309 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 407 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", ""); }
#line 1316 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 409 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1324 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 415 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1332 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 418 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1341 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 422 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1349 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 425 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1358 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 432 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1367 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 436 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node(yystack_[2].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1379 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 443 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1387 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 449 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1393 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 450 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1399 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 454 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1405 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 455 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1411 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 456 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1417 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 457 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1423 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 458 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1429 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 459 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1435 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 460 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1441 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 461 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1447 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 462 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1453 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 463 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1459 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 464 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1465 "binary.tab.cc" // lalr1.cc:859
    break;

  case 99:
#line 468 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1471 "binary.tab.cc" // lalr1.cc:859
    break;

  case 100:
#line 469 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1477 "binary.tab.cc" // lalr1.cc:859
    break;

  case 101:
#line 470 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1483 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1487 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -64;

  const signed char parser::yytable_ninf_ = -63;

  const short int
  parser::yypact_[] =
  {
     515,   -64,   515,    12,    12,     3,    27,    20,    12,   -64,
     515,    12,    25,   515,    10,    33,    56,    74,   191,   201,
     515,    28,   -64,   -64,    57,   -64,   -64,   -64,   -64,    83,
     -64,   -64,   -64,   -64,    95,    45,    80,   -64,   191,   -64,
     -64,   -64,    12,   301,    41,    23,   -64,    19,   -64,    63,
      67,    78,   270,   122,   392,   -64,   100,   112,   -64,   -64,
      12,    15,   -64,    12,   245,   129,   154,   -64,   -64,   -64,
     132,   134,    12,   -64,   270,   194,   105,   515,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    12,
      51,    51,    51,    51,   270,   515,    12,    12,   159,    16,
     165,   166,   -64,   132,    12,    12,   -64,   -64,   -64,    78,
     115,   405,   -64,    -8,    22,   -64,   -64,    12,   435,   -64,
     105,   -64,   -64,   -64,   170,   270,    80,    80,   -64,   -64,
     104,   465,    44,   -64,   515,   -64,    34,   143,   -64,   -64,
     -64,   270,   270,   -64,   -64,   -64,   270,   149,   -64,   -64,
     -64,    12,   515,   113,    12,   515,   176,   159,   -64,   515,
      12,   332,   180,   -64,    12,   515,   257,   183,   -64,   184,
     270,   515,   -64,   362,   185,   515,   -64,   -64,   -64,   515,
     -64,   189,   -64,   -64
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    36,     0,     0,     0,     0,     0,     0,    28,    30,
       0,     0,     0,     2,     3,     5,     0,    61,     0,    13,
      11,     0,    56,    55,     0,    52,    53,    54,   100,     0,
      99,    57,   101,    61,     0,    43,    46,    49,    59,    62,
      58,    60,     0,     0,    39,     0,    31,     0,    39,     0,
      25,    29,    41,     0,     0,     1,     7,     9,     4,     6,
       0,     0,    69,     0,     0,     0,     0,    64,    68,    14,
       0,    36,     0,    77,    85,     0,    79,     0,    97,    98,
      95,    88,    89,    90,    91,    92,    93,    94,    96,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,    63,     8,    10,    12,
      61,     0,    66,     0,     0,    38,    70,     0,     0,    78,
      81,    86,    87,    80,     0,    44,    47,    48,    51,    50,
       0,     0,     0,    40,     0,    76,    73,     0,    33,    32,
      24,    42,    16,    37,    67,    65,    84,     0,    82,    15,
      17,     0,     0,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    71,     0,
      83,     0,    18,     0,     0,     0,    22,    72,    26,     0,
      20,     0,    27,    21
  };

  const short int
  parser::yypgoto_[] =
  {
     -64,   -64,   202,    -1,    55,   -64,    70,   -64,   -64,     0,
      -2,   -52,   182,   -64,     2,    35,     1,    29,    75,   -64,
     -63,   -64,   -14,   -64,   126,    86,   -64,   -64
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    20,    21,    14,   153,    15,    47,    16,    33,
      45,    51,    52,    35,    36,    37,    38,    39,    67,    40,
     102,   137,    41,    75,    76,   123,    89,    42
  };

  const short int
  parser::yytable_[] =
  {
      17,    18,    17,    18,    68,    50,    44,   116,   109,    53,
      17,    18,   113,    17,    18,     1,    22,    23,     1,    48,
      17,    18,   144,    48,    68,    55,    62,   104,    24,    19,
      46,    19,    25,    26,    27,    69,    49,    28,    97,    19,
     140,    11,    19,    29,    11,   132,   134,    58,    99,    19,
     155,    64,    30,    29,     1,    22,    23,   100,    98,    31,
      70,   110,    18,   135,   101,    32,   103,    24,    56,   157,
      59,    25,    26,    27,    96,    56,   124,    17,    18,   104,
      11,   158,    29,    57,    90,    91,    71,    22,    23,    60,
      57,    61,   126,   127,   130,    17,    18,   136,    31,    24,
      68,    77,    98,    25,    26,    27,    19,   -34,    28,   -34,
      72,   150,    11,   104,    29,    73,   151,   152,    78,    79,
     163,    92,    93,    30,    19,   164,   165,   128,   129,    80,
      31,   105,   114,   156,    17,    18,    32,   107,    81,    82,
     121,    83,   122,    84,    85,    86,    87,    88,   -35,   108,
     -35,   162,    17,    18,   167,    17,    18,   115,   169,    17,
      18,    99,   133,    19,   174,    17,    18,   117,   138,   139,
     178,    17,    18,   159,   181,    17,    18,   149,   182,    17,
      18,    19,   160,   168,    19,    34,    43,   172,    19,   145,
     176,   177,   180,    54,    19,    62,   183,    71,    22,    23,
      19,   120,    13,     0,    19,   -62,   148,     0,    19,     0,
      24,    74,     0,     0,    25,    26,    27,     0,    63,    28,
      64,    72,    29,    11,    94,    29,   119,     0,   -62,    65,
       0,     0,   -62,     0,    30,     0,    66,     0,     0,   -62,
       0,    31,     0,     0,     0,   111,   -62,    32,     1,    22,
      23,     0,     0,     0,   118,     0,     0,    74,     0,     0,
       0,    24,     0,   175,     0,    25,    26,    27,     0,     0,
      28,   125,     0,     0,    11,   112,    29,     0,   131,     0,
      78,    79,     0,     0,     0,    30,   141,   142,     0,     0,
       0,    80,    31,    78,    79,     0,     0,     0,    32,   146,
      81,    82,     0,    83,    80,    84,    85,    86,    87,    88,
       0,     0,    95,    81,    82,     0,    83,     0,    84,    85,
      86,    87,    88,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,   161,     0,    80,   166,     0,     0,     0,
       0,     0,   170,   171,    81,    82,   173,    83,     0,    84,
      85,    86,    87,    88,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,   179,     0,    81,    82,     0,    83,     0,
      84,    85,    86,    87,    88,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,    83,     0,
      84,    85,    86,    87,    88,    78,    79,     0,     0,     0,
       0,     0,   106,     0,     0,     0,    80,     0,    78,    79,
       0,     0,     0,   143,     0,    81,    82,     0,    83,    80,
      84,    85,    86,    87,    88,     0,     0,     0,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    88,    78,    79,
       0,     0,     0,   147,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    88,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
     154,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    88,     1,     0,
       0,     2,     0,     3,     0,     4,     0,     0,     0,     5,
       0,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    10,     0,     0,    11
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    18,     7,     3,    70,    60,    10,
      10,    10,    64,    13,    13,     3,     4,     5,     3,     3,
      20,    20,    30,     3,    38,     0,     4,    35,    16,     0,
       3,     2,    20,    21,    22,     7,    16,    25,    15,    10,
     103,    29,    13,    31,    29,    97,    30,    37,    29,    20,
       6,    29,    40,    31,     3,     4,     5,    38,    35,    47,
       3,    61,    61,    47,    45,    53,     3,    16,    13,    35,
      37,    20,    21,    22,    33,    20,    77,    77,    77,    35,
      29,    47,    31,    13,    39,    40,     3,     4,     5,    33,
      20,    35,    90,    91,    95,    95,    95,    99,    47,    16,
     114,     6,    35,    20,    21,    22,    77,    33,    25,    35,
      27,     7,    29,    35,    31,    32,    12,    13,    23,    24,
       7,    41,    42,    40,    95,    12,    13,    92,    93,    34,
      47,     9,     3,   134,   134,   134,    53,    37,    43,    44,
      35,    46,    37,    48,    49,    50,    51,    52,    33,    37,
      35,   152,   152,   152,   155,   155,   155,     3,   159,   159,
     159,    29,     3,   134,   165,   165,   165,    33,     3,     3,
     171,   171,   171,    30,   175,   175,   175,     7,   179,   179,
     179,   152,    33,     7,   155,     3,     4,     7,   159,   114,
       7,     7,     7,    11,   165,     4,     7,     3,     4,     5,
     171,    75,     0,    -1,   175,     4,   120,    -1,   179,    -1,
      16,    29,    -1,    -1,    20,    21,    22,    -1,    27,    25,
      29,    27,    31,    29,    42,    31,    32,    -1,    27,    38,
      -1,    -1,    31,    -1,    40,    -1,    45,    -1,    -1,    38,
      -1,    47,    -1,    -1,    -1,    63,    45,    53,     3,     4,
       5,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      -1,    16,    -1,     6,    -1,    20,    21,    22,    -1,    -1,
      25,    89,    -1,    -1,    29,    30,    31,    -1,    96,    -1,
      23,    24,    -1,    -1,    -1,    40,   104,   105,    -1,    -1,
      -1,    34,    47,    23,    24,    -1,    -1,    -1,    53,   117,
      43,    44,    -1,    46,    34,    48,    49,    50,    51,    52,
      -1,    -1,    11,    43,    44,    -1,    46,    -1,    48,    49,
      50,    51,    52,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    34,   154,    -1,    -1,    -1,
      -1,    -1,   160,    11,    43,    44,   164,    46,    -1,    48,
      49,    50,    51,    52,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    43,    44,    -1,    46,    -1,
      48,    49,    50,    51,    52,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,
      48,    49,    50,    51,    52,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    23,    24,
      -1,    -1,    -1,    28,    -1,    43,    44,    -1,    46,    34,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    43,    44,
      -1,    46,    -1,    48,    49,    50,    51,    52,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    46,    -1,    48,    49,    50,    51,    52,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    46,    -1,    48,    49,    50,    51,    52,     3,    -1,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     6,     8,    10,    14,    16,    17,    18,    19,
      26,    29,    55,    56,    58,    60,    62,    63,    70,    71,
      56,    57,     4,     5,    16,    20,    21,    22,    25,    31,
      40,    47,    53,    63,    66,    67,    68,    69,    70,    71,
      73,    76,    81,    66,     3,    64,     3,    61,     3,    16,
      64,    65,    66,    57,    66,     0,    58,    60,    37,    37,
      33,    35,     4,    27,    29,    38,    45,    72,    76,     7,
       3,     3,    27,    32,    66,    77,    78,     6,    23,    24,
      34,    43,    44,    46,    48,    49,    50,    51,    52,    80,
      39,    40,    41,    42,    66,    11,    33,    15,    35,    29,
      38,    45,    74,     3,    35,     9,    30,    37,    37,    65,
      63,    66,    30,    65,     3,     3,    74,    33,    66,    32,
      78,    35,    37,    79,    57,    66,    68,    68,    69,    69,
      57,    66,    65,     3,    30,    47,    64,    75,     3,     3,
      74,    66,    66,    28,    30,    72,    66,    28,    79,     7,
       7,    12,    13,    59,    35,     6,    57,    35,    47,    30,
      33,    66,    57,     7,    12,    13,    66,    57,     7,    57,
      66,    11,     7,    66,    57,     6,     7,     7,    57,    11,
       7,    57,    57,     7
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     2,     2,     3,     2,
       3,     1,     3,     1,     3,     5,     4,     5,     7,     6,
       8,     9,     7,     3,     4,     2,     4,     5,     1,     2,
       1,     1,     3,     3,     1,     3,     1,     4,     3,     1,
       3,     1,     3,     1,     3,     2,     1,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     2,     3,     1,     1,
       3,     4,     5,     1,     2,     2,     1,     2,     3,     1,
       2,     2,     3,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
       0,   105,   105,   109,   112,   115,   118,   121,   124,   127,
     130,   136,   142,   146,   147,   150,   154,   158,   162,   167,
     172,   178,   184,   189,   193,   197,   203,   211,   222,   225,
     228,   232,   233,   236,   242,   245,   251,   252,   256,   263,
     266,   272,   275,   281,   282,   288,   295,   296,   301,   309,
     310,   315,   323,   324,   325,   326,   327,   330,   331,   332,
     333,   337,   338,   339,   343,   347,   357,   359,   362,   365,
     371,   381,   384,   391,   394,   397,   401,   407,   409,   415,
     418,   422,   425,   432,   436,   443,   449,   450,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   468,
     469,   470
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
#line 1963 "binary.tab.cc" // lalr1.cc:1167
