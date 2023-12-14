#include "monty.h"

/**
 * swap_stack - swaps the top two elements of the stack
 * @stack_top: pointer to the top of the stack
 * @line_number: current line
 *
 * Return: void
 */

void swap_stack(stack_t **stack_top, unsigned int line_number)
{
    int temp;

    if (stack_top == NULL || *stack_top == NULL || (*stack_top)->prev == NULL)
    {
        dprintf(2, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack_top)->n;
    (*stack_top)->n = (*stack_top)->prev->n;
    (*stack_top)->prev->n = temp;
}
