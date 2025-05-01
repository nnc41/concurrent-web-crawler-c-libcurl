# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <errno.h>
# include <ctype.h>

//declaration
const char wordCounter(const char filepath[]);


int main()
{
    //file path of folder holding page1,page2, etc in as parameter.
    wordCounter("/home/seed/Desktop/HTMLfolder");
    return 0;
}

//function for counting defined words
const char wordCounter(const char filepath[])
{
    //dir pointer
    DIR *dirp;
    //file pointer
    FILE *fptr;
    //html files pointer
    struct dirent *files;
    //position int for building words
    int pos = 0;
    //words to be counted and count array
    char *words[] = {"Linux", "Science", "Code", "Libcurl", "Kernel"};
    //lowercase for the words
    char *lowercasewords[] = {"linux", "science", "code", "libcurl", "kernel"};
    int count[5] = {0, 0, 0, 0, 0};
    //char for building strings
    char w[100];

    //char c for fgetc
    char c;

    //opendir operation
    if ((dirp = opendir(filepath)) == NULL )
    {
        perror("Dir doesn't exist");
    }

    //while loop that gets the contents of the dirp(folder with html) until it returns null
    while((files = readdir(dirp)) != NULL)
    {
        //strcmp to check if files is . or .. , or the files for the c file
        //if so then ignore the files
        if(strcmp(files->d_name, ".") == 0)
        {
            continue;
        }

        if(strcmp(files->d_name, "..") == 0)
        {
            continue;
        }

        if(strcmp(files->d_name, "WordProcessing") == 0)
        {
            continue;
        }

        if(strcmp(files->d_name, "WordProcessing.c") == 0)
        {
            continue;
        }

        if(strcmp(files->d_name, "WordProcessing.o") == 0)
        {
            continue;
        }


        //file opening operation uses -> d_name to get the string for fopen
        if((fptr = fopen(files->d_name, "r")) == NULL )
        {
            perror("File coundn't open");
        }

        //whille loop that runs while fgetc of fptr isn't at the end of file
        //used fgetc to deal with non alphabet characters like " : / etc
        while((c = fgetc(fptr)) != EOF)
        {

            //if c isn't apart of the alphabet then the word is finished and before resetting pos and erasing w
            //check if w and words array are equal, if so then += 1 to counts for respective word
            if((isalpha(c)) == 0)
            {
                //Linux
                if(strcmp(w, words[0]) == 0 || strcmp(w, lowercasewords[0]) == 0)
                {
                    count[0] += 1;
                }
                //science
                if(strcmp(w, words[1]) == 0 || strcmp(w, lowercasewords[1]) == 0)
                {
                    count[1] += 1;
                }
                //code
                if(strcmp(w, words[2]) == 0 || strcmp(w, lowercasewords[2]) == 0)
                {
                    count[2] += 1;
                }
                //libcurl
                if(strcmp(w, words[3]) == 0 || strcmp(w, lowercasewords[3]) == 0)
                {
                    count[3] += 1;
                }
                //kernel
                if(strcmp(w, words[4]) == 0 || strcmp(w, lowercasewords[4]) == 0)
                {
                    count[4] += 1;
                }
                //erase the current string in w and reset pos
                w[0] = (int)"\0";
                pos = 0;
            } else {
                //use pos with post increment to assign w at current pos to c and then increment after
                w[pos++] = c;
                //use the post increment to add terminating char
                w[pos] = 0;
            }
        }
        //fclose for after the while loop of fgetc is finished
        fclose(fptr);
    }

    //close dir after while of readdir is finished
    closedir(dirp);
    //output
    for(int i = 0; i<5; i++)
    {
        printf("%s: %d\n", words[i], count[i]);
    }


}
