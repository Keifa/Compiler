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
      case 68: // mulDivExp
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
      case 80: // addSubBinop
      case 81: // mulDivBinop
      case 82: // binop
      case 83: // unop
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
      case 68: // mulDivExp
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
      case 80: // addSubBinop
      case 81: // mulDivBinop
      case 82: // binop
      case 83: // unop
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
      case 68: // mulDivExp
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
      case 80: // addSubBinop
      case 81: // mulDivBinop
      case 82: // binop
      case 83: // unop
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
#line 106 "binary.yy" // lalr1.cc:859
    { root.children.push_back(yystack_[0].value.as< Node > ()); }
#line 707 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 110 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 715 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 113 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 723 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 116 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 731 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 119 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("chunk", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 739 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 122 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 747 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 125 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 755 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 128 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 763 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 131 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 771 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 137 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("block", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 779 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 143 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 788 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 147 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 794 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 148 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 802 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 151 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 811 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 155 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 820 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 159 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 829 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 163 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< std::string > ()); }
#line 839 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 168 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[5].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 849 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 173 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[7].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 860 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 179 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[8].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[7].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 871 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 185 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 881 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 190 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 890 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 194 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 899 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 198 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 907 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 204 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 920 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 212 "binary.yy" // lalr1.cc:859
    {
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yystack_[4].value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); }
#line 933 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 223 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("RETURN")); }
#line 941 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 226 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 949 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 229 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ()); }
#line 955 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 233 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", yystack_[0].value.as< std::string > ()); }
#line 961 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 234 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 969 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 237 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 977 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 243 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("varlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 985 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 246 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 993 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 252 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ()); }
#line 999 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 253 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1008 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 257 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1017 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 264 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("namelist", "");
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1025 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 267 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1033 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 273 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("explist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1041 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 276 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1049 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 282 "binary.yy" // lalr1.cc:859
    { std::cout << "exp\n"; yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1055 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 283 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1065 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 288 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1074 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 295 "binary.yy" // lalr1.cc:859
    { std::cout << "addSubExp\n"; yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1080 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 296 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1090 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 304 "binary.yy" // lalr1.cc:859
    { std::cout << "mulDivExp\n"; yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1096 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 305 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1106 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 313 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1112 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 314 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1118 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 315 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1124 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 316 "binary.yy" // lalr1.cc:859
    { std::cout << "baseExp\n"; yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1130 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 317 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1138 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 320 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1144 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 321 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1150 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 322 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1156 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 323 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1162 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 327 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1168 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 328 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1174 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 329 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1180 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 333 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1189 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 337 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp("name", yystack_[1].value.as< std::string > ());
      temp.children.push_back(Node(yystack_[3].value.as< Node > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1201 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 347 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", ""); }
#line 1208 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 349 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1216 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 352 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1224 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 355 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("args", yystack_[0].value.as< std::string > ()); }
#line 1232 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 361 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("function", "");
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[2].value.as< std::string > ()));
      Node temp("name");
      temp.children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1244 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 371 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1252 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 374 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1261 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 381 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1269 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 384 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1277 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 387 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1286 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 391 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1294 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 397 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", ""); }
#line 1301 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 399 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1309 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 405 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1317 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 408 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1326 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 412 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1334 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 415 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1343 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 422 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1352 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 426 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node(yystack_[2].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1364 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 433 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1372 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 439 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1378 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 440 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1384 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 444 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1390 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 445 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1396 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 449 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1402 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 450 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1408 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 454 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1414 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 455 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1420 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 456 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1426 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 457 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1432 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 458 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1438 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 459 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1444 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 460 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1450 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 461 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1456 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 462 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1462 "binary.tab.cc" // lalr1.cc:859
    break;

  case 99:
#line 463 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1468 "binary.tab.cc" // lalr1.cc:859
    break;

  case 100:
#line 464 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1474 "binary.tab.cc" // lalr1.cc:859
    break;

  case 101:
#line 468 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1480 "binary.tab.cc" // lalr1.cc:859
    break;

  case 102:
#line 469 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1486 "binary.tab.cc" // lalr1.cc:859
    break;

  case 103:
#line 470 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1492 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1496 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -52;

  const signed char parser::yytable_ninf_ = -61;

  const short int
  parser::yypact_[] =
  {
     517,   -52,   517,    12,    12,    33,    37,    52,    12,   -52,
     517,    12,    60,   517,    32,    54,    77,    78,    43,    62,
     517,    75,   -52,   -52,   101,   -52,   -52,   -52,   -52,   194,
     -52,   -52,   -52,   -52,    95,   -52,   -32,    53,    43,   -52,
     -52,   -52,    12,   291,    82,    -9,   -52,     6,   -52,   113,
      86,    88,   467,   115,   381,   -52,    90,    91,   -52,   -52,
      12,     9,   -52,    12,   246,   122,   127,   -52,   -52,   -52,
     103,   104,    12,   -52,   467,   208,    50,   517,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,    12,
     -52,   -52,   307,   -52,   -52,   307,   467,   517,    12,    12,
     133,    20,   139,   147,   -52,   103,    12,    12,   -52,   -52,
     -52,    88,    87,   394,   -52,    -5,    44,   -52,   -52,    12,
     424,   -52,    50,   -52,   -52,   -52,   150,   467,   -52,   -52,
      51,   454,    21,   -52,   517,   -52,    45,   132,   -52,   -52,
     -52,   467,   467,   -52,   -52,   -52,   467,   134,   -52,   -52,
     -52,    12,   517,    96,    12,   517,   161,   133,   -52,   517,
      12,   321,   162,   -52,    12,   517,   257,   166,   -52,   170,
     467,   517,   -52,   351,   175,   517,   -52,   -52,   -52,   517,
     -52,   176,   -52,   -52
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    36,     0,     0,     0,     0,     0,     0,    28,    30,
       0,     0,     0,     2,     3,     5,     0,    59,     0,    13,
      11,     0,    54,    53,     0,    50,    51,    52,   102,     0,
     101,    55,   103,    59,     0,    43,    46,    48,    57,    60,
      56,    58,     0,     0,    39,     0,    31,     0,    39,     0,
      25,    29,    41,     0,     0,     1,     7,     9,     4,     6,
       0,     0,    67,     0,     0,     0,     0,    62,    66,    14,
       0,    36,     0,    75,    83,     0,    77,     0,    99,   100,
      97,    90,    91,    92,    93,    94,    95,    96,    98,     0,
      86,    87,     0,    89,    88,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,    61,     8,
      10,    12,    59,     0,    64,     0,     0,    38,    68,     0,
       0,    76,    79,    84,    85,    78,     0,    44,    47,    49,
       0,     0,     0,    40,     0,    74,    71,     0,    33,    32,
      24,    42,    16,    37,    65,    63,    82,     0,    80,    15,
      17,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    69,     0,
      81,     0,    18,     0,     0,     0,    22,    70,    26,     0,
      20,     0,    27,    21
  };

  const short int
  parser::yypgoto_[] =
  {
     -52,   -52,   185,    -1,    66,   -52,    70,   -52,   -52,     0,
      -2,   -42,    42,   -52,    94,    92,     1,    29,    73,   -52,
     -51,   -52,   -14,   -52,   116,    68,   -52,   -52,   -52,   -52
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    20,    21,    14,   153,    15,    47,    16,    33,
      45,    51,    52,    35,    36,    37,    38,    39,    67,    40,
     104,   137,    41,    75,    76,   125,    92,    95,    89,    42
  };

  const short int
  parser::yytable_[] =
  {
      17,    18,    17,    18,    68,    50,    99,    90,    91,    53,
      17,    18,     1,    17,    18,     1,    22,    23,   111,   118,
      17,    18,   115,    48,    68,   144,   100,   155,    24,    19,
     106,    19,    25,    26,    27,   101,    44,    28,    11,    19,
      46,    11,    19,    29,   102,    34,    43,    62,    62,    19,
     134,   103,    30,    54,   140,    48,   106,   132,   150,    31,
      55,   112,    18,   151,   152,    32,   -60,   135,    49,    58,
      63,    74,    64,    64,    29,    29,   126,    17,    18,    56,
     157,    65,    69,    57,    96,   123,    56,   124,    66,   -60,
      57,    59,   158,   -60,    93,    94,   130,    17,    18,   136,
     -60,    77,    68,   163,    70,   113,    19,   -60,   164,   165,
      60,   -34,    61,   -34,   120,    98,   105,    74,    78,    79,
     -35,   100,   -35,   106,   107,   116,    19,   109,   110,    80,
     117,   127,   101,   156,    17,    18,   133,   119,    81,    82,
     131,    83,   138,    84,    85,    86,    87,    88,   141,   142,
     139,   162,    17,    18,   167,    17,    18,   149,   169,    17,
      18,   146,   159,    19,   174,    17,    18,   160,   168,   172,
     178,    17,    18,   176,   181,    17,    18,   177,   182,    17,
      18,    19,   180,   183,    19,    13,   128,   129,    19,   145,
     148,   122,     0,   161,    19,     0,   166,    71,    22,    23,
      19,     0,   170,     0,    19,     0,   173,     0,    19,     0,
      24,    71,    22,    23,    25,    26,    27,     0,     0,    28,
       0,    72,     0,    11,    24,    29,    73,     0,    25,    26,
      27,     0,     0,    28,    30,    72,     0,    11,     0,    29,
     121,    31,     0,     0,     0,     0,     0,    32,    30,     1,
      22,    23,     0,     0,     0,    31,     0,     0,     0,     0,
       0,    32,    24,   175,     0,     0,    25,    26,    27,     0,
       0,    28,     0,     0,     0,    11,   114,    29,     0,     0,
      78,    79,     0,     0,     0,     0,    30,     0,     0,     0,
       0,    80,     0,    31,     0,     0,     0,     0,     0,    32,
      81,    82,    97,    83,     0,    84,    85,    86,    87,    88,
       1,    22,    23,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    80,     0,    25,    26,    27,
       0,     0,   171,     0,    81,    82,    11,    83,    29,    84,
      85,    86,    87,    88,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    80,     0,     0,     0,     0,
       0,     0,   179,     0,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,    78,    79,     0,     0,     0,     0,
       0,   108,     0,     0,     0,    80,     0,    78,    79,     0,
       0,     0,   143,     0,    81,    82,     0,    83,    80,    84,
      85,    86,    87,    88,     0,     0,     0,    81,    82,     0,
      83,     0,    84,    85,    86,    87,    88,    78,    79,     0,
       0,     0,   147,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
      83,     0,    84,    85,    86,    87,    88,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,   154,
      78,    79,     0,     0,     0,     0,     0,    81,    82,     0,
      83,    80,    84,    85,    86,    87,    88,     0,     0,     0,
      81,    82,     0,    83,     0,    84,    85,    86,    87,    88,
       1,     0,     0,     2,     0,     3,     0,     4,     0,     0,
       0,     5,     0,     6,     7,     8,     9,     0,     0,     0,
       0,     0,     0,    10,     0,     0,    11
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    18,     7,    15,    39,    40,    10,
      10,    10,     3,    13,    13,     3,     4,     5,    60,    70,
      20,    20,    64,     3,    38,    30,    35,     6,    16,     0,
      35,     2,    20,    21,    22,    29,     3,    25,    29,    10,
       3,    29,    13,    31,    38,     3,     4,     4,     4,    20,
      30,    45,    40,    11,   105,     3,    35,    99,     7,    47,
       0,    61,    61,    12,    13,    53,     4,    47,    16,    37,
      27,    29,    29,    29,    31,    31,    77,    77,    77,    13,
      35,    38,     7,    13,    42,    35,    20,    37,    45,    27,
      20,    37,    47,    31,    41,    42,    97,    97,    97,   101,
      38,     6,   116,     7,     3,    63,    77,    45,    12,    13,
      33,    33,    35,    35,    72,    33,     3,    75,    23,    24,
      33,    35,    35,    35,     9,     3,    97,    37,    37,    34,
       3,    89,    29,   134,   134,   134,     3,    33,    43,    44,
      98,    46,     3,    48,    49,    50,    51,    52,   106,   107,
       3,   152,   152,   152,   155,   155,   155,     7,   159,   159,
     159,   119,    30,   134,   165,   165,   165,    33,     7,     7,
     171,   171,   171,     7,   175,   175,   175,     7,   179,   179,
     179,   152,     7,     7,   155,     0,    92,    95,   159,   116,
     122,    75,    -1,   151,   165,    -1,   154,     3,     4,     5,
     171,    -1,   160,    -1,   175,    -1,   164,    -1,   179,    -1,
      16,     3,     4,     5,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    -1,    29,    16,    31,    32,    -1,    20,    21,
      22,    -1,    -1,    25,    40,    27,    -1,    29,    -1,    31,
      32,    47,    -1,    -1,    -1,    -1,    -1,    53,    40,     3,
       4,     5,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    16,     6,    -1,    -1,    20,    21,    22,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    34,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      43,    44,    11,    46,    -1,    48,    49,    50,    51,    52,
       3,     4,     5,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    34,    -1,    20,    21,    22,
      -1,    -1,    11,    -1,    43,    44,    29,    46,    31,    48,
      49,    50,    51,    52,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    43,    44,    -1,    46,    -1,    48,
      49,    50,    51,    52,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,    48,
      49,    50,    51,    52,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    -1,    23,    24,    -1,
      -1,    -1,    28,    -1,    43,    44,    -1,    46,    34,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    43,    44,    -1,
      46,    -1,    48,    49,    50,    51,    52,    23,    24,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      46,    -1,    48,    49,    50,    51,    52,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      23,    24,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      46,    34,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      43,    44,    -1,    46,    -1,    48,    49,    50,    51,    52,
       3,    -1,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     6,     8,    10,    14,    16,    17,    18,    19,
      26,    29,    55,    56,    58,    60,    62,    63,    70,    71,
      56,    57,     4,     5,    16,    20,    21,    22,    25,    31,
      40,    47,    53,    63,    66,    67,    68,    69,    70,    71,
      73,    76,    83,    66,     3,    64,     3,    61,     3,    16,
      64,    65,    66,    57,    66,     0,    58,    60,    37,    37,
      33,    35,     4,    27,    29,    38,    45,    72,    76,     7,
       3,     3,    27,    32,    66,    77,    78,     6,    23,    24,
      34,    43,    44,    46,    48,    49,    50,    51,    52,    82,
      39,    40,    80,    41,    42,    81,    66,    11,    33,    15,
      35,    29,    38,    45,    74,     3,    35,     9,    30,    37,
      37,    65,    63,    66,    30,    65,     3,     3,    74,    33,
      66,    32,    78,    35,    37,    79,    57,    66,    68,    69,
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
      64,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     2,     2,     3,     2,
       3,     1,     3,     1,     3,     5,     4,     5,     7,     6,
       8,     9,     7,     3,     4,     2,     4,     5,     1,     2,
       1,     1,     3,     3,     1,     3,     1,     4,     3,     1,
       3,     1,     3,     1,     3,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     4,     2,     3,     1,     1,     3,     4,
       5,     1,     2,     2,     1,     2,     3,     1,     2,     2,
       3,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  "addSubExp", "mulDivExp", "baseExp", "prefixexp", "functioncall", "args",
  "function", "funcbody", "parlist", "tableconstructor", "fieldlist",
  "field", "fieldsep", "addSubBinop", "mulDivBinop", "binop", "unop", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   106,   106,   110,   113,   116,   119,   122,   125,   128,
     131,   137,   143,   147,   148,   151,   155,   159,   163,   168,
     173,   179,   185,   190,   194,   198,   204,   212,   223,   226,
     229,   233,   234,   237,   243,   246,   252,   253,   257,   264,
     267,   273,   276,   282,   283,   288,   295,   296,   304,   305,
     313,   314,   315,   316,   317,   320,   321,   322,   323,   327,
     328,   329,   333,   337,   347,   349,   352,   355,   361,   371,
     374,   381,   384,   387,   391,   397,   399,   405,   408,   412,
     415,   422,   426,   433,   439,   440,   444,   445,   449,   450,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   468,   469,   470
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
#line 1972 "binary.tab.cc" // lalr1.cc:1167
