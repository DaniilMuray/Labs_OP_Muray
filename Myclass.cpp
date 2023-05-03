//
// Created by Legion on 4/16/2023.
//

#include "Myclass.h"


void add_text_to_file(const string& filename){
    string input;

    ofstream outfile(filename, ios::out);
    cout << "\nEnter text:" << endl;

    while(getline(cin, input)){
        if(input.empty()){
            break;
        }
        outfile << input << endl;
    }

    outfile.close();
}




void create_file(const string& filename){

    ofstream file(filename);

    if(file.is_open())
        cout << "File is created!" << endl;
    else
        cout << "Cannot open file!" << endl;


    file.close();


}

void fileName(string &filename){

    cout << "\nEnter filename:";

    getline(cin, filename);
    filename.append(".txt");

}



char getLetter(){
    char letter;
    cout << "Enter letter to find:";
    cin >> letter;

    return letter;
}


void changeFile(const string& filename, const string& filename2){


    ifstream infile(filename);
    ofstream outfile(filename2);

    string line;
    string text;



    while (getline(infile, line, '\n')) {
        // Об'єднуємо рядки, які складають одне речення
        text += line;

    }


    bool newWord = true;
    char letter = getLetter();

    bool inside = false;
    for(int i = 0, j = 0; i < text.length(); i++){
        char c = text[i];

        if(c == '{')
            inside = true;
        if(c == '}'){

            outfile << ":" << j;
            inside = false;
            j = 0;
        }



        if (c == letter && newWord && inside){
            newWord = false;
            j++;

        }
        if (c == ' ' || c == '.' || c == '!' || c == '?' || c == ','){
            newWord = true;

        }
        if (c == '.' || c == '!' || c == '?') { // якщо символ знайдений
            outfile.put(c); // записуємо знайденний символ у файл
            outfile.put('\n'); // записуємо символ переносу строки після знайденого символу
        } else {
            outfile.put(c); // записуємо симвпол у вихідний файл без зміни
        }

    }

    infile.close();
    outfile.close();

}

void PrintFile(const string& filename){
    ifstream infile(filename);


    if(infile){
        string text1;
        cout << "\n\n";
        while (getline(infile, text1)) {
            cout << text1 << '\n';

        }
    }

    infile.close();
}

// FilePointer mode



void PrintFile(const char* filename) {
    ifstream infile(filename);

    if (infile) {
        string text1;
        while (getline(infile, text1)) {
            cout << text1 << endl;
        }
        infile.close();
    }
}

void add_text_to_file(const char *filename)
{
    char input[1024];
    FILE *outfile = fopen(filename, "w");
    if (!outfile)
    {
        cout << "Error: Unable to open file: " << filename << endl;
        return;
    }
    cout << "\nEnter some text:\n";

    // Зчитувати рядки та додавати їх у файл, поки користувач не натисне двічі enter
    while (fgets(input, 1024, stdin))
    {
        if (strcmp(input, "\n") == 0)
        {
            break;
        }
        fputs(input, outfile); // додаємо рядок до кінця файлу
    }

    fclose(outfile); // закриваємо файл
}

void create_file(const char *filename)
{
    // створюємо текстовий файл
    FILE *file = fopen(filename, "w");
    fclose(file);
    cout << "File created successfully!" << endl;
}

void fileName(char* filename)
{
    cout << "\nEnter filename:";
    // Отримуємо ім'я файлу від користувача
    fgets(filename, 100, stdin);
    // Видаляємо символ переносу рядка з кінця введення
    filename[strcspn(filename, "\n")] = '\0';
    // Додаємо розширення .txt до імені файлу
    strcat(filename, ".txt");
}


void changeFile(const char* filename, const char* filename2){


//    ifstream infile(filename);
    ofstream outfile(filename2);

    FILE *file;
    file = fopen(filename, "r");
    char *text;
    long file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Виділяємо пам'ять для масиву char
    text = (char *)malloc(file_size);

    // Зчитуємо вміст файлу в масив char
    fread(text, 1, file_size, file);




    bool newWord = true;
    char letter = getLetter();

    bool inside = false;
    for(int i = 0, j = 0; i < ::strlen(text); i++){
        char c = text[i];

        if(c == '{')
            inside = true;
        if(c == '}'){

            outfile << ":" << j;
            inside = false;
            j = 0;
        }



        if (c == letter && newWord && inside){
            newWord = false;
            j++;

        }
        if (c == ' ' || c == '.' || c == '!' || c == '?' || c == ','){
            newWord = true;

        }
        if (c == '.' || c == '!' || c == '?') { // если символ найден
            outfile.put(c); // записываем найденный символ в выходной файл
            outfile.put('\n'); // записываем символ перевода строки после найденного символа
        } else {
            outfile.put(c); // записываем символ в выходной файл без изменений
        }

    }

    fclose(file); // закрываем входной файл
    outfile.close(); // закрываем выходной файл


}



bool isMode(const char *modeValue, int argc, char *argv[])
{
    // Проходимо по всіх аргументах командного рядка
    for (int i = 1; i < argc; i++)
    {
        // Якщо зустрічаємо аргумент "-mode" та наступний аргумент дорівнює modeValue, повертаємо true
        if (strcmp(argv[i], "-mode") == 0 && i + 1 < argc)
        {
            return strcmp(argv[i + 1], modeValue) == 0;
        }
    }
    // Якщо режим не був знайдений, повертаємо false
    return false;
}