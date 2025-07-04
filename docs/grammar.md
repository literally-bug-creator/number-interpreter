# EBNF (ISO/IEC 14977) legend

- `=` - defines/is defined as
- `;` - rule terminator
- `|` - alternative (OR)
- `[]` - optional (zero or one)
- `{}` - repetition (zero or more)
- `()` - grouping
- `""` - terminal string literal

# Extended JSON (RFC 7159)

extended_decimal = decimal | special_value ;
special = [ sign ] ( infinity | not_a_number ) ;

decimal = signed_integer [ fractional_part ] [ exponent ];

exponent = exp signed_integer ;
fractional_part = dot digit { digit } ;
signed_integer = [ sign ] unsigned_integer ;
unsigned_integer = zero | ( non_zero_digit { digit } ;

digit = zero | non_zero_digit ;

non_zero_digit = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
zero = "0" ;

infinity = "inf" | "infinity" ;
not_a_number = "nan" ;

sign = "+" | "-" ;
exp = "e" ;
dot = "." ;
