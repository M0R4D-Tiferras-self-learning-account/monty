#include "monty.h"

/**
 * push_err - handles wrong push
 * @line_number: current line number
 *
 * Return: Nothing
 */

int push_err(int line_number)
{
    dprintf(2, "L%d: usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * push_stack - pushes a new member to the stack
 * @num_str: the number to be pushed to the stack as a string
 * @stack: pointer to a pointer tothe stack
 * @line_number: current line number of the bytecode file being read
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int push_stack(char *num_str, stack_t **stack, int line_number)
{
    int num;
    stack_t *new_node = NULL;

    if (!num_str)
        return (push_err(line_number));

    if (strspn(num_str, "-0123456789") != strlen(num_str))
        return (push_err(line_number));

    num = atoi(num_str);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        dprintf(2, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }

    new_node->prev = *stack;
    new_node->n = num;
    new_node->next = NULL;

    if (*stack != NULL)
        (*stack)->next = new_node;

    *stack = new_node;

    return (EXIT_SUCCESS);
}

