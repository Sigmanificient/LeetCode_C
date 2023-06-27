#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void hello_world(void);

Test(hello, should_print_correctly)
{
    cr_redirect_stdout();
    hello_world();
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello, World!\n");
}
