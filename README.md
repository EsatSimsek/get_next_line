*This project has been created as part of the 42 curriculum by essimsek.*

# get_next_line

## Description

**get_next_line** is a function that reads a line from a file descriptor, one line at a time. The function returns a single line (ending with `\n` or EOF) each time it is called, making it ideal for reading files line by line without loading the entire file into memory.

The main goal of this project is to understand and implement:
- Static variables and their persistence across function calls
- Dynamic memory allocation and proper memory management
- File I/O operations using low-level system calls (`read`)
- Buffer handling and efficient data processing

## Instructions

### Compilation

To use `get_next_line` in your project, include the following files:
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Compile with your project using:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o your_program
```

The `BUFFER_SIZE` macro can be modified at compile time using the `-D` flag. If not specified, the default value is `7`.

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm Explanation

### Static Variable Approach

The algorithm uses a **static variable** to store any leftover data between function calls. This approach was chosen because:

1. **Efficiency**: Data read beyond the newline character is not discarded but stored for the next call, reducing unnecessary `read()` system calls.

2. **Simplicity**: A single static pointer is easy to manage and debug compared to more complex data structures.

3. **Memory Optimization**: Only one buffer is maintained between calls, minimizing memory overhead.

### Algorithm Flow

1. **read_to_static()**: Reads from the file descriptor into a temporary buffer and appends the data to the static variable until a newline (`\n`) is found or EOF is reached.

2. **get_line()**: Extracts a single line (up to and including `\n`) from the static variable.

3. **new_static_res()**: Removes the extracted line from the static variable and stores the remaining content for the next call.

4. **get_next_line()**: Orchestrates the above functions, handles edge cases (invalid fd, zero or negative buffer size), and returns the extracted line.

### Why Static Variable Over Other Approaches?

| Approach | Pros | Cons |
|----------|------|------|
| **Static Variable** | Simple, efficient, minimal memory usage | Limited to single fd per function |
| **Linked List** | Can handle multiple fds easily | More complex, higher memory overhead |
| **Global Array** | Fast access | Fixed size, not scalable |

The static variable approach was selected as it perfectly balances simplicity and efficiency for the project requirements.

## Resources

### Documentation & References
- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html) - Linux manual for the read system call
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Understanding static variable behavior
- [42 Docs - get_next_line](https://harm-smits.github.io/42docs/projects/get_next_line) - Community documentation

### AI Usage

AI tools were utilized during the development of this project strictly for educational and debugging purposes. Specifically, AI was used to:

* Understand the behavior and intended purpose of standard library functions.
* Clarify concepts related to memory management and data structures.

**Note:** All actual code implementation and logic construction were done manually to ensure a complete understanding of the core concepts.

---

## Author

- **essimsek** - 42 Istanbul
