# EBNF (ISO/IEC 14977) legend

- `=` - defines/is defined as
- `;` - rule terminator
- `|` - alternative (OR)
- `[]` - optional (zero or one)
- `{}` - repetition (zero or more)
- `()` - grouping
- `""` - terminal string literal

# Extended JSON (RFC 7159)

special_value = [ sign ] ( infinity | not_a_number ) ;
floating_point = signed_number | special_value ;
signed_number = [ sign ] unsigned_number ;

unsigned_number = integer_part [ fractional_part ] [ exponent_part ]
| fractional_part [ exponent_part ] ;

exponent_part = exp [ sign ] integer_part ;
fractional_part = dot digit { digit } ;
integer_part = zero | non_zero_digit { digit } ;

digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
non_zero_digit = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
zero = "0" ;

infinity = "inf" | "infinity" ;
not_a_number = "nan" ;

sign = "+" | "-" ;
exp = "e" ;
dot = "." ;
