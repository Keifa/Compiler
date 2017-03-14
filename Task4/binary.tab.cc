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
      case 67: // orExp
      case 68: // andExp
      case 69: // compareExp
      case 70: // dotDotExp
      case 71: // addSubExp
      case 72: // divMulModExp
      case 73: // notHashUnExp
      case 74: // powExp
      case 75: // baseExp
      case 76: // prefixexp
      case 77: // functioncall
      case 78: // args
      case 79: // function
      case 80: // funcbody
      case 81: // parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // field
      case 85: // fieldsep
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
      case 67: // orExp
      case 68: // andExp
      case 69: // compareExp
      case 70: // dotDotExp
      case 71: // addSubExp
      case 72: // divMulModExp
      case 73: // notHashUnExp
      case 74: // powExp
      case 75: // baseExp
      case 76: // prefixexp
      case 77: // functioncall
      case 78: // args
      case 79: // function
      case 80: // funcbody
      case 81: // parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // field
      case 85: // fieldsep
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
      case 67: // orExp
      case 68: // andExp
      case 69: // compareExp
      case 70: // dotDotExp
      case 71: // addSubExp
      case 72: // divMulModExp
      case 73: // notHashUnExp
      case 74: // powExp
      case 75: // baseExp
      case 76: // prefixexp
      case 77: // functioncall
      case 78: // args
      case 79: // function
      case 80: // funcbody
      case 81: // parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // field
      case 85: // fieldsep
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
#line 108 "binary.yy" // lalr1.cc:859
    { root = yystack_[0].value.as< Node > (); }
#line 713 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 112 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 721 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 115 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 729 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 118 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("chunk", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< std::string > ()); }
#line 737 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 121 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 745 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 124 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 753 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 127 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 761 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 133 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("block", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 769 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 139 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", "assignment");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 778 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 143 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 784 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 144 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 792 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 147 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 801 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 151 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 810 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 155 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 819 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 159 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp = Node("else");
      temp.children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 831 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 166 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[5].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 841 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 171 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[7].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 852 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 177 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[8].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[7].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 863 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 183 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 873 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 188 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 882 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 192 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 891 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 196 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 899 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 202 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 910 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 208 "binary.yy" // lalr1.cc:859
    {
      Node temp("elseif");
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yystack_[4].value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); }
#line 921 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 217 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("RETURN")); }
#line 929 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 220 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 937 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 223 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ()); }
#line 943 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 227 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", yystack_[0].value.as< std::string > ()); }
#line 949 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 228 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 957 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 231 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 965 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 237 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("varlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 973 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 240 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 981 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 246 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ()); }
#line 987 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 247 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 996 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 251 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1005 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 258 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("namelist", "");
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1013 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 261 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1021 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 267 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("explist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1029 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 270 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1037 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 276 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1043 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 280 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1049 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 281 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1059 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 289 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1065 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 290 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1075 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 298 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1081 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 299 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1091 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 304 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1101 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 309 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1111 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 314 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1121 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 319 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1131 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 324 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1141 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 332 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1147 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 333 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1157 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 341 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1163 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 342 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1173 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 347 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1183 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 355 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1189 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 356 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1199 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 361 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1209 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 366 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1219 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 374 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1225 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 375 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1235 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 380 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1245 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 385 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1254 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 392 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1260 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 393 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1270 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 401 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1276 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 402 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1282 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 403 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1288 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 404 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1294 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 405 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > ().insert(0, "\\");
      yystack_[0].value.as< std::string > ().insert(yystack_[0].value.as< std::string > ().length() - 1, "\\");
      yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1303 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 409 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1309 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 410 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1315 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 411 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1321 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 412 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1327 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 416 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1333 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 417 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1339 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 418 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1345 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 422 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1354 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 426 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp("name", yystack_[1].value.as< std::string > ());
      temp.children.push_back(Node(yystack_[3].value.as< Node > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1366 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 436 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", ""); }
#line 1373 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 438 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1381 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 441 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1389 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 444 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > ().insert(0, "\\");
      yystack_[0].value.as< std::string > ().insert(yystack_[0].value.as< std::string > ().length() - 1, "\\");
      yylhs.value.as< Node > () = Node("args", yystack_[0].value.as< std::string > ()); }
#line 1398 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 451 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("function", "");
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[2].value.as< std::string > ()));
      Node temp("name");
      temp.children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1410 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 461 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1418 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 464 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1427 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 471 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1435 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 474 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1443 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 477 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1451 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 480 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1460 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 487 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", ""); }
