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
      case 67: // prefixexp
      case 68: // functioncall
      case 69: // args
      case 70: // function
      case 71: // funcbody
      case 72: // parlist
      case 73: // tableconstructor
      case 74: // fieldlist
      case 75: // field
      case 76: // fieldsep
      case 77: // binop
      case 78: // unop
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
      case 67: // prefixexp
      case 68: // functioncall
      case 69: // args
      case 70: // function
      case 71: // funcbody
      case 72: // parlist
      case 73: // tableconstructor
      case 74: // fieldlist
      case 75: // field
      case 76: // fieldsep
      case 77: // binop
      case 78: // unop
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
      case 67: // prefixexp
      case 68: // functioncall
      case 69: // args
      case 70: // function
      case 71: // funcbody
      case 72: // parlist
      case 73: // tableconstructor
      case 74: // fieldlist
      case 75: // field
      case 76: // fieldsep
      case 77: // binop
      case 78: // unop
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
#line 101 "binary.yy" // lalr1.cc:859
    { root.children.push_back(yystack_[0].value.as< Node > ()); }
#line 692 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 105 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 700 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 108 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 708 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 111 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("chunk", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 716 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 114 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("chunk", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 724 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 117 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 732 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 120 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 740 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 123 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 748 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 126 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 756 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 132 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("block", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 764 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 138 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 773 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 142 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 779 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 143 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 787 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 146 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 796 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 150 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 805 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 154 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[4].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 814 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 158 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< std::string > ()); }
#line 824 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 163 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[5].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 834 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 168 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[7].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 845 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 174 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[8].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[7].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 856 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 180 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[6].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 866 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 185 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 875 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 189 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 884 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 193 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("stat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 892 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 199 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(temp); }
#line 905 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 207 "binary.yy" // lalr1.cc:859
    {
      Node temp("elseif");
      temp.children.push_back(Node(yystack_[3].value.as< std::string > ()));
      temp.children.push_back(yystack_[2].value.as< Node > ());
      temp.children.push_back(Node(yystack_[1].value.as< std::string > ()));
      temp.children.push_back(yystack_[0].value.as< Node > ());
      yystack_[4].value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); }
#line 918 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 218 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(Node("RETURN")); }
#line 926 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 221 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("laststat", yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 934 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 224 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", yystack_[0].value.as< std::string > ()); }
#line 940 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 228 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", yystack_[0].value.as< std::string > ()); }
#line 946 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 229 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 954 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 232 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 962 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 238 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("varlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 970 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 241 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 978 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 247 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ()); }
#line 984 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 248 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 993 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 252 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("var", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1002 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 259 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("namelist", "");
      yylhs.value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ())); }
#line 1010 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 262 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(Node("name", yystack_[0].value.as< std::string > ()));
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1018 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 268 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("explist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1026 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 271 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1034 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 277 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1040 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 278 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1046 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 279 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1052 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 280 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1058 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 281 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1066 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 284 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", yystack_[0].value.as< std::string > ()); }
#line 1072 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 285 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1078 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 286 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1084 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 287 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1090 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 288 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
    }
#line 1101 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 294 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("exp", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1110 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 301 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1116 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 302 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1122 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 303 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1128 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 307 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1137 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 311 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("functioncall", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      Node temp("name", yystack_[1].value.as< std::string > ());
      temp.children.push_back(Node(yystack_[3].value.as< Node > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1149 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 321 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", ""); }
#line 1156 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 323 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1164 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 326 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("args", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1172 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 329 "binary.yy" // lalr1.cc:859
    {
      yystack_[0].value.as< std::string > () = yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 2);
      yylhs.value.as< Node > () = Node("args", yystack_[0].value.as< std::string > ()); }
#line 1180 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 335 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("function", "");
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[2].value.as< std::string > ()));
      Node temp("name");
      temp.children.push_back(yystack_[1].value.as< std::string > ());
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1192 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 345 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1200 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 348 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("funcbody", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1209 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 355 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1217 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 358 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1225 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 361 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1234 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 365 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("parlist", "");
      yylhs.value.as< Node > ().children.push_back(Node("...")); }
