.PHONY: all clean run

# Build the crawler, linking libcurl for HTTP downloads
all:
	gcc -std=c11 -pedantic -pthread -lcurl crawler.c -o crawler

# Remove the binary and any fetched pages
clean:
	rm -f crawler page*.html

# Run the crawler (it will read urls.txt automatically)
run:
	./crawler
