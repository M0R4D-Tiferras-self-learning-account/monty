#include "monty.h"

/**
 * pop_stack - removes the top element of the stack
 * @stack_top: pointer to the top of the stack
 * @line_number: current line number
 *
 * Return: void
 */

void pop_stack(stack_t **stack_top, unsigned int line_number)
{
    stack_t *temp = NULL;

    if (*stack_top == NULL)
    {
        dprintf(2, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack_top;
    *stack_top = (*stack_top)->prev;

    temp->prev = NULL;
    free(temp);

    if (*stack_top)
        (*stack_top)->next = NULL;
}
