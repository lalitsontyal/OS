#include<stdio.h>
//#include<conio.h> // Commented out because it's not standard
#define max 25

void main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    //static int bf[max], ff[max]; // Unused variables
    //clrscr(); // Commented out because it's not standard

    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (b[j] >= f[i])
            {
                frag[i] = b[j] - f[i];
                // Allocate the file to the block and break out of the loop
                b[j] = -1;
                break;
            }
        }
    }

    printf("\nFile_no:\tFile_size :\tFragment");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d", i, f[i], frag[i]);

    //getch(); // Commented out because it's not standard
    getchar(); // Pauses the console
}
