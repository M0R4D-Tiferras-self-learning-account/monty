#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack
 * @stack_top: pointer to the top of stack
 * @line_number: line number
 *
 * Return: void
 */

void add_stack(stack_t **stack_top, unsigned int line_number)
{
    stack_t *temp;

    if (stack_top == NULL || *stack_top == NULL || (*stack_top)->prev == NULL)
    {
        dprintf(2, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack_top)->prev->n += (*stack_top)->n;
    temp = *stack_top;
    (*stack_top) = (*stack_top)->prev;
    (*stack_top)->next = NULL;
    free(temp);
}
