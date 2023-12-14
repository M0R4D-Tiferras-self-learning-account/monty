#include "monty.h"

/**
 * parse_line_stack - splits each line of monty into an array of words
 * @line: the line to be splitted
 *
 * Return: the array of words containing the splitted line
 */

char **parse_line_stack(char *line)
{
    char *word, *line_copy;
    char **words;
    int len = 0, i = 0;

    line_copy = strdup(line);

    word = strtok(line, " \n");
    while (word)
    {
        len++;
        word = strtok(NULL, " \n");
    }

    words = malloc(sizeof(char *) * (len + 1));
    if (words == NULL)
    {
        free(line_copy);
        dprintf(2, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    word = strtok(line_copy, " \n");
    while (word)
    {
        words[i] = strdup(word);
        word = strtok(NULL, " \n");
        i++;
    }
    words[i] = NULL;
    free(line_copy);
    return (words);
}

/**
 * check_opcode_stack - checks a specific opcode and executes its corresponding
 * function
 * @opcode: the opcode
 * @line_number: the line number currently being read
 * @stack_top: pointer to the stack
 *
 * Return: Nothing
 */

int check_opcode_stack(char *opcode, int line_number, stack_t **stack_top)
{
    int i = 0;

    instruction_t opcodes[] = {
        {"pall", pall_stack},
        {"pint", pint_stack},
        {"pop", pop_stack},
        {"swap", swap_stack},
        {"add", add_stack},
        {NULL, NULL},
    };

    if (strcmp(opcode, "nop") == 0)
        return (EXIT_SUCCESS);

    while (opcodes[i].opcode)
    {
        if (strcmp(opcodes[i].opcode, opcode) == 0)
        {
            (opcodes[i].f)(stack_top, line_number);
            return (EXIT_SUCCESS);
        }
        i++;
    }

    dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
    return (EXIT_FAILURE);
}

/**
 * main - Entry point to the monty
 * @argc: argument counter
 * @argv: arg vector
 *
 * Return: On Success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
    FILE *file;
    int line_number = 0, fail_check = 0;
    size_t len = 0;
    char *line = NULL, **words = NULL;
    stack_t *top = NULL;

    if (argc != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        words = parse_line_stack(line);
        if (words && words[0])
        {
            if (strcmp(words[0], "push") == 0)
                fail_check = push_stack(words[1], &top, line_number);
            else
                fail_check = check_opcode_stack(words[0], line_number, &top);
        }
        free_words(words), words = NULL;
        if (fail_check)
            break;
    }

    free(line), free_stack(&top), fclose(file);
    if (fail_check)
        exit(EXIT_FAILURE);
    exit(EXIT_SUCCESS);
}
