### Circular Buffer for Embedded Systems

I am building this project to understand how data flows between hardware and software as part of my journey to become an embedded softwere developer.
This project is my implementation of a Circular Buffer (also known as a Ring Buffer) written in pure C.

The goal is to master memory management without using malloc (dynamic allocation) and to learn how to handle asynchronous data streams like UART, SPI, and ADC.

### 📂 Project Structure
```text

├── include/
│   └── circular_buffer.h    # API definitions & control structures
├── src/
│   └── circular_buffer.c    # Implementation of buffer logic
├── main.c                   # test my buffer
│
├── .gitignore               # Keeps the repo clean from build files
├── LICENSE                  # MIT License
└── README.md                # My learning log and documentation
