alpha [a-zA-Z]
digit [0-9]
uds [_]

PLUS        [\+]
MINUS       [\-]
TIMES       [\*]
BY          [/]
BIN_AND			[&]
BIN_OR			[|]
SMALLER			[<]
GREATER			[>]
NOT					[!]
MOD					[\%]
XOR					[\^]
COMP				[\~]
CONDITIONAL	[\?]
ASSIGN      [\=]
BINARYOP    {PLUS}|{MINUS}|{TIMES}|{BY}|{ASSIGN}
SEPARATOR   [\t,:;()\\.{}\'\[\]]
QUOTATION   [\"]
COMMENT     "{"[^}\n]*"}"
PPR					[#]
%%
{PPR} { printf(" FLEX PREPROCESSOR %s\n", yytext); }
({PPR}[ ]*("include"|"INCLUDE")[ ]*{SMALLER}[ ]*{alpha}+[ ]*"."[ ]*("h"|"H")[ ]*{GREATER}) {printf(" FLEX HEADER %s\n", yytext); }

"int" { printf(" FLEX KEY INT %s\n", yytext); }
"char" { printf(" FLEX KEY CHAR %s\n", yytext);}

"if" { printf(" FLEX KEY IF %s\n", yytext);}
"else" { printf(" FLEX KEY ELSE %s\n", yytext);}
"while" { printf(" FLEX KEY WHILE %s\n", yytext);}
"do" { printf(" FLEX KEY DO %s\n", yytext);}
"void" {printf(" FLEX KEY VOID %s\n", yytext);}


({NOT}) { printf(" FLEX NOT %s\n", yytext);}
({MOD}) { printf(" FLEX MOD %s\n", yytext);}
({XOR}) { printf(" FLEX XOR %s\n", yytext);}
({COMP}) { printf(" FLEX COMPLEMENT %s\n", yytext);}
({CONDITIONAL}) { printf(" FLEX CONDITIONAL %s\n", yytext);}

({PLUS}) { printf(" FLEX PLUS %s\n", yytext);}
({MINUS}) { printf(" FLEX MINUS %s\n", yytext);}
({TIMES}) { printf(" FLEX TIMES %s\n", yytext);}
({BY}) { printf(" FLEX BY %s\n", yytext);}
({BIN_AND}{BIN_AND}) { printf(" FLEX AND %s\n", yytext);}
({BIN_AND}) { printf(" FLEX BIN_AND %s\n", yytext);}
({BIN_OR}{BIN_OR}) { printf(" FLEX OR %s\n", yytext);}
({BIN_OR}) { printf(" FLEX BIN_OR %s\n", yytext);}
({SMALLER}) { printf(" FLEX SMALLER %s\n", yytext);}
({GREATER}) { printf(" FLEX GREATER %s\n", yytext);}
({SMALLER}{ASSIGN}) { printf(" FLEX SMALLER_EQUAL %s\n", yytext);}
({GREATER}{ASSIGN}) { printf(" FLEX GREATER_EQUAL %s\n", yytext);}
({PLUS}{PLUS}) { printf(" FLEX INCREMENT %s\n", yytext);}
({MINUS}{MINUS}) { printf(" FLEX DECREMENT %s\n", yytext);}

[ ] { printf(" FLEX SPACE %s\n", yytext);}
[\n] { printf(" FLEX NEWLINE \n", yytext);}

({ASSIGN}) { printf(" FLEX ASSIGN %s\n", yytext);}
({ASSIGN}{ASSIGN}) { printf(" FLEX COMPARE %s\n", yytext);}
({QUOTATION}) { printf(" FLEX QUOTATION %s\n", yytext);}
({SEPARATOR}) { printf(" FLEX SEPARATOR %s\n", yytext);}
{digit}+  { printf(" FLEX digit %s\n", yytext);}
({alpha}|{uds})({alpha}|{digit}|{uds})*  { printf(" FLEX ID %s\n",yytext);}
"//"[^\n]* {printf("single line comment ");}

"/*"[^"*/"]*"*/" {printf("multilines comment ");}
. {printf(" unknown %s ", yytext);}
%%
int main()
{
  yyin=fopen("d:\\compiler\\input.c","r");
	yylex();
	return 0;
}
