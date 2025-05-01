# Multithreaded Web Crawler in C

Project Description:


## Roles:

Scarlett – Thread Management & Input Handling

- Reads input URLs from 'urls.txt'
- Validates URLs (must start with 'http://' or 'https://')
- Creates one thread per valid URL using 'pthread'
- Passes each thread the assigned URL and index
- Logs which thread handles which URL

Wenhao - Error Handling, Logging & Build System

- Adds error handling for file access, memory allocation, and thread creation
- Checks if urls.txt exists and prints an error if it cannot be opened
- Verifies that at least one valid URL is loaded before starting threads
- Uses perror() and fprintf(stderr, ...) to report runtime issues
- Logs when the crawler starts and finishes, and when each thread begins and ends
- Adds [INFO], [WARNING], and [ERROR] tags to log messages for clarity

Lucia - HTML Fetching & Storage
- Integrate **libcurl** to perform concurrent HTTP GET requests.  
- Write each page’s HTML into a uniquely named file: `page<index>.html`.  
- Implement a `write_data` callback to stream downloads directly to disk.  
- Log success (`[INFO]`) or failure (`[ERROR]`) for each download.

Dillon - Word Counting & Output
+ Use file opening to get the html of page1, page2, and page3
+ Use fgetc to build current string
+ Compare current string with word list of linux, science, code, libcurl, and kernel
+ Add 1 to count for respective word and display final count at end of main run

## Project Files

| File          | Description                                  |
|---------------|----------------------------------------------|
| 'crawler.c'   | Main program: input handling and threading   |
| 'Makefile'    | Build instructions using `make`              |
| 'urls.txt'    | List of URLs to be processed (one per line)  |

## Install Required Packages

(I am using Visual Studio Code with the WSL extension to work on the project inside the Ubuntu environment) -Scar

- sudo apt update
- sudo apt install build-essential make
- sudo apt install dos2unix

## How to Run

Step 1: Navigate to the project folder

cd ~/web-crawler

Step 2: Compile the program

make

Step 3: Execute

./crawler
