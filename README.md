# Dynamic Email List in C

A simple C program that demonstrates dynamic memory allocation, resizing, and deallocation using `malloc`, `realloc`, and `free`.

## Overview

The program:

1. Dynamically allocates memory to store 10 student email addresses.
2. Accepts email input from the user.
3. Displays all entered emails.
4. Shrinks the email list to keep only the first 6 emails (using `realloc` safely).
5. Frees all allocated memory to avoid leaks.

## Features

- Proper use of `malloc`, `realloc`, and `free`
- Memory leak–free design
- Modular structure with helper functions:
  - `read_emails()` — reads and stores email addresses
  - `display_emails()` — prints stored emails
  - `shrink_email_addresses()` — safely resizes memory
  - `free_memory()` — releases allocated memory

## Compilation & Run

```bash
gcc dynamic_emails.c -o dynamic_emails
./dynamic_emails
