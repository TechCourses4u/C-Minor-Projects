    /* Menu driven database management system */
    #include<stdio.h>
    #include<stdlib.h> // for system
    #include<conio.h>  // for getch
    #include<string.h> // for strcmp

    struct student {
        char name[20];
        int age;
        float marks;
    };

    int main() {
        FILE *fp,*ft;
        struct student st;
        char stdName[20];
        long int recSize = sizeof(st);

        fp = fopen("Student.DAT","rb+");
        if(fp==NULL) {
            fp = fopen("Student.DAT","wb+");
            if(fp==NULL) {
                printf("Cannot open file\n");
                exit(1);
            }
        }

        char another, choice;
        while(1) {
            system("cls");
            system("Color fd");
            printf("******************************\n");
            printf("* Database Management System *\n");
            printf("******************************\n\n");
            printf("You can perform below operations : \n");
            printf("1. Add records\n");
            printf("2. List records\n");
            printf("3. Modify records\n");
            printf("4. Delete records\n");
            printf("5. Exit\n");
            printf("\n*****Enter Your choice*****\n");

            fflush(stdin);
            scanf("%c",&choice);
            system("cls");

            switch(choice) {
                case '1':   //Add Records
                    // get details from user and store at end of file
                    fseek(fp,0, SEEK_END);

                    another = 'Y';
                    while(another == 'Y') {
                        printf("\nEnter name, age and marks : \n");
                        fflush(stdin);
                        scanf("%s %d %f", st.name, &st.age, &st.marks);
                        fwrite(&st, recSize,1,fp);
        
                        printf("\nAdd another REcord (Y/N) : ");
                        fflush(stdin);
                        scanf("%c",&another);
                    }
                    break;

                case '2':   //List Records
                    // move to beg and print records one by one
                    rewind(fp);

                    while(fread(&st,recSize,1,fp)==1)
                        printf("%s %d %f\n", st.name, st.age, st.marks);
                    getch();
                    break;
                
                case '3':   // Modify Records
                    // Get Student name whose record needs modification and search records
                    // get new details from user and store in file at that location
                    another = 'Y';
                    while(another == 'Y') {
                        printf("Enter name of student to modify : ");
                        fflush(stdin);
                        scanf("%s", stdName);

                        rewind(fp);
                        while(fread(&st,recSize,1,fp)==1) {  
                            if(strcmp(st.name,stdName)==0) { 
                                printf("Entre new name, age and marks :\n");
                                scanf("%s %d %f", st.name, &st.age, &st.marks);
                                fseek(fp, -recSize, SEEK_CUR);
                                fwrite(&st,recSize,1,fp);
                                break;
                            }
                        }
                        printf("\nModify another record (Y/N) : ");
                        fflush(stdin);
                        scanf("%c",&another);
                    }
                    break;
                
                case '4':   // Delete records
                    // Get Student name whose record needs to be delted
                    // store other records in a temp file, 
                    // delete original file and rename temp file to original
                    another = 'Y';
                    while(another == 'Y') {
                        printf("Enter name of student to delete : ");
                        fflush(stdin);
                        scanf("%s", stdName);

                        ft = fopen("temp.DAT","wb");

                        rewind(fp);
                        while(fread(&st, recSize,1,fp)==1) { 
                            if(strcmp(st.name,stdName)!=0)
                                fwrite(&st,recSize,1,ft);              
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("Student.DAT");
                        rename("TEMP.DAT","Student.DAT");

                        fp = fopen("Student.DAT","rb+");

                        printf("Delete another record (Y/N) : ");
                        fflush(stdin);
                        scanf("%c",&another);
                    }
                    break;

                default :
                    fclose(fp);
                    exit(0);
            }
        }
        return 0;
    }

