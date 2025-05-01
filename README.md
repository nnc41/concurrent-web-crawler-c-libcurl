# Concurrent Web Crawler in C (libcurl + pthreads) 🌐⚙️

Downloads up to **100 URLs in parallel**, streams each page directly to disk, and produces a keyword-frequency report for *Linux*, *Science*, *Code*, *libcurl*, and *Kernel*.

---

## ✨ Key Features
| Area | Highlights |
|------|------------|
| **Multithreading** | One POSIX thread (`pthread`) per valid URL; thread-safe logs with `[INFO] / [WARNING] / [ERROR]` tags. |
| **Robust I/O** | Graceful checks for missing `urls.txt`, file-open failures, and memory allocation errors. |
| **HTTP Downloads** | Uses **libcurl**; streams directly to `page<N>.html` via a zero-copy `write_data` callback. |
| **Keyword Analytics** | Scans every downloaded file character-by-character and tallies target words (case-insensitive). |
| **Clean Build System** | Single-command workflow: `make all`, `make run`, `make clean`. |

---

## 📂 Project Structure

| File/Dir | Purpose |
|----------|---------|
| `crawler.c` | Entire application (input parsing, threading, downloads, and word counting). |
| `Makefile` | Build / run / clean targets. |
| `urls.txt` | One URL per line (HTTP or HTTPS). Edit to crawl different sites. |

---

## 🔧 Build & Run

```bash
# 1 — clone repo then enter directory
git clone https://github.com/YOUR_USERNAME/concurrent-web-crawler-c-libcurl.git
cd concurrent-web-crawler-c-libcurl

# 2 — compile
make            # or: make all

# 3 — run crawler (reads urls.txt automatically)
make run

# 4 — optional: remove binary + downloaded HTML
make clean
