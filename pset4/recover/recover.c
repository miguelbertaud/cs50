#include <stdio.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card\n");
        return 1;
    }
    
    //open the card
    FILE *fileCard = fopen(argv[1] ,"r");
    if (fileCard == NULL)
    {
        fprintf(stderr, "Could not open \n");
        return 2;
    }
    
    unsigned char buffer[512];
    int i = 0;
    FILE *fp = NULL;
    
    while (fread(buffer, 512, 1, fileCard) == 1) {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(fp != NULL)
            {
                fclose(fp);
            }
            
            char filename[sizeof "000.jpg"];
            
            sprintf(filename, "%03d.jpg", i);
            
            
            fp = fopen(filename,"w");
            
            fwrite(buffer, 512, 1, fp);
            
            i++;
        }
        else if(fp != NULL)
        {
            //write 512 bytes
            fwrite(buffer, 512, 1, fp);
        }
    }
    fclose(fp);
    fclose(fileCard);
    
    return 0;
}