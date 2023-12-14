#include "monty.h"

/**
 * free_stack - free stack
 * @stack_top: pointer to the top of the stack to be freed
 *
 * Return: void
 */

void free_stack(stack_t **stack_top)
{
    stack_t *temp = NULL;

    while (*stack_top != NULL)
    {
        temp = *stack_top;
        *stack_top = (*stack_top)->prev;
        free(temp);
    }
}

/**
 * free_words - frees parse_line output
 * @tokenized_line: to freeing
 *
 * Return: void
 */

void free_words(char **tokenized_line)
{
    int i;

    if (tokenized_line != NULL)
    {
        for (i = 0; tokenized_line[i]; i++)
            free(tokenized_line[i]);
        free(tokenized_line);
    }
}