#line 1467 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 489 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1475 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 495 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1483 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 498 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      //$$.children.push_back($2);
    }
#line 1493 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 503 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1501 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 506 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      //$1.children.push_back($3);
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1510 "binary.tab.cc" // lalr1.cc:859
    break;

  case 99:
#line 513 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1519 "binary.tab.cc" // lalr1.cc:859
    break;

  case 100:
#line 517 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node(yystack_[2].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1531 "binary.tab.cc" // lalr1.cc:859
    break;

  case 101:
#line 524 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1539 "binary.tab.cc" // lalr1.cc:859
    break;

  case 102:
#line 530 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1545 "binary.tab.cc" // lalr1.cc:859
    break;

  case 103:
#line 531 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1551 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1555 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -79;

  const short int
  parser::yypact_[] =
  {
     273,   -57,   273,   221,   221,    27,    46,    22,   221,   -57,
     273,   221,   -57,    58,   295,   -57,   -57,    72,    79,   217,
      14,   295,    81,   -57,   -57,    76,   -57,   -57,   -57,   114,
     253,   -57,   -57,    90,    87,    92,    35,    83,   -16,    26,
      -6,    94,   -57,   217,   -57,   -57,   -57,   127,   111,    -8,
     -57,    17,   -57,   139,   116,   117,   -57,   144,   132,   -57,
     -57,   -57,   -57,   221,     3,   -57,   221,    73,   160,   161,
     -57,   -57,   -57,   142,   143,   221,   -57,   -57,   207,    88,
      94,   273,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   253,   253,   253,   273,
     221,   221,   172,    10,   178,   179,   -57,   142,   221,   221,
     -57,   117,    91,   155,   -57,    18,    32,   -57,   -57,   221,
     159,   -57,    88,   -57,   -57,   -57,   184,    92,    35,    83,
      83,    83,    83,    83,    83,   -16,    26,    26,    -6,    -6,
      -6,    94,    94,   -57,   109,   162,     2,   -57,   273,   -57,
       9,   170,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   168,   -57,   -57,   -57,   221,   273,   120,   221,   273,
     196,   172,   -57,   273,   221,   193,   199,   -57,   221,   273,
     201,   206,   -57,   208,   -57,   273,   -57,   205,   210,   273,
     -57,   -57,   -57,   273,   -57,   212,   -57,   -57
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    34,     0,     0,     0,     0,     0,     0,    26,    28,
       0,     0,     5,     0,     2,     3,     4,     0,    77,     0,
      11,     9,     0,    72,    71,     0,    68,    69,    70,     0,
       0,    73,    77,     0,    41,    42,    44,    46,    53,    55,
      58,    62,    66,    75,    78,    74,    76,     0,    37,     0,
      29,     0,    37,     0,    23,    27,    39,     0,     0,     1,
       8,     6,     7,     0,     0,    85,     0,     0,     0,     0,
      80,    84,    12,     0,    34,     0,    93,   101,     0,    95,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      79,    10,    77,     0,    82,     0,     0,    36,    86,     0,
       0,    94,    97,   102,   103,    96,     0,    43,    45,    52,
      47,    49,    48,    50,    51,    54,    56,    57,    60,    59,
      61,    63,    64,    67,     0,     0,     0,    38,     0,    90,
      89,     0,    31,    30,    22,    40,    14,    35,    83,    81,
     100,     0,    98,    13,    15,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    87,     0,    99,     0,    16,     0,     0,     0,
      20,    88,    24,     0,    18,     0,    25,    19
  };

  const short int
  parser::yypgoto_[] =
  {
     -57,   -57,   220,    -1,    12,   -57,    52,   -57,   -57,     0,
       5,   -47,    31,   -57,   148,   149,    71,   141,   -17,    -3,
     -25,   135,     1,    29,   119,   -57,   -56,   -57,   -15,   -57,
     167,   118
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    13,    21,    22,    15,   167,    16,    51,    17,    32,
      49,    55,    56,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    70,    45,   106,   151,    46,    78,
      79,   125
  };

  const short int
  parser::yytable_[] =
  {
      18,    19,    18,    19,    71,    80,     1,   101,   169,    57,
      18,    19,    54,    52,    18,    19,   111,   118,   -78,    96,
     115,    18,    19,    91,    92,    52,    61,   102,    71,    20,
      48,    20,    11,    61,    33,    47,    65,   108,    53,    20,
     148,   -78,    58,    20,   171,   -78,   103,    97,   158,    50,
      20,   154,   -78,   108,   146,   104,   172,   149,    59,   -78,
      77,    67,   105,    29,   112,    19,    62,    93,    94,    84,
      95,   141,   142,    62,   136,   137,     1,    23,    24,    73,
     126,    18,    19,    85,    86,    87,    88,    89,    72,    25,
     138,   139,   140,    26,    27,    28,    81,   113,   144,    18,
      19,    71,    11,   114,    29,    63,   120,    64,   150,    77,
      20,    82,   -32,    30,   -32,    83,   164,    74,    23,    24,
      31,   165,   166,   123,   -33,   124,   -33,   177,    20,    90,
      25,   145,   178,   179,    26,    27,    28,    98,    99,   155,
     156,    75,   107,    11,   100,    29,    76,   170,    18,    19,
     160,   102,   108,   109,    30,   129,   130,   131,   132,   133,
     134,    31,   110,   116,   117,   176,    18,    19,   181,    18,
      19,   103,   183,    18,    19,   147,   119,    20,   188,    18,
      19,   152,   153,   157,   192,    18,    19,   161,   195,    18,
      19,   163,   196,    18,    19,    20,   175,   168,    20,   180,
     173,   174,    20,   182,   185,   184,   186,   189,    20,   187,
      74,    23,    24,   190,    20,   191,   193,   194,    20,   197,
      14,    65,    20,    25,     1,    23,    24,    26,    27,    28,
     127,   135,   128,   143,    75,   159,    11,    25,    29,   121,
     162,    26,    27,    28,    66,   122,    67,    30,    29,     0,
      11,     0,    29,     0,    31,    68,     1,    23,    24,     0,
       0,    30,    69,     0,     0,     0,     0,     0,    31,    25,
       0,     0,     0,    26,    27,    28,     1,     0,     0,     2,
       0,     3,    11,     4,    29,     0,     0,     5,     0,     6,
       7,     8,     9,     0,     0,     0,     0,     0,     1,    10,
      31,     2,    11,     3,     0,     4,     0,     0,     0,     5,
      12,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    10,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    60
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    19,    30,     3,    15,     6,    10,
      10,    10,     7,     3,    14,    14,    63,    73,     4,    25,
      67,    21,    21,    39,    40,     3,    14,    35,    43,     0,
       3,     2,    29,    21,     3,     4,     4,    35,    16,    10,
      30,    27,    11,    14,    35,    31,    29,    53,    30,     3,
      21,   107,    38,    35,   101,    38,    47,    47,     0,    45,
      29,    29,    45,    31,    64,    64,    14,    41,    42,    34,
      44,    96,    97,    21,    91,    92,     3,     4,     5,     3,
      81,    81,    81,    48,    49,    50,    51,    52,     7,    16,
      93,    94,    95,    20,    21,    22,     6,    66,    99,    99,
      99,   116,    29,    30,    31,    33,    75,    35,   103,    78,
      81,    24,    33,    40,    35,    23,     7,     3,     4,     5,
      47,    12,    13,    35,    33,    37,    35,     7,    99,    46,
      16,   100,    12,    13,    20,    21,    22,    43,    11,   108,
     109,    27,     3,    29,    33,    31,    32,   148,   148,   148,
     119,    35,    35,     9,    40,    84,    85,    86,    87,    88,
      89,    47,    30,     3,     3,   166,   166,   166,   169,   169,
     169,    29,   173,   173,   173,     3,    33,   148,   179,   179,
     179,     3,     3,    28,   185,   185,   185,    28,   189,   189,
     189,     7,   193,   193,   193,   166,   165,    35,   169,   168,
      30,    33,   173,     7,    11,   174,     7,     6,   179,   178,
       3,     4,     5,     7,   185,     7,    11,     7,   189,     7,
       0,     4,   193,    16,     3,     4,     5,    20,    21,    22,
      82,    90,    83,    98,    27,   116,    29,    16,    31,    32,
     122,    20,    21,    22,    27,    78,    29,    40,    31,    -1,
      29,    -1,    31,    -1,    47,    38,     3,     4,     5,    -1,
      -1,    40,    45,    -1,    -1,    -1,    -1,    -1,    47,    16,
      -1,    -1,    -1,    20,    21,    22,     3,    -1,    -1,     6,
      -1,     8,    29,    10,    31,    -1,    -1,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,     3,    26,
      47,     6,    29,     8,    -1,    10,    -1,    -1,    -1,    14,
      37,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     6,     8,    10,    14,    16,    17,    18,    19,
      26,    29,    37,    55,    56,    58,    60,    62,    63,    76,
      77,    56,    57,     4,     5,    16,    20,    21,    22,    31,
      40,    47,    63,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    79,    82,    66,     3,    64,
       3,    61,     3,    16,    64,    65,    66,    57,    66,     0,
      37,    58,    60,    33,    35,     4,    27,    29,    38,    45,
      78,    82,     7,     3,     3,    27,    32,    66,    83,    84,
      74,     6,    24,    23,    34,    48,    49,    50,    51,    52,
      46,    39,    40,    41,    42,    44,    25,    53,    43,    11,
      33,    15,    35,    29,    38,    45,    80,     3,    35,     9,
      30,    65,    63,    66,    30,    65,     3,     3,    80,    33,
      66,    32,    84,    35,    37,    85,    57,    68,    69,    70,
      70,    70,    70,    70,    70,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    57,    66,    65,     3,    30,    47,
      64,    81,     3,     3,    80,    66,    66,    28,    30,    78,
      66,    28,    85,     7,     7,    12,    13,    59,    35,     6,
      57,    35,    47,    30,    33,    66,    57,     7,    12,    13,
      66,    57,     7,    57,    66,    11,     7,    66,    57,     6,
       7,     7,    57,    11,     7,    57,    57,     7
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    85
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       3,     1,     3,     5,     4,     5,     7,     6,     8,     9,
       7,     3,     4,     2,     4,     5,     1,     2,     1,     1,
       3,     3,     1,     3,     1,     4,     3,     1,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     2,     3,     1,     1,     3,     4,     5,     1,
       1,     2,     2,     2,     3,     1,     2,     2,     3,     5,
       3,     1,     1,     1
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
  "orExp", "andExp", "compareExp", "dotDotExp", "addSubExp",
  "divMulModExp", "notHashUnExp", "powExp", "baseExp", "prefixexp",
  "functioncall", "args", "function", "funcbody", "parlist",
  "tableconstructor", "fieldlist", "field", "fieldsep", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   108,   108,   112,   115,   118,   121,   124,   127,   133,
     139,   143,   144,   147,   151,   155,   159,   166,   171,   177,
     183,   188,   192,   196,   202,   208,   217,   220,   223,   227,
     228,   231,   237,   240,   246,   247,   251,   258,   261,   267,
     270,   276,   280,   281,   289,   290,   298,   299,   304,   309,
     314,   319,   324,   332,   333,   341,   342,   347,   355,   356,
     361,   366,   374,   375,   380,   385,   392,   393,   401,   402,
     403,   404,   405,   409,   410,   411,   412,   416,   417,   418,
     422,   426,   436,   438,   441,   444,   451,   461,   464,   471,
     474,   477,   480,   487,   489,   495,   498,   503,   506,   513,
     517,   524,   530,   531
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
#line 1995 "binary.tab.cc" // lalr1.cc:1167