#line 1242 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 371 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", ""); }
#line 1249 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 373 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("tableconstructor", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 1257 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 379 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1265 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 382 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("fieldlist", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1274 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 386 "binary.yy" // lalr1.cc:859
    {
      yystack_[1].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1282 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 389 "binary.yy" // lalr1.cc:859
    {
      yystack_[2].value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
      yystack_[2].value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); }
#line 1291 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 396 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1300 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 400 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node(yystack_[2].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(temp);
      yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< std::string > ()));
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1312 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 407 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = Node("field", "");
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1320 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 413 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1326 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 414 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1332 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 418 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1338 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 419 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1344 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 420 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1350 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 421 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1356 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 422 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1362 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 423 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1368 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 424 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1374 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 425 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1380 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 426 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1386 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 427 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1392 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 428 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1398 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 429 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1404 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 430 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1410 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 431 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1416 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 432 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ()); }
#line 1422 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 436 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1428 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 437 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1434 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 438 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ()); }
#line 1440 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1444 "binary.tab.cc" // lalr1.cc:859
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

  const signed char parser::yytable_ninf_ = -56;

  const short int
  parser::yypact_[] =
  {
     106,   -64,   106,   238,   238,    14,    30,    37,   238,   -64,
     106,   238,    67,   106,    32,    39,   -17,    82,    34,    51,
     106,    70,   -64,   -64,    83,   -64,   -64,   -64,   -64,     3,
     -64,   -64,   -64,   -64,   256,    34,   -64,   -64,   -64,   238,
     320,    72,    11,   -64,    19,   -64,   115,    84,    94,   538,
     121,   418,   -64,    96,   100,   -64,   -64,   238,    33,   -64,
     238,   200,   136,   137,   -64,   -64,   -64,   112,   117,   238,
     -64,   538,   186,    31,   106,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     238,   538,   106,   238,   238,   151,    24,   157,   158,   -64,
     112,   238,   238,   -64,   -64,   -64,    94,   103,   448,   -64,
      76,    56,   -64,   -64,   238,   478,   -64,    31,   -64,   -64,
     -64,   155,   538,    87,   508,     6,   -64,   106,   -64,    48,
     140,   -64,   -64,   -64,   538,   538,   -64,   -64,   -64,   538,
     133,   -64,   -64,   -64,   238,   106,    95,   238,   106,   168,
     151,   -64,   106,   238,   354,   169,   -64,   238,   106,   286,
     171,   -64,   172,   538,   106,   -64,   388,   173,   106,   -64,
     -64,   -64,   106,   -64,   175,   -64,   -64
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    36,     0,     0,     0,     0,     0,     0,    28,    30,
       0,     0,     0,     2,     3,     5,     0,    54,     0,    13,
      11,     0,    47,    46,     0,    43,    44,    45,    97,     0,
      96,    48,    98,    54,     0,    50,    55,    49,    51,     0,
       0,    39,     0,    31,     0,    39,     0,    25,    29,    41,
       0,     0,     1,     7,     9,     4,     6,     0,     0,    62,
       0,     0,     0,     0,    57,    61,    14,     0,    36,     0,
      70,    78,     0,    72,     0,    94,    95,    92,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    93,
       0,    53,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    56,     8,    10,    12,    54,     0,    59,
       0,     0,    38,    63,     0,     0,    71,    74,    79,    80,
      73,     0,    52,     0,     0,     0,    40,     0,    69,    66,
       0,    33,    32,    24,    42,    16,    37,    60,    58,    77,
       0,    75,    15,    17,     0,     0,     0,     0,     0,     0,
      67,    68,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    64,     0,    76,     0,    18,     0,     0,     0,    22,
      65,    26,     0,    20,     0,    27,    21
  };

  const short int
  parser::yypgoto_[] =
  {
     -64,   -64,   183,    -1,    68,   -64,    77,   -64,   -64,     0,
       8,   -10,    41,     1,    29,    73,   -64,   -63,   -64,   -13,
     -64,   114,    75,   -64,   -64
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    20,    21,    14,   146,    15,    44,    16,    33,
      42,    48,    49,    35,    36,    64,    37,    99,   130,    38,
      72,    73,   120,    90,    39
  };

  const short int
  parser::yytable_[] =
  {
      17,    18,    17,    18,   113,    65,    68,    22,    23,    50,
      17,    18,   148,    17,    18,    47,    57,    41,    58,    24,
      17,    18,    65,    25,    26,    27,    94,    45,    28,    19,
      69,    19,    11,    43,    29,    70,     1,   133,    59,    19,
      45,   101,    19,    30,    34,    40,    95,   106,    96,    19,
      31,   110,    51,    46,   127,   -55,    32,    97,   107,    18,
      59,    60,    11,    61,    98,    29,   118,    52,   119,    55,
      71,   128,    62,   121,    17,    18,    56,    66,   -55,    63,
      91,    53,   -55,   150,   125,    61,    67,    29,    53,   -55,
      54,   123,    17,    18,   143,   151,   -55,    54,    65,   144,
     145,   108,   156,    19,   129,    93,   137,   157,   158,     1,
     115,   101,     2,    71,     3,   -34,     4,   -34,   100,    95,
       5,    19,     6,     7,     8,     9,   149,    17,    18,   101,
     102,   122,    10,   104,   124,    11,   -35,   105,   -35,   111,
     112,    96,   134,   135,   155,    17,    18,   160,    17,    18,
     114,   162,    17,    18,   126,   139,    19,   167,    17,    18,
     131,   132,   142,   171,    17,    18,   153,   174,    17,    18,
     152,   175,    17,    18,    19,   161,   165,    19,   169,   170,
     173,    19,   176,    13,   138,   154,   117,    19,   159,    68,
      22,    23,   141,    19,   163,     0,     0,    19,   166,     0,
       0,    19,    24,     1,    22,    23,    25,    26,    27,     0,
       0,    28,     0,    69,     0,    11,    24,    29,   116,     0,
      25,    26,    27,     0,     0,    28,    30,     0,     0,    11,
     109,    29,     0,    31,     0,     0,     0,     0,     0,    32,
      30,     1,    22,    23,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    32,    24,     0,     0,     0,    25,    26,
      27,     0,    74,    28,     0,     0,     0,    11,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    75,
      76,     0,     0,     0,     0,    31,     0,     0,     0,     0,
      77,    32,   168,     0,     0,    78,    79,    80,    81,    82,
      83,     0,    84,     0,    85,    86,    87,    88,    89,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    92,    84,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,   164,    84,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,   172,
      84,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    75,    76,     0,     0,     0,     0,     0,   103,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    75,    76,     0,     0,     0,   136,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    75,    76,     0,     0,     0,   140,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,   147,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,     0,    84,     0,    85,    86,    87,    88,
      89
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    67,    18,     3,     4,     5,    10,
      10,    10,     6,    13,    13,     7,    33,     3,    35,    16,
      20,    20,    35,    20,    21,    22,    15,     3,    25,     0,
      27,     2,    29,     3,    31,    32,     3,   100,     4,    10,
       3,    35,    13,    40,     3,     4,    35,    57,    29,    20,
      47,    61,    11,    16,    30,     4,    53,    38,    58,    58,
       4,    27,    29,    29,    45,    31,    35,     0,    37,    37,
      29,    47,    38,    74,    74,    74,    37,     7,    27,    45,
      39,    13,    31,    35,    94,    29,     3,    31,    20,    38,
      13,    92,    92,    92,     7,    47,    45,    20,   111,    12,
      13,    60,     7,    74,    96,    33,    30,    12,    13,     3,
      69,    35,     6,    72,     8,    33,    10,    35,     3,    35,
      14,    92,    16,    17,    18,    19,   127,   127,   127,    35,
       9,    90,    26,    37,    93,    29,    33,    37,    35,     3,
       3,    29,   101,   102,   145,   145,   145,   148,   148,   148,
      33,   152,   152,   152,     3,   114,   127,   158,   158,   158,
       3,     3,     7,   164,   164,   164,    33,   168,   168,   168,
      30,   172,   172,   172,   145,     7,     7,   148,     7,     7,
       7,   152,     7,     0,   111,   144,    72,   158,   147,     3,
       4,     5,   117,   164,   153,    -1,    -1,   168,   157,    -1,
      -1,   172,    16,     3,     4,     5,    20,    21,    22,    -1,
      -1,    25,    -1,    27,    -1,    29,    16,    31,    32,    -1,
      20,    21,    22,    -1,    -1,    25,    40,    -1,    -1,    29,
      30,    31,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      40,     3,     4,     5,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    53,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,     6,    25,    -1,    -1,    -1,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    23,
      24,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      34,    53,     6,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    46,    -1,    48,    49,    50,    51,    52,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    11,    46,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    11,    46,    -1,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    11,
      46,    -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    48,    49,    50,    51,
      52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     6,     8,    10,    14,    16,    17,    18,    19,
      26,    29,    55,    56,    58,    60,    62,    63,    67,    68,
      56,    57,     4,     5,    16,    20,    21,    22,    25,    31,
      40,    47,    53,    63,    66,    67,    68,    70,    73,    78,
      66,     3,    64,     3,    61,     3,    16,    64,    65,    66,
      57,    66,     0,    58,    60,    37,    37,    33,    35,     4,
      27,    29,    38,    45,    69,    73,     7,     3,     3,    27,
      32,    66,    74,    75,     6,    23,    24,    34,    39,    40,
      41,    42,    43,    44,    46,    48,    49,    50,    51,    52,
      77,    66,    11,    33,    15,    35,    29,    38,    45,    71,
       3,    35,     9,    30,    37,    37,    65,    63,    66,    30,
      65,     3,     3,    71,    33,    66,    32,    75,    35,    37,
      76,    57,    66,    57,    66,    65,     3,    30,    47,    64,
      72,     3,     3,    71,    66,    66,    28,    30,    69,    66,
      28,    76,     7,     7,    12,    13,    59,    35,     6,    57,
      35,    47,    30,    33,    66,    57,     7,    12,    13,    66,
      57,     7,    57,    66,    11,     7,    66,    57,     6,     7,
       7,    57,    11,     7,    57,    57,     7
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     2,     2,     3,     2,
       3,     1,     3,     1,     3,     5,     4,     5,     7,     6,
       8,     9,     7,     3,     4,     2,     4,     5,     1,     2,
       1,     1,     3,     3,     1,     3,     1,     4,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     3,     2,     4,     2,
       3,     1,     1,     3,     4,     5,     1,     2,     2,     1,
       2,     3,     1,     2,     2,     3,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "prefixexp", "functioncall", "args", "function", "funcbody", "parlist",
  "tableconstructor", "fieldlist", "field", "fieldsep", "binop", "unop", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   101,   101,   105,   108,   111,   114,   117,   120,   123,
     126,   132,   138,   142,   143,   146,   150,   154,   158,   163,
     168,   174,   180,   185,   189,   193,   199,   207,   218,   221,
     224,   228,   229,   232,   238,   241,   247,   248,   252,   259,
     262,   268,   271,   277,   278,   279,   280,   281,   284,   285,
     286,   287,   288,   294,   301,   302,   303,   307,   311,   321,
     323,   326,   329,   335,   345,   348,   355,   358,   361,   365,
     371,   373,   379,   382,   386,   389,   396,   400,   407,   413,
     414,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   436,   437,   438
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
#line 1923 "binary.tab.cc" // lalr1.cc:1167
