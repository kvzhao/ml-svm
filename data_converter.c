#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

FILE *fp, *rp;

void read_file(const char *filename)
{

}

int main(int argc, char **argv)
{
    char input_file_name[64];
    char output_file_name[64];
    char line[80];

    const char *error_msg;

    /* File source should more than one */
    if(argc != 2) {
        error_msg = "Improper arguments amount.";
        fprintf(stderr,"ERROR: %s\n",error_msg);
        exit(1);
    } else {
        /* Assign I/O file names */
        strcpy(input_file_name,argv[1]);
        strcpy(output_file_name,"train-db");
    }

    /* Open input file */
    fp = fopen(input_file_name,"r");
    if(fp == NULL) {
        fprintf(stderr,"can't open input file %s\n",input_file_name);
        exit(1);
    }
    /* Open result file */
    rp = fopen(output_file_name,"w+");
    if(rp == NULL) {
        fprintf(stderr,"can't open output file %s\n",output_file_name);
        exit(1);
    }

    // Parsing the file
   float fvec[4]; // feature vectors
   int ind;       // index
    while(fgets(line,80,fp) != NULL)
    {
        // Extract each values from one line
        sscanf(line,"%f %f %f %f %d", &fvec[0],&fvec[1],&fvec[2],&fvec[3],&ind);
        // Write in new format in output file following below
        // [label] [index1]:[value1] [index2]:[value2] ...
        if (ind)
        {
            fprintf(rp,"+1 1:%f 2:%f 3:%f 4:%f\n",&fvec[0],&fvec[1],&fvec[2],&fvec[3]);
        } else
        {
            fprintf(rp,"-1 1:%f 2:%f 3:%f 4:%f\n",&fvec[0],&fvec[1],&fvec[2],&fvec[3]);
        }
    }

    /* close files */
    fclose(fp);
    fclose(rp);

    return 0;
}
