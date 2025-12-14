
# Contenet

* [[#useful_methods_in_C]]
* [[#memset]]
* [[#Buffer]]
* [[#Write/read functions]] 
* [[#Read only data (String)]]
* [[#Memory and pointers in C]]
* [[#Hexadecimal]]
* [[#Difference between adding headers and adding functions directly in C]]
* [[#Volatile data type]]
* [[#Pointers]]













# useful_methods_in_C

* `perror`:
	*  When a system call (like `open`, `read`, `socket`, etc.) fails, it usually sets a global variable `errno` with a code representing the error. 
	- `perror` looks at `errno` and prints a human-readable message.
	- If you pass a string `s`, it prints that first, then adds the error description.
# memset

* Used on raw array like static ones to put every byte in an array to specific given value.
* So when I say `memset(int *ptr,int value,size_t num)` --> memset(arr,2,sizeof(arr)):
     * I'm saying put every byte in int type value (assuming you have int array[size]) in the array (in memory) to the hexadecimal of 2 .
     * So it's something like [0xYY0xYY0xYY0xYY, 0xYY0xYY0xYY0xYY, etc..]  ---> so I'm saying for each byte put the hexadecimal representation of the value then, but when you print the array values it will turn them into decimal values so that's could lead to unwanted values.
* In short: you can't use it to initialize a static array to something else other that 0.



---


# Buffer
* Is a region of memory (a block of bytes) used to temporarily store data.
```c
char buffer[1024]; //1 kb buffer
```
* This allocates 1024 bytes of memory.

* You can use it to:
    - Store a string from user input
    - Read a file into it
    -  Temporarily hold data before sending over a network
    - Interpret it as integers, floats, structs, etc.
* Most of the time it will be char because char is 1 byte .



---


# Write/read functions

* write/read they are low level functions from `<unistd.h>` library.
* they are low level system call.
* Write, it's no formatting raw bytes only --> just sends bytes to a file descriptor.
* format `write(file descriptor, const void *buf, size_t n) `
* file descriptor :
     * we can use `0 for stdin (read),1 for stdout (write), 2 for stderr (write)` 
     * By default it will redirect to the terminal or console for stdout which is a normal output. To make it redirect to other place, use `dup2(place: {socket,file} , number)`, Ex:
       ```c
 int sockfd = socket(AF_INET, SOCK_STREAM, 0);
// ... set up socket, connect, etc.

// Redirect stdout to socket
dup2(sockfd, 1);

write(1, "Hello socket\n", 13);
```
     * files, sockets, etc..

### `printf()` vs `write()` in C

#### 🔍 Comparison Table

| Feature         | `printf()`                           | `write()`                                   |
| --------------- | ------------------------------------ | ------------------------------------------- |
| **Level**       | High-level C standard library        | Low-level system call                       |
| **Header**      | `#include <stdio.h>`                 | `#include <unistd.h>`                       |
| **Formatting**  | Yes (`%d`, `%s`, etc.)               | No formatting — raw bytes only              |
| **Output type** | Converts and prints formatted output | Just sends bytes to a file descriptor       |
| **Buffering**   | Usually **buffered** (faster)        | Usually **unbuffered** (immediate)          |
| **Flexibility** | Great for printing readable output   | Great for low-level I/O like files, sockets |


### 🔧 `write()` — What does it actually do?

```c
ssize_t write(int fd, const void *buf, size_t count);
```

It writes **`count` bytes** from **`buf`** to the file or device identified by **file descriptor `fd`**.

#### Example: Print a character

```c
char c = 'A';
write(1, &c, 1); // 1 = stdout (terminal)
```

#### Example: Write to a file

```c
#include <fcntl.h>
#include <unistd.h>

int fd = open("out.txt", O_WRONLY | O_CREAT, 0644);
write(fd, "Hello\n", 6);
close(fd);
```



### 🔧 `printf()` — What does it do?

```c
printf("Hello %s, your score is %d\n", name, score);
```

It converts values into a formatted string (with `%s`, `%d`, etc.) and sends it to **stdout** — usually via a `write()` call internally after buffering.

---

### 🧠 When to Use Which?

| Use Case                              | Recommended Function |
| ------------------------------------- | -------------------- |
| Human-readable output                 | `printf()`           |
| Writing binary or raw data            | `write()`            |
| Writing to sockets/files/devices      | `write()`            |
| Formatted console logging             | `printf()`           |
| Writing in a low-level system context | `write()`            |

---

## 💡 Summary

- Use `**write**` when you're working with **low-level** output (files, sockets, raw bytes).
- Use `**printf**` when you need **formatted output** for the user or debugging.



---

# Read only data (String)
```C
int main(){
   char *arr="ahmad";
   arr[0]='A'; //X this not allowed because this is raw data which is saved in read only memory so it's immutable & string literals
}
```



---

# Memory and pointers in C

* Pointer variable --> save the **Memory allocation** *Not* **Address of the value inside it**
* So: when I say:
```C
int main(){
var="hello";
  const char const *arr= &var; // This means the pointer is const (I can't increase or decrease it) and the value that it's points to is also const (You can't change it like arr[0]="A")
}
```


 ## 🧠 First, understand the C memory model (for most systems):

![[screenshot-20250626-202501.png]]


 ## ✅ Where things go:

| Type                            | Memory Region          | Example                   |
| ------------------------------- | ---------------------- | ------------------------- |
| Local variables (`int x`)       | Stack                  | `void f() { int x = 5; }` |
| Pointers (local, like `int *p`) | Stack (pointer itself) | `int a = 5; int *p = &a;` |
| String literal (`"hello"`)      | Read-only data         | `char *s = "hello";`      |
| Dynamically allocated           | Heap                   | `int *p = malloc(4);`     |
| Global/static variables         | Data segment           | `static int count = 0;`   |


### 🔍 So to answer directly:

> **Are pointer variables and normal ones saved in the stack until I say `new`?**

Yes — **unless you allocate dynamically**, _both normal variables and pointers are stored on the stack_.
#### Example:
```c
`void test() {     int x = 42;          // stored on stack     int *p = &x;         // 'p' is a pointer on stack, points to 'x' also on stack }`

Everything here is on the **stack**. No `malloc` or `new` involved → nothing on the **heap**.
```
#### Example with dynamic allocation:


```c



`void test() {     int *p = malloc(sizeof(int));  // 'p' is on stack, but points to heap memory     *p = 42; }`
```
Now:

- `p` is on the stack
- `*p` is on the **heap** (new memory)
- Memory stays alive **even after `test()` ends**, unless you `free()` it.
    
## 🧠 Analogy:

Think of it like this:

|Concept|Real-World Analogy|
|---|---|
|Stack|Local desk space|
|Heap|Renting storage in a warehouse|
|Pointer var|Sticky note with an address|
|`"hello"`|A label on a read-only box|



---

# Hexadecimal 
* - `1 hex digit` → 4 bits
- `2 hex digits` → 8 bits → **1 byte**
- `4 hex digits` → 2 bytes
- `8 hex digits` → 4 bytes (e.g., 32-bit int)
- `16 hex digits` → 8 bytes (e.g., 64-bit pointer)




---


# Difference between adding headers and adding functions directly in C

```C
void example(void );

int main(){

 
}
```

* This way of adding functions from another file to this one is bad and not modular, because if you changed the name or attribute of this function you will need to change it across all files that you have added them in and this is not modular nor flexible .
```example.h
#ifndef  HELL_H
#define HELL_H

void hell(void)

#endif
```

* This one will be modular and flexible and meaningful .

## ✅ Advantages of Using Headers

  - **DRY principle**: Define prototypes once, include everywhere.
   - **Consistency**: Compiler errors catch mismatches between `.c` and `.h`
   - **Scalability**: Ideal for large projects (like 42 ones with `src/` and `includes/`)
   - **Readability**: Easier to see a module’s interface (via `.h` files)



* Headers are just **included** into `.c` files to tell the compiler what exists.
* *You Should compile the original .c files for those .h files*
* *IF you want to include .h files into your code and they are not in you project scope then you need to add the full path of them.*
```C
#include "../../shared/utils.h"
```


* Global headers like `<stdio.h>` and such, are exists in this path `/usr/include` which is public among different systems and C search in it by default. *Note: Don't add you headers to this if you want your headers to become global in the system.*
* You can use `export CPATH=/home/ahmad/my_headers` to export your headers to make C looking for them when needed and make them global (Put them in the search path for C) .
## How to make the header files 

* Simply make .h file and add the following :
```point.h
#ifndef PONIT_H   //include guard
#define POINT_H 

//your code 

#endif
```

* Why all capital ? 
     * because it's a name common practice, Helps avoid name collisions with variables or functions. 





---



# Volatile data type

### Why it's used ? 

**Preventing Compiler Optimizations:**

The primary purpose of `volatile` is to prevent the compiler from performing optimizations on a variable that might lead to incorrect behavior. Without `volatile`, a compiler might:

- **Cache values in registers:** If the compiler believes a variable's value won't change, it might store it in a CPU register for faster access, not always reading from main memory.
- **Reorder or eliminate reads/writes:** The compiler might reorder instructions or eliminate redundant reads/writes if it assumes the variable's value remains constant within a certain scope.



# Pointers

* Pointers just save the raw address, it's not in hexadecimal way, it's in byte way (bits).
* Hexadecimal is just a way or representing the data in human readable way.
### what happened when you write ptr + 1 ?
* It depends on the type of the pointer:
	* If the pointer was integer, when you say ptr + 1 it will move 4 bytes.
	* If it was char it will move 1 bytes.
	* etc ...


### What is the difference between const `const int * ptr` and `int *const ptr`

1) `const int * ptr`: Means that there is a pointer which points to a constant int, so you can't change the value of that integer throw the pointer.
	* You can't say `*ptr = 10` //ERROR

2)  `int * const ptr`: This means a const pointer that can't be re-assign to another memory address (it will always assigned to the same memory location). 