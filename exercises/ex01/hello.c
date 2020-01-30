#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Hello, World! x = %i\n", y);
    return 0;
}

/*
Answers to questions:

1.  Lines 17-18:
subq	$16, %rsp
movl	$5, -4(%rbp)

2. Those lines disappear-- it looks like int x gets removed.

3. I'm not sure other than that the assembly code is definitely shorter when optimized,
and the print statement can't be optimized to 'put' anymore.

4. Without optimization, I see these lines:

    movl	$5, -8(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax

But with it, I only see this:

	movl	$6, %edx

These examples make me think that optimization removes variables
that aren't used often, and pre-performs operations when possible.
*/
