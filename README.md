# 42sp_ft_printf
ft_printf written with ❤ for 42sp.

## Key Concepts

### **Variadic arguments**

- Allows a function to take a indefinite number of arguments.
- Provided by the `<stdarg.h>` header.
- The variable arguments are declared with an ellipsis `...` as the last argument.
---
### Defining a variadic function
```c
int	sum(int num_args, ...);
long func(char a, double b, int c, ...);
```
- By C standards a variadic function should take at least ***ONE*** named argument.
---
### **`<stdarg.h>` types**
- The `va_list` type consists is an array which contains a single structural element necessary to implement the `va_arg` macro.:
```c
typedef struct {
   unsigned int gp_offset;
   unsigned int fp_offset;
   void *overflow_arg_area;
   void *reg_save_area;
} va_list[1];
```
- The `va_start` macro initializes the structure with the following:

1) **gp_offset** - Holds the offset in bytes from the `reg_save_area` to the place where the next "non-floating-point" argument register is saved.

2) **fp_offset** - Holds the offset in butes from the `reg_save_area` to the place where the next floating point argument is saved.

3) **overflow_arg_area** - Used to fetch arguments passed on the stack. It is initializes with the address of the first argument passed on the stack, if there is one, and updated to point to the start of the next argument.

4) **reg_save_area** - Is a pointer to the start of the register save area. The technical definition of what is the `register save area` is not utterly important, but you should know that if relates to assembler-level stack saves, allocation and offsets for variables.
---
### **`<stdarg.h>` macros**

| Macro Name        | Short Description           | Standard  |
| ------------- |---------------| ------|
| `va_start(va_list arg ptr, prev_param)`      | Initializes a argument iteration | C89 |
| `va_arg(va_list arg ptr, arg_type)`      | Retrieves an argument from the list      |   C89 |
| `va_end(va_list arg_ptr)` | Frees a `va_list`      |    C89 |
| `va_copy(va_list dest, va_list src)` | Copy the contents from one `va_list` to another      |    C99 |

#### Parameters

- `type` - The data type of the argument to be retrieved.
- `arg_ptr` - The pointer to the list of arguments.
- `dest` - Pointer to the list of arguments that will be initialized from `src`.
- `src` - Pointer to the initialized list of arguments from where we want to copy to `dest`.
- `prev_param` - Parameter that preceds the first optional/variable argument.
---