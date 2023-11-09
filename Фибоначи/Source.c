#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int main(int argc, char* argv[]) {

    if (argc == 3) {

        int* mass;
        int size = 0;
        int tmp;
        int noSwap;

        FILE* in = fopen(argv[1], "r");
        FILE* out = fopen(argv[2], "w");

        if (in)
        {
            fscanf(in, "%d", &size);
            fprintf(out, "%d ", size);
            mass = (int*)calloc(size, sizeof(int));
            for (int i = 0; i < size; i++)
            {
                fscanf(in, "%d", &mass[i]);
            }
            fclose(in);
            if (out)
            {

                for (int i = size - 1; i >= 0; i--)
                {
                    noSwap = 1;
                    for (int j = 0; j < i; j++)
                    {
                        if (mass[j] > mass[j + 1])
                        {
                            tmp = mass[j];
                            mass[j] = mass[j + 1];
                            mass[j + 1] = tmp;
                            noSwap = 0;
                        }

                        for (int i = size - 1; i >= 0; i--)
                        {
                            if (mass[size - 1] > mass[size])
                            {
                                tmp = mass[size];
                                mass[size - 1] = mass[size];
                                mass[size] = tmp;
                                noSwap = 0;
                            }
                        }
                    }
                    if (noSwap == 1)
                    {
                        break;
                    }
                }
            }
            for (int j = 0; j < size; j++)
            {
                fprintf(out, "%d ", mass[j]);

            }
            fclose(out);
            free(mass);
            return 0;
        }
    }
}