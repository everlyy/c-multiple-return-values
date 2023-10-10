# c-multiple-return-values

Returning multiple values from a function in C. \
It's really stupid and I know you can just return a struct, this is simply done out of curiosity.

# How it works

When you call a function with multiple return values it will:
 1. Save the return address to a local variable (thanks optimizations for making that work, because you can't do local variables in a naked function)
 2. Execute the function body, if this contains a `RETURN(value);` macro, it will push the value you provided onto the stack
 3. Put the previously saved return adress back on top of the stack, and then return

The callee will then handle the extra values on the stack and put them into variables. 