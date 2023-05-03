
#include "Myclass.h"

using namespace std;


int main(int argc, char *argv[]) {



    if (isMode("FileStream", argc, argv)){

        cout << "Using FileStream mode" << endl;

        string filename;
        string filename2;

        fileName(filename);
        create_file(filename);


        add_text_to_file(filename);


        fileName(filename2);
        create_file(filename2);


        changeFile(filename, filename2);
        cout << "\n\nFirst file:";
        PrintFile(filename);
        cout << "\n\nSecond file:";
        PrintFile(filename2);
    }
    else if(isMode("FilePointer", argc, argv))
    {

        cout << "Using FilePointer mode" << endl;


        char filename[100];
        char filename2[100];

        fileName(filename);
        create_file(filename);


        add_text_to_file(filename);


        fileName(filename2);
        create_file(filename2);


        changeFile(filename, filename2);
        cout << "\n\nFirst file:";
        PrintFile(filename);
        cout << "\n\nSecond file:";
        PrintFile(filename2);



    }




    return 0;

}
