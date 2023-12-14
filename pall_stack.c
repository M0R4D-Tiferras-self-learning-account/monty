#include "monty.h"

/**
 * pall_stack - prints all the values on the stack,
 * starting from the top
 * @stack_top: pointer to the top
 * @line_number: current line number of the bytecode file
 *
 * Return: void
 */

void pall_stack(stack_t **stack_top, unsigned int __attribute__((unused)) line_number)
{
    stack_t *current_node = *stack_top;

    if (current_node == NULL)
        return;

    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->prev;
    }
}
