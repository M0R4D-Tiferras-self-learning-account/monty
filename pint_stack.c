#include "monty.h"

/**
 * pint_stack - prints the value at the top of the stack, followed by a new line
 * @stack_top: pointer to the top of the stack
 * @line_number: current line
 *
 * Return: void
 */

void pint_stack(stack_t **stack_top, unsigned int line_number)
{
    if (*stack_top == NULL)
    {
        dprintf(2, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack_top)->n);
}
